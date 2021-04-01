#include <string.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

#define ALERT_NOTIFICATION_SERVICE_UUID        "1811" // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.service.alert_notification.xml


BLECharacteristic *pNewAlertCharacteristic;
BLEServer *pServer;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE ...");

  BLEDevice::init("ESP32 alerter");
  pServer = BLEDevice::createServer();
  Serial.println("Server created");
  
  BLEService *pService = pServer->createService(ALERT_NOTIFICATION_SERVICE_UUID);
  Serial.println("Service created");
  
  BLECharacteristic *pSupportedAlertCharacteristic = pService->createCharacteristic(
                                                           "2A47", // Supported new alert category: https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.supported_new_alert_category.xml
                                                           BLECharacteristic::PROPERTY_READ
                                                         );
  uint8_t simple_alert_val [] = {0x1};  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.alert_category_id_bit_mask.xml
  pSupportedAlertCharacteristic->setValue(simple_alert_val,1);   



  pNewAlertCharacteristic = pService->createCharacteristic(
                                                           "2A46", // New alert: https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.new_alert.xml  */
                                                           BLECharacteristic::PROPERTY_NOTIFY
                                                         );

 
  BLE2902 *p2902 = new BLE2902();
  p2902->setNotifications(true);
  pNewAlertCharacteristic->addDescriptor(p2902);
  
  pService->start();
  Serial.println("Service started");
  
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(ALERT_NOTIFICATION_SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("BLE advertising started.");
}

// TODO implement 0x2902 to be able to subscribe (Android complains)
// https://play.google.com/store/apps/details?id=com.punchthrough.lightblueexplorer&hl=en_US

void loop() {

  uint32_t nConnected = pServer->getConnectedCount();
  Serial.println("Connected devices from pServer:" + String(nConnected));
  if(nConnected > 0){
  
    char message[] = "  Hi there";
    size_t len = strlen(message);
    Serial.println("Message length: " + String(len));
    message[0] = 0x00; // Simple alert id https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.alert_category_id.xml
    message[1] = 0x01; // one new alert present https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.new_alert.xml
    
    pNewAlertCharacteristic->setValue((uint8_t*)message, len); //simple alert https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.alert_category_id_bit_mask.xml
    pNewAlertCharacteristic->notify(true);
    Serial.println("Notification sent");
  }
  delay(10000);
}
