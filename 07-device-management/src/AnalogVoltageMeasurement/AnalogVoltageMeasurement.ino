unsigned int raw=0;
float volt=0.0;
const int sleepTimeS = 60;

void setup() {

  Serial.begin(115200);
  Serial.println("Serial is up");
}

void loop() {

  pinMode(A0, INPUT);
  raw = analogRead(A0);
  volt=raw/1023.0;
  volt=volt*4.2;

  Serial.println("Voltage: " + String(volt) + " raw:" + String(raw));
  delay(1000);

}
