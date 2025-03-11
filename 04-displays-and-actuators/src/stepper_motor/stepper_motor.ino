/*
The provided code is an Arduino sketch that demonstrates how to control a stepper motor using the Stepper library. The sketch begins by including the Stepper library with `#include <Stepper.h>`, which provides the necessary functions to control the stepper motor.

A constant `stepsPerRevolution` is defined with a value of 1024, representing the number of steps the motor needs to complete one full revolution. This value can be adjusted to match the specifications of the stepper motor being used.

The ULN2003 motor driver pins are defined using `#define` directives. These pins (IN1, IN2, IN3, and IN4) are connected to the Arduino and control the stepper motor. The specific pin numbers (19, 18, 5, and 17) correspond to the digital pins on the Arduino board.

An instance of the Stepper class, named `myStepper`, is created and initialized with the number of steps per revolution and the pin numbers. This instance will be used to control the stepper motor.

In the `setup` function, the speed of the stepper motor is set to 5 revolutions per minute (rpm) using the `setSpeed` method. Additionally, the serial port is initialized with a baud rate of 115200 using `Serial.begin(115200)`. This allows for communication between the Arduino and a connected computer, which can be useful for debugging or monitoring the motor's behavior.

The `loop` function contains the main logic for controlling the stepper motor. It first prints "Going clockwise" to the serial monitor and then commands the motor to step one full revolution in the clockwise direction using `myStepper.step(stepsPerRevolution)`. After a delay of 1000 milliseconds (1 second), it prints "Going counterclockwise" to the serial monitor and commands the motor to step one full revolution in the counterclockwise direction using `myStepper.step(-stepsPerRevolution)`. This loop repeats indefinitely, causing the motor to alternate between clockwise and counterclockwise rotations.
*/
#include <Stepper.h>

const int stepsPerRevolution = 1024;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  // set the speed at 5 rpm
  myStepper.setSpeed(5);
  // initialize the serial port
  Serial.begin(115200);
}

void loop() {
  // step one revolution in one direction:
  Serial.println("Going clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // step one revolution in the other direction:
  Serial.println("Going counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}