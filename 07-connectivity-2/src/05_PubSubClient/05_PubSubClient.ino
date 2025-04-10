#include <WiFi.h>
#include <PubSubClient.h> //https://github.com/knolleary/pubsubclient/blob/master/src/PubSubClient.cpp

const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* clientId = "DoesntMatter98327988982385729834028";
// const char* user = "rw";
// const char* pass = "readwrite";

WiFiClient wifi;
PubSubClient client(wifi);

void setup_wifi() {
  WiFi.begin("btc123", "whishiknewit"); 
  Serial.println("Connecting to wifi ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
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
  // if (client.connect(clientId, user, pass)) {
  if(client.connect(clientId)) {
    Serial.println("connected");
    
    client.subscribe("v1/devices/me/telemetry");
    Serial.println("resubscribed");
    return 0;
    
  } else {
    Serial.println("failed");
    return client.state();
  }
}

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
  
  setup_wifi();
  
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  
  float temperature = random(200, 301) / 10.0;

  int err = reconnect();
  if(err != 0){
    // TODO buffer the measurement to send next time
    Serial.println("Could not reconnect");
  } else {
    client.loop(); // process incoming messages and maintain connection to server
    
    // TODO add sequence number
    String json = "{\"temperature\":" + String(temperature,1) + "}"; 
    // Serial.println(json);
    client.publish("v1/devices/me/telemetry", json.c_str());
    
  }
  delay(2000);
}
