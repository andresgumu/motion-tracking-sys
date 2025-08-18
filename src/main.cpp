#include <Arduino.h>
#include <LiquidCrystal.h> // needed for controlling the LCD

// Creates variable of type LiquidCrystal (using 4 data lines; omit d0-d3)
/*
SYNTAX: 
LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal(rs, rw, enable, d4, d5, d6, d7)
LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7)
LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)
*/
// Initialize library with interface pins and the corr. # (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("LCD Test Starting...");
  
  // begin() function used to set up LCD's dimensions 
  // syntax: lcd.begin(cols, rows, charsize(optional) )
  lcd.begin(16, 2);
  
  // print() function used to print text
  lcd.print("LCD Test!"); // print "LCD Test!" to screen

  // setCursor() function used to set the location at 
  // ..which subsequent text written to the LCD will be displayed.
  lcd.setCursor(0, 1);  
  lcd.print("Hello World!");
  
  // for debugging purposes
  Serial.println("LCD should now display text");
  Serial.println("If blank, adjust contrast potentiometer");
}

void loop() {
  // Display a dynamic counter on the top row
  lcd.setCursor(10, 0);  
  lcd.print("    ");     // Clear previous number
  lcd.setCursor(10, 0);
  // millis() function returns number of milliseconds since arduino started
  lcd.print(millis()/1000);  // Show seconds elapsed
  
  // Display status on second row
  lcd.setCursor(12, 1);  // Position: column 12, row 1
  if ((millis()/1000) % 2 == 0) {
    lcd.print("ON ");
  } else {
    lcd.print("OFF");
  }
  
  delay(500); // allow time for transitions
}