# Progress Notes

## Initial Setup

Day 0
- **Tasks**: Initialized project with PlatformIO, set up GitHub repository, linked local folder.
- **Challenges**: Resolved branch mismatch (master/main), handled non-fast-forward push.
- **Next Steps**: Look through Arduino Docs, become familiar with components, begin building

Day 1
- **Tasks**: Familiarize yourself with components (potentiometer, stepper motor)
- **Challenges**: Learning proper breadboarding (connections, safety)
- **Next Steps**: Order extra male-female dupont wires to test/connect stepper motor

Day 2
- **Tasks**: Connect and test stepper motor
- **Challenges**: 
  * <u>Figuring out if Arduino 5V PSU could properly power the stepper motor:</u> noticed that the rated voltage on the motor itself says "5V DC"; might want to supply it with more voltage if I think about altering the weight of a specific load 
  * <u>Learning Stepper built-in library functions to make the motor rotate:</u> step() and setSpeed() (their uses are explained in respective README code blocks)
  * <u>Debugging stepper motor not wanting to turn counter-clockwise:</u> Apparently the pin input is 8,10,9,11 not 8,9,10,11
- **Next Steps**: Testing rotary encoder module with interrupt-driven reading.

Day 3
- **Tasks**: test rotary encoder module
- **Challenges**: 
  * <u>understanding pinMode() function and INPUT_PULLUP option:</u> The arduino sets the specified pin as an input and internally connects a 10,000 ohm resistor between the pin and 5V (power). Important because you ensure you get clean and reliable digital signals (in the case of no pull-up resistor: when the switch is not connected, the pin reads a floating voltage and thus causes unreliable readings. In the case of a pull-up resistor present: pin reads HIGH when encoder switch is open, LOW when switch closes to ground)
  * <u>Using interrupts:</u> arduino docs: *"Interrupts help make things happen automatically in microcontroller programs and can help solve timing problems. Good tasks for using an interrupt may include reading a rotary encoder, or monitoring user input. If you wanted to ensure that a program always caught the pulses from a rotary encoder, so that it never misses a pulse, it would make it very tricky to write a program to do anything else, because the program would need to constantly poll the sensor lines for the encoder, to catch pulses when they occurred."* 
  * <u>basic C++ syntax:</u> tried calling a function inside setup() when the function was defined and initialized after setup()
- **Next Steps**: PIR sensor testing and calibration, LCD1602 interface setup and display testing.

Day 4
- **Tasks**: test PIR sensor and LCD interface
- **Challenges**:
  * <u>pin description:</u> Since the three pins on the sensor were not labeled, I had to search the model (HC-SR501) online to find out (left (when looking at sensor with yellow module at bottom left) is GND, middle is HIGH/LOW output, right is power)
  * <u>:</u> 
  * <u>:</u> 
- **Next Steps**: 








*template*

Day _
- **Tasks**: 
- **Challenges**:
  * <u>:</u>  
  * <u>:</u> 
  * <u>:</u> 
- **Next Steps**: 