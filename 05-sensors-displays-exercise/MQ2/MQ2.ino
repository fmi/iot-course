#define SENSOR 25

void setup() { 
  Serial.begin(115200);
  while (!Serial);

  pinMode(SENSOR, INPUT);
  Serial.println("MQ2 sensor");
}
 
 
void loop(){

  Serial.print("Analog output: ");
  Serial.println(analogRead(SENSOR)); 
  delay(100); 
}
