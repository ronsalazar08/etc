#include "FastLED.h"

#define NUM_LEDS 300      //heto ang bilang ng LED
#define DATA_PIN 6
#define BUTTON_PIN 2
#define BRIGHTNESS 100    //Heto yung adjustment ng brightness

CRGB leds[NUM_LEDS];

bool oldState = HIGH;
int showType = 0;



void setup() { 
      
     pinMode(BUTTON_PIN, INPUT_PULLUP);
       
  	  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);


      // Startup lang 
      
       int j=0;  
       while (j<299) {j++; leds[j] = CRGB::Blue;  FastLED.show();}          
           
       int k=0;
       while (k<299){k++; leds[k] = CRGB::Green;  FastLED.show();}

       int l=0;
       while (l<299){l++; leds[l] = CRGB::Red;    FastLED.show();} 
         
                 
       int m=0;
       while (m<299){m++; leds[m] = CRGB::Black;  FastLED.show();} 
              
      
}
void loop() { 
  
   bool newState = digitalRead(BUTTON_PIN);

   if (newState == LOW && oldState == HIGH)
       {delay(20); newState = digitalRead(BUTTON_PIN);
          if (newState == LOW) {showType++; 
          if (showType > 60)         //heto yung ilang beses pipindot ng button bago umulit sa loop ng button
               showType=1;           //heto yung saan magsisimula umilaw yung LED
               startShow(showType);}
        }
   oldState = newState;
}




