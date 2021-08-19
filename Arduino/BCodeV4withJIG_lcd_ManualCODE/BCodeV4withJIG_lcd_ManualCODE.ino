
#include <hidboot.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
//output1
int dataPIN1 = 30;
int clockPIN1 = 28;
int latchPIN1 = 26;
int buttonPIN1 = 24;
int chassisbtn1 = 31;
int chassisbtn2 = 22;
int chassisbtn3 = 40;
int buttonState1 = 0;         
int lastButtonState1 = 0;     
int buttonPushCounter1 = 1000;  

//output2
int dataPIN2 = 2;
int clockPIN2 = 3;
int latchPIN2 = 4;
int buttonPIN2 = 5;
int bodybtn1 = 6;
int bodybtn2 = 7;
int bodybtn3 = 42;
int buttonState2 = 0;         
int lastButtonState2 = 0;     
int buttonPushCounter2 = 2000;  

//output3
int dataPIN3 = 8;
int clockPIN3 = 9;
int latchPIN3 = 10;
int buttonPIN3 = 11;
int rightbtn1 = 12;
int rightbtn2 = 13;
int buttonState3 = 0;         
int lastButtonState3 = 0;     
int buttonPushCounter3 = 3000;  



char BarcodeBuffer[20];
int BarcodeBufferIndex = 0 ;                                            
boolean BarcodeComplete = false ;                                        
class KbdRptParser : public KeyboardReportParser
{protected:
void OnKeyDown  (uint8_t mod, uint8_t key);
void OnKeyUp  (uint8_t mod, uint8_t key);
void OnKeyPressed(uint8_t key);
};
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
uint8_t c = OemToAscii(mod, key);
if (c)
if (mod != 1)OnKeyPressed(c);                                      
}
void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)
{if (key==40){BarcodeComplete = true ;}}
void KbdRptParser::OnKeyPressed(uint8_t key)
{
BarcodeBuffer[BarcodeBufferIndex] = key;      
BarcodeBufferIndex ++;
}

USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
uint32_t next_time;
KbdRptParser Prs;
void setup()
{
// chassis
 pinMode(chassisbtn1, OUTPUT);
 pinMode(chassisbtn2, OUTPUT);
 pinMode(chassisbtn3, OUTPUT);
 pinMode(dataPIN1, OUTPUT);
 pinMode(clockPIN1, OUTPUT);
 pinMode(latchPIN1, OUTPUT);
 pinMode(buttonPIN1, INPUT);

//body
pinMode(bodybtn1, OUTPUT);
 pinMode(bodybtn2, OUTPUT);
 pinMode(bodybtn3, OUTPUT);
 pinMode(dataPIN2, OUTPUT);
 pinMode(clockPIN2, OUTPUT);
 pinMode(latchPIN2, OUTPUT);
 pinMode(buttonPIN2, INPUT);

 //right
pinMode(rightbtn1, OUTPUT);
 pinMode(rightbtn2, OUTPUT);
 pinMode(dataPIN3, OUTPUT);
 pinMode(clockPIN3, OUTPUT);
 pinMode(latchPIN3, OUTPUT);
 pinMode(buttonPIN3, INPUT);


 
Serial.begin( 115200 );
clear1();clear2();
#if !defined(__MIPSEL__)
while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
Serial.println("Start");
if (Usb.Init() == -1)
Serial.println("OSC did not start.");
delay( 200 );
next_time = millis() + 5000;
HidKeyboard.SetReportParser(0, &Prs);

}
void loop()
{




  
BarcodeBufferIndex = 0;
while (BarcodeComplete == false)
{
buttonState1 = digitalRead(buttonPIN1);
buttonState2 = digitalRead(buttonPIN2);
buttonState3 = digitalRead(buttonPIN3);

 if (buttonState1 != lastButtonState1) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
   buttonPushCounter1++;
   Serial.println(buttonPushCounter1);
    } 
     else{
  }
delay(50);
     }
   else{
    
  
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState1 = buttonState1;
if (buttonPushCounter1 == 0){//1
d1On();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  l1();
 
}
else if (buttonPushCounter1 == 1){//1
clear1();
 d1On();
 cc1();
 l1();
 buttonPushCounter1 = 2;
}
else if (buttonPushCounter1 == 3){//2
 d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 4;
}
else if (buttonPushCounter1 == 5){//3
 d1Off();
 cc1();
 l1();
 
 digitalWrite(chassisbtn1,0);
 digitalWrite(chassisbtn2,1);
 digitalWrite(chassisbtn3,0);
 buttonPushCounter1 = 6;
}
else if (buttonPushCounter1 == 7){//4
 d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 8;
}
else if (buttonPushCounter1 == 9){//5
 d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 10;
 
 digitalWrite(chassisbtn1,0);
 digitalWrite(chassisbtn2,0);
 digitalWrite(chassisbtn3,1);
}
else if (buttonPushCounter1 == 11){//6
 d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 12;
}
else if (buttonPushCounter1 == 13){//7
 d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 14;
}
else if (buttonPushCounter1 == 15){//8
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 16;
 }
else if (buttonPushCounter1 == 17){//9
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 18;
 }
else if (buttonPushCounter1 == 19){//10
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 20;
 }
else if (buttonPushCounter1 == 21){//11
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 22;
 }
else if (buttonPushCounter1 == 23){//12
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 24;
 }
else if (buttonPushCounter1 == 25){//13
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 26;
 }
else if (buttonPushCounter1 == 27){//14
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 28;
 }
else if (buttonPushCounter1 == 29){//15
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 30;

 }
 else if (buttonPushCounter1 == 31){//16
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 32;
 }
 else if (buttonPushCounter1 == 33){//16
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 34;
 }


 //==========================================================================================body
if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
   buttonPushCounter2++;
   Serial.println(buttonPushCounter2);
    } 
     else{
  }
