#include <SPI.h>
byte Input, Output,Output1, Check;
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

Output = B00111111;

SPI.transfer(Output);
SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  Serial.begin(9600);
 attachInterrupt(2, pin_read, RISING); 
  
}//setup

void loop(){



 


 
}//loop


  void pin_read(){
     for(j=0; j<50; j++)
    delayMicroseconds(1000);

  
 if((digitalRead(2) ==HIGH) && (Output = B00000001))
 {
  bitWrite(Output,0, LOW);
  bitWrite(Output,1, LOW);
  bitWrite(Output,2, LOW);
  bitWrite(Output,3, LOW);
  bitWrite(Output,4, LOW);
  bitWrite(Output,5, LOW);
  bitWrite(Output,6, LOW);
  bitWrite(Output,7, LOW);
 

  SPI.transfer(Output);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
 
   
   Check=1;
    for(j=0; j<=8; j++){
  SPI.transfer(Output);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  delayMicroseconds(500);
  if(digitalRead(2)==HIGH){
      if(bitRead(Output, j)==1)
      bitWrite(Output, j, 0);
      else
      bitWrite(Output, j, 1);
  }//dig check
  
  Check = Check<<1;
    }//j
    
  SPI.transfer(255);
  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
 
 while(digitalRead(2)==HIGH){}

  }
  

}//pin_read



