#include <Arduino.h>

// volatile keyword to tell compiler that the variable can change unexpectedly
// ..and to always read actual value from memory
volatile long encoderCount = 0;
int lastA = 0;

void readEncoder();

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  // (digitalPinToInterrupt(pin), ISR, mode)
  // Interrupt Service Routine (ISR); function that returns nothing/has no parameters
  // CHANGE as mode to trigger the interrupt whenever the pin changes value
  attachInterrupt(digitalPinToInterrupt(2), readEncoder, CHANGE);
}

void readEncoder() { // need to define this before setup()
  int A = digitalRead(2); // set pin 2 reading to A
  int B = digitalRead(3); // set pin 3 reading to B
  
  if (lastA == 0 && A == 1) {
    if (B == 0) encoderCount++;
    else encoderCount--;
  }
  lastA = A;
}

void loop() {
  Serial.print("Position: ");
  Serial.println(encoderCount);
  delay(200);
}