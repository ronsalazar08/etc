
#include "FastLED.h"

#define NUM_LEDS 1700          //heto ang bilang ng LED
#define DATA_PIN 12
#define BUTTON_PIN 5          //next button
#define BUTTON_PINjapan 2     //japan
#define BUTTON_PINeuro  3     //euro
#define BUTTON_PINnafta 4     //nafta
#define BRIGHTNESS 50         //Heto yung adjustment ng brightness

CRGB leds[NUM_LEDS];

int buttonState1 = 0;         
int lastButtonState1 = 0;     
int buttonPushCounter1 = 1000;   //japan tray 1
int buttonPushCounter2 = 2000;   //euro tray 1
int buttonPushCounter3 = 3000;   //nafta tray 1

int buttonPushCounter4 = 4000;   //japan tray 2
int buttonPushCounter5 = 5000;   //euro tray 2
int buttonPushCounter6 = 6000;   //nafta tray 2

int buttonPushCounter7 = 7000;   //japan tray 3
int buttonPushCounter8 = 8000;   //euro tray 3
int buttonPushCounter9 = 9000;   //nafta tray 3

int buttonPushCounter10 = 10000;   //japan tray 4
int buttonPushCounter11 = 11000;   //euro tray 4
int buttonPushCounter12 = 12000;   //nafta tray 4

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
if (buttonPushCounter4 < 3999)
{
  buttonPushCounter4 = 1;
  buttonPushCounter1 = 1; 
}
else
{
buttonPushCounter1 = 1; 
}    
}


//==========================================================================================================     start of tray 2 japan
if (buttonPushCounter4 == 1){//1 LED
             leds[301] = CRGB::Blue;
             leds[302] = CRGB::Blue;
             leds[397] = CRGB::Black;
             leds[398] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 3){//2
             leds[301] = CRGB::Black;
             leds[302] = CRGB::Black;
             leds[305] = CRGB::Blue;
             leds[306] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 5){//3
             leds[305] = CRGB::Black;
             leds[306] = CRGB::Black;
             leds[309] = CRGB::Blue;
             leds[310] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 7){//4
             leds[309] = CRGB::Black;
             leds[310] = CRGB::Black;
             leds[313] = CRGB::Blue;
             leds[314] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 9){//5
             leds[313] = CRGB::Black;
             leds[314] = CRGB::Black;
             leds[317] = CRGB::Blue;
             leds[318] = CRGB::Blue;
             FastLED.show();
   
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 11){//6
             leds[317] = CRGB::Black;
             leds[318] = CRGB::Black;
             leds[321] = CRGB::Blue;
             leds[322] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 13){//7
             leds[321] = CRGB::Black;
             leds[322] = CRGB::Black;
             leds[325] = CRGB::Blue;
             leds[326] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 15){//8
             leds[325] = CRGB::Black;
             leds[326] = CRGB::Black;
             leds[329] = CRGB::Blue;
             leds[330] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 17){//9
             leds[329] = CRGB::Black;
             leds[330] = CRGB::Black;
             leds[333] = CRGB::Blue;
             leds[334] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 19){//10
             leds[333] = CRGB::Black;
             leds[334] = CRGB::Black;
             leds[337] = CRGB::Blue;
             leds[338] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 21){//11
             leds[337] = CRGB::Black;
             leds[338] = CRGB::Black;
             leds[341] = CRGB::Blue;
             leds[342] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 23){//12
             leds[341] = CRGB::Black;
             leds[342] = CRGB::Black;
             leds[345] = CRGB::Blue;
             leds[346] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 25){//13
             leds[345] = CRGB::Black;
             leds[346] = CRGB::Black;
             leds[349] = CRGB::Blue;
             leds[350] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 27){//14
             leds[349] = CRGB::Black;
             leds[350] = CRGB::Black;
             leds[353] = CRGB::Blue;
             leds[354] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 29){//15
             leds[353] = CRGB::Black;
             leds[354] = CRGB::Black;
             leds[357] = CRGB::Blue;
             leds[358] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 31){//16
             leds[357] = CRGB::Black;
             leds[358] = CRGB::Black;
             leds[361] = CRGB::Blue;
             leds[362] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++;        
}
else if (buttonPushCounter4 == 33){//17
             leds[361] = CRGB::Black;
             leds[362] = CRGB::Black;
             leds[365] = CRGB::Blue;
             leds[366] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++;        
}
else if (buttonPushCounter4 == 35){//18
             leds[365] = CRGB::Black;
             leds[366] = CRGB::Black;
             leds[369] = CRGB::Blue;
             leds[370] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++;        
}
else if (buttonPushCounter4 == 37){//19
             leds[369] = CRGB::Black;
             leds[370] = CRGB::Black;
             leds[373] = CRGB::Blue;
             leds[374] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++;        
}
else if (buttonPushCounter4 == 39){//20
             leds[373] = CRGB::Black;
             leds[374] = CRGB::Black;
             leds[377] = CRGB::Blue;
             leds[378] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++;        
}
else if (buttonPushCounter4 == 41){//21
             leds[377] = CRGB::Black;
             leds[378] = CRGB::Black;
             leds[381] = CRGB::Blue;
             leds[382] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++;        
}
else if (buttonPushCounter4 == 43){//22
             leds[381] = CRGB::Black;
             leds[382] = CRGB::Black;
             leds[385] = CRGB::Blue;
             leds[386] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++;        
}
else if (buttonPushCounter4 == 45){//23
             leds[385] = CRGB::Black;
             leds[386] = CRGB::Black;
             leds[389] = CRGB::Blue;
             leds[390] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++;        
}
else if (buttonPushCounter4 == 47){//24
             leds[389] = CRGB::Black;
             leds[390] = CRGB::Black;
             leds[393] = CRGB::Blue;
             leds[394] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++;        
}
else if (buttonPushCounter4 == 49){//25
             leds[393] = CRGB::Black;
             leds[394] = CRGB::Black;
             leds[397] = CRGB::Blue;
             leds[398] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter4++ ;        
}
else if (buttonPushCounter4 == 51){//back to 1
buttonPushCounter4 = 1 ;        
}


