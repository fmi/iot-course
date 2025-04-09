#include <WiFi.h> // https://docs.espressif.com/projects/arduino-esp32/en/latest/api/wifi.html

const char* SSID = "TODO";
const char* WIFI_PASSWORD = "TODO";


void setup() {
  Serial.begin(115200);
  while(!Serial);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, WIFI_PASSWORD);

  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println("Connected");

  Serial.print("ESP32 MAC: ");
  Serial.println(WiFi.macAddress());
  
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());

  Serial.print("Subnet mask: ");
  Serial.println(WiFi.subnetMask());

  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  
  Serial.print("Channel: ");
  Serial.println(WiFi.channel());

  Serial.print("DNS: ");
  Serial.println(WiFi.dnsIP());
  
  Serial.print("TxPower: ");
  Serial.println( WiFi.getTxPower());

  IPAddress resolvedIP;
  WiFi.hostByName("google.com", resolvedIP);
  Serial.print("Resolved google.com: ");
  Serial.println(resolvedIP);
}

void loop(){

  Serial.println(WiFi.RSSI()); // -30 to -50 dBm is excellent, -50 to -67 dBm is OK, -67 to -70 dBm shaky
  delay(2000);
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconnecting...");
    WiFi.disconnect();
    WiFi.reconnect();
    // alternatively, see WiFi.onEvent
    // or even simpler, WiFi.setAutoReconnect(true);
  }
}