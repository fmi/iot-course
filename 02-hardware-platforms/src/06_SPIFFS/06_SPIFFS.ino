#include "SPIFFS.h"
 
void setup() {
 
  Serial.begin(115200);
 
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS Error");
    return;
  }

  File testFile = SPIFFS.open("/test.txt", FILE_WRITE);
 
  if (!testFile) {
    Serial.println("Can't open file");
    return;
  }

  Serial.println("Writing to file ...");
  if (!testFile.print("TEST")) {
    Serial.println("Write failure");
    return;
  }
  testFile.close();


  Serial.println("List files: ");
  File root = SPIFFS.open("/");
  File file = root.openNextFile();
  
  while(file){
      Serial.println(file.name());
      file = root.openNextFile();
  }
}
 
void loop() {}
