
/*
 * Original example by: https://github.com/SensorsIot/Bluetooth-BLE-on-Arduino-IDE/blob/master/Polar_H7_Sensor/Polar_H7_Sensor.ino 
 */
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>


byte flags = 0b00111110;
byte bpm = 1;
byte heart[8] = { 0b00001110, 60, 0, 0, 0 , 0, 0, 0};
byte hrmPos[1] = {2};

#define heartRateService BLEUUID((uint16_t)0x180D)

BLECharacteristic heartRateMeasurementCharacteristics(BLEUUID((uint16_t)0x2A37), BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic sensorPositionCharacteristic(BLEUUID((uint16_t)0x2A38), BLECharacteristic::PROPERTY_READ);

void setup() {

  Serial.begin(115200);
  Serial.println("Start");
  
  BLEDevice::init("Pavel H7");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(heartRateService);

  pService->addCharacteristic(&heartRateMeasurementCharacteristics);
  pService->addCharacteristic(&sensorPositionCharacteristic);

  BLEDescriptor heartRateDescriptor(BLEUUID((uint16_t)0x2901));
  heartRateDescriptor.setValue("Rate from 0 to 200");
  heartRateMeasurementCharacteristics.addDescriptor(&heartRateDescriptor);
  heartRateMeasurementCharacteristics.addDescriptor(new BLE2902());
  
  BLEDescriptor sensorPositionDescriptor(BLEUUID((uint16_t)0x2901));
  sensorPositionDescriptor.setValue("Position 0 - 6");
  sensorPositionCharacteristic.addDescriptor(&sensorPositionDescriptor);
  
  
  pServer->getAdvertising()->addServiceUUID(heartRateService);

  pService->start();
  pServer->getAdvertising()->start();
}

void loop() {
  
  heart[1] = (byte)bpm;
  int energyUsed = 3000;
  heart[3] = energyUsed / 256;
  heart[2] = energyUsed - (heart[2] * 256);
  Serial.println("BPM:" + String(bpm));

  heartRateMeasurementCharacteristics.setValue(heart, 8);
  heartRateMeasurementCharacteristics.notify();

  sensorPositionCharacteristic.setValue(hrmPos, 1);
  bpm++;

  delay(2000);
}
