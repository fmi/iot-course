# Exercises

## Measure battery voltage
Battery voltage cannot be measured on a digital pin, because it is an analog value that must be converted to digital first. Luckily, [ESP8266](https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf) and [ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/peripherals/adc.html) both have a built in ADC (analog to digital converter). 

This exercise shall be done with **ESP8266**. Be aware that the chip (ESP12) itself expects a voltage within the range [0,1V], however there is usually a voltage divider on the board (Wemos D1 and NodeMCU), that allows us to pass higher voltages. For example, Wemos D1 has a 1/3.3 divider, that allows us to pass voltages in the range [0,3.3V]

![Wemos D1 schematic](https://escapequotes.net/wp-content/uploads/2016/02/wemos-d1-mini-shematics.jpg "Wemos D1 schematic")
[**THE ABSOLUTE MAX VOLTAGE TOLERABLE VOLTAGE ON THE ANALOG PIN IS NO MORE THAN 1.8V**](https://www.esp8266.com/viewtopic.php?f=5&t=5556). Due to this, we may be forgiven if we pass e.g. 5V to the **input of the built in divider**. However, in all cases whe shall aim to have less than 1V on the internal analog pin. 


To simulate a battery and to uderstand how dividers work, proceed as follows:
* See this diagram to understand [voltage dividers](https://crcit.net/c/9a0ef05f)
* Connect the A0 pin of ESP8266 to GND (this shall always be safe). Then run the program to measure the voltage. Value shall be zero or very close to it.
* Connect A0 (AD on the battery powered boards) to the 3.3V. Measured value shall be close to the max one (raw value 1024)
* Measure the voltage of a 3.7V LiPo battery. You will need to plug in an additional resitor between the input voltage and the A0 pin. What shall be the value of this resistor? Experiment and pick an appropriate value that lets you measure voltages up to 5V (a fully charged LiPo battery may reach a voltage of 4.2V). Then figure out what would be the right calibration coefficient so you can measure correct values. 
* Optional: [Upload measurements to thingspeak](https://arduinodiy.wordpress.com/2016/12/25/monitoring-lipo-battery-voltage-with-wemos-d1-minibattery-shield-and-thingspeak/)

## OTA update
* [Local HTTP server + browser update](https://github.com/esp8266/Arduino/tree/2.3.0/doc/ota_updates#web-browser) - use `Sketch > Export Compiled Binary` menu item to obtain the `bin` file. More details in [this tutorial](https://randomnerdtutorials.com/bin-binary-files-sketch-arduino-ide/).

* [Remote HTTP server update](https://github.com/esp8266/Arduino/tree/2.3.0/doc/ota_updates#http-server) - use a local XAMPP server and get the PHP example running and adapted to your use case.


## Onboarding
* Implement onboarding with [WiFiManager](https://github.com/tzapu/WiFiManager)
    * Get basic example running
    * Password protect your WifiManager
    * Add a callback for connection failure


## Detect unexpected restarts (e.g. WDT)
* Use the ESP8266 SDK to read the [reason for reset](https://www.espressif.com/sites/default/files/documentation/esp8266_reset_causes_and_common_fatal_exception_causes_en.pdf).
* Look around for other interesting information [in the API](https://github.com/esp8266/Arduino/blob/61cd8d83859524db0066a647de3de3f6a0039bb2/libraries/esp8266/examples/TestEspApi/TestEspApi.ino)

## Optional: Device management
* Research the [Thinx cloud](https://thinx.cloud) capabilities for the above use cases


# References
* [Resistor color codes](https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-resistor-color-code-5-band)
* [Arduino timekeeping](http://www.instructables.com/id/TESTED-Timekeeping-on-ESP8266-Arduino-Uno-WITHOUT-/)
* [Hotspot manager for Android](https://play.google.com/store/apps/details?id=com.etustudio.android.hotspotmanager&hl=en)
* [Multicast DNS](https://en.wikipedia.org/wiki/Multicast_DNS)
* [DNS-SD](http://www.dns-sd.org/)
