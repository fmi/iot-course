# Exercises

## OneWire
Connect the DS18b20 temp sensor to the board and measure its temperature

## Bluetooth Low Energy 
Use ESP32 to emulate a heart rate monitor. 


Notes:
* You must install the [ESP32 to Arduino](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md) and select "ESP32 Dev Module".
* While uploading the sketch you must hold the "BOOT" button. Otherwise upload will not start. You can release it after upload has started.
See: https://www.reddit.com/r/esp32/comments/885mzj/what_do_the_boot_and_en_buttons_do/
* Use the SelfLoops HRV application (Android) to test if it works.

## WiFi access point and HTTP server
Implement an access point and an HTTP server that lets you change the state of LED with an incoming HTTP request


## (Optional) ISM band (433MHz) connectivity (HC-12)
Implement a remote controlled LED using the HC-12 module

The HC-12 is a wireless serial port communication module that is very useful, extremely powerful and easy to use. It allows communication up to 1.8km distance in open air. You have to implement an receiver and a transmitter.

HC-12 is configurable, take a look at [AT Commands:](https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-12-long-range-wireless-communication-module)



