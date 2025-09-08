#include <Arduino.h>
#include <Stepper.h> // for stepper motor

enum State { ARMED, TRACKING}; // declare simple user-defined datatype State
State currentState {};

// U.S sensor
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
float duration;
float currentDistance, prevDistance;
float threshold = 3;

// Stepper motor
const int STEPS_PER_REVOLUTION = 2048;
Stepper myStepper (STEPS_PER_REVOLUTION, 2,4,3,5); 



void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myStepper.setSpeed(15); // in rpm
  Serial.begin(9600);

  Serial.println("System Starting");
}

void scan(){
  const int RANGE = 1024;
  // (1024 steps)x = (180 degrees), solve for x
  // equal to 0.1757.. degrees
  for (int i = 0; i < RANGE;  ){
    
  }
}

void loop() {

  myStepper.step(1024);
  delay(10000);
}

