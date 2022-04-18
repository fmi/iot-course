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
> Full URL option format is: `mqtt://[username[:password]@]host[:port]/topic -u username -P password`

To publish a message  use e.g.:
```bash
mosquitto_pub --url mqtt://localhost:1883/topic/1 -m 32 -q 0
```

Alternatively for ThingsBoard:
```bash
mosquitto_pub -d -q 1 -h tb.genevski.com -p "1883" -t "v1/devices/me/telemetry" -u youraccesstoken -m {"temperature":25.1}
```


> WARNING - may not work easily for TLS connection. You must add either the `--cafile` or `--capath` options as per the [official documentation](https://mosquitto.org/man/mosquitto_pub-1.html), but nevertheless still get SSL handshape errors. For TLS better test it with the GIU based client

- https://mosquitto.org/man/mosquitto_pub-1.html

### Websockets client
You can use the [live Eclipse Paho client](https://www.eclipse.org/paho/clients/js/utility/) to test websocket communication.


### ESP32 / ESP8266
Use [Pubsubclient](https://pubsubclient.knolleary.net/api.html)


## Server configuration
### Generating passwords
One option to supply user accounts to mosquitto is through a pa
This script can be used to create/update the password for a given user, provided that the `passwd` file is in the current directory.
```bash
docker run -it -v $(pwd):/mnt/tmp eclipse-mosquitto mosquitto_passwd /mnt/tmp/passwd username1
```

> NOTE: the passwd file given in this repo is only an example of what you should expect inside it. Please generate your own file.

### Server configuration
Server configuration has been provided in the given `mosquitto.conf` and `mosquitto.yml` files.

References:
- https://mosquitto.org/man/mosquitto_passwd-1.html
- https://www.digitalocean.com/community/tutorials/how-to-install-and-secure-the-mosquitto-mqtt-messaging-broker-on-ubuntu-16-04 
