/****************************************************************************************************************************
  bmp.h
  For ESP32 boards

  Blynk_Async_WM is a library, using AsyncWebServer instead of (ESP8266)WebServer for the ESP8266/ESP32 to enable easy
  configuration/reconfiguration and autoconnect/autoreconnect of WiFi/Blynk.
  
  Based on and modified from Blynk library v0.6.1 (https://github.com/blynkkk/blynk-library/releases)
  Built by Khoi Hoang (https://github.com/khoih-prog/Blynk_Async_WM)
  Licensed under MIT license
 ********************************************************************************************************************************/
 
// ArduinoMenu
// Height : 8 pixels
// Width  : 8 pixels

// Just fake bmp to satisfy compiler. You have to replace this with the real and working one.

const unsigned short wifi[64] PROGMEM =
{
  0x8410, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x8410, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

const unsigned short rec[64] PROGMEM =
{
  0x8410, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x8410, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 0x630c, 
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x630c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
