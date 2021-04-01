# Exercises

## UART
Review the code of the [RS485 anemometer example](https://www.hackster.io/philippedc/arduino-esp8266-rs485-modbus-anemometer-45f1d8
).

> ESP32 has [three hardware UART devices](https://github.com/G6EJD/ESP32-Using-Hardware-Serial-Ports
) of which at least one is available, so you don't need [software serial as in ESP8266](https://github.com/plerup/espsoftwareserial).

- https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/uart.html

## SPI
Review the code of the [official SPI example](https://github.com/espressif/arduino-esp32/blob/master/libraries/SPI/examples/SPI_Multiple_Buses/SPI_Multiple_Buses.ino).

> ESP32 has [four hardware SPI devices](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/spi_master.html), of which only two can be used by your program (HSPI and VSPI).

## OneWire
Connect the DS18b20 temp sensor to the board and measure its temperature

## Bluetooth Low Energy 
Use ESP32 to emulate a heart rate monitor. 

* Use the [SelfLoops HRV application (Android)](https://play.google.com/store/apps/details?id=com.wellness.selfloops.hrv&hl=en_US&gl=US) to test if it works.

## (Optional) LoRa
Review the implementation of the LoRa client device.

## (Optional) ISM band (433MHz) connectivity (HC-12)
Implement a remote controlled LED using the HC-12 module

The HC-12 is a wireless serial port communication module that is very useful, extremely powerful and easy to use. It allows communication up to 1.8km distance in open air. You have to implement an receiver and a transmitter.

HC-12 is configurable, take a look at [AT Commands:](https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-12-long-range-wireless-communication-module)



