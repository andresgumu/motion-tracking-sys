#include <Arduino.h>

int pirPin = 8;
int pirState = LOW; // LOW state means there is no motion

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  Serial.println("PIR Test Started");
  Serial.println("Warming up sensor (60 seconds)...");
  delay(60000); // PIR needs time to calibrate
  Serial.println("Ready to detect motion!");
}

void loop() {
  int motion = digitalRead(pirPin);
  
  if (motion == HIGH) {
    if (pirState == LOW) {
      Serial.println("MOTION DETECTED!");
      pirState = HIGH; // change state to moving
    }
  } else {
    if (pirState == HIGH) {
      Serial.println("Motion ended");
      pirState = LOW; // change state to static (no movement)
    }
  }
  
  delay(100);
}