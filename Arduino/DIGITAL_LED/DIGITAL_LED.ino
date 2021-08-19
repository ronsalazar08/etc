#include "FastLED.h"

#define NUM_LEDS 300      //heto ang bilang ng LED
#define DATA_PIN 12
#define BUTTON_PIN 2
#define BUTTON_PIN2 4
#define BUTTON_PIN3 6
#define BUTTON_PIN4 8
#define BUTTON_PINjapan 10    //japan
#define BRIGHTNESS 100    //Heto yung adjustment ng brightness

CRGB leds[NUM_LEDS];

bool oldState = HIGH;
int showType = 0;

bool oldState2 = HIGH;
int showType2 = 0;

bool oldStatejapan = LOW;

int x = 0;

void setup() { 
      Serial.begin(115200);
     pinMode(BUTTON_PIN, INPUT);
      pinMode(BUTTON_PIN2, INPUT);
       pinMode(BUTTON_PINjapan, INPUT);
  	  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);


      // Startup lang 
      
       int j=0;  
       while (j<300) {j++; leds[j] = CRGB::Blue;  FastLED.show();
       FastLED.clear();}          
           
       //int k=0;
      // while (k<299){k++; leds[k] = CRGB::Green;  FastLED.show();
      // FastLED.clear();}

      // int l=0;
      // while (l<299){l++; leds[l] = CRGB::Red;    FastLED.show();
      // FastLED.clear();} 
         
                 
     //  int m=0;
     //  while (m<299){m++; leds[m] = CRGB::White;  FastLED.show();
     //  FastLED.clear();} 
              
      
}
void loop() { 

  
  
   bool newState = digitalRead(BUTTON_PIN);
   bool japan = digitalRead(BUTTON_PINjapan);






if (japan == HIGH) {
   
    x = 1;
 showType=1;           //heto yung saan magsisimula umilaw yung LED
               startShow(showType);
            }
 

   if (newState == LOW && oldState == HIGH && x == 1)
       {delay(20); newState = digitalRead(BUTTON_PIN);
          if (newState == LOW) {showType++; 
          if (showType > 5)         //heto yung ilang beses pipindot ng button bago umulit sa loop ng button
               showType=1;           //heto yung saan magsisimula umilaw yung LED
               startShow(showType);}
        }
   oldState = newState;





   bool newState2 = digitalRead(BUTTON_PIN2);

   if (newState2 == LOW && oldState2 == HIGH && x == 1)
       {
        delay(20); newState2 = digitalRead(BUTTON_PIN2);
          if (newState2 == LOW) 
          {
            showType2++; 
            if (showType2 > 5)         //heto yung ilang beses pipindot ng button bago umulit sa loop ng button
               showType2=1;           //heto yung saan magsisimula umilaw yung LED
               startShow2(showType2);
               }
        }
   oldState2 = newState2;
}





void startShow(int i) {
             

   FastLED.setBrightness(BRIGHTNESS);    //dito lang sa loop na ito na-adjust yung brightness
 


   //Value ng LED
   
 
switch(i){

    
     case 1: leds[1] = CRGB::Blue;
             leds[2] = CRGB::Blue;
             leds[21] = CRGB::Black;
             leds[22] = CRGB::Black;
             FastLED.show();          
             break; 
             
    case 2:  leds[1] = CRGB::Black;
             leds[2] = CRGB::Black;
             leds[3] = CRGB::Black;
             leds[4] = CRGB::Black;
             leds[5] = CRGB::Black;
             leds[6] = CRGB::Blue;
             leds[7] = CRGB::Blue;
             FastLED.show();
             break;

    case 3:  leds[6] = CRGB::Black;
             leds[7] = CRGB::Black;
             leds[8] = CRGB::Black;
             leds[9] = CRGB::Black;
             leds[10] = CRGB::Black;
             leds[11] = CRGB::Blue;
             leds[12] = CRGB::Blue;
             FastLED.show();
             break;       

    case 4:  leds[11] = CRGB::Black;
             leds[12] = CRGB::Black;
             leds[13] = CRGB::Black;
             leds[14] = CRGB::Black;
             leds[15] = CRGB::Black;
             leds[16] = CRGB::Blue;
             leds[17] = CRGB::Blue;
             FastLED.show();
             break;  
                           
    case 5:  leds[16] = CRGB::Black;
             leds[17] = CRGB::Black;
             leds[18] = CRGB::Black;
             leds[19] = CRGB::Black;
             leds[20] = CRGB::Black;
             leds[21] = CRGB::Blue;
             leds[22] = CRGB::Blue;
             FastLED.show();
             break;                
}
}




void startShow2(int z) {
             

   FastLED.setBrightness(BRIGHTNESS);    //dito lang sa loop na ito na-adjust yung brightness
 


   //Value ng LED
   
 
switch(z){

    
    case 1:  leds[31] = CRGB::Red;
             leds[32] = CRGB::Red;
             leds[51] = CRGB::Black;
             leds[52] = CRGB::Black;
             FastLED.show();          
             break; 
    case 2:  leds[31] = CRGB::Black;
             leds[32] = CRGB::Black;
             leds[33] = CRGB::Black;
             leds[34] = CRGB::Black;
             leds[35] = CRGB::Black;
             leds[36] = CRGB::Red;
             leds[37] = CRGB::Red;
             FastLED.show();
             break;

    case 3:  leds[36] = CRGB::Black;
             leds[37] = CRGB::Black;
             leds[38] = CRGB::Black;
             leds[39] = CRGB::Black;
             leds[40] = CRGB::Black;
             leds[41] = CRGB::Red;
             leds[42] = CRGB::Red;
             FastLED.show();
             break;       

    case 4:  leds[41] = CRGB::Black;
             leds[42] = CRGB::Black;
             leds[43] = CRGB::Black;
             leds[44] = CRGB::Black;
             leds[45] = CRGB::Black;
             leds[46] = CRGB::Red;
             leds[47] = CRGB::Red;
             FastLED.show();
             break;  
                           
    case 5:  leds[46] = CRGB::Black;
             leds[47] = CRGB::Black;
             leds[48] = CRGB::Black;
             leds[49] = CRGB::Black;
             leds[50] = CRGB::Black;
             leds[51] = CRGB::Red;
             leds[52] = CRGB::Red;
             FastLED.show();
             break;  

   








   
}

}