//==========================================================================================================     start of tray 3 japan
if (buttonPushCounter7 == 1){//1 LED
             leds[601] = CRGB::Blue;
             leds[602] = CRGB::Blue;
             leds[697] = CRGB::Black;
             leds[698] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 3){//2
             leds[601] = CRGB::Black;
             leds[602] = CRGB::Black;
             leds[605] = CRGB::Blue;
             leds[606] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 5){//3
             leds[605] = CRGB::Black;
             leds[606] = CRGB::Black;
             leds[609] = CRGB::Blue;
             leds[610] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 7){//4
             leds[609] = CRGB::Black;
             leds[610] = CRGB::Black;
             leds[613] = CRGB::Blue;
             leds[614] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 9){//5
             leds[613] = CRGB::Black;
             leds[614] = CRGB::Black;
             leds[617] = CRGB::Blue;
             leds[618] = CRGB::Blue;
             FastLED.show();
   
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 11){//6
             leds[617] = CRGB::Black;
             leds[618] = CRGB::Black;
             leds[621] = CRGB::Blue;
             leds[622] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 13){//7
             leds[621] = CRGB::Black;
             leds[622] = CRGB::Black;
             leds[625] = CRGB::Blue;
             leds[626] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 15){//8
             leds[625] = CRGB::Black;
             leds[626] = CRGB::Black;
             leds[629] = CRGB::Blue;
             leds[630] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 17){//9
             leds[629] = CRGB::Black;
             leds[630] = CRGB::Black;
             leds[633] = CRGB::Blue;
             leds[634] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 19){//10
             leds[633] = CRGB::Black;
             leds[634] = CRGB::Black;
             leds[637] = CRGB::Blue;
             leds[638] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 21){//11
             leds[637] = CRGB::Black;
             leds[638] = CRGB::Black;
             leds[641] = CRGB::Blue;
             leds[642] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 23){//12
             leds[641] = CRGB::Black;
             leds[642] = CRGB::Black;
             leds[645] = CRGB::Blue;
             leds[646] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 25){//13
             leds[645] = CRGB::Black;
             leds[646] = CRGB::Black;
             leds[649] = CRGB::Blue;
             leds[650] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 27){//14
             leds[649] = CRGB::Black;
             leds[650] = CRGB::Black;
             leds[653] = CRGB::Blue;
             leds[654] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 29){//15
             leds[653] = CRGB::Black;
             leds[654] = CRGB::Black;
             leds[657] = CRGB::Blue;
             leds[658] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 31){//16
             leds[657] = CRGB::Black;
             leds[658] = CRGB::Black;
             leds[661] = CRGB::Blue;
             leds[662] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++;        
}
else if (buttonPushCounter7 == 33){//17
             leds[661] = CRGB::Black;
             leds[662] = CRGB::Black;
             leds[665] = CRGB::Blue;
             leds[666] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++;        
}
else if (buttonPushCounter7 == 35){//18
             leds[665] = CRGB::Black;
             leds[666] = CRGB::Black;
             leds[669] = CRGB::Blue;
             leds[670] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++;        
}
else if (buttonPushCounter7 == 37){//19
             leds[669] = CRGB::Black;
             leds[670] = CRGB::Black;
             leds[673] = CRGB::Blue;
             leds[674] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++;        
}
else if (buttonPushCounter7 == 39){//20
             leds[673] = CRGB::Black;
             leds[674] = CRGB::Black;
             leds[677] = CRGB::Blue;
             leds[678] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++;        
}
else if (buttonPushCounter7 == 41){//21
             leds[677] = CRGB::Black;
             leds[678] = CRGB::Black;
             leds[681] = CRGB::Blue;
             leds[682] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++;        
}
else if (buttonPushCounter7 == 43){//22
             leds[681] = CRGB::Black;
             leds[682] = CRGB::Black;
             leds[685] = CRGB::Blue;
             leds[686] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++;        
}
else if (buttonPushCounter7 == 45){//23
             leds[685] = CRGB::Black;
             leds[686] = CRGB::Black;
             leds[689] = CRGB::Blue;
             leds[690] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++;        
}
else if (buttonPushCounter7 == 47){//24
             leds[689] = CRGB::Black;
             leds[690] = CRGB::Black;
             leds[693] = CRGB::Blue;
             leds[694] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++;        
}
else if (buttonPushCounter7 == 49){//25
             leds[693] = CRGB::Black;
             leds[694] = CRGB::Black;
             leds[697] = CRGB::Blue;
             leds[698] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter7++ ;        
}
else if (buttonPushCounter7 == 51){//back to 1
buttonPushCounter7 = 1 ;        
}


