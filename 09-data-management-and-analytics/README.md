# Exercises

## Implement a data pipeline
1. Produce MQTT messages on ESP8266 (e.g. upon button pressed)
2. Send messages to a RabitMQ MQTT endpoint (provided and connected to a Kafka cluster)
3. Consume messages from the Kafka cluster using a Java client
4. (Optional) Send MQTT messages with QoS 1 (see the [arduino-mqtt library](https://github.com/256dpi/arduino-mqtt)) and
 test what happens upon transmission failure (e.g. the RabbitMQ endpoint is missing, no WiFi ...)
 
## ESP8266, US020, MQTT, RabbitMQ, Kafka Demo
1. Install, setup and start RabbitMQ server - follow previous tutorial: https://github.com/iproduct/course-iot/tree/master/esp8266-mqtt-rabbitmq
2. Install, setup and start Kafka server - follow the [Kafka Quickstart Example tutorial](http://kafka.apache.org/11/documentation/streams/quickstart) - Word counting example.
3. Get the RabbitMQ-to-Kafka bridge and ESP Arduino code from: https://github.com/iproduct/course-iot/tree/master/esp8266-mqtt-kafka-demo


# References
* https://github.com/256dpi/arduino-mqtt
* https://github.com/iproduct/course-iot/blob/master/esp8266-mqtt-rabbitmq/esp8266-mqtt/mqtt_esp8266.ino
* https://github.com/256dpi/lwmqtt/blob/bb48a8f8f60ca546808d3b3e3c2b40bc3adf2293/src/client.c
