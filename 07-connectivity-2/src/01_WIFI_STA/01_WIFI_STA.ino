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

  Serial.println(WiFi.RSSI());
  delay(1000);
}