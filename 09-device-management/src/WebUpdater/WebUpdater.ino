/*
  Forked from the official ESP8266 examples
  To upload through terminal you can use: curl -F "image=@firmware.bin" esp8266.local/update
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

const char* host = "esp8266"; // shall be accessible at http://esp8266.local
const char* ssid = "AndroidAP";
const char* password = "*******";

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

void setup(void){

  Serial.begin(115200);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);

  while(WiFi.waitForConnectResult() != WL_CONNECTED){
    WiFi.begin(ssid, password);
    Serial.println("WiFi failed, retrying.");
  }

  MDNS.begin(host); // used to advertise the host through mDNS

  httpUpdater.setup(&httpServer);
  httpServer.begin();

  MDNS.addService("http", "tcp", 80); // advertise the service on DNS-SD
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);
}

void loop(void){
  httpServer.handleClient(); // non blocking
  // do other useful stuff here
  
}
