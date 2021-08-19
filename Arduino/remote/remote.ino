/*
  Serial Event example
 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and 
 clears it.
 
 A good test for this is to try it with a GPS receiver 
 that sends out NMEA 0183 sentences. 
 
 Created 9 May 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */

#include <SoftwareSerial.h> //Serial library
SoftwareSerial bt (5,6);  //RX, TX (Switched on the Bluetooth - RX -> TX | TX -> RX)
int Received=0;
void setup() {
  // initialize serial:
  bt.begin(9600);
  pinMode(8,OUTPUT);
}

void loop() {
  // print the string when a newline arrives:
  
    if(bt.available()>0)
 { 
    Received = bt.read();
    
 }
   
    if (bt.read() == '1')
    {
      digitalWrite(8,1);
      bt.println(bt.read());
    }
   
    if (bt.read() == '9')
    {
      digitalWrite(8,0);
    }
}




