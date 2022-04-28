# Exercises

## Encryption
### HTTPS
Implement a [full verification client](src/01_WifiClientSecure) with **ESP32**. Try it out with other hosts, such as [tb.genevski.com](tb.genevski.com) and change the root CA certificate if necessary. This example was adapted from the [official example](https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFiClientSecure/examples/WiFiClientSecure/WiFiClientSecure.ino) to include the up to date Root CA certificate of the howsmyssl host.
    
To figure out if the problem is in your code or the connection, you can test with `curl`:
```bash
curl -X POST -d "{\"temperature\": 25}" https://tb.genevski.com/api/v1/your_access_token/telemetry --header "Content-Type:application/json" -H "Connection: close"
```
    
### MQTTS
Connect to the MQTT endpoint from the previous exercises, but this time [over TLS](src/02_MQTTS)

To figure out if the problem is in your code or the connection, you can test `mosquitto_pub` (on Linux):
```bash
mosquitto_pub --capath /etc/ssl/certs/ -d -q 1 -h "tb.genevski.com" -p "8883" -t "v1/devices/me/telemetry" -u "your_access_token" -m {"temperature":27}
```

## WiFi probing
Get this [Wifi probing example](https://github.com/pgenevski/esp8266-sniffer/tree/3df0334b316d9b6e6e36d46792ed9e8a8a8ccc52) running on ESP8266. See if you can log more useful information.

## Reverse engineering with Signal Analyzer
Record and decode the OneWire signal from DS18B20 communication using a signal analyzer.

# References
* [Another ESP TLS example](http://www.iotsharing.com/2017/08/how-to-use-https-in-arduino-esp32.html)
* [MQTT Lens Chrome app](https://chrome.google.com/webstore/detail/mqttlens/hemojaaeigabkbcookmlgmdigohjobjm)
* [Wifi network geolocation](https://wigle.net/)
* [Signal analyzer - Ikalogic](https://ikalogic.com/pages/discontinued-products)
* [Signal analyzer - Saleae](https://www.saleae.com/downloads)
* [ESP32 exploit of Flash Encryption and Sec. Boot Keys Extraction](https://limitedresults.com/2019/11/pwn-the-esp32-forever-flash-encryption-and-sec-boot-keys-extraction/)
