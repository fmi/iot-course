#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 0

OneWire oneWire(ONE_WIRE_BUS);  
DallasTemperature sensors(&oneWire);

int deviceCount = 0;
float tempC;

void setup(void)
{
  Serial.begin(115200);
  while(!Serial){
    delay(1);
  }

  Serial.println("Starting sensors");
  sensors.begin();
  
  Serial.print("Locating devices...");
  deviceCount = sensors.getDeviceCount();
  Serial.println("Found " + String(deviceCount) + " devices");
}

void loop(void)
{ 
  sensors.requestTemperatures(); 
  
  for (int i = 0;  i < deviceCount;  i++){
    tempC = sensors.getTempCByIndex(i);
    
    Serial.println("Sensor " + String(i+1) + ": " + tempC + " C | " + DallasTemperature::toFahrenheit(tempC) + " F");
  }
  
  Serial.println("");
  delay(1500);
}
