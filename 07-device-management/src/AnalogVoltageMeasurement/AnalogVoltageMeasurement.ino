unsigned int raw=0;
float volt=0.0;
const int sleepTimeS = 60;

const int resistor = 100;
const float scalingFactor = 5.14; // TODO how was this calculated?


void setup() {

  Serial.begin(115200);
  Serial.println("Serial is up");
}

void loop() {

  pinMode(A0, INPUT);
  raw = analogRead(A0);
  
  volt=raw/1023.0;
  volt=volt*scalingFactor;

  Serial.println("Voltage: " + String(volt) + " raw:" + String(raw));
  delay(1000);

}
