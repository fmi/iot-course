
# *ESP32 USB Voltage Measurement Example*

We are using Olimex [ESP32-DevKit-LiPo Board](https://github.com/OLIMEX/ESP32-DevKit-LiPo/blob/master/DOCS/ESP32-DevKit-LiPo-user-manual.pdf)

You already have some components to use:

- **[ESP32-DevKit-LiPo Board](https://github.com/OLIMEX/ESP32-DevKit-LiPo/blob/master/DOCS/ESP32-DevKit-LiPo-user-manual.pdf)**.

![alt text](/04-displays-and-actuators/src/servo/images/esp32.png)

## Schematic and connections

- Pinout of the ESP32 board is shown [here](images/olimex_esp32.png).

## Code to Run (Arduino Sketches)

1. **No need to install any library**

2. **Run this sketch in Arduino IDE**:
Expected Output: The supply voltage will be printed to the Serial Monitor in volts.
Example output:

```
Raw ADC Value: 4095
Measured Voltage: 3.30 V
Supply Voltage: 5.00 V
```

```cpp
/*
ESP32 USB Voltage Measurement Example (OLIMEX ESP32-DevKit-LiPo)
========================================================
This code demonstrates how to measure the USB voltage powering the ESP32
using the internal ADC. Ensure the correct ADC pin and voltage divider ratio
are used based on the board's documentation.


**NOTE: AVOID EXCEEDING ADC VOLTAGE LIMITS:**  
THE ESP32'S ADC CAN ONLY MEASURE VOLTAGES IN THE RANGE OF 0–3.3V. ENSURE THAT THE VOLTAGE BEING MEASURED IS WITHIN THIS RANGE.  
IF THE USB VOLTAGE (5V) IS DIRECTLY CONNECTED TO THE ADC PIN WITHOUT A PROPER VOLTAGE DIVIDER, IT CAN DAMAGE THE ESP32.


1. Internal Voltage Divider:
 - Some ESP32 boards have an internal voltage divider connected to the VCC pin, which scales down the supply voltage to a range measurable by the ADC (0–3.3V).
 - The VOLTAGE_DIVIDER_RATIO is used to calculate the actual supply voltage from the measured voltage. For example, if the divider ratio is 2:1, the VOLTAGE_DIVIDER_RATIO is 2.0.

2. ADC Configuration:
- The ADC pin (e.g., GPIO 35) is used to read the scaled-down voltage.
- The ESP32's ADC has a resolution of 12 bits, meaning the raw ADC value ranges from 0 to 4095.

3. Voltage Calculation:
- The raw ADC value is converted to a voltage using the formula:
    * Measured Voltage = (Raw ADC Value / ADC Resolution) * Reference Voltage

4. Supply Voltage Calculation:
- The supply voltage is calculated using the voltage divider ratio:
    * Supply Voltage = Measured Voltage * Voltage Divider Ratio
*/

const int ADC_PIN = 0; // Update this to the correct ADC pin
const float ADC_RESOLUTION = 4095.0; // 12-bit ADC resolution
const float ADC_REF_VOLTAGE = 3.3; // Reference voltage for the ADC (in volts)
const float VOLTAGE_DIVIDER_RATIO = 1.515; // Update this based on the board's documentation

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("ESP32 USB Voltage Measurement");
}

void loop() {
  int rawADC = analogRead(ADC_PIN); // Read raw ADC value
  float measuredVoltage = (rawADC / ADC_RESOLUTION) * ADC_REF_VOLTAGE; // Convert to voltage
  float supplyVoltage = measuredVoltage * VOLTAGE_DIVIDER_RATIO; // Calculate supply voltage

  // Debugging output
  Serial.print("Raw ADC Value: ");
  Serial.println(rawADC);
  Serial.print("Measured Voltage: ");
  Serial.print(measuredVoltage);
  Serial.println(" V");
  Serial.print("Supply Voltage: ");
  Serial.print(supplyVoltage);
  Serial.println(" V");

  delay(1000);
}
```
