/****************************************************************************************************************************
   ESP_LED_BUILTINS.h Blynk_WM_Template.ino
   For ESP32/ESP8266 boards
   Written by Thor Johnson (https://github.com/thorathome) May 2020 as a template for
   Blynk Wifi ESP communications. See https://github.com/thorathome/Blynk_Examples
   
   Blynk_Async_WM is a library, using AsyncWebServer instead of (ESP8266)WebServer for the ESP8266/ESP32 to enable easy
   configuration/reconfiguration and autoconnect/autoreconnect of WiFi/Blynk.
   
   Based on and modified from Blynk library v0.6.1 (https://github.com/blynkkk/blynk-library/releases)
   Built by Khoi Hoang (https://github.com/khoih-prog/Blynk_Async_WM)
   Licensed under MIT license
   Version: 1.2.0

   Version    Modified By   Date      Comments
   -------    -----------  ---------- -----------
    1.0.16    K Hoang      25/08/2020 Initial coding to use (ESP)AsyncWebServer instead of (ESP8266)WebServer. 
                                      Bump up to v1.0.16 to sync with Blynk_WM v1.0.16
    1.1.0     K Hoang      26/11/2020 Add examples using RTOS MultiTask to avoid blocking in operation.
    1.2.0     K Hoang      01/01/2021 Add support to ESP32 LittleFS. Remove possible compiler warnings. Update examples. Add MRD
 ********************************************************************************************************************************/

#ifndef ESP_LED_BUILTINS_h
#define ESP_LED_BUILTINS_h

// This is a simple Kludge that lets sketches be more device-independent
// Arduino for ESP8266 inverts the HIGH/LOW for the onboard LED_BUILTIN
// Use LED_BUILTIN_HIGH and LED_BUILTIN_LOW in your sketch and all will be right with the world

#if ESP8266  // There's a quirk in Arduino that has the LED_BUILTIN inverted. This corrects for it.
  #define LED_BUILTIN_HIGH      LOW
  #define LED_BUILTIN_LOW       HIGH
#else
  #define LED_BUILTIN_HIGH      HIGH
  #define LED_BUILTIN_LOW       LOW
#endif

// Also the ESP32 board manager files appear to NOT have LED_BUILTIN assigned correctly
// This fixes that
#if ESP32
  #ifdef LED_BUILTIN
    #undef LED_BUILTIN      
  #endif 
  #define LED_BUILTIN           13  // NOT DEFINED IN ESP32 BOARD FILES - HMMM.
#endif

#endif    //ESP_LED_BUILTINS_h
