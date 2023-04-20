# Exercises
## HTTP (and different WiFi modes)
- [Station + HTTP client](https://randomnerdtutorials.com/esp32-http-get-post-arduino/)
  - You may use the [Yahoo finance endpoint](https://query1.finance.yahoo.com/v8/finance/chart/SAP?interval=1d) 
- [Access point + HTTP server](https://randomnerdtutorials.com/esp32-web-server-arduino-ide/)

## MQTT

- [QoS 0 with the knolleary/pubsubclient library](https://github.com/fmi/iot-course/tree/master/08-connectivity-2/src/PubSubClient) 
- [QoS 1 with the 256dpi/arduino-mqtt library](https://github.com/fmi/iot-course/tree/master/08-connectivity-2/src/PubSubClient_qos1)

Use thingsboard server at [tb.genevski.com](tb.genevski.com) for these exercises. You shall setup a device first, using the official [thingsboard helloworld tutorial](https://thingsboard.io/docs/getting-started-guides/helloworld/). It is recommended to first test the MQTT connection [using mosquitto command line client](https://github.com/fmi/iot-course/blob/master/08-connectivity-2/src/mosquitto_examples.md) and only then try with the ESP32 to make it easier to isolate errors.

> Credentials for [tb.genevski.com](tb.genevski.com) will be provided during the lecture.
