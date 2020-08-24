/****************************************************************************************************************************
   Async_AM2315_ESP8266.ino
   For ESP8266 boards

   Blynk_Async_WM is a library, using AsyncWebServer instead of (ESP8266)WebServer for the ESP8266/ESP32 to enable easy
   configuration/reconfiguration and autoconnect/autoreconnect of WiFi/Blynk.
   
   Based on and modified from Blynk library v0.6.1 (https://github.com/blynkkk/blynk-library/releases)
   Built by Khoi Hoang (https://github.com/khoih-prog/Blynk_Async_WM)
   Licensed under MIT license
   Version: 1.0.16

   Version    Modified By   Date      Comments
   -------    -----------  ---------- -----------
    1.0.16    K Hoang      25/08/2020 Initial coding to use (ESP)AsyncWebServer instead of (ESP8266)WebServer. 
                                      Bump up to v1.0.16 to sync with Blynk_WM v1.0.16
 *****************************************************************************************************************************/

#include "defines.h"

#include <Ticker.h>
#include <Wire.h>
#include <Adafruit_AM2315.h>        // To install Adafruit AM2315 library

// Connect RED of the AM2315 sensor to 5.0V
// Connect BLACK to Ground
// Connect WHITE to i2c clock (PIN_D1 / SCL)
// Connect YELLOW to i2c data (PIN_D2 / SDA)

Adafruit_AM2315 AM2315;

#define AM2315_DEBUG     true

BlynkTimer timer;
Ticker     led_ticker;

#define READ_INTERVAL        30000          //read AM2315 interval 30s

void ReadData()
{
  static float temperature, humidity;

  if (!AM2315.readTemperatureAndHumidity(&temperature, &humidity))
  {
#if AM2315_DEBUG
    Serial.println(F("Failed to read data from AM2315"));
#endif

    return;
  }

#if AM2315_DEBUG
  Serial.println("Temp *C: " + String(temperature));
  Serial.println("Humid %: " + String(humidity));
#endif

  //V1 and V2 are Blynk Display widgets' VPIN
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
}

void set_led(byte status)
{
  digitalWrite(LED_BUILTIN, status);
}

void heartBeatPrint(void)
{
  static int num = 1;

  if (Blynk.connected())
  {
    set_led(LOW);
    led_ticker.once_ms(111, set_led, (byte) HIGH);
    Serial.print(F("B"));
  }
  else
  {
    Serial.print(F("F"));
  }

  if (num == 80)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(F(" "));
  }
}

void check_status()
{
  static unsigned long checkstatus_timeout = 0;

#define STATUS_CHECK_INTERVAL     60000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    // report status to Blynk
    heartBeatPrint();

    checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
  }
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

#if ( USE_LITTLEFS || USE_SPIFFS)
  Serial.print("\nStarting AM2315_ESP8266 using " + String(CurrentFileFS));  
#else
  Serial.print(F("\nStarting AM2315_ESP8266 using EEPROM"));
#endif  

  if (!AM2315.begin())
  {
    Serial.println(F("Sensor not found, check wiring & pullups!"));
  }

#if USE_BLYNK_WM
  // From v1.0.5
  // Set config portal SSID and Password
  Blynk.setConfigPortal("TestPortal", "TestPortalPass");
  // Set config portal IP address
  Blynk.setConfigPortalIP(IPAddress(192, 168, 200, 1));
  // Set config portal channel, defalut = 1. Use 0 => random channel from 1-13
  Blynk.setConfigPortalChannel(0);

  // From v1.0.5, select either one of these to set static IP + DNS
  Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0));
  //Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0),
  //                           IPAddress(192, 168, 2, 1), IPAddress(8, 8, 8, 8));
  //Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0),
  //                           IPAddress(4, 4, 4, 4), IPAddress(8, 8, 8, 8));

  // Use this to default DHCP hostname to ESP8266-XXXXXX or ESP32-XXXXXX
  //Blynk.begin();
  // Use this to personalize DHCP hostname (RFC952 conformed)
  // 24 chars max,- only a..z A..Z 0..9 '-' and no '-' as last char
  //Blynk.begin("AM2315_ESP8266");
  Blynk.begin(HOST_NAME);
#else
  WiFi.begin(ssid, pass);

#if USE_LOCAL_SERVER
  Blynk.config(auth, blynk_server, BLYNK_HARDWARE_PORT);
#else
  Blynk.config(auth);
#endif

  Blynk.connect();
#endif

  if (Blynk.connected())
  {
#if ( USE_LITTLEFS || USE_SPIFFS)
    Serial.println("\nBlynk ESP8288 using " + String(CurrentFileFS) + " connected.");
#else
    {
      Serial.println(F("\nBlynk ESP8288 using EEPROM connected."));
      Serial.printf("EEPROM size = %d bytes, EEPROM start address = %d / 0x%X\n", EEPROM_SIZE, EEPROM_START, EEPROM_START);
    }
#endif

#if USE_BLYNK_WM
    Serial.println("Board Name : " + Blynk.getBoardName());
#endif
  }

  timer.setInterval(READ_INTERVAL, ReadData);
}

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
void displayCredentials(void)
{
  Serial.println(F("\nYour stored Credentials :"));

  for (int i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.println(String(myMenuItems[i].displayName) + " = " + myMenuItems[i].pdata);
  }
}
#endif

void loop()
{
  Blynk.run();
  timer.run();
  check_status();

#if (USE_BLYNK_WM && USE_DYNAMIC_PARAMETERS)
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
    {
      if (!strlen(myMenuItems[i].pdata))
      {
        break;
      }

      if ( i == (NUM_MENU_ITEMS - 1) )
      {
        displayedCredentials = true;
        displayCredentials();
      }
    }
  }
#endif
}
