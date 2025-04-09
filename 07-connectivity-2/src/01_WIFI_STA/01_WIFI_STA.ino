#include <WiFi.h>

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
  Serial.print("Connected. Local IP: ");
  Serial.println(WiFi.localIP());
  // TODO get mac
}

void loop(){

  Serial.println(WiFi.RSSI()); // -30 to -50 dBm is excellent, -50 to -67 dBm is OK, -67 to -70 dBm shaky
  delay(1000);
}