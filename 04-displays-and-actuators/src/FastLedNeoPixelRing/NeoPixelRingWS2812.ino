/***

The provided code is an Arduino sketch that controls a ring of NeoPixel LEDs using the FastLED library. The sketch defines the number of LEDs (NUM_LEDS) as 16 and the data pin (DATA_PIN) as 18. An array leds of type CRGB is created to hold the color values for each LED, and an integer roundCounter is initialized to 0 to keep track of the number of completed cycles.

In the setup function, the FastLED.addLeds method is called to initialize the LED array with the specified type (NEOPIXEL) and data pin. This sets up the FastLED library to control the LEDs.

The loop function contains the main logic for controlling the LEDs. It first lights up the LEDs sequentially from the first LED to the last, setting each LED to CRGB::LightCoral and then turning it off after a 200-millisecond delay. This creates a chasing light effect. The same process is then repeated in reverse, lighting up the LEDs from the last to the first.

After completing one forward and one backward cycle, the roundCounter is incremented. If the roundCounter reaches 5, indicating that 5 complete cycles have been performed, all LEDs are set to CRGB::Blue and displayed for 1 second. The roundCounter is then reset to 0, and the process starts over.

This code effectively creates a visual effect where the LEDs chase back and forth, and after every 5 cycles, all LEDs turn blue for a brief period.

***/
#include <FastLED.h>
#define NUM_LEDS 16
#define DATA_PIN 18
CRGB leds[NUM_LEDS];
int roundCounter = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  // Light up LEDs from 0 to NUM_LEDS-1
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::LightCoral;
    FastLED.show();
    delay(200);
    leds[i] = CRGB::Black;
  }

  // Light up LEDs from NUM_LEDS-1 to 0
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = CRGB::LightCoral;
    FastLED.show();
    delay(200);
    leds[i] = CRGB::Black;
  }

  // Increment the round counter
  roundCounter++;

  // After 5 rounds, turn all LEDs blue
  if (roundCounter >= 5) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Blue;
    }
    FastLED.show();
    delay(1000); // Keep the LEDs blue for 1 second
    roundCounter = 0; // Reset the round counter
  }
}
