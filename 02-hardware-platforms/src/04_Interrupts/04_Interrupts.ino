#define FLASH_BUTTON 14

volatile int unprocessed_interrupts;

void setup() {
  
  pinMode(FLASH_BUTTON,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FLASH_BUTTON), handleInterrupt, FALLING);
  
  Serial.begin(115200L);
}

 ICACHE_RAM_ATTR void handleInterrupt() {
  unprocessed_interrupts++;
}

void loop() {

  Serial.println("Processing interrupts: " + String(unprocessed_interrupts));
  unprocessed_interrupts = 0;
  
  delay(3000);
}
