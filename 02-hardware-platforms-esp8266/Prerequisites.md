# Installation
1. Install Arduino IDE 1.8.10: https://www.arduino.cc/en/Main/OldSoftwareReleases#previous - Тръгва и с по-нови версии на Arduino IDE, но работи по-бавно и ако се ползват директории с шпации в името не работи добре
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
   * ESP32 Devkit V1 or ESP32 Dev Module
   * TTGO (with display and USB-C Port)

# Troubleshooting
## ESP32: Upload not working
1. You tried unplugging and plugging the board back right :) ?
2. On some boards, you have to hold the `BOOT` button for a while after triggering the upload from the IDE. After upload starts, you can release it.
3. Sometimes, upload speeds higher than 256000 do not work reliably (e.g. depending on the USB cable quality).
4. Try stopping your antivirus and see if it makes a difference (don't forget to turn it back on).
- If this is the problem, you may have to whitelist some of the Arduino executables, or install Arduino in a folder outside e.g. `C:\Program Files (x86)`
6. Do a fresh reinstall
- Uninstall Arduino
- Manually delete its data folder
    - Windows: `C:\Users\(username)\AppData\Roaming\Arduino15` or `C:\Users\(username)\AppData\Local\Arduino15`
    - Linux: `/home/(username)/.arduino15`
    - Mac: `/Users/(username)/Library/Arduino15`
- Install again
7. Try to [set both outputs to verbose mode](https://forum.arduino.cc/index.php?topic=615560.0) and look carefuly at the output.
8. See if [turning off the compile cache](https://forum.arduino.cc/index.php?topic=686705.0) solves the problem.

## ESP32: no output in serial monitor in Windows 10
For some reason i had to go to Device Manager -> Ports and then in the COM Port for the connected device. Then go to Properties -> Port Settings -> Advanced, and set the COM Port number to something else (e.g. COM 19). Then I had to unplug the device and plug it again and it was working and reverting the port back to the original it was working again


# Optional Drivers
1. (optional) Install drivers (Windows & Mac) for the CH340G Usb2Serial chip: http://vair-monitor.com/drivers/
   * This shall only be needed for the NodeMCU (yellow) and Wemos D1 mini (blue) boards. 
   * Long (battery powered) Wemos and the NodeMCU 1.0 (black ones) usually run without driver installation
