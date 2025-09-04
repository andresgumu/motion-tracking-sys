# Automated Motion Tracking System

## Overview

Develop a mini motion-tracking security system using a stepper motor and PIR sensor to automatically point toward detected motion with precise positioning control. The project demonstrates expertise in sensor fusion, closed-loop control systems, C++ programming, and real-time event handling, tailored for hardware engineering applications. Success is defined by achieving <500ms response time from detection to pointing, reliable multi-target tracking, and stable 24/7 operation capability.

## Hardware Components

- **Stepper Motor + ULN2003 Driver**: Controlled pointing mechanism, powered by 9V external supply for smooth rotation and precise angular positioning.
- **PIR Motion Sensor (HC-SR501)**: Motion detection with adjustable sensitivity, mounted to detect motion in a 120° field of view.
- **Rotary Encoder Module**: Position feedback for accurate pointing direction, connected to Arduino interrupt pins (2, 3) with pull-up resistors.
- **LCD1602**: Real-time display of system status, detection count, current pointing angle, and last detection time.
- **RGB LED**: Visual status indicators (green=armed, yellow=detecting, red=pointing, blue=scanning).
- **Active Buzzer**: Audio alerts for motion detections with configurable alarm patterns.
- **Button**: Manual control for system modes (Armed/Disarmed/Demo/Reset).
- **Potentiometer**: Real-time sensitivity adjustment and scanning speed control.
- **Arduino Uno**: Central controller for sensor fusion and motor control implementation in C++.
- **RTC Module**: Timestamp logging for security event tracking and system uptime monitoring.

## Features

- Motion Detection & Pointing: PIR sensor automatically detects movement and stepper motor precisely points toward the motion source with <500ms response time
- Multi-Zone Tracking: Maps 8 detection zones across 120° field of view and can remember/cycle between multiple recent motion events
- Real-Time Feedback: LCD display, RGB status LEDs, audio alerts, and manual controls for system monitoring and interaction
- Precision Control: PID-controlled positioning with rotary encoder feedback achieving ~3° accuracy and reliable target tracking
- Smart Operation: 48+ hour continuous operation with event logging, automatic calibration, false positive filtering, and multiple system modes (Armed/Disarmed/Demo)

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
