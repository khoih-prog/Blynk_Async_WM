/****************************************************************************************************************************
  AsyncMT_AM2315_ESP32_SSL.ino
  For ESP32 boards

  Blynk_Async_WM is a library, using AsyncWebServer instead of (ESP8266)WebServer for the ESP8266/ESP32 to enable easy
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi/Blynk.
  
  Based on and modified from Blynk library v0.6.1 (https://github.com/blynkkk/blynk-library/releases)
  Built by Khoi Hoang (https://github.com/khoih-prog/Blynk_Async_WM)
  Licensed under MIT license
  Version: 1.2.1

  Version    Modified By   Date      Comments
  -------    -----------  ---------- -----------
  1.0.16    K Hoang      25/08/2020 Initial coding to use (ESP)AsyncWebServer instead of (ESP8266)WebServer. 
                                    Bump up to v1.0.16 to sync with Blynk_WM v1.0.16
  1.1.0     K Hoang      26/11/2020 Add examples using RTOS MultiTask to avoid blocking in operation.
  1.2.0     K Hoang      01/01/2021 Add support to ESP32 LittleFS. Remove possible compiler warnings. Update examples. Add MRD
  1.2.1     K Hoang      16/01/2021 Add functions to control Config Portal from software or Virtual Switches
 ********************************************************************************************************************************/

#include "defines.h"

#include <Ticker.h>
#include <Wire.h>
#include <Adafruit_AM2315.h>        // To install Adafruit AM2315 library

// Connect RED of the AM2315 sensor to 5.0V
// Connect BLACK to Ground
// Connect WHITE to i2c clock (PIN_D22 / SCL)
// Connect YELLOW to i2c data (PIN_D21 / SDA)

Adafruit_AM2315 AM2315;

#define AM2315_DEBUG     1

Ticker     led_ticker;

volatile bool blynkConnected = false;

#if USE_DYNAMIC_PARAMETERS

void displayCredentials()
{
  Serial.println(F("\nYour stored Credentials :"));

  for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.print(myMenuItems[i].displayName);
    Serial.print(F(" = "));
    Serial.println(myMenuItems[i].pdata);
  }
}

void checkAndDisplayCredentials()
{
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (uint16_t i = 0; i < NUM_MENU_ITEMS; i++)
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
}

#endif

void readAndSendData()
{
  static float temperature, humidity;

  temperature = AM2315.readTemperature();
  humidity    = AM2315.readHumidity();

  if (!isnan(temperature) && !isnan(humidity))
  {
#if (AM2315_DEBUG > 0)
    Serial.println("Temp *C: " + String(temperature));
    Serial.println("Humid %: " + String(humidity));
#endif

    if (blynkConnected)
    {
      Blynk.virtualWrite(V1, String(temperature, 1));
      Blynk.virtualWrite(V2, String(humidity, 1));
    }
  }
  else
  {
#if (AM2315_DEBUG > 1)
    Serial.println(F("\nTemp *C: Error"));
    Serial.println(F("Humid %: Error"));
#endif

    if (blynkConnected)
    {
      Blynk.virtualWrite(V1, "NAN");
      Blynk.virtualWrite(V2, "NAN");
    }
  }
}

void set_led(byte status)
{
  digitalWrite(LED_BUILTIN, status);
}

