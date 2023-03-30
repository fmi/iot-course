#ifdef ESP8266
extern "C" {
#include "user_interface.h"
}
#endif

void setup() {
  delay(100);
  Serial.begin(115200);
  delay(1000);
#ifdef ESP8266
  Serial.println("Getting reset reason");
  struct rst_info *rtc_info = system_get_rst_info(); // defined in https://github.com/esp8266/Arduino/blob/master/tools/sdk/include/user_interface.h
  Serial.println("Reset reason: " + String(rtc_info->reason) + " exccause: " + String(rtc_info->exccause));
#endif
}

void loop() {
  Serial.println("Inside loop");
  delay(1000);
  while(true){};
}