//==========================================================================================================     start of tray 4 japan
if (buttonPushCounter10 == 1){//1 LED
             leds[901] = CRGB::Blue;
             leds[902] = CRGB::Blue;
             leds[997] = CRGB::Black;
             leds[998] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 3){//2
             leds[901] = CRGB::Black;
             leds[902] = CRGB::Black;
             leds[905] = CRGB::Blue;
             leds[906] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 5){//3
             leds[905] = CRGB::Black;
             leds[906] = CRGB::Black;
             leds[909] = CRGB::Blue;
             leds[910] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 7){//4
             leds[909] = CRGB::Black;
             leds[910] = CRGB::Black;
             leds[913] = CRGB::Blue;
             leds[914] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 9){//5
             leds[913] = CRGB::Black;
             leds[914] = CRGB::Black;
             leds[917] = CRGB::Blue;
             leds[918] = CRGB::Blue;
             FastLED.show();
   
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 11){//6
             leds[917] = CRGB::Black;
             leds[918] = CRGB::Black;
             leds[921] = CRGB::Blue;
             leds[922] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 13){//7
             leds[921] = CRGB::Black;
             leds[922] = CRGB::Black;
             leds[925] = CRGB::Blue;
             leds[926] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 15){//8
             leds[925] = CRGB::Black;
             leds[926] = CRGB::Black;
             leds[929] = CRGB::Blue;
             leds[930] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 17){//9
             leds[929] = CRGB::Black;
             leds[930] = CRGB::Black;
             leds[933] = CRGB::Blue;
             leds[934] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 19){//10
             leds[933] = CRGB::Black;
             leds[934] = CRGB::Black;
             leds[937] = CRGB::Blue;
             leds[938] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 21){//11
             leds[937] = CRGB::Black;
             leds[938] = CRGB::Black;
             leds[941] = CRGB::Blue;
             leds[942] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 23){//12
             leds[941] = CRGB::Black;
             leds[942] = CRGB::Black;
             leds[945] = CRGB::Blue;
             leds[946] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 25){//13
             leds[945] = CRGB::Black;
             leds[946] = CRGB::Black;
             leds[949] = CRGB::Blue;
             leds[950] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 27){//14
             leds[949] = CRGB::Black;
             leds[950] = CRGB::Black;
             leds[953] = CRGB::Blue;
             leds[954] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 29){//15
             leds[953] = CRGB::Black;
             leds[954] = CRGB::Black;
             leds[957] = CRGB::Blue;
             leds[958] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 31){//16
             leds[957] = CRGB::Black;
             leds[958] = CRGB::Black;
             leds[961] = CRGB::Blue;
             leds[962] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++;        
}
else if (buttonPushCounter10 == 33){//17
             leds[961] = CRGB::Black;
             leds[962] = CRGB::Black;
             leds[965] = CRGB::Blue;
             leds[966] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++;        
}
else if (buttonPushCounter10 == 35){//18
             leds[965] = CRGB::Black;
             leds[966] = CRGB::Black;
             leds[969] = CRGB::Blue;
             leds[970] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++;        
}
else if (buttonPushCounter10 == 37){//19
             leds[969] = CRGB::Black;
             leds[970] = CRGB::Black;
             leds[973] = CRGB::Blue;
             leds[974] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++;        
}
else if (buttonPushCounter10 == 39){//20
             leds[973] = CRGB::Black;
             leds[974] = CRGB::Black;
             leds[977] = CRGB::Blue;
             leds[978] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++;        
}
else if (buttonPushCounter10 == 41){//21
             leds[977] = CRGB::Black;
             leds[978] = CRGB::Black;
             leds[981] = CRGB::Blue;
             leds[982] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++;        
}
else if (buttonPushCounter10 == 43){//22
             leds[981] = CRGB::Black;
             leds[982] = CRGB::Black;
             leds[985] = CRGB::Blue;
             leds[986] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++;        
}
else if (buttonPushCounter10 == 45){//23
             leds[985] = CRGB::Black;
             leds[986] = CRGB::Black;
             leds[989] = CRGB::Blue;
             leds[990] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++;        
}
else if (buttonPushCounter10 == 47){//24
             leds[989] = CRGB::Black;
             leds[990] = CRGB::Black;
             leds[993] = CRGB::Blue;
             leds[994] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++;        
}
else if (buttonPushCounter10 == 49){//25
             leds[993] = CRGB::Black;
             leds[994] = CRGB::Black;
             leds[997] = CRGB::Blue;
             leds[998] = CRGB::Blue;
             FastLED.show();  
buttonPushCounter10++ ;        
}
else if (buttonPushCounter10 == 51){//back to 1
buttonPushCounter10 = 1 ;        
}

