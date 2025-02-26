# Installation
1. Install [Arduino IDE](https://www.arduino.cc/en/software) 2.3.4
2. Install [ESP32 Development Kit](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)
3. Some boards require USB to serial drivers. To determine which chip you have, open device manager, plug the board and look what appears under `Ports (COM & LPT)`. On linux you may have to tail the syslog to determine the device. Then download the driver from the manufacturer's site. Known drivers are:
   - [Silabs CP2102](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads)


# Board selection
Open the Arduino IDE, plug your board and select the board from the
`Tools > Board > esp32 >` **OLIMEX-ESP32-S2-DevKit-Lipo-USB**

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

## Serial Port under Linux
This post explains what needs to be done to enable the com port under linux: http://forum.vair-monitor.com/showthread.php?tid=1&pid=41#pid41
* ESP and MacOS BigSur 11.2.3 - pyserial or esptool directories not found next to this upload.py tool.
 ![](https://user-images.githubusercontent.com/492455/111058955-b582a480-849a-11eb-853b-f692e5d1e226.png)


# Optional Drivers
1. (optional) Install drivers (Mac) for the CP2102 Usb2Serial chip: [http://vair-monitor.com/drivers/](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads)
   
