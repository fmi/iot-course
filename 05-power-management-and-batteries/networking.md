### Connecting to WiFi
Wifi/Wifi/WifiScan, Wifi/WifiClient, Wifi/WifiMulti

Wifi/WifiSmartConfig - allows automatic configuration of the Wifi network and requires the ESP Touch aplication for either Android or Iphone

### Sending HTTP
While in Wifi/Wificlient we saw that we can have a Socket-like connection, usually this is not very convenient. 
HttpClient/HttpClientBasic - this example shows how to use the HTTP Client library on ESP which abstracts from the underlying details

### Connect to Local WiFi and send Http Request
<Arduino IDE> -> File -> Examples -> HttpClient -> BasicHttpsClient
  
  Note: Recently most of the free test online Web Servers only accept HTTPS requests. This is why it is important to get the Https example. To run it against the server, the verification of the server-side certificate has to be disabled (unless this is needed for the scenario). This can be done by replacing the line
``` 
  client -> setCACert(rootCACertificate); 
```  
  in the top with
```
   client -> setInsecure();
```  
https://requestbin.com/ - simple online Web Server, to check outgoing requests

### Data to Thingspeak
Create account here - http://thingspeak.com, also account to Mathlabs is necessary to be created
Create channel as described here 
https://www.mathworks.com/help/thingspeak/collect-data-in-a-new-channel.html

Use the example from the first excercise for sending HTTPS request

Use Write api key - here in <key>
http://api.thingspeak.com/update?key=[key]&field1=[value]

```
        String url = "https://api.thingspeak.com/update?api_key=DGJI41Z9325VC02E&field1=";
      url = url + x++;
```
  
### WebServer
Going further it is worth exploring how to run a WebServer on ESP
WebServer/HelloServer - the other examples there are also interesting
