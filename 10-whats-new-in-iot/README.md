# Exercises

## Implement MQTT Producer with Quality of Service level 1
1. Produce MQTT messages on ESP8266 (e.g. produce sequence of numbers)
- Use one of the following libraries which support QoS: [arduino-mqtt](https://github.com/256dpi/arduino-mqtt) or [adafruit-mqtt](https://github.com/adafruit/Adafruit_MQTT_Library)
2. Send messages to MQTT endpoint (with delay of 1 second between the messages)
- You can use [shftr.io](https://shiftr.io/try)
  - configurations for arduino-mqtt
  ```c
  WiFiClient net;
  MQTTClient client;
  
  WiFi.begin(ssid, pass);
  
  client.begin("broker.shiftr.io", net);
  client.connect("esp<id>", "try", "try")
  ```
  - configurations for adafruit-mqtt
  ```c
  #define AIO_SERVER      "broker.shiftr.io"
  #define AIO_SERVERPORT  1883             
  #define AIO_CLIENT_ID   "esp<id>"
  #define AIO_USERNAME    "try"
  #define AIO_KEY         "try"
  
  WiFiClient client;
  Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT,AIO_CLIENT_ID, AIO_USERNAME, AIO_KEY);
  
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  mqtt.connect()
  ```

## Extend the previos task with retry logic when messages cannot be delivered
- Do not block the producer with retries until the message is delivered - store these messages and when connection is accomplished send them
- You can use [QueueArray](https://playground.arduino.cc/Code/QueueArray)
