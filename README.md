## Blynk_Async_WM

[![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_Async_WM.svg?)](https://www.ardu-badge.com/Blynk_Async_WM)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Blynk_Async_WM.svg)](https://github.com/khoih-prog/Blynk_Async_WM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Blynk_Async_WM/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Blynk_Async_WM.svg)](http://github.com/khoih-prog/Blynk_Async_WM/issues)


---
---

### Why do we need this [Blynk_Async_WM library](https://github.com/khoih-prog/Blynk_Async_WM)

- Using asynchronous network means that you can handle **more than one connection at the same time**
- You are called once the request is ready and parsed
- When you send the response, you are **immediately ready** to handle other connections while the server is taking care of sending the response in the background
- **Speed is OMG**
- **Easy to use API, HTTP Basic and Digest MD5 Authentication (default), ChunkedResponse**
- Easily extensible to handle **any type of content**
- Supports Continue 100
- Async WebSocket plugin offering different locations without extra servers or ports
- Async EventSource (Server-Sent Events) plugin to send events to the browser
- URL Rewrite plugin for conditional and permanent url rewrites
- ServeStatic plugin that supports cache, Last-Modified, default index and more
- Simple template processing engine to handle templates

---

This is a Blynk and WiFiManager Library, using [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) instead of (ESP8266)WebServer, for configuring/auto(re)connecting ESP8266/ESP32 modules to the best or available MultiWiFi APs and MultiBlynk servers at runtime. Connection is with or without SSL. Configuration data to be saved in either LittleFS, SPIFFS or EEPROM. Default Credentials as well as Dynamic custom parameters can be added and modified easily without coding knowledge. DoubleResetDetector is used to force Config Portal opening even if the Credentials are still valid.
 
This library is designed to help you to eliminate `hardcoding` your Wifi and Blynk credentials for ESP8266 and ESP32 (with/without SSL), and updating/reflashing every time you need to change them.

Thanks to this [**Blynk_Async_WM library**](https://github.com/khoih-prog/Blynk_Async_WM) is based on and sync'ed with [`Blynk_WM library`](https://github.com/khoih-prog/Blynk_WM), all the features currently supported by [`Blynk_WM library`](https://github.com/khoih-prog/Blynk_WM) will be available. Please have a look at [`DONE`](https://github.com/khoih-prog/Blynk_Async_WM#done) or [`DONE in Blynk_WM library`](https://github.com/khoih-prog/Blynk_WM#done) for those too-many-to-list features.

---

### Releases v1.0.16

1. Initial coding to use [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) instead of (ESP8266)WebServer.
2. Bump up to v1.0.16 to sync with [Blynk_WiFiManager library](https://github.com/khoih-prog/Blynk_WM) v1.0.16.

---
---

## Prerequisite

1. [`Arduino IDE 1.8.13+` for Arduino](https://www.arduino.cc/en/Main/Software)
2. [`Blynk library 0.6.1+`](https://github.com/blynkkk/blynk-library/releases)
3. [`ESP32 core 1.0.4+`](https://github.com/espressif/arduino-esp32/releases) for ESP32 boards
4. [`ESP8266 core 2.7.4+`](https://github.com/esp8266/Arduino#installing-with-boards-manager) for ESP8266 boards. To use ESP8266 core 2.7.1+ for LittleFS.
5. [`ESP_DoubleResetDetector v1.0.3+`](https://github.com/khoih-prog/ESP_DoubleResetDetector) to use DRD feature. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_DoubleResetDetector.svg?)](https://www.ardu-badge.com/ESP_DoubleResetDetector).
6. [`ESPAsyncWebServer v1.2.3+`](https://github.com/me-no-dev/ESPAsyncWebServer).
7. [`ESPAsyncTCP v1.2.2+`](https://github.com/me-no-dev/ESPAsyncTCP) for ESP8266.
8. [`AsyncTCP v1.1.1+`](https://github.com/me-no-dev/AsyncTCP) for ESP32.

---

## Installation

### I) For Arduino IDE:

1. Be certain you have installed the most up to date version of Arduino IDE.
2. Be certain you have installed the most up-to-date Blynk library.
3. Using Arduino IDE, 
* either *use the zip file*
	 * **Navigate to the** [Blynk_Async_WM](https://github.com/khoih-prog/Blynk_Async_WM) page in Github.
	 * **Download the latest release** of `Blynk_Async_WM-master.zip` and save to your hard drive.
	 * **Open Arduino IDE.**
	 * Menu: Sketch->Include Library->Add .ZIP library…
	 * Select the downloaded `Blynk_Async_WM-master.zip` file
	 * Hit Open
  * Once Arduino IDE is finished installing the library, **EXIT Arduino IDE.**
	 
* or *use Arduino IDE's Library Manager*
	 * **Open Arduino IDE.**
  * Menu: Tools->**Manage Libraries…**
  * Wait for library list to populate.
  * Search for the keyword "Blynk". **Find Blynk_Async_WM** in the library list.
  * Select the latest version of the Blynk_Async_WM library.
  * Hit Install.
  * Once Arduino IDE is finished installing the library, **EXIT Arduino IDE.**

4. COPY the /certs files from the main Blynk library to the Blynk_Async_WM library.	
   * **Find the `Blynk/src/certs` library directory.** (This is in the main Blynk library, may be named differently.)
   * **Find the `Blynk_Async_WM/src/certs` library directory.** (This is in the installed Blynk_Async_WM library, may be named differently.) Using Arduino IDE, these directories are normally found under .../Arduino/Sketchbook/libraries or .../Arduino/libraries. 
      * *(Sometimes Arduino IDE names a library folder with an unhelpful name like Arduino_12345. You can safely rename that folder under …/libraries/ to a compliant name like Blynk_Async_WM for convenience. Remember to exit and restart IDE after renaming any library directory.)*
   * **COPY (do not cut and paste) the entire contents** of the `Blynk/src/certs` directory to the `Blynk_Async_WM/src/certs` directory.
      * *(FYI: the reason for copying the certs from the Blynk library to Blynk_Async_WM library is so that Blynk_Async_WM will have access to Blynk's SSL certificates. And you almost certainly want to be using SSL!)*
  * **You must do Step 4 each time you update the Blynk_Async_WM library** to keep those SSL certs accessible. 
   
5. **Open Arduino IDE.** Your library is installed.

### II) For VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install **Blynk_Async_WM** library by using [Library Manager](https://docs.platformio.org/en/latest/librarymanager/). Search for **Blynk_Async_WM** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---

### How to migrate from [Blynk_WiFiManager library](https://github.com/khoih-prog/Blynk_WM) 

In your code, just replacing

1. `BlynkSimpleEsp8266_WM.h`     with `BlynkSimpleEsp8266_Async_WM.h`      for ESP8266 `without SSL`
2. `BlynkSimpleEsp8266_SSL_WM.h` with `BlynkSimpleEsp8266_SSL_Async_WM.h`  for ESP8266 `with SSL`
3. `BlynkSimpleEsp32_WM.h`       with `BlynkSimpleEsp32_Async_WM.h`        for ESP32 `without SSL`
4. `BlynkSimpleEsp32_SSL_WM.h`   with `BlynkSimpleEsp32_SSL_Async_WM.h`    for ESP32 `with SSL`

### How to to migrate from Blynk

In your code, replace
1. `BlynkSimpleEsp8266.h`     with `BlynkSimpleEsp8266_Async_WM.h`      for ESP8266 `without SSL`
2. `BlynkSimpleEsp8266_SSL.h` with `BlynkSimpleEsp8266_SSL_Async_WM.h`  for ESP8266 `with SSL`
3. `BlynkSimpleEsp32.h`       with `BlynkSimpleEsp32_Async_WM.h`        for ESP32 `without SSL`
4. `BlynkSimpleEsp32_SSL.h`   with `BlynkSimpleEsp32_SSL_Async_WM.h`    for ESP32 `with SSL`

---

1. For EP8266, add

```
#define USE_LITTLEFS    true
#define USE_SPIFFS      false
```
to use LittleFS or

```
#define USE_LITTLEFS    false
#define USE_SPIFFS      true
```

to use SPIFFS or

```
#define USE_LITTLEFS    false
#define USE_SPIFFS      false
```
to use EEPROM.

2. For EP32, add

```
#define USE_SPIFFS      true
```

to use SPIFFS or

```
#define USE_SPIFFS    false
```
to use EEPROM.

Currently, data size, with DRD and not including dynamic params, is 380  bytes from address EEPROM_START ) to save your configuration data.

EEPROM_SIZE can be specified from 512 to 4096 (2048 for ESP32) bytes.

---

See examples [Async_ESP32WM_Config](examples/Async_ESP32WM_Config) and [Async_ESP8266WM_Config](examples/Async_ESP8266WM_Config).


```cpp
// Force some params in Blynk, only valid for library version 1.0.1 and later
#define TIMEOUT_RECONNECT_WIFI                    10000L
#define RESET_IF_CONFIG_TIMEOUT                   true
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5

```

To use personalized Config Portal AP SSID and Password, as well as IP Address, channel e.g. call :

```cpp
  // Set config portal SSID and Password
  Blynk.setConfigPortal("TestPortal-ESP8266", "TestPortalPass");
  // Set config portal IP address
  Blynk.setConfigPortalIP(IPAddress(192, 168, 200, 1));
  // Set config portal channel, default = 1. Use 0 => random channel from 1-13 to avoid conflict
  Blynk.setConfigPortalChannel(0);
```

You can specify STA-mode Static IP address,  Gateway, Subnet Mask, as well as DNS server 1 and 2:

```cpp
  // Select either one of these to set static IP
  Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0));
  //Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0),
  //                           IPAddress(192, 168, 2, 1), IPAddress(8, 8, 8, 8));
  //Blynk.setSTAStaticIPConfig(IPAddress(192, 168, 2, 220), IPAddress(192, 168, 2, 1), IPAddress(255, 255, 255, 0),
  //                           IPAddress(4, 4, 4, 4), IPAddress(8, 8, 8, 8));
```

Then replace `Blynk.begin(...)` with :

1. `Blynk.begin()` to use default DHCP hostname `ESP8266-XXXXXX` or `ESP32-XXXXXX`

or to have a personalized hostname `(RFC952-conformed,- 24 chars max,- only a..z A..Z 0..9 '-' and no '-' as last char)`

2. `Blynk.begin("Personalized-HostName")`

in your code. Keep `Blynk.run()` intact.

That's it.

---

Also see examples: 
 1. [Async_AM2315_ESP32_SSL](examples/Async_AM2315_ESP32_SSL)
 2. [Async_AM2315_ESP8266](examples/Async_AM2315_ESP8266)
 3. [Async_DHT11ESP32](examples/Async_DHT11ESP32) 
 4. [Async_DHT11ESP32_SSL](examples/Async_DHT11ESP32_SSL) 
 5. [Async_DHT11ESP8266](examples/Async_DHT11ESP8266)
 6. [Async_DHT11ESP8266_Debug](examples/Async_DHT11ESP8266_Debug)
 7. [Async_DHT11ESP8266_SSL](examples/Async_DHT11ESP82662_SSL) 
 8. [Async_ESP32WM_Config](examples/Async_ESP32WM_Config)
 9. [Async_ESP8266WM_Config](examples/Async_ESP8266WM_Config)
10. [Async_Blynk_WM_Template](examples/Async_Blynk_WM_Template)

---

## So, how it works?

If it cannot connect to the Blynk server in 30 seconds, no valid stored Credentials or Double Reset is detected within default abd configurable 10s, it will switch to `Configuration Mode`. You will see your built-in LED turned ON. In `Configuration Mode`, it starts an AP with default name `ESP_xxxxxx` and password `MyESP_xxxxxx` or configurable name and password you specified. The AP IP address is default at `192.168.4.1` or configured IP (e.g. `192.168.200.1`).

First, connect your (PC, Laptop, Tablet, phone, etc.) WiFi to Config Portal AP, then enter the WiFi password :

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/PortalAuth.jpg">
</p>

1. If you choose **not to load** default Credentials and Dynamic Parameters

After you connected, please, go to http://192.168.4.1 or the configured AP IP. The following Config Portal screen will appear:

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/Main.png">
</p>

2. If you choose **to load** default Credentials and Dynamic Parameters

After you connected, please, go to http://192.168.4.1 or the configured AP IP. The following  Config Portal screen will appear:

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/Default_Main.png">
</p>

Enter your WiFi and Blynk Credentials:

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/ConfigPortal.png">
</p>

Then click **Save**. The system will auto-restart. You will see the board's built-in LED turned OFF. That means, it's already connected to your Blynk server successfully.

---

### Important notes
1. Now you can use special chars such as **~, !, @, #, $, %, ^, &, _, -, space,etc.** thanks to [brondolin](https://github.com/brondolin) to provide the amazing fix to permit input special chars such as **%** and **#** into data fields. See [Issue 3](https://github.com/khoih-prog/Blynk_WM/issues/3).
2. The SSIDs, Passwords, BlynkServers and Tokens must be input (or to make them different from **nothing**). Otherwise, the Config Portal will re-open until those fields have been changed. If you don't need any field, just input anything or use duplicated data from similar field.
3. WiFi password max length now is 63 chars according to WPA2 standard.
4. Sometimes, it's hard or not possible to connect to Config Portal WiFi AP, the majority cases are caused by WiFi channel conflict if there are too many WiFi APs running around. Please use **random ConfigPortal WiFi AP channel** in sketch (see code snippet below) and reset the board so that another channel is used. Repeat until connection is OK

```cpp
// Set config portal channel, default = 1. Use 0 => random channel from 1-13 to avoid conflict
  Blynk.setConfigPortalChannel(0);
```

---

### How to use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

1. To load [Default Credentials](examples/Async_ESP32WM_Config/Credentials.h)

```cpp
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

2. To use system default to load "blank" when there is no valid Credentials

```cpp
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

3. Example of [Default Credentials](examples/Async_ESP32WM_Config/Credentials.h)

```cpp
/// Start Default Config Data //////////////////

/*
  // Defined in <BlynkSimpleEsp32_Async_WM.h> and <BlynkSimpleEsp32_SSL_Async_WM.h>

  #define SSID_MAX_LEN      32
  #define PASS_MAX_LEN      64
  
  typedef struct
  {
  char wifi_ssid[SSID_MAX_LEN];
  char wifi_pw  [PASS_MAX_LEN];
  }  WiFi_Credentials;

  #define BLYNK_SERVER_MAX_LEN      32
  #define BLYNK_TOKEN_MAX_LEN       36

  typedef struct
  {
  char blynk_server[BLYNK_SERVER_MAX_LEN];
  char blynk_token [BLYNK_TOKEN_MAX_LEN];
  }  Blynk_Credentials;

  #define NUM_WIFI_CREDENTIALS      2
  #define NUM_BLYNK_CREDENTIALS     2

  typedef struct Configuration
  {
  char header         [16];
  WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  int  blynk_port;
  char board_name     [24];
  int  checkSum;
  } Blynk_WM_Configuration;

*/

//bool LOAD_DEFAULT_CONFIG_DATA = true;
bool LOAD_DEFAULT_CONFIG_DATA = false;

Blynk_WM_Configuration defaultConfig =
{
  //char header[16], dummy, not used
#if USE_SSL  
  "SSL",
#else
  "NonSSL",
#endif
  //WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS]
  //WiFi_Creds.wifi_ssid and WiFi_Creds.wifi_pw
  "SSID1", "password1",
  "SSID2", "password2",
  // Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  // Blynk_Creds.blynk_server and Blynk_Creds.blynk_token
  "account.ddns.net",     "token",
  "account.duckdns.org",  "token1", 
  //int  blynk_port;
#if USE_SSL
  9443,
#else
  8080,
#endif
  //char board_name     [24];
  "ESP32-Async-Blynk",
  //int  checkSum, dummy, not used
  0
};

/////////// End Default Config Data /////////////
```

### How to add dynamic parameters from sketch

- To add custom parameters, just modify the example below

```cpp
#define USE_DYNAMIC_PARAMETERS      true

/////////////// Start dynamic Credentials ///////////////

//Defined in <BlynkSimpleEsp32_Async_WM.h> and <BlynkSimpleEsp32_SSL_Async_WM.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

  #define MAX_MQTT_SERVER_LEN      34
  char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "default-mqtt-server";
  
  #define MAX_MQTT_PORT_LEN        6
  char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "1883";
  
  #define MAX_MQTT_USERNAME_LEN      34
  char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "default-mqtt-username";
  
  #define MAX_MQTT_PW_LEN        34
  char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "default-mqtt-password";
  
  #define MAX_MQTT_SUBS_TOPIC_LEN      34
  char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "default-mqtt-SubTopic";
  
  #define MAX_MQTT_PUB_TOPIC_LEN       34
  char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "default-mqtt-PubTopic";
  
  MenuItem myMenuItems [] =
  {
    { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
    { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
    { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
    { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
    { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
    { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
  };
  
  uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

  MenuItem myMenuItems [] = {};
  
  uint16_t NUM_MENU_ITEMS = 0;
#endif


/////// // End dynamic Credentials ///////////

```cpp
- If you don't need to add dynamic parameters, use the following in sketch

```
#define USE_DYNAMIC_PARAMETERS     false
```

or

```cpp
/////////////// Start dynamic Credentials ///////////////

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
/////// // End dynamic Credentials ///////////

```

### Important Notes for using Dynamic Parameters' ids

1. These ids (such as "mqtt" in example) must be **unique**.

Please be noted that the following **reserved names are already used in library**:

```
"id"    for WiFi SSID
"pw"    for WiFi PW
"id1"   for WiFi1 SSID
"pw1"   for WiFi1 PW
"sv"    for Blynk Server
"tk"    for Blynk Token
"sv1"   for Blynk Server1
"tk1"   for Blynk Token1
"pt"    for Blynk Port
"nm"    for Board Name
```

---

The following is the sample terminal output when running example [Async_ESP8266WM_Config](examples/Async_ESP8266WM_Config)

1. No Config Data with **LOAD_DEFAULT_CONFIG_DATA = true** => Config Portal loads default Credentials and dynamic Params
cpp
```
Starting Async_ESP32WM_Config using SPIFFS with SSL on ESP32_DEV
[180] ======= Start Default Config Data =======
[180] Hdr=SSL,BrdName=ESP32-Async-Blynk
[180] SSID=SSID1,PW=password1
[180] SSID1=SSID2,PW1=password2
[182] Server=account.ddns.net,Token=token
[186] Server1=account.duckdns.org,Token1=token1
[190] Port=9443
[192] ======= End Config Data =======
[300] Hostname=ESP32-Async-Controller
[345] SaveCfgFile 
[345] WCSum=0x2585
[349] OK
[352] SaveBkUpCfgFile 
[356] OK
[359] SaveCredFile 
[359] CW1:pdata=default-mqtt-server,len=34
[359] CW1:pdata=1883,len=6
[359] CW1:pdata=default-mqtt-username,len=34
[360] CW1:pdata=default-mqtt-password,len=34
[364] CW1:pdata=default-mqtt-SubTopic,len=34
[368] CW1:pdata=default-mqtt-PubTopic,len=34
[374] OK
[374] CrWCSum=0x29a6
[377] SaveBkUpCredFile 
[377] CW2:pdata=default-mqtt-server,len=34
[381] CW2:pdata=1883,len=6
[383] CW2:pdata=default-mqtt-username,len=34
[387] CW2:pdata=default-mqtt-password,len=34
[391] CW2:pdata=default-mqtt-SubTopic,len=34
[395] CW2:pdata=default-mqtt-PubTopic,len=34
[401] OK
[401] ======= Start Loaded Config Data =======
[404] Hdr=SSL_ESP32,BrdName=ESP32-Async-Blynk
[408] SSID=SSID1,PW=password1
[411] SSID1=SSID2,PW1=password2
[414] Server=account.ddns.net,Token=token
[418] Server1=account.duckdns.org,Token1=token1
[422] Port=9443
[423] ======= End Config Data =======
[427] bg: noConfigPortal = true
[430] Connecting MultiWifi...
[49418] WiFi not connected
[49418] bg: Fail2connect WiFi+Blynk
[50315] 
stConf:SSID=TestPortal-ESP32,PW=TestPortalPass
[50315] IP=192.168.220.1,ch=10
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
RF
```

2. Input valid credentials with **LOAD_DEFAULT_CONFIG_DATA = true** => reboot

```cpp
Starting Async_ESP32WM_Config using SPIFFS with SSL on ESP32_DEV
[276] Hostname=ESP32-Async-Controller
[320] LoadCfgFile 
[321] OK
[321] ======= Start Stored Config Data =======
[321] Hdr=SSL_ESP32,BrdName=ESP32-Blynk-Async
[321] SSID=HueNet1,PW=12345678
[323] SSID1=HueNet2,PW1=12345678
[326] Server=********.duckdns.org,Token=********
[332] Server1=********.duckdns.org,Token1=********
[338] Port=9443
[340] ======= End Config Data =======
[343] CCSum=0x37af,RCSum=0x37af
[347] LoadCredFile 
[348] CrR:pdata=mqtt-server,len=34
[351] CrR:pdata=1883,len=6
[353] CrR:pdata=mqtt-user,len=34
[356] CrR:pdata=mqtt-pw,len=34
[359] CrR:pdata=Sub-Topics,len=34
[362] CrR:pdata=Pub-Topics,len=34
[365] OK
[366] CrCCsum=0x1379,CrRCsum=0x1379
[369] Valid Stored Dynamic Data
[372] Hdr=SSL_ESP32,BrdName=ESP32-Blynk-Async
[376] SSID=HueNet1,PW=12345678
[379] SSID1=HueNet2,PW1=12345678
[382] Server=********.duckdns.org,Token=********
[388] Server1=********.duckdns.org,Token1=********
[395] Port=9443
[396] ======= End Config Data =======
[399] bg: noConfigPortal = true
[402] Connecting MultiWifi...
[6739] WiFi connected after time: 1
[6739] SSID: HueNet1, RSSI = -37
[6739] Channel: 2, IP address: 192.168.2.98
[6739] bg: WiFi OK. Try Blynk
[6741] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[7754] NTP time: Mon Aug 24 06:28:38 2020
[7754] BlynkArduinoClient.connect: Connecting to ********.duckdns.org:9443
[9696] Certificate OK
[9737] Ready (ping: 40ms).
[9806] Connected to Blynk Server = ********.duckdns.org, Token = ********
[9806] bg: WiFi+Blynk OK

Blynk ESP32 using SPIFFS connected. Board Name : ESP32-Blynk-Async
B
Your stored Credentials :
MQTT Server = mqtt-server
Port = 1883
MQTT UserName = mqtt-user
MQTT PWD = mqtt-pw
Subs Topics = Sub-Topics
Pubs Topics = Pub-Topics
```

3. No Config Data with **LOAD_DEFAULT_CONFIG_DATA = false** => Config Portal loads "blank" to all fields

```
Starting Async_ESP32WM_Config using EEPROM without SSL on ESP32_DEV
[214] Hostname=ESP32-Async-Controller
[220] EEPROMsz:2048
[220] ======= Start Stored Config Data =======
[220] Hdr=SSL_ESP32,BrdName=Air-Control
[220] SSID=HueNet1,PW=12345678
[221] SSID1=HueNet,PW1=12345678
[224] Server=your_account.ddns.net,Token=OS5w5X_XRmME9ytSi7P_M6ss-Bt4BYUO
[230] Server1=your_account.duckdns.org,Token1=OS5w5X_XRmME9ytSi7P_M6ss-Bt4BYUO
[236] Port=9443
[238] ======= End Config Data =======
[241] CCSum=0x343a,RCSum=0x343a
[244] CR:pdata=default-mqtt-server,len=34
[248] CR:pdata=1883,len=6
[250] CR:pdata=default-mqtt-username,len=34
[254] CR:pdata=default-mqtt-password,len=34
[258] CR:pdata=default-mqtt-SubTopic,len=34
[262] CR:pdata=default-mqtt-PubTopic,len=34
[266] CrCCsum=0x29a6,CrRCsum=0x29a6
[269] Valid Stored Dynamic Data
[272] InitEEPROM,sz=2048,DataSz=556
[275] g:myMenuItems[0]=blank
[277] g:myMenuItems[1]=blank
[280] g:myMenuItems[2]=blank
[283] g:myMenuItems[3]=blank
[285] g:myMenuItems[4]=blank
[288] g:myMenuItems[5]=blank
[290] SaveEEPROM,sz=2048,CSum=0x1444
[294] CW:pdata=blank,len=34
[296] CW:pdata=blank,len=6
[299] CW:pdata=blank,len=34
[301] CW:pdata=blank,len=34
[304] CW:pdata=blank,len=34
[306] CW:pdata=blank,len=34
[309] CrWCSum=0xc30
[362] bg: Stay forever in config portal.No configDat
[1207] 
stConf:SSID=TestPortal-ESP32,PW=TestPortalPass
[1207] IP=192.168.220.1,ch=10
F
Your stored Credentials :
MQTT Server = blank
Port = blank
MQTT UserName = blank
MQTT PWD = blank
Subs Topics = blank
Pubs Topics = blank
[55106] h1:myMenuItems[0]=blank
[55106] h1:myMenuItems[1]=blank
[55107] h1:myMenuItems[2]=blank
[55107] h1:myMenuItems[3]=blank
[55107] h1:myMenuItems[4]=blank
[55109] h1:myMenuItems[5]=blank
RFRFRF
[205949] id: = HueNet1
[205972] pw = 12345678
[206010] id1 = HueNet2
[206040] pw1 = 12345678
[206058] sv = your_account.ddns.net
[206081] tk = ********
[206105] sv1 = your_account.duckdns.org
[206123] tk1 = ********
[206148] pt = 8080
[206163] nm = ESP32-Blynk-Async
[206181] h:mqtt=mqtt-server
[206181] h2:myMenuItems[0]=mqtt-server
[206197] h:mqpt=1883
[206197] h2:myMenuItems[1]=1883
[206213] h:user=mqtt-user
[206213] h2:myMenuItems[2]=mqtt-user
[206230] h:mqpw=mqtt-pw
[206230] h2:myMenuItems[3]=mqtt-pw
[206270] h:subs=Sub-Topics
[206270] h2:myMenuItems[4]=Sub-Topics
[206287] h:pubs=Pub-Topics
[206287] h2:myMenuItems[5]=Pub-Topics
[206288] h:UpdEEPROM
[206288] SaveEEPROM,sz=2048,CSum=0x34c2
[206288] CW:pdata=mqtt-server,len=34
[206290] CW:pdata=1883,len=6
[206293] CW:pdata=mqtt-user,len=34
[206296] CW:pdata=mqtt-pw,len=34
[206299] CW:pdata=Sub-Topics,len=34
[206302] CW:pdata=Pub-Topics,len=34
[206305] CrWCSum=0x1379
[206370] h:Rst
```

4. Input valid credentials with **LOAD_DEFAULT_CONFIG_DATA = false** => reboot

```cpp
Starting Async_ESP32WM_Config using EEPROM without SSL on ESP32_DEV
[152] Hostname=ESP32-Async-Controller
[158] EEPROMsz:2048
[158] ======= Start Stored Config Data =======
[158] Hdr=ESP32,BrdName=ESP32-Blynk-Async
[158] SSID=HueNet1,PW=12345678
[160] SSID1=HueNet2,PW1=12345678
[163] Server=your_account.ddns.net,Token=********
[169] Server1=your_account.duckdns.org,Token1=********
[175] Port=8080
[176] ======= End Config Data =======
[180] CCSum=0x34c2,RCSum=0x34c2
[183] CR:pdata=mqtt-server,len=34
[186] CR:pdata=1883,len=6
[188] CR:pdata=mqtt-user,len=34
[191] CR:pdata=mqtt-pw,len=34
[194] CR:pdata=Sub-Topics,len=34
[196] CR:pdata=Pub-Topics,len=34
[199] CrCCsum=0x1379,CrRCsum=0x1379
[203] Valid Stored Dynamic Data
[205] Hdr=ESP32,BrdName=ESP32-Blynk-Async
[209] SSID=HueNet1,PW=12345678
[212] SSID1=HueNet2,PW1=12345678
[215] Server=your_account.ddns.net,Token=********
[221] Server1=your_account.duckdns.org,Token1=********
[227] Port=8080
[229] ======= End Config Data =======
[232] bg: noConfigPortal = true
[235] Connecting MultiWifi...
[7299] WiFi connected after time: 1
[7299] SSID:HueNet1,RSSI=-37
[7299] Channel:2,IP address:192.168.2.98
[7299] bg: WiFi OK. Try Blynk
[7300] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[7313] BlynkArduinoClient.connect: Connecting to your_account.ddns.net:8080
[7407] Ready (ping: 4ms).
[7475] Connected to Blynk Server = your_account.ddns.net, Token = ********
[7475] bg: WiFi+Blynk OK

Blynk ESP32 using EEPROM connected. Board Name : ESP32-Blynk-Async
EEPROM size = 2048 bytes, EEPROM start address = 0 / 0x0
B
Your stored Credentials :
MQTT Server = mqtt-server
Port = 1883
MQTT UserName = mqtt-user
MQTT PWD = mqtt-pw
Subs Topics = Sub-Topics
Pubs Topics = Pub-Topics
```

5. **No DRD detected** => no Config Portal with valid Credentials

```
Starting Async_ESP32WM_Config using SPIFFS with SSL on ESP32_DEV
[276] Hostname=ESP32-Async-Controller
[320] LoadCfgFile 
[321] OK
[321] ======= Start Stored Config Data =======
[321] Hdr=SSL_ESP32,BrdName=ESP32-Blynk-Async
[321] SSID=HueNet1,PW=12345678
[323] SSID1=HueNet2,PW1=12345678
[326] Server=********.duckdns.org,Token=********
[332] Server1=********.duckdns.org,Token1=********
[338] Port=9443
[340] ======= End Config Data =======
[343] CCSum=0x37af,RCSum=0x37af
[347] LoadCredFile 
[348] CrR:pdata=mqtt-server,len=34
[351] CrR:pdata=1883,len=6
[353] CrR:pdata=mqtt-user,len=34
[356] CrR:pdata=mqtt-pw,len=34
[359] CrR:pdata=Sub-Topics,len=34
[362] CrR:pdata=Pub-Topics,len=34
[365] OK
[366] CrCCsum=0x1379,CrRCsum=0x1379
[369] Valid Stored Dynamic Data
[372] Hdr=SSL_ESP32,BrdName=ESP32-Blynk-Async
[376] SSID=HueNet1,PW=12345678
[379] SSID1=HueNet2,PW1=12345678
[382] Server=********.duckdns.org,Token=********
[388] Server1=********.duckdns.org,Token1=********
[395] Port=9443
[396] ======= End Config Data =======
[399] bg: noConfigPortal = true
[402] Connecting MultiWifi...
[6739] WiFi connected after time: 1
[6739] SSID: HueNet1, RSSI = -37
[6739] Channel: 2, IP address: 192.168.2.98
[6739] bg: WiFi OK. Try Blynk
[6741] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[7754] NTP time: Mon Aug 24 06:28:38 2020
[7754] BlynkArduinoClient.connect: Connecting to ********.duckdns.org:9443
[9696] Certificate OK
[9737] Ready (ping: 40ms).
[9806] Connected to Blynk Server = ********.duckdns.org, Token = ********
[9806] bg: WiFi+Blynk OK

Blynk ESP32 using SPIFFS connected. Board Name : ESP32-Blynk-Async
B
Your stored Credentials :
MQTT Server = mqtt-server
Port = 1883
MQTT UserName = mqtt-user
MQTT PWD = mqtt-pw
Subs Topics = Sub-Topics
Pubs Topics = Pub-Topics
```

6. **DRD detected** => Config Portal even with valid Credentials

```

Starting Async_ESP32WM_Config using SPIFFS with SSL on ESP32_DEV
[180] Double Reset Detected
[328] Hostname=ESP32-Async-Controller
[414] LoadCfgFile 
[415] OK
[415] ======= Start Stored Config Data =======
[415] Hdr=SSL_ESP32,BrdName=ESP32-Async-Blynk
[415] SSID=SSID1,PW=password1
[417] SSID1=SSID2,PW1=password2
[420] Server=account.ddns.net,Token=token
[423] Server1=account.duckdns.org,Token1=token1
[428] Port=9443
[429] ======= End Config Data =======
[433] CCSum=0x2585,RCSum=0x2585
[436] LoadCredFile 
[437] CrR:pdata=default-mqtt-server,len=34
[441] CrR:pdata=1883,len=6
[443] CrR:pdata=default-mqtt-username,len=34
[447] CrR:pdata=default-mqtt-password,len=34
[451] CrR:pdata=default-mqtt-SubTopic,len=34
[455] CrR:pdata=default-mqtt-PubTopic,len=34
[459] OK
[460] CrCCsum=0x29a6,CrRCsum=0x29a6
[464] Valid Stored Dynamic Data
[466] Hdr=SSL_ESP32,BrdName=ESP32-Async-Blynk
[470] SSID=SSID1,PW=password1
[473] SSID1=SSID2,PW1=password2
[476] Server=account.ddns.net,Token=token
[480] Server1=account.duckdns.org,Token1=token1
[484] Port=9443
[485] ======= End Config Data =======
[489] bg: Stay forever in config portal.DRD detected
[1339] 
stConf:SSID=TestPortal-ESP32,PW=TestPortalPass
[1339] IP=192.168.220.1,ch=10
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic

```

7. Testing WiFi and Blynk Server lost to verify auto-reconnection

```
Starting Async_ESP32WM_Config using SPIFFS with SSL on ESP32_DEV
[275] Hostname=ESP32-Async-Controller
[319] LoadCfgFile 
[320] OK
[320] ======= Start Stored Config Data =======
[320] Hdr=SSL_ESP32,BrdName=ESP32-Blynk-Async
[320] SSID=HueNet1,PW=12345678
[322] SSID1=HueNet2,PW1=12345678
[325] Server=your_account.duckdns.org,Token=********
[331] Server1=your_account.duckdns.org,Token1=********
[337] Port=8080
[339] ======= End Config Data =======
[342] CCSum=0x3757,RCSum=0x3757
[346] LoadCredFile 
[347] CrR:pdata=mqtt-server,len=34
[350] CrR:pdata=1883,len=6
[353] CrR:pdata=mqtt-user,len=34
[355] CrR:pdata=mqtt-pw,len=34
[358] CrR:pdata=Sub-Topics,len=34
[361] CrR:pdata=Pub-Topics,len=34
[364] OK
[365] CrCCsum=0x1379,CrRCsum=0x1379
[368] Valid Stored Dynamic Data
[371] Hdr=SSL_ESP32,BrdName=ESP32-Blynk-Async
[375] SSID=HueNet1,PW=12345678
[378] SSID1=HueNet2,PW1=12345678
[381] Server=your_account.duckdns.org,Token=********
[387] Server1=your_account.duckdns.org,Token1=********
[394] Port=8080
[395] ======= End Config Data =======
[398] bg: noConfigPortal = true
[401] Connecting MultiWifi...
[6319] WiFi connected after time: 1
[6319] SSID: HueNet1, RSSI = -43
[6319] Channel: 2, IP address: 192.168.2.98
[6319] bg: WiFi OK. Try Blynk
[6321] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[7334] NTP time: Mon Aug 24 14:09:41 2020
[7334] BlynkArduinoClient.connect: Connecting to your_account.duckdns.org:9443
[10135] Certificate OK
[10144] Ready (ping: 8ms).
[10213] Connected to Blynk Server = your_account.duckdns.org, Token = ********
[10213] bg: WiFi+Blynk OK

Blynk ESP32 using SPIFFS connected. Board Name : ESP32-Blynk-Async
B
Your stored Credentials :
MQTT Server = mqtt-server
Port = 1883
MQTT UserName = mqtt-user
MQTT PWD = mqtt-pw
Subs Topics = Sub-Topics
Pubs Topics = Pub-Topics
[26580] run: WiFi lost. Reconnect WiFi+Blynk
[26580] Connecting MultiWifi...
[34389] WiFi connected after time: 2
[34389] SSID: HueNet2, RSSI = -54
[34389] Channel: 4, IP address: 192.168.2.98
[34389] run: WiFi reconnected. Connect to Blynk
[34392] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[34406] NTP time: Mon Aug 24 14:10:08 2020
[34409] BlynkArduinoClient.connect: Connecting to your_account.duckdns.org:9443
[36249] Certificate OK
[36264] Ready (ping: 14ms).
[36332] Connected to Blynk Server = your_account.duckdns.org, Token = ********
[36332] run: WiFi+Blynk reconnected

```

You can see that the system automatically detects and connects to the best or avaiable WiFi APs and/or Blynk Servers, whenever interruption happens. This feature is very useful for systems requiring high degree of reliability.

Moreover, this `Blynk.begin()` is **not a blocking call**, so you can use it for critical functions requiring in loop(). 
Anyway, this is better for projects using Blynk just for GUI (graphical user interface).

In operation, if WiFi or Blynk connection is lost, `Blynk.run()` will try reconnecting automatically. Therefore, `Blynk.run()` must be called in the `loop()` function. Don't use:

```cpp
void loop()
{
  if (Blynk.connected())
     Blynk.run();
     
  ...
}
```
just

```cpp
void loop()
{
  Blynk.run();
  ...
}
```
---
---

## Example [Async_ESP32WM_Config](examples/Async_ESP32WM_Config)

Please take a look at other examples, as well.

1. File [Async_ESP32WM_Config.ino](examples/Async_ESP32WM_Config/Async_ESP32WM_Config.ino)

```cpp
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
```

2. File [defines.h](examples/Async_ESP32WM_Config/defines.h)

```cpp
#ifndef defines_h
#define defines_h

#ifndef ESP32
  #error This code is intended to run on the ESP32 platform! Please check your Tools->Board setting.
#endif

#define BLYNK_PRINT Serial

#define DOUBLERESETDETECTOR_DEBUG     false
#define BLYNK_WM_DEBUG                3

// Not use #define USE_SPIFFS  => using EEPROM for configuration data in WiFiManager
// #define USE_SPIFFS    false => using EEPROM for configuration data in WiFiManager
// #define USE_SPIFFS    true  => using SPIFFS for configuration data in WiFiManager
// Be sure to define USE_SPIFFS before #include <BlynkSimpleEsp8266_Async_WM.h>

#define USE_SPIFFS                  true
//#define USE_SPIFFS                  false

#if (!USE_SPIFFS)
  // EEPROM_SIZE must be <= 2048 and >= CONFIG_DATA_SIZE (currently 172 bytes)
  #define EEPROM_SIZE    (2 * 1024)
  // EEPROM_START + CONFIG_DATA_SIZE must be <= EEPROM_SIZE
  #define EEPROM_START   0
#endif

// Force some params in Blynk, only valid for library version 1.0.1 and later
#define TIMEOUT_RECONNECT_WIFI                    10000L
#define RESET_IF_CONFIG_TIMEOUT                   true
#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5
// Those above #define's must be placed before #include <BlynkSimpleEsp8266_Async_WM.h>

#define USE_SSL   true
//#define USE_SSL   false

#if USE_SSL
  #include <BlynkSimpleEsp32_SSL_Async_WM.h>      //https://github.com/khoih-prog/Blynk_Async_WM
#else
  #include <BlynkSimpleEsp32_Async_WM.h>          //https://github.com/khoih-prog/Blynk_Async_WM
#endif

#define PIN_D22   22            // Pin D22 mapped to pin GPIO22/SCL of ESP32

#define DHT_PIN     PIN_D22     // pin DATA @ D22 / GPIO22
#define DHT_TYPE    DHT11

#define HOST_NAME   "ESP32-Async-Controller"

#endif      //defines_h
```

3. File [Credentials.h](examples/Async_ESP32WM_Config/Credentials.h)

```cpp
#ifndef Credentials_h
#define Credentials_h

/// Start Default Config Data //////////////////

/*
  // Defined in <BlynkSimpleEsp32_Async_WM.h> and <BlynkSimpleEsp32_SSL_Async_WM.h>

  #define SSID_MAX_LEN      32
  #define PASS_MAX_LEN      64
  
  typedef struct
  {
  char wifi_ssid[SSID_MAX_LEN];
  char wifi_pw  [PASS_MAX_LEN];
  }  WiFi_Credentials;

  #define BLYNK_SERVER_MAX_LEN      32
  #define BLYNK_TOKEN_MAX_LEN       36

  typedef struct
  {
  char blynk_server[BLYNK_SERVER_MAX_LEN];
  char blynk_token [BLYNK_TOKEN_MAX_LEN];
  }  Blynk_Credentials;

  #define NUM_WIFI_CREDENTIALS      2
  #define NUM_BLYNK_CREDENTIALS     2

  typedef struct Configuration
  {
  char header         [16];
  WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS];
  Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  int  blynk_port;
  char board_name     [24];
  int  checkSum;
  } Blynk_WM_Configuration;

*/

//bool LOAD_DEFAULT_CONFIG_DATA = true;
bool LOAD_DEFAULT_CONFIG_DATA = false;

Blynk_WM_Configuration defaultConfig =
{
  //char header[16], dummy, not used
#if USE_SSL  
  "SSL",
#else
  "NonSSL",
#endif
  //WiFi_Credentials  WiFi_Creds  [NUM_WIFI_CREDENTIALS]
  //WiFi_Creds.wifi_ssid and WiFi_Creds.wifi_pw
  "SSID1", "password1",
  "SSID2", "password2",
  // Blynk_Credentials Blynk_Creds [NUM_BLYNK_CREDENTIALS];
  // Blynk_Creds.blynk_server and Blynk_Creds.blynk_token
  "account.ddns.net",     "token",
  "account.duckdns.org",  "token1", 
  //int  blynk_port;
#if USE_SSL
  9443,
#else
  8080,
#endif
  //char board_name     [24];
  "ESP32-Async-Blynk",
  //int  checkSum, dummy, not used
  0
};

/////////// End Default Config Data /////////////


#endif    //Credentials_h
```


4. File [dynamicParams.h](examples/Async_ESP32WM_Config/dynamicParams.h)

```cpp
#ifndef dynamicParams_h
#define dynamicParams_h

#define USE_DYNAMIC_PARAMETERS      true

/////////////// Start dynamic Credentials ///////////////

//Defined in <BlynkSimpleEsp32_Async_WM.h> and <BlynkSimpleEsp32_SSL_Async_WM.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#if USE_DYNAMIC_PARAMETERS

  #define MAX_MQTT_SERVER_LEN      34
  char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "default-mqtt-server";
  
  #define MAX_MQTT_PORT_LEN        6
  char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "1883";
  
  #define MAX_MQTT_USERNAME_LEN      34
  char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "default-mqtt-username";
  
  #define MAX_MQTT_PW_LEN        34
  char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "default-mqtt-password";
  
  #define MAX_MQTT_SUBS_TOPIC_LEN      34
  char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "default-mqtt-SubTopic";
  
  #define MAX_MQTT_PUB_TOPIC_LEN       34
  char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "default-mqtt-PubTopic";
  
  MenuItem myMenuItems [] =
  {
    { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
    { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
    { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
    { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
    { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
    { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
  };
  
  uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

  MenuItem myMenuItems [] = {};
  
  uint16_t NUM_MENU_ITEMS = 0;
#endif


/////// // End dynamic Credentials ///////////

#endif      //dynamicParams_h
```

---
---

## TO DO

1. Fix bug. Add enhancement

## DONE

 1. Permit EEPROM size and location configurable to avoid conflict with others.
 2. More flexible to configure reconnection timeout.
 3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
 4. If the config data not entered completely (SSID, password, Server and Blynk token), entering config portal
 5. Correct the operation of BUILTIN_LED
 6. Modify code to be compatible with ESP8266 core pre-2.5.2.
 7. Add RFC952 hostname
 8. Add configurable Config Portal IP, SSID and Password
 9. Add configurable Static IP, GW, Subnet Mask and 2 DNS Servers' IP Addresses.
10. Add checksum for more reliable data
11. Add MultiWiFi feature to enable reconnect to the best / available WiFi AP.
12. Add MultiBlynk feature to enable reconnect to the best / available Blynk Server.
13. WiFi Password max length is 63, as in WPA2 standards
14. Permit to input special chars such as **%** and **#** into data fields.
15. Add Dynamic Parameters with checksum
16. Default Credentials and dynamic parameters
17. **DoubleDetectDetector** to force Config Portal when double reset is detected within predetermined time, default 10s.
18. Configurable Config Portal Title
19. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device.
20. Add **LittleFS** support to ESP8266 as SPIFFS deprecated since **ESP8266 core 2.7.1.**
21. Using [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) instead of (ESP8266)WebServer.

---
---

### Releases v1.0.16

1. Initial coding to use [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) instead of (ESP8266)WebServer.
2. Bump up to v1.0.16 to sync with [Blynk_WiFiManager library](https://github.com/khoih-prog/Blynk_WM) v1.0.16.


---
---

### Contributions and thanks

1. Thanks to [me-no-dev](https://github.com/me-no-dev) for great [ESPAsyncWebServer Library](https://github.com/me-no-dev/ESPAsyncWebServer), [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP) and [AsyncTCP](https://github.com/me-no-dev/AsyncTCP).
2. Thanks to [thorathome in GitHub](https://github.com/thorathome) and [thorathome in Blynk](https://community.blynk.cc/u/thorathome) to test, find bug, suggest and encourage to add those new features in [Blynk_WiFiManager library](https://github.com/khoih-prog/Blynk_WM) v1.0.13, such as Default Credentials/Dynamic Parms, Configurable Config Portal Title, DRD. The powerful [Async_Blynk_WM_Template](examples/Async_Blynk_WM_Template) is written by [thorathome](https://github.com/thorathome) and is included in the examples with his permission. See [WM Config Portal using BlynkSimpleEsp32/8266_WM.h](https://community.blynk.cc/t/wm-config-portal-using-blynksimpleesp32-8266-wm-h/45402).
3. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for working with, developing, debugging and testing.

<table>
  <tr>
    <td align="center"><a href="https://github.com/me-no-dev"><img src="https://github.com/me-no-dev.png" width="100px;" alt="me-no-dev"/><br /><sub><b>⭐️⭐️ me-no-dev</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/thorathome"><img src="https://github.com/thorathome.png" width="100px;" alt="thorathome"/><br /><sub><b>⭐️ thorathome</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>tcpipchip</b></sub></a><br /></td>
  </tr> 
</table>

---

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

## Copyright

Copyright 2020- Khoi Hoang
