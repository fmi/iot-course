#include <SoftwareSerial.h>

const int RX = D2, TX = D3;   // RX and TX pins of HC-12 module
SoftwareSerial HC12(TX, RX);

void setup() {
  HC12.begin(9600);
  Serial.begin(9600);
}

void loop() {
  char s;
  if (HC12.available();) {
    s = HC12.read();
    while (HC12.available()) {
      HC12.read();
    }
    Serial.println(s);  // logs the received data on the serial output
    //TODO: make some actions, for example blink the LED based on received data
    if ( s == '1') {
    } else if ( s == '0') {
    }
  }
  delay(20);
}