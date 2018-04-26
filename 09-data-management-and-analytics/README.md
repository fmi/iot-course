# Exercises

## Implement a data pipeline
1. Produce MQTT messages on ESP8266 (e.g. upon button pressed)
2. Send messages to a RabitMQ MQTT endpoint (provided and connected to a Kafka cluster)
3. Consume messages from the Kafka cluster using a Java client
4. (Optional) Send MQTT messages with QoS 1 (see the [arduino-mqtt library](https://github.com/256dpi/arduino-mqtt)) and
 test what happens upon transmission failure (e.g. the RabbitMQ endpoint is missing, no WiFi ...)


# References
* https://github.com/256dpi/arduino-mqtt
* https://github.com/iproduct/course-iot/blob/master/esp8266-mqtt-rabbitmq/esp8266-mqtt/mqtt_esp8266.ino
* https://github.com/256dpi/lwmqtt/blob/bb48a8f8f60ca546808d3b3e3c2b40bc3adf2293/src/client.c