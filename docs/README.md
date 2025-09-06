# Automated Motion Tracking System

## Overview

Develop a mini motion-tracking security system using a stepper motor and ultrasonic sensor to automatically point toward detected motion with precise positioning control. The project demonstrates expertise in sensor fusion, closed-loop control systems, C++ programming, and real-time event handling, tailored for hardware engineering applications. Success is defined by achieving <500ms response time from detection to pointing, reliable multi-target tracking, and stable 24/7 operation capability.

## Hardware Components

- **Stepper Motor + ULN2003 Driver**: Controlled pointing mechanism, powered by 9V external supply for smooth rotation and precise angular positioning.
- **PIR Motion Sensor (NOT USED)**: Motion detection mounted to detect motion in a 120° field of view. Inferior to HC-SR04 since its hold time skews additional movement after detection.
- **Ultrasonic Sensor (HC-SR04)**: 
- **Rotary Encoder Module**: Position feedback for accurate pointing direction, connected to Arduino interrupt pins (2, 3) with pull-up resistors.
- **LCD1602 (for future integration)** : Real-time display of system status, detection count, current pointing angle, and last detection time.
- **RGB LED**: Visual status indicators (green=armed, yellow=detecting, red=pointing, blue=scanning).
- **Active Buzzer**: Audio alerts for motion detections with configurable alarm patterns.
- **Button**: Manual control for system modes (Armed/Disarmed/Demo/Reset).
- **Arduino Uno**: Central controller for sensor fusion and motor control implementation in C++.

## Features

- Motion Detection & Pointing: tbd
- Multi-Zone Tracking: tbd
- Real-Time Feedback: tbd
- Precision Control: tbd
- Smart Operation: tbd

## Setup

### Building a Simple State Machine

#### The Shell (and testing switch logic)
- **manually switching between armed and tracking states**: created a simple user defined datatype "State" to either be ARMED or TRACKING. this code is the shell of the State Machine that will be built upon with additional components.
 * button doesn't actually STORE HIGH or LOW, instead when continually pressed down, the value that will be read will be HIGH (TRACKING) and when released, will be LOW (ARMED)

```c++
#include <Arduino.h>

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
```
#### Testing U.S sensor
- **detailed implementation**: final threshold for the distance between object and sensor tbd as I need to test and debug with different room layouts. I also need to test various delays after the switch statement to prevent serial output overflow.

```c++
#include <Arduino.h>

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
```



## Performance Targets

- **Response Time**: <500ms from motion detection to pointing completion (target: <350ms average).
- **Pointing Accuracy**: ~3° positioning repeatability when returning to detection zones.
- **Detection Coverage**: 8 distinct zones covering 120° field of view with 45° resolution.
- **System Uptime**: 48+ hour continuous operation without manual intervention.
- **False Positive Rate**: <5% false detections through optimized debouncing algorithms.
- **Multi-Target Handling**: Successfully track and cycle between up to 4 recent detection points.
- **Power Efficiency**: <200mA average current draw during armed standby mode.
- **Event Logging**: Real-time timestamp accuracy within ±1 second using RTC module.

## Usage

*tbd*

## Results

*Document actual performance metrics and test results here.*
