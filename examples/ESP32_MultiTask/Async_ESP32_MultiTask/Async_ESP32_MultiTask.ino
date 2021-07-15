/****************************************************************************************************************************
  Async_ESP32_MultiTask.ino
  For ESP32 boards

  Blynk_Async_WM is a library, using AsyncWebServer instead of (ESP8266)WebServer for the ESP8266/ESP32 to enable easy
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi/Blynk.
  
  Based on and modified from Blynk library v0.6.1 (https://github.com/blynkkk/blynk-library/releases)
  Built by Khoi Hoang (https://github.com/khoih-prog/Blynk_Async_WM)
  Licensed under MIT license
  Version: 1.6.1

  Version    Modified By   Date      Comments
  -------    -----------  ---------- -----------
  1.0.16    K Hoang      25/08/2020 Initial coding to use (ESP)AsyncWebServer instead of (ESP8266)WebServer. 
                                    Bump up to v1.0.16 to sync with Blynk_WM v1.0.16
  1.1.0     K Hoang      26/11/2020 Add examples using RTOS MultiTask to avoid blocking in operation.
  1.2.0     K Hoang      01/01/2021 Add support to ESP32 LittleFS. Remove possible compiler warnings. Update examples. Add MRD
  1.2.1     K Hoang      16/01/2021 Add functions to control Config Portal from software or Virtual Switches
  1.2.2     K Hoang      28/01/2021 Fix Config Portal and Dynamic Params bugs
  1.2.3     K Hoang      31/01/2021 To permit autoreset after timeout if DRD/MRD or non-persistent forced-CP
  1.3.0     K Hoang      24/02/2021 Add customs HTML header feature and support to ESP32-S2.
  1.4.0     K Hoang      19/04/2021 Add LittleFS and SPIFFS support to ESP32-S2. Add support to ESP32-C3 without LittleFS
                                    Fix SSL issue with Blynk Cloud Server
  1.4.1     K Hoang      24/04/2021 Fix issue of custom Blynk port (different from 8080 or 9443) not working on ESP32
  1.5.0     K Hoang      25/04/2021 Enable scan of WiFi networks for selection in Configuration Portal
  1.6.0     K Hoang      19/05/2021 Fix AP connect and SSL issues caused by breaking ESP8266 core v3.0.0
  1.6.1     K Hoang      15/07/2021 Add configurable connectMultiWiFi parameters. Update for ESP8266 core v3.0.1
 ********************************************************************************************************************************/
 
#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 27 // Temperature
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//BlynkTimer timer;

//*** TFT *****

#include <TFT_eSPI.h>
#include "bmp.h"              // ./ArduinoMenu_library/examples/adafruitGfx_eTFT/TFT_eSPI/ArduinoMenu_LilyGo_TTGO_T-display_demo/bmp.h
#include "Free_Fonts.h"       // https://github.com/Bodmer/TFT_eSPI/blob/master/examples/320%20x%20240/Free_Font_Demo/Free_Fonts.h
#include <FS.h>
#include <SPI.h>

#include <Ticker.h>
Ticker     led_ticker;

TFT_eSPI tft = TFT_eSPI();

WidgetLED led1(V1);

bool isOnline         = false;
bool isBlynkConnected = false;

//***********************************

bool toggle;

float Temperature0 = 100;
float Temperature1 = 100;
float Temperature2 = 100;

float t0 = 200;
float t1 = 200;
float t2 = 200;

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

//**** displayLocation *****************

void displayLocation()
{
  tft.setFreeFont(FSSB12);

  tft.fillScreen(TFT_BLACK);

  tft.setCursor(60, 30);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("#01:");

  tft.setCursor(60, 75);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.println("#02:");

  tft.setCursor(60, 120);
  tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  tft.println("#03:");
}

