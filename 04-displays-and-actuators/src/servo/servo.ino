/*
The provided code is an Arduino sketch that demonstrates how to control a servo motor using the ESP32Servo library. The sketch begins by defining a constant `servoPin` with a value of 13, which represents the GPIO pin on the ESP32 to which the servo motor is connected. An instance of the Servo class, named `servo1`, is then created to control the servo motor.

In the `setup` function, the serial communication is initialized with a baud rate of 115200 using `Serial.begin(115200)`. This allows for communication between the ESP32 and a connected computer, which can be useful for debugging or monitoring the servo motor's behavior. The servo motor is then attached to the specified pin (servoPin) using the `attach` method of the Servo class.

The `loop` function contains the main logic for controlling the servo motor. It consists of two for-loops that move the servo motor back and forth between 0 and 180 degrees. The first for-loop increments the servo position from 0 to 180 degrees in steps of 1 degree. For each position, the `write` method of the Servo class is called to set the servo to the specified angle, and the current position is printed to the serial monitor using `Serial.println(posDegrees)`. A delay of 20 milliseconds is added between each step to control the speed of the servo movement.

The second for-loop decrements the servo position from 180 to 0 degrees, following the same process as the first loop. This back-and-forth movement of the servo motor continues indefinitely, causing the servo to sweep smoothly between the two positions.
*/

#include <ESP32Servo.h>

static const int servoPin = 13;

Servo servo1;

void setup() {

  Serial.begin(115200);
  servo1.attach(servoPin);
}

void loop() {
  for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }

  for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }
}