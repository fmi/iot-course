#include "Adafruit_SGP40.h"
#include "SHT2x.h"

Adafruit_SGP40 sgp; // default address 0x59
SHT2x sht; // default address 0x40

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("SGP40 example with temperature compensation");
  Wire.begin(21, 22); // SDA, SCL

  if (! sgp.begin()){ 
    Serial.println("ERROR: SGP40 sensor not found");
    while (1);
  }

  if (!sht.begin()) {
    Serial.println("ERROR: SHT sensor not found");
    while (1);
  }

  Serial.print("Found all sensors. SGP serial: ");
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);
  delay(3000);
}

void loop() {
  uint16_t sraw;
  int32_t voc_index;

  sht.read(); 
  float t = sht.getTemperature();
  float h = sht.getHumidity();
  Serial.print(t); Serial.print(" C"); Serial.print("\t"); Serial.print(h); Serial.println("\%");

  sraw = sgp.measureRaw(t, h);
  Serial.print("Raw measurement: "); Serial.println(sraw);

  voc_index = sgp.measureVocIndex(t, h);
  Serial.print("Voc Index: "); Serial.println(voc_index);

  delay(2000);
}
