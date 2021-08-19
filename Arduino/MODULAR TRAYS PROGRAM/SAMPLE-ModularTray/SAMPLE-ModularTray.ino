
#include "FastLED.h"

#define NUM_LEDS 300          //heto ang bilang ng LED
#define DATA_PIN 12
#define BUTTON_PINjapan 2     //japan
#define BUTTON_PINeuro  3     //euro
#define BUTTON_PINnafta 4     //nafta
#define BUTTON_PIN1 5          //next button tray 1
#define BUTTON_PIN2 6          //next button tray 2
#define BUTTON_PIN3 7          //next button tray 3
#define BUTTON_PIN4 8          //next button tray 4
#define BRIGHTNESS 50         //Heto yung adjustment ng brightness

CRGB leds[NUM_LEDS];

int buttonState1 = 0;         
int lastButtonState1 = 0;     
int buttonState2 = 0;         
int lastButtonState2 = 0;
int buttonState3 = 0;         
int lastButtonState3 = 0;
int buttonState4 = 0;         
int lastButtonState4 = 0;
int buttonPushCounter1 = 1001;   //japan tray 1
int buttonPushCounter2 = 2001;   //euro tray 1
int buttonPushCounter3 = 3001;   //nafta tray 1

int buttonPushCounter4 = 4001;   //japan tray 2
int buttonPushCounter5 = 5001;   //euro tray 2
int buttonPushCounter6 = 6001;   //nafta tray 2

int buttonPushCounter7 = 7001;   //japan tray 3
int buttonPushCounter8 = 8001;   //euro tray 3
int buttonPushCounter9 = 9001;   //nafta tray 3

int buttonPushCounter10 = 10001;   //japan tray 4
int buttonPushCounter11 = 11001;   //euro tray 4
int buttonPushCounter12 = 12001;   //nafta tray 4

