/***************************************************
  WS2812 NeoPixel Ring - Chasing LED Effect

  This example controls a 16-LED NeoPixel (WS2812)
  ring to create a back-and-forth chasing light.
  After every 5 cycles the entire ring flashes blue.

  WS2812 LEDs are "addressable" — each LED has a
  tiny chip inside that receives colour data over a
  single data wire. The FastLED library handles the
  precise timing required by the WS2812 protocol.

  Wiring (ESP32):
    WS2812 DIN -> GPIO 18
    WS2812 5V  -> 5V
    WS2812 GND -> GND

  Required library: FastLED
    Install via: Sketch -> Include Library -> Manage Libraries
    Search for "FastLED" by Daniel Garcia
 ***************************************************/

// Include the FastLED library for controlling addressable LEDs
#include <FastLED.h>

// Number of LEDs on the ring
#define NUM_LEDS 16

// GPIO pin connected to the DIN (data in) of the ring
#define DATA_PIN 18

// Array that holds the colour value for each LED
CRGB leds[NUM_LEDS];

// Counts how many back-and-forth cycles have completed
int roundCounter = 0;

void setup() {
  // Register the LED strip: chip type NEOPIXEL, data on DATA_PIN
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  // --- Forward chase: light each LED one at a time, 0 -> 15 ---
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::LightCoral;   // Turn this LED on (coral colour)
    FastLED.show();                // Push colours to the ring
    delay(200);                    // Wait so the eye can see it
    leds[i] = CRGB::Black;        // Turn it off before moving on
  }

  // --- Reverse chase: light each LED one at a time, 15 -> 0 ---
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = CRGB::LightCoral;
    FastLED.show();
    delay(200);
    leds[i] = CRGB::Black;
  }

  // One full back-and-forth cycle done
  roundCounter++;

  // Every 5 cycles, flash the whole ring blue for 1 second
  if (roundCounter >= 5) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Blue;
    }
    FastLED.show();
    delay(1000);
    roundCounter = 0;
  }
}
