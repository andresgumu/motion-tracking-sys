#include <Arduino.h>
#include <Stepper.h> // for stepper motor

enum State { ARMED, TRACKING}; // declare simple user-defined datatype State
State currentState {};

// ultrasonic sensor
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
float duration;
float currentDistance, prevDistance;
float threshold = 3;

// stepper motor
const int STEPS_PER_REVOLUTION = 2048;
Stepper myStepper (STEPS_PER_REVOLUTION, 2,4,3,5); 

// tracking variables

const int SCAN_RANGE = 180; // in degrees
const int SCAN_STEP_SIZE = 5;
const int STEPS_PER_DEGREE = STEPS_PER_REVOLUTION / 360;

int object_at_Angle = -1; // "-1" indicates that no object was found
int currentPosition = 0;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myStepper.setSpeed(15); // in rpm
  Serial.begin(9600);

  Serial.println("System Starting");
  currentState = ARMED;
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2); // ensure a clean start 
  digitalWrite(TRIG_PIN, HIGH); //trigger pulse
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH); // measures time in microseconds that the ECHO_PIN remains HIGH
  float distance = duration * 0.034 / 2; // speed of sound = 0.034 cm per microsecond, divide by two to get one-way dist.
  return distance;
}

void scan(){
  int minDistance = 500; // arbitrary high value (cm) to begin
  int currentAngle = 0;
  object_at_Angle = -1; // reset angle for every new scan (new function call)

  Serial.println("Scanning for motion");

  // for loop to sweep from -90 to 90 degrees in 5 degree increments
  for (int angle  = -SCAN_RANGE / 2; angle <= SCAN_RANGE / 2; angle += SCAN_STEP_SIZE){ 

    // converts desired angle into an exact number of steps from the motor's reference point
    int targetPosition = (STEPS_PER_REVOLUTION / 2) + (angle * STEPS_PER_DEGREE); // relative to motors full range

    // tells the motor how many steps to take to get to the correct absolute position
    int stepsToMove = targetPosition - currentPosition;

    // move the stepper the calculated number of steps
    myStepper.step(stepsToMove);

    // update position (using the currentPosition variable as a tracker)
    currentPosition += stepsToMove;

    // allow for movement to settle before sensor writes down the reading
    delay(50);

    // get measurement from getDistance() func.
    currentDistance = getDistance();

    // check if new, closer object has been found: 
      // currentDistance > 2 ---> to ignore very close readings
      // currentDistance < 300 ---> to ignore very far readings
      // currentDistance < minDistance ---> to check if the current reading is closer than the minimum distance recorded thus far
    if ((currentDistance > 2) && (currentDistance < 300) && (currentDistance < minDistance)){
      // update to closer distance
      minDistance = currentDistance;
      object_at_Angle = angle;
    }
  }

  // condition checked only after loop finishes the 180 degree scan
  // if objectAngle is still -1, no object was found
  if (object_at_Angle != -1){ 
    currentState = TRACKING;
    Serial.print("Object detected at angle: ");
    Serial.print(object_at_Angle);
    Serial.print(" degrees, with distance: ");
    Serial.print(minDistance);
    Serial.println(" cm. Entering TRACKING state..");
  }
  else {
  Serial.println("Scan complete, no object detected");
  }
}

void track(){

  // move to last known object angle
    // (STEPS_PER_REVOLUTION / 2) is the 0 degree reference point
    // (object_at_Angle * STEPS_PER_DEGREE) to convert from degrees to number of steps
    // -currentPosition to get the RELATIVE number of steps it needs to move

  int stepsToMove = (STEPS_PER_REVOLUTION / 2) + (object_at_Angle * STEPS_PER_DEGREE) - currentPosition;

  // move stepper
  myStepper.step(stepsToMove);

  // again, need to update it
  currentPosition += stepsToMove;

  Serial.println("Tracking object...");
  delay(100);

  currentDistance = getDistance();

  // checks if new distance reading is outside of a valid range
  if (currentDistance > 400 || currentDistance < 2){
    Serial.println("Lost target. Returning to ARMED state.");
    currentState = ARMED;
  }
}


void loop() {

  switch (currentState){
    case ARMED:
      scan();
      break;

    case TRACKING:
      track();
      break;
  }
}