void startShow(int i) {
             

   FastLED.setBrightness(BRIGHTNESS);    //dito lang sa loop na ito na-adjust yung brightness
   FastLED.clear();                      //bawat loop clear


   //Value ng LED
 
switch(i){

    
    case 1:  leds[1] = CRGB::Blue;
             leds[2] = CRGB::Blue;
             leds[3] = CRGB::Blue;
             FastLED.show();
             break; 
    case 2:  leds[5] = CRGB::Blue;
             leds[6] = CRGB::Blue;
             leds[7] = CRGB::Blue;
             FastLED.show();
             break;

    case 3:  leds[10] = CRGB::Blue;
             leds[11] = CRGB::Blue;
             leds[12] = CRGB::Blue;
             FastLED.show();
             break;       
    case 4:  leds[15] = CRGB::Blue;
             leds[16] = CRGB::Blue;
             leds[17] = CRGB::Blue;
             FastLED.show();
             break; 

    case 5:  leds[20] = CRGB::Blue;
             leds[21] = CRGB::Blue;
             leds[22] = CRGB::Blue;
             FastLED.show();
             break; 
    case 6:  leds[25] = CRGB::Blue;
             leds[26] = CRGB::Blue;
             leds[27] = CRGB::Blue;
             FastLED.show();
             break;                    
    case 7:  leds[30] = CRGB::Blue;
             leds[31] = CRGB::Blue;
             leds[32] = CRGB::Blue;
             FastLED.show();
             break;  
    case 8:  leds[35] = CRGB::Blue;
             leds[36] = CRGB::Blue;
             leds[37] = CRGB::Blue;
             FastLED.show();
             break;                 
   case 9:  leds[40] = CRGB::Blue;
             leds[41] = CRGB::Blue;
             leds[42] = CRGB::Blue;
             FastLED.show();
             break;  
   case 10:  leds[45] = CRGB::Blue;
             leds[46] = CRGB::Blue;
             leds[47] = CRGB::Blue;
             FastLED.show();
             break;                                                                      
   case 11:  leds[50] = CRGB::Blue;
             leds[51] = CRGB::Blue;
             leds[52] = CRGB::Blue;
             FastLED.show();
             break;  
   case 12:  leds[55] = CRGB::Blue;
             leds[56] = CRGB::Blue;
             leds[57] = CRGB::Blue;
             FastLED.show();
             break; 
   case 13:  leds[60] = CRGB::Blue;
             leds[61] = CRGB::Blue;
             leds[62] = CRGB::Blue;
             FastLED.show();
             break;
   case 14:  leds[65] = CRGB::Blue;
             leds[66] = CRGB::Blue;
             leds[67] = CRGB::Blue;
             FastLED.show();
             break;

   case 15:  leds[70] = CRGB::Blue;
             leds[71] = CRGB::Blue;
             leds[72] = CRGB::Blue;
             FastLED.show();
             break;       
   case 16:  leds[75] = CRGB::Blue;
             leds[76] = CRGB::Blue;
             leds[77] = CRGB::Blue;
             FastLED.show();
             break; 

   case 17:  leds[80] = CRGB::Blue;
             leds[81] = CRGB::Blue;
             leds[82] = CRGB::Blue;
             FastLED.show();
             break; 
   case 18:  leds[85] = CRGB::Blue;
             leds[86] = CRGB::Blue;
             leds[87] = CRGB::Blue;
             FastLED.show();
             break;                    
   case 19:  leds[90] = CRGB::Blue;
             leds[91] = CRGB::Blue;
             leds[92] = CRGB::Blue;
             FastLED.show();
             break;  
   case 20:  leds[95] = CRGB::Blue;
             leds[96] = CRGB::Blue;
             leds[97] = CRGB::Blue;
             FastLED.show();
             break;                 
   case 21:  leds[100] = CRGB::Blue;
             leds[101] = CRGB::Blue;
             leds[102] = CRGB::Blue;
             FastLED.show();
             break;  
   case 22:  leds[105] = CRGB::Blue;
             leds[106] = CRGB::Blue;
             leds[107] = CRGB::Blue;
             FastLED.show();
             break;                                                                      
   case 23:  leds[110] = CRGB::Blue;
             leds[111] = CRGB::Blue;
             leds[112] = CRGB::Blue;
             FastLED.show();
             break;  
   case 24:  leds[115] = CRGB::Blue;
             leds[116] = CRGB::Blue;
             leds[117] = CRGB::Blue;
             FastLED.show();
             break;                                                                
   case 25:  leds[120] = CRGB::Blue;
             leds[121] = CRGB::Blue;
             leds[122] = CRGB::Blue;
             FastLED.show();
             break;
   case 26:  leds[125] = CRGB::Blue;
             leds[126] = CRGB::Blue;
             leds[127] = CRGB::Blue;
             FastLED.show();
             break;

   case 27:  leds[130] = CRGB::Blue;
             leds[131] = CRGB::Blue;
             leds[132] = CRGB::Blue;
             FastLED.show();
             break;       
   case 28:  leds[135] = CRGB::Blue;
             leds[136] = CRGB::Blue;
             leds[137] = CRGB::Blue;
             FastLED.show();
             break; 

   case 29:  leds[140] = CRGB::Blue;
             leds[141] = CRGB::Blue;
             leds[142] = CRGB::Blue;
             FastLED.show();
             break; 
   case 30:  leds[145] = CRGB::Blue;
             leds[146] = CRGB::Blue;
             leds[147] = CRGB::Blue;
             FastLED.show();
             break;                    
   case 31:  leds[150] = CRGB::Blue;
             leds[151] = CRGB::Blue;
             leds[152] = CRGB::Blue;
             FastLED.show();
             break;  
   case 32:  leds[155] = CRGB::Blue;
             leds[156] = CRGB::Blue;
             leds[157] = CRGB::Blue;
             FastLED.show();
             break;                 
   case 33:  leds[160] = CRGB::Blue;
             leds[161] = CRGB::Blue;
             leds[162] = CRGB::Blue;
             FastLED.show();
             break;  
   case 34:  leds[165] = CRGB::Blue;
             leds[166] = CRGB::Blue;
             leds[167] = CRGB::Blue;
             FastLED.show();
             break;                                                                      
   case 35:  leds[170] = CRGB::Blue;
             leds[171] = CRGB::Blue;
             leds[172] = CRGB::Blue;
             FastLED.show();
             break;  
   case 36:  leds[175] = CRGB::Blue;
             leds[176] = CRGB::Blue;
             leds[177] = CRGB::Blue;
             FastLED.show();
             break; 
   case 37:  leds[180] = CRGB::Blue;
             leds[181] = CRGB::Blue;
             leds[182] = CRGB::Blue;
             FastLED.show();
             break;
             
   case 38:  leds[185] = CRGB::Blue;
             leds[186] = CRGB::Blue;
             leds[187] = CRGB::Blue;
             FastLED.show();
             break; 
             
   case 39:  leds[190] = CRGB::Blue;
             leds[191] = CRGB::Blue;
             leds[192] = CRGB::Blue;
             FastLED.show(); 
              break;  
                              
   case 40:  leds[195] = CRGB::Blue;
             leds[196] = CRGB::Blue;
             leds[197] = CRGB::Blue;
             FastLED.show();
             break;

   case 41:  leds[200] = CRGB::Blue;
             leds[201] = CRGB::Blue;
             leds[202] = CRGB::Blue;
             FastLED.show();
             break;       
   case 42:  leds[205] = CRGB::Blue;
             leds[206] = CRGB::Blue;
             leds[207] = CRGB::Blue;
             FastLED.show();
             break; 

   case 43:  leds[210] = CRGB::Blue;
             leds[211] = CRGB::Blue;
             leds[212] = CRGB::Blue;
             FastLED.show();
             break; 
   case 44:  leds[215] = CRGB::Blue;
             leds[216] = CRGB::Blue;
             leds[217] = CRGB::Blue;
             FastLED.show();
             break;                    
   case 45:  leds[220] = CRGB::Blue;
             leds[221] = CRGB::Blue;
             leds[222] = CRGB::Blue;
             FastLED.show();
             break;  
   case 46:  leds[225] = CRGB::Blue;
             leds[226] = CRGB::Blue;
             leds[227] = CRGB::Blue;
             FastLED.show();
             break;                 
   case 47:  leds[230] = CRGB::Blue;
             leds[231] = CRGB::Blue;
             leds[232] = CRGB::Blue;
             FastLED.show();
             break;  
   case 48:  leds[235] = CRGB::Blue;
             leds[236] = CRGB::Blue;
             leds[237] = CRGB::Blue;
             FastLED.show();
             break;                                                                      
   case 49:  leds[240] = CRGB::Blue;
             leds[241] = CRGB::Blue;
             leds[242] = CRGB::Blue;
             FastLED.show();
             break;  
   case 50:  leds[245] = CRGB::Blue;
             leds[246] = CRGB::Blue;
             leds[247] = CRGB::Blue;
             FastLED.show();
             break;                                                                
   case 51:  leds[250] = CRGB::Blue;
             leds[251] = CRGB::Blue;
             leds[252] = CRGB::Blue;
             FastLED.show();
             break;       
   case 52:  leds[255] = CRGB::Blue;
             leds[256] = CRGB::Blue;
             leds[257] = CRGB::Blue;
             FastLED.show();
             break; 

   case 53:  leds[260] = CRGB::Blue;
             leds[261] = CRGB::Blue;
             leds[262] = CRGB::Blue;
             FastLED.show();
             break; 
   case 54:  leds[265] = CRGB::Blue;
             leds[266] = CRGB::Blue;
             leds[267] = CRGB::Blue;
             FastLED.show();
             break;                    
   case 55:  leds[270] = CRGB::Blue;
             leds[271] = CRGB::Blue;
             leds[272] = CRGB::Blue;
             FastLED.show();
             break;  
   case 56:  leds[275] = CRGB::Blue;
             leds[276] = CRGB::Blue;
             leds[277] = CRGB::Blue;
             FastLED.show();
             break;                 
   case 57:  leds[280] = CRGB::Blue;
             leds[281] = CRGB::Blue;
             leds[282] = CRGB::Blue;
             FastLED.show();
             break;  
   case 58:  leds[285] = CRGB::Blue;
             leds[286] = CRGB::Blue;
             leds[287] = CRGB::Blue;
             FastLED.show();
             break;                                                                      
   case 59:  leds[290] = CRGB::Blue;
             leds[291] = CRGB::Blue;
             leds[292] = CRGB::Blue;
             FastLED.show();
             break;  
   case 60:  leds[295] = CRGB::Blue;
             leds[296] = CRGB::Blue;
             leds[297] = CRGB::Blue;
             FastLED.show();
             break; 

   


}
}
