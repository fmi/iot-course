# WiFi
## WifiScan

Examples -> Wifi -> WifiScan

## Connect to Local WiFi and send Http Request
<Arduino IDE> -> File -> Examples -> HttpClient -> BasicHttpsClient
  
  Note: Recently most of the free test online Web Servers only accept HTTPS requests. This is why it is important to get the Https example. To run it against the server, the verification of the server-side certificate has to be disabled (unless this is needed for the scenario). This can be done by replacing the line
``` 
  client -> setCACert(rootCACertificate); 
```  
  in the top with
```
   client -> setInsecure();
```  
https://requestbin.com/ - simple online Web Server, to check outgoing requests


# VL53L0X - TOF Sensor
  
Лазерен сензор за измерване на разстояние, между 20-1200 мм
  
## Install Driver

  * Adafruit_VL53L0X -  <Arduino IDE> -> Sketch -> Include Library -> Manage Libraries -> Search for "VL53L0X", install "Adafruit VL53L0X "
  
## Connection
* VCC - 3.3v (3V3)
* GND - GND (G)
* SDA - 16 or any other 
* SCL - 17 or any other
  
  
  ## Run Example
  
  1. Open Example from -> File / Examples / Adafriut VL53L0X / VL53L0X_continous
  2. Adapt for correct I2C Pins, e.g. `Wire.begin(SDA, SCL)
  ```
  void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  ```
  3. Run and enjoy
  

# BME 280 / SI7021 / BMP280

* BME280 vs BMP280
<img width="300" alt="image" src="https://github.com/fmi/iot-course/assets/492455/29b96997-4214-4acf-b2bf-d78791b99c92">

* SI7021
<img width="150" alt="image" src="https://github.com/fmi/iot-course/assets/492455/f7aba63a-968d-4c4c-99fe-836b36e082e0">


(За Si7021 -  аналогично, пак трябва да се добави Wire.begin, но няма нужда да се специфицира адрес на сензора)
## Install Driver

* BME280 Driver - <Arduino IDE> -> Sketch -> Include Library -> Manage Libraries -> Search for "bme280", install "Adafruit BME280 Library"
* BMP280 Driver - <Arduino IDE> -> Sketch -> Include Library -> Manage Libraries -> Search for "bmp280", install "Adafruit BMP280 Library"
* SI7021 Driver - <Arduino IDE> -> Sketch -> Include Library -> Manage Libraries -> Search for "si7021", install "Adafruit SI7021 Library"


## Connection

* VCC - 3.3v (3V3)
* GND - GND (G)
* SDA - 16
* SCL - 17


## Run Example

1. Open Example from - File / Examples / Adafruit BME280 Library / bme280test
2. Adapt for ESP8266, and BME280 Breakout

The sensor can have addresses 0x76 & 0x77, our breakout uses 0x76, the default for the library is 0x77.
We need to call *Wire.begin(SDA, SCL)*, e.g. like Wire.begin(16, 17). Without it, the expected ports for I2C communication are different for each breakout board

Make sure that you do not have 2 lines, only the one with the address is needed. The other breaks it
```
  status = bme.begin()
  ...
  status = bme.begin(0x76)
```
  
```
    Serial.begin(9600); 
    
    Wire.begin(16, 17);
    status = bme.begin(0x76); 
```
_Note the serial baud rate in this example is 9600, so it needs to be changed in the serial monitor_
  
# Buttons
  
  Good tutorial for button debouncing, and explanation: https://esp32io.com/tutorials/esp32-button-debounce
  Defautl button on the board "BOOT" seems to be debounced. So to test it a wire between a pin and GND needs to be used

# Data to Thingspeak

Create account here - http://thingspeak.com, also account to Mathlabs is necessary to be created
Create channel as described here 
https://www.mathworks.com/help/thingspeak/collect-data-in-a-new-channel.html

Use the example from the first excercise for sending HTTPS request

Use Write api key - here in <key>
http://api.thingspeak.com/update?key=[key]&field1=[value]

```
        String url = "https://api.thingspeak.com/update?api_key=DGJI41Z9325VC02E&field1=";
      url = url + x++;
```
  
# Web Server

Examples -> WebServer -> HelloServer

___
