# Random
Location of default GPIO mappings for ESP8266 boards: 	c:\Users\I024148\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\2.7.4\variants\nodemcu\

# Serial Input Test
It is a bit tricky to handle Serial Input correctly and there wasn't a good example for this shipped with the ESP libraries, so here is one that can be embeded in other projects

1. Copy contents of this sketch https://github.com/iot-course/04-displays/SerialTest.ino to a new sketch

# NeoPixel Test
Documentation is here https://github.com/Makuna/NeoPixelBus/wiki, but is quite a LOT.

For ESP32 amd Arduino328 it can be connected to almost any pin, for ESP8266, it works best on GPIO 2 (D4 on some boards) and GPIO 3 (used for Serial Input usually). When connected to other pins there may be issues with WiFi. This is why initialization is via

Note: the drawback here is that GPIO2 on ESP8266 is pulled up/down during sketch upload, so NeoPixels may show some colors (usually Green) after sketch is uploaded
For ESP32 there are no such issues detected

**Connection** : 5V/VIN, GND, DIN -> G2 (ESP32) or D4 (ESP8266 GPIO2)
1. Install "NeopPixelBus by Makuna" library
2. Example: https://github.com/fmi/iot-course/blob/master/04-displays-and-actuators/NeoPixeslFmi22.ino
3. Some good example from the library is examples/NeopPixelBus by Makuna/animations/NeoPixelFunLoop (just set Pixelcount to the number of pixels - e.g. 8)


# LiquidCrystal (OUTDATED)
Documentation is here: https://www.arduino.cc/en/Reference/LiquidCrystal .

But we cannot use the standard library as our displays are I2C.

Information on supported methods can be found (if necessary) in the [source](https://github.com/marcoschwartz/LiquidCrystal_I2C/blob/master/) 
1. Connect display to 5V(VIN), GND and two pins, e.g. D6(SDA), D7(SCL)
1. Install "LiquidCrystal I2C by Frank Brabander" Library via Library Manager: 
2. Open example: **File -> Examples -> LiquidCrystal_I2C -> Hello World**
  * Modify the instantiation to `LiquidCrystal_I2C lcd(0x3F,16,2);` as our module is on address 0x3f, and is 16x2
  * Add at the begin of setup(), `Wire.begin(<SDA>, <SCL>)` depending on the pins you used. E.g. `Wire.begin(D6, D7);`
 
https://circuits4you.com/2019/03/17/esp8266-esp32-i2c-lcd-display-interface/#more-1650
