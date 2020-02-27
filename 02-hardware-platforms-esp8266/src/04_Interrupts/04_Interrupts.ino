#define LED_BUILTIN 2  // ESP32
#define FLASH_BUTTON 0

volatile int unprocessed_interrupts;

void setup() {
  
  pinMode(FLASH_BUTTON,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FLASH_BUTTON), handleInterrupt, FALLING);
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200L);
}

void handleInterrupt() {
  unprocessed_interrupts++;
}

void loop() {

  Serial.println("Processing interrupts: " + String(unprocessed_interrupts));
  unprocessed_interrupts = 0;
  
  delay(3000);
}
