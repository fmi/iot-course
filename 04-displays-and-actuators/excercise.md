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


# LiquidCrystal 
1. Install "LiquidCrystal I2C" Library by Marco Schwarz. There are a lot so find and select this one
2. Load example from examples/INCOMPATIBLE/Liquid Crystal I2C/HelloWorld (it says incompatible as the library does not state ESP32, but it uses just standard functionality so it is fine)
3. In the beginning of the sketch, provide the SDA,SCA pins that you are using via   Wire.begin(16,17); (in case SDA=16, SCL=17). And connect to 5V and GND
4. Most likely you will need to turn the knob on the back clockwise to increase contrast until you see something
5. if nothing is shown, you may need to change the port for the display from 0x27 to 0x3F -> `LiquidCrystal_I2C lcd(0x3F,16,2);`

