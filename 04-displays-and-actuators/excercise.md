# Random
Location of default GPIO mappings for ESP8266 boards: 	c:\Users\I024148\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\2.7.4\variants\nodemcu\

# Serial Input Test
1. Copy contents of this sketch https://github.com/iot-course/04-displays/SerialTest.ino to a new sketch

# NeoPixel Test
Documentation is here https://github.com/Makuna/NeoPixelBus/wiki, but is quite a LOT.

For Arduino it can be connected to almost any pin, for ESP8266, it works best on GPIO 2 (D4 on some boards) and GPIO 3 (used for Serial Input usually). When connected to other pins there may be issues with WiFi. This is why initialization is via

(This may be outdated, check current examples!)

`NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart800KbpsMethod> strip(PixelCount, PixelPin);`

Note: the drawback here is that GPIO2 is pulled up/down during sketch upload, so NeoPixels may show some colors (usually Green) after sketch is uploaded

**Connection** : 5V/VIN, GND, D4 (GPIO2)
1. Install "NeopPixelBus by Makuna" library
2. Example: https://github.com/iot-course/04-displays/NeoPixelBar.ino (the examples from the library are a bit more complex)


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