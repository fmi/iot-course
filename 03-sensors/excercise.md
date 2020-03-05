# WiFi

## Connect to Local WiFi and send Http Request
<Arduino IDE> -> File -> Examples -> HttpClient -> BasicHttpClient
  
https://postb.in/ - simple online Web Server, to check outgoing requests


# BME 280

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
dsds
```

![](https://cloud.githubusercontent.com/assets/492455/23690399/087e3e16-03ca-11e7-98ab-bde2e0655ed0.png)

___
# Data to Thingspeak

Create account here - http://thingspeak.com, also account to Mathlabs is necessary to be created
Create channel as described here, at the bottom section "Thingspeak"
https://github.com/vlast3k/simple-co2-monitor-fw/wiki/First-Steps

Import example from
File -> Examples -> ESP8266HTTPClient -> BasicHTTPClient

Change Wifi Connection as shown below

Use Write api key - here in <key>
http://api.thingspeak.com/update?key=[key]&field1=[value]

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
# MPU 6050

## Connection

* VCC - 3.3v
* GND - GND (G)
* SDA - D6
* SCL - D7
* INT - D8

## Install Driver

MPU 6050 Driver - https://github.com/jrowberg/i2cdevlib

1. Download ZIP, and extract somewhere
2. Copy Arduino/I2CDev and Arduino/MPU6050 to 'libraries' folder
3. Restart Arduino

## Run Example

1. Open From - File / Examples / MPU6050 / MPU6050_DMP6
2. Adaptations:

* top of file, add: ```#define I2CDEV_IMPLEMENTATION I2CDEV_ARDUINO_WIRE```
* find and uncomment ``` #define OUTPUT_READABLE_REALACCEL ```
* Change ```#define INTERRUPT_PIN```to D8 and ```#define LED_PIN``` to BUILTIN_LED
* Find ```Wire.begin();``` change to ```Wire.begin(D6,D7);```

## Sample code to detect taps on the table

add
```int ox, oy, oz;```
as global variables, and then find code block on line ~330
```
  ...
        #ifdef OUTPUT_READABLE_REALACCEL
            // display real acceleration, adjusted to remove gravity
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetAccel(&aa, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
  //add this
            if (abs(aaReal.x - ox) > 14 ||
                abs(aaReal.y - oy) > 14 ||
                abs(aaReal.z - oz) > 14) {
                  Serial.println(millis());
            }
            ox = aaReal.x;
            oy = aaReal.y;
            oz = aaReal.z;
  //end
  ...
```