void displayTemp()
{
  // *********** LED toggle **************

  if (toggle == 1)
  {
    tft.fillRect(4, 104, 33, 33, TFT_BLACK);
    tft.pushImage(5, 105, 30, 30, rec);
    led1.on();
    digitalWrite(LED_BUILTIN, 1);
  }
  else
  {
    tft.fillRect(4, 104, 33, 33, TFT_BLACK);
    led1.off();
    digitalWrite(LED_BUILTIN, 0);
  }
  //***************************************

  tft.setFreeFont(FSSB18);

  // Define true to simulate DS18B20s for testing if you don't have real DS18B20
#define SIMULATE_ONLY   true

#if SIMULATE_ONLY

  float curTime = millis() % 100000;

  Serial.println("=================");
  Serial.printf("Time = %ld ms\n", millis());

  Temperature0 = 25.0 + curTime / 100000;
  Temperature1 = 26.0 + curTime / 125000;
  Temperature2 = 27.0 + curTime / 150000;

#endif

  if (Temperature0 != t0)
  {
    tft.fillRect(120, 0, 120, 39, TFT_BLACK);
    tft.setCursor(120, 30);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);

    tft.println(Temperature0);
    Serial.printf("T0 = %5.2f\n", Temperature0);

    t0 = Temperature0;
  }

  if (Temperature1 != t1)
  {
    tft.fillRect (120, 45, 120, 40, TFT_BLACK);
    tft.setCursor(120, 75);
    tft.setTextColor(TFT_BLUE, TFT_BLACK);

    tft.println(Temperature1);
    Serial.printf("T1 = %5.2f\n", Temperature1);

    t1 = Temperature1;
  }

  if (Temperature2 != t2)
  {
    tft.fillRect (120, 90, 120, 40, TFT_BLACK);
    tft.setCursor(120, 120);
    tft.setTextColor(TFT_ORANGE, TFT_BLACK);

    tft.println(Temperature2);
    Serial.printf("T2 = %5.2f\n", Temperature2);

    t2 = Temperature2;
  }

  toggle = !toggle;
}

void readTemp()
{
  sensors.requestTemperatures();
  Temperature0 = sensors.getTempCByIndex(0);
  Temperature1 = sensors.getTempCByIndex(1);
  Temperature2 = sensors.getTempCByIndex(2);

  //******* wifi  ***********************************

  if (Blynk.connected())
  {
    tft.pushImage(5, 5, 30, 30, wifi);
    Blynk.virtualWrite(V2, Temperature0);
    Blynk.virtualWrite(V3, Temperature1);
    Blynk.virtualWrite(V4, Temperature2);
  }
  else
  {
    tft.fillRect(5, 5, 30, 30, TFT_BLACK);
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

void DisplayEveryNSec( void * pvParameters )
{
#define DISPLAY_INTERVAL_MS       1000L

  for (;;)
  {
    displayTemp();
    vTaskDelay(DISPLAY_INTERVAL_MS / portTICK_PERIOD_MS);
  }
}

void SensorReadEveryNSec( void * pvParameters )
{
#define SENSOR_READ_INTERVAL_MS       5000L

  for (;;)
  {
    readTemp();
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

#if ( ARDUINO_ESP32S2_DEV || ARDUINO_FEATHERS2 || ARDUINO_PROS2 || ARDUINO_MICROS2 )
  #define USING_CORE_2      0
#else
  #define USING_CORE_2      1  
#endif

//Low priority numbers denote low priority tasks. The idle task has priority 0 (tskIDLE_PRIORITY).
//MAX_PRIORITIES = 25 => Can use priority from 0-24
#define DisplayEveryNSec_Priority           ( 3 | portPRIVILEGE_BIT )
#define SensorReadEveryNSec_Priority        ( 4 | portPRIVILEGE_BIT )
#define InternetBlynkStatus_Priority        ( 3 | portPRIVILEGE_BIT )

// Don't use BlynkRun_Priority too low, can drop Blynk connection, especially in SSL
#define BlynkRun_Priority                   ( 15 | portPRIVILEGE_BIT )

#define BlynkCheck_Priority                 ( BlynkRun_Priority )

////////////////// End Free-RTOS related code //////////////////

#if USING_CUSTOMS_STYLE
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";
#endif

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(115200);
  while (!Serial);

  delay(200);

#if ( USE_LITTLEFS || USE_SPIFFS)
  Serial.print(F("\nStarting Async_ESP32_MultiTask using "));
  Serial.print(CurrentFileFS);
#else
  Serial.print(F("\nStarting Async_ESP32_MultiTask using EEPROM"));
#endif

#if USE_SSL
  Serial.print(F(" with SSL on ")); Serial.println(ARDUINO_BOARD);
#else
  Serial.print(F(" without SSL on ")); Serial.println(ARDUINO_BOARD);
#endif  

  Serial.println(BLYNK_ASYNC_WM_VERSION);
  Serial.println(ESP_DOUBLE_RESET_DETECTOR_VERSION);

  tft.begin();
  sensors.begin();
  delay(100);
  tft.setRotation(1);
  tft.setSwapBytes(true);

  delay(200);
  tft.fillScreen(TFT_BLUE);
  delay(500);

  displayLocation();
  sensors.setResolution(12);

  // Set config portal SSID and Password
  Blynk.setConfigPortal("xxxxxxxxxxxx", "xxxxxxxxxxxx");
  // Set config portal IP address
  Blynk.setConfigPortalIP(IPAddress(192, 168, 200, 4));
  // Set config portal channel, default = 1. Use 0 => random channel from 1-13 to avoid conflict
  Blynk.setConfigPortalChannel(0);

  // From v1.0.5, select either one of these to set static IP + DNS
  Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 230), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0));
  //Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0),
  //                           IPAddress(192, 168, 2, 1), IPAddress(8, 8, 8, 8));
  //Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0),
  //                           IPAddress(4, 4, 4, 4), IPAddress(8, 8, 8, 8));

//////////////////////////////////////////////
  
#if USING_CUSTOMS_STYLE
  Blynk.setCustomsStyle(NewCustomsStyle);
#endif

#if USING_CUSTOMS_HEAD_ELEMENT
  Blynk.setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
#endif

#if USING_CORS_FEATURE  
  Blynk.setCORSHeader("Your Access-Control-Allow-Origin");
#endif

  //////////////////////////////////////////////
  
  // Use this to default DHCP hostname to ESP8266-XXXXXX or ESP32-XXXXXX
  //Blynk.begin();
  // Use this to personalize DHCP hostname (RFC952 conformed)
  // 24 chars max,- only a..z A..Z 0..9 '-' and no '-' as last char
  //Blynk.begin("ESP32-WM-Config");
  Blynk.begin(HOST_NAME);

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

    Serial.print(F("Board Name : ")); Serial.println(Blynk.getBoardName());
  }

  ////////////////// Tasks creation //////////////////
