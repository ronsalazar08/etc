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
const int  buttonPin2 = 3;
const int  buttonPin3 = 4;
const int  buttonPin4 = 5;
const int  buttonPin5 = 6;
const int  buttonPin6 = 7;
const int  buttonPin7 = 8;
const int  buttonPin8 = 9;
const int  buttonPin9 = 10;
const int  buttonPin10= 11;
const int  buttonPin11= 12;
const int  buttonPin12= 13;
const int  buttonPin13= A0;
const int  buttonPin14= A1;
const int  buttonPin15= A2;
const int  buttonPin16= A3;
const int  buttonPin17= A4;
const int  buttonPin18= A5;

// Variables will change:
int buttonPushCounter = 0;   
int buttonPushCounter2 = 0;
int buttonPushCounter3 = 0;
int buttonPushCounter4 = 0;   
int buttonPushCounter5 = 0;
int buttonPushCounter6 = 0;
int buttonPushCounter7 = 0;   
int buttonPushCounter8 = 0;
int buttonPushCounter9 = 0;
int buttonPushCounter10 = 0;   
int buttonPushCounter11 = 0;
int buttonPushCounter12 = 0;
int buttonPushCounter13 = 0;   
int buttonPushCounter14 = 0;
int buttonPushCounter15 = 0;
int buttonPushCounter16 = 0;   
int buttonPushCounter17 = 0;
int buttonPushCounter18 = 0;
int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
int buttonState9 = 0;
int buttonState10 = 0;
int buttonState11 = 0;
int buttonState12 = 0;
int buttonState13 = 0;
int buttonState14 = 0;
int buttonState15 = 0;
int buttonState16 = 0;
int buttonState17 = 0;
int buttonState18 = 0;

int lastButtonState = 1;     
int lastButtonState2 = 1;     
int lastButtonState3 = 1;    
int lastButtonState4 = 1;     
int lastButtonState5 = 1;    
int lastButtonState6 = 1;     
int lastButtonState7 = 1;    
int lastButtonState8 = 1;     
int lastButtonState9 = 1;    
int lastButtonState10 = 1;     
int lastButtonState11 = 1;    
int lastButtonState12 = 1;     
int lastButtonState13 = 1;    
int lastButtonState14 = 1;     
int lastButtonState15 = 1;    
int lastButtonState16 = 1;     
int lastButtonState17 = 1;    
int lastButtonState18 = 1; 
int j;    
void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  pinMode(buttonPin8, INPUT);
  pinMode(buttonPin9, INPUT);
  pinMode(buttonPin10, INPUT);
  pinMode(buttonPin11, INPUT);
  pinMode(buttonPin12, INPUT);
  pinMode(buttonPin13, INPUT);
  pinMode(buttonPin14, INPUT);
  pinMode(buttonPin15, INPUT);
  pinMode(buttonPin16, INPUT);
  pinMode(buttonPin17, INPUT);
  pinMode(buttonPin18, INPUT);
  Serial.begin(9600);
   
}


void loop() {
 
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);
  buttonState8 = digitalRead(buttonPin8);
  buttonState9 = digitalRead(buttonPin9);
  buttonState10 = digitalRead(buttonPin10);
  buttonState11 = digitalRead(buttonPin11);
  buttonState12 = digitalRead(buttonPin12);
  buttonState13 = digitalRead(buttonPin13);
  buttonState14 = digitalRead(buttonPin14);
  buttonState15 = digitalRead(buttonPin15);
  buttonState16 = digitalRead(buttonPin16);
  buttonState17 = digitalRead(buttonPin17);
  buttonState18 = digitalRead(buttonPin18);
  
Serial.available() == 0; 

