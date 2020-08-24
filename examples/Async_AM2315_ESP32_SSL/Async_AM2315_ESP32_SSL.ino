/****************************************************************************************************************************
   Async_AM2315_ESP32_SSL.ino
   For ESP32 boards

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
// Connect WHITE to i2c clock (PIN_D22 / SCL)
// Connect YELLOW to i2c data (PIN_D21 / SDA)

Adafruit_AM2315 AM2315;

#define AM2315_DEBUG     true

BlynkTimer timer;
Ticker     led_ticker;

#define READ_INTERVAL        60000L          //read AM2315 interval 30s

void readAndSendData()
{
  static float temperature, humidity;

  temperature = AM2315.readTemperature();
  humidity    = AM2315.readHumidity();

  if (!isnan(temperature) && !isnan(humidity))
  {
    Blynk.virtualWrite(V1, String(temperature, 1));
    Blynk.virtualWrite(V2, String(humidity, 1));

#if AM2315_DEBUG
    Serial.println("Temp *C: " + String(temperature));
    Serial.println("Humid %: " + String(humidity));
#endif
  }
  else
  {
    Blynk.virtualWrite(V1, "NAN");
    Blynk.virtualWrite(V2, "NAN");
  }
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
    set_led(HIGH);
    led_ticker.once_ms(111, set_led, (byte) LOW);
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
  
  pinMode(LED_BUILTIN, OUTPUT);

#if ( USE_SPIFFS)
  Serial.print(F("\nStarting Async_AM2315_ESP32_SSL using SPIFFS"));
#else
  Serial.print(F("\nStarting Async_AM2315_ESP32_SSL using EEPROM"));
#endif

#if USE_SSL
  Serial.println(" with SSL on " + String(ARDUINO_BOARD));
#else
  Serial.println(" without SSL on " + String(ARDUINO_BOARD));
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
  // Set config portal channel, default = 1. Use 0 => random channel from 1-13
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
  //Blynk.begin("AM2315_ESP32_SSL");
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

  timer.setInterval(READ_INTERVAL, readAndSendData);

  if (Blynk.connected())
  {
#if USE_SPIFFS
    Serial.print(F("\nBlynk ESP32 SSL using SPIFFS connected."));

#else
    Serial.println(F("\nBlynk ESP32 SSL using EEPROM connected."));
#endif
#if USE_BLYNK_WM
    Serial.println("Board Name : " + Blynk.getBoardName());
#endif
  }
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
