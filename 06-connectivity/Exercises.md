# Exercises

## WiFi modes (TODO Hristo)
Implement the following functionality:
1. Station + HTTP client (you can skip this if you already did it in the previous lectures)
2. Access point + HTTP server
Implement an access point and an HTTP server that lets you:
* Render an HTML page from the ESP memory (A message and an on/off button to control the builtin LED)
* Change the state of LED with an incoming HTTP request (button is clicked)
3. SoftAP

## ISM band (433MHz) connectivity (HC-12)
Implement a remote controlled LED using the HC-12 module

The HC-12 is a wireless serial port communication module that is very useful, extremely powerful and easy to use. It allows communication up to 1.8km distance in open air.
You have to implement an receiver and a transmitter.

HC-12 is configurable, take a look at [AT Commands:](https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-12-long-range-wireless-communication-module)

## MQTT client
The MQTT demo project with ESP8266 WiFi module and RabbitMQ (+ Java clients for receving status messages from ESP board and sending commands)
is available at: https://github.com/iproduct/course-iot/tree/master/esp8266-mqtt-rabbitmq
