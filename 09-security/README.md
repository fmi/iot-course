# Exercises

## Encryption
### HTTPS
Implement a [full verification client](src/01_HTTP_W_WiFiClientSecure) with **ESP32**. This is an extention of a previous exercise, that adds https. 

If things don't work, you can test the connection `curl`:
```bash
curl -v -X GET "https://api.open-meteo.com/v1/forecast?latitude=42.67&longitude=23.33&current=temperature_2m,wind_speed_10m,relative_humidity_2m"
```
    
### MQTTS
Connect to the MQTT endpoint from the previous exercises, but this time [over TLS](src/02_MQTTS)

To figure out if the problem is in your code or the connection, you can test with the excellent [MQTTX tool](https://mqttx.app/).

### OAuth2 code flow
Authorize and connect the board to your github account using [OAuth device code flow](src/03_OAuth_Device_Flow).


## Reverse engineering with Signal Analyzer
Record and decode the OneWire signal from DS18B20 communication using a signal analyzer.

# References
* [Wifi network geolocation](https://wigle.net/)
* [Signal analyzer - Saleae](https://www.saleae.com/downloads)
* [ESP32 exploit of Flash Encryption and Sec. Boot Keys Extraction](https://limitedresults.com/2019/11/pwn-the-esp32-forever-flash-encryption-and-sec-boot-keys-extraction/)
