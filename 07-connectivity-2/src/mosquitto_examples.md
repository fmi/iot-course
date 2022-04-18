# Intro
This guide has some popular mosquitto commands that have been tested with the course setup at [tb.genevski.com](tb.genevski.com). We have only tested them on Ubuntu.

# Installation
Mosquitto is usually distributed through two packages, `mosquitto` and `mosquitto-clients`. If you don't need to run your own server, you can install the second package only. Have a look at [this installation guide for Ubuntu](http://www.steves-internet-guide.com/install-mosquitto-linux/)

# Clients
## Command line
Mosquitto installation comes with several commands that can be used for testing the protocol.

### Subscribing
To subscribe to a hypothetical topic `topics/1` on a localhost sever you only need to provide the topic URL:
```bash
mosquitto_sub --url mqtt://localhost:1883/topic/1
```
> Full URL option format is: `mqtt://[username[:password]@]host[:port]/topic -u username -P password`

### Publishing
Publishing requires more options, such as QoS and message payload:
```bash
mosquitto_pub --url mqtt://localhost:1883/topic/1 -m 32 -q 0
```

To publish to the provided [tb.genevski.com](tb.genevski.com) MQTT service you need even more options:

- Using non-encrypted TCP connection:
```bash
mosquitto_pub -d -q 1 -h tb.genevski.com -p "1883" -t "v1/devices/me/telemetry" -u youraccesstoken -m {"temperature":25.1}
```

- Using encrypted (TLS) TCP connection
```bash
 mosquitto_pub -d -q 1 -h tb.genevski.com -p "8883" -t "v1/devices/me/telemetry" -u youraccesstoken --capath /etc/ssl/certs/ -m {"temperature":25.3}
```

> WARNING - this has only been tested on Ubuntu and may not work for other distros. You can add either the `--cafile` or `--capath` options as per the [official documentation](https://mosquitto.org/man/mosquitto_pub-1.html), but nevertheless still get SSL handshape errors if your cert store doesn't trust the certificate provider.


## Websockets client
You can use the [live Eclipse Paho client](https://www.eclipse.org/paho/clients/js/utility/) to test websocket communication.


## ESP32 / ESP8266

- [QoS 0 with the knolleary/pubsubclient library](https://github.com/fmi/iot-course/tree/master/07-connectivity-2/src/PubSubClient) 
- [QoS 1 with the 256dpi/arduino-mqtt library](https://github.com/fmi/iot-course/tree/master/07-connectivity-2/src/PubSubClient_qos1)


# Running a mosquitto server through docker
If you nevertheless need to run a mosquitto server, you can look at the really simple setup in the provided [`mosquitto.yml`](mosquitto.yml), which runs in docker swarm / docker compose.

### Generating passwords
One option to supply user accounts to mosquitto is through a `passwd` file. This script can be used to create/update the password for a given user, provided that the `passwd` file is in the current directory.

```bash
docker run -it -v $(pwd):/mnt/tmp eclipse-mosquitto mosquitto_passwd /mnt/tmp/passwd username1
```

> NOTE: the passwd file given in this repo is only an example of what you should expect inside it. Please generate your own file.

### Server configuration
Server configuration has been provided in the given `mosquitto.conf` and `mosquitto.yml` files.

References:
- https://mosquitto.org/man/mosquitto_passwd-1.html
- https://www.digitalocean.com/community/tutorials/how-to-install-and-secure-the-mosquitto-mqtt-messaging-broker-on-ubuntu-16-04 
