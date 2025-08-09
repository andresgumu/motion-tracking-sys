#include <Arduino.h>
#include <Stepper.h> // use built-in Stepper library for Arduino

#define STEPS_PER_REVOLUTION 2048 // define a constant (2048 steps for full rev.)

Stepper myStepper(STEPS_PER_REVOLUTION, 8, 10, 9, 11); // had to change 9,10 order

void setup() {
  // setSpeed() sets motor speed in RPM
  myStepper.setSpeed(15); // doesn't make motor turn, just sets speed at which it will when step() is called
  Serial.begin(9600);
}

void loop() {
    // rotate motor one full revolution clockwise
  Serial.println("Moving clockwise...");
  // step() turns motor a specific number of steps
  myStepper.step(STEPS_PER_REVOLUTION);
  delay(500);
  
  // rotate motor one full revolution counter-clockwise
  Serial.println("Moving counter-clockwise...");
  myStepper.step(-STEPS_PER_REVOLUTION);
  delay(500);
}


