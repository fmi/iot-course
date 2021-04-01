#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* mqtt_server = "mqtt.genevski.com";
const char* clientId = "ESP32Client";

WiFiClient wifi;
PubSubClient client(wifi);

void setup_wifi() {
  WiFi.begin("btc123", "malchozaicho");
  Serial.println("Connecting to wifi ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on topic [" + String(topic) + "]");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

int reconnect() {
  Serial.println("Reconnect requested");
  if(client.connected()) {
    Serial.println("MQTT client is still connected");
    return 0;
  }
  
  Serial.print("Reconnecting to MQTT server...");  
  if (client.connect(clientId)) {
    Serial.println("connected");
    client.subscribe("topics/2"); // resubscribe
    return 0;
  } else {
    Serial.println("failed");
    return client.state();
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  // TODO performa some real measurement here
  float temperature = 25.8;

  int err = reconnect();
  if(err != 0){
    // TODO buffer the measurement to send next time
  } else {
    client.loop(); // process incoming messages and maintain connection to server
    client.publish("topics/1", String(temperature).c_str()); // TODO format message in JSON and add sequence number
  }
  delay(2000);
}
