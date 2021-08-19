#include <SPI.h>
byte output;

void setup() {
  // put your setup code here, to run once:
pinMode(52, OUTPUT);//clock
pinMode(51, OUTPUT);//data
pinMode(12, OUTPUT);//latch
pinMode(10, OUTPUT);//led&buzzer
  for (int i = 1; i< 9; i++)
  {
   pinMode(i, INPUT);//2-9 input pins
  }
SPI.setBitOrder(LSBFIRST);
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV2);
SPI.begin();
Serial.begin(115200);

}

void loop() {
    wire1();
    wire2();
    wire3();
    wire4();
    wire5();
    wire6();
    wire7();
    wire8();
}//void

void latch() {
digitalWrite(12, HIGH);
digitalWrite(12, LOW);
delay(40);
}
void ledOff()
{
digitalWrite(10, 0);
}
void ledOn()
{
digitalWrite(10, 1);
delay(40);
digitalWrite(10, 0);
}



void wire1(){
  output = B10000000;
SPI.transfer(output);
latch();
  
  if (digitalRead(2))
  {
    ledOff();
  }
  else if(
          (digitalRead(2) == 0 && digitalRead(3)) || 
          (digitalRead(2) == 0 && digitalRead(4)) ||
          (digitalRead(2) == 0 && digitalRead(5)) || 
          (digitalRead(2) == 0 && digitalRead(6)) || 
          (digitalRead(2) == 0 && digitalRead(7)) || 
          (digitalRead(2) == 0 && digitalRead(8)) || 
          (digitalRead(2) == 0 && digitalRead(9)) 
          )
  {
    ledOn();
   
  }

}

void wire2(){
  output = B01000000;
SPI.transfer(output);
latch();
  
  if (digitalRead(3))
  {
    ledOff();
  }
  else if(
          (digitalRead(3) == 0 && digitalRead(2)) || 
          (digitalRead(3) == 0 && digitalRead(4)) ||
          (digitalRead(3) == 0 && digitalRead(5)) || 
          (digitalRead(3) == 0 && digitalRead(6)) || 
          (digitalRead(3) == 0 && digitalRead(7)) || 
          (digitalRead(3) == 0 && digitalRead(8)) || 
          (digitalRead(3) == 0 && digitalRead(9)) 
          )
  {
    ledOn();
   
  }

}

void wire3(){
  output = B00100000;
SPI.transfer(output);
latch();
  
  if (digitalRead(4))
  {
    ledOff();
  }
  else if(
          (digitalRead(4) == 0 && digitalRead(3)) || 
          (digitalRead(4) == 0 && digitalRead(2)) ||
          (digitalRead(4) == 0 && digitalRead(5)) || 
          (digitalRead(4) == 0 && digitalRead(6)) || 
          (digitalRead(4) == 0 && digitalRead(7)) || 
          (digitalRead(4) == 0 && digitalRead(8)) || 
          (digitalRead(4) == 0 && digitalRead(9)) 
          )
  {
    ledOn();
   
  }

}

void wire4(){
  output = B00010000;
SPI.transfer(output);
latch();
  
  if (digitalRead(5))
  {
    ledOff();
  }
  else if(
          (digitalRead(5) == 0 && digitalRead(3)) || 
          (digitalRead(5) == 0 && digitalRead(4)) ||
          (digitalRead(5) == 0 && digitalRead(2)) || 
          (digitalRead(5) == 0 && digitalRead(6)) || 
          (digitalRead(5) == 0 && digitalRead(7)) || 
          (digitalRead(5) == 0 && digitalRead(8)) || 
          (digitalRead(5) == 0 && digitalRead(9)) 
          )
  {
    ledOn();
   
  }

}

void wire5(){
  output = B00001000;
SPI.transfer(output);
latch();
  
  if (digitalRead(6))
  {
    ledOff();
  }
  else if(
          (digitalRead(6) == 0 && digitalRead(3)) || 
          (digitalRead(6) == 0 && digitalRead(4)) ||
          (digitalRead(6) == 0 && digitalRead(5)) || 
          (digitalRead(6) == 0 && digitalRead(2)) || 
          (digitalRead(6) == 0 && digitalRead(7)) || 
          (digitalRead(6) == 0 && digitalRead(8)) || 
          (digitalRead(6) == 0 && digitalRead(9)) 
          )
  {
    ledOn();
   
  }

}

void wire6(){
  output = B00000100;
SPI.transfer(output);
latch();
  
  if (digitalRead(7))
  {
    ledOff();
  }
  else if(
          (digitalRead(7) == 0 && digitalRead(3)) || 
          (digitalRead(7) == 0 && digitalRead(4)) ||
          (digitalRead(7) == 0 && digitalRead(5)) || 
          (digitalRead(7) == 0 && digitalRead(6)) || 
          (digitalRead(7) == 0 && digitalRead(2)) || 
          (digitalRead(7) == 0 && digitalRead(8)) || 
          (digitalRead(7) == 0 && digitalRead(9)) 
          )
  {
    ledOn();
   
  }

}

void wire7(){
  output = B00000010;
SPI.transfer(output);
latch();
  
  if (digitalRead(8))
  {
    ledOff();
  }
  else if(
          (digitalRead(8) == 0 && digitalRead(3)) || 
          (digitalRead(8) == 0 && digitalRead(4)) ||
          (digitalRead(8) == 0 && digitalRead(5)) || 
          (digitalRead(8) == 0 && digitalRead(6)) || 
          (digitalRead(8) == 0 && digitalRead(7)) || 
          (digitalRead(8) == 0 && digitalRead(2)) || 
          (digitalRead(8) == 0 && digitalRead(9)) 
          )
  {
    ledOn();
   
  }

}

void wire8(){
  output = B00000001;
SPI.transfer(output);
latch();
  
  if (digitalRead(9))
  {
    ledOff();
  }
  else if(
          (digitalRead(9) == 0 && digitalRead(3)) || 
          (digitalRead(9) == 0 && digitalRead(4)) ||
          (digitalRead(9) == 0 && digitalRead(5)) || 
          (digitalRead(9) == 0 && digitalRead(6)) || 
          (digitalRead(9) == 0 && digitalRead(7)) || 
          (digitalRead(9) == 0 && digitalRead(8)) || 
          (digitalRead(9) == 0 && digitalRead(2)) 
          )
  {
    ledOn();
   
  }

}

