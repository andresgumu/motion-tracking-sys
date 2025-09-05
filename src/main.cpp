#include <Arduino.h>
#include <Stepper.h>
#include <LiquidCrystal.h> // needed for controlling the LCD

enum State { ARMED, TRACKING}; // declare simple user-defined datatype State
State currentState {};

const int pirPin = 8;
int pirState = LOW;


void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  Serial.println("calibrating sensor (60 sec)...");
  delay(60000);
  Serial.println("System Starting");
}

unsigned long lastPrintTime = 0;
const unsigned long printInterval = 1000; // 1 second

void loop() {

  int motion = digitalRead(pirPin);

  if (motion == HIGH){
    if (pirState == LOW){
      Serial.println("Motion Detected");
      pirState = HIGH;
      currentState = TRACKING;
    }
  } 
  else {
    if (pirState == HIGH) {
      Serial.println("Motion ended");
      pirState = LOW;
      currentState = ARMED;
    }
  }

  unsigned long now = millis(); // returns # milliseconds since start of program

  if (now - lastPrintTime >= printInterval){
    switch(currentState) {
      case ARMED:
        Serial.println("in ARMED State");
        break;
      case TRACKING:
        Serial.println("in TRACKING State");
        break;
    }
    lastPrintTime = now;
}

  delay(10);
}