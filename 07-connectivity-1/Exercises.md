# Exercises

## ESP-NOW
Make a transmitter and receiver with two ESP devices (or only sender, we will provide few receivers for shared usage).

### Prepare transmitter ESP 
> [!NOTE]
> You can skip MAC address step 1 if using already prepared receiver.

1. First you need to obtain WIFI MAC address of the receiver device. [Run this sketch](src/ESP-Now/mac-scanner.ino) on the receiver ESP and obtain MAC address from the serial console.

2. [Upload this sketch](src/ESP-Now/espnow-transmitter.ino) on the transmitter ESP and do not forget to change the MAC address in the code. Now when you power on the transmitter it will start to transmit messages each 1 sec and will print results in the serial console.

### Prepare the receiver ESP
[Upload this sketch](src/ESP-Now/espnow-receiver.ino) on the receiver ESP device and run it. On the serial console it will print what it receives. Also a single ESP device can receive ESP-Now data from multiple receivers, as long as they are configured with it's MAC Address. 

(Optional) You can extend the exercise by modifying sending data by receiving input from a button or connecting display on the receiver to show the data. Or modify the sketch to turn on the builtin LED on the receiver (https://circuits4you.com/2018/02/02/esp32-led-blink-example/) by pressing the BOOT button on the transmitter (BOOT button is connected to GPIO0).

- more about ESP-NOW: https://docs.arduino.cc/tutorials/nano-esp32/esp-now/
- Exercise is based on this tutorial: https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/ 

## Bluetooth Low Energy 
Use ESP32 to [emulate a heart rate monitor](src/02_BLE_heartrate/02_BLE_heartrate.ino). 

* Use the [SelfLoops HRV application (Android)](https://play.google.com/store/apps/details?id=com.wellness.selfloops.hrv&hl=en_US&gl=US) to test if it works.

## UART
Review the code of the [RS485 Modbus smart meter example](https://embeddedthere.com/how-to-interface-esp32-with-rs485-modbus-sensors-with-example-code/).

> ESP32 has [three hardware UART devices](https://circuits4you.com/2018/12/31/esp32-hardware-serial2-example/) of which at least one is available, so you don't need [software serial as in ESP8266](https://github.com/plerup/espsoftwareserial). 
> - https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/uart.html

## SPI
Review the code of the [official SPI example](https://github.com/espressif/arduino-esp32/blob/master/libraries/SPI/examples/SPI_Multiple_Buses/SPI_Multiple_Buses.ino).

> ESP32 has [four hardware SPI devices](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/spi_master.html), of which only two can be used by your program (HSPI and VSPI).
> - [More details about the SPI protocol](https://www.analog.com/en/analog-dialogue/articles/introduction-to-spi-interface.html#)

## OneWire
Connect the DS18b20 temp sensor to the board and [measure its temperature](src/DS18x20_multiple/DS18x20_multiple.ino)

You can connect the sensor in two ways:
- Three wire interface: https://randomnerdtutorials.com/guide-for-ds18b20-temperature-sensor-with-arduino/
- Parasitic power: https://forum.arduino.cc/t/ds18b20-problem-with-parasite-power-mode/415950

![schematic](https://europe1.discourse-cdn.com/arduino/original/4X/b/9/a/b9a8e50187caa34614fcf361a51fd5f0f04bf393.jpeg "Parasitic power")

## (Optional) LoRa
Review the implementation of the LoRa client device.

