#include "esp_system.h"

const int TIMEOUT_MS = 2000;

esp_timer_handle_t timer;

void IRAM_ATTR timerTriggered(void* arg) {
  esp_restart();
}

void setup() {
  Serial.begin(115200);

  // Create a timer
  const esp_timer_create_args_t timer_args = {
    .callback = &timerTriggered,
    .arg = NULL,
    .name = "watchdog_timer"
  };
  esp_timer_create(&timer_args, &timer);

  // Start the timer
  esp_timer_start_once(timer, TIMEOUT_MS * 1000);
}

void loop() {
  Serial.println("In main loop");
  delay(TIMEOUT_MS * 2);
  esp_timer_stop(timer);
  esp_timer_start_once(timer, TIMEOUT_MS * 1000);
}
