/***************************************************
  BMP280 - Temperature & Barometric Pressure Sensor

  This example reads temperature, pressure, and
  approximate altitude from a BMP280 sensor using I2C.

  Wiring (ESP32):
    BMP280 SDA -> GPIO 21
    BMP280 SCL -> GPIO 22
    BMP280 VIN -> 3.3V
    BMP280 GND -> GND

  I2C address: 0x76 (if SDO pin is connected to GND)
                0x77 (if SDO pin is connected to VCC)

  Required library: Adafruit BMP280 Library
    Install via: Sketch -> Include Library -> Manage Libraries
    Search for "Adafruit BMP280"
 ***************************************************/

// Include the library for the BMP280 sensor
#include <Adafruit_BMP280.h>

// Create a sensor object
Adafruit_BMP280 bmp;

void setup() {
  // Start serial communication so we can see the output
  Serial.begin(115200);
  while (!Serial);

  Serial.println("BMP280 example");

  // Initialize I2C with the ESP32 default SDA and SCL pins
  Wire.begin(21, 22);

  // Try to initialize the sensor at address 0x76
  // Change to 0x77 if your sensor uses that address
  if (!bmp.begin(0x76)) {
    Serial.println("ERROR: BMP280 sensor not found. Check wiring!");
    // Stop the program if the sensor is not found
    while (1) delay(1);
  }

  Serial.println("Found BMP280 sensor");
}

void loop() {
  // Read and print the temperature in degrees Celsius
  Serial.print("Temperature: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" C");

  // Read and print the atmospheric pressure in hPa (hectopascals)
  // The raw value is in Pa, so we divide by 100 to get hPa
  Serial.print("Pressure: ");
  Serial.print(bmp.readPressure() / 100.0F);
  Serial.println(" hPa");

  // Estimate the altitude based on the current pressure
  // 1013.25 hPa is the standard sea level pressure
  // For better accuracy, replace with your local sea level pressure
  Serial.print("Approx. Altitude: ");
  Serial.print(bmp.readAltitude(1013.25));
  Serial.println(" m");

  Serial.println();

  // Wait 2 seconds before reading again
  delay(2000);
}
