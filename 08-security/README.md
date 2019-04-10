# Exercises

## Encryption
### HTTPS
* **ESP8266**: Implement simple verification of the host by fingerprint checking - [example](https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/examples/HTTPSRequest/HTTPSRequest.ino)
* **ESP32**: Implement a full verification client
    * [Official example](https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFiClientSecure/examples/WiFiClientSecure/WiFiClientSecure.ino)
    * [Another example](http://www.iotsharing.com/2017/08/how-to-use-https-in-arduino-esp32.html)
    
### MQTTS
Try to connect to the MQTT endpoint from the previous exercises, but this time [using PubSubClient over WifiClientSecure](http://www.iotsharing.com/2017/08/how-to-use-esp32-mqtts-with-mqtts-mosquitto-broker-tls-ssl.html)

## Client authentication
### HTTP + Bearer token
TODO
### MQTT credentials
TODO

## WiFi probing
Get this [Wifi probing example](https://github.com/pgenevski/esp8266-sniffer/tree/3df0334b316d9b6e6e36d46792ed9e8a8a8ccc52) up and running. See if you can log more useful information.

## Reverse engineering with Signal Analyzer
Record and decode the OneWire signal from DS18B20 communication using a signal analyzer.

# References
* https://www.espressif.com/en/media_overview/news/espressif-releases-patches-wifi-vulnerabilities-cert-vu228519
* https://ikalogic.com/pages/discontinued-products
* https://www.saleae.com/downloads
* https://wigle.net/