delay(50);
     }
   else{
    
  
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState2 = buttonState2;
if (buttonPushCounter2 == 0){//1
d2On();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
}
else if (buttonPushCounter2 == 1){//2
 clear2();
 d2On();
 cc2();
 l2();
 buttonPushCounter2 = 2;
}
 else if (buttonPushCounter2 == 3){//3
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 4;
}
else if (buttonPushCounter2 == 5){//4
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 6;
}
else if (buttonPushCounter2 == 7){//5
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 8;
}
else if (buttonPushCounter2 == 9){//6
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 10;
}
else if (buttonPushCounter2 == 11){//7
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 12;
}
else if (buttonPushCounter2 == 13){//8
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 14;
}
else if (buttonPushCounter2 == 15){//8
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 16;
}
else if (buttonPushCounter2 == 17){//8
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 18;
 }



 //==========================================================================================body
if (buttonState3 != lastButtonState3) {
    // if the state has changed, increment the counter
    if (buttonState3 == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
   buttonPushCounter3++;
   Serial.println(buttonPushCounter3);
    } 
     else{
  }
delay(50);
     }
   else{
    
  
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState3 = buttonState3;
if (buttonPushCounter3 == 0){//1
d3On();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  l3();
}
else if (buttonPushCounter3 == 1){//2
 clear3();
 d3On();
 cc3();
 l3();
 buttonPushCounter3 = 2;
}
 else if (buttonPushCounter3 == 3){//3
 d3Off();
 cc3();
 l3();
 buttonPushCounter3 = 4;
}
else if (buttonPushCounter3 == 5){//4
 d3Off();
 cc3();
 l3();
 buttonPushCounter3 = 6;
}
else if (buttonPushCounter3 == 7){//5
 d3Off();
 cc3();
 l3();
 buttonPushCounter3 = 8;
}
else if (buttonPushCounter3 == 9){//6
 d3Off();
 cc3();
 l3();
 buttonPushCounter3 = 10;
}
else if (buttonPushCounter3 == 11){//7
 d3Off();
 cc3();
 l3();
 buttonPushCounter3 = 12;
}
else if (buttonPushCounter3 == 13){//8
 d3Off();
 cc3();
 l3();
 buttonPushCounter3 = 14;
}
else if (buttonPushCounter3 == 15){//8
 d3Off();
 cc3();
 l3();
 buttonPushCounter3 = 16;
}
else if (buttonPushCounter3 == 17){//8
d3Off();
 cc3();
 l3();
 buttonPushCounter3 = 18;
 }


//===============
Usb.Task();
}//while
BarcodeComplete = false ;
BarcodeBufferIndex --;
Serial.write(BarcodeBuffer,BarcodeBufferIndex);
Serial.write('\n');

if (
(BarcodeBuffer[0] == 'c')
 &&
(BarcodeBuffer[1] == 'h')
 &&
(BarcodeBuffer[2] == 'a')
 &&
(BarcodeBuffer[3] == 's')
 &&
(BarcodeBuffer[4] == 's')
 &&
(BarcodeBuffer[5] == 'i')
 &&
(BarcodeBuffer[6] == 's')
)
{
//================================
clear1();
 buttonPushCounter1 = 0;

 digitalWrite(chassisbtn1,1);
 digitalWrite(chassisbtn2,0);
 digitalWrite(chassisbtn3,0);
}
if (
(BarcodeBuffer[0] == 'b')
 &&
(BarcodeBuffer[1] == 'o')
 &&
(BarcodeBuffer[2] == 'd')
 &&
(BarcodeBuffer[3] == 'y')
)

{
//==================================
 clear2();
 buttonPushCounter2 = 0;

digitalWrite(bodybtn1,1);
digitalWrite(bodybtn2,0);
digitalWrite(bodybtn3,0);
 }
if (
(BarcodeBuffer[0] == 'r')
 &&
(BarcodeBuffer[1] == 'i')
 &&
(BarcodeBuffer[2] == 'g')
 &&
(BarcodeBuffer[3] == 'h')
 &&
(BarcodeBuffer[4] == 't')
)
{
//================================
clear3();
 buttonPushCounter3 = 0;

 digitalWrite(rightbtn1,1);
 digitalWrite(rightbtn2,0);
}

}//loop

void clear1()
{//chassis
d1Off();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  l1();
}
void clear2()
{
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
}
void clear3()
{
  d3Off();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();cc3();
  l3();
}
//========
void d1On()
{
  digitalWrite(dataPIN1, 1);
}
void d1Off()
{
  digitalWrite(dataPIN1, 0);
}
void cc1()
{
  digitalWrite(clockPIN1, 1);
  digitalWrite(clockPIN1, 0);
}
void l1()
{
  digitalWrite(latchPIN1, 1);
  digitalWrite(latchPIN1, 0);
}//========
void d2On()
{
  digitalWrite(dataPIN2, 1);
}

void d2Off()
{
  digitalWrite(dataPIN2, 0);
}
void cc2()
{
  digitalWrite(clockPIN2, 1);
  digitalWrite(clockPIN2, 0);
}
void l2()
{
  digitalWrite(latchPIN2, 1);
  digitalWrite(latchPIN2, 0);
}
//========
void d3On()
{
  digitalWrite(dataPIN3, 1);
}

void d3Off()
{
  digitalWrite(dataPIN3, 0);
}
void cc3()
{
  digitalWrite(clockPIN3, 1);
  digitalWrite(clockPIN3, 0);
}
void l3()
{
  digitalWrite(latchPIN3, 1);
  digitalWrite(latchPIN3, 0);
}
