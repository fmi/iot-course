#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h> // TODO consider https://github.com/me-no-dev/ESPAsyncWebServer
#include "FS.h"

#include <algorithm>
#include <string>

const char* ssid = "btc123";
const char* password = "iwhichiknewthat";

ESP8266WebServer server(80);

float temperature = 0.0;
int humidity = 50;

void setupWiFi(){
  Serial.println("Setting up wifi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}


void setupFS(){
  if(!SPIFFS.begin()){
    Serial.println("Cannot start SPIFFS");
    return;
  }
  Serial.println("SPIFFS ready");
  
  File file = SPIFFS.open("/index.html", "r");
  if(!file){
    Serial.println("Cannot open index.html");
  }
}


void handleHome(){
  server.send(200, "text/html", "I am alive"); // TODO serve html from SPIFFS
}


void handleMeasurements() {

    String response = "{";
    
    response+= "\"temperature\":" + String(temperature);
    response+= ",\"humidity\":" + String(humidity);

    response+="}";
    server.sendHeader("Access-Control-Allow-Origin", "*", true);  // for browser testing
    server.send(200, "text/json", response);
}


void handleNotFound(){
  server.send(404, "text/plain", "Not found");
}


void setupRoutes(){
    server.on("/", HTTP_GET, handleHome);
    server.on("/measurements", HTTP_GET, handleMeasurements);
   
    server.onNotFound(handleNotFound);
    
    server.begin();
    Serial.println("HTTP server ready");
}


void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(1);
  }
  Serial.println("Serial ready");

  setupWiFi();
  setupRoutes();
  setupFS();
}


void loop() {
  temperature = random(200, 300) / 10.0;
  humidity = random(30, 80);

  server.handleClient();
  delay(100);
}
