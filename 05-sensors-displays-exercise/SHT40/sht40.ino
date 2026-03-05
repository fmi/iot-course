/***************************************************
  SHT40 - Temperature & Humidity Sensor

  This example reads temperature and humidity from
  a SHT4x sensor using I2C.

  Wiring (ESP32):
    SHT40 SDA -> GPIO 21
    SHT40 SCL -> GPIO 22
    SHT40 VIN -> 3.3V
    SHT40 GND -> GND

  I2C address: 0x44 (default)

  Required library: Adafruit SHT4x Library
    Install via: Sketch -> Include Library -> Manage Libraries
    Search for "Adafruit SHT4x"
 ***************************************************/

// Include the library for the SHT4x sensor
#include "Adafruit_SHT4x.h"

// Create a sensor object
Adafruit_SHT4x sht4 = Adafruit_SHT4x();

void setup() {
  // Start serial communication so we can see the output
  Serial.begin(115200);

  while (!Serial)
    delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit SHT4x test");

  // Try to initialize the sensor
  if (! sht4.begin()) {
    Serial.println("Couldn't find SHT4x. Check wiring!");
    // Stop the program if the sensor is not found
    while (1) delay(1);
  }
  Serial.println("Found SHT4x sensor");
  Serial.print("Serial number 0x");
  Serial.println(sht4.readSerial(), HEX);

  // Set measurement precision: HIGH, MED, or LOW
  // Higher precision takes longer but gives more accurate readings
  sht4.setPrecision(SHT4X_HIGH_PRECISION);
  switch (sht4.getPrecision()) {
     case SHT4X_HIGH_PRECISION: 
       Serial.println("High precision");
       break;
     case SHT4X_MED_PRECISION: 
       Serial.println("Med precision");
       break;
     case SHT4X_LOW_PRECISION: 
       Serial.println("Low precision");
       break;
  }

  // The SHT4x has a built-in heater to remove condensation
  // Higher heat and longer times use more power
  // NO_HEATER is recommended for normal operation
  sht4.setHeater(SHT4X_NO_HEATER);
  switch (sht4.getHeater()) {
     case SHT4X_NO_HEATER: 
       Serial.println("No heater");
       break;
     case SHT4X_HIGH_HEATER_1S: 
       Serial.println("High heat for 1 second");
       break;
     case SHT4X_HIGH_HEATER_100MS: 
       Serial.println("High heat for 0.1 second");
       break;
     case SHT4X_MED_HEATER_1S: 
       Serial.println("Medium heat for 1 second");
       break;
     case SHT4X_MED_HEATER_100MS: 
       Serial.println("Medium heat for 0.1 second");
       break;
     case SHT4X_LOW_HEATER_1S: 
       Serial.println("Low heat for 1 second");
       break;
     case SHT4X_LOW_HEATER_100MS: 
       Serial.println("Low heat for 0.1 second");
       break;
  }
  
}


void loop() {
  // sensors_event_t is a standard Adafruit type for sensor readings
  sensors_event_t humidity, temp;

  // Measure how long the reading takes
  uint32_t timestamp = millis();
  // Read temperature and humidity from the sensor
  sht4.getEvent(&humidity, &temp);
  timestamp = millis() - timestamp;

  // Print the temperature in degrees Celsius
  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  // Print the relative humidity in percent
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  Serial.print("Read duration (ms): ");
  Serial.println(timestamp);

  // Wait 1 second before reading again
  delay(1000);
}