int japan = 0;
int euro = 0;
int nafta = 0;
void setup()
{
      Serial.begin( 115200 );
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
buttonState1 = digitalRead(BUTTON_PIN1);
buttonState2 = digitalRead(BUTTON_PIN2);
buttonState3= digitalRead(BUTTON_PIN3);
buttonState4 = digitalRead(BUTTON_PIN4);
//==========================================================================================================     DEBOUNCE FOR NEXT BUTTON tray 1
 if (buttonState1 != lastButtonState1)
 {
   if (buttonState1 == HIGH)
   {
      buttonPushCounter1++;// INCREMENT WHEN NEXT BUTTON IS PUSHED
      buttonPushCounter2++;
      buttonPushCounter3++;
      Serial.print(buttonPushCounter1);
      Serial.println( "---------------------------------tray 1 japan" );
      Serial.print(buttonPushCounter2);
      Serial.println( "---------------------------------tray 1 eu" );
      Serial.print(buttonPushCounter3);
      Serial.println( "---------------------------------tray 1 nafta" );
      
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

//==========================================================================================================     DEBOUNCE FOR NEXT BUTTON tray 2
 if (buttonState2 != lastButtonState2)
 {
   if (buttonState2 == HIGH)
   {
      buttonPushCounter4++;// INCREMENT WHEN NEXT BUTTON IS PUSHED
      buttonPushCounter5++;
      buttonPushCounter6++;
      
     Serial.print(buttonPushCounter4);
      Serial.println( "---------------------------------tray 2 japan" );
      Serial.print(buttonPushCounter5);
      Serial.println( "---------------------------------tray 2 eu" );
      Serial.print(buttonPushCounter6);
      Serial.println( "---------------------------------tray 2 nafta" );
   } 
   else
   {
   }
delay(50);
  }
   else
  {
  }
  lastButtonState2 = buttonState2;
//==========================================================================================================     DEBOUNCE FOR NEXT BUTTON tray 3
 if (buttonState3 != lastButtonState3)
 {
   if (buttonState3 == HIGH)
   {
      buttonPushCounter7++;// INCREMENT WHEN NEXT BUTTON IS PUSHED
      buttonPushCounter8++;
      buttonPushCounter9++;
      Serial.print(buttonPushCounter7);
      Serial.println( "---------------------------------tray 3 japan" );
      Serial.print(buttonPushCounter8);
      Serial.println( "---------------------------------tray 3 eu" );
      Serial.print(buttonPushCounter9);
      Serial.println( "---------------------------------tray 3 nafta" );
   } 
   else
   {
   }
delay(50);
  }
   else
  {
  }
  lastButtonState3 = buttonState3;
//==========================================================================================================     DEBOUNCE FOR NEXT BUTTON tray 4
 if (buttonState4 != lastButtonState4)
 {
   if (buttonState4 == HIGH)
   {
      buttonPushCounter10++;// INCREMENT WHEN NEXT BUTTON IS PUSHED
      buttonPushCounter11++;
      buttonPushCounter12++;
      Serial.print(buttonPushCounter10);
      Serial.println( "---------------------------------tray 4 japan" );
      Serial.print(buttonPushCounter11);
      Serial.println( "---------------------------------tray 4 eu" );
      Serial.print(buttonPushCounter12);
      Serial.println( "---------------------------------tray 4 nafta" );
   } 
   else
   {
   }
delay(50);
  }
   else
  {
  }
  lastButtonState4 = buttonState4;

//==========================================================================================================     start of tray 1 japan
if (buttonPushCounter1 == 1000){
            for (int i = 1; i < 38;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 buttonPushCounter1++;
}
else if (buttonPushCounter1 == 1){//1 LED
             leds[1] = CRGB::Blue;
             leds[2] = CRGB::Blue;
             leds[37] = CRGB::Black;
             leds[38] = CRGB::Black;
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
else if (buttonPushCounter1 == 21){//back to 1
if ((buttonPushCounter4 > 3999) && (buttonPushCounter5 > 4999))
{
  buttonPushCounter4 = 1;
  buttonPushCounter1 = 1; 
}
else if((buttonPushCounter4 < 3999) || (buttonPushCounter5 < 4999))
{
  buttonPushCounter1 = 1; 
}
}


//==========================================================================================================     start of tray 2 japan
else if (buttonPushCounter4 == 4000){
             for (int x = 40; x < 79;x++)
            {
               leds[x] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 1){//1 LED
             leds[40] = CRGB::Blue;
             leds[41] = CRGB::Blue;
             leds[76] = CRGB::Black;
             leds[77] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 3){//2
             leds[40] = CRGB::Black;
             leds[41] = CRGB::Black;
             leds[44] = CRGB::Blue;
             leds[45] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 5){//3
             leds[44] = CRGB::Black;
             leds[45] = CRGB::Black;
             leds[48] = CRGB::Blue;
             leds[49] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 7){//4
             leds[48] = CRGB::Black;
             leds[49] = CRGB::Black;
             leds[52] = CRGB::Blue;
             leds[53] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 9){//5
             leds[52] = CRGB::Black;
             leds[53] = CRGB::Black;
             leds[56] = CRGB::Blue;
             leds[57] = CRGB::Blue;
             FastLED.show();
   
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 11){//6
             leds[56] = CRGB::Black;
             leds[57] = CRGB::Black;
             leds[60] = CRGB::Blue;
             leds[61] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 13){//7
             leds[60] = CRGB::Black;
             leds[61] = CRGB::Black;
             leds[64] = CRGB::Blue;
             leds[65] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 15){//8
             leds[64] = CRGB::Black;
             leds[65] = CRGB::Black;
             leds[68] = CRGB::Blue;
             leds[69] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 17){//9
             leds[68] = CRGB::Black;
             leds[69] = CRGB::Black;
             leds[72] = CRGB::Blue;
             leds[73] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 19){//10
             leds[72] = CRGB::Black;
             leds[73] = CRGB::Black;
             leds[76] = CRGB::Blue;
             leds[77] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter4++;
}
else if (buttonPushCounter4 == 21){//back to 1
if ((buttonPushCounter7 > 6999)&&(buttonPushCounter8 > 7999))
{
buttonPushCounter7 = 1;
buttonPushCounter4 = 1;
}

if ((buttonPushCounter7 < 6999)||(buttonPushCounter8 < 7999))
{ 
buttonPushCounter4 = 1; 
}
if (buttonPushCounter1 > 999)
{
  buttonPushCounter4 = 4000;
}
if (buttonPushCounter2 < 1999)
{
  buttonPushCounter5 = 1;
}

}


//==========================================================================================================     start of tray 3 japan
else if (buttonPushCounter7 == 7000){
            for (int i = 80; i < 119;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 1){//1 LED
             leds[80] = CRGB::Blue;
             leds[81] = CRGB::Blue;
             leds[116] = CRGB::Black;
             leds[117] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 3){//2
             leds[80] = CRGB::Black;
             leds[81] = CRGB::Black;
             leds[84] = CRGB::Blue;
             leds[85] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 5){//3
             leds[84] = CRGB::Black;
             leds[85] = CRGB::Black;
             leds[88] = CRGB::Blue;
             leds[89] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 7){//4
             leds[88] = CRGB::Black;
             leds[89] = CRGB::Black;
             leds[92] = CRGB::Blue;
             leds[93] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 9){//5
             leds[92] = CRGB::Black;
             leds[93] = CRGB::Black;
             leds[96] = CRGB::Blue;
             leds[97] = CRGB::Blue;
             FastLED.show();
   
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 11){//6
             leds[96] = CRGB::Black;
             leds[97] = CRGB::Black;
             leds[100] = CRGB::Blue;
             leds[101] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 13){//7
             leds[100] = CRGB::Black;
             leds[101] = CRGB::Black;
             leds[104] = CRGB::Blue;
             leds[105] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 15){//8
             leds[104] = CRGB::Black;
             leds[105] = CRGB::Black;
             leds[108] = CRGB::Blue;
             leds[109] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 17){//9
             leds[108] = CRGB::Black;
             leds[109] = CRGB::Black;
             leds[112] = CRGB::Blue;
             leds[113] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}
else if (buttonPushCounter7 == 19){//10
             leds[112] = CRGB::Black;
             leds[113] = CRGB::Black;
             leds[116] = CRGB::Blue;
             leds[117] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter7++;
}

else if (buttonPushCounter7 == 21){//back to 1
if ((buttonPushCounter10 > 9999)&&(buttonPushCounter11 > 10999))
{
buttonPushCounter10 = 1;
buttonPushCounter7 = 1;
}

if ((buttonPushCounter10 < 9999)||(buttonPushCounter11 < 10999))
{ 
buttonPushCounter7 = 1; 
}
if (buttonPushCounter4 > 3999)
{
  buttonPushCounter7 = 7000;
}
if (buttonPushCounter5 < 4999)
{
  buttonPushCounter8 = 1;
}
}


//==========================================================================================================     start of tray 4 japan
else if (buttonPushCounter10 == 10000){
for (int i = 120; i < 158;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 1){//1 LED
             leds[120] = CRGB::Blue;
             leds[121] = CRGB::Blue;
             leds[156] = CRGB::Black;
             leds[157] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 3){//2
             leds[120] = CRGB::Black;
             leds[121] = CRGB::Black;
             leds[124] = CRGB::Blue;
             leds[125] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 5){//3
             leds[124] = CRGB::Black;
             leds[125] = CRGB::Black;
             leds[128] = CRGB::Blue;
             leds[129] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 7){//4
             leds[128] = CRGB::Black;
             leds[129] = CRGB::Black;
             leds[132] = CRGB::Blue;
             leds[133] = CRGB::Blue;
             FastLED.show();
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 9){//5
             leds[132] = CRGB::Black;
             leds[133] = CRGB::Black;
             leds[136] = CRGB::Blue;
             leds[137] = CRGB::Blue;
             FastLED.show();
   
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 11){//6
             leds[136] = CRGB::Black;
             leds[137] = CRGB::Black;
             leds[140] = CRGB::Blue;
             leds[141] = CRGB::Blue;
             FastLED.show();  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 13){//7
             leds[140] = CRGB::Black;
             leds[141] = CRGB::Black;
             leds[144] = CRGB::Blue;
             leds[145] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 15){//8
             leds[144] = CRGB::Black;
             leds[145] = CRGB::Black;
             leds[148] = CRGB::Blue;
             leds[149] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 17){//9
             leds[148] = CRGB::Black;
             leds[149] = CRGB::Black;
             leds[152] = CRGB::Blue;
             leds[153] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 19){//10
             leds[152] = CRGB::Black;
             leds[153] = CRGB::Black;
             leds[156] = CRGB::Blue;
             leds[157] = CRGB::Blue;
             FastLED.show();  
  
 buttonPushCounter10++;
}
else if (buttonPushCounter10 == 21){//back to 1

if (buttonPushCounter7 > 6999)
{
  buttonPushCounter10 = 10000;
}  
if (buttonPushCounter8 < 7999)
{
  buttonPushCounter11 = 1;
}
else 
{
    buttonPushCounter10 = 1;   
}
}

//==========================================================================================================     start of tray 1 euro
else if (buttonPushCounter2 == 2000){
        for (int i = 160; i < 182;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 1){//1 LED
             leds[160] = CRGB::Red;
             leds[161] = CRGB::Red;
             leds[180] = CRGB::Black;
             leds[181] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 3){//2
             leds[160] = CRGB::Black;
             leds[161] = CRGB::Black;
             leds[164] = CRGB::Red;
             leds[165] = CRGB::Red;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 5){//3
             leds[164] = CRGB::Black;
             leds[165] = CRGB::Black;
             leds[168] = CRGB::Red;
             leds[169] = CRGB::Red;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 7){//4
             leds[168] = CRGB::Black;
             leds[169] = CRGB::Black;
             leds[172] = CRGB::Red;
             leds[173] = CRGB::Red;
             FastLED.show();
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 9){//5
             leds[172] = CRGB::Black;
             leds[173] = CRGB::Black;
             leds[176] = CRGB::Red;
             leds[177] = CRGB::Red;
             FastLED.show();
   
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 11){//6
             leds[176] = CRGB::Black;
             leds[177] = CRGB::Black;
             leds[180] = CRGB::Red;
             leds[181] = CRGB::Red;
             FastLED.show();  
 buttonPushCounter2++;
}
else if (buttonPushCounter2 == 13){//back to 1
if ((buttonPushCounter4 > 3999) && (buttonPushCounter5 > 4999))
{
  buttonPushCounter5 = 1;
  buttonPushCounter2 = 1; 
}
else if((buttonPushCounter4 < 3999) || (buttonPushCounter5 < 4999))
{
  buttonPushCounter2 = 1; 
}   
}


//==========================================================================================================     start of tray 2 euro
else if (buttonPushCounter5 == 5000){
            for (int i = 184; i < 222;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 1){//1 LED
             leds[184] = CRGB::Red;
             leds[185] = CRGB::Red;
             leds[220] = CRGB::Black;
             leds[221] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 3){//2
             leds[184] = CRGB::Black;
             leds[185] = CRGB::Black;
             leds[188] = CRGB::Red;
             leds[189] = CRGB::Red;
             FastLED.show();
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 5){//3
             leds[188] = CRGB::Black;
             leds[189] = CRGB::Black;
             leds[192] = CRGB::Red;
             leds[193] = CRGB::Red;
             FastLED.show();
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 7){//4
             leds[192] = CRGB::Black;
             leds[193] = CRGB::Black;
             leds[196] = CRGB::Red;
             leds[197] = CRGB::Red;
             FastLED.show();
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 9){//5
             leds[196] = CRGB::Black;
             leds[197] = CRGB::Black;
             leds[200] = CRGB::Red;
             leds[201] = CRGB::Red;
             FastLED.show();
   
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 11){//6
             leds[200] = CRGB::Black;
             leds[201] = CRGB::Black;
             leds[204] = CRGB::Red;
             leds[205] = CRGB::Red;
             FastLED.show();  
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 13){//7
             leds[204] = CRGB::Black;
             leds[205] = CRGB::Black;
             leds[208] = CRGB::Red;
             leds[209] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 15){//8
             leds[208] = CRGB::Black;
             leds[209] = CRGB::Black;
             leds[212] = CRGB::Red;
             leds[213] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 17){//9
             leds[212] = CRGB::Black;
             leds[213] = CRGB::Black;
             leds[216] = CRGB::Red;
             leds[217] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 19){//10
             leds[216] = CRGB::Black;
             leds[217] = CRGB::Black;
             leds[220] = CRGB::Red;
             leds[221] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter5++;
}
else if (buttonPushCounter5 == 21){//back to 1
if ((buttonPushCounter7 > 6999)&&(buttonPushCounter8 > 7999))
{
buttonPushCounter8 = 1;
buttonPushCounter5 = 1;
}

if ((buttonPushCounter7 < 6999)||(buttonPushCounter8 < 7999))
{ 
buttonPushCounter5 = 1; 
}
if (buttonPushCounter2 > 1999)
{
  buttonPushCounter5 = 5000;
} 
if (buttonPushCounter1 < 999)
{
  buttonPushCounter4 = 1;
}     
}


//==========================================================================================================     start of tray 3 euro

else if (buttonPushCounter8 == 8000){
          for (int i = 225; i < 263;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 1){//1 LED
             leds[225] = CRGB::Red;
             leds[226] = CRGB::Red;
             leds[261] = CRGB::Black;
             leds[262] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 3){//2
             leds[225] = CRGB::Black;
             leds[226] = CRGB::Black;
             leds[229] = CRGB::Red;
             leds[230] = CRGB::Red;
             FastLED.show();
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 5){//3
             leds[229] = CRGB::Black;
             leds[230] = CRGB::Black;
             leds[233] = CRGB::Red;
             leds[234] = CRGB::Red;
             FastLED.show();
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 7){//4
             leds[233] = CRGB::Black;
             leds[234] = CRGB::Black;
             leds[237] = CRGB::Red;
             leds[238] = CRGB::Red;
             FastLED.show();
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 9){//5
             leds[237] = CRGB::Black;
             leds[238] = CRGB::Black;
             leds[241] = CRGB::Red;
             leds[242] = CRGB::Red;
             FastLED.show();
   
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 11){//6
             leds[241] = CRGB::Black;
             leds[242] = CRGB::Black;
             leds[245] = CRGB::Red;
             leds[246] = CRGB::Red;
             FastLED.show();  
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 13){//7
             leds[245] = CRGB::Black;
             leds[246] = CRGB::Black;
             leds[249] = CRGB::Red;
             leds[250] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 15){//8
             leds[249] = CRGB::Black;
             leds[250] = CRGB::Black;
             leds[253] = CRGB::Red;
             leds[254] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 17){//9
             leds[253] = CRGB::Black;
             leds[254] = CRGB::Black;
             leds[257] = CRGB::Red;
             leds[258] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter8++;
}
else if (buttonPushCounter8 == 19){//10
             leds[257] = CRGB::Black;
             leds[258] = CRGB::Black;
             leds[261] = CRGB::Red;
             leds[262] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter8++;
}

else if (buttonPushCounter8 == 21){//back to 1
if ((buttonPushCounter10 > 9999)&&(buttonPushCounter11 > 10999))
{
buttonPushCounter11 = 1;
buttonPushCounter8 = 1;
}

if ((buttonPushCounter10 < 9999)||(buttonPushCounter11 < 10999))
{ 
buttonPushCounter8 = 1; 
}
if (buttonPushCounter5 > 4999)
{
  buttonPushCounter8 = 8000;
}   
if (buttonPushCounter4 < 3999)
{
  buttonPushCounter7 = 1;
}  
}


//==========================================================================================================     start of tray 4 euro

else if (buttonPushCounter11 == 11000){
             for (int i = 265; i < 300;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 1){//1 LED
             leds[265] = CRGB::Red;
             leds[266] = CRGB::Red;
             leds[297] = CRGB::Black;
             leds[298] = CRGB::Black;
             FastLED.show();  
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 3){//2
             leds[265] = CRGB::Black;
             leds[266] = CRGB::Black;
             leds[269] = CRGB::Red;
             leds[270] = CRGB::Red;
             FastLED.show();
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 5){//3
             leds[269] = CRGB::Black;
             leds[270] = CRGB::Black;
             leds[273] = CRGB::Red;
             leds[274] = CRGB::Red;
             FastLED.show();
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 7){//4
             leds[273] = CRGB::Black;
             leds[274] = CRGB::Black;
             leds[277] = CRGB::Red;
             leds[278] = CRGB::Red;
             FastLED.show();
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 9){//5
             leds[277] = CRGB::Black;
             leds[278] = CRGB::Black;
             leds[281] = CRGB::Red;
             leds[282] = CRGB::Red;
             FastLED.show();
   
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 11){//6
             leds[281] = CRGB::Black;
             leds[282] = CRGB::Black;
             leds[285] = CRGB::Red;
             leds[286] = CRGB::Red;
             FastLED.show();  
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 13){//7
             leds[285] = CRGB::Black;
             leds[286] = CRGB::Black;
             leds[289] = CRGB::Red;
             leds[290] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 15){//8
             leds[289] = CRGB::Black;
             leds[290] = CRGB::Black;
             leds[293] = CRGB::Red;
             leds[294] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 17){//9
             leds[293] = CRGB::Black;
             leds[294] = CRGB::Black;
             leds[297] = CRGB::Red;
             leds[298] = CRGB::Red;
             FastLED.show();  
  
 buttonPushCounter11++;
}
else if (buttonPushCounter11 == 19){//back to 1
if (buttonPushCounter8 > 7999)
{
  buttonPushCounter11 = 11000;
} 
if (buttonPushCounter7 < 6999)
{
  buttonPushCounter10 = 1;
}   
else 
{
    buttonPushCounter11 = 1;   
}       
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

  buttonPushCounter1 = 1;
  buttonPushCounter2 = 2000;
  buttonPushCounter3 = 3000;
  delay(500);
 }
if (euro == HIGH)
  {
  buttonPushCounter1 = 1000;
  buttonPushCounter2 = 1;
  buttonPushCounter3 = 3000;
  delay(500);
  }
if (nafta == HIGH)
  {
  buttonPushCounter1 = 1000;
  buttonPushCounter2 = 2000;
  buttonPushCounter3 = 1;
  delay(500);
  }



  ex:;
}

