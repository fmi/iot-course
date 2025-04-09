#include <WiFi.h>
#include <WiFiAP.h>

const char* SSID = "TODO";
const char* WIFI_PASSWORD = "1234567890";


void setup() {
  Serial.begin(115200);
  while(!Serial);


  if (!WiFi.softAP(SSID, WIFI_PASSWORD)) {
    Serial.println("Soft AP creation failed.");
    while(true);
  }
  
  IPAddress access_point_ip = WiFi.softAPIP();
  Serial.print("AP is up. IP: ");
  Serial.println(access_point_ip);
}

void loop(){

  Serial.print("I am alive: ");
  Serial.println(millis());
  delay(1000);
}