#include <SoftwareSerial.h>

const int RX = D2, TX = D3;   // RX and TX pins of HC-12 module
SoftwareSerial HC12(TX, RX);

void setup() {
  HC12.begin(9600);
  Serial.begin(9600);
}

void loop() {
  bool sendOne = ((millis() % 5) == 0);  // TODO-> use button, not millis()
  Serial.print("Sending: ");
  Serial.println(sendOne);
  if (sendOne) {
    HC12.write('1');
  } else {
    HC12.write('0');
  }
  delay(881);
}