//==========================================================================================================     start of tray 1 euro

if (buttonPushCounter2 == 1){//1
             leds[197] = CRGB::Red;
             leds[196] = CRGB::Red;
             leds[117] = CRGB::Black;
             leds[116] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 3){//2
             leds[197] = CRGB::Black;
             leds[196] = CRGB::Black;
             leds[193] = CRGB::Red;
             leds[192] = CRGB::Red;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 5){//3
             leds[193] = CRGB::Black;
             leds[192] = CRGB::Black;
             leds[189] = CRGB::Red;
             leds[188] = CRGB::Red;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 7){//4
             leds[189] = CRGB::Black;
             leds[188] = CRGB::Black;
             leds[185] = CRGB::Red;
             leds[184] = CRGB::Red;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 9){//5
             leds[185] = CRGB::Black;
             leds[184] = CRGB::Black;
             leds[181] = CRGB::Red;
             leds[180] = CRGB::Red;
             FastLED.show();
   
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 11){//6
             leds[181] = CRGB::Black;
             leds[180] = CRGB::Black;
             leds[177] = CRGB::Red;
             leds[176] = CRGB::Red;
             FastLED.show();  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 13){//7
             leds[177] = CRGB::Black;
             leds[176] = CRGB::Black;
             leds[173] = CRGB::Red;
             leds[172] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 15){//8
             leds[173] = CRGB::Black;
             leds[172] = CRGB::Black;
             leds[169] = CRGB::Red;
             leds[168] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 17){//9
             leds[169] = CRGB::Black;
             leds[168] = CRGB::Black;
             leds[165] = CRGB::Red;
             leds[164] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 19){//10
             leds[165] = CRGB::Black;
             leds[164] = CRGB::Black;
             leds[161] = CRGB::Red;
             leds[160] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 21){//11
             leds[161] = CRGB::Black;
             leds[160] = CRGB::Black;
             leds[157] = CRGB::Red;
             leds[156] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 23){//12
             leds[157] = CRGB::Black;
             leds[156] = CRGB::Black;
             leds[153] = CRGB::Red;
             leds[152] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 25){//13
             leds[153] = CRGB::Black;
             leds[152] = CRGB::Black;
             leds[149] = CRGB::Red;
             leds[148] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 27){//14
             leds[149] = CRGB::Black;
             leds[148] = CRGB::Black;
             leds[145] = CRGB::Red;
             leds[144] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 29){//15
             leds[145] = CRGB::Black;
             leds[144] = CRGB::Black;
             leds[141] = CRGB::Red;
             leds[140] = CRGB::Red;
             FastLED.show();  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 31){//16
             leds[141] = CRGB::Black;
             leds[140] = CRGB::Black;
             leds[137] = CRGB::Red;
             leds[136] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 33){//17
             leds[137] = CRGB::Black;
             leds[136] = CRGB::Black;
             leds[133] = CRGB::Red;
             leds[132] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 35){//18
             leds[133] = CRGB::Black;
             leds[132] = CRGB::Black;
             leds[129] = CRGB::Red;
             leds[128] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 37){//19
             leds[129] = CRGB::Black;
             leds[128] = CRGB::Black;
             leds[125] = CRGB::Red;
             leds[124] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 39){//20
             leds[125] = CRGB::Black;
             leds[124] = CRGB::Black;
             leds[121] = CRGB::Red;
             leds[120] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 41){//21
             leds[121] = CRGB::Black;
             leds[120] = CRGB::Black;
             leds[117] = CRGB::Red;
             leds[116] = CRGB::Red;
             FastLED.show();  
buttonPushCounter2++;        
}
else if (buttonPushCounter2 == 43){//BACK TO 1
buttonPushCounter2 = 1;        
}


