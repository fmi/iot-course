char line[200];

int readLine(int timeout) {
  unsigned long deadline = millis() + timeout;
  int i = 0;
  while (millis() < deadline) {
    if (Serial.available()) {
      line[i++] = (char) Serial.read();
      if      (line[i-1] == '\r')  i--;
      else if (i == sizeof(line) - 1)  break;
      else if (line[i-1] == '\n')  {i--; break;}
    }
  }
  line[i] = 0;
  return i;
}

void setup() {
  Serial.begin(115200L);
  Serial.println("Serial test started");
}

void loop() {
  if (readLine(1000) > 0) {
    Serial.print("Received: " );
    Serial.println(line);
    String s = line;
    if (s == "restart") ESP.restart();
    else if (s == "millis") Serial.println(millis());
  }
}
