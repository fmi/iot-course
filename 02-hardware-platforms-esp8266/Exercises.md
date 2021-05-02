## First Steps
Here https://github.com/fmi/iot-course/tree/master/02-hardware-platforms-esp8266/src are the basic examples for working with the ESP32 and ESP8266.
Have in mind that not all boards havea built in LED, so on some of them the Blink sketch will not work. On the ones with LED, it is usually bound to GPIO 2, but sometimes to 1 or 13.
The most important examples for the initial steps are:
01_HelloWorld, 02_Blink, 03_Button, 04_SerialTest

The most comprehensive store of information for core and common functionalities is the examples folder for each ESP variant. Both types (ESP32 and ESP8266), share almost the same programming abstraction - in our case "Arduino C".
This is why the existing examples and excercies we do often work for both. (while in some cases like Watchdog, it relies on specific functionality for each chip and therefore they would be different)

Some other core functionalities that are covered as part of this lection are covered by the examples, accessible under Arduino IDE->File->Examples->ESP32/ESP8266

### General guidelines
http://www.danielcasner.org/guidelines-for-writing-code-for-the-esp8266/

### Connecting to WiFi
Wifi/Wifi/WifiScan, Wifi/WifiClient, Wifi/WifiMulti

Wifi/WifiSmartConfig - allows automatic configuration of the Wifi network and requires the ESP Touch aplication for either Android or Iphone

### Sending HTTP
While in Wifi/Wificlient we saw that we can have a Socket-like connection, usually this is not very convenient. 
HttpClient/HttpClientBasic - this example shows how to use the HTTP Client library on ESP which abstracts from the underlying details

### WebServer
Going further it is worth exploring how to run a WebServer on ESP
WebServer/HelloServer - the other examples there are also interesting

## Next Steps
Going deeper into ESP-programming, it is worth doing some exercises by combing code from the examples or even doing things from scratch.
See also the links below, for details on Interrupts, Watchdog and Storage, but those are more advanced topics

### Interrupts
https://techtutorialsx.com/2016/12/11/esp8266-external-interrupts/

### Watchdog
https://techtutorialsx.com/2017/01/21/esp8266-watchdog-functions/

### Storage & FS
http://esp8266.github.io/Arduino/versions/2.3.0/doc/filesystem.html

### ESP32 Dual Core
The ESP32 has two available cores that share the heap (~290KB). By default, the loop() function runs on core 1. Using some built-in functions, we can set as many as we want tasks on any core.

Most notably, we can run a high-memory high-performance task on core 0, and run our networking/error-handling code on core 1 to avoid bottlenecks.

https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos.html
https://www.freertos.org/a00113.html
https://www.freertos.org/RTOS_Task_Notification_As_Counting_Semaphore.html

