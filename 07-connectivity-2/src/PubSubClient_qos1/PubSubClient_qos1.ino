#include <ESP8266WiFi.h>
#include <MQTT.h> // https://github.com/256dpi/arduino-mqtt

const char* mqtt_server = "tb.genevski.com";
const char* clientId = "DoesntMatter";
const char* user = "niceaccesstoken2021";
const char* pass = NULL;

WiFiClient wifi;
MQTTClient client;

void setup_wifi() {
  WiFi.begin("btc123", "iwhishiknewthat"); 
  Serial.println("Connecting to wifi ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
}

bool reconnect() {
  Serial.println("Reconnect requested");
  if(client.connected()) {
    Serial.println("MQTT client is still connected");
    return true;
  } 
  
  Serial.print("Reconnecting to MQTT server...");  
  if(client.connect(clientId, user, pass)) {
    Serial.println("connected");
    
    //client.subscribe("topics/2");
    //Serial.println("resubscribed");
    return true;
    
  } else {
    Serial.println("failed");
    lwmqtt_err_t err = client.lastError();
    Serial.println(err);

    lwmqtt_return_code_t ret = client.returnCode();
    Serial.println(ret);
    return false;
  }
}

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
  
  setup_wifi();
  
  client.onMessage(messageReceived);
  client.begin(mqtt_server, wifi);
}

void loop() {
  
  float temperature = random(200, 301) / 10.0;

  if(!reconnect()){
    // TODO buffer the measurement to send next time
  } else {
    client.loop(); // process incoming messages and maintain connection to server
    delay(10);
      
    // TODO add sequence number
    String json = "{\"temperature\":" + String(temperature,1) + "}"; 
    Serial.println(json);

    int qos = 1;
    bool retained = false;
    bool success = client.publish("v1/devices/me/telemetry", json.c_str(), retained, qos);
    if(!success){
      Serial.println("publish failed");
      lwmqtt_err_t err = client.lastError(); // https://github.com/256dpi/arduino-mqtt/blob/master/src/lwmqtt/lwmqtt.h
      Serial.println(err);
    }
  }
  delay(2000);
}
