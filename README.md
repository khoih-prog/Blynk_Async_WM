## Blynk_Async_WM

[![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_Async_WM.svg?)](https://www.ardu-badge.com/Blynk_Async_WM)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Blynk_Async_WM.svg)](https://github.com/khoih-prog/Blynk_Async_WM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Blynk_Async_WM/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Blynk_Async_WM.svg)](http://github.com/khoih-prog/Blynk_Async_WM/issues)
[![star this repo](https://githubbadges.com/star.svg?user=khoih-prog&repo=Blynk_Async_WM)](https://github.com/khoih-prog/Blynk_Async_WM)

---
---

## Table of Contents

* [Why do we need this Blynk_Async_WM library](#why-do-we-need-this-blynk_async_wm-library)
  * [Features](#features)
  * [Why using Async](#why-using-async)
  * [Why using SSL insecured mode now](#why-using-ssl-insecured-mode-now)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](#changelog)
  * [Releases v1.6.1](#releases-v161)
  * [Major Releases v1.6.0](#major-releases-v160)
  * [Major Releases v1.5.0](#major-releases-v150)
  * [Releases v1.4.1](#releases-v141)
  * [Major Releases v1.4.0](#major-releases-v140)
  * [Major Releases v1.3.0](#major-releases-v130)
  * [Releases v1.2.3](#releases-v123)
  * [Releases v1.2.2](#releases-v122)
  * [Releases v1.2.1](#releases-v121)
  * [Major Releases v1.2.0](#major-releases-v120)
  * [Releases v1.1.0](#releases-v110)
  * [Releases v1.0.16](#releases-v1016)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [I) For Arduino IDE](#i-for-arduino-ide)
  * [II) For VS Code & PlatformIO:](#ii-for-vs-code--platformio)
* [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide)
  * [1. Save the original esp32 core](#1-save-the-original-esp32-core)
  * [2. Install esp32 core v1.0.6](#2-install-esp32-core-v106)
    * [2.1 Install esp32 core](#21-install-esp32-core)
    * [2.2 Download latest zip with esp32-s2 support](#22-download-latest-zip-with-esp32-s2-support)
    * [2.3 Unzip](#23-unzip)
    * [2.3 Update esp32 core directories](#24-update-esp32-core-directories)
  * [3. Download tools for ESP32-S2](#3-download-tools-for-esp32-s2) 
    * [3.1 Download Toolchain for Xtensa (ESP32-S2) based on GCC](#31-download-toolchain-for-xtensa-esp32-s2-based-on-gcc)
    * [3.2 Download esptool](#32-download-esptool)
    * [3.3 Unzip](#33-unzip)
  * [4. Update tools](#4-update-tools)
    * [4.1 Update Toolchain](#41-update-toolchain)
    * [4.2 Update esptool](#42-update-esptool)
  * [5. Download tools for ESP32-C3](#5-download-tools-for-esp32-c3)
  * [6. esp32-s2 WebServer Library Patch](#6-esp32-s2-webserver-library-patch)
  * [7. esp32-c3 ESPAsyncWebServer Library Patch](#7-esp32-c3-espasyncwebserver-library-patch)
* [Note for Platform IO using ESP32 LittleFS](#note-for-platform-io-using-esp32-littlefs) 
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [How to migrate from Blynk_WM library](#how-to-migrate-from-blynk_wm-library)
* [How to migrate from Blynk](#how-to-migrate-from-blynk)
* [HOWTO use default Credentials and have them pre-loaded onto Config Portal](#howto-use-default-credentials-and-have-them-pre-loaded-onto-config-portal)
  * [ 1. To load Default Credentials](#1-to-load-default-credentials)
  * [ 2. To use system default to load "blank" when there is no valid Credentials](#2-to-use-system-default-to-load-blank-when-there-is-no-valid-credentials)
  * [ 3. Example of Default Credentials](#3-example-of-default-credentials)
  * [ 4. How to add dynamic parameters from sketch](#4-how-to-add-dynamic-parameters-from-sketch)
  * [ 5. If you don't need to add dynamic parameters](#5-if-you-dont-need-to-add-dynamic-parameters)
  * [ 6. To use custom HTML Style](#6-to-use-custom-html-style)
  * [ 7. To use custom Head Elements](#7-to-use-custom-head-elements)
  * [ 8. To use CORS Header](#8-to-use-cors-header)
  * [ 9. To use and input only one set of WiFi SSID and PWD](#9-to-use-and-input-only-one-set-of-wifi-ssid-and-pwd)
    * [ 9.1 If you need to use and input only one set of WiFi SSID/PWD](#91-if-you-need-to-use-and-input-only-one-set-of-wifi-ssidpwd)
    * [ 9.2 If you need to use both sets of WiFi SSID/PWD](#92-if-you-need-to-use-both-sets-of-wifi-ssidpwd)
  * [10. To enable auto-scan of WiFi networks for selection in Configuration Portal](#10-to-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [10.1 Enable auto-scan of WiFi networks for selection in Configuration Portal](#101-enable-auto-scan-of-wifi-networks-for-selection-in-configuration-portal)
    * [10.2 Disable manually input SSIDs](#102-disable-manually-input-ssids)
    * [10.3 Select maximum number of SSIDs in the list](#103-select-maximum-number-of-ssids-in-the-list)
* [Important Notes for using Dynamic Parameters' ids](#important-notes-for-using-dynamic-parameters-ids)
* [Important Notes](#important-notes)
* [Why using this Blynk_Async_WM with MultiWiFi-MultiBlynk features](#why-using-this-blynk_async_wm-with-multiwifi-multiblynk-features)
* [Examples](#examples)
  * [Not using MultiTasking](#not-using-multitasking)
    * [ 1. Async_AM2315_ESP32_SSL](examples/Async_AM2315_ESP32_SSL)
    * [ 2. Async_AM2315_ESP8266](examples/Async_AM2315_ESP8266)
    * [ 3. Async_DHT11ESP32](examples/Async_DHT11ESP32)
    * [ 4. Async_DHT11ESP32_SSL](examples/Async_DHT11ESP32_SSL)
    * [ 5. Async_DHT11ESP8266](examples/Async_DHT11ESP8266)
    * [ 6. Async_DHT11ESP8266_Debug](examples/Async_DHT11ESP8266_Debug)
    * [ 7. Async_DHT11ESP8266_SSL](examples/Async_DHT11ESP82662_SSL)
    * [ 8. Async_ESP32WM_Config](examples/Async_ESP32WM_Config)
    * [ 9. Async_ESP8266WM_Config](examples/Async_ESP8266WM_Config)
    * [10. Async_Blynk_WM_Template](examples/Async_Blynk_WM_Template)
    * [11. **Async_ESP32WM_MRD_Config**](examples/Async_ESP32WM_MRD_Config)
    * [12. **Async_ESP8266WM_MRD_Config**](examples/Async_ESP8266WM_MRD_Config)
    * [13. **Async_ESP32WM_ForcedConfig**](examples/Async_ESP32WM_ForcedConfig) 
    * [14. **Async_ESP32WM_MRD_ForcedConfig**](examples/Async_ESP32WM_MRD_ForcedConfig)
    * [15. **Async_ESP8266WM_ForcedConfig**](examples/Async_ESP8266WM_ForcedConfig)
    * [16. **Async_ESP8266WM_MRD_ForcedConfig**](examples/Async_ESP8266WM_MRD_ForcedConfig)
  * [Using Free-RTOS MultiTasking for ESP32](#using-free-rtos-multitasking-for-esp32)
    * [ 1. Async_ESP32_MultiTask](examples/ESP32_MultiTask/Async_ESP32_MultiTask)
    * [ 2. AsyncMT_AM2315_ESP32_SSL](examples/ESP32_MultiTask/AsyncMT_AM2315_ESP32_SSL)
    * [ 3. AsyncMT_DHT11ESP32](examples/ESP32_MultiTask/AsyncMT_DHT11ESP32)
    * [ 4. AsyncMT_DHT11ESP32_SSL](examples/ESP32_MultiTask/AsyncMT_DHT11ESP32_SSL)
    * [ 5. AsyncMT_ESP32WM_Config](examples/ESP32_MultiTask/AsyncMT_ESP32WM_Config)
    * [ 6. **AsyncMT_ESP32WM_ForcedConfig**](examples/ESP32_MultiTask/AsyncMT_ESP32WM_ForcedConfig)
* [So, how it works?](#so-how-it-works)
  * [ 1. Without SCAN_WIFI_NETWORKS](#1-without-scan_wifi_networks)
  * [ 2. With SCAN_WIFI_NETWORKS](#2-with-scan_wifi_networks)
* [Example Async_ESP32WM_MRD_ForcedConfig](#example-async_esp32wm_mrd_forcedconfig)
  * [1. File Async_ESP32WM_MRD_ForcedConfig.ino](#1-file-async_esp32wm_mrd_forcedconfigino)
  * [2. File defines.h](#2-file-definesh) 
  * [3. File Credentials.h](#3-file-credentialsh) 
  * [4. File dynamicParams.h](#4-file-dynamicparamsh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. Async_ESP8266WM_MRD_Config using LittleFS with SSL on ESP8266_NODEMCU_ESP12E](#1-async_esp8266wm_mrd_config-using-littlefs-with-ssl-on-esp8266_nodemcu_esp12e)
    * [1.1. No MultiReset Detected => Running normally](#11-no-multireset-detected--running-normally)
    * [1.2. MultiReset Detected => Enter Config Portal](#12-multireset-detected--enter-config-portal)
    * [1.3. Exit Config Portal with Data](#13-exit-config-portal-with-data)
  * [2. Async_ESP32WM_MRD_Config using LITTLEFS without SSL on ESP32_DEV](#2-async_esp32wm_mrd_config-using-littlefs-with-ssl-on-esp32_dev)
    * [2.1. No MultiReset Detected => Running normally](#21-no-multireset-detected--running-normally)
    * [2.2. MultiReset Detected => Enter Config Portal](#22-multireset-detected--enter-config-portal)
    * [2.3. Exit Config Portal with Data](#23-exit-config-portal-with-data)
    * [2.4. WiFi Lost => AutoReconnect WiFi and Blynk](#24-wifi-lost-autoreconnect-wifi-and-blynk)
  * [3. Async_ESP32_MultiTask using LittleFS without SSL on ESP32_DEV](#3-async_esp32_multitask-using-littlefs-without-ssl-on-esp32_dev) 
  * [4. Async_ESP32WM_MRD_ForcedConfig using non-persistent ConfigPortal virtual button](#4-async_esp32wm_mrd_forcedconfig-using-non-persistent-configportal-virtual-button)
    * [4.1. Start normally then press non-persistent ConfigPortal virtual button](#41-start-normally-then-press-non-persistent-configportal-virtual-button)
    * [4.2. Enter non-persistent ConfigPortal](#42-enter-non-persistent-configportal)
    * [4.3. Exit Config Portal with Saved Data](#43-exit-config-portal-with-saved-data)
  * [5. Async_ESP32WM_MRD_ForcedConfig using persistent ConfigPortal virtual button](#5-async_esp32wm_mrd_forcedconfig-using-persistent-configportal-virtual-button)
    * [5.1. Start normally then press persistent ConfigPortal virtual button](#51-start-normally-then-press-persistent-configportal-virtual-button)
    * [5.2. Enter persistent ConfigPortal](#52-enter-persistent-configportal)
    * [5.3. Exit Config Portal with Saved Data](#53-exit-config-portal-with-saved-data)
 * [6. Async_ESP32WM_ForcedConfig using LittleFS with SSL on ESP32S2_DEV](#6-async_esp32wm_forcedconfig-using-littlefs-with-ssl-on-esp32s2_dev)
 * [7. Async_ESP32WM_MRD_ForcedConfig using LITTLEFS with SSL on ESP32_DEV to demo WiFi Scan](#7-async_esp32wm_mrd_forcedconfig-using-littlefs-with-ssl-on-esp32_dev-to-demo-wifi-scan)
    * [7.1 MRD/DRD => Open Config Portal](#71-mrddrd--open-config-portal)
    * [7.2 Config Data Saved => Connection to Blynk](#72-config-data-saved--connection-to-blynk)
 * [8. Async_ESP8266WM_MRD_Config using LITTLEFS with SSL on ESP8266_NODEMCU_ESP12E using new ESP8266 core v3.0.1](#8-async_esp8266wm_mrd_config-using-littlefs-with-ssl-on-esp8266_nodemcu_esp12e-using-new-esp8266-core-v301)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Releases](#releases)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)


---
---

### Why do we need this [Blynk_Async_WM library](https://github.com/khoih-prog/Blynk_Async_WM)

#### Features

This is a Blynk and WiFiManager Library, using [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) instead of (ESP8266)WebServer, for configuring/auto(re)connecting ESP8266/ESP32 modules to the best or available MultiWiFi APs and MultiBlynk servers at runtime. Connection is with or without SSL. Configuration data to be saved in either LittleFS, SPIFFS or EEPROM. Default Credentials as well as Dynamic custom parameters can be added and modified easily without coding knowledge. DoubleResetDetector is used to force Config Portal opening even if the Credentials are still valid.

This library is designed to help you to eliminate `hardcoding` your Wifi and Blynk credentials for ESP8266 and ESP32 (with/without SSL), and updating/reflashing every time you need to change them.

Thanks to this [**Blynk_Async_WM library**](https://github.com/khoih-prog/Blynk_Async_WM) is based on and sync'ed with [`Blynk_WM library`](https://github.com/khoih-prog/Blynk_WM), all the features currently supported by [`Blynk_WM library`](https://github.com/khoih-prog/Blynk_WM) will be available. Please have a look at [`DONE`](https://github.com/khoih-prog/Blynk_Async_WM#done) or [`DONE in Blynk_WM library`](https://github.com/khoih-prog/Blynk_WM#done) for those too-many-to-list features.

With version `v1.6.0` or later, you can use:

1. `New ESP8266 core v3.0.0`

#### Why using Async

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

#### Why using SSL insecured mode now

This so-called **"insecured mode"** 

1. permits you to actually connect to a **TLS server** (port 443,9443, etc., especially with expired CA Certs such as **Blynk Cloud**). It won't let you connect to plain non-SSL server because full encryption is still required.
2. You never have to worry about CA Certs' update and to include every trusted CA root certificate of every TLS server
3. Still requires **encryption**. It just does not **validate the certificate or fingerprint**. Insecure because we could be subject to a **MITM** (**M**an-**I**n-**T**he-**M**iddle) attack.
4. It's still much better than **plain non-SSL** mode which just communicates using no encryption at all.

So this is the much better choice.

For more information, check [Blynk WiFiManager for ESP8266/ESP32 (including ESP32-S2, ESP32-C3) with Multi-WiFi and Multi-Blynk. Fix SSL issue for Blynk Cloud Server now](https://community.blynk.cc/t/blynk-wifimanager-for-esp8266-esp32-including-esp32-s2-esp32-c3-with-multi-wifi-and-multi-blynk-fix-ssl-issue-for-blynk-cloud-server-now/41011/40) and [ESP8266 SSL connections down using Blynk_WiFiManager (ESP32 works fine, non-SSL 8266 works fine)](https://community.blynk.cc/t/esp8266-ssl-connections-down-using-blynk-wifimanager-esp32-works-fine-non-ssl-8266-works-fine/52144/19)

#### Currently supported Boards

This [**Blynk_Async_WM** library](https://github.com/khoih-prog/Blynk_Async_WM) currently supports these following boards:

 1. **ESP8266 and ESP32-based boards using EEPROM, SPIFFS or LittleFS**.
 2. **ESP32-S2 (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.) using EEPROM, SPIFFS or LittleFS**.
 3. **ESP32-C3 (ARDUINO_ESP32C3_DEV) using EEPROM or SPIFFS**.
 
---
---

## Changelog

### Releases v1.6.1

1. Add configurable connectMultiWiFi parameters. Check [Minimize blocking during multi-wifi reconnect #6](https://github.com/khoih-prog/Blynk_Async_WM/issues/6)
2. Update ESP8266_CORE_VERSION for ESP8266 core v3.0.1+

### Major Releases v1.6.0

1. Fix AP connect issue caused by **breaking ESP8266 core v3.0.0**. Caused by multiple core changes, but the new solution results a better and faster connection to AP.
2. Fix SSL issue caused by breaking ESP8266 core v3.0.0. Now the better **BearSSL** is used in both ESP32 and ESP8266 to replace the ESP8266 deprecated `axTLS`. Check [Remove axTLS from code and documentation #7437](https://github.com/esp8266/Arduino/pull/7437)
3. Fix the `BLYNK_INFO_DEVICE`displaying the generic ESP8266 board with Blynk logo. Caused by new ESP8266 core changes of `build.board`. For example from `ESP8266_NODEMCU` in core v2.7.4 to `ESP8266_NODEMCU_ESP12E` in core v3.0.0
4. Fix many warnings only displayed in new core ESP8266 v3.0.0
5. Make code compatible for either new ESP8266 core v3.0.0+ or ealier cores v2.7.4-

### Major Releases v1.5.0

1. Enable scan of WiFi networks for selection in Configuration Portal. Check [PR for v1.3.0 - Enable scan of WiFi networks #10](https://github.com/khoih-prog/WiFiManager_NINA_Lite/pull/10). Now you can select optional **SCAN_WIFI_NETWORKS**, **MANUAL_SSID_INPUT_ALLOWED** to be able to manually input SSID, not only from a scanned SSID lists and **MAX_SSID_IN_LIST** (from 2-15)
2. Fix invalid "blank" Config Data treated as Valid.
3. Permit optionally inputting one set of WiFi SSID/PWD by using `REQUIRE_ONE_SET_SSID_PW == true`
4. Enforce WiFi PWD minimum length of 8 chars
5. Minor enhancement to not display garbage when data is invalid

### Releases v1.4.1

1. Fix issue of custom Blynk port (different from 8080 or 9443) not working on ESP32. Check [Custom Blynk port not working for BlynkSimpleEsp32_Async_WM.h #4](https://github.com/khoih-prog/Blynk_Async_WM/issues/4)

### Major Releases v1.4.0

1. Add **LittleFS and SPIFFS** support to new **ESP32-S2** boards (**Arduino ESP32C3_DEV**). Check [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).
2. Add **EEPROM and SPIFFS** support to new **ESP32-C3** boards (**Arduino ESP32C3_DEV**). Check [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).
3. Fix SSL issue with Blynk Cloud Server
4. Update examples

### Major Releases v1.3.0

1. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header.
2. Add support to **ESP32-S2 (ESP32-S2 Saola and AI-Thinker ESP-12K)**. Currently using EEPROM only. To add support to LittleFS and SPIFFS in future releases.
3. Fix Config Portal Bug.
4. Tested with [**Latest ESP32 Core 1.0.5**](https://github.com/espressif/arduino-esp32) for ESP32-based boards.
5. Update examples

### Releases v1.2.3

1. To permit auto-reset after configurable timeout if DRD/MRD or non-persistent forced-CP. Check [**Good new feature: Blynk.resetAndEnterConfigPortal() Thanks & question #27**](https://github.com/khoih-prog/Blynk_WM/issues/27)

### Releases v1.2.2

1. Fix rare Config Portal bug not updating Config and dynamic Params data successfully in very noisy or weak WiFi situation

### Releases v1.2.1

1. Add functions to control Config Portal from software or Virtual Switches. Check [How to trigger a Config Portal from code #25](https://github.com/khoih-prog/Blynk_WM/issues/25)
2. Add examples to demo the new Virtual ConfigPortal SW feature
3. Optimize code

### Major Releases v1.2.0

1. Add support to LittleFS for ESP32 using [LITTLEFS](https://github.com/lorol/LITTLEFS) Library
2. Add support to MultiDetectDetector. **MultiDetectDetector** feature to force Config Portal when configurable multi-reset is detected within predetermined time.
3. Clean-up all compiler warnings possible.
4. Add Table of Contents
5. Modify Version String
6. Add MRD-related examples.


### Releases v1.1.0

1. Add examples using RTOS MultiTask to avoid blocking in operation.
2. Add Version String.


### Releases v1.0.16

1. Initial coding to use [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) instead of (ESP8266)WebServer.
2. Bump up to v1.0.16 to sync with [Blynk_WiFiManager library](https://github.com/khoih-prog/Blynk_WM) v1.0.16.

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.15+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Blynk library 0.6.1+`](https://github.com/blynkkk/blynk-library/releases). [![Latest release](https://img.shields.io/github/release/blynkkk/blynk-library.svg)](https://github.com/blynkkk/blynk-library/releases/latest/). Never use the `Blynk beta` versions.
 3. [`ESP32 Core 1.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 4. [`ESP32-S2/C3 Core 1.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-S2/C3-based boards. Must follow [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).
 5. [`ESP8266 Core 3.0.1+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS. 
 6. [`ESP_DoubleResetDetector library 1.1.1+`](https://github.com/khoih-prog/ESP_DoubleResetDetector) to use DRD feature. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_DoubleResetDetector.svg?)](https://www.ardu-badge.com/ESP_DoubleResetDetector).
 7. [`ESP_MultiResetDetector library 1.1.1+`](https://github.com/khoih-prog/ESP_MultiResetDetector) to use MRD feature. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP_MultiResetDetector.svg?)](https://www.ardu-badge.com/ESP_MultiResetDetector).
 8. [`LittleFS_esp32 v1.0.6+`](https://github.com/lorol/LITTLEFS) for ESP32-based boards using LittleFS. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_esp32.svg?)](https://www.ardu-badge.com/LittleFS_esp32). **Notice**: This [`LittleFS_esp32 library`](https://github.com/lorol/LITTLEFS) has been integrated to Arduino [esp32 core v1.0.6](https://github.com/espressif/arduino-esp32/tree/master/libraries/LITTLEFS).
 9. [`ESPAsyncWebServer v1.2.3+`](https://github.com/me-no-dev/ESPAsyncWebServer).
10. [`ESPAsyncTCP v1.2.2+`](https://github.com/me-no-dev/ESPAsyncTCP) for ESP8266.
11. [`AsyncTCP v1.1.1+`](https://github.com/me-no-dev/AsyncTCP) for ESP32.

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
3. Install [**Blynk_Async_WM** library](https://platformio.org/lib/show/11085/Blynk_Async_WM) or [**Blynk_Async_WM** library](https://platformio.org/lib/show/11511/Blynk_Async_WM) by using [Library Manager](https://platformio.org/lib/show/11085/Blynk_Async_WM/installation). Search for **Blynk_Async_WM** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

## HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE


These are instructions demonstrating the steps to install esp32-s2/c3 core on Ubuntu machines. For Windows or other OS'es, just follow the the similar principles and steps.

* Windows 10, follows these steps in [Steps to install Arduino ESP32 support on Windows](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/windows.md) 

* Mac OS, follows these steps in [Installation instructions for Mac OS](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/mac.md)

* Fedora, follows these steps in [Installation instructions for Fedora](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/fedora.md)

* openSUSE, follows these steps in [Installation instructions for openSUSE](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/opensuse.md)

* You can also try to add [package_esp32_dev_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json) into Arduino IDE `File - Preferences - Additional Boards Manager URLs` 


```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
```

and have Board Manager auto-install the **development** esp32 core. For example : esp32 core `v2.0.0-alpha1`


---

If you're already successful in testing the core, after installing by using the above procedures, you don't need to follows the hereafter manual steps.

---

Assuming you already installed Arduino IDE ESP32 core and the installed directory is

`/home/your_account/.arduino15/packages/esp32`


### 1. Save the original esp32 core

First, copy the whole original esp32 core to another safe place. Then delete all the sub-directories of

`/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.4`

---


### 2. Install esp32 core v1.0.6

#### 2.1 Install esp32 core

Just use Arduino IDE Board Manager to install [ESP32 Arduino Release 1.0.6 based on ESP-IDF v3.3.5](https://github.com/espressif/arduino-esp32/releases/tag/1.0.6). This official v1.06 core doesn't have esp32-s2/s3 support. You have to download and use the latest master branch.


#### 2.2 Download latest zip with esp32-s2 support

As of **April 16th 2021**, the **esp32-s2/c3** board support has been included in master branch of esp32 core. Download [**esp32 core, master branch**](https://github.com/espressif/arduino-esp32) in the zip format.

#### 2.3 Unzip

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/esp32_s2_Core_Unzipped.png">
</p>

#### 2.4 Update esp32 core directories

Copy all subdirectories of esp32 core into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6`


---

### 3 Download tools for ESP32-S2


#### 3.1 Download Toolchain for Xtensa (ESP32-S2) based on GCC

Download [**esp32-s2 Toolchain**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-guides/tools/idf-tools.html#xtensa-esp32s2-elf) corresponding to your environment (linux-amd64, win64, etc.).

For example `xtensa-esp32s2-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz`, then un-archive.


<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/esp32_s2_Toolchain.png">
</p>

#### 3.2 Download esptool


Download [esptool](https://github.com/espressif/esptool/releases) int the `zip` format:

`esptool-3.0.zip`

#### 3.3 Unzip

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/esp32_s2_esptool.png">
</p>

---

### 4. Update tools

#### 4.1 Update Toolchain

Copy whole `xtensa-esp32s2-elf` directory into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6/tools`


#### 4.2 Update esptool

Rename `esptool-3.0` directory to `esptool`


Copy whole `esptool` directory into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6/tools`


<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/esp32_s2_tools.png">
</p>


### 5 Download tools for ESP32-C3

Download [**esp32-c3 Toolchain**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-guides/tools/idf-tools.html#riscv32-esp-elf) corresponding to your environment (linux-amd64, win64, etc.).

For example`riscv32-esp-elf-gcc8_4_0-crosstool-ng-1.24.0-123-g64eb9ff-linux-amd64.tar.gz`, then un-archive.

Then using the similar steps as in

* [3. Download tools for ESP32-S2](#3-download-tools-for-esp32-s2) 
  * [3.1 Download Toolchain for Xtensa (ESP32-S2) based on GCC](#31-download-toolchain-for-xtensa-esp32-s2-based-on-gcc)
  * [3.2 Download esptool](#32-download-esptool)
  * [3.3 Unzip](#33-unzip)
* [4. Update tools](#4-update-tools)
  * [4.1 Update Toolchain](#41-update-toolchain)
  * [4.2 Update esptool](#42-update-esptool)

then copy whole `riscv32-esp-elf` directory into `/home/your_account/.arduino15/packages/esp32/hardware/esp32/1.0.6/tools`

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/Blynk_Async_ESP32_C3_Support.png">
</p>


### 6. esp32-s2 WebServer Library Patch

#### Necessary only for esp32 core v1.0.6-

If you haven't installed a new version with [WebServer.handleClient delay PR #4350](https://github.com/espressif/arduino-esp32/pull/4350) or haven't applied the above mentioned PR, you have to use the following patch.


**To be able to run Config Portal on ESP32-S2 boards**, you have to copy the files in [esp32-s2 WebServer Patch](esp32s2_WebServer_Patch/) directory into esp32-s2 WebServer library directory (~/.arduino15/packages/esp32/hardware/esp32/1.0.4/libraries/WebServer).

Supposing the esp32-s2 version is 1.0.4, these files `WebServer.h/cpp` must be copied into the directory to replace:

- `~/.arduino15/packages/esp32/hardware/esp32/1.0.4/libraries/WebServer/src/WebServer.h`
- `~/.arduino15/packages/esp32/hardware/esp32/1.0.4/libraries/WebServer/src/WebServer.cpp`

### 7. esp32-c3 ESPAsyncWebServer Library Patch


If you haven't installed a new version with [Fix compiler error for ESP32-C3 #970](https://github.com/me-no-dev/ESPAsyncWebServer/pull/970) or haven't applied the above mentioned PR, you have to use the following patch.


**To be able to compile on ESP32-C3 boards**, you have to copy the file in [AsyncWebSocket.cpp](esp32c3_ESPAsyncWebServer_Patch/AsyncWebSocket.cpp) directory into Arduino ESPAsyncWebServer library directory (~/Arduino/libraries/ESPAsyncWebServer/src/AsyncWebSocket.cpp)

Not fixing the file, you'll receive the compile error as follows :

```
/home/aa/Arduino/libraries/ESPAsyncWebServer-master/src/AsyncWebSocket.cpp: In member function 'IPAddress AsyncWebSocketClient::remoteIP()':
/home/aa/Arduino/libraries/ESPAsyncWebServer-master/src/AsyncWebSocket.cpp:843:28: error: call of overloaded 'IPAddress(unsigned int)' is ambiguous
         return IPAddress(0U);
                            ^
```


---

That's it. You're now ready to compile and test for ESP32-S2 now

---
---

### Note for Platform IO using ESP32 LittleFS

#### Necessary only for esp32 core v1.0.6-

From esp32 core v1.0.6+, [`LittleFS_esp32 v1.0.6`](https://github.com/lorol/LITTLEFS) has been included and this step is not necessary anymore.

In Platform IO, to fix the error when using [`LittleFS_esp32 v1.0`](https://github.com/lorol/LITTLEFS) for ESP32-based boards with ESP32 core v1.0.4- (ESP-IDF v3.2-), uncomment the following line

from

```
//#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

to

```
#define CONFIG_LITTLEFS_FOR_IDF_3_2   /* For old IDF - like in release 1.0.4 */
```

It's advisable to use the latest [`LittleFS_esp32 v1.0.5+`](https://github.com/lorol/LITTLEFS) to avoid the issue.

Thanks to [Roshan](https://github.com/solroshan) to report the issue in [Error esp_littlefs.c 'utime_p'](https://github.com/khoih-prog/ESPAsync_WiFiManager/issues/28) 

---
---

### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use ADC2 for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use ADC2 with WiFi/BlueTooth (BT/BLE).
- Use ADC1, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by ADC2 (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

---
---

### How to migrate from [Blynk_WM library](https://github.com/khoih-prog/Blynk_WM) 

In your code, just replacing

1. `BlynkSimpleEsp8266_WM.h`     with `BlynkSimpleEsp8266_Async_WM.h`      for ESP8266 `without SSL`
2. `BlynkSimpleEsp8266_SSL_WM.h` with `BlynkSimpleEsp8266_SSL_Async_WM.h`  for ESP8266 `with SSL`
3. `BlynkSimpleEsp32_WM.h`       with `BlynkSimpleEsp32_Async_WM.h`        for ESP32 `without SSL`
4. `BlynkSimpleEsp32_SSL_WM.h`   with `BlynkSimpleEsp32_SSL_Async_WM.h`    for ESP32 `with SSL`

### How to migrate from Blynk

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

---

2. For EP32, add

```
#define USE_LITTLEFS          true
#define USE_SPIFFS            false
```

to use LittleFS or


```
#define USE_LITTLEFS          false
#define USE_SPIFFS            true
```

to use SPIFFS or

```
#define USE_LITTLEFS          false
#define USE_SPIFFS            false
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
---

### HOWTO Use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

#### 1. To load [Default Credentials](examples/ESP32WM_Config/Credentials.h)

```cpp
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

#### 2. To use system default to load "blank" when there is no valid Credentials

```cpp
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

#### 3. Example of [Default Credentials](examples/ESP32WM_Config/Credentials.h)

```cpp
/// Start Default Config Data //////////////////

/*
  // Defined in <BlynkSimpleEsp32_WM.h> and <BlynkSimpleEsp32_SSL_WM.h>

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

bool LOAD_DEFAULT_CONFIG_DATA = true;
//bool LOAD_DEFAULT_CONFIG_DATA = false;

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
  "Air-Control",
  //int  checkSum, dummy, not used
  0
};

/////////// End Default Config Data /////////////
```

### 4. How to add dynamic parameters from sketch

- To add custom parameters, just modify the example below

```cpp
#define USE_DYNAMIC_PARAMETERS      true

/////////////// Start dynamic Credentials ///////////////

//Defined in <BlynkSimpleEsp32_WM.h> and <BlynkSimpleEsp32_SSL_WM.h>
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

```
#### 5. If you don't need to add dynamic parameters

Use the following code snippet in sketch

```cpp
#define USE_DYNAMIC_PARAMETERS     false
```

or

```cpp
/////////////// Start dynamic Credentials ///////////////

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;
/////// // End dynamic Credentials ///////////

```

#### 6. To use custom HTML Style

```
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";

...

Blynk.setCustomsStyle(NewCustomsStyle);
```

#### 7. To use custom Head Elements


```
Blynk.setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
```

#### 8. To use CORS Header

```
Blynk.setCORSHeader("Your Access-Control-Allow-Origin");
```

#### 9. To use and input only one set of WiFi SSID and PWD

#### 9.1 If you need to use and input only one set of WiFi SSID/PWD

```
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       true
```
But it's always advisable to use and input both sets for reliability.
 
#### 9.2 If you need to use both sets of WiFi SSID/PWD

```
// Permit input only one set of WiFi SSID/PWD. The other can be "NULL or "blank"
// Default is false (if not defined) => must input 2 sets of SSID/PWD
#define REQUIRE_ONE_SET_SSID_PW       false
```

#### 10. To enable auto-scan of WiFi networks for selection in Configuration Portal

#### 10.1 Enable auto-scan of WiFi networks for selection in Configuration Portal


```
#define SCAN_WIFI_NETWORKS                  true
```

The manual input of SSIDs is default enabled, so that users can input arbitrary SSID, not only from the scanned list. This is for the sample use-cases in which users can input the known SSIDs of another place, then send the boards to that place. The boards can connect to WiFi without users entering Config Portal to re-configure.

#### 10.2 Disable manually input SSIDs

```
// To disable manually input SSID, only from a scanned SSID lists
#define MANUAL_SSID_INPUT_ALLOWED           false
```

This is for normal use-cases in which users can only select an SSID from a scanned list of SSIDs to avoid typo mistakes and/or security.

#### 10.3 Select maximum number of SSIDs in the list

The maximum number of SSIDs in the list is seletable from 2 to 15. If invalid number of SSIDs is selected, the default number of 10 will be used.


```
// From 2-15
#define MAX_SSID_IN_LIST                    8
```

---
---

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
---

### Why using this [Blynk_Async_WM](https://github.com/khoih-prog/Blynk_Async_WM) with MultiWiFi-MultiBlynk features

You can see that the system **automatically detects and connects to the best or avaiable WiFi APs and/or Blynk Servers**, whenever interruption happens. This feature is very useful for systems requiring high degree of reliability.

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


### Examples

#### Not using MultiTasking

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
11. [**Async_ESP32WM_MRD_Config**](examples/Async_ESP32WM_MRD_Config)
12. [**Async_ESP8266WM_MRD_Config**](examples/Async_ESP8266WM_MRD_Config)
13. [**Async_ESP32WM_ForcedConfig**](examples/Async_ESP32WM_ForcedConfig) 
14. [**Async_ESP32WM_MRD_ForcedConfig**](examples/Async_ESP32WM_MRD_ForcedConfig) 
15. [**Async_ESP8266WM_ForcedConfig**](examples/Async_ESP8266WM_ForcedConfig)
16. [**Async_ESP8266WM_MRD_ForcedConfig**](examples/Async_ESP8266WM_MRD_ForcedConfig)

#### Using Free-RTOS MultiTasking for ESP32

 1. [Async_ESP32_MultiTask](examples/ESP32_MultiTask/Async_ESP32_MultiTask)
 2. [AsyncMT_AM2315_ESP32_SSL](examples/ESP32_MultiTask/AsyncMT_AM2315_ESP32_SSL)
 3. [AsyncMT_DHT11ESP32](examples/ESP32_MultiTask/AsyncMT_DHT11ESP32) 
 4. [AsyncMT_DHT11ESP32_SSL](examples/ESP32_MultiTask/AsyncMT_DHT11ESP32_SSL) 
 5. [AsyncMT_ESP32WM_Config](examples/ESP32_MultiTask/AsyncMT_ESP32WM_Config)
 6. [**AsyncMT_ESP32WM_ForcedConfig**](examples/ESP32_MultiTask/AsyncMT_ESP32WM_ForcedConfig)

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

### 1. Without SCAN_WIFI_NETWORKS


<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/ConfigPortal.png">
</p>


### 2. With SCAN_WIFI_NETWORKS


<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/Input_With_Scan.png">
</p>


Then click **Save**. The system will auto-restart. You will see the board's built-in LED turned OFF. That means, it's already connected to your Blynk server successfully.

<p align="center">
    <img src="https://github.com/khoih-prog/Blynk_Async_WM/blob/master/pics/Saved.png">
</p>


---
---

## Example [Async_ESP32WM_MRD_ForcedConfig](examples/Async_ESP32WM_MRD_ForcedConfig)

Please take a look at other examples, as well.

#### 1. File [Async_ESP32WM_MRD_ForcedConfig.ino](examples/Async_ESP32WM_MRD_ForcedConfig/Async_ESP32WM_MRD_ForcedConfig.ino)


```cpp
#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

#include <Ticker.h>
#include <DHT.h>        // https://github.com/adafruit/DHT-sensor-library

DHT dht(DHT_PIN, DHT_TYPE);
BlynkTimer timer;
Ticker     led_ticker;

#define BLYNK_PIN_FORCED_CONFIG           V10
#define BLYNK_PIN_FORCED_PERS_CONFIG      V20

// Use button V10 (BLYNK_PIN_FORCED_CONFIG) to forced Config Portal
BLYNK_WRITE(BLYNK_PIN_FORCED_CONFIG)
{ 
  if (param.asInt())
  {
    Serial.println( F("\nCP Button Hit. Rebooting") ); 

    // This will keep CP once, clear after reset, even you didn't enter CP at all.
    Blynk.resetAndEnterConfigPortal(); 
  }
}

// Use button V20 (BLYNK_PIN_FORCED_PERS_CONFIG) to forced Persistent Config Portal
BLYNK_WRITE(BLYNK_PIN_FORCED_PERS_CONFIG)
{ 
  if (param.asInt())
  {
    Serial.println( F("\nPersistent CP Button Hit. Rebooting") ); 
   
    // This will keep CP forever, until you successfully enter CP, and Save data to clear the flag.
    Blynk.resetAndEnterConfigPortalPersistent();
  }
}

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
  Serial.print(F("R"));
}

void set_led(byte status)
{
  digitalWrite(LED_BUILTIN, status);
}

void heartBeatPrint()
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

  if (num == 40)
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
  Serial.print(F("\nStarting Async_ESP32WM_MRD_ForcedConfig using "));
  Serial.print(CurrentFileFS);
#else
  Serial.print(F("\nStarting Async_ESP32WM_MRD_ForcedConfig using EEPROM"));
#endif

#if USE_SSL
  Serial.print(F(" with SSL on ")); Serial.println(ARDUINO_BOARD);
#else
  Serial.print(F(" without SSL on ")); Serial.println(ARDUINO_BOARD);
#endif  

  Serial.println(BLYNK_ASYNC_WM_VERSION);
  
#if USING_MRD
  Serial.println(ESP_MULTI_RESET_DETECTOR_VERSION);
#else
  Serial.println(ESP_DOUBLE_RESET_DETECTOR_VERSION);
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

  timer.setInterval(60 * 1000, readAndSendData);

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
}

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

void displayCredentialsInLoop()
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

void loop()
{
  Blynk.run();
  timer.run();
  check_status();

#if USE_DYNAMIC_PARAMETERS
  displayCredentialsInLoop();
#endif
}
```

#### 2. File [defines.h](examples/Async_ESP32WM_MRD_ForcedConfig/defines.h)

```cpp
/*
  // To add something similar to this for ESP32-C3
  #if CONFIG_IDF_TARGET_ESP32
  const int8_t esp32_adc2gpio[20] = {36, 37, 38, 39, 32, 33, 34, 35, -1, -1, 4, 0, 2, 15, 13, 12, 14, 27, 25, 26};
  #elif CONFIG_IDF_TARGET_ESP32S2
  const int8_t esp32_adc2gpio[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  #elif CONFIG_IDF_TARGET_ESP32C3
  const int8_t esp32_adc2gpio[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  #endif 
 */
 
#ifndef defines_h
#define defines_h

#ifndef ESP8266
  #error This code is intended to run on the ESP8266 platform! Please check your Tools->Board setting.
#endif

#define BLYNK_PRINT        Serial

#define BLYNK_WM_DEBUG     3

#define USING_MRD           true

#if USING_MRD
  // These definitions must be placed before #include <ESP_MultiResetDetector.h> to be used
  // Otherwise, default values (MRD_TIMES = 3, MRD_TIMEOUT = 10 seconds and MRD_ADDRESS = 0) will be used
  // Number of subsequent resets during MRD_TIMEOUT to activate
  #define MRD_TIMES               3
  
  // Number of seconds after reset during which a subseqent reset will be considered a mlti reset.
  #define MRD_TIMEOUT             10
  
  // RTC/EEPPROM Address for the MultiResetDetector to use
  #define MRD_ADDRESS             0

  #define MULTIRESETDETECTOR_DEBUG       true 
  
  #warning Using MultiResetDetector MRD
#else
  // These definitions must be placed before #include <ESP_DoubleResetDetector.h> to be used
  // Otherwise, default values (DRD_TIMEOUT = 10 seconds and DRD_ADDRESS = 0) will be used
  // Number of subsequent resets during DRD_TIMEOUT to activate
  
  // Number of seconds after reset during which a subseqent reset will be considered a mlti reset.
  #define DRD_TIMEOUT             10

// RTC/EEPPROM Address for the DoubleResetDetector to use
  #define DRD_ADDRESS             0

  #define DOUBLERESETDETECTOR_DEBUG     false
  
  #warning Using DoubleResetDetector DRD 
#endif

// #define USE_SPIFFS and USE_LITTLEFS   false        => using EEPROM for configuration data in WiFiManager
// #define USE_LITTLEFS    true                       => using LITTLEFS for configuration data in WiFiManager
// #define USE_LITTLEFS    false and USE_SPIFFS true  => using SPIFFS for configuration data in WiFiManager
// Be sure to define USE_LITTLEFS and USE_SPIFFS before #include <BlynkSimpleEsp8266_WM.h>
// From ESP8266 core 2.7.1, SPIFFS will be deprecated and to be replaced by LittleFS
// Select USE_LITTLEFS (higher priority) or USE_SPIFFS

#define USE_LITTLEFS                true
#define USE_SPIFFS                  false

#if USE_LITTLEFS
  //LittleFS has higher priority
  #define CurrentFileFS     "LittleFS"
  #ifdef USE_SPIFFS
    #undef USE_SPIFFS
  #endif
  #define USE_SPIFFS                  false
#elif USE_SPIFFS
  #define CurrentFileFS     "SPIFFS"
#endif


#if !( USE_LITTLEFS || USE_SPIFFS)
  // EEPROM_SIZE must be <= 4096 and >= CONFIG_DATA_SIZE (currently 172 bytes)
  #define EEPROM_SIZE    (4 * 1024)
  // EEPROM_START + CONFIG_DATA_SIZE must be <= EEPROM_SIZE
  #define EEPROM_START  768
#endif

/////////////////////////////////////////////

// Add customs headers from v1.2.0
#define USING_CUSTOMS_STYLE                 true
#define USING_CUSTOMS_HEAD_ELEMENT          true
#define USING_CORS_FEATURE                  true

/////////////////////////////////////////////

// Force some params in Blynk, only valid for library version 1.0.1 and later
#define TIMEOUT_RECONNECT_WIFI                    10000L
#define RESET_IF_CONFIG_TIMEOUT                   true

#define CONFIG_TIMEOUT_RETRYTIMES_BEFORE_RESET    5

// Config Timeout 120s (default 60s)
#define CONFIG_TIMEOUT                            120000L

#define USE_DYNAMIC_PARAMETERS                    true

/////////////////////////////////////////////

#define REQUIRE_ONE_SET_SSID_PW             false

#define SCAN_WIFI_NETWORKS                  true

// To be able to manually input SSID, not from a scanned SSID lists
#define MANUAL_SSID_INPUT_ALLOWED           true

// From 2-15
#define MAX_SSID_IN_LIST                    8

/////////////////////////////////////////////

// Those above #define's must be placed before #include <BlynkSimpleEsp8266_WM.h> and <BlynkSimpleEsp8266_SSL_WM.h>
//////////////////////////////////////////

#define USE_SSL   true
//#define USE_SSL   false

#if USE_SSL
  #include <BlynkSimpleEsp8266_SSL_WM.h>
#else
  #include <BlynkSimpleEsp8266_WM.h>
#endif

#define PIN_LED   2   // Pin D4 mapped to pin GPIO2/TXD1 of ESP8266, NodeMCU and WeMoS, control on-board LED
#define PIN_D2    4   // Pin D2 mapped to pin GPIO4 of ESP8266

#define DHT_PIN     PIN_D2
#define DHT_TYPE    DHT11

#define HOST_NAME   "8266-Master-Controller"

#endif      //defines_h
```

#### 3. File [Credentials.h](examples/Async_ESP32WM_MRD_ForcedConfig/Credentials.h)


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

#### 4. File [dynamicParams.h](examples/Async_ESP32WM_MRD_ForcedConfig/dynamicParams.h)


```cpp
#ifndef dynamicParams_h
#define dynamicParams_h

// USE_DYNAMIC_PARAMETERS defined in defined.h

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

### Debug Terminal Output Samples

### 1. Async_ESP8266WM_MRD_Config using LittleFS with SSL on ESP8266_NODEMCU_ESP12E

The following is the sample terminal output when running example [Async_ESP8266WM_MRD_Config](examples/Async_ESP8266WM_MRD_Config) on **ESP8266_NODEMCU_ESP12E**

#### 1.1 No MultiReset Detected => Running normally


```
Starting Async_ESP8266WM_MRD_Config using LittleFS with SSL on ESP8266_NODEMCU_ESP12E
ESP8266 core v3.0.1
Blynk_Async_WM SSL for ESP8266 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[452] Hostname=ESP8266-Async-Config
[508] LoadCfgFile 
[508] OK
[508] ======= Start Stored Config Data =======
[508] Hdr=SSL_ESP8266,BrdName=Air-Control
[508] SSID=HueNet1,PW=12345678
[510] SSID1=HueNet2,PW1=12345678
[513] Server=account.duckdns.org,Token=token1
[519] Server1=account.duckdns.org,Token1=token2
[526] Port=9443
[527] ======= End Config Data =======
[530] CCSum=0x36c8,RCSum=0x36c8
[543] LoadCredFile 
[543] CrR:pdata=new-mqtt-server,len=34
[543] CrR:pdata=1883,len=6
[543] CrR:pdata=new-mqtt-username,len=34
[545] CrR:pdata=default-mqtt-password,len=34
[549] CrR:pdata=default-mqtt-SubTopic,len=34
[553] CrR:pdata=default-mqtt-PubTopic,len=34
[557] OK
[557] CrCCsum=0x2670,CrRCsum=0x2670
[561] Valid Stored Dynamic Data
[564] Hdr=SSL_ESP8266,BrdName=Air-Control
[567] SSID=HueNet1,PW=12345678
[570] SSID1=HueNet2,PW1=12345678
[573] Server=account.duckdns.org,Token=token1
[579] Server1=account.duckdns.org,Token1=token2
[585] Port=9443
[587] ======= End Config Data =======
[590] bg: noConfigPortal = true
[593] Connecting MultiWifi...
[6895] WiFi connected after time: 1
[6896] SSID: HueNet1, RSSI = -32
[6896] Channel: 2, IP address: 192.168.2.166
[6896] bg: WiFi OK. Try Blynk
[6897] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP8266_NODEMCU_ESP12E

[22919] NTP time: Sat Jan  2 06:58:15 2021
[22919] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[23720] Certificate OK
[23731] Ready (ping: 1ms).
[23802] Connected to Blynk Server = account.duckdns.org, Token = token1
[23802] bg: WiFi+Blynk OK

Blynk ESP8266 using LittleFS connected.
Board Name : Air-Control
Stop multiResetDetecting
Saving config file...
Saving config file OK
B
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
BBBBBB
```

---

#### 1.2 MultiReset Detected => Enter Config Portal

```
Starting Async_ESP8266WM_MRD_Config using LittleFS with SSL on ESP8266_NODEMCU_ESP12E
ESP8266 core v3.0.1
Blynk_Async_WM SSL for ESP8266 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFC0003
multiResetDetectorFlag = 0xFFFC0003
lowerBytes = 0x0003, upperBytes = 0x0003
multiResetDetected, number of times = 3
Saving config file...
Saving config file OK
[291] Multi or Double Reset Detected
[291] Hostname=ESP8266-Async-Config
[307] LoadCfgFile 
[307] OK
[307] ======= Start Stored Config Data =======
[307] Hdr=SSL_ESP8266,BrdName=Air-Control
[307] SSID=HueNet1,PW=12345678
[309] SSID1=HueNet2,PW1=12345678
[312] Server=account.duckdns.org,Token=token1
[318] Server1=account.duckdns.org,Token1=token2
[325] Port=9443
[326] ======= End Config Data =======
[329] CCSum=0x36c8,RCSum=0x36c8
[335] LoadCredFile 
[335] CrR:pdata=new-mqtt-server,len=34
[338] CrR:pdata=1883,len=6
[340] CrR:pdata=new-mqtt-username,len=34
[344] CrR:pdata=default-mqtt-password,len=34
[348] CrR:pdata=default-mqtt-SubTopic,len=34
[352] CrR:pdata=default-mqtt-PubTopic,len=34
[356] OK
[356] CrCCsum=0x2670,CrRCsum=0x2670
[360] Valid Stored Dynamic Data
[363] Hdr=SSL_ESP8266,BrdName=Air-Control
[366] SSID=HueNet1,PW=12345678
[369] SSID1=HueNet2,PW1=12345678
[372] Server=account.duckdns.org,Token=token1
[378] Server1=account.duckdns.org,Token1=token2
[384] Port=9443
[386] ======= End Config Data =======
[389] bg: Stay forever in config portal.DRD/MRD detected
[688] 
stConf:SSID=TestPortal-ESP8266,PW=TestPortalPass
[688] IP=192.168.200.1,ch=2
F
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
[212982] h1:myMenuItems[0]=new-mqtt-server
[212983] h1:myMenuItems[1]=1883
[212983] h1:myMenuItems[2]=new-mqtt-username
[212984] h1:myMenuItems[3]=default-mqtt-password
[212987] h1:myMenuItems[4]=default-mqtt-SubTopic
[212991] h1:myMenuItems[5]=default-mqtt-PubTopic
F[229521] id: = HueNet1
[229531] pw = 12345678
[229539] id1 = HueNet2
[229550] pw1 = 12345678
[229558] sv = account.duckdns.org
[229567] tk = token1
[229577] sv1 = account.duckdns.org
[229586] tk1 = token2
[229595] pt = 9443
[229607] nm = Async_ESP8266
[229617] h:mqtt=new-mqtt-server
[229617] h2:myMenuItems[0]=new-mqtt-server
[229626] h:mqpt=1883
[229626] h2:myMenuItems[1]=1883
[229635] h:user=new-mqtt-username
[229635] h2:myMenuItems[2]=new-mqtt-username
[229645] h:mqpw=default-mqtt-password
[229645] h2:myMenuItems[3]=default-mqtt-password
[229655] h:subs=default-mqtt-SubTopic
[229655] h2:myMenuItems[4]=default-mqtt-SubTopic
[229664] h:pubs=default-mqtt-PubTopic
[229664] h2:myMenuItems[5]=default-mqtt-PubTopic
[229665] h:UpdLittleFS:/wmssl_conf.dat
[229672] SaveCfgFile 
[229672] WCSum=0x36b9
[229745] OK
[229753] SaveBkUpCfgFile 
[229814] OK
[229823] SaveCredFile 
[229823] CW1:pdata=new-mqtt-server,len=34
[229823] CW1:pdata=1883,len=6
[229823] CW1:pdata=new-mqtt-username,len=34
[229877] CW1:pdata=default-mqtt-password,len=34
[229877] CW1:pdata=default-mqtt-SubTopic,len=34
[229878] CW1:pdata=default-mqtt-PubTopic,len=34
[229884] OK
[229884] CrWCSum=0x2670
[229893] SaveBkUpCredFile 
[229893] CW2:pdata=new-mqtt-server,len=34
[229893] CW2:pdata=1883,len=6
[229893] CW2:pdata=new-mqtt-username,len=34
[229949] CW2:pdata=default-mqtt-password,len=34
[229949] CW2:pdata=default-mqtt-SubTopic,len=34
[229950] CW2:pdata=default-mqtt-PubTopic,len=34
[229956] OK
[229956] h:Rst

```

---

#### 1.3 Exit Config Portal with Data

```
Starting Async_ESP8266WM_MRD_Config using LittleFS with SSL on ESP8266_NODEMCU_ESP12E
ESP8266 core v3.0.1
Blynk_Async_WM SSL for ESP8266 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[394] Hostname=ESP8266-Async-Config
[416] LoadCfgFile 
[416] OK
[416] ======= Start Stored Config Data =======
[417] Hdr=SSL_ESP8266,BrdName=Async_ESP8266
[417] SSID=HueNet1,PW=12345678
[419] SSID1=HueNet2,PW1=12345678
[421] Server=account.duckdns.org,Token=token1
[428] Server1=account.duckdns.org,Token1=token2
[434] Port=9443
[435] ======= End Config Data =======
[439] CCSum=0x36b9,RCSum=0x36b9
[445] LoadCredFile 
[445] CrR:pdata=new-mqtt-server,len=34
[447] CrR:pdata=1883,len=6
[449] CrR:pdata=new-mqtt-username,len=34
[453] CrR:pdata=default-mqtt-password,len=34
[458] CrR:pdata=default-mqtt-SubTopic,len=34
[461] CrR:pdata=default-mqtt-PubTopic,len=34
[465] OK
[466] CrCCsum=0x2670,CrRCsum=0x2670
[469] Valid Stored Dynamic Data
[472] Hdr=SSL_ESP8266,BrdName=Async_ESP8266
[476] SSID=HueNet1,PW=12345678
[479] SSID1=HueNet2,PW1=12345678
[482] Server=account.duckdns.org,Token=token1
[488] Server1=account.duckdns.org,Token1=token2
[494] Port=9443
[496] ======= End Config Data =======
[499] bg: noConfigPortal = true
[502] Connecting MultiWifi...
[6780] WiFi connected after time: 1
[6780] SSID: HueNet1, RSSI = -32
[6781] Channel: 2, IP address: 192.168.2.166
[6781] bg: WiFi OK. Try Blynk
[6782] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP8266_NODEMCU_ESP12E

[22805] NTP time: Sat Jan  2 07:03:13 2021
[22805] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[23707] Certificate OK
[23720] Ready (ping: 7ms).
[23793] Connected to Blynk Server = account.duckdns.org, Token = token1
[23793] bg: WiFi+Blynk OK

Blynk ESP8266 using LittleFS connected.
Board Name : Async_ESP8266
Stop multiResetDetecting
Saving config file...
Saving config file OK
B
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
BBBB
```

---
---

### 2. Async_ESP32WM_MRD_Config using LittleFS with SSL on ESP32_DEV

The following is the sample terminal output when running example [Async_ESP32WM_MRD_Config](examples/Async_ESP32WM_MRD_Config) on **ESP32_DEV**


#### 2.1 No MultiReset Detected => Running normally

```
Starting Async_ESP32WM_MRD_Config using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[373] Hostname=ESP32-Async-Controller
[407] LoadCfgFile 
[411] OK
[412] ======= Start Stored Config Data =======
[412] Hdr=SSL_ESP32,BrdName=Air-Control
[412] SSID=HueNet1,PW=12345678
[412] SSID1=HueNet2,PW1=12345678
[415] Server=account.duckdns.org,Token=token1
[421] Server1=account.duckdns.org,Token1=token2
[427] Port=9443
[429] ======= End Config Data =======
[432] CCSum=0x3657,RCSum=0x3657
[449] LoadCredFile 
[453] CrR:pdata=new-mqtt-server,len=34
[453] CrR:pdata=1883,len=6
[454] CrR:pdata=new-mqtt-username,len=34
[454] CrR:pdata=default-mqtt-password,len=34
[456] CrR:pdata=default-mqtt-SubTopic,len=34
[460] CrR:pdata=default-mqtt-PubTopic,len=34
[464] OK
[465] CrCCsum=0x2670,CrRCsum=0x2670
[468] Valid Stored Dynamic Data
[471] Hdr=SSL_ESP32,BrdName=Air-Control
[474] SSID=HueNet1,PW=12345678
[477] SSID1=HueNet2,PW1=12345678
[480] Server=account.duckdns.org,Token=token1
[486] Server1=account.duckdns.org,Token1=token2
[493] Port=9443
[494] ======= End Config Data =======
[497] bg: noConfigPortal = true
[500] Connecting MultiWifi...
[7589] WiFi connected after time: 1
[7589] SSID: HueNet1, RSSI = -27
[7589] Channel: 2, IP address: 192.168.2.101
[7589] bg: WiFi OK. Try Blynk
[7591] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[8604] NTP time: Sat Jan  2 07:09:42 2021
[8604] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[10551] Certificate OK
[10558] Ready (ping: 6ms).
[10627] Connected to Blynk Server = account.duckdns.org, Token = token1
[10627] bg: WiFi+Blynk OK

Blynk ESP32 using LittleFS connected.
Board Name : Air-Control
Stop multiResetDetecting
Saving config file...
Saving config file OK
B
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
```

---

#### 2.2 MultiReset Detected => Enter Config Portal

```
Starting Async_ESP32WM_MRD_Config using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFC0003
multiResetDetectorFlag = 0xFFFC0003
lowerBytes = 0x0003, upperBytes = 0x0003
multiResetDetected, number of times = 3
Saving config file...
Saving config file OK
[272] Multi or Double Reset Detected
[343] Hostname=ESP32-Async-Controller
[379] LoadCfgFile 
[384] OK
[384] ======= Start Stored Config Data =======
[384] Hdr=SSL_ESP32,BrdName=Air-Control
[384] SSID=HueNet1,PW=12345678
[384] SSID1=HueNet2,PW1=12345678
[387] Server=account.duckdns.org,Token=token1
[393] Server1=account.duckdns.org,Token1=token2
[400] Port=9443
[401] ======= End Config Data =======
[405] CCSum=0x3657,RCSum=0x3657
[422] LoadCredFile 
[427] CrR:pdata=new-mqtt-server,len=34
[427] CrR:pdata=1883,len=6
[427] CrR:pdata=new-mqtt-username,len=34
[427] CrR:pdata=default-mqtt-password,len=34
[429] CrR:pdata=default-mqtt-SubTopic,len=34
[433] CrR:pdata=default-mqtt-PubTopic,len=34
[437] OK
[438] CrCCsum=0x2670,CrRCsum=0x2670
[441] Valid Stored Dynamic Data
[444] Hdr=SSL_ESP32,BrdName=Air-Control
[448] SSID=HueNet1,PW=12345678
[451] SSID1=HueNet2,PW1=12345678
[454] Server=account.duckdns.org,Token=token1
[460] Server1=account.duckdns.org,Token1=token2
[466] Port=9443
[468] ======= End Config Data =======
[471] bg: Stay forever in config portal.DRD/MRD detected
[1360] 
stConf:SSID=TestPortal-ESP32,PW=TestPortalPass
[1360] IP=192.168.220.1,ch=4
F
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
RFRFRF[188660] id: = HueNet1
[188671] pw = 12345678
[188697] id1 = HueNet2
[188709] pw1 = 12345678
[188718] sv = account.duckdns.org
[188728] tk = token1
[188739] sv1 = account.duckdns.org
[188749] tk1 = token2
[188760] pt = 9443
[188770] nm = ESP32_MRD
[188783] h:mqtt=default-mqtt-server
[188783] h2:myMenuItems[0]=default-mqtt-server
[188794] h:mqpt=1883
[188794] h2:myMenuItems[1]=1883
[188806] h:user=default-mqtt-username
[188806] h2:myMenuItems[2]=default-mqtt-username
[188851] h:mqpw=default-mqtt-password
[188851] h2:myMenuItems[3]=default-mqtt-password
[188863] h:subs=default-mqtt-SubTopic
[188863] h2:myMenuItems[4]=default-mqtt-SubTopic
[188873] h:pubs=default-mqtt-PubTopic
[188873] h2:myMenuItems[5]=default-mqtt-PubTopic
[188874] h:Updating LittleFS:/wmssl_conf.dat
[188898] SaveCfgFile 
[188898] WCSum=0x34bc
[188905] OK
[188923] SaveBkUpCfgFile 
[188930] OK
[188950] SaveCredFile 
[188950] CW1:pdata=default-mqtt-server,len=34
[188959] CW1:pdata=1883,len=6
[188959] CW1:pdata=default-mqtt-username,len=34
[188959] CW1:pdata=default-mqtt-password,len=34
[188959] CW1:pdata=default-mqtt-SubTopic,len=34
[188964] CW1:pdata=default-mqtt-PubTopic,len=34
[188969] OK
[188969] CrWCSum=0x29a6
[188998] SaveBkUpCredFile 
[188998] CW2:pdata=default-mqtt-server,len=34
[189005] CW2:pdata=1883,len=6
[189005] CW2:pdata=default-mqtt-username,len=34
[189005] CW2:pdata=default-mqtt-password,len=34
[189007] CW2:pdata=default-mqtt-SubTopic,len=34
[189011] CW2:pdata=default-mqtt-PubTopic,len=34
[189016] OK
[189016] h:Rst

```

---

#### 2.3 Exit Config Portal with Data

```
Starting Async_ESP32WM_MRD_Config using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[363] Hostname=ESP32-Async-Controller
[416] LoadCfgFile 
[424] OK
[424] ======= Start Stored Config Data =======
[424] Hdr=SSL_ESP32,BrdName=ESP32_MRD
[424] SSID=HueNet1,PW=12345678
[424] SSID1=HueNet2,PW1=12345678
[427] Server=account.duckdns.org,Token=token1
[433] Server1=account.duckdns.org,Token1=token2
[439] Port=9443
[441] ======= End Config Data =======
[444] CCSum=0x34bc,RCSum=0x34bc
[468] LoadCredFile 
[476] CrR:pdata=default-mqtt-server,len=34
[476] CrR:pdata=1883,len=6
[476] CrR:pdata=default-mqtt-username,len=34
[476] CrR:pdata=default-mqtt-password,len=34
[479] CrR:pdata=default-mqtt-SubTopic,len=34
[483] CrR:pdata=default-mqtt-PubTopic,len=34
[487] OK
[488] CrCCsum=0x29a6,CrRCsum=0x29a6
[491] Valid Stored Dynamic Data
[494] Hdr=SSL_ESP32,BrdName=ESP32_MRD
[497] SSID=HueNet1,PW=12345678
[500] SSID1=HueNet2,PW1=12345678
[503] Server=account.duckdns.org,Token=token1
[509] Server1=account.duckdns.org,Token1=token2
[515] Port=9443
[517] ======= End Config Data =======
[520] bg: noConfigPortal = true
[523] Connecting MultiWifi...
[6380] WiFi connected after time: 1
[6380] SSID: HueNet1, RSSI = -24
[6380] Channel: 2, IP address: 192.168.2.101
[6380] bg: WiFi OK. Try Blynk
[6382] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[7395] NTP time: Sat Jan  2 07:14:16 2021
[7395] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[9293] Certificate OK
[9302] Ready (ping: 8ms).
[9371] Connected to Blynk Server = account.duckdns.org, Token = token1
[9371] bg: WiFi+Blynk OK

Blynk ESP32 using LittleFS connected.
Board Name : ESP32_MRD
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop multiResetDetecting
Saving config file...
Saving config file OK
RBRB
```

---

#### 2.4 WiFi Lost. AutoReconnect WiFi and Blynk

```

[142428] run: WiFi lost. Reconnect WiFi+Blynk
[142428] Connecting MultiWifi...
[149669] WiFi connected after time: 2
[149669] SSID: HueNet2, RSSI = -51
[149669] Channel: 4, IP address: 192.168.2.101
[149669] run: WiFi reconnected. Connect to Blynk
[149673] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[149687] NTP time: Sat Jan  2 07:16:39 2021
[149690] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[151559] Certificate OK
[151568] Ready (ping: 8ms).
[151637] Connected to Blynk Server = account.duckdns.org, Token = token1
[151637] run: WiFi+Blynk reconnected
RB
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

### 3. Async_ESP32_MultiTask using LittleFS without SSL on ESP32_DEV

The following is the sample terminal output when running example [Async_ESP32_MultiTask](examples/ESP32_MultiTask/Async_ESP32_MultiTask) to demonstrate the displaying and measuring tasks still work when the WiFi and Blynk are lost and the system is busy reconnecting to WiFi and Blynk. See the issue in [**Blynk + LCD + WiFi Manager**](https://community.blynk.cc/t/blynk-lcd-wifi-manager/49818) if not using MultiTask in that case.

```
Starting Async_ESP32_MultiTask using LittleFS without SSL on ESP32_DEV
Blynk_Async_WM for ESP32 v1.6.1
ESP_DoubleResetDetector v1.1.1
[1431] Hostname=ESP32-Async-MTask
[1517] LoadCfgFile 
[1518] OK
[1518] ======= Start Stored Config Data =======
[1518] Hdr=ESP32,BrdName=ESP32-Async-Blynk
[1518] SSID=HueNet1,PW=12345678
[1520] SSID1=HueNet1,PW1=12345678
[1523] Server=account.ddns.net,Token=blynk_token
[1529] Server1=account.duckdns.org,Token1=blynk_token
[1535] Port=8080
[1537] ======= End Config Data =======
[1540] CCSum=0x3551,RCSum=0x3551
[1544] LoadCredFile 
[1545] CrR:pdata=default-mqtt-server,len=34
[1549] CrR:pdata=1883,len=6
[1552] CrR:pdata=default-mqtt-username,len=34
[1556] CrR:pdata=default-mqtt-password,len=34
[1560] CrR:pdata=default-mqtt-SubTopic,len=34
[1564] CrR:pdata=default-mqtt-PubTopic,len=34
[1568] OK
[1569] CrCCsum=0x29a6,CrRCsum=0x29a6
[1572] Valid Stored Dynamic Data
[1575] Hdr=ESP32,BrdName=ESP32-Async-Blynk
[1579] SSID=HueNet1,PW=12345678
[1582] SSID1=HueNet1,PW1=12345678
[1585] Server=account.ddns.net,Token=blynk_token
[1591] Server1=account.duckdns.org,Token1=blynk_token
[1597] Port=8080
[1599] ======= End Config Data =======
[1602] bg: noConfigPortal = true
[1605] Connecting MultiWifi...
[7893] WiFi connected after time: 1
[7893] SSID:HueNet1,RSSI=-34
[7893] Channel:2,IP address:192.168.2.101
[7893] bg: WiFi OK. Try Blynk
[7894] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[7907] BlynkArduinoClient.connect: Connecting to account.ddns.net:8080
[7952] Ready (ping: 15ms).
[8020] Connected to Blynk Server = account.ddns.net, Token = blynk_token
[8020] bg: WiFi+Blynk OK

Blynk ESP32 using SPIFFS connected. Board Name : ESP32-Async-Blynk
=================
Time = 8842 ms
T0 = 25.09
T1 = 26.07
T2 = 27.06

Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
=================
Time = 8869 ms
T0 = 25.09
T1 = 26.07
T2 = 27.06
=================
Time = 10022 ms
T0 = 25.10
T1 = 26.08
T2 = 27.07
...
Blynk Online
=================
Time = 15911 ms
T0 = 25.16
T1 = 26.13
T2 = 27.11
=================
Time = 16927 ms
T0 = 25.17
T1 = 26.14
T2 = 27.11
=================
Time = 17942 ms
T0 = 25.18
T1 = 26.14
T2 = 27.12
...
=================
Time = 23894 ms
T0 = 25.24
T1 = 26.19
T2 = 27.16
[24848] run: WiFi lost. Reconnect WiFi+Blynk
[24848] Connecting MultiWifi...
=================
Time = 24911 ms
T0 = 25.25
T1 = 26.20
T2 = 27.17
=================
Time = 26534 ms
T0 = 25.27
T1 = 26.21
T2 = 27.18
=================
Time = 27549 ms
T0 = 25.28
T1 = 26.22
T2 = 27.18
=================
Time = 28564 ms
T0 = 25.29
T1 = 26.23
T2 = 27.19
...
Time = 34574 ms
T0 = 25.24
T1 = 26.19
T2 = 27.16
Internet Offline
...
=================
Time = 65106 ms
T0 = 25.65
T1 = 26.52
T2 = 27.43
=================
Time = 66798 ms
T0 = 25.67
T1 = 26.53
T2 = 27.45
=================
Time = 67813 ms
T0 = 25.68
T1 = 26.54
T2 = 27.45
=================
Time = 68828 ms
T0 = 25.69
T1 = 26.55
T2 = 27.46
=================
Time = 69843 ms
T0 = 25.70
T1 = 26.56
T2 = 27.47
[70647] WiFi connected after time: 10
[70647] SSID:HueNet1,RSSI=-33
[70647] Channel:2,IP address:192.168.2.101
[70647] run: WiFi reconnected. Connect to Blynk
[70650] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[70663] BlynkArduinoClient.connect: Connecting to account.ddns.net:8080
[70712] Ready (ping: 12ms).
[70781] Connected to Blynk Server = account.ddns.net, Token = blynk_token
[70781] run: WiFi+Blynk reconnected
=================
Time = 70860 ms
T0 = 25.71
T1 = 26.57
T2 = 27.47
=================
Time = 72618 ms
T0 = 25.73
T1 = 26.58
T2 = 27.48
=================
Time = 73702 ms
T0 = 25.74
T1 = 26.59
T2 = 27.49
...
=================
Time = 93405 ms
T0 = 25.93
T1 = 26.75
T2 = 27.62
=================
Time = 94422 ms
T0 = 25.94
T1 = 26.76
T2 = 27.63
```

---
---


### 4. Async_ESP32WM_MRD_ForcedConfig using non-persistent ConfigPortal virtual button

The following is the sample terminal output when running example [Async_ESP32WM_MRD_ForcedConfig](examples/Async_ESP32WM_MRD_ForcedConfig) on **ESP32_DEV**

The function to call is 

```
// This will keep CP once, clear after reset, even you didn't enter CP at all.
Blynk.resetAndEnterConfigPortal();
```

#### 4.1 Start normally then press non-persistent ConfigPortal virtual button

```
Starting Async_ESP32WM_MRD_ForcedConfig using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[369] Hostname=ESP32-Async-Controller
[421] LoadCfgFile 
[429] OK
[429] ======= Start Stored Config Data =======
[429] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[429] SSID=HueNet1,PW=12345678
[429] SSID1=HueNet2,PW1=12345678
[432] Server=account.duckdns.org,Token=token
[438] Server1=account.duckdns.org,Token1=token1
[444] Port=9443
[446] ======= End Config Data =======
[449] CCSum=0x3553,RCSum=0x3553
[473] LoadCredFile 
[481] CrR:pdata=default-mqtt-server,len=34
[481] CrR:pdata=1883,len=6
[481] CrR:pdata=default-mqtt-username,len=34
[481] CrR:pdata=default-mqtt-password,len=34
[484] CrR:pdata=default-mqtt-SubTopic,len=34
[488] CrR:pdata=default-mqtt-PubTopic,len=34
[492] OK
[493] CrCCsum=0x29a6,CrRCsum=0x29a6
[496] Valid Stored Dynamic Data
[499] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[502] SSID=HueNet1,PW=12345678
[505] SSID1=HueNet2,PW1=12345678
[508] Server=account.duckdns.org,Token=token
[514] Server1=account.duckdns.org,Token1=token1
[520] Port=9443
[522] ======= End Config Data =======
[525] Check if isForcedCP
[545] LoadCPFile 
[551] OK
[551] bg: noConfigPortal = true
[551] Connecting MultiWifi...
[6826] WiFi connected after time: 1
[6826] SSID: HueNet1, RSSI = -24
[6826] Channel: 2, IP address: 192.168.2.82
[6826] bg: WiFi OK. Try Blynk
[6827] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[7841] NTP time: Mon Jan 18 02:41:32 2021
[7841] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[9638] Certificate OK
[9645] Ready (ping: 6ms).
[9714] Connected to Blynk Server = account.duckdns.org, Token = token
[9714] bg: WiFi+Blynk OK

Blynk ESP32 using LittleFS connected.
Board Name : ESP32_SSL
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop multiResetDetecting
Saving config file...
Saving config file OK

CP Button Hit. Rebooting
[19457] setForcedCP non-Persistent    <========== Non-Persistent CP will clear after reset
[19475] SaveCPFile 
[19482] OK
[19491] SaveBkUpCPFile 
[19495] OK
```

---

#### 4.2 Enter non-persistent ConfigPortal

Non-Persistent CP will be removed after first reset, even you didn't enter the CP. You can optionally enter CP, input and `Save` config data.

```
Starting Async_ESP32WM_MRD_ForcedConfig using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[419] Hostname=ESP32-Async-Controller
[477] LoadCfgFile 
[485] OK
[485] ======= Start Stored Config Data =======
[485] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[485] SSID=HueNet1,PW=12345678
[485] SSID1=HueNet2,PW1=12345678
[488] Server=account.duckdns.org,Token=token
[494] Server1=account.duckdns.org,Token1=token1
[501] Port=9443
[502] ======= End Config Data =======
[506] CCSum=0x3553,RCSum=0x3553
[532] LoadCredFile 
[540] CrR:pdata=default-mqtt-server,len=34
[540] CrR:pdata=1883,len=6
[540] CrR:pdata=default-mqtt-username,len=34
[540] CrR:pdata=default-mqtt-password,len=34
[543] CrR:pdata=default-mqtt-SubTopic,len=34
[547] CrR:pdata=default-mqtt-PubTopic,len=34
[551] OK
[552] CrCCsum=0x29a6,CrRCsum=0x29a6
[555] Valid Stored Dynamic Data
[558] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[562] SSID=HueNet1,PW=12345678
[564] SSID1=HueNet2,PW1=12345678
[567] Server=account.duckdns.org,Token=token
[574] Server1=account.duckdns.org,Token1=token1
[580] Port=9443
[581] ======= End Config Data =======
[585] Check if isForcedCP
[606] LoadCPFile 
[612] OK
[613] bg: isForcedConfigPortal = true
[613] bg:Stay forever in CP:Forced-non-Persistent  <========== Non-Persistent CP will clear after reset
[613] clearForcedCP
[632] SaveCPFile 
[639] OK
[648] SaveBkUpCPFile 
[652] OK
[1497] 
stConf:SSID=TestPortal-ESP32,PW=TestPortalPass
[1497] IP=192.168.220.1,ch=8
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop multiResetDetecting
Saving config file...
Saving config file OK
RF[66298] id: = HueNet1
[66311] pw = 12345678
[66330] id1 = HueNet2
[66339] pw1 = 12345678
[66350] sv = account.duckdns.org
[66364] tk = token
[66382] sv1 = account.duckdns.org
[66391] tk1 = token1
[66400] pt = 9443
[66409] nm = ESP32_SSL
[66423] h2:myMenuItems[0]=default-mqtt-server
[66439] h2:myMenuItems[1]=1883
[66451] h2:myMenuItems[2]=default-mqtt-username
[66475] h2:myMenuItems[3]=default-mqtt-password
[66485] h2:myMenuItems[4]=default-mqtt-SubTopic
[66494] h2:myMenuItems[5]=default-mqtt-PubTopic
[66495] h:Updating LittleFS:/wmssl_conf.dat
[66540] SaveCfgFile 
[66540] WCSum=0x3553
[66681] OK
[66697] SaveBkUpCfgFile 
[66703] OK
[66721] SaveCredFile 
[66721] CW1:pdata=default-mqtt-server,len=34
[66726] CW1:pdata=1883,len=6
[66726] CW1:pdata=default-mqtt-username,len=34
[66726] CW1:pdata=default-mqtt-password,len=34
[66726] CW1:pdata=default-mqtt-SubTopic,len=34
[66731] CW1:pdata=default-mqtt-PubTopic,len=34
[66736] OK
[66736] CrWCSum=0x29a6
[66758] SaveBkUpCredFile 
[66758] CW2:pdata=default-mqtt-server,len=34
[66764] CW2:pdata=1883,len=6
[66764] CW2:pdata=default-mqtt-username,len=34
[66764] CW2:pdata=default-mqtt-password,len=34
[66764] CW2:pdata=default-mqtt-SubTopic,len=34
[66768] CW2:pdata=default-mqtt-PubTopic,len=34
[66773] OK
[66774] clearForcedCP
[66803] SaveCPFile 
[66812] OK
[66827] SaveBkUpCPFile 
[66837] OK
[66837] h:Rst
```

---

#### 4.3 Exit Config Portal with Saved Data

```
Starting Async_ESP32WM_MRD_ForcedConfig using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[386] Hostname=ESP32-Async-Controller
[439] LoadCfgFile 
[447] OK
[447] ======= Start Stored Config Data =======
[447] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[447] SSID=HueNet1,PW=12345678
[447] SSID1=HueNet2,PW1=12345678
[450] Server=account.duckdns.org,Token=token
[456] Server1=account.duckdns.org,Token1=token1
[462] Port=9443
[464] ======= End Config Data =======
[467] CCSum=0x3553,RCSum=0x3553
[491] LoadCredFile 
[498] CrR:pdata=default-mqtt-server,len=34
[498] CrR:pdata=1883,len=6
[498] CrR:pdata=default-mqtt-username,len=34
[498] CrR:pdata=default-mqtt-password,len=34
[501] CrR:pdata=default-mqtt-SubTopic,len=34
[505] CrR:pdata=default-mqtt-PubTopic,len=34
[509] OK
[510] CrCCsum=0x29a6,CrRCsum=0x29a6
[513] Valid Stored Dynamic Data
[516] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[519] SSID=HueNet1,PW=12345678
[522] SSID1=HueNet2,PW1=12345678
[525] Server=account.duckdns.org,Token=token
[531] Server1=account.duckdns.org,Token1=token1
[538] Port=9443
[539] ======= End Config Data =======
[543] Check if isForcedCP
[564] LoadCPFile 
[570] OK
[570] bg: noConfigPortal = true
[571] Connecting MultiWifi...
[7355] WiFi connected after time: 1
[7355] SSID: HueNet1, RSSI = -23
[7355] Channel: 2, IP address: 192.168.2.82
[7355] bg: WiFi OK. Try Blynk
[7356] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[7371] NTP time: Mon Jan 18 02:43:00 2021
[7373] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[9310] Certificate OK
[9317] Ready (ping: 6ms).
[9386] Connected to Blynk Server = account.duckdns.org, Token = token
[9386] bg: WiFi+Blynk OK

Blynk ESP32 using LittleFS connected.
Board Name : ESP32_SSL
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop multiResetDetecting
Saving config file...
Saving config file OK
RB

```


---
---


### 5. Async_ESP32WM_MRD_ForcedConfig using persistent ConfigPortal virtual button

The following is the sample terminal output when running example [Async_ESP32WM_MRD_ForcedConfig](examples/Async_ESP32WM_MRD_ForcedConfig) on **ESP32_DEV**


The function to call is 

```
// This will keep CP once, clear after reset, even you didn't enter CP at all.
Blynk.resetAndEnterConfigPortalPersistent();
```

#### 5.1 Start normally then press persistent ConfigPortal virtual button

```
Starting Async_ESP32WM_MRD_ForcedConfig using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[386] Hostname=ESP32-Async-Controller
[439] LoadCfgFile 
[447] OK
[447] ======= Start Stored Config Data =======
[447] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[447] SSID=HueNet1,PW=12345678
[447] SSID1=HueNet2,PW1=12345678
[450] Server=account.duckdns.org,Token=token
[456] Server1=account.duckdns.org,Token1=token1
[462] Port=9443
[464] ======= End Config Data =======
[467] CCSum=0x3553,RCSum=0x3553
[491] LoadCredFile 
[498] CrR:pdata=default-mqtt-server,len=34
[498] CrR:pdata=1883,len=6
[498] CrR:pdata=default-mqtt-username,len=34
[498] CrR:pdata=default-mqtt-password,len=34
[501] CrR:pdata=default-mqtt-SubTopic,len=34
[505] CrR:pdata=default-mqtt-PubTopic,len=34
[509] OK
[510] CrCCsum=0x29a6,CrRCsum=0x29a6
[513] Valid Stored Dynamic Data
[516] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[519] SSID=HueNet1,PW=12345678
[522] SSID1=HueNet2,PW1=12345678
[525] Server=account.duckdns.org,Token=token
[531] Server1=account.duckdns.org,Token1=token1
[538] Port=9443
[539] ======= End Config Data =======
[543] Check if isForcedCP
[564] LoadCPFile 
[570] OK
[570] bg: noConfigPortal = true
[571] Connecting MultiWifi...
[7355] WiFi connected after time: 1
[7355] SSID: HueNet1, RSSI = -23
[7355] Channel: 2, IP address: 192.168.2.82
[7355] bg: WiFi OK. Try Blynk
[7356] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[7371] NTP time: Mon Jan 18 02:43:00 2021
[7373] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[9310] Certificate OK
[9317] Ready (ping: 6ms).
[9386] Connected to Blynk Server = account.duckdns.org, Token = token
[9386] bg: WiFi+Blynk OK

Blynk ESP32 using LittleFS connected.
Board Name : ESP32_SSL
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop multiResetDetecting
Saving config file...
Saving config file OK
RBRB
Persistent CP Button Hit. Rebooting
[170221] setForcedCP Persistent     <========== Persistent CP requested
[170240] SaveCPFile 
[170248] OK
[170358] SaveBkUpCPFile 
[170398] OK
```

---

#### 5.2 Enter persistent ConfigPortal

Persistent CP will remain after resets. The only way to get rid of Config Portal is to enter CP, input (even fake data or none) and `Save` config data.

```
Starting Async_ESP32WM_MRD_ForcedConfig using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[351] Hostname=ESP32-Async-Controller
[403] LoadCfgFile 
[411] OK
[411] ======= Start Stored Config Data =======
[411] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[411] SSID=HueNet1,PW=12345678
[411] SSID1=HueNet2,PW1=12345678
[414] Server=account.duckdns.org,Token=token
[420] Server1=account.duckdns.org,Token1=token1
[427] Port=9443
[428] ======= End Config Data =======
[432] CCSum=0x3553,RCSum=0x3553
[455] LoadCredFile 
[462] CrR:pdata=default-mqtt-server,len=34
[462] CrR:pdata=1883,len=6
[462] CrR:pdata=default-mqtt-username,len=34
[463] CrR:pdata=default-mqtt-password,len=34
[466] CrR:pdata=default-mqtt-SubTopic,len=34
[470] CrR:pdata=default-mqtt-PubTopic,len=34
[474] OK
[474] CrCCsum=0x29a6,CrRCsum=0x29a6
[478] Valid Stored Dynamic Data
[480] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[484] SSID=HueNet1,PW=12345678
[487] SSID1=HueNet2,PW1=12345678
[490] Server=account.duckdns.org,Token=token
[496] Server1=account.duckdns.org,Token1=token1
[502] Port=9443
[504] ======= End Config Data =======
[507] Check if isForcedCP
[527] LoadCPFile 
[534] OK
[534] bg: isForcedConfigPortal = true
[534] bg:Stay forever in CP:Forced-Persistent     <========== Persistent CP will remain after reset
[1379] 
stConf:SSID=TestPortal-ESP32,PW=TestPortalPass
[1379] IP=192.168.220.1,ch=11
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop multiResetDetecting
Saving config file...
Saving config file OK
RF[76317] id: = HueNet1
[76337] pw = 12345678
[76358] id1 = HueNet2
[76372] pw1 = 12345678
[76384] sv = account.duckdns.org
[76403] tk = token
[76416] sv1 = account.duckdns.org
[76432] tk1 = token1
[76450] pt = 9443
[76463] nm = ESP32_SSL
[76483] h2:myMenuItems[0]=default-mqtt-server
[76498] h2:myMenuItems[1]=1883
[76520] h2:myMenuItems[2]=default-mqtt-username
[76531] h2:myMenuItems[3]=default-mqtt-password
[76546] h2:myMenuItems[4]=default-mqtt-SubTopic
[76560] h2:myMenuItems[5]=default-mqtt-PubTopic
[76561] h:Updating LittleFS:/wmssl_conf.dat
[76594] SaveCfgFile 
[76594] WCSum=0x3553
[76722] OK
[76735] SaveBkUpCfgFile 
[76742] OK
[76767] SaveCredFile 
[76767] CW1:pdata=default-mqtt-server,len=34
[76774] CW1:pdata=1883,len=6
[76774] CW1:pdata=default-mqtt-username,len=34
[76774] CW1:pdata=default-mqtt-password,len=34
[76774] CW1:pdata=default-mqtt-SubTopic,len=34
[76779] CW1:pdata=default-mqtt-PubTopic,len=34
[76784] OK
[76785] CrWCSum=0x29a6
[76806] SaveBkUpCredFile 
[76806] CW2:pdata=default-mqtt-server,len=34
[76811] CW2:pdata=1883,len=6
[76812] CW2:pdata=default-mqtt-username,len=34
[76812] CW2:pdata=default-mqtt-password,len=34
[76812] CW2:pdata=default-mqtt-SubTopic,len=34
[76816] CW2:pdata=default-mqtt-PubTopic,len=34
[76821] OK
[76821] clearForcedCP
[76844] SaveCPFile 
[76857] OK
[76867] SaveBkUpCPFile 
[76871] OK
[76871] h:Rst
```

---

#### 5.3 Exit Config Portal with Saved Data

Enter CP, input (even fake data or none) and `Save` config data to exit persistent ConfigPortal

```
Starting Async_ESP32WM_MRD_ForcedConfig using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[388] Hostname=ESP32-Async-Controller
[438] LoadCfgFile 
[446] OK
[446] ======= Start Stored Config Data =======
[446] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[446] SSID=HueNet1,PW=12345678
[446] SSID1=HueNet2,PW1=12345678
[449] Server=account.duckdns.org,Token=token
[455] Server1=account.duckdns.org,Token1=token1
[461] Port=9443
[463] ======= End Config Data =======
[466] CCSum=0x3553,RCSum=0x3553
[489] LoadCredFile 
[496] CrR:pdata=default-mqtt-server,len=34
[496] CrR:pdata=1883,len=6
[496] CrR:pdata=default-mqtt-username,len=34
[496] CrR:pdata=default-mqtt-password,len=34
[499] CrR:pdata=default-mqtt-SubTopic,len=34
[503] CrR:pdata=default-mqtt-PubTopic,len=34
[507] OK
[508] CrCCsum=0x29a6,CrRCsum=0x29a6
[511] Valid Stored Dynamic Data
[514] Hdr=SSL_ESP32,BrdName=ESP32_SSL
[517] SSID=HueNet1,PW=12345678
[520] SSID1=HueNet2,PW1=12345678
[523] Server=account.duckdns.org,Token=token
[529] Server1=account.duckdns.org,Token1=token1
[535] Port=9443
[537] ======= End Config Data =======
[540] Check if isForcedCP
[560] LoadCPFile 
[567] OK
[567] bg: noConfigPortal = true
[567] Connecting MultiWifi...
[6820] WiFi connected after time: 1
[6820] SSID: HueNet1, RSSI = -24
[6820] Channel: 2, IP address: 192.168.2.82
[6820] bg: WiFi OK. Try Blynk
[6821] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[6836] NTP time: Mon Jan 18 02:47:10 2021
[6838] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[8814] Certificate OK
[8821] Ready (ping: 6ms).
[8890] Connected to Blynk Server = account.duckdns.org, Token = token
[8890] bg: WiFi+Blynk OK

Blynk ESP32 using LittleFS connected.
Board Name : ESP32_SSL
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop multiResetDetecting
Saving config file...
Saving config file OK
RBRBRBRBRB
```

---
---

### 6. Async_ESP32WM_ForcedConfig using LittleFS with SSL on ESP32S2_DEV

The following is the sample terminal output when running example [Async_ESP32WM_ForcedConfig](examples/Async_ESP32WM_ForcedConfig) on **ESP32S2_DEV** to demonstrate the usage of SSL, Blynk and LittleFS.

```
Starting Async_ESP32WM_ForcedConfig using LittleFS with SSL on ESP32S2_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_DoubleResetDetector v1.1.1
[958] Set CustomsStyle to : <style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>
[980] Set CustomsHeadElement to : <style>html{filter: invert(10%);}</style>
[987] Set CORS Header to : Your Access-Control-Allow-Origin
[1202] Hostname=ESP32-Async-Controller
[1247] LoadCfgFile 
[1253] OK
[1253] ======= Start Stored Config Data =======
[1253] Hdr=SSL_ESP32,BrdName=ESP32-S2
[1253] SSID=HueNet1,PW=12345678
[1253] SSID1=HueNet2,PW1=12345678
[1256] Server=blynk-cloud.com,Token=token
[1262] Server1=blynk-cloud.com,Token1=token
[1269] Port=9443
[1270] ======= End Config Data =======
[1274] CCSum=0x2f32,RCSum=0x2f32
[1291] LoadCredFile 
[1297] CrR:pdata=default-mqtt-server,len=34
[1297] CrR:pdata=1883,len=6
[1297] CrR:pdata=default-mqtt-username,len=34
[1297] CrR:pdata=default-mqtt-password,len=34
[1301] CrR:pdata=default-mqtt-SubTopic,len=34
[1305] CrR:pdata=default-mqtt-PubTopic,len=34
[1309] OK
[1310] CrCCsum=0x29a6,CrRCsum=0x29a6
[1313] Valid Stored Dynamic Data
[1316] Hdr=SSL_ESP32,BrdName=ESP32-S2
[1319] SSID=HueNet1,PW=12345678
[1322] SSID1=HueNet2,PW1=12345678
[1325] Server=blynk-cloud.com,Token=token
[1331] Server1=blynk-cloud.com,Token1=token
[1337] Port=9443
[1339] ======= End Config Data =======
[1342] Check if isForcedCP
[1358] LoadCPFile 
[1363] OK
[1364] bg: noConfigPortal = true
[1364] Connecting MultiWifi...
[11065] WiFi connected after time: 1
[11065] SSID: HueNet1, RSSI = -45
[11066] Channel: 2, IP address: 192.168.2.157
[11066] bg: WiFi OK. Try Blynk
[11067] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[16081] NTP time: Mon Apr 19 23:16:54 2021
[16081] BlynkArduinoClient.connect: Connecting to blynk-cloud.com:9443
[16702] Certificate OK
[16725] Ready (ping: 21ms).
[16793] Connected to Blynk Server = blynk-cloud.com, Token = token
[16794] bg: WiFi+Blynk OK

Blynk ESP32 using LittleFS connected.
Board Name : ESP32-S2
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
```

---
---

### 7. Async_ESP32WM_MRD_ForcedConfig using LITTLEFS with SSL on ESP32_DEV to demo WiFi Scan

The following is the sample terminal output when running example [Async_ESP32WM_MRD_ForcedConfig](examples/Async_ESP32WM_MRD_ForcedConfig) on **ESP32_DEV** with WiFi Scan for selection in Configuration Portal.

#### 7.1 MRD/DRD => Open Config Portal

```
Starting Async_ESP32WM_MRD_ForcedConfig using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
[228] Set CustomsStyle to : <style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>
[250] Set CustomsHeadElement to : <style>html{filter: invert(10%);}</style>
[257] Set CORS Header to : Your Access-Control-Allow-Origin
LittleFS Flag read = 0xFFFC0003
multiResetDetectorFlag = 0xFFFC0003
lowerBytes = 0x0003, upperBytes = 0x0003
multiResetDetected, number of times = 3
Saving config file...
Saving config file OK
[418] Hostname=ESP32-Async-Controller
[482] LoadCfgFile 
[493] OK
[493] CCSum=0x34ef,RCSum=0x34ef
[521] LoadCredFile 
[532] OK
[532] CrCCsum=0x29a6,CrRCsum=0x29a6
[532] Hdr=SSL_ESP32,BrdName=ESP32-SSL
[533] SSID=HueNet,PW=password
[533] SSID1=HueNet1,PW1=password
[534] Server=account.duckdns.org,Token=token
[540] Server1=account.duckdns.org,Token1=token1
[547] Port=9443
[548] ======= End Config Data =======
[578] LoadCPFile 
[588] OK
[588] bg:Stay forever in CP:DRD/MRD
[619] SaveCPFile 
[630] OK
[663] SaveBkUpCPFile 
[674] OK
[674] Scanning Network
[5781] scanWifiNetworks: Done, Scanned Networks n = 8
[5782] Sorting
[5782] Removing Dup
[5782] WiFi networks found:
[5782] 1: HueNet, -29dB
[5783] 2: HueNetTek, -33dB
[5786] 3: HueNet1, -38dB
[5788] 4: dragino-1ed63c, -43dB
[5791] 5: HueNet2, -53dB
[5793] 6: bacau, -67dB
[5795] 7: guest_24, -67dB
[5797] 8: dlink-4F96, -89dB
[6699] 
stConf:SSID=TestPortal-ESP32,PW=TestPortalPass
[6699] IP=192.168.220.1,ch=8
F
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
[36948] handleRequest:WM_HTTP_CORS:Access-Control-Allow-Origin : Your Access-Control-Allow-Origin
[50918] h:mqtt=default-mqtt-server
[50937] h:mqpt=1883
[50949] h:user=default-mqtt-username
[50963] h:mqpw=default-mqtt-password
[50978] h:subs=default-mqtt-SubTopic
[50992] h:pubs=default-mqtt-PubTopic
[50993] h:Updating LittleFS:/wmssl_conf.dat
[51042] SaveCfgFile 
[51043] WCSum=0x3613
[51057] OK
[51106] SaveBkUpCfgFile 
[51292] OK
[51326] SaveCredFile 
[51339] OK
[51339] CrWCSum=0x29a6
[51384] SaveBkUpCredFile 
[51397] OK
[51398] h:Rst
```

---

#### 7.2 Config Data Saved => Connection to Blynk


```
Starting Async_ESP32WM_MRD_ForcedConfig using LittleFS with SSL on ESP32_DEV
Blynk_Async_WM SSL for ESP32 v1.6.1
ESP_MultiResetDetector v1.1.1
[229] Set CustomsStyle to : <style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>
[251] Set CustomsHeadElement to : <style>html{filter: invert(10%);}</style>
[258] Set CORS Header to : Your Access-Control-Allow-Origin
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[469] Hostname=ESP32-Async-Controller
[541] LoadCfgFile 
[554] OK
[554] CCSum=0x34ef,RCSum=0x34ef
[585] LoadCredFile 
[598] OK
[598] CrCCsum=0x29a6,CrRCsum=0x29a6
[598] Hdr=SSL_ESP32,BrdName=ESP32-SSL
[598] SSID=HueNet,PW=password
[598] SSID1=HueNet1,PW1=password
[600] Server=account.duckdns.org,Token=token
[606] Server1=account.duckdns.org,Token1=token1
[612] Port=9443
[614] ======= End Config Data =======
[647] LoadCPFile 
[659] OK
[659] Connecting MultiWifi...
[13045] WiFi connected after time: 1
[13045] SSID: HueNet, RSSI = -35
[13046] Channel: 10, IP address: 192.168.2.45
[13046] bg: WiFi OK. Try Blynk
[13047] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP32

[14061] NTP time: Sun Apr 25 17:59:30 2021
[16012] Certificate OK
[16020] Ready (ping: 7ms).
[16089] Connected to Blynk Server = account.duckdns.org, Token = token
[16089] bg: WiFi+Blynk OK

Blynk ESP32 using LittleFS connected.
Board Name : ESP32-SSL
Stop multiResetDetecting
Saving config file...
Saving config file OK
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
RBRBRBRBRBRBRBRB
```

---


### 8. Async_ESP8266WM_MRD_Config using LITTLEFS with SSL on ESP8266_NODEMCU_ESP12E using new ESP8266 core v3.0.1

The following is the sample terminal output when running example [Async_ESP8266WM_MRD_Config](examples/Async_ESP8266WM_MRD_Config) on **ESP8266_NODEMCU_ESP12E** using new **ESP8266 core v3.0.1**

```
Starting Async_ESP8266WM_MRD_Config using LittleFS with SSL on ESP8266_NODEMCU_ESP12E
ESP8266 core v3.0.1
Blynk_Async_WM SSL for ESP8266 v1.6.1
ESP_MultiResetDetector v1.1.1
[268] Set CustomsStyle to : <style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>
[290] Set CustomsHeadElement to : <style>html{filter: invert(10%);}</style>
[297] Set CORS Header to : Your Access-Control-Allow-Origin
LittleFS Flag read = 0xFFFE0001
multiResetDetectorFlag = 0xFFFE0001
lowerBytes = 0x0001, upperBytes = 0x0001
No multiResetDetected, number of times = 1
LittleFS Flag read = 0xFFFE0001
Saving config file...
Saving config file OK
[348] Hostname=ESP8266-Async-Config
[370] LoadCfgFile 
[370] OK
[371] ======= Start Stored Config Data =======
[371] Hdr=SSL_ESP8266,BrdName= ESP8266_NODEMCU_ESP12E
[371] SSID=HueNet1,PW=password
[373] SSID1=HueNet2,PW1=password
[376] Server=account.duckdns.org,Token=token
[383] Server1=account.duckdns.org,Token1=token1
[389] Port=9443
[390] ======= End Config Data =======
[394] CCSum=0x395d,RCSum=0x395d
[400] LoadCredFile 
[400] CrR:pdata=default-mqtt-server,len=34
[402] CrR:pdata=1883,len=6
[405] CrR:pdata=default-mqtt-username,len=34
[409] CrR:pdata=default-mqtt-password,len=34
[413] CrR:pdata=default-mqtt-SubTopic,len=34
[417] CrR:pdata=default-mqtt-PubTopic,len=34
[421] OK
[422] CrCCsum=0x29a6,CrRCsum=0x29a6
[425] Valid Stored Dynamic Data
[428] Hdr=SSL_ESP8266,BrdName= ESP8266_NODEMCU_ESP12E
[432] SSID=HueNet1,PW=password
[435] SSID1=HueNet2,PW1=password
[438] Server=account.duckdns.org,Token=token
[444] Server1=account.duckdns.org,Token1=token1
[451] Port=9443
[452] ======= End Config Data =======
[455] Check if isForcedCP
[462] LoadCPFile 
[462] OK
[462] bg: noConfigPortal = true
[463] Connecting MultiWifi...
[5563] WiFi connected after time: 1
[5563] SSID: HueNet1, RSSI = -43
[5564] Channel: 2, IP address: 192.168.2.135
[5564] bg: WiFi OK. Try Blynk
[5565] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on ESP8266_NODEMCU_ESP12E

[6580] NTP time: Thu May 20 04:54:30 2021
[6612] BlynkArduinoClient.connect: Connecting to account.duckdns.org:9443
[7369] Certificate OK
[7375] Ready (ping: 1ms).
[7451] Connected to Blynk Server = account.duckdns.org, Token = token
[7451] bg: WiFi+Blynk OK

Blynk ESP8266 using LittleFS connected.
Board Name :  ESP8266_NODEMCU_ESP12E
B
Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
Stop multiResetDetecting
Saving config file...
Saving config file OK
BBB
```


---
---


### Debug

Debug is enabled by default on Serial.

You can also change the debugging level from 0 to 4

```cpp
#define BLYNK_PRINT        Serial

#define BLYNK_WM_DEBUG     3

#define USING_MRD          true

#if USING_MRD
  #define MULTIRESETDETECTOR_DEBUG       true 
#else
  #define DOUBLERESETDETECTOR_DEBUG     false
#endif
```

---
---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.

---
---

## Releases

### Releases v1.6.1

1. Add configurable connectMultiWiFi parameters. Check [Minimize blocking during multi-wifi reconnect #6](https://github.com/khoih-prog/Blynk_Async_WM/issues/6)
2. Update ESP8266_CORE_VERSION for ESP8266 core v3.0.1+

### Major Releases v1.6.0

1. Fix AP connect issue caused by **breaking ESP8266 core v3.0.0**. Caused by multiple core changes, but the new solution results a better and faster connection to AP.
2. Fix SSL issue caused by breaking ESP8266 core v3.0.0. Now the better **BearSSL** is used in both ESP32 and ESP8266 to replace the ESP8266 deprecated `axTLS`. Check [Remove axTLS from code and documentation #7437](https://github.com/esp8266/Arduino/pull/7437)
3. Fix the `BLYNK_INFO_DEVICE`displaying the generic ESP8266 board with Blynk logo. Caused by new ESP8266 core changes of `build.board`. For example from `ESP8266_NODEMCU` in core v2.7.4 to `ESP8266_NODEMCU_ESP12E` in core v3.0.0
4. Fix many warnings only displayed in new core ESP8266 v3.0.0
5. Make code compatible for either new ESP8266 core v3.0.0+ or ealier cores v2.7.4-

### Major Releases v1.5.0

1. Enable scan of WiFi networks for selection in Configuration Portal. Check [PR for v1.3.0 - Enable scan of WiFi networks #10](https://github.com/khoih-prog/WiFiManager_NINA_Lite/pull/10). Now you can select optional **SCAN_WIFI_NETWORKS**, **MANUAL_SSID_INPUT_ALLOWED** to be able to manually input SSID, not only from a scanned SSID lists and **MAX_SSID_IN_LIST** (from 2-15)
2. Fix invalid "blank" Config Data treated as Valid.
3. Permit optionally inputting one set of WiFi SSID/PWD by using `REQUIRE_ONE_SET_SSID_PW == true`
4. Enforce WiFi PWD minimum length of 8 chars
5. Minor enhancement to not display garbage when data is invalid

### Releases v1.4.1

1. Fix issue of custom Blynk port (different from 8080 or 9443) not working on ESP32. Check [Custom Blynk port not working for BlynkSimpleEsp32_Async_WM.h #4](https://github.com/khoih-prog/Blynk_Async_WM/issues/4)

### Major Releases v1.4.0

1. Add **LittleFS and SPIFFS** support to new **ESP32-S2** boards (**Arduino ESP32C3_DEV**). Check [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).
2. Add **EEPROM and SPIFFS** support to new **ESP32-C3** boards (**Arduino ESP32C3_DEV**). Check [HOWTO Install esp32 core for ESP32-S2 (Saola, AI-Thinker ESP-12K) and ESP32-C3 boards into Arduino IDE](#howto-install-esp32-core-for-esp32-s2-saola-ai-thinker-esp-12k-and-esp32-c3-boards-into-arduino-ide).
3. Fix SSL issue with Blynk Cloud Server
4. Update examples

### Major Releases v1.3.0

1. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header.
2. Add support to **ESP32-S2 (ESP32-S2 Saola and AI-Thinker ESP-12K)**. Currently using EEPROM only. To add support to LittleFS and SPIFFS in future releases.
3. Fix Config Portal Bug.
4. Tested with [**Latest ESP32 Core 1.0.5**](https://github.com/espressif/arduino-esp32) for ESP32-based boards.
5. Update examples

### Releases v1.2.3

1. To permit auto-reset after configurable timeout if DRD/MRD or non-persistent forced-CP. Check [**Good new feature: Blynk.resetAndEnterConfigPortal() Thanks & question #27**](https://github.com/khoih-prog/Blynk_WM/issues/27)

### Releases v1.2.2

1. Fix rare Config Portal bug not updating Config and dynamic Params data successfully in very noisy or weak WiFi situation

### Releases v1.2.1

1. Add functions to control Config Portal from software or Virtual Switches. Check [How to trigger a Config Portal from code #25](https://github.com/khoih-prog/Blynk_WM/issues/25)
2. Add examples to demo the new Virtual ConfigPortal SW feature
3. Optimize code

### Major Releases v1.2.0

1. Add support to LittleFS for ESP32 using [LITTLEFS](https://github.com/lorol/LITTLEFS) Library
2. Add support to MultiDetectDetector. **MultiDetectDetector** feature to force Config Portal when configurable multi-reset is detected within predetermined time.
3. Clean-up all compiler warnings possible.
4. Add Table of Contents
5. Modify Version String
6. Add MRD-related examples.

### Releases v1.1.0

1. Add examples using RTOS MultiTask to avoid blocking in operation.
2. Add Version String.

### Releases v1.0.16

1. Initial coding to use [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) instead of (ESP8266)WebServer.
2. Bump up to v1.0.16 to sync with [Blynk_WiFiManager library](https://github.com/khoih-prog/Blynk_WM) v1.0.16.

---

### Issues ###

Submit issues to: [Blynk_Async_WM issues](https://github.com/khoih-prog/Blynk_Async_WM/issues)

---
---

## TO DO

1. Fix bug. Add enhancement

---

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
22. Add examples using RTOS MultiTask to avoid blocking in operation.
21. Add **LittleFS** support to ESP32 using [Lorol's LittleFS_esp32](https://github.com/lorol/LITTLEFS) Library.
22. Add support to MultiDetectDetector and MRD-related examples
23. Add Table of Contents and Version String
24. Clean-up all compiler warnings possible.
25. Add functions to control Config Portal from software or **Virtual Switches**.
26. Add support to **ESP32-S2 (ESP32-S2 Saola, AI-Thinker ESP-12K, etc.) using EEPROM, LittleFS and SPIFFS**
27. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header
28. Add support to **ESP32-C3 using EEPROM and SPIFFS**
29. Fix SSL issue with Blynk Cloud Server by using SSL in unsecured mode. For more information, check [Blynk WiFiManager for ESP8266/ESP32 (including ESP32-S2, ESP32-C3) with Multi-WiFi and Multi-Blynk. Fix SSL issue for Blynk Cloud Server now](https://community.blynk.cc/t/blynk-wifimanager-for-esp8266-esp32-including-esp32-s2-esp32-c3-with-multi-wifi-and-multi-blynk-fix-ssl-issue-for-blynk-cloud-server-now/41011/40) and [ESP8266 SSL connections down using Blynk_WiFiManager (ESP32 works fine, non-SSL 8266 works fine)](https://community.blynk.cc/t/esp8266-ssl-connections-down-using-blynk-wifimanager-esp32-works-fine-non-ssl-8266-works-fine/52144/19)
30. Permit optionally inputting one set of WiFi SSID/PWD by using `REQUIRE_ONE_SET_SSID_PW == true`
31. Enforce WiFi PWD minimum length of 8 chars
32. Enable **scan of WiFi networks** for selection in Configuration Portal
33. Drastically update code to work with either ESP8266 new breaking ESP8266 core v3.0.0 or old core ESP8266 v2.7.4-
34. Make SSL working using `BearSSL`, not deprecated `axTLS`

---
---

### Contributions and thanks

1. Thanks to [me-no-dev](https://github.com/me-no-dev) for great [ESPAsyncWebServer Library](https://github.com/me-no-dev/ESPAsyncWebServer), [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP) and [AsyncTCP](https://github.com/me-no-dev/AsyncTCP).
2. Thanks to [lorol](https://github.com/lorol) for useful [LittleFS_esp32 Library](https://github.com/lorol/LITTLEFS)
3. Thanks to [Thor Johnson](https://github.com/thorathome) and [Thor Johnson in Blynk](https://community.blynk.cc/u/thorathome) to test, find bug, suggest and encourage to add those new features in [Blynk_WiFiManager library](https://github.com/khoih-prog/Blynk_WM) v1.0.13, such as Default Credentials/Dynamic Parms, Configurable Config Portal Title, DRD. The powerful [Async_Blynk_WM_Template](examples/Async_Blynk_WM_Template) is written by [Thor Johnson](https://github.com/thorathome) and is included in the examples with his permission.
Check these new features thanks to his direct contribution and/or enhancement requests :
  * [WM Config Portal using BlynkSimpleEsp32/8266_WM.h](https://community.blynk.cc/t/wm-config-portal-using-blynksimpleesp32-8266-wm-h/45402).
  * [How to trigger a Config Portal from code #25](https://github.com/khoih-prog/Blynk_WM/issues/25)
  * [Good new feature: Blynk.resetAndEnterConfigPortal() Thanks & question #27](https://github.com/khoih-prog/Blynk_WM/issues/27)
4. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for working with, developing, debugging and testing.
5. Thanks to [komaneko](https://github.com/jjskaife) to 
  * report bugs in [Custom Blynk port not working for BlynkSimpleEsp32_Async_WM.h #4](https://github.com/khoih-prog/Blynk_Async_WM/issues/4) leading to v1.4.1
  * ask for enhancement in [Minimize blocking during multi-wifi reconnect #6](https://github.com/khoih-prog/Blynk_Async_WM/issues/6) leading to v1.6.1

6. Thanks to [Michael H. "bizprof"](https://github.com/bizprof). With the impressive new feature :
  - `Enable scan of WiFi networks for selection in Configuration Portal`. Check [PR for v1.3.0 - Enable scan of WiFi networks #10](https://github.com/khoih-prog/WiFiManager_NINA_Lite/pull/10) leading to v1.5.0
  

<table>
  <tr>
    <td align="center"><a href="https://github.com/me-no-dev"><img src="https://github.com/me-no-dev.png" width="100px;" alt="me-no-dev"/><br /><sub><b>⭐️⭐️ me-no-dev</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/lorol"><img src="https://github.com/lorol.png" width="100px;" alt="lorol"/><br /><sub><b>⭐️ lorol</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/thorathome"><img src="https://github.com/thorathome.png" width="100px;" alt="thorathome"/><br /><sub><b>⭐️ Thor Johnson</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>tcpipchip</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/jjskaife"><img src="https://github.com/jjskaife.png" width="100px;" alt="jjskaife"/><br /><sub><b>komaneko</b></sub></a><br /></td>
  </tr>
    <td align="center"><a href="https://github.com/bizprof"><img src="https://github.com/bizprof.png" width="100px;" alt="bizprof"/><br /><sub><b>⭐️⭐️ Michael H. "bizprof"</b></sub></a><br /></td>
</table>

---

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

## License

- The library is licensed under [MIT](https://github.com/khoih-prog/Blynk_Async_WM/blob/master/LICENSE)

---

## Copyright

Copyright 2020- Khoi Hoang
