#include <SPI.h>
byte Input, Output,Output1,Output2, Check;
int j;
float sec = 0;
void setup(){
  pinMode(13, OUTPUT);//clock
  pinMode(11, OUTPUT);//data
  pinMode(4, OUTPUT);//latch
  pinMode(2, INPUT);//Input from buttons


  
  
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV2);
SPI.begin();

Output = B00000001;
Output1 = B00000001;

SPI.transfer(Output1);
SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  Serial.begin(9600);
// attachInterrupt(2, pin_read, RISING); 
  
}//setup

void loop(){

delay(500);
sec = sec + 1;

 Serial.print("ms = ");
    Serial.println(sec);



   if (sec == 7){
    bitClear(Output1, 0);
    bitSet(Output1, 1);
    
  }

  
  else if (sec == 9){
    bitClear(Output2, 0);
     bitClear(Output2, 1);
    bitSet(Output2, 2);
    
  }
   else if (sec == 20)
 {sec = 0;}
  
   //start
 if((digitalRead(2) ==HIGH) && (sec == 5) && (Output = B00000001))
 {
  bitWrite(Output,0, LOW);
  bitWrite(Output,1, HIGH);
  bitWrite(Output,2, HIGH);
  bitWrite(Output,3, HIGH);
  bitWrite(Output,4, HIGH);
  bitWrite(Output,5, HIGH);
  bitWrite(Output,6, LOW);
  bitWrite(Output,7, LOW);
 

  SPI.transfer(Output1);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
 }
 
if((digitalRead(2) ==HIGH) && (sec == 7) && (Output1 = B00000010)){
  bitWrite(Output,0, LOW);
  bitWrite(Output,1, HIGH);
  bitWrite(Output,2, LOW);
  bitWrite(Output,3, LOW);
  bitWrite(Output,4, LOW);
  bitWrite(Output,5, LOW);
  bitWrite(Output,6, LOW);
  bitWrite(Output,7, LOW);

  SPI.transfer(Output1);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
 }
  if((digitalRead(2) ==HIGH) && (sec == 9) && (Output2 = B00000100)){
  bitWrite(Output,0, LOW);
  bitWrite(Output,1, LOW);
  bitWrite(Output,2,HIGH);
  bitWrite(Output,3, LOW);
  bitWrite(Output,4, LOW);
  bitWrite(Output,5, LOW);
  bitWrite(Output,6, LOW);
  bitWrite(Output,7,LOW);

  SPI.transfer(Output1);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
 }

 
}//loop


 // void pin_read(){

   // for(j=0; j<50; j++)
   // delayMicroseconds(1000);

   

  
  

//}//pin_read