void checkBlynk()
{
  static int num = 1;

  if (blynkConnected)
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

////////////////// Start Free-RTOS related code //////////////////

void SensorReadEveryNSec( void * pvParameters )
{
#define SENSOR_READ_INTERVAL_MS       10000L

  for (;;)
  {
    readAndSendData();
    vTaskDelay(SENSOR_READ_INTERVAL_MS / portTICK_PERIOD_MS);
  }
}

void InternetBlynkStatus( void * pvParameters )
{
  // Check Internet connection every PING_INTERVAL_MS if already Online
#define CHECK_BLYNK_INTERVAL_MS       10000L

  for (;;)
  {
    checkBlynk();
    vTaskDelay(CHECK_BLYNK_INTERVAL_MS / portTICK_PERIOD_MS);
  }
}

void BlynkRun( void * pvParameters )
{
#define BLYNK_RUN_INTERVAL_MS    250L

  for (;;)
  {
    Blynk.run();

#if USE_DYNAMIC_PARAMETERS
    checkAndDisplayCredentials();
#endif

    vTaskDelay(BLYNK_RUN_INTERVAL_MS / portTICK_PERIOD_MS);
  }
}

void BlynkCheck( void * pvParameters )
{
#define BLYNK_CHECK_INTERVAL_MS    5000L

  bool wifiConnected = false;

  for (;;)
  {
    wifiConnected = (WiFi.status() == WL_CONNECTED);

    if ( wifiConnected && Blynk.connected() )
    {
      blynkConnected = true;
    }
    else
    {
      blynkConnected = false;

      if (wifiConnected)
        Serial.println(F("\nBlynk Disconnected"));
      else
        Serial.println(F("\nWiFi Disconnected"));
    }

    vTaskDelay(BLYNK_CHECK_INTERVAL_MS / portTICK_PERIOD_MS);
  }
}

/////////// Set Core and Priority. Be careful here ///////////

#define USING_CORE_1      0
#define USING_CORE_2      1

//Low priority numbers denote low priority tasks. The idle task has priority 0 (tskIDLE_PRIORITY).
//MAX_PRIORITIES = 25 => Can use priority from 0-24

#define SensorReadEveryNSec_Priority        ( 4 | portPRIVILEGE_BIT )
#define InternetBlynkStatus_Priority        ( 3 | portPRIVILEGE_BIT )

// Don't use BlynkRun_Priority too low, can drop Blynk connection, especially in SSL
#define BlynkRun_Priority                   ( 15 | portPRIVILEGE_BIT )

#define BlynkCheck_Priority                 ( BlynkRun_Priority )

////////////////// End Free-RTOS related code //////////////////

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(115200);
  while (!Serial);

  delay(200);

#if ( USE_LITTLEFS || USE_SPIFFS)
  Serial.print(F("\nStarting AsyncMT_AM2315_ESP32_SSL using "));
  Serial.print(CurrentFileFS);
#else
  Serial.print(F("\nStarting AsyncMT_AM2315_ESP32_SSL using EEPROM"));
#endif

#if USE_SSL
  Serial.print(F(" with SSL on ")); Serial.println(ARDUINO_BOARD);
#else
  Serial.print(F(" without SSL on ")); Serial.println(ARDUINO_BOARD);
#endif  

#if USE_BLYNK_WM
  Serial.println(BLYNK_ASYNC_WM_VERSION);
  Serial.println(ESP_DOUBLE_RESET_DETECTOR_VERSION);
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

  if (Blynk.connected())
  {
#if ( USE_LITTLEFS || USE_SPIFFS)
    Serial.print(F("\nBlynk ESP32 using "));
    Serial.print(CurrentFileFS);
    Serial.println(F(" connected."));
#else
    Serial.println(F("\nBlynk ESP32 using EEPROM connected."));
    Serial.printf("EEPROM size = %d bytes, EEPROM start address = %d / 0x%X\n", EEPROM_SIZE, EEPROM_START, EEPROM_START);
#endif

#if USE_BLYNK_WM
    Serial.print(F("Board Name : ")); Serial.println(Blynk.getBoardName());
#endif    
  }

  ////////////////// Tasks creation //////////////////

#if (BLYNK_WM_RTOS_DEBUG > 0)
  Serial.println(F("*********************************************************"));
  Serial.printf("configUSE_PORT_OPTIMISED_TASK_SELECTION = %s\n", configUSE_PORT_OPTIMISED_TASK_SELECTION ? "true" : "false");
  Serial.printf("configUSE_TIME_SLICING = %s\n", configUSE_TIME_SLICING ? "true" : "false");
  Serial.printf("configMAX_PRIORITIES = %d, portPRIVILEGE_BIT = %d\n", configMAX_PRIORITIES, portPRIVILEGE_BIT);

  Serial.printf("Task Priority : InternetBlynkStatus = %d, BlynkRun   = %d\n", InternetBlynkStatus_Priority, BlynkRun_Priority);
  Serial.printf("Task Priority : SensorReadEveryNSec = %d, BlynkCheck = %d\n", SensorReadEveryNSec_Priority, BlynkCheck_Priority);
  Serial.println(F("*********************************************************"));
#endif

  // RTOS function prototype
  //BaseType_t xTaskCreatePinnedToCore(TaskFunction_t pvTaskCode, const char *constpcName, const uint32_t STACK_SIZE,
  //    void *constpvParameters, UBaseType_t IDLE_PRIORITY, TaskHandle_t *constpvCreatedTask, const BaseType_t xCoreID)
  xTaskCreatePinnedToCore( BlynkRun,              "BlynkRun",             50000,  NULL, BlynkRun_Priority,              NULL, USING_CORE_2);
  xTaskCreatePinnedToCore( BlynkCheck,            "BlynkCheck",           5000,   NULL, BlynkCheck_Priority,            NULL, USING_CORE_2);
  xTaskCreatePinnedToCore( SensorReadEveryNSec,   "SensorReadEveryNSec",  20000,  NULL, SensorReadEveryNSec_Priority,   NULL, USING_CORE_2);
  xTaskCreatePinnedToCore( InternetBlynkStatus,   "InternetBlynkStatus",  5000,   NULL, InternetBlynkStatus_Priority,   NULL, USING_CORE_2);
  ////////////////// End Tasks creation //////////////////
}

void loop()
{
  // No more Blynk.run() and timer.run() here. All is tasks
}