#include <Arduino.h>
#include <Stepper.h>
#include <LiquidCrystal.h> // needed for controlling the LCD

enum State { ARMED, TRACKING}; // declare simple user-defined datatype State
State currentState {};

const int buttonPin = 3;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("System Starting");
  pinMode(buttonPin, INPUT); // line isn't needed, but written anyways to show that the purpose of a button is to
  // provide a signal to the microcontroller, so it needs to be configured to read that signal (INPUT).
}

void loop() {
  buttonState = digitalRead(buttonPin); // read value of button connected to pin 2 (buttonPin)
  if (buttonState == LOW){
    currentState = ARMED;
  }
  else { 
    currentState = TRACKING;
  }

  switch(currentState) {
    case ARMED:
      Serial.println("in ARMED State");
      break;
    case TRACKING:
      Serial.println("in TRACKING State");
      break;
  }
  delay(2000);
}