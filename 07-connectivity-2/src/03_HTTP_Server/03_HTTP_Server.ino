// inspired by https://lastminuteengineers.com/creating-esp32-web-server-arduino-ide/
#include <WiFi.h>
#include <WiFiAP.h>
#include <WebServer.h>

#define LED_PIN 17

const char* SSID = "TODO";
const char* WIFI_PASSWORD = "1234567890";
const int PORT = 80;

bool LED = LOW;

WebServer server(PORT);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  while(!Serial);


  if (!WiFi.softAP(SSID, WIFI_PASSWORD)) {
    Serial.println("Soft AP creation failed.");
    while(true);
  }
  
  IPAddress access_point_ip = WiFi.softAPIP();
  Serial.print("AP is up. IP: ");
  Serial.println(access_point_ip);

  server.on("/", handle_root);
  server.on("/on", handle_on);
  server.on("/off", handle_off);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("Server started on port: " + String(PORT));
}

void handle_root() {
  server.send(200, "text/html", html_template(LED)); 
}

void handle_on() {
  Serial.println("ON");
  LED = HIGH;
  server.send(200, "text/html", html_template(LED)); 
}

void handle_off() {
  Serial.println("OFF");
  LED = LOW;
  server.send(200, "text/html", html_template(LED));
}

void handle_NotFound(){
  server.send(404, "text/plain", "Nothing here");
}

String html_template(uint8_t led){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Controller</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>LED controller</h1>\n";
  
  if(led){
    ptr +="<a class=\"button button-on\" href=\"/off\">TURN OFF</a>\n";
  } else {
    ptr +="<a class=\"button button-off\" href=\"/on\">TURN ON</a>\n";
  }

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}

void loop(){
  server.handleClient();
  digitalWrite(LED_PIN, LED);
}