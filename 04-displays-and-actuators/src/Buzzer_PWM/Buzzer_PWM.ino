#define BUZZER 13 // GPIO pin connected to the buzzer

void setup() {
    pinMode(BUZZER, OUTPUT);
}

void loop() {
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    analogWrite(BUZZER, dutyCycle);
    delay(15);
  }
}
