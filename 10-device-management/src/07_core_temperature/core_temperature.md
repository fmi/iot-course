
# *ESP32 Core Temperature Measurement*

We are using Olimex [ESP32-DevKit-LiPo Board](https://github.com/OLIMEX/ESP32-DevKit-LiPo/blob/master/DOCS/ESP32-DevKit-LiPo-user-manual.pdf)

You already have some components to use:

- **[ESP32-DevKit-LiPo Board](https://github.com/OLIMEX/ESP32-DevKit-LiPo/blob/master/DOCS/ESP32-DevKit-LiPo-user-manual.pdf)**.

![alt text](/04-displays-and-actuators/src/servo/images/esp32.png)

## Schematic and connections

- Pinout of the ESP32 board is shown [here](images/olimex_esp32.png).

## Code to Run (Arduino Sketches)

1. **No need to install any library**


2. **Run this sketch in Arduino IDE**, The `temperatureRead()` function is used to retrieve the internal temperature
of the ESP32 chip. The temperature is printed to the Serial Monitor in degrees Celsius.

CPU Temperature: 55.00 °C
CPU Temperature: 55.00 °C.

```cpp
/*
Core Temperature Measurement Example
=====================================
This code demonstrates how to measure the CPU core temperature of an ESP32.
The `temperatureRead()` function is used to retrieve the internal temperature
of the ESP32 chip. The temperature is printed to the Serial Monitor.
More details about the `temperatureRead()` function:

Purpose:
The temperatureRead() function reads the internal temperature sensor of the ESP32 chip and returns the temperature in degrees Celsius.

Declaration:
The temperatureRead() function is declared in the ESP32 Arduino core library. It is part of the ESP32's hardware abstraction layer (HAL) and is implemented in the ESP-IDF (Espressif IoT Development Framework).

Return Value:
The function returns a float value representing the temperature in degrees Celsius.

Usage:
The function does not require any arguments and can be called directly in the code.

Accuracy:
The temperature value is approximate and may vary depending on the ESP32 model and environmental conditions. It is primarily intended for internal monitoring and not for precise temperature measurement.



Note:
- The temperature value is approximate and may vary depending on the ESP32 model.
- This feature is primarily for internal monitoring and not for precise temperature measurement.
- The temperature is reported in degrees Celsius.
*/

void setup() {
  // Initialize Serial communication
  Serial.begin(115200);
  delay(1000); // Allow time for the Serial Monitor to initialize

  Serial.println("ESP32 Core Temperature Measurement");
}

void loop() {
  // Read the CPU core temperature
  float temperature = temperatureRead();

  // Print the temperature to the Serial Monitor
  Serial.print("CPU Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Wait for 1 second before the next reading
  delay(1000);
}
```
