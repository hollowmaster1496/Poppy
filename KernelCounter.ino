

//www.elegoo.com
//2016.12.9

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
#include <elapsedMillis.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Declare the FC-04 (sound sensor) ports
int led_fc04=13;         //define LED port
int buttonPin=3;    //define switch port (D3)

int  val;           //define digital variable val
int  pop_state;     //define "pop" state
int  prev_pop_state;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 0.003;

int count=0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Print a message to the LCD.
  lcd.print("Popcorn Count: ");

  // Define output and input ports
  pinMode(led_fc04,OUTPUT);
  pinMode(buttonPin,INPUT);

  // initialize
  val=digitalRead(buttonPin);
  prev_pop_state=val;
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);

  int reading = digitalRead(buttonPin);

  /* Debouncing logic */
  // Reset timer if buttonPin toggled
  if(reading != prev_pop_state)
  {
     lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Reading has existed for sufficiently long time

    // if state has changed
    if(reading != pop_state) {
      pop_state = reading;

      if (pop_state == HIGH) {
        // blink LED when "Pop" is detected
        digitalWrite(led_fc04, HIGH);
        pop_state=val;
        count++;
      }
      else
      {
        digitalWrite(led_fc04,LOW);
      }
    }

  }

    
  prev_pop_state=reading;
  lcd.print(count);

}

