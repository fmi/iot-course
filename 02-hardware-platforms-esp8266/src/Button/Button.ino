//#define LED_BUILTIN 16
#define FLASH_BUTTON 0
#define GPIO_05 5   // D1 on NodeMCU 0.9

void setup() {
  
  pinMode(FLASH_BUTTON,INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200L);
}

void loop() {
  
  int value = digitalRead(FLASH_BUTTON);

  Serial.println((value == HIGH)?"HIGH":"LOW");
  digitalWrite(LED_BUILTIN, value);
  
  delay(1000);
}
