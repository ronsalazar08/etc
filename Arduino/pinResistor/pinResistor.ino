#include <SPI.h>
byte Input, Output,Output1, Check=1;
int j;
 int pinread = A0;
  int pinread1 = A1;
 int val,val1;
 int s1 = 135;
 int s2 = 145;
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

 int f1 = 1020;
 int f2 = 1025;
void setup() {
  // put your setup code here, to run once:
pinMode(pinread, INPUT);
pinMode(pinread1, INPUT);
pinMode(13, OUTPUT);//clock
  pinMode(11, OUTPUT);//data
  pinMode(4, OUTPUT);//latch
  pinMode(2, INPUT);//Input from buttons
SPI.setBitOrder(MSBFIRST);
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV2);
SPI.begin();
Output = B00000001;
 

  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(pinread1);

  val1 = analogRead(pinread);
   Serial.println(val1);
delay(100);
//start
if ((val> s1)&&(val < s2)){
  Output = B00111110;
 

  SPI.transfer(Output);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
  
s1 = 2000;
s2 = 2000;
pa1 = 330;
 pa2 = 355;
pb1 = 455;
 pb2 = 490;
 pc1 = 595;
 pc2 = 625;
pd1 = 670;
 pd2 = 705;
 pe1 = 955;
 pe2 = 999;

}//s1 if

//pA
if ((val1> pa1)&&(val1 < pa2)){
 Output1 = B00000010;
 

  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);

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
//SEQUENCE
}
else if ((val1> pb1)&&(val1 < pb2)){
 Output1 = B00000100;
 

  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);

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

//SEQUENCE
}
else if ((val1> pc1)&&(val1 < pc2)){
 Output1 = B00001000;
 

  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);

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
//SEQUENCE
}
else if ((val1> pd1)&&(val1 < pd2)){
 Output1 = B00010000;
 

  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);

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

//SEQUENCE
}

else if ((val1> pe1)&&(val1 < pe2)){
 Output1 = B00100000;
 

  SPI.transfer(Output1);
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);

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

//SEQUENCE
}
 




}
