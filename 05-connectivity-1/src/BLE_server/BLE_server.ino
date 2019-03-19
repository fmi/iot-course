#include <string.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID        "1811" // Assigned number of Alert notification service: https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.service.alert_notification.xml

class DeviceConnectedCallback: public BLEServerCallbacks {

    private:
      bool deviceConnected = false;

    public:
      void onConnect(BLEServer* pServer) {
        deviceConnected = true;
      };
  
      void onDisconnect(BLEServer* pServer) {
        deviceConnected = false;
      }
  
      bool isDeviceConnected(){
        return deviceConnected;
      }
};
DeviceConnectedCallback *pDcCallback = new DeviceConnectedCallback();

BLECharacteristic *pNewAlertCharacteristic;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE ...");

  BLEDevice::init("ESP32 alerter");
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(pDcCallback);
  Serial.println("Server created");

  
  BLEService *pService = pServer->createService(SERVICE_UUID);
  Serial.println("Service created");
  
  
  BLECharacteristic *pSupportedAlertCharacteristic = pService->createCharacteristic(
                                                           *(new BLEUUID((uint16_t)0x2A47)), // Supported new alert category: https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.supported_new_alert_category.xml
                                                           BLECharacteristic::PROPERTY_READ
                                                         );
  uint8_t val[1]; val[0] = 1; //simple alert https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.alert_category_id_bit_mask.xml
  pSupportedAlertCharacteristic->setValue(val,1);   



  pNewAlertCharacteristic = pService->createCharacteristic(
                                                           /*(new BLEUUID((uint16_t)0x2A46), // New alert: https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.new_alert.xml  */
                                                           "2A46",
                                                           BLECharacteristic::PROPERTY_NOTIFY
                                                         );
  //uint8_t val[1]; val[0] = 1; //simple alert https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.alert_category_id_bit_mask.xml
  //pNewAlertCharacteristic->setValue(val,1);   
  
  
  pService->start();
  Serial.println("Service started");
  
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("BLE advertising started.");
}

// TODO implement 0x2902 to be able to subscribe (Android complains)
// https://play.google.com/store/apps/details?id=com.punchthrough.lightblueexplorer&hl=en_US

void loop() {
  // put your main code here, to run repeatedly:
  bool connected = pDcCallback->isDeviceConnected();
  Serial.println("Device connected: " + String(connected));
  if(connected){
  
    char message[] = "  Hi there";
    size_t len = strlen(message);
    Serial.println("Message length: " + String(len));
    message[0] = 0x00; // Simple alert id https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.alert_category_id.xml
    message[1] = 0x01; // one new alert present https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.new_alert.xml
    // Serial.println("New message length: " + String(strlen(message)) );
    pNewAlertCharacteristic->setValue((uint8_t*)message, len);
    pNewAlertCharacteristic->notify();
    Serial.println("Notification sent");
  }
  delay(2000);
}
