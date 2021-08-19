
#include "FastLED.h"

#define NUM_LEDS 300          //heto ang bilang ng LED
#define DATA_PIN 12
#define BUTTON_PIN 5          //next button
#define BUTTON_PINjapan 2     //japan
#define BUTTON_PINeuro  3     //euro
#define BUTTON_PINnafta 4     //nafta
#define BRIGHTNESS 50        //Heto yung adjustment ng brightness

CRGB leds[NUM_LEDS];

int buttonState1 = 0;         
int lastButtonState1 = 0;     
int buttonPushCounter1 = 1000;   
int buttonPushCounter2 = 2000;   
int buttonPushCounter3 = 3000;
int japan = 0;
int euro = 0;
int nafta = 0;
void setup()
{
      Serial.begin( 115200 );
      pinMode(BUTTON_PIN, INPUT);
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
euro = digitalRead(BUTTON_PINeuro);
nafta = digitalRead(BUTTON_PINnafta);
buttonState1 = digitalRead(BUTTON_PIN);
//==========================================================================================================     DEBOUNCE FOR NEXT BUTTON
 if (buttonState1 != lastButtonState1)
 {
   if (buttonState1 == HIGH)
   {
      buttonPushCounter1++;// INCREMENT WHEN NEXT BUTTON IS PUSHED
      buttonPushCounter2++;
      buttonPushCounter3++;
   } 
   else
   {
   }
delay(50);
  }
   else
  {
  }
  lastButtonState1 = buttonState1;

//==========================================================================================================     start of tray 1 japan
if (buttonPushCounter1 == 1){//1 LED
             leds[1] = CRGB::Blue;
             leds[2] = CRGB::Blue;
             leds[97] = CRGB::Black;
             leds[98] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 3){//2
             leds[1] = CRGB::Black;
             leds[2] = CRGB::Black;
             leds[5] = CRGB::Blue;
             leds[6] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 5){//3
             leds[5] = CRGB::Black;
             leds[6] = CRGB::Black;
             leds[9] = CRGB::Blue;
             leds[10] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 7){//4
             leds[9] = CRGB::Black;
             leds[10] = CRGB::Black;
             leds[13] = CRGB::Blue;
             leds[14] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 9){//5
             leds[13] = CRGB::Black;
             leds[14] = CRGB::Black;
             leds[17] = CRGB::Blue;
             leds[18] = CRGB::Blue;
             FastLED.show();
   
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 11){//6
             leds[17] = CRGB::Black;
             leds[18] = CRGB::Black;
             leds[21] = CRGB::Blue;
             leds[22] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 13){//7
             leds[21] = CRGB::Black;
             leds[22] = CRGB::Black;
             leds[25] = CRGB::Blue;
             leds[26] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 15){//8
             leds[25] = CRGB::Black;
             leds[26] = CRGB::Black;
             leds[29] = CRGB::Blue;
             leds[30] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 17){//9
             leds[29] = CRGB::Black;
             leds[30] = CRGB::Black;
             leds[33] = CRGB::Blue;
             leds[34] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 19){//10
             leds[33] = CRGB::Black;
             leds[34] = CRGB::Black;
             leds[37] = CRGB::Blue;
             leds[38] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 21){//11
             leds[37] = CRGB::Black;
             leds[38] = CRGB::Black;
             leds[41] = CRGB::Blue;
             leds[42] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 23){//12
             leds[41] = CRGB::Black;
             leds[42] = CRGB::Black;
             leds[45] = CRGB::Blue;
             leds[46] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 25){//13
             leds[45] = CRGB::Black;
             leds[46] = CRGB::Black;
             leds[49] = CRGB::Blue;
             leds[50] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 27){//14
             leds[49] = CRGB::Black;
             leds[50] = CRGB::Black;
             leds[53] = CRGB::Blue;
             leds[54] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 29){//15
             leds[53] = CRGB::Black;
             leds[54] = CRGB::Black;
             leds[57] = CRGB::Blue;
             leds[58] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 31){//16
             leds[57] = CRGB::Black;
             leds[58] = CRGB::Black;
             leds[61] = CRGB::Blue;
             leds[62] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++;        
}
else if (buttonPushCounter1 == 33){//17
             leds[61] = CRGB::Black;
             leds[62] = CRGB::Black;
             leds[65] = CRGB::Blue;
             leds[66] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++;        
}
else if (buttonPushCounter1 == 35){//18
             leds[65] = CRGB::Black;
             leds[66] = CRGB::Black;
             leds[69] = CRGB::Blue;
             leds[70] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++;        
}
else if (buttonPushCounter1 == 37){//19
             leds[69] = CRGB::Black;
             leds[70] = CRGB::Black;
             leds[73] = CRGB::Blue;
             leds[74] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++;        
}
else if (buttonPushCounter1 == 39){//20
             leds[73] = CRGB::Black;
             leds[74] = CRGB::Black;
             leds[77] = CRGB::Blue;
             leds[78] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++;        
}
else if (buttonPushCounter1 == 41){//21
             leds[77] = CRGB::Black;
             leds[78] = CRGB::Black;
             leds[81] = CRGB::Blue;
             leds[82] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++;        
}
else if (buttonPushCounter1 == 43){//22
             leds[81] = CRGB::Black;
             leds[82] = CRGB::Black;
             leds[85] = CRGB::Blue;
             leds[86] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++;        
}
else if (buttonPushCounter1 == 45){//23
             leds[85] = CRGB::Black;
             leds[86] = CRGB::Black;
             leds[89] = CRGB::Blue;
             leds[90] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++;        
}
else if (buttonPushCounter1 == 47){//24
             leds[89] = CRGB::Black;
             leds[90] = CRGB::Black;
             leds[93] = CRGB::Blue;
             leds[94] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++;        
}
else if (buttonPushCounter1 == 49){//25
             leds[93] = CRGB::Black;
             leds[94] = CRGB::Black;
             leds[97] = CRGB::Blue;
             leds[98] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter1++ ;        
}
else if (buttonPushCounter1 == 51){//back to 1
buttonPushCounter1 = 1 ;        
}

//==========================================================================================================     start of tray 1 euro

if (buttonPushCounter2 == 1){//1
             leds[101] = CRGB::Red;
             leds[102] = CRGB::Red;
             leds[181] = CRGB::Black;
             leds[182] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 3){//2
             leds[101] = CRGB::Black;
             leds[102] = CRGB::Black;
             leds[105] = CRGB::Red;
             leds[106] = CRGB::Red;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 5){//3
             leds[105] = CRGB::Black;
             leds[106] = CRGB::Black;
             leds[109] = CRGB::Red;
             leds[110] = CRGB::Red;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 7){//4
             leds[109] = CRGB::Black;
             leds[110] = CRGB::Black;
             leds[113] = CRGB::Red;
             leds[114] = CRGB::Red;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 9){//5
             leds[113] = CRGB::Black;
             leds[114] = CRGB::Black;
             leds[117] = CRGB::Red;
             leds[118] = CRGB::Red;
             FastLED.show();
   
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 11){//6
             leds[117] = CRGB::Black;
             leds[118] = CRGB::Black;
             leds[121] = CRGB::Red;
             leds[122] = CRGB::Red;
             FastLED.show();  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 13){//7
             leds[121] = CRGB::Black;
             leds[122] = CRGB::Black;
             leds[125] = CRGB::Red;
             leds[126] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 15){//8
             leds[125] = CRGB::Black;
             leds[126] = CRGB::Black;
             leds[129] = CRGB::Red;
             leds[130] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 17){//9
             leds[129] = CRGB::Black;
             leds[130] = CRGB::Black;
             leds[133] = CRGB::Red;
             leds[134] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 19){//10
             leds[133] = CRGB::Black;
             leds[134] = CRGB::Black;
             leds[137] = CRGB::Red;
             leds[138] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 21){//11
             leds[137] = CRGB::Black;
             leds[138] = CRGB::Black;
             leds[141] = CRGB::Red;
             leds[142] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 23){//12
             leds[141] = CRGB::Black;
             leds[142] = CRGB::Black;
             leds[145] = CRGB::Red;
             leds[146] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 25){//13
             leds[145] = CRGB::Black;
             leds[146] = CRGB::Black;
             leds[149] = CRGB::Red;
             leds[150] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 27){//14
             leds[149] = CRGB::Black;
             leds[150] = CRGB::Black;
             leds[153] = CRGB::Red;
             leds[154] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 29){//15
             leds[153] = CRGB::Black;
             leds[154] = CRGB::Black;
             leds[157] = CRGB::Red;
             leds[158] = CRGB::Red;
             FastLED.show();  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 31){//16
             leds[157] = CRGB::Black;
             leds[158] = CRGB::Black;
             leds[161] = CRGB::Red;
             leds[162] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 33){//17
             leds[161] = CRGB::Black;
             leds[162] = CRGB::Black;
             leds[165] = CRGB::Red;
             leds[166] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 35){//18
             leds[165] = CRGB::Black;
             leds[166] = CRGB::Black;
             leds[169] = CRGB::Red;
             leds[170] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 37){//19
             leds[169] = CRGB::Black;
             leds[170] = CRGB::Black;
             leds[173] = CRGB::Red;
             leds[174] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 39){//20
             leds[173] = CRGB::Black;
             leds[174] = CRGB::Black;
             leds[177] = CRGB::Red;
             leds[178] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 41){//21
             leds[177] = CRGB::Black;
             leds[178] = CRGB::Black;
             leds[181] = CRGB::Red;
             leds[182] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 43){//BACK TO 1
buttonPushCounter2 = 1;        
}


//==========================================================================================================     start of tray 1 nafta


if (buttonPushCounter3 == 1){//1
             leds[201] = CRGB::Green;
             leds[202] = CRGB::Green;
             leds[285] = CRGB::Black;
             leds[286] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 3){//2
             leds[201] = CRGB::Black;
             leds[202] = CRGB::Black;
             leds[205] = CRGB::Green;
             leds[206] = CRGB::Green;
             FastLED.show();
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 5){//3
             leds[205] = CRGB::Black;
             leds[206] = CRGB::Black;
             leds[209] = CRGB::Green;
             leds[210] = CRGB::Green;
             FastLED.show();
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 7){//4
             leds[209] = CRGB::Black;
             leds[210] = CRGB::Black;
             leds[213] = CRGB::Green;
             leds[214] = CRGB::Green;
             FastLED.show();
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 9){//5
             leds[213] = CRGB::Black;
             leds[214] = CRGB::Black;
             leds[217] = CRGB::Green;
             leds[218] = CRGB::Green;
             FastLED.show();
   
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6
             leds[217] = CRGB::Black;
             leds[218] = CRGB::Black;
             leds[221] = CRGB::Green;
             leds[222] = CRGB::Green;
             FastLED.show();  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 13){//7
             leds[221] = CRGB::Black;
             leds[222] = CRGB::Black;
             leds[225] = CRGB::Green;
             leds[226] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 15){//8
             leds[225] = CRGB::Black;
             leds[226] = CRGB::Black;
             leds[229] = CRGB::Green;
             leds[230] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 17){//9
             leds[229] = CRGB::Black;
             leds[230] = CRGB::Black;
             leds[233] = CRGB::Green;
             leds[234] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 19){//10
             leds[233] = CRGB::Black;
             leds[234] = CRGB::Black;
             leds[237] = CRGB::Green;
             leds[238] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 21){//11
             leds[237] = CRGB::Black;
             leds[238] = CRGB::Black;
             leds[241] = CRGB::Green;
             leds[242] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 23){//12
             leds[241] = CRGB::Black;
             leds[242] = CRGB::Black;
             leds[245] = CRGB::Green;
             leds[246] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 25){//13
             leds[245] = CRGB::Black;
             leds[246] = CRGB::Black;
             leds[249] = CRGB::Green;
             leds[250] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 27){//14
             leds[249] = CRGB::Black;
             leds[250] = CRGB::Black;
             leds[253] = CRGB::Green;
             leds[254] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 29){//15
             leds[253] = CRGB::Black;
             leds[254] = CRGB::Black;
             leds[257] = CRGB::Green;
             leds[258] = CRGB::Green;
             FastLED.show();  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 31){//16
             leds[257] = CRGB::Black;
             leds[258] = CRGB::Black;
             leds[261] = CRGB::Green;
             leds[262] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 33){//17
             leds[261] = CRGB::Black;
             leds[262] = CRGB::Black;
             leds[265] = CRGB::Green;
             leds[266] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 35){//18
             leds[265] = CRGB::Black;
             leds[266] = CRGB::Black;
             leds[269] = CRGB::Green;
             leds[270] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 37){//19
             leds[269] = CRGB::Black;
             leds[270] = CRGB::Black;
             leds[273] = CRGB::Green;
             leds[274] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 39){//20
             leds[273] = CRGB::Black;
             leds[274] = CRGB::Black;
             leds[277] = CRGB::Green;
             leds[278] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 41){//21
             leds[277] = CRGB::Black;
             leds[278] = CRGB::Black;
             leds[281] = CRGB::Green;
             leds[282] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 43){//22
             leds[281] = CRGB::Black;
             leds[282] = CRGB::Black;
             leds[285] = CRGB::Green;
             leds[286] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 45){//BACK TO 1
buttonPushCounter3 = 1;        
}

//==========================================================================================================     products
if (japan == HIGH)
 {
  FastLED.clear();
  buttonPushCounter1 = 1;
  buttonPushCounter2 = 2000;
  buttonPushCounter3 = 3000;
  delay(500);
 }
if (euro == HIGH)
  {
  FastLED.clear();
  buttonPushCounter1 = 1000;
  buttonPushCounter2 = 1;
  buttonPushCounter3 = 3000;
  delay(500);
  }
if (nafta == HIGH)
  {
  FastLED.clear();
  buttonPushCounter1 = 1000;
  buttonPushCounter2 = 2000;
  buttonPushCounter3 = 1;
  delay(500);
  }
}

