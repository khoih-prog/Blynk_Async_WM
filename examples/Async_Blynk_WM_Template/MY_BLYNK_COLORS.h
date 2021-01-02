/****************************************************************************************************************************
   MY_BLYNK_COLORS.h Blynk_WM_Template.ino
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

#ifndef MY_BLYNK_COLORS_h
#define MY_BLYNK_COLORS_h

// #include "MY_BLYNK_COLORS.h" 
// BLYNK COLOR PALETTE SAMPLE
#define BLYNK_GREEN             "#23C48E"
#define BLYNK_BLUE              "#04C0F8"
#define BLYNK_YELLOW            "#ED9D00"
#define BLYNK_RED               "#D3435C"
#define BLYNK_DARK_BLUE         "#5F7CD8"

#define BLYNK_WHITE             "#FFFFFF"
  
#define BLYNK_TEAL              "#00AE97"
#define BLYNK_REALLY_RED        "#F90000"
#define BLYNK_PLEASANT_GREEN    "#009140"
#define BLYNK_DK_GREY_BACKGRND  "#212266"

#endif    //MY_BLYNK_COLORS_h
