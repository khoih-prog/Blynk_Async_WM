/****************************************************************************************************************************
   Async_ESP32WM_Config.ino
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
#include "Credentials.h"
#include "dynamicParams.h"

#include <Ticker.h>
#include <DHT.h>

DHT dht(DHT_PIN, DHT_TYPE);
BlynkTimer timer;
Ticker     led_ticker;

void readAndSendData()
{
  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  if (!isnan(temperature) && !isnan(humidity))
  {
    Blynk.virtualWrite(V17, String(temperature, 1));
    Blynk.virtualWrite(V18, String(humidity, 1));
  }
  else
  {
    Blynk.virtualWrite(V17, "NAN");
    Blynk.virtualWrite(V18, "NAN");
  }

  // Blynk Timer uses millis() and is still working even if WiFi/Blynk not connected
  Serial.print("R");
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
    Serial.print("B");
  }
  else
  {
    Serial.print("F");
  }

  if (num == 40)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(" ");
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
  // Debug console
  Serial.begin(115200);
  while (!Serial);

  pinMode(LED_BUILTIN, OUTPUT);

#if ( USE_SPIFFS)
  Serial.print("\nStarting Async_ESP32WM_Config using SPIFFS");
#else
  Serial.print("\nStarting Async_ESP32WM_Config using EEPROM");
#endif

#if USE_SSL
  Serial.println(" with SSL on " + String(ARDUINO_BOARD));
#else
  Serial.println(" without SSL on " + String(ARDUINO_BOARD));
#endif

  dht.begin();

  // Set config portal SSID and Password
  Blynk.setConfigPortal("TestPortal-ESP32", "TestPortalPass");
  // Set config portal IP address
  Blynk.setConfigPortalIP(IPAddress(192, 168, 220, 1));
  // Set config portal channel, default = 1. Use 0 => random channel from 1-13 to avoid conflict
  Blynk.setConfigPortalChannel(0);

  // From v1.0.5, select either one of these to set static IP + DNS
  Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 230), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0));
  //Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0),
  //                           IPAddress(192, 168, 2, 1), IPAddress(8, 8, 8, 8));
  //Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0),
  //                           IPAddress(4, 4, 4, 4), IPAddress(8, 8, 8, 8));

  // Use this to default DHCP hostname to ESP8266-XXXXXX or ESP32-XXXXXX
  //Blynk.begin();
  // Use this to personalize DHCP hostname (RFC952 conformed)
  // 24 chars max,- only a..z A..Z 0..9 '-' and no '-' as last char
  //Blynk.begin("ESP32-WM-Config");
  Blynk.begin(HOST_NAME);

  timer.setInterval(60 * 1000, readAndSendData);

  if (Blynk.connected())
  {
#if USE_SPIFFS
    Serial.println("\nBlynk ESP32 using SPIFFS connected. Board Name : " + Blynk.getBoardName());
#else
    Serial.println("\nBlynk ESP32 using EEPROM connected. Board Name : " + Blynk.getBoardName());
    Serial.printf("EEPROM size = %d bytes, EEPROM start address = %d / 0x%X\n", EEPROM_SIZE, EEPROM_START, EEPROM_START);
#endif
  }
}

#if USE_DYNAMIC_PARAMETERS
void displayCredentials(void)
{
  Serial.println("\nYour stored Credentials :");

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

#if USE_DYNAMIC_PARAMETERS
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
