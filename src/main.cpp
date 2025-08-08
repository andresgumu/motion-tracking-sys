#include <Arduino.h>

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Potentiometer Test Starting...");
}

void loop() {
  int potValue = analogRead(A0);
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  delay(200);
}

// put function definitions here:
