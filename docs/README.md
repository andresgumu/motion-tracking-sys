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

*tbd*


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
