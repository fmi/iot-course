#include "esp_system.h"

const int TIMEOUT_MS = 2000;
const int TIMER_ID = 0;
const int TIMER_DIVIDER = 80;
const int TIMER_EDGE = true;
const bool COUNT_UP = true;
const int RESET = 0;

hw_timer_t *timer = NULL;


void IRAM_ATTR timerTriggered() {
  esp_restart();
}


void setup() {
  
  Serial.begin(115200);
  
  timer = timerBegin(TIMER_ID, TIMER_DIVIDER, COUNT_UP);
  timerAttachInterrupt(timer, &timerTriggered, TIMER_EDGE);
  
  timerAlarmWrite(timer, TIMEOUT_MS * 1000, false);
  timerAlarmEnable(timer);
}

void loop() {
  
  Serial.println("In main loop");
  delay(TIMEOUT_MS *  2);
  timerWrite(timer, RESET);
}