int val = Serial.read() - '0'; 
if (val == 1) {
 buttonPushCounter = 0;   
 buttonPushCounter2 = 0;
 buttonPushCounter3 = 0;
 buttonPushCounter4 = 0;
 buttonPushCounter5 = 0;
 buttonPushCounter6 = 0;
 buttonPushCounter7 = 0;
 buttonPushCounter8 = 0;
 buttonPushCounter9 = 0;
 buttonPushCounter10 = 0;
 buttonPushCounter11 = 0;
 buttonPushCounter12 = 0;
 buttonPushCounter13 = 0;
 buttonPushCounter14 = 0;
 buttonPushCounter15 = 0;
 buttonPushCounter16 = 0;
 buttonPushCounter17 = 0;
 buttonPushCounter18 = 0;
 
  }
  //=======================
  if (buttonState != lastButtonState) 
  {
    
    if (buttonState == HIGH) 
          {
            buttonPushCounter++;
     
            Serial.print("L1-S1_STOP");
            delay(100);
          }
    else {
            if (buttonPushCounter == 0)
                {
                  Serial.print("NONE"); 
                }
            else{
                  Serial.print("L1-S1_START");
                  delay(100);
                }
          }
    delay(10);
  }
  lastButtonState = buttonState;


   //=======================

 if (buttonState2 != lastButtonState2)
 {
    
    if (buttonState2 == HIGH) 
    {
      buttonPushCounter2++;
      Serial.print("L1-S2_STOP");
      delay(100);
    } 
    else {
       if (buttonPushCounter2 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L1-S2_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState2 = buttonState2;

 //=======================

 if (buttonState3 != lastButtonState3) {
    
    if (buttonState3 == HIGH) {
      buttonPushCounter3++;
      
      Serial.print("L1-S3_STOP");
      delay(100);
    } else {
      
       if (buttonPushCounter3 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L1-S3_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState3 = buttonState3;

//=======================
  if (buttonState4 != lastButtonState4) {
    
    if (buttonState4 == HIGH) {
      buttonPushCounter4++;
     
      Serial.print("L1-S4_STOP");
      delay(100);
    } else {
       if (buttonPushCounter4 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L1-S4_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState4 = buttonState4;
  
//=======================
  if (buttonState5 != lastButtonState5) {
    
    if (buttonState5 == HIGH) {
      buttonPushCounter5++;
     
      Serial.print("L1-S5_STOP");
      delay(100);
    } else {
       if (buttonPushCounter5 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L1-S5_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState5 = buttonState5;
 //=======================
  if (buttonState6 != lastButtonState6) {
    
    if (buttonState6 == HIGH) {
      buttonPushCounter6++;
     
      Serial.print("L1-S6_STOP");
      delay(100);
    } else {
       if (buttonPushCounter6 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L1-S6_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState6 = buttonState6;
 
//=======================
  if (buttonState7 != lastButtonState7) {
    
    if (buttonState7 == HIGH) {
      buttonPushCounter7++;
     
      Serial.print("L1-S7_STOP");
      delay(100);
    } else {
       if (buttonPushCounter7 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L1-S7_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState7 = buttonState7;
 
//=======================
  if (buttonState8 != lastButtonState8) {
    
    if (buttonState8 == HIGH) {
      buttonPushCounter8++;
     
      Serial.print("L1-S8_STOP");
      delay(100);
    } else {
       if (buttonPushCounter8 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L1-S8_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState8 = buttonState8;
 
  //=======================
  if (buttonState9 != lastButtonState9) {
    
    if (buttonState9 == HIGH) {
      buttonPushCounter9++;
     
      Serial.print("L1-S9_STOP");
      delay(100);
    } else {
       if (buttonPushCounter9 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L1-S9_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState9 = buttonState9;

 //=======================
  if (buttonState10!= lastButtonState10) {
    
    if (buttonState10 == HIGH) {
      buttonPushCounter10++;
     
      Serial.print("L2-S1_STOP");
      delay(100);
    } else {
       if (buttonPushCounter10 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L2-S1_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState10 = buttonState10;

 //=======================
  if (buttonState11 != lastButtonState11) {
    
    if (buttonState11 == HIGH) {
      buttonPushCounter11++;
     
      Serial.print("L2-S2_STOP");
      delay(100);
    } else {
       if (buttonPushCounter11 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L2-S2_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState11 = buttonState11;

 //=======================
  if (buttonState12 != lastButtonState12) {
    
    if (buttonState12 == HIGH) {
      buttonPushCounter12++;
     
      Serial.print("L2-S3_STOP");
      delay(100);
    } else {
       if (buttonPushCounter12 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L2-S3_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState12 = buttonState12;

 //=======================
  if (buttonState13 != lastButtonState13) {
    
    if (buttonState13 == HIGH) {
      buttonPushCounter13++;
     
      Serial.print("L2-S4_STOP");
      delay(100);
    } else {
       if (buttonPushCounter13 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L2-S4_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState13 = buttonState13;

 //=======================
  if (buttonState14 != lastButtonState14) {
    
    if (buttonState14 == HIGH) {
      buttonPushCounter14++;
     
      Serial.print("L2-S5_STOP");
      delay(100);
    } else {
       if (buttonPushCounter14 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L2-S5_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState14 = buttonState14;

 //=======================
  if (buttonState15 != lastButtonState15) {
    
    if (buttonState15 == HIGH) {
      buttonPushCounter15++;
     
      Serial.print("L2-S6_STOP");
      delay(100);
    } else {
       if (buttonPushCounter15 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L2-S6_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState15 = buttonState15;

 //=======================
  if (buttonState16 != lastButtonState16) {
    
    if (buttonState16 == HIGH) {
      buttonPushCounter16++;
     
      Serial.print("L2-S7_STOP");
      delay(100);
    } else {
       if (buttonPushCounter16 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L2-S7_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState16 = buttonState16;

 //=======================
  if (buttonState17 != lastButtonState17) {
    
    if (buttonState17 == HIGH) {
      buttonPushCounter17++;
     
      Serial.print("L2-S8_STOP");
      delay(100);
    } else {
       if (buttonPushCounter17 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L2-S8_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState17 = buttonState17;

 //=======================
  if (buttonState18 != lastButtonState18) {
    
    if (buttonState18 == HIGH) {
      buttonPushCounter18++;
     
      Serial.print("L2-S9_STOP");
      delay(100);
    } else {
       if (buttonPushCounter18 == 0){
        Serial.print("NONE"); 
      }
      else{
      Serial.print("L2-S9_START");
      delay(100);
      }
    }
    delay(10);
  }
  lastButtonState18 = buttonState18;

 
}










