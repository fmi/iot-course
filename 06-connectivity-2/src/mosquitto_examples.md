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
> Full URL option format is: `mqtt(s)://[username[:password]@]host[:port]/topic`

To publish a message:
```bash
mosquitto_pub --url mqtt://localhost:1883/topic/1 -m 32 -q 0
```