
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
/*
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
*/


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
/*
 //right
pinMode(rightbtn1, OUTPUT);
 pinMode(rightbtn2, OUTPUT);
 pinMode(dataPIN3, OUTPUT);
 pinMode(clockPIN3, OUTPUT);
 pinMode(latchPIN3, OUTPUT);
 pinMode(buttonPIN3, INPUT);
*/

 
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
//buttonState3 = digitalRead(buttonPIN3);

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
if (buttonPushCounter1 == 500){//1
clear1();
d1On();
for (int x = 0; x < 149; x++)
{
  cc1();
}

  l1();
 buttonPushCounter1 = 0;
 
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
 else if (buttonPushCounter1 == 33){//17
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 34;
 }
  else if (buttonPushCounter1 == 35){//18
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 36;
 }
  else if (buttonPushCounter1 == 37){//19
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 38;
 }
  else if (buttonPushCounter1 == 39){//20
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 40;
 }
  else if (buttonPushCounter1 == 41){//21
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 42;
 }
  else if (buttonPushCounter1 == 43){//22
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 44;
 }
  else if (buttonPushCounter1 == 45){//23
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 46;
 }
  else if (buttonPushCounter1 == 47){//24
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 48;
 }
  else if (buttonPushCounter1 == 49){//25
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 50;
 }
  else if (buttonPushCounter1 == 51){//26
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 52;
 }
  else if (buttonPushCounter1 == 53){//27
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 54;
 }
  else if (buttonPushCounter1 == 55){//28
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 56;
 }
  else if (buttonPushCounter1 == 57){//29
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 58;
 }
  else if (buttonPushCounter1 == 59){//30
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 60;
 }
  else if (buttonPushCounter1 == 61){//31
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 62;
 }
  else if (buttonPushCounter1 == 63){//32
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 64;
 }
  else if (buttonPushCounter1 == 65){//33
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 66;
 }
  else if (buttonPushCounter1 == 67){//34
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 68;
 }
  else if (buttonPushCounter1 == 69){//35
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 70;
 }
  else if (buttonPushCounter1 == 71){//36
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 72;
 }
  else if (buttonPushCounter1 == 73){//37
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 74;
 }
  else if (buttonPushCounter1 == 75){//38
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 76;
 }
  else if (buttonPushCounter1 == 77){//39
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 78;
 }
  else if (buttonPushCounter1 == 79){//40
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 80;
 }
  else if (buttonPushCounter1 == 81){//41
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 82;
 }
  else if (buttonPushCounter1 == 83){//42
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 84;
 }
  else if (buttonPushCounter1 == 85){//43
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 86;
 }
  else if (buttonPushCounter1 == 87){//44
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 88;
 }
  else if (buttonPushCounter1 == 89){//45
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 90;
 }
  else if (buttonPushCounter1 == 91){//46
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 92;
 }
  else if (buttonPushCounter1 == 93){//47
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 94;
 }
  else if (buttonPushCounter1 == 95){//48
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 96;
 }
  else if (buttonPushCounter1 == 97){//49
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 98;
 }
 //51 -------
  else if (buttonPushCounter1 == 99){//50
d1Off();
 cc1();
 cc1();
 l1();
 digitalWrite(chassisbtn1,0);
 digitalWrite(chassisbtn2,1);
 digitalWrite(bodybtn1,0);
 buttonPushCounter1 = 100;
 }
  else if (buttonPushCounter1 == 101){//51
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 102;
 }
  else if (buttonPushCounter1 == 103){//52
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 104;
 }
  else if (buttonPushCounter1 == 105){//53
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 106;
 }
  else if (buttonPushCounter1 == 107){//54
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 108;
 }
  else if (buttonPushCounter1 == 109){//55
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 110;
 }
  else if (buttonPushCounter1 == 111){//56
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 112;
 }
  else if (buttonPushCounter1 == 113){//57
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 114;
 }
  else if (buttonPushCounter1 == 115){//58
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 116;
 }
  else if (buttonPushCounter1 == 117){//59
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 118;
 }
  else if (buttonPushCounter1 == 119){//60
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 120;
 }
  else if (buttonPushCounter1 == 121){//61
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 122;
 }
  else if (buttonPushCounter1 == 123){//62
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 124;
 }
  else if (buttonPushCounter1 == 125){//63
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 126;
 }
  else if (buttonPushCounter1 == 127){//64
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 128;
 }
  else if (buttonPushCounter1 == 129){//65
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 130;
 }
  else if (buttonPushCounter1 == 131){//66
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 132;
 }
  else if (buttonPushCounter1 == 133){//67
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 134;
 }
  else if (buttonPushCounter1 == 135){//68
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 136;
 }
  else if (buttonPushCounter1 == 137){//69
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 138;
 }
  else if (buttonPushCounter1 == 139){//70
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 140;
 }
  else if (buttonPushCounter1 == 141){//71
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 142;
 }
  else if (buttonPushCounter1 == 143){//72
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 144;
 }
  else if (buttonPushCounter1 == 145){//73
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 146;
 }
  else if (buttonPushCounter1 == 147){//74
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 148;
 }
  else if (buttonPushCounter1 == 149){//75
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 150;
 }
  else if (buttonPushCounter1 == 151){//76
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 152;
 }
  else if (buttonPushCounter1 == 153){//77
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 154;
 }
  else if (buttonPushCounter1 == 155){//78
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 156;
 }
  else if (buttonPushCounter1 == 157){//79
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 158;
 }
  else if (buttonPushCounter1 == 159){//80
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 160;
 }
  else if (buttonPushCounter1 == 161){//81
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 162;
 }
  else if (buttonPushCounter1 == 163){//82
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 164;
 }
  else if (buttonPushCounter1 == 165){//83
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 166;
 }
  else if (buttonPushCounter1 == 167){//84
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 168;
 }
  else if (buttonPushCounter1 == 169){//85
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 170;
 }
  else if (buttonPushCounter1 == 171){//86
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 172;
 }
  else if (buttonPushCounter1 == 173){//87
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 174;
 }
  else if (buttonPushCounter1 == 175){//88
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 176;
 }
  else if (buttonPushCounter1 == 177){//89
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 178;
 }
  else if (buttonPushCounter1 == 179){//90
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 180;
 }
  else if (buttonPushCounter1 == 181){//91
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 182;
 }
  else if (buttonPushCounter1 == 183){//92
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 184;
 }
  else if (buttonPushCounter1 == 185){//93
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 186;
 }
  else if (buttonPushCounter1 == 187){//94
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 188;
 }
  else if (buttonPushCounter1 == 189){//95
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 190;
 }
  else if (buttonPushCounter1 == 191){//96
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 192;
 }
  else if (buttonPushCounter1 == 193){//97
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 194;
 }
  else if (buttonPushCounter1 == 195){//98
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 196;
 }
  else if (buttonPushCounter1 == 197){//99
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 198;
 }
  else if (buttonPushCounter1 == 199){//100
d1Off();
 cc1();
 l1();
 digitalWrite(chassisbtn1,0);
 digitalWrite(chassisbtn2,0);
 digitalWrite(bodybtn1,1);
 buttonPushCounter1 = 200;
 }
  else if (buttonPushCounter1 == 201){//101
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 202;
 }
  else if (buttonPushCounter1 == 203){//102
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 204;
 }
  else if (buttonPushCounter1 == 205){//103
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 206;
 }
  else if (buttonPushCounter1 == 207){//104
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 208;
 }
  else if (buttonPushCounter1 == 209){//105
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 210;
 }
  else if (buttonPushCounter1 == 211){//106
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 212;
 }
  else if (buttonPushCounter1 == 213){//107
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 214;
 }
  else if (buttonPushCounter1 == 215){//108
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 216;
 }
  else if (buttonPushCounter1 == 217){//109
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 218;
 }
  else if (buttonPushCounter1 == 219){//110
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 220;
 }
  else if (buttonPushCounter1 == 221){//111
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 222;
 }
  else if (buttonPushCounter1 == 223){//112
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 224;
 }
  else if (buttonPushCounter1 == 225){//113
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 226;
 }
  else if (buttonPushCounter1 == 227){//114
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 228;
 }
  else if (buttonPushCounter1 == 229){//115
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 230;
 }
  else if (buttonPushCounter1 == 231){//116
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 232;
 }
  else if (buttonPushCounter1 == 233){//117
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 234;
 }
  else if (buttonPushCounter1 == 235){//118
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 236;
 }
  else if (buttonPushCounter1 == 237){//119
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 238;
 }
  else if (buttonPushCounter1 == 239){//120
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 240;
 }
  else if (buttonPushCounter1 == 241){//121
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 242;
 }
  else if (buttonPushCounter1 == 243){//122
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 244;
 }
  else if (buttonPushCounter1 == 245){//123
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 246;
 }
  else if (buttonPushCounter1 == 247){//124
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 248;
 }
  else if (buttonPushCounter1 == 249){//125
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 250;
 }
  else if (buttonPushCounter1 == 251){//126
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 252;
 }
  else if (buttonPushCounter1 == 253){//127
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 254;
 }
  else if (buttonPushCounter1 == 255){//128
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 256;
 }
  else if (buttonPushCounter1 == 257){//129
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 258;
 }
  else if (buttonPushCounter1 == 259){//130
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 260;
 }
  else if (buttonPushCounter1 == 261){//131
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 262;
 }
  else if (buttonPushCounter1 == 263){//132
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 264;
 }
  else if (buttonPushCounter1 == 265){//133
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 266;
 }
  else if (buttonPushCounter1 == 267){//134
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 268;
 }
  else if (buttonPushCounter1 == 269){//135
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 270;
 }
  else if (buttonPushCounter1 == 271){//136
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 272;
 }
  else if (buttonPushCounter1 == 273){//137
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 274;
 }
  else if (buttonPushCounter1 == 275){//138
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 276;
 }
  else if (buttonPushCounter1 == 277){//139
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 278;
 }
  else if (buttonPushCounter1 == 279){//140
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 280;
 }
  else if (buttonPushCounter1 == 281){//141
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 282;
 }
  else if (buttonPushCounter1 == 283){//142
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 284;
 }
  else if (buttonPushCounter1 == 285){//143
d1Off();
  cc1();
 l1();
 buttonPushCounter1 = 286;
 }
  else if (buttonPushCounter1 == 287){//144
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 288;
 }
  else if (buttonPushCounter1 == 289){//145
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 290;
 }
  else if (buttonPushCounter1 == 291){//146
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 292;
 }
 else if (buttonPushCounter1 == 293){//146
d1Off();
 cc1();
 l1();
 buttonPushCounter1 = 294;
 }
  else if (buttonPushCounter1 == 295){//147
 clear1();
 digitalWrite(chassisbtn1,0);
 digitalWrite(chassisbtn2,0);
 digitalWrite(bodybtn1,0);
 d1On();
 cc1();
 l1();
 d1Off();
 for (int y = 0; y < 150; y++)
 {
  cc1();
 }
  l1();
  delay(5000);
  d1Off();cc1();l1();
 buttonPushCounter1 = 1000;
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
if (buttonPushCounter2 == 500){//1
d2On();
 for (int y = 0; y < 150; y++)
 {
  cc2();
 }
  l2();
  
 buttonPushCounter2 = 0;
}
else if (buttonPushCounter2 == 1){//1
clear2();
 d2On();
 cc2();
 l2();
 buttonPushCounter2 = 2;
}
else if (buttonPushCounter2 == 3){//2
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 4;
}
else if (buttonPushCounter2 == 5){//3
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 6;
}
else if (buttonPushCounter2 == 7){//4
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 8;
}
else if (buttonPushCounter2 == 9){//5
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 10;
}
else if (buttonPushCounter2 == 11){//6
 d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 12;
}
else if (buttonPushCounter2 == 13){//7
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
else if (buttonPushCounter2 == 17){//9
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 18;
 }
else if (buttonPushCounter2 == 19){//10
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 20;
 }
else if (buttonPushCounter2 == 21){//11
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 22;
 }
else if (buttonPushCounter2 == 23){//12
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 24;
 }
else if (buttonPushCounter2 == 25){//13
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 26;
 }
else if (buttonPushCounter2 == 27){//14
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 28;
 }
else if (buttonPushCounter2 == 29){//15
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 30;

 }
 else if (buttonPushCounter2 == 31){//16
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 32;
 }
 else if (buttonPushCounter2 == 33){//17
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 34;
 }
  else if (buttonPushCounter2 == 35){//18
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 36;
 }
  else if (buttonPushCounter2 == 37){//19
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 38;
 }
  else if (buttonPushCounter2 == 39){//20
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 40;
 }
  else if (buttonPushCounter2 == 41){//21
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 42;
 }
  else if (buttonPushCounter2 == 43){//22
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 44;
 }
  else if (buttonPushCounter2 == 45){//23
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 46;
 }
  else if (buttonPushCounter2 == 47){//24
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 48;
 }
  else if (buttonPushCounter2 == 49){//25
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 50;
 }
  else if (buttonPushCounter2 == 51){//26
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 52;
 }
  else if (buttonPushCounter2 == 53){//27
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 54;
 }
  else if (buttonPushCounter2 == 55){//28
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 56;
 }
  else if (buttonPushCounter2 == 57){//29
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 58;
 }
  else if (buttonPushCounter2 == 59){//30
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 60;
 }
  else if (buttonPushCounter2 == 61){//31
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 62;
 }
  else if (buttonPushCounter2 == 63){//32
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 64;
 }
  else if (buttonPushCounter2 == 65){//33
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 66;
 }
  else if (buttonPushCounter2 == 67){//34
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 68;
 }
  else if (buttonPushCounter2 == 69){//35
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 70;
 }
  else if (buttonPushCounter2 == 71){//36
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 72;
 }
  else if (buttonPushCounter2 == 73){//37
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 74;
 }
  else if (buttonPushCounter2 == 75){//38
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 76;
 }
  else if (buttonPushCounter2 == 77){//39
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 78;
 }
  else if (buttonPushCounter2 == 79){//40
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 80;
 }
  else if (buttonPushCounter2 == 81){//41
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 82;
 }
  else if (buttonPushCounter2 == 83){//42
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 84;
 }
  else if (buttonPushCounter2 == 85){//43
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 86;
 }
  else if (buttonPushCounter2 == 87){//44
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 88;
 }
  else if (buttonPushCounter2 == 89){//45
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 90;
 }
  else if (buttonPushCounter2 == 91){//46
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 92;
 }
  else if (buttonPushCounter2 == 93){//47
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 94;
 }
  else if (buttonPushCounter2 == 95){//48
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 96;
 }
  else if (buttonPushCounter2 == 97){//49
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 98;
 }
 //51------
  else if (buttonPushCounter2 == 99){//50
d2Off();
 cc2();
 cc2();
 l2();
 digitalWrite(chassisbtn1,0);
 digitalWrite(chassisbtn2,1);
 digitalWrite(bodybtn1,0);
 buttonPushCounter2 = 100;
 }
  else if (buttonPushCounter2 == 101){//51
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 102;
 }
  else if (buttonPushCounter2 == 103){//52
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 104;
 }
  else if (buttonPushCounter2 == 105){//53
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 106;
 }
  else if (buttonPushCounter2 == 107){//54
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 108;
 }
  else if (buttonPushCounter2 == 109){//55
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 110;
 }
  else if (buttonPushCounter2 == 111){//56
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 112;
 }
  else if (buttonPushCounter2 == 113){//57
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 114;
 }
  else if (buttonPushCounter2 == 115){//58
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 116;
 }
  else if (buttonPushCounter2 == 117){//59
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 118;
 }
  else if (buttonPushCounter2 == 119){//60
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 120;
 }
  else if (buttonPushCounter2 == 121){//61
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 122;
 }
  else if (buttonPushCounter2 == 123){//62
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 124;
 }
  else if (buttonPushCounter2 == 125){//63
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 126;
 }
  else if (buttonPushCounter2 == 127){//64
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 128;
 }
  else if (buttonPushCounter2 == 129){//65
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 130;
 }
  else if (buttonPushCounter2 == 131){//66
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 132;
 }
  else if (buttonPushCounter2 == 133){//67
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 134;
 }
  else if (buttonPushCounter2 == 135){//68
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 136;
 }
  else if (buttonPushCounter2 == 137){//69
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 138;
 }
  else if (buttonPushCounter2 == 139){//70
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 140;
 }
  else if (buttonPushCounter2 == 141){//71
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 142;
 }
  else if (buttonPushCounter2 == 143){//72
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 144;
 }
  else if (buttonPushCounter2 == 145){//73
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 146;
 }
  else if (buttonPushCounter2 == 147){//74
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 148;
 }
  else if (buttonPushCounter2 == 149){//75
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 150;
 }
  else if (buttonPushCounter2 == 151){//76
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 152;
 }
  else if (buttonPushCounter2 == 153){//77
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 154;
 }
  else if (buttonPushCounter2 == 155){//78
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 156;
 }
  else if (buttonPushCounter2 == 157){//79
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 158;
 }
  else if (buttonPushCounter2 == 159){//80
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 160;
 }
  else if (buttonPushCounter2 == 161){//81
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 162;
 }
  else if (buttonPushCounter2 == 163){//82
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 164;
 }
  else if (buttonPushCounter2 == 165){//83
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 166;
 }
  else if (buttonPushCounter2 == 167){//84
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 168;
 }
  else if (buttonPushCounter2 == 169){//85
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 170;
 }
  else if (buttonPushCounter2 == 171){//86
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 172;
 }
  else if (buttonPushCounter2 == 173){//87
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 174;
 }
  else if (buttonPushCounter2 == 175){//88
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 176;
 }
  else if (buttonPushCounter2 == 177){//89
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 178;
 }
  else if (buttonPushCounter2 == 179){//90
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 180;
 }
  else if (buttonPushCounter2 == 181){//91
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 182;
 }
  else if (buttonPushCounter2 == 183){//92
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 184;
 }
  else if (buttonPushCounter2 == 185){//93
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 186;
 }
  else if (buttonPushCounter2 == 187){//94
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 188;
 }
  else if (buttonPushCounter2 == 189){//95
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 190;
 }
  else if (buttonPushCounter2 == 191){//96
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 192;
 }
  else if (buttonPushCounter2 == 193){//97
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 194;
 }
  else if (buttonPushCounter2 == 195){//98
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 196;
 }
  else if (buttonPushCounter2 == 197){//99
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 198;
 }
  else if (buttonPushCounter2 == 199){//100
d2Off();
 cc2();
 l2();
 digitalWrite(chassisbtn1,0);
 digitalWrite(chassisbtn2,0);
 digitalWrite(bodybtn1,1);
 buttonPushCounter2 = 200;
 }
  else if (buttonPushCounter2 == 201){//101
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 202;
 }
  else if (buttonPushCounter2 == 203){//102
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 204;
 }
  else if (buttonPushCounter2 == 205){//103
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 206;
 }
  else if (buttonPushCounter2 == 207){//104
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 208;
 }
  else if (buttonPushCounter2 == 209){//105
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 210;
 }
  else if (buttonPushCounter2 == 211){//106
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 212;
 }
  else if (buttonPushCounter2 == 213){//107
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 214;
 }
  else if (buttonPushCounter2 == 215){//108
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 216;
 }
  else if (buttonPushCounter2 == 217){//109
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 218;
 }
  else if (buttonPushCounter2 == 219){//110
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 220;
 }
  else if (buttonPushCounter2 == 221){//111
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 222;
 }
  else if (buttonPushCounter2 == 223){//112
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 224;
 }
  else if (buttonPushCounter2 == 225){//113
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 226;
 }
  else if (buttonPushCounter2 == 227){//114
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 228;
 }
  else if (buttonPushCounter2 == 229){//115
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 230;
 }
  else if (buttonPushCounter2 == 231){//116
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 232;
 }
  else if (buttonPushCounter2 == 233){//117
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 234;
 }
  else if (buttonPushCounter2 == 235){//118
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 236;
 }
  else if (buttonPushCounter2 == 237){//119
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 238;
 }
  else if (buttonPushCounter2 == 239){//120
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 240;
 }
  else if (buttonPushCounter2 == 241){//121
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 242;
 }
  else if (buttonPushCounter2 == 243){//122
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 244;
 }
  else if (buttonPushCounter2 == 245){//123
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 246;
 }
  else if (buttonPushCounter2 == 247){//124
d2Off();
 cc2();
 l2();
 buttonPushCounter2 = 250;
 }
  else if (buttonPushCounter2 == 251){//126
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 252;
 }
  else if (buttonPushCounter2 == 253){//127
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 254;
 }
  else if (buttonPushCounter2 == 255){//128
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 256;
 }
  else if (buttonPushCounter2 == 257){//129
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 258;
 }
  else if (buttonPushCounter2 == 259){//130
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 260;
 }
  else if (buttonPushCounter2 == 261){//131
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 262;
 }
  else if (buttonPushCounter2 == 263){//132
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 264;
 }
  else if (buttonPushCounter2 == 265){//133
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 266;
 }
  else if (buttonPushCounter2 == 267){//134
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 268;
 }
  else if (buttonPushCounter2 == 269){//135
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 270;
 }
  else if (buttonPushCounter2 == 271){//136
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 272;
 }
  else if (buttonPushCounter2 == 273){//137
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 274;
 }
  else if (buttonPushCounter2 == 275){//138
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 276;
 }
  else if (buttonPushCounter2 == 277){//139
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 278;
 }
  else if (buttonPushCounter2 == 279){//140
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 280;
 }
  else if (buttonPushCounter2 == 281){//141
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 282;
 }
  else if (buttonPushCounter2 == 283){//142
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 284;
 }
  else if (buttonPushCounter2 == 285){//143
clear2();
d2On();
  cc2();
  l2();
  d2Off();
 cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 286;
 }
  else if (buttonPushCounter2 == 287){//144
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 288;
 }
  else if (buttonPushCounter2 == 289){//145
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 290;
 }
  else if (buttonPushCounter2 == 291){//146
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 292;
 }
  else if (buttonPushCounter2 == 293){//147
clear2();
d2On();
  cc2();
  l2();
  d2Off();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();
  l2();
 buttonPushCounter2 = 294;
 }
  else if (buttonPushCounter2 == 295){//148
 clear2();
 clear1();
 digitalWrite(chassisbtn1,0);
 digitalWrite(chassisbtn2,0);
 digitalWrite(bodybtn1,0);
 d1On();
 cc1();
 l1();
 d1Off();
 for (int y = 0; y < 150; y++)
 {
  cc1();
 }
  l1();
  delay(5000);
  d1Off();cc1();l1();
 buttonPushCounter2 = 2000;
 }


/*
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

*/
//===============
Usb.Task();
}//while
BarcodeComplete = false ;
BarcodeBufferIndex --;
Serial.write(BarcodeBuffer,BarcodeBufferIndex);
Serial.write('\n');

if (
(BarcodeBuffer[0] == 'n')
 &&
(BarcodeBuffer[1] == 'a')
 &&
(BarcodeBuffer[2] == 'f')
 &&
(BarcodeBuffer[3] == 't')
 &&
(BarcodeBuffer[4] == 'a')
)
{
//================================
clear1();

 if ( buttonPushCounter2 > 1999)
 {buttonPushCounter1 = 500;

digitalWrite(chassisbtn1,1);
 digitalWrite(chassisbtn2,0);
 digitalWrite(bodybtn1,0);
 }
 else {
  goto ex;
 }
}
if (/*
(BarcodeBuffer[0] == 'b')
 &&
(BarcodeBuffer[1] == 'o')
 &&
(BarcodeBuffer[2] == 'd')
 &&
(BarcodeBuffer[3] == 'y')*/
(BarcodeBuffer[0] == 'j')
 &&
(BarcodeBuffer[1] == 'a')
 &&
(BarcodeBuffer[2] == 'p')
 &&
(BarcodeBuffer[3] == 'a')
 &&
(BarcodeBuffer[4] == 'n')
)

{
//==================================
 clear2();

 if ( buttonPushCounter1 > 999)
 {buttonPushCounter2 = 500;

digitalWrite(chassisbtn1,1);
 digitalWrite(chassisbtn2,0);
 digitalWrite(bodybtn1,0);
 }
 else {
  goto ex;
 }
 }
/*if (
(BarcodeBuffer[0] == 't')
 &&
(BarcodeBuffer[1] == 'e')
 &&
(BarcodeBuffer[2] == 's')
 &&
(BarcodeBuffer[3] == 't')
)
{
//================================
d1On();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();cc1();
  l1();
  d2On();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();cc2();
  l2();
  delay(300);
  clear1();
  clear2();
  //======
  d1On();cc1();l1();
  d2On();cc2();l2();

  for (int i = 0; i < 151; i++)
  {
    d1Off();cc1();l1();
    
    d2Off();cc2();l2();delay(150);
  }
  buttonPushCounter1 = 1000;
  buttonPushCounter2 = 2000;
}*/

ex:;
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
  cc2();
  l2();
}
/*
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
*/
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
  delay(100);
  digitalWrite(clockPIN1, 0);
}
void l1()
{
  digitalWrite(latchPIN1, 1);
  delay(100);
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
  delay(100);
  digitalWrite(clockPIN2, 0);
  delay(100);
}
void l2()
{
  digitalWrite(latchPIN2, 1);
  delay(100);
  digitalWrite(latchPIN2, 0);
  delay(100);
}
/*
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
}*/