#if (BLYNK_WM_RTOS_DEBUG > 0)  
  Serial.println(F("*********************************************************"));
  Serial.printf("configUSE_PORT_OPTIMISED_TASK_SELECTION = %s\n", configUSE_PORT_OPTIMISED_TASK_SELECTION ? "true" : "false");
  Serial.printf("configUSE_TIME_SLICING = %s\n", configUSE_TIME_SLICING ? "true" : "false");
  Serial.printf("configMAX_PRIORITIES = %d, portPRIVILEGE_BIT = %d\n", configMAX_PRIORITIES, portPRIVILEGE_BIT);
  
  Serial.printf("Task Priority : InternetBlynkStatus = %d, BlynkRun/BlynkCheck = %d\n", InternetBlynkStatus_Priority, BlynkRun_Priority);
  Serial.printf("Task Priority : SensorReadEveryNSec = %d, DisplayEveryNSec    = %d\n", SensorReadEveryNSec_Priority, DisplayEveryNSec_Priority);
  Serial.println(F("*********************************************************"));
#endif
  
  // RTOS function prototype
  //BaseType_t xTaskCreatePinnedToCore(TaskFunction_t pvTaskCode, const char *constpcName, const uint32_t STACK_SIZE,
  //    void *constpvParameters, UBaseType_t IDLE_PRIORITY, TaskHandle_t *constpvCreatedTask, const BaseType_t xCoreID)
  xTaskCreatePinnedToCore( BlynkRun,              "BlynkRun",             50000,  NULL, BlynkRun_Priority,              NULL, USING_CORE_2);
  xTaskCreatePinnedToCore( BlynkCheck,            "BlynkCheck",           5000,   NULL, BlynkCheck_Priority,            NULL, USING_CORE_2);
  xTaskCreatePinnedToCore( DisplayEveryNSec,      "DisplayEveryNSec",     20000,  NULL, DisplayEveryNSec_Priority,      NULL, USING_CORE_2);
  xTaskCreatePinnedToCore( SensorReadEveryNSec,   "SensorReadEveryNSec",  20000,  NULL, SensorReadEveryNSec_Priority,   NULL, USING_CORE_2);
  xTaskCreatePinnedToCore( InternetBlynkStatus,   "InternetBlynkStatus",  5000,   NULL, InternetBlynkStatus_Priority,   NULL, USING_CORE_2);
  ////////////////// End Tasks creation //////////////////
}

void loop()
{
  // No more Blynk.run() and timer.run() here. All is tasks
}
