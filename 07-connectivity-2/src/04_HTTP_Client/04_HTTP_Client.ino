#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h> // ArduinoJson by Benoit Blanchon...

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
  WiFi.setAutoReconnect(true);

  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
}

void loop(){

  HTTPClient http;
  http.begin("https://api.open-meteo.com/v1/forecast?latitude=42.67&longitude=23.33&current=temperature_2m,wind_speed_10m,relative_humidity_2m");
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    String payload = http.getString();
    Serial.println(payload);

    JsonDocument doc; // https://arduinojson.org/v7/assistant
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
    } else {
      Serial.println("Elevation: " + String(doc["elevation"]));

    JsonObject current_units = doc["current_units"];
    const char* temperature_unit = current_units["temperature_2m"]; // "°C"
    const char* wind_speed_unit = current_units["wind_speed_10m"]; // "km/h"
    const char* humidity_unit = current_units["relative_humidity_2m"]; // "%"

    JsonObject current = doc["current"];
    float temperature = current["temperature_2m"]; // 6.3
    int wind_speed = current["wind_speed_10m"]; // 12
    int humidity = current["relative_humidity_2m"]; // 44
    Serial.println(String(temperature) + temperature_unit + ", " + String(wind_speed) + wind_speed_unit + ", " + String(humidity) + humidity_unit);

    }


  } else {
    Serial.println("Request failed: " + String(httpCode));
  }

  delay(120 * 1000); // do not flood the API with too many requests

}