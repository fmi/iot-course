# WiFi

## Connect to Local WiFi and send Http Request
<Arduino IDE> -> File -> Examples -> HttpClient -> BasicHttpClient
  
https://postb.in/ - simple online Web Server, to check outgoing requests


# BME 280 / SI7021

(За Si7021 -  аналогично, пак трябва да се добави Wire.begin, но няма нужда да се специфицира адрес на сензора)
## Install Driver

* BME280 Driver - <Arduino IDE> -> Sketch -> Include Library -> Manage Libraries -> Search for "bme280", install "Adafruit BME280 Library"

## Connection

* VCC - 3.3v (3V3)
* GND - GND (G)
* SDA - 21
* SCL - 19

## Run Example

1. Open Example from - File / Examples / Adafruit BME280 Library / bme280test
2. Adapt for ESP8266, and BME280 Breakout

The sensor can have addresses 0x76 & 0x77, our breakout uses 0x76, the default for the library is 0x77.
We need to call *Wire.begin(SDA, SCL)*, e.g. like Wire.begin(21, 19). Without it, the expected ports for I2C communication are different for each breakout board
```
    Serial.begin(9600); 
    
    Wire.begin(21, 19);
    status = bme.begin(0x76); 
```
_Note the serial baud rate in this example is 9600, so it needs to be changed in the serial monitor_

# Data to Thingspeak

Create account here - http://thingspeak.com, also account to Mathlabs is necessary to be created
Create channel as described here, at the bottom section "Thingspeak"
https://github.com/vlast3k/simple-co2-monitor-fw/wiki/First-Steps

Import example from
File -> Examples -> ESP8266HTTPClient -> BasicHTTPClient

Change Wifi Connection as shown below

Use Write api key - here in <key>
http://api.thingspeak.com/update?key=[key]&field1=[value]
  
# Web Server

Examples -> WebServer -> HelloServer

# Wifi Connection

Instead of using WiFiMulti, and the associated instability with it, better to do simple WiFi connection like this

```
#include <ESP8266WiFi.h>

...

void main() {
...
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Local IP:"); Serial.println(WiFi.localIP());
...
}
```
___
