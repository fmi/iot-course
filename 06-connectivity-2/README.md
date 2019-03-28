# Exercises

## LoRAWAN on TTN

You have to
* Setup the board in Arduino
* Create a TTN account
* Create a TTN app and register the device

### Board setup
* Make sure the IBM_LMIC library version "1.5.0+arduino-2" is installed in your Arduino IDE (Tools > Manage Libraries ..)
* Download https://quadmeup.com/wp-content/uploads/2017/10/bsfrance.zip
* Go to your Arduino folder e.g. `C:\Users\<Your user>\Documents\Arduino`
* Inside it, create a folder with the name `hardware` if it does not already exist
* Extract the `bsfrance` folder of the archive into the `hardware` folder. You should get a path like `Arduino\hardware\bsfrance\avr`
* Restart Arudino IDE
* Select the `LoRA32u4` board from the Tools > Board menu. 

**PLEASE DOUBLE CHECK THIS, BECAUSE WRONG BOARD SELECTION MAY DESTROY THE BOARD PHYSICALLY**
![alt text][screenshot]

[screenshot]: board_name.png "Board name"


### TTN Account & Application setup
* Create a TTN account and log in: https://account.thethingsnetwork.org/register
* Create a new application
* Add a new device to the application
* In the device settings:
    * Select the `ABP` activation method
    * DISABLE "Frame Counter Checks" at the bottom of the page to [overcome this problem](https://www.thethingsnetwork.org/forum/t/node-is-sending-data-to-ttn-but-no-data-coming-in-at-ttn-console/6982)
* Go back to "Device overview" and take note of the:
    * Device address
    * Network session key
    * App session key
### Create a LoRA client app
* Use the [LoRAWAN example](https://github.com/fmi/iot-course/tree/master/06-connectivity-2/src/01_LoraModuleClient) and replace the three credentials above with yours.
* Upload to the board and inspect if device data is coming in.


## MQTT client with ESP8266
You can use [cloudmqtt's free tier](https://customer.cloudmqtt.com/instance/create?plan=cat) instead of installing your own MQTT server. [This tutorial](http://www.arjunsk.com/iot/esp8266-programming-cloud-mqtt-part-3/) describes an end to end scenario.

More information on [pubSubClient ESP8266](https://github.com/knolleary/pubsubclient)
