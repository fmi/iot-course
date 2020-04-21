# Installation
## Running the mosquitto server
For a really simple setup for testing you can use the provided `mosquitto.yml` with docker swarm / docker compose. Alternatively, you can install and run it as a windows service


## Clients
### Command line
The mosquitto installation comes with several commands that can be used for testing the protocol.

To subscribe to a hypothetical topic `topics/1` on the command line (e.g. for testing):
```bash
mosquitto_sub --url mqtt://localhost:1883/topic/1
```
> Full URL option format is: `mqtt://[username[:password]@]host[:port]/topic`

To publish a message:
```bash
mosquitto_pub --url mqtt://localhost:1883/topic/1 -m 32 -q 0
```

> WARNING - may not work easily for TLS connection. You must add either the `--cafile` or `--capath` options as per the [official documentation](https://mosquitto.org/man/mosquitto_pub-1.html), but nevertheless still get SSL handshape errors. For TLS better test it with the GIU based client

### GUI client
Use [MQTT.FX](http://mqttfx.org/). It is a cross-platform open source tool that actually worked for me.

### ESP32 / ESP8266
Use [Pubsubclient](https://pubsubclient.knolleary.net/api.html)