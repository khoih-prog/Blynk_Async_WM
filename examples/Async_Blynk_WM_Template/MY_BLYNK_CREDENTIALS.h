/****************************************************************************************************************************
  MY_BLYNK_CREDENTIALS.h Blynk_WM_Template.ino
  For ESP32/ESP8266 boards
  Written by Thor Johnson (https://github.com/thorathome) May 2020 as a template for
  Blynk Wifi ESP communications. See https://github.com/thorathome/Blynk_Examples
   
  Blynk_Async_WM is a library, using AsyncWebServer instead of (ESP8266)WebServer for the ESP8266/ESP32 to enable easy
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi/Blynk.
  
  Based on and modified from Blynk library v0.6.1 (https://github.com/blynkkk/blynk-library/releases)
  Built by Khoi Hoang (https://github.com/khoih-prog/Blynk_Async_WM)
  Licensed under MIT license
  Version: 1.2.2

  Version    Modified By   Date      Comments
  -------    -----------  ---------- -----------
  1.0.16    K Hoang      25/08/2020 Initial coding to use (ESP)AsyncWebServer instead of (ESP8266)WebServer. 
                                    Bump up to v1.0.16 to sync with Blynk_WM v1.0.16
  1.1.0     K Hoang      26/11/2020 Add examples using RTOS MultiTask to avoid blocking in operation.
  1.2.0     K Hoang      01/01/2021 Add support to ESP32 LittleFS. Remove possible compiler warnings. Update examples. Add MRD
  1.2.1     K Hoang      16/01/2021 Add functions to control Config Portal from software or Virtual Switches
  1.2.2     K Hoang      28/01/2021 Fix Config Portal and Dynamic Params bugs
 ********************************************************************************************************************************/

#ifndef MY_BLYNK_CREDENTIALS_h
#define MY_BLYNK_CREDENTIALS_h

#define MY_BLYNK_SERVER               "blynk-cloud.com"
#define MY_WM_TEMPLATE_AUTHCODE       "0123456789abcdef0123456789abcdef"

#endif    //MY_BLYNK_CREDENTIALS_h
