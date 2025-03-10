#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>


LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
  

void setup() {
  int error;

  Serial.begin(115200);
  while (!Serial);

  Serial.println("Probing for PCF8574 on address 0x27...");

  Wire.begin(21, 22); // SDA, SCL
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();

  if (error == 0) {
    Serial.println("LCD found.");
    lcd.begin(16, 2);  // initialize the lcd
    lcd.setBacklight(1); // turn on backlight. 0 turns it off
    lcd.display(); // turn on the LCD, turn off with lcd.noDisplay();
    lcd.clear(); // clear the display
    lcd.home(); // set cursor to 0,0
    // lcd.cursor(); // shows the current cursor position with _
    lcd.noCursor(); // turn cursor off
    // lcd.blink(); // show a blinking cursor
    lcd.noBlink(); // turn off blinking cursor

  } else {
    Serial.println(": LCD not found.");
    Serial.print("Error: ");
    Serial.print(error);
    while(1){}
  }
}


void loop() {
    lcd.clear();
    lcd.print("Message:");

    lcd.setCursor(0, 1);
    lcd.print("Hi");
    delay(2000);

    lcd.print(" there");
    delay(2000);

    for(int i = 0; i< 10; i++){
      lcd.scrollDisplayLeft();
      delay(300);
    }

    lcd.blink();
    lcd.setCursor(8, 1);
    lcd.print(" student");

    delay(2000);

    for(int i = 0; i< 9; i++){
      lcd.scrollDisplayRight();
      delay(300);
    }
    lcd.noBlink();

}
