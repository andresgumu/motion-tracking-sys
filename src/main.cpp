#include <Arduino.h>
#include <Stepper.h>
#include <LiquidCrystal.h> // needed for controlling the LCD

enum State { ARMED, TRACKING}; // declare simple user-defined datatype State
State currentState {};

const int trigPin = 9;
const int echoPin = 10;
float duration;
float currentDistance, prevDistance;
float threshold = 3;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  Serial.println("System Starting");
}


void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  currentDistance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(currentDistance);
  delay(100);

  if (fabs(prevDistance - currentDistance) > threshold){
    currentState = TRACKING;
  }
  else {
    currentState = ARMED;
  }

  switch(currentState) {
    case ARMED:
      Serial.println("in ARMED State");
      break;
    case TRACKING:
      Serial.println("in TRACKING State");
      break;
  }

  prevDistance = currentDistance;
  delay(200);

}