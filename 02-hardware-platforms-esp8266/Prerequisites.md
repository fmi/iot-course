# Installation
1. Install Arduino IDE: https://www.arduino.cc/en/Main/Software - за опреационната система която използвате
2. Install ESP8266 Development Kit: https://github.com/esp8266/Arduino#installing-with-boards-manager
3. Install ESP32 Development Kit: https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md


# Board selection and specifics
Plug your board and select it from the Tools > Board menu
* ESP8266
  * Node MCU 0.9 (yellow) - The LED_BUILTIN constant shall be replaced with 1 to get the built in LED to work.
  * Node MCU 1.0 (black)
  * Wemos D1 R2 & mini (blue) - Use upload speed = 115200 baud
  * Node MCU 1.0 (long battery powered boards) - Use this one although the board is labeled Wemos. The "Wemos D1 R2 & mini" will also work, but you will have to replace LED_BUILTIN with 16

* ESP32
   * ESP32 Devkit V1
   * TTGO (with display and USB-C Port)

# Optional Drivers
1. (optional) Install drivers (Windows & Mac) for the CH340G Usb2Serial chip: http://vair-monitor.com/drivers/
   * This shall only be needed for the NodeMCU (yellow) and Wemos D1 mini (blue) boards. 
   * Long (battery powered) Wemos and the NodeMCU 1.0 (black ones) usually run without driver installation
