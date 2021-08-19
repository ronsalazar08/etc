
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
  delay(2000);
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
if ((buttonState0> s1)&&(buttonState0 < s2)){
  Serial.print("START");
  Output = B00111110;
 
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);

s1 = 2000;
s2 = 2000;
/*
pa1 = 315;
 pa2 = 375;
pb1 = 430;
 pb2 = 495;
 pc1 = 570;
 pc2 = 630;
pd1 = 1015;
 pd2 = 1040;
 pe1 = 920;
 pe2 = 999;
*/
}//s1 if
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
  goto B;
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
  goto C;
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
  goto D;
}

else if
((buttonState1 > pe1 )&&(buttonState1 < pe2)||(val == 6)){
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
  goto E;
}

A:

 /* // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
    } 
    else{
      
    }
      delay(50);
if (buttonPushCounter == 15) {
    Serial.print("POFF");
    delay(50);
    }
    // Delay a little bit to avoid bouncing
  
  }
  else{
    
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;
if (buttonPushCounter == 1){
pAseq1();
goto ex;
}
else if (buttonPushCounter == 2){
pAseq2();
goto ex;
}
else if (buttonPushCounter == 3){
pAseq3();
goto ex;
}
else if (buttonPushCounter == 4){
pAseq4();
goto ex;
}
else if (buttonPushCounter == 5){
pAseq5();
goto ex;
}
else if (buttonPushCounter == 6){
pAseq6();
goto ex;
}
else if (buttonPushCounter == 7){
pAseq7();
goto ex;
}
else if (buttonPushCounter == 8){
pAseq8();
goto ex;
}
else if (buttonPushCounter == 9){
pAseq9();
goto ex;
}
else if (buttonPushCounter == 10){
pAseq10();
goto ex;
}
else if (buttonPushCounter == 11){
pAseq11();
goto ex;
}
else if (buttonPushCounter == 12){
pAseq12();
goto ex;
}
else if (buttonPushCounter == 13){
pAseq13();
goto ex;
}
else if (buttonPushCounter == 14){
pAseq14();
goto ex;
}
else if (buttonPushCounter == 15){

 finish();
 goto ex;
// }
}

//else if (buttonPushCounter == 10){
//buttonPushCounter = 0;
//}

  // turns on the LED every four button pushes by
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of
  // the division of two numbers:
*/
B:
finish();
/*
// compare the buttonState to its previous state
  if (buttonState != lastButtonState1) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      
      buttonPushCounter1++;
    } 
if (buttonPushCounter1 == 15) {
    Serial.print("POFF");
        delay(50);
    }
     }
   else{
    
  
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState1 = buttonState;
if (buttonPushCounter1 == 1){
//pBseq1();
finish();
goto ex;
}
else if (buttonPushCounter1 == 2){
pBseq2();

goto ex;
}
else if (buttonPushCounter1 == 3){
pBseq3();
goto ex;
}
else if (buttonPushCounter1 == 4){
pBseq4();
goto ex;
}
else if (buttonPushCounter1 == 5){
pBseq5();
goto ex;
}
else if (buttonPushCounter1 == 6){
pBseq6();
goto ex;
}
else if (buttonPushCounter1 == 7){
pBseq7();
goto ex;
}
else if (buttonPushCounter1 == 8){
pBseq8();
goto ex;
}
else if (buttonPushCounter1 == 9){
pBseq9();
goto ex;
}
else if (buttonPushCounter1 ==10){
pBseq10();
goto ex;
}
else if (buttonPushCounter1 ==11){
pBseq11();
goto ex;
}
else if (buttonPushCounter1 ==12){
pBseq12();
goto ex;
}
else if (buttonPushCounter1 == 13){
pBseq13();
goto ex;
}
else if (buttonPushCounter1 ==14){
pBseq14();
goto ex;
}
else if (buttonPushCounter1 ==15){
finish();
goto ex;
}
*/

C:
finish();
/*
// compare the buttonState to its previous state
  if (buttonState != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      
      buttonPushCounter2++;
    } 
if (buttonPushCounter2 == 8) {
    Serial.print("POFF");
        delay(50);
    }
   
  }
   else{
    
  
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState2 = buttonState;



if (buttonPushCounter2 == 1){
pCseq1();

goto ex;
}
else if (buttonPushCounter2 == 2){
pCseq2();

goto ex;
}
else if (buttonPushCounter2 == 3){
pCseq3();
goto ex;
}
else if (buttonPushCounter2 ==4){
pCseq4();
goto ex;
}
else if (buttonPushCounter2 == 5){
pCseq5();
goto ex;
}
else if (buttonPushCounter2 == 6){
pCseq6();
goto ex;
}
else if (buttonPushCounter2 == 7){
pCseq7();
goto ex;
}
else if (buttonPushCounter2 == 8){
finish();
goto ex;
}

*/


