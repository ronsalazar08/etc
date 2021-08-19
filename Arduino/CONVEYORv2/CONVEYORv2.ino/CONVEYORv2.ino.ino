/*
  State change detection (edge detection)

 Often, you don't need to know the state of a digital input all the time,
 but you just need to know when the input changes from one state to another.
 For example, you want to know when a button goes from OFF to ON.  This is called
 state change detection, or edge detection.

 This example shows how to detect when a button or button changes from off to on
 and on to off.

 The circuit:
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 * LED attached from pin 13 to ground (or use the built-in LED on
   most Arduino boards)

 created  27 Sep 2005
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/ButtonStateChange

 */

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int  buttonPin2 = 4;
const int  buttonPin3 = 6;
// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int lastButtonState = 0;     // previous state of the button
int lastButtonState2 = 0;     
int lastButtonState3 = 0;     
void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
   buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.print("WORD");
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.print("WORDOFF");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of
  // the division of two numbers:

 if (buttonState2 != lastButtonState2) {
    
    if (buttonState2 == HIGH) {
      buttonPushCounter++;
      Serial.print("EXCEL");
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.print("EXCELOFF");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState2 = buttonState2;



 if (buttonState3 != lastButtonState3) {
    
    if (buttonState3 == HIGH) {
      buttonPushCounter++;
      Serial.print("POWER");
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.print("POWEROFF");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState3 = buttonState3;


}









