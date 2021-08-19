
#include <SPI.h>
byte Input, Output,Output1, Output2, Output3, Output4, Output5;
// this constant won't change:
const int  buttonPin =2;    // the pin that the pushbutton is attached to
const int  buttonPin1 =A0;   
 const int pinread1 = A1;
      // the pin that the LED is attached to
int s1 = 120;
 int s2 = 170;
 int pa1;
 int pa2;
 int pb1;
 int pb2;
 int pc1;
 int pc2;
 int pd1;
 int pd2;
 int pe1;
 int pe2;
// Variables will change:

int buttonState = 0; 
int buttonState1 = 0;// current state of the button
int buttonState0 = 0;// current state of the button
int lastButtonState = 0;     // previous state of the button
int lastButtonState1 = 0;
int lastButtonState2 = 0;
int lastButtonState3 = 0;
int lastButtonState4 = 0;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonPushCounter1 = 0;
int buttonPushCounter2 = 0;
int buttonPushCounter3 = 0;
int buttonPushCounter4 = 0;

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(pinread1, INPUT);
  pinMode(A4, INPUT);
   pinMode(7, OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(9,OUTPUT);
   digitalWrite(7, LOW);
   digitalWrite(8, LOW);
  // initialize the LED as an output:
  // initialize serial communication:
 pinMode(13, OUTPUT);//clock
  pinMode(11, OUTPUT);//data
  pinMode(4, OUTPUT);//latch
  pinMode(2, INPUT);//Input from buttons
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV2);
SPI.begin();

Output5= B00000000;
Output4= B00000000;
Output3= B00000000;
Output2= B00000000;
Output1= B00000000;
Output = B00000001;
 

  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);

Serial.begin(9600);

  digitalWrite(9, LOW);
}


void loop() {
  // read the pushbutton input pin:
digitalWrite(8, LOW); // turn on LED
Serial.available() == 0 ; // do nothing if nothing sent

int val = Serial.read()- '0'; // deduct ascii value of '0' to find numeric value of sent number
if (val == 1) { // test for command 1 then turn on LED

digitalWrite(8, HIGH);

}

  buttonState = digitalRead(buttonPin);
buttonState1 = analogRead(buttonPin1);
buttonState0 = analogRead(pinread1);
//Serial.println(buttonState1);

if ((buttonState1 > pa1 )&&(buttonState1<pa2)||(val == 2)){
Serial.print("PA");
 s1 = 2000;
s2 = 2000;
pa1 = 2000;
 pa2 = 2000;
pb1 = 2000;
 pb2 = 2000;
 pc1 = 2000;
 pc2 = 2000;
pd1 = 2000;
 pd2 = 2000;
 pe1 = 2000;
 pe2 = 2000;
  pALayout();
 digitalWrite(9, HIGH);
  /*Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B01000000;
  Output2 = B00000000;
  Output1 = B10000010;
SPI.transfer(Output5);
SPI.transfer(Output4);
SPI.transfer(Output3);
SPI.transfer(Output2);
SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
 */
 finish();
 goto A;
}
else if
((buttonState1 > pb1 )&&(buttonState1<pb2)||(val == 3)){
Serial.print("PB");
 s1 = 2000;
s2 = 2000;
pa1 = 2000;
 pa2 = 2000;
pb1 = 2000;
 pb2 = 2000;
 pc1 = 2000;
 pc2 = 2000;
pd1 = 2000;
 pd2 = 2000;
 pe1 = 2000;
 pe2 = 2000;
  
 /* Output5 = B00010000;
  Output4 = B00000000;
  Output3 = B00100000;
  Output2 = B00000000;
  Output1 = B00000100;
SPI.transfer(Output5);
SPI.transfer(Output4);
SPI.transfer(Output3);
SPI.transfer(Output2);
SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
   buttonPushCounter = 50;*/
     pBLayout();
     
 digitalWrite(9, HIGH);
 finish();
 goto A;
}
 else if
((buttonState1 > pc1 )&&(buttonState1 < pc2)||(val == 4)){
  Serial.print("PC");
s1 = 2000;
s2 = 2000;
pa1 = 2000;
 pa2 = 2000;
pb1 = 2000;
 pb2 = 2000;
 pc1 = 2000;
 pc2 = 2000;
pd1 = 2000;
 pd2 = 2000;
 pe1 = 2000;
 pe2 = 2000;
  
 /* Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B01000000;
  Output2 = B00000000;
  Output1 = B10001000;
SPI.transfer(Output5);
SPI.transfer(Output4);
SPI.transfer(Output3);
SPI.transfer(Output2);
SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
   buttonPushCounter = 50;
   buttonPushCounter1 = 50;*/
     pCLayout();
digitalWrite(9, HIGH);
 finish();
 goto A;
}
else if
((buttonState1 > pd1 )&&(buttonState1 < pd2)||(val == 5)){
  Serial.print("PD");
  s1 = 2000;
s2 = 2000;
pa1 = 2000;
 pa2 = 2000;
pb1 = 2000;
 pb2 = 2000;
 pc1 = 2000;
 pc2 = 2000;
pd1 = 2000;
 pd2 = 2000;
 pe1 = 2000;
 pe2 = 2000;
  
 /* Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B10000000;
  Output2 = B00000001;
  Output1 = B00010000;
SPI.transfer(Output5);
SPI.transfer(Output4);
SPI.transfer(Output3);
SPI.transfer(Output2);
SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
   buttonPushCounter = 50;
   buttonPushCounter1 = 50;
   buttonPushCounter2 = 50;
   */
     pDLayout();
     
 digitalWrite(9, HIGH);
 finish();
 goto A;
}

else if((buttonState1 > pe1 )&&(buttonState1 < pe2)||(val == 6)){
  Serial.print("PE");
  s1 = 2000;
s2 = 2000;
pa1 = 2000;
 pa2 = 2000;
pb1 = 2000;
 pb2 = 2000;
 pc1 = 2000;
 pc2 = 2000;
pd1 = 2000;
 pd2 = 2000;
 pe1 = 2000;
 pe2 = 2000;
  
/*  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B01000000;
  Output2 = B00000000;
  Output1 = B10100000;
SPI.transfer(Output5);
SPI.transfer(Output4);
SPI.transfer(Output3);
SPI.transfer(Output2);
SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
   buttonPushCounter = 50;
   buttonPushCounter1 = 50;
   buttonPushCounter2 = 50;
   buttonPushCounter3 = 50;*/
   pELayout();
   
 digitalWrite(9, HIGH);
 
 goto A;
}

A:
finish();


}

void finish(){
  
  
  
 /* Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B00000000;
  Output2 = B00000000;
  Output1 = B01000000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  */
 
   
  int fin = digitalRead(A4);
  if (fin == HIGH){

Output5= B00000000;
Output4= B00000000;
Output3= B00000000;
Output2= B00000000;
Output1= B00000000;
Output = B00000001;
 digitalWrite(9,LOW);

  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
    Serial.print("FINISH");
    
    delay(50);
    delay(500);
//digitalWrite(7,HIGH);
  }
  }

void pALayout(){

  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B00111111;
  Output2 = B11111111;
  Output1 = B11000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }

void pBLayout(){

  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B00010101;
  Output2 = B01010101;
  Output1 = B01000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  
  }

  void pCLayout(){

  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B00101010;
  Output2 = B10101010;
  Output1 = B11001000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  
  }
  void pDLayout(){

  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B00100100;
  Output2 = B10010010;
  Output1 = B01010000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  
  }
  void pELayout(){

  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B00110110;
  Output2 = B11011011;
  Output1 = B01100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  
  }
