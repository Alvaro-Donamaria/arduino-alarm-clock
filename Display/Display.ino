/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 2
 * LCD Enable pin to digital pin 3
 * LCD D4 pin to digital pin 6
 * LCD D5 pin to digital pin 7
 * LCD D6 pin to digital pin 8
 * LCD D7 pin to digital pin 9
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define util pins
int BUZZER= 13;
int L_Button = 4;
int T_Button = 5;
int R_Button = 10;
int B_Button = 11;
int C_Button = 12;

// Define vars to use
unsigned int hour = 10;
unsigned int minutes = 35;
unsigned int seconds = 0;
unsigned int start_time;




void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Define button pins as input and activate the internal pull-up resistor
  pinMode(L_Button, INPUT_PULLUP);
  pinMode(T_Button, INPUT_PULLUP);
  pinMode(R_Button, INPUT_PULLUP);
  pinMode(B_Button, INPUT_PULLUP);
  pinMode(C_Button, INPUT_PULLUP);
  // Define pin #13 as output, for the BUZZER
  pinMode(BUZZER, OUTPUT);

  //Start to count time
  start_time = millis();
}

void loop() {
  // Read the value of the input. It can either be 1 or 0
  int buttonValue = digitalRead(C_Button);
  if (buttonValue == LOW){
  // If button pushed, turn BUZZER on
    ring(true);
  } else {
  // Otherwise, turn the BUZZER off
    ring(false);
  }
  //setMainview(hour,minutes,seconds);
  //lcd.print(start_time);
  delay(100);
}

void ring(bool on){
  if (on == true){
    digitalWrite(BUZZER,HIGH);
  } else {
    digitalWrite(BUZZER,LOW);
  }
}

void setMainview(int nh, int nm, int ns){
  //Print hour
  lcd.setCursor(4,0);
  lcd.print(nh);
  lcd.setCursor(6,0);
  lcd.print(":");
  //Print minute
  lcd.setCursor(7,0);
  lcd.print(nm);
  lcd.setCursor(9,0);
  lcd.print(":");
  //Print seconds
  lcd.setCursor(10,0);
  lcd.print(ns);

  //
}