//==========================================================================================================     start of tray 1 nafta


if (buttonPushCounter3 == 1){//1
             leds[199] = CRGB::Green;
             leds[200] = CRGB::Green;
             leds[283] = CRGB::Black;
             leds[284] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 3){//2
             leds[199] = CRGB::Black;
             leds[200] = CRGB::Black;
             leds[203] = CRGB::Green;
             leds[204] = CRGB::Green;
             FastLED.show();
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 5){//3
             leds[203] = CRGB::Black;
             leds[204] = CRGB::Black;
             leds[207] = CRGB::Green;
             leds[208] = CRGB::Green;
             FastLED.show();
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 7){//4
             leds[207] = CRGB::Black;
             leds[208] = CRGB::Black;
             leds[211] = CRGB::Green;
             leds[212] = CRGB::Green;
             FastLED.show();
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 9){//5
             leds[211] = CRGB::Black;
             leds[212] = CRGB::Black;
             leds[215] = CRGB::Green;
             leds[216] = CRGB::Green;
             FastLED.show();
   
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 11){//6
             leds[215] = CRGB::Black;
             leds[216] = CRGB::Black;
             leds[219] = CRGB::Green;
             leds[220] = CRGB::Green;
             FastLED.show();  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 13){//7
             leds[219] = CRGB::Black;
             leds[220] = CRGB::Black;
             leds[223] = CRGB::Green;
             leds[224] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 15){//8
             leds[223] = CRGB::Black;
             leds[224] = CRGB::Black;
             leds[227] = CRGB::Green;
             leds[228] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 17){//9
             leds[227] = CRGB::Black;
             leds[228] = CRGB::Black;
             leds[231] = CRGB::Green;
             leds[232] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 19){//10
             leds[231] = CRGB::Black;
             leds[232] = CRGB::Black;
             leds[235] = CRGB::Green;
             leds[236] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 21){//11
             leds[235] = CRGB::Black;
             leds[236] = CRGB::Black;
             leds[239] = CRGB::Green;
             leds[240] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 23){//12
             leds[239] = CRGB::Black;
             leds[240] = CRGB::Black;
             leds[243] = CRGB::Green;
             leds[244] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 25){//13
             leds[243] = CRGB::Black;
             leds[244] = CRGB::Black;
             leds[247] = CRGB::Green;
             leds[248] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 27){//14
             leds[247] = CRGB::Black;
             leds[248] = CRGB::Black;
             leds[251] = CRGB::Green;
             leds[252] = CRGB::Green;
             FastLED.show();  
  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 29){//15
             leds[251] = CRGB::Black;
             leds[252] = CRGB::Black;
             leds[255] = CRGB::Green;
             leds[256] = CRGB::Green;
             FastLED.show();  
 buttonPushCounter3++;
}
else if (buttonPushCounter3 == 31){//16
             leds[255] = CRGB::Black;
             leds[256] = CRGB::Black;
             leds[259] = CRGB::Green;
             leds[260] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 33){//17
             leds[259] = CRGB::Black;
             leds[260] = CRGB::Black;
             leds[263] = CRGB::Green;
             leds[264] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 35){//18
             leds[263] = CRGB::Black;
             leds[264] = CRGB::Black;
             leds[267] = CRGB::Green;
             leds[268] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 37){//19
             leds[267] = CRGB::Black;
             leds[268] = CRGB::Black;
             leds[271] = CRGB::Green;
             leds[272] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 39){//20
             leds[271] = CRGB::Black;
             leds[272] = CRGB::Black;
             leds[275] = CRGB::Green;
             leds[276] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 41){//21
             leds[275] = CRGB::Black;
             leds[276] = CRGB::Black;
             leds[279] = CRGB::Green;
             leds[280] = CRGB::Green;
             FastLED.show();  
buttonPushCounter3++;        
}
else if (buttonPushCounter3 == 43){//22
             leds[279] = CRGB::Black;
             leds[280] = CRGB::Black;
             leds[283] = CRGB::Green;
             leds[284] = CRGB::Green;
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