D:
finish();
/*
// compare the buttonState to its previous state
  if (buttonState != lastButtonState3) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      
      buttonPushCounter3++;
    } 
if (buttonPushCounter3 == 7) {
    Serial.print("POFF");
        delay(50);
    }
 ;
  }
 else{
    
  
  }
  lastButtonState3 = buttonState;



if (buttonPushCounter3 == 1){
pDseq1();

goto ex;
}
else if (buttonPushCounter3 == 2){
pDseq2();

goto ex;
}
else if (buttonPushCounter3 == 3){
pDseq3();

goto ex;
}
else if (buttonPushCounter3 == 4){
pDseq4();

goto ex;
}
else if (buttonPushCounter3 == 5){
pDseq5();

goto ex;
}
else if (buttonPushCounter3 == 6){
pDseq6();

goto ex;
}
else if (buttonPushCounter3 == 7){
finish();

goto ex;
}

*/
E:
finish();
/*
// compare the buttonState to its previous state
  if (buttonState != lastButtonState4) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      
      buttonPushCounter4++;
    } 
    if (buttonPushCounter4 == 15) {
    Serial.print("POFF");
        delay(50);
    }
  
  }
   else{
    
  
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState4 = buttonState;



if (buttonPushCounter4 == 1){
pEseq1();

goto ex;
}
else if (buttonPushCounter4 == 2){
pEseq2();

goto ex;
}
else if (buttonPushCounter4 == 3){
pEseq3();

goto ex;
}
else if (buttonPushCounter4 == 4){
pEseq4();

goto ex;
}
else if (buttonPushCounter4 == 5){
pEseq5();

goto ex;
}
else if (buttonPushCounter4 == 6){
pEseq6();

goto ex;
}
else if (buttonPushCounter4 == 7){
pEseq7();

goto ex;
}
else if (buttonPushCounter4 == 8){
pEseq8();

goto ex;
}
else if (buttonPushCounter4 == 9){
pEseq9();

goto ex;
}
else if (buttonPushCounter4 ==10){
pEseq10();

goto ex;
}
else if (buttonPushCounter4 ==11){
pEseq11();

goto ex;
}
else if (buttonPushCounter4 ==12){
pEseq12();

goto ex;
}
else if (buttonPushCounter4 ==13){
pEseq13();

goto ex;
}
else if (buttonPushCounter4 ==14){
pEseq14();

goto ex;
}
else if (buttonPushCounter4 ==15){
finish();

goto ex;
}


ex:;
  
*/
}
/*

void pAseq1(){
  Serial.print("LED1");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B10000000;
  Output2 = B00000001;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }

void pAseq2(){
  Serial.print("LED2");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000001;
  Output3 = B00000000;
  Output2 = B00000010;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
void pAseq3(){
  Serial.print("LED3");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000010;
  Output3 = B00000000;
  Output2 = B00000100;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
void pAseq4(){
  Serial.print("LED4");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000100;
  Output3 = B00000000;
  Output2 = B00001000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
void pAseq5(){
  
  Serial.print("LED5");
    delay(50);
  Output5 = B00000000;
  Output4 = B00001000;
  Output3 = B00000000;
  Output2 = B00010000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
void pAseq6(){
  Serial.print("LED6");
    delay(50);
  Output5 = B00000000;
  Output4 = B00010000;
  Output3 = B00000000;
  Output2 = B00100000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}

void pAseq7(){
  Serial.print("LED7");
    delay(50);
  Output5 = B00000000;
  Output4 = B00100000;
  Output3 = B00000000;
  Output2 = B01000000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
void pAseq8(){
  Serial.print("LED8");
    delay(50);
  Output5 = B00000000;
  Output4 = B01000000;
  Output3 = B00000000;
  Output2 = B10000000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
void pAseq9(){
  Serial.print("LED9");
    delay(50);
  Output5 = B00000000;
  Output4 = B10000000;
  Output3 = B00000001;
  Output2 = B00000000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}

void pAseq10(){
  Serial.print("LED10");
    delay(50);
  Output5 = B00000001;
  Output4 = B00000000;
  Output3 = B00000010;
  Output2 = B00000000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
void pAseq11(){
  Serial.print("LED11");
    delay(50);
  Output5 = B00000010;
  Output4 = B00000000;
  Output3 = B00000100;
  Output2 = B00000000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
void pAseq12(){
  Serial.print("LED12");
    delay(50);
  Output5 = B00000100;
  Output4 = B00000000;
  Output3 = B00001000;
  Output2 = B00000000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}

void pAseq13(){
  Serial.print("LED13");
    delay(50);
  Output5 = B00001000;
  Output4 = B00000000;
  Output3 = B00010000;
  Output2 = B00000000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}

void pAseq14(){
  Serial.print("LED14");
    delay(50);
  Output5 = B00010000;
  Output4 = B00000000;
  Output3 = B00100000;
  Output2 = B00000000;
  Output1 = B00000010;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  
}*/
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
    
      SPI.transfer(0);
      SPI.transfer(0);
      SPI.transfer(0);
      SPI.transfer(0);
      SPI.transfer(0);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
    Serial.print("FINISH");
    
    delay(50);
    delay(500);
 digitalWrite(7,HIGH);
  }
  }
  /*
void pBseq1(){
  
 Serial.print("BLED14");
    delay(50);
 Output5 = B00001000;
  Output4 = B00000000;
  Output3 = B00010000;
  Output2 = B00000000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pBseq2(){
    
  Serial.print("BLED13");
    delay(50);
 Output5 = B00000100;
  Output4 = B00000000;
  Output3 = B00001000;
  Output2 = B00000000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pBseq3(){
  Serial.print("BLED12");
    delay(50);
  Output5 = B00000010;
  Output4 = B00000000;
  Output3 = B00000100;
  Output2 = B00000000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pBseq4(){
  Serial.print("BLED11");
    delay(50);
  Output5 = B00000001;
  Output4 = B00000000;
  Output3 = B00000010;
  Output2 = B00000000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pBseq5(){
  Serial.print("BLED10");
    delay(50);
  Output5 = B00000000;
  Output4 = B10000000;
  Output3 = B00000001;
  Output2 = B00000000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pBseq6(){
  Serial.print("BLED9");
    delay(50);
  Output5 = B00000000;
  Output4 = B01000000;
  Output3 = B00000000;
  Output2 = B10000000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
void pBseq7(){
  Serial.print("BLED8");
    delay(50);
  Output5 = B00000000;
  Output4 = B00100000;
  Output3 = B00000000;
  Output2 = B01000000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pBseq8(){
  Serial.print("BLED7");
    delay(50);
  Output5 = B00000000;
  Output4 = B00010000;
  Output3 = B00000000;
  Output2 = B00100000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pBseq9(){
    
  Serial.print("BLED6");
    delay(50);
  Output5 = B00000000;
  Output4 = B00001000;
  Output3 = B00000000;
  Output2 = B00010000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
void pBseq10(){
  Serial.print("BLED5");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000100;
  Output3 = B00000000;
  Output2 = B00001000;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pBseq11(){
  Serial.print("BLED4");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000010;
  Output3 = B00000000;
  Output2 = B00000100;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pBseq12(){
  Serial.print("BLED3");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000001;
  Output3 = B00000000;
  Output2 = B00000010;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
void pBseq13(){
  Serial.print("BLED2");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B10000000;
  Output2 = B00000001;
  Output1 = B00000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pBseq14(){
    
  Serial.print("BLED1");
    delay(50);
  
  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B01000000;
  Output2 = B00000000;
  Output1 = B10000100;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }



  void pCseq1(){
     Serial.print("CLED1");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000001;
  Output3 = B00000000;
  Output2 = B00000010;
  Output1 = B00001000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pCseq2(){
     Serial.print("CLED2");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000100;
  Output3 = B00000000;
  Output2 = B00001000;
  Output1 = B00001000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pCseq3(){
     Serial.print("CLED3");
    delay(50);
  Output5 = B00000000;
  Output4 = B00010000;
  Output3 = B00000000;
  Output2 = B00100000;
  Output1 = B00001000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
 void pCseq4(){
     Serial.print("CLED4");
    delay(50);
  Output5 = B00000000;
  Output4 = B01000000;
  Output3 = B00000000;
  Output2 = B10000000;
  Output1 = B00001000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
 void pCseq5(){
     Serial.print("CLED5");
    delay(50);
  Output5 = B00000001;
  Output4 = B00000000;
  Output3 = B00000010;
  Output2 = B00000000;
  Output1 = B00001000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
 void pCseq6(){
     Serial.print("CLED6");
    delay(50);
  Output5 = B00000100;
  Output4 = B00000000;
  Output3 = B00001000;
  Output2 = B00000000;
  Output1 = B00001000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
 void pCseq7(){
     Serial.print("CLED7");
    delay(50);
  
  
  Output5 = B00010000;
  Output4 = B00000000;
  Output3 = B00100000;
  Output2 = B00000000;
  Output1 = B00001000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }


void pDseq1(){
  Serial.print("DLED1");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000010;
  Output3 = B00000000;
  Output2 = B00000100;
  Output1 = B00010000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pDseq2(){
  Serial.print("DLED2");
    delay(50);
  Output5 = B00000000;
  Output4 = B00001000;
  Output3 = B00000000;
  Output2 = B00010000;
  Output1 = B00010000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pDseq3(){
  Serial.print("DLED3");
    delay(50);
  Output5 = B00000000;
  Output4 = B00100000;
  Output3 = B00000000;
  Output2 = B01000000;
  Output1 = B00010000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  
  void pDseq4(){
  Serial.print("DLED4");
    delay(50);
  Output5 = B00000000;
  Output4 = B10000000;
  Output3 = B00000001;
  Output2 = B00000000;
  Output1 = B00010000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pDseq5(){
  Serial.print("DLED5");
    delay(50);
  Output5 = B00000010;
  Output4 = B00000000;
  Output3 = B00000100;
  Output2 = B00000000;
  Output1 = B00010000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pDseq6(){
  Serial.print("DLED6");
    delay(50);
    
 
  Output5 = B00001000;
  Output4 = B00000000;
  Output3 = B00010000;
  Output2 = B00000000;
  Output1 = B00010000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }

   void pEseq1(){
  Serial.print("ELED1");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000100;
  Output3 = B00000000;
  Output2 = B00001000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pEseq2(){
  Serial.print("ELED2");
    delay(50);
  Output5 = B00000000;
  Output4 = B10000000;
  Output3 = B00000001;
  Output2 = B00000000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pEseq3(){
  Serial.print("ELED3");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000000;
  Output3 = B10000000;
  Output2 = B00000001;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pEseq4(){
  Serial.print("ELED4");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000001;
  Output3 = B00000000;
  Output2 = B00000010;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
     void pEseq5(){
  Serial.print("ELED5");
    delay(50);
  Output5 = B00000000;
  Output4 = B00100000;
  Output3 = B00000000;
  Output2 = B01000000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
     void pEseq6(){
  Serial.print("ELED6");
    delay(50);
  Output5 = B00000000;
  Output4 = B01000000;
  Output3 = B00000000;
  Output2 = B10000000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
void pEseq7(){
  Serial.print("ELED7");
    delay(50);
  Output5 = B00000000;
  Output4 = B00010000;
  Output3 = B00000000;
  Output2 = B00100000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pEseq8(){
  Serial.print("ELED8");
    delay(50);
  Output5 = B00000000;
  Output4 = B00000010;
  Output3 = B00000000;
  Output2 = B00000100;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
void pEseq9(){
  
  Serial.print("ELED9");
    delay(50);
  Output5 = B00000000;
  Output4 = B00001000;
  Output3 = B00000000;
  Output2 = B00010000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pEseq10(){
  Serial.print("ELED10");
    delay(50);
  Output5 = B00000010;
  Output4 = B00000000;
  Output3 = B00000100;
  Output2 = B00000000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pEseq11(){
  Serial.print("ELED11");
    delay(50);
  Output5 = B00010000;
  Output4 = B00000000;
  Output3 = B00100000;
  Output2 = B00000000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pEseq12(){
  Serial.print("ELED12");
    delay(50);
  Output5 = B00001000;
  Output4 = B00000000;
  Output3 = B00010000;
  Output2 = B00000000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
  void pEseq13(){
  Serial.print("ELED13");
    delay(50);
  Output5 = B00000001;
  Output4 = B00000000;
  Output3 = B00000010;
  Output2 = B00000000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }
   void pEseq14(){
  Serial.print("ELED14");
    delay(50);
    
  
  Output5 = B00000100;
  Output4 = B00000000;
  Output3 = B00001000;
  Output2 = B00000000;
  Output1 = B00100000;
  SPI.transfer(Output5);
  SPI.transfer(Output4);
  SPI.transfer(Output3);
  SPI.transfer(Output2);
  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  }*/
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
