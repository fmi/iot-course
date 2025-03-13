// https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/ledc.html
// https://lastminuteengineers.com/esp32-pwm-tutorial/

#define BUZZER 13 // GPIO pin connected to the buzzer
#define FREQUENCY 3000
#define RESOLUTION 8

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Setting up PWM...");
  
  bool success = ledcAttach(BUZZER, FREQUENCY, RESOLUTION);
  if(success){
    Serial.println("Done");
  }else{
    Serial.println("Error");
  }
  delay(100);
  uint32_t freq = ledcReadFreq(BUZZER);
  Serial.println("Frequency set to " + String(freq));
}

void setDuty(uint32_t duty){
  bool success = ledcWrite(BUZZER, duty);
  if(success){
    delay(50);
    uint32_t d = ledcRead(BUZZER);
    Serial.println("duty=" + String(duty) + "->" + String(d));
  }else{
    Serial.println("Error in ledcWrite with duty=" + String(duty));
  }
}

void loop() {

  setDuty(0); // turn off LOW level
  delay(500);

  setDuty(1);
  delay(1000);

  setDuty(32);
  delay(1000);

  setDuty(64);
  delay(1000);


  setDuty(127);
  delay(2000);


  setDuty(255); // turn off HIGH level
  delay(1000);
}
