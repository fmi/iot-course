/***************************************************
  BME280 - Temperature, Humidity & Barometric Pressure Sensor

  This example reads temperature, humidity, pressure, and
  approximate altitude from a BME280 sensor using I2C.

  The BME280 is similar to the BMP280 but also measures
  humidity. It is commonly used in weather stations.

  Wiring (ESP32):
    BME280 SDA -> GPIO 21
    BME280 SCL -> GPIO 22
    BME280 VIN -> 3.3V
    BME280 GND -> GND

  I2C address: 0x76 (if SDO pin is connected to GND)
                0x77 (if SDO pin is connected to VCC)

  Required library: Adafruit BME280 Library
    Install via: Sketch -> Include Library -> Manage Libraries
    Search for "Adafruit BME280"
 ***************************************************/

// Include the library for the BME280 sensor
#include <Adafruit_BME280.h>

// Create a sensor object
Adafruit_BME280 bme;

void setup() {
  // Start serial communication so we can see the output
  Serial.begin(115200);
  while (!Serial);

  Serial.println("BME280 example");

  // Initialize I2C with the ESP32 default SDA and SCL pins
  Wire.begin(21, 22);

  // Try to initialize the sensor at address 0x76
  // Change to 0x77 if your sensor uses that address
  if (!bme.begin(0x76)) {
    Serial.println("ERROR: BME280 sensor not found. Check wiring!");
    // Stop the program if the sensor is not found
    while (1) delay(1);
  }

  Serial.println("Found BME280 sensor");
}

void loop() {
  // Read and print the temperature in degrees Celsius
  Serial.print("Temperature: ");
  Serial.print(bme.readTemperature());
  Serial.println(" C");

  // Read and print the relative humidity in percent
  Serial.print("Humidity: ");
  Serial.print(bme.readHumidity());
  Serial.println(" %rH");

  // Read and print the atmospheric pressure in hPa (hectopascals)
  // The raw value is in Pa, so we divide by 100 to get hPa
  Serial.print("Pressure: ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  // Estimate the altitude based on the current pressure
  // 1013.25 hPa is the standard sea level pressure
  // For better accuracy, replace with your local sea level pressure
  Serial.print("Approx. Altitude: ");
  Serial.print(bme.readAltitude(1013.25));
  Serial.println(" m");

  Serial.println();

  // Wait 2 seconds before reading again
  delay(2000);
}
