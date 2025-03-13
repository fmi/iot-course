// https://docs.arduino.cc/built-in-examples/digital/toneMelody/
// https://www.hibit.dev/posts/62/playing-popular-songs-with-arduino-and-a-buzzer

#include "pitches.h"
#define BUZZER 13 // GPIO pin connected to the buzzer

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4 // 4 = q uarter note, 8 = eighth note
};


void setup() {

}

void loop() {

  for (int idx = 0; idx < 8; idx++) {

    int noteDuration = 1000 / noteDurations[idx];

    tone(BUZZER, melody[idx], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    noTone(BUZZER);
  }
  delay(2000);
}