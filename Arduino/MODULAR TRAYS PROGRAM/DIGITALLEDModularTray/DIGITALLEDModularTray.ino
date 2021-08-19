
#include "FastLED.h"

#define NUM_LEDS 300          //heto ang bilang ng LED
#define DATA_PIN 12
#define BUTTON_PIN 2
#define BUTTON_PIN2 4
#define BUTTON_PIN3 6
#define BUTTON_PIN4 8
#define BUTTON_PINjapan 10    //japan
#define BUTTON_PINnafta 8     //nafta
#define BRIGHTNESS 100        //Heto yung adjustment ng brightness

CRGB leds[NUM_LEDS];

int buttonPIN1 = 2;
int buttonState1 = 0;         
int lastButtonState1 = 0;     
int buttonPushCounter1 = 1000;  

int buttonPIN2 = 4;
int buttonState2 = 0;         
int lastButtonState2 = 0;     
int buttonPushCounter2 = 2000;  

int lastButtonState3 = 0;     
int buttonPushCounter3 = 3000; 

int lastButtonState4 = 0;     
int buttonPushCounter4 = 4000; 

int japan = 0;
int nafta = 0;
void setup()
{
      Serial.begin( 115200 );
      pinMode(BUTTON_PIN, INPUT);
      pinMode(BUTTON_PIN2, INPUT);
      pinMode(BUTTON_PINjapan, INPUT);
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      FastLED.setBrightness(BRIGHTNESS);

      // Startup
      
       int j=0;  
       while (j<300) {j++; leds[j] = CRGB::Blue;
       FastLED.show();
       FastLED.clear();}          

}
void loop()
{



japan = digitalRead(BUTTON_PINjapan);
nafta = digitalRead(BUTTON_PINnafta);

buttonState1 = digitalRead(buttonPIN1);   //pin 2
buttonState2 = digitalRead(buttonPIN2);   //pin 4
//==========================================================================================================     start of tray 1 japan
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

if (buttonPushCounter1 == 1){//1
             leds[1] = CRGB::Blue;
             leds[2] = CRGB::Blue;
             leds[71] = CRGB::Black;
             leds[72] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 3){//2
             leds[1] = CRGB::Black;
             leds[2] = CRGB::Black;
             leds[6] = CRGB::Blue;
             leds[7] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 5){//3
             leds[6] = CRGB::Black;
             leds[7] = CRGB::Black;
             leds[11] = CRGB::Blue;
             leds[12] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 7){//4
             leds[11] = CRGB::Black;
             leds[12] = CRGB::Black;
             leds[16] = CRGB::Blue;
             leds[17] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 9){//5
             leds[16] = CRGB::Black;
             leds[17] = CRGB::Black;
             leds[21] = CRGB::Blue;
             leds[22] = CRGB::Blue;
             FastLED.show();
   
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 11){//6
             leds[21] = CRGB::Black;
             leds[22] = CRGB::Black;
             leds[26] = CRGB::Blue;
             leds[27] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 13){//7
             leds[26] = CRGB::Black;
             leds[27] = CRGB::Black;
             leds[31] = CRGB::Blue;
             leds[32] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 15){//8
             leds[31] = CRGB::Black;
             leds[32] = CRGB::Black;
             leds[36] = CRGB::Blue;
             leds[37] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 17){//9
             leds[36] = CRGB::Black;
             leds[37] = CRGB::Black;
             leds[41] = CRGB::Blue;
             leds[42] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 19){//10
             leds[41] = CRGB::Black;
             leds[42] = CRGB::Black;
             leds[46] = CRGB::Blue;
             leds[47] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 21){//11
             leds[46] = CRGB::Black;
             leds[47] = CRGB::Black;
             leds[51] = CRGB::Blue;
             leds[52] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 23){//12
             leds[51] = CRGB::Black;
             leds[52] = CRGB::Black;
             leds[56] = CRGB::Blue;
             leds[57] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 25){//13
             leds[56] = CRGB::Black;
             leds[57] = CRGB::Black;
             leds[61] = CRGB::Blue;
             leds[62] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 27){//14
             leds[61] = CRGB::Black;
             leds[62] = CRGB::Black;
             leds[66] = CRGB::Blue;
             leds[67] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 29){//15
             leds[66] = CRGB::Black;
             leds[67] = CRGB::Black;
             leds[71] = CRGB::Blue;
             leds[72] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 31){//16
        
 buttonPushCounter1 = 1;
}

//==========================================================================================================     start of tray 2 japan
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
if (buttonPushCounter2 == 1){//1

             leds[75] = CRGB::Blue;
             leds[76] = CRGB::Blue;
             leds[145] = CRGB::Black;
             leds[146] = CRGB::Black;
             FastLED.show();     
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 3){//2
             leds[75] = CRGB::Black;
             leds[76] = CRGB::Black;
             leds[80] = CRGB::Blue;
             leds[81] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 5){//3
             leds[80] = CRGB::Black;
             leds[81] = CRGB::Black;
             leds[85] = CRGB::Blue;
             leds[86] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 7){//4
             leds[85] = CRGB::Black;
             leds[86] = CRGB::Black;
             leds[90] = CRGB::Blue;
             leds[91] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 9){//5
             leds[90] = CRGB::Black;
             leds[91] = CRGB::Black;
             leds[95] = CRGB::Blue;
             leds[96] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 11){//6
             leds[95] = CRGB::Black;
             leds[96] = CRGB::Black;
             leds[100] = CRGB::Blue;
             leds[101] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 13){//7
             leds[100] = CRGB::Black;
             leds[101] = CRGB::Black;
             leds[105] = CRGB::Blue;
             leds[106] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 15){//8
             leds[105] = CRGB::Black;
             leds[106] = CRGB::Black;
             leds[110] = CRGB::Blue;
             leds[111] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 17){//9
             leds[110] = CRGB::Black;
             leds[111] = CRGB::Black;
             leds[115] = CRGB::Blue;
             leds[116] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 19){//10
             leds[115] = CRGB::Black;
             leds[116] = CRGB::Black;
             leds[120] = CRGB::Blue;
             leds[121] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 21){//11
             leds[120] = CRGB::Black;
             leds[121] = CRGB::Black;
             leds[125] = CRGB::Blue;
             leds[126] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 23){//12
             leds[125] = CRGB::Black;
             leds[126] = CRGB::Black;
             leds[130] = CRGB::Blue;
             leds[131] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 25){//13
             leds[130] = CRGB::Black;
             leds[131] = CRGB::Black;
             leds[135] = CRGB::Blue;
             leds[136] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 27){//14
             leds[135] = CRGB::Black;
             leds[136] = CRGB::Black;
             leds[140] = CRGB::Blue;
             leds[141] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 29){//15
             leds[140] = CRGB::Black;
             leds[141] = CRGB::Black;
             leds[145] = CRGB::Blue;
             leds[146] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 31){//16
  
 buttonPushCounter2 = 1;
}

//==========================================================================================================     start of tray 1 nafta
 if (buttonState1 != lastButtonState3) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {
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
  lastButtonState3 = buttonState1;

if (buttonPushCounter3 == 1){//1
             leds[150] = CRGB::Red;
             leds[151] = CRGB::Red;
             leds[21] = CRGB::Black;
             leds[22] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 3){//2
             leds[16] = CRGB::Red;
             leds[17] = CRGB::Red;
             leds[21] = CRGB::Black;
             leds[22] = CRGB::Black;
             FastLED.show();
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 5){//3
             leds[11] = CRGB::Red;
             leds[12] = CRGB::Red;
             leds[16] = CRGB::Black;
             leds[17] = CRGB::Black;
             FastLED.show();
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 7){//4
             leds[6] = CRGB::Red;
             leds[7] = CRGB::Red;
             leds[11] = CRGB::Black;
             leds[12] = CRGB::Black;
             FastLED.show();
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 9){//5
             leds[1] = CRGB::Red;
             leds[2] = CRGB::Red;
             leds[6] = CRGB::Black;
             leds[7] = CRGB::Black;
             FastLED.show();
   
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6  
 buttonPushCounter3++;
}

//==========================================================================================================     start of tray 2 nafta
if (buttonState2 != lastButtonState4) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
   buttonPushCounter4++;
   Serial.println(buttonPushCounter4);
    } 
     else{
  }
delay(50);
     }
   else{
    
  
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState4 = buttonState2;
if (buttonPushCounter4 == 1){//1

             
             leds[31] = CRGB::Black;
             leds[32] = CRGB::Black;
             leds[51] = CRGB::Red;
             leds[52] = CRGB::Red;
             FastLED.show();     
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 3){//2
             leds[46] = CRGB::Red;
             leds[47] = CRGB::Red;
             leds[51] = CRGB::Black;
             leds[52] = CRGB::Black;             
             FastLED.show();
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 5){//3
             leds[41] = CRGB::Red;
             leds[42] = CRGB::Red;  
             leds[46] = CRGB::Black;
             leds[47] = CRGB::Black;
             FastLED.show();
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 7){//4
             leds[36] = CRGB::Red;
             leds[37] = CRGB::Red;
             leds[41] = CRGB::Black;
             leds[42] = CRGB::Black;
             FastLED.show();
  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 9){//5
             leds[31] = CRGB::Red;
             leds[32] = CRGB::Red;
             leds[36] = CRGB::Black;
             leds[37] = CRGB::Black;
             FastLED.show();
  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 11){//6
  
  
  
 buttonPushCounter4 = 1;
}
//==========================================================================================================     products
 if (japan == HIGH)
 {
  FastLED.clear();
  buttonPushCounter1 = 1;
  buttonPushCounter2 = 1;
  buttonPushCounter3 = 3000;
  buttonPushCounter4 = 4000;
  delay(500);
 }

 if (nafta == HIGH)
  {
  FastLED.clear();
  buttonPushCounter1 = 1000;
  buttonPushCounter2 = 2000;
  buttonPushCounter3 = 1;
  buttonPushCounter4 = 1;
  delay(500);
  }
}

