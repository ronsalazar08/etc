
#include "FastLED.h"

#define NUM_LEDS 300            //heto ang bilang ng LED
#define DATA_PIN 12             // data pin for digital LED strip
#define BUTTON_PINP1 2          //P1 319
#define BUTTON_PINP2 3          //P2 320
#define BUTTON_PINP3 4          //P3 321
#define BUTTON_PINP4 5          //P4 322
#define BUTTON_PIN1 6           //next button tray 1
#define BUTTON_PIN2 7           //next button tray 2
#define BUTTON_PIN3 8           //next button tray 3
#define BUTTON_PIN4 9           //next button tray 4
#define BRIGHTNESS 50           //Heto yung adjustment ng brightness

CRGB leds[NUM_LEDS];

int buttonState1 = 0;         
int lastButtonState1 = 0;     
int buttonState2 = 0;         
int lastButtonState2 = 0;
int buttonState3 = 0;         
int lastButtonState3 = 0;
int buttonState4 = 0;         
int lastButtonState4 = 0;
int P1T1 = 1001;   //P1 tray 1
int P2T1 = 1001;   //P2 tray 1
int P3T1 = 1001;   //P3 tray 1
int P4T1 = 1001;   //P4 tray 1

int P1T2 = 1001;   //P1 tray 2
int P2T2 = 1001;   //P2 tray 2
int P3T2 = 1001;   //P3 tray 2
int P4T2 = 1001;   //P4tray 2


int P1T3 = 1001;   //P1 tray 3
int P2T3 = 1001;   //P2 tray 3
int P3T3 = 1001;   //P3 tray 3
int P4T3 = 1001;   //P4 tray 3

int P1T4 = 1001;   //P1 tray 4
int P2T4 = 1001;   //P2 tray 4
int P3T4 = 1001;   //P3 tray 4
int P4T4 = 1001;   //P4 tray 4

int P1 = 0;
int P2 = 0;
int P3 = 0;
int P4 = 0;
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

P1 = digitalRead(BUTTON_PINP1);
P2 = digitalRead(BUTTON_PINP2);
P3 = digitalRead(BUTTON_PINP3);
P4 = digitalRead(BUTTON_PINP4);
buttonState1 = digitalRead(BUTTON_PIN1);
buttonState2 = digitalRead(BUTTON_PIN2);
buttonState3 = digitalRead(BUTTON_PIN3);
buttonState4 = digitalRead(BUTTON_PIN4);
//==========================================================================================================     DEBOUNCE FOR NEXT BUTTON tray 1
 if (buttonState1 != lastButtonState1)
 {
   if (buttonState1 == HIGH)
   {
      P1T1++;// INCREMENT WHEN NEXT BUTTON IS PUSHED
      P2T1++;
      P3T1++;
      P4T1++;
      Serial.print(P1T1);
      Serial.println( "---------------------------------tray 1 P1" );
      Serial.print(P2T1);
      Serial.println( "---------------------------------tray 1 P2" );
      Serial.print(P3T1);
      Serial.println( "---------------------------------tray 1 P3" );
      Serial.print(P4T1);
      Serial.println( "---------------------------------tray 1 P3" );
      
      
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
      P1T2++;// INCREMENT WHEN NEXT BUTTON IS PUSHED
      P2T2++;
      P3T2++;
      P4T2++;
      
     Serial.print(P1T2);
      Serial.println( "---------------------------------tray 2 P1" );
      Serial.print(P2T2);
      Serial.println( "---------------------------------tray 2 P2" );
      Serial.print(P3T2);
      Serial.println( "---------------------------------tray 2 P3" );
      Serial.print(P4T2);
      Serial.println( "---------------------------------tray 2 P3" );
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
      P1T3++;// INCREMENT WHEN NEXT BUTTON IS PUSHED
      P2T3++;
      P3T3++;
      P4T3++;
      Serial.print(P1T3);
      Serial.println( "---------------------------------tray 3 P1" );
      Serial.print(P2T3);
      Serial.println( "---------------------------------tray 3 P2" );
      Serial.print(P3T3);
      Serial.println( "---------------------------------tray 3 P3" );
      Serial.print(P4T3);
      Serial.println( "---------------------------------tray 3 P3" );
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
      P1T4++;// INCREMENT WHEN NEXT BUTTON IS PUSHED
      P2T4++;
      P3T4++;
      P4T4++;
      Serial.print(P1T4);
      Serial.println( "---------------------------------tray 4 P1" );
      Serial.print(P2T4);
      Serial.println( "---------------------------------tray 4 P2" );
      Serial.print(P3T4);
      Serial.println( "---------------------------------tray 4 P3" );
      Serial.print(P4T4);
      Serial.println( "---------------------------------tray 4 P3" );
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

//==========================================================================================================     start of tray 1 P1
if (P1T1 == 1000){
            for (int i = 1; i < 19;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P1T1++;
}
else if (P1T1 == 1){//1 LED
             leds[1] = CRGB::Blue;
             leds[2] = CRGB::Blue;
             leds[17] = CRGB::Black;
             leds[18] = CRGB::Black;
             FastLED.show();  
 P1T1++;
}
else if (P1T1 == 3){//2
             leds[1] = CRGB::Black;
             leds[2] = CRGB::Black;
             leds[5] = CRGB::Blue;
             leds[6] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
else if (P1T1 == 5){//3
             leds[5] = CRGB::Black;
             leds[6] = CRGB::Black;
             leds[9] = CRGB::Blue;
             leds[10] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
else if (P1T1 == 7){//4
             leds[9] = CRGB::Black;
             leds[10] = CRGB::Black;
             leds[13] = CRGB::Blue;
             leds[14] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
else if (P1T1 == 9){//5
             leds[13] = CRGB::Black;
             leds[14] = CRGB::Black;
             leds[17] = CRGB::Blue;
             leds[18] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 == 11){//back to 1
if ((P1T2 > 999) && (P2T2 > 999) && (P3T2 > 999) && (P4T2 > 999))
{
  P1T2 = 1;
  P1T1 = 1; 
}
else if((P1T2 < 999) || (P2T2 < 999) || (P3T2 < 999) || (P3T2 < 999))
{
  P1T1 = 1; 
}
}


//==========================================================================================================     start of tray 2 P1
else if (P1T2 == 1000){
             for (int x = 21; x < 39;x++)
            {
               leds[x] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P1T2++;
}
else if (P1T2 == 1){//1 LED
             leds[21] = CRGB::Blue;
             leds[22] = CRGB::Blue;
             leds[37] = CRGB::Black;
             leds[38] = CRGB::Black;
             FastLED.show();  
 P1T2++;
}
else if (P1T2 == 3){//2
             leds[21] = CRGB::Black;
             leds[22] = CRGB::Black;
             leds[25] = CRGB::Blue;
             leds[26] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
else if (P1T2 == 5){//3
             leds[25] = CRGB::Black;
             leds[26] = CRGB::Black;
             leds[29] = CRGB::Blue;
             leds[30] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
else if (P1T2 == 7){//4
             leds[29] = CRGB::Black;
             leds[30] = CRGB::Black;
             leds[33] = CRGB::Blue;
             leds[34] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
else if (P1T2 == 9){//5
             leds[33] = CRGB::Black;
             leds[34] = CRGB::Black;
             leds[37] = CRGB::Blue;
             leds[38] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 == 11){//back to 1
if ((P1T3 > 999)&&(P2T3 > 999)&&(P3T3 > 999)&&(P3T3 > 999))
{
P1T3 = 1;
P1T2 = 1;
}

if ((P1T3 < 999)||(P2T3 < 999)||(P3T3 < 999)||(P3T3 < 999))
{ 
P1T2 = 1; 
}
if (P1T1 > 999)
{
  P1T2 = 1000;
}
if (P2T1 < 999)
{
  P2T2 = 1;
}
if (P3T1 < 999)
{
  P3T2 = 1;
}
if (P4T1 < 999)
{
  P4T2 = 1;
}
}


//==========================================================================================================     start of tray 3 P1
else if (P1T3 == 1000){
            for (int i = 41; i < 59;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P1T3++;
}
else if (P1T3 == 1){//1 LED
             leds[41] = CRGB::Blue;
             leds[42] = CRGB::Blue;
             leds[57] = CRGB::Black;
             leds[58] = CRGB::Black;
             FastLED.show();  
 P1T3++;
}
else if (P1T3 == 3){//2
             leds[41] = CRGB::Black;
             leds[42] = CRGB::Black;
             leds[45] = CRGB::Blue;
             leds[46] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
else if (P1T3 == 5){//3
             leds[45] = CRGB::Black;
             leds[46] = CRGB::Black;
             leds[49] = CRGB::Blue;
             leds[50] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
else if (P1T3 == 7){//4
             leds[49] = CRGB::Black;
             leds[50] = CRGB::Black;
             leds[53] = CRGB::Blue;
             leds[54] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
else if (P1T3 == 9){//5
             leds[53] = CRGB::Black;
             leds[54] = CRGB::Black;
             leds[57] = CRGB::Blue;
             leds[58] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 == 11){//back to 1
if ((P1T4 > 999)&&(P2T4 > 999)&&(P3T4 > 999)&&(P3T4 > 999))
{
P1T4 = 1;
P1T3 = 1;
}

if ((P1T4 < 999)||(P2T4 < 999)||(P3T4 < 999)||(P3T4 < 999))
{ 
P1T3 = 1; 
}
if (P1T2 > 999)
{
  P1T3 = 1000;
}
if (P2T2 < 999)
{
  P2T3 = 1;
}
if (P3T2 < 999)
{
  P3T3 = 1;
}
if (P4T2 < 999)
{
  P4T3 = 1;
}
}


//==========================================================================================================     start of tray 4 P1
else if (P1T4 == 1000){
for (int i = 61; i < 79;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P1T4++;
}
else if (P1T4 == 1){//1 LED
             leds[61] = CRGB::Blue;
             leds[62] = CRGB::Blue;
             leds[77] = CRGB::Black;
             leds[78] = CRGB::Black;
             FastLED.show();  
 P1T4++;
}
else if (P1T4 == 3){//2
             leds[61] = CRGB::Black;
             leds[62] = CRGB::Black;
             leds[65] = CRGB::Blue;
             leds[66] = CRGB::Blue;
             FastLED.show();
 P1T4++;
}
else if (P1T4 == 5){//3
             leds[65] = CRGB::Black;
             leds[66] = CRGB::Black;
             leds[69] = CRGB::Blue;
             leds[70] = CRGB::Blue;
             FastLED.show();
 P1T4++;
}
else if (P1T4 == 7){//4
             leds[69] = CRGB::Black;
             leds[70] = CRGB::Black;
             leds[73] = CRGB::Blue;
             leds[74] = CRGB::Blue;
             FastLED.show();
 P1T4++;
}
else if (P1T4 == 9){//5
             leds[73] = CRGB::Black;
             leds[74] = CRGB::Black;
             leds[77] = CRGB::Blue;
             leds[78] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 == 11){//back to 1

if (P1T3 > 999)
{
  P1T4 = 1000;
}  
if (P2T3 < 999)
{
  P2T4 = 1;
}
if (P3T3 < 999)
{
  P3T4 = 1;
}if (P4T3 < 999)
{
  P4T4 = 1;
}
if (P1T3 < 999)
{
  P1T4 = 1;
}  
}

//==========================================================================================================     start of tray 1 P2
else if (P2T1 == 1000){
        for (int i = 81; i < 99;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P2T1++;
}
else if (P2T1 == 1){//1 LED
             leds[81] = CRGB::Red;
             leds[82] = CRGB::Red;
             leds[97] = CRGB::Black;
             leds[98] = CRGB::Black;
             FastLED.show();  
 P2T1++;
}
else if (P2T1 == 3){//2
             leds[81] = CRGB::Black;
             leds[82] = CRGB::Black;
             leds[85] = CRGB::Red;
             leds[86] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
else if (P2T1 == 5){//3
             leds[85] = CRGB::Black;
             leds[86] = CRGB::Black;
             leds[89] = CRGB::Red;
             leds[90] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
else if (P2T1 == 7){//4
             leds[89] = CRGB::Black;
             leds[90] = CRGB::Black;
             leds[93] = CRGB::Red;
             leds[94] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
else if (P2T1 == 9){//5
             leds[93] = CRGB::Black;
             leds[94] = CRGB::Black;
             leds[97] = CRGB::Red;
             leds[98] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 == 11){//back to 1
if ((P1T2 > 999) && (P2T2 > 999)&& (P3T2 > 999)&& (P4T2 > 999))
{
  P2T2 = 1;
  P2T1 = 1; 
}
else if((P1T2 < 999) || (P2T2 < 999)|| (P3T2 < 999)|| (P3T2 < 999))
{
  P2T1 = 1; 
}   
}


//==========================================================================================================     start of tray 2 P2
else if (P2T2 == 1000){
            for (int i = 101; i < 119;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P2T2++;
}
else if (P2T2 == 1){//1 LED
             leds[101] = CRGB::Red;
             leds[102] = CRGB::Red;
             leds[117] = CRGB::Black;
             leds[118] = CRGB::Black;
             FastLED.show();  
 P2T2++;
}
else if (P2T2 == 3){//2
             leds[101] = CRGB::Black;
             leds[102] = CRGB::Black;
             leds[105] = CRGB::Red;
             leds[106] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
else if (P2T2 == 5){//3
             leds[105] = CRGB::Black;
             leds[106] = CRGB::Black;
             leds[109] = CRGB::Red;
             leds[110] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
else if (P2T2 == 7){//4
             leds[109] = CRGB::Black;
             leds[110] = CRGB::Black;
             leds[113] = CRGB::Red;
             leds[114] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
else if (P2T2 == 9){//5
             leds[113] = CRGB::Black;
             leds[114] = CRGB::Black;
             leds[117] = CRGB::Red;
             leds[118] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 == 11){//back to 1
if ((P1T3 > 999)&&(P2T3 > 999)&&(P3T3 > 999)&&(P4T3 > 999))
{
P2T3 = 1;
P2T2 = 1;
}
if ((P1T3 < 999)||(P2T3 < 999)||(P3T3 < 999)||(P3T3 < 999))
{ 
P2T2 = 1; 
}
if (P2T1 > 999)
{
  P2T2 = 1000;
} 
if (P1T1 < 999)
{
  P1T2 = 1;
}      
if (P3T1 < 999)
{
  P3T2 = 1;
}  
if (P4T1 < 999)
{
  P4T2 = 1;
}         
}


//==========================================================================================================     start of tray 3 P2

else if (P2T3 == 1000){
          for (int i = 121; i < 139;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P2T3++;
}
else if (P2T3 == 1){//1 LED
             leds[121] = CRGB::Red;
             leds[122] = CRGB::Red;
             leds[137] = CRGB::Black;
             leds[138] = CRGB::Black;
             FastLED.show();  
 P2T3++;
}
else if (P2T3 == 3){//2
             leds[121] = CRGB::Black;
             leds[122] = CRGB::Black;
             leds[125] = CRGB::Red;
             leds[126] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
else if (P2T3 == 5){//3
             leds[125] = CRGB::Black;
             leds[126] = CRGB::Black;
             leds[129] = CRGB::Red;
             leds[130] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
else if (P2T3 == 7){//4
             leds[129] = CRGB::Black;
             leds[130] = CRGB::Black;
             leds[133] = CRGB::Red;
             leds[134] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
else if (P2T3 == 9){//5
             leds[133] = CRGB::Black;
             leds[134] = CRGB::Black;
             leds[137] = CRGB::Red;
             leds[138] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 == 11){//back to 1
if ((P1T4 > 999)&&(P2T4 > 999)&&(P3T4 > 999)&&(P4T4 > 999))
{
P2T4 = 1;
P2T3 = 1;
}

if ((P1T4 < 999)||(P2T4 < 999)||(P3T4 < 999)||(P4T4 < 999))
{ 
P2T3 = 1; 
}
if (P2T2 > 999)
{
  P2T3 = 1000;
}   
if (P1T2 < 999)
{
  P1T3 = 1;
}   
if (P3T2 < 999)
{
  P3T3 = 1;
}  
if (P4T2 < 999)
{
  P3T3 = 1;
}   
}


//==========================================================================================================     start of tray 4 P2

else if (P2T4 == 1000){
             for (int i = 141; i < 159;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P2T4++;
}
else if (P2T4 == 1){//1 LED
             leds[141] = CRGB::Red;
             leds[142] = CRGB::Red;
             leds[157] = CRGB::Black;
             leds[158] = CRGB::Black;
             FastLED.show();  
 P2T4++;
}
else if (P2T4 == 3){//2
             leds[141] = CRGB::Black;
             leds[142] = CRGB::Black;
             leds[145] = CRGB::Red;
             leds[146] = CRGB::Red;
             FastLED.show();
 P2T4++;
}
else if (P2T4 == 5){//3
             leds[145] = CRGB::Black;
             leds[146] = CRGB::Black;
             leds[149] = CRGB::Red;
             leds[150] = CRGB::Red;
             FastLED.show();
 P2T4++;
}
else if (P2T4 == 7){//4
             leds[149] = CRGB::Black;
             leds[150] = CRGB::Black;
             leds[153] = CRGB::Red;
             leds[154] = CRGB::Red;
             FastLED.show();
 P2T4++;
}
else if (P2T4 == 9){//5
             leds[153] = CRGB::Black;
             leds[154] = CRGB::Black;
             leds[157] = CRGB::Red;
             leds[158] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 == 11){//back to 1
if (P2T3 > 999)
{
  P2T4 = 1000;
} 
if (P1T3 < 999)
{
  P1T4 = 1;
}   
if (P3T3 < 999)
{
  P3T4 = 1;
}   
if (P4T3 < 999)
{
  P4T4 = 1;
}   
 if (P2T3 < 999)
{
  P2T4 = 1;
}      
}

//==========================================================================================================     start of tray 1 P3

if (P3T1 == 1000){
            for (int i = 161; i < 179;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P3T1++;
}
else if (P3T1 == 1){//1 LED
             leds[161] = CRGB::Green;
             leds[162] = CRGB::Green;
             leds[177] = CRGB::Black;
             leds[178] = CRGB::Black;
             FastLED.show();  
 P3T1++;
}
else if (P3T1 == 3){//2
             leds[161] = CRGB::Black;
             leds[162] = CRGB::Black;
             leds[165] = CRGB::Green;
             leds[166] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
else if (P3T1 == 5){//3
             leds[165] = CRGB::Black;
             leds[166] = CRGB::Black;
             leds[169] = CRGB::Green;
             leds[170] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
else if (P3T1 == 7){//4
             leds[169] = CRGB::Black;
             leds[170] = CRGB::Black;
             leds[173] = CRGB::Green;
             leds[174] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
else if (P3T1 == 9){//5
             leds[173] = CRGB::Black;
             leds[174] = CRGB::Black;
             leds[177] = CRGB::Green;
             leds[178] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 == 11){//back to 1
if ((P1T2 > 999) && (P2T2 > 999) && (P3T2 > 999) && (P4T2 > 999))
{
  P3T2 = 1;
  P3T1 = 1; 
}
else if((P1T2 < 999) || (P2T2 < 999) || (P3T2 < 999) || (P3T2 < 999))
{
  P3T1 = 1; 
}
}


//==========================================================================================================     start of tray 2 P3

else if (P3T2 == 1000){
             for (int x = 181; x < 200;x++)
            {
               leds[x] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P3T2++;
}
else if (P3T2 == 1){//1 LED
             leds[181] = CRGB::Green;
             leds[182] = CRGB::Green;
             leds[197] = CRGB::Black;
             leds[198] = CRGB::Black;
             FastLED.show();  
 P3T2++;
}
else if (P3T2 == 3){//2
             leds[181] = CRGB::Black;
             leds[182] = CRGB::Black;
             leds[185] = CRGB::Green;
             leds[186] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
else if (P3T2 == 5){//3
             leds[185] = CRGB::Black;
             leds[186] = CRGB::Black;
             leds[189] = CRGB::Green;
             leds[190] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
else if (P3T2 == 7){//4
             leds[189] = CRGB::Black;
             leds[190] = CRGB::Black;
             leds[193] = CRGB::Green;
             leds[194] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
else if (P3T2 == 9){//5
             leds[193] = CRGB::Black;
             leds[194] = CRGB::Black;
             leds[197] = CRGB::Green;
             leds[198] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 == 11){//back to 1
if ((P1T3 > 999)&&(P2T3 > 999)&&(P3T3 > 999)&&(P3T3 > 999))
{
P3T3 = 1;
P3T2 = 1;
}

if ((P1T3 < 999)||(P2T3 < 999)||(P3T3 < 999)||(P3T3 < 999))
{ 
P3T2 = 1; 
}
if (P3T1 > 999)
{
  P3T2 = 1000;
}
if (P2T1 < 999)
{
  P2T2 = 1;
}
if (P1T1 < 999)
{
  P1T2 = 1;
}
if (P4T1 < 999)
{
  P4T2 = 1;
}
}


//==========================================================================================================     start of tray 3 P3

else if (P3T3 == 1000){
            for (int i = 201; i < 219;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P3T3++;
}
else if (P3T3 == 1){//1 LED
             leds[201] = CRGB::Green;
             leds[202] = CRGB::Green;
             leds[217] = CRGB::Black;
             leds[218] = CRGB::Black;
             FastLED.show();  
 P3T3++;
}
else if (P3T3 == 3){//2
             leds[201] = CRGB::Black;
             leds[202] = CRGB::Black;
             leds[205] = CRGB::Green;
             leds[206] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
else if (P3T3 == 5){//3
             leds[205] = CRGB::Black;
             leds[206] = CRGB::Black;
             leds[209] = CRGB::Green;
             leds[210] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
else if (P3T3 == 7){//4
             leds[209] = CRGB::Black;
             leds[210] = CRGB::Black;
             leds[213] = CRGB::Green;
             leds[214] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
else if (P3T3 == 9){//5
             leds[213] = CRGB::Black;
             leds[214] = CRGB::Black;
             leds[217] = CRGB::Green;
             leds[218] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 == 11){//back to 1
if ((P1T4 > 999)&&(P2T4 > 999)&&(P3T4 > 999)&&(P3T4 > 999))
{
P3T4 = 1;
P3T3 = 1;
}

if ((P1T4 < 999)||(P2T4 < 999)||(P3T4 < 999)||(P3T4 < 999))
{ 
P3T3 = 1; 
}
if (P3T2 > 999)
{
  P3T3 = 1000;
}
if (P2T2 < 999)
{
  P2T3 = 1;
}
if (P1T2 < 999)
{
  P1T3 = 1;
}
if (P4T2 < 999)
{
  P4T3 = 1;
}
}


//==========================================================================================================     start of tray 4 P3
else if (P3T4 == 1000){
for (int i = 221; i < 239;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P3T4++;
}
else if (P3T4 == 1){//1 LED
             leds[221] = CRGB::Green;
             leds[222] = CRGB::Green;
             leds[237] = CRGB::Black;
             leds[238] = CRGB::Black;
             FastLED.show();  
 P3T4++;
}
else if (P3T4 == 3){//2
             leds[221] = CRGB::Black;
             leds[222] = CRGB::Black;
             leds[225] = CRGB::Green;
             leds[226] = CRGB::Green;
             FastLED.show();
 P3T4++;
}
else if (P3T4 == 5){//3
             leds[225] = CRGB::Black;
             leds[226] = CRGB::Black;
             leds[229] = CRGB::Green;
             leds[230] = CRGB::Green;
             FastLED.show();
 P3T4++;
}
else if (P3T4 == 7){//4
             leds[229] = CRGB::Black;
             leds[230] = CRGB::Black;
             leds[233] = CRGB::Green;
             leds[234] = CRGB::Green;
             FastLED.show();
 P3T4++;
}
else if (P3T4 == 9){//5
             leds[233] = CRGB::Black;
             leds[234] = CRGB::Black;
             leds[237] = CRGB::Green;
             leds[238] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 == 11){//back to 1

if (P3T3 > 999)
{
  P3T4 = 1000;
}  
if (P2T3 < 999)
{
  P2T4 = 1;
}
if (P1T3 < 999)
{
  P1T4 = 1;
}if (P4T3 < 999)
{
  P4T4 = 1;
}
if (P3T3 < 999)
{
  P3T4 = 1;
}  
}




//==========================================================================================================     start of tray 1 P4

if (P4T1 == 1000){
            for (int i = 241; i < 259;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P4T1++;
}
else if (P4T1 == 1){//1 LED
             leds[241] = CRGB::Yellow;
             leds[242] = CRGB::Yellow;
             leds[257] = CRGB::Black;
             leds[258] = CRGB::Black;
             FastLED.show();  
 P4T1++;
}
else if (P4T1 == 3){//2
             leds[241] = CRGB::Black;
             leds[242] = CRGB::Black;
             leds[245] = CRGB::Yellow;
             leds[246] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
else if (P4T1 == 5){//3
             leds[245] = CRGB::Black;
             leds[246] = CRGB::Black;
             leds[249] = CRGB::Yellow;
             leds[250] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
else if (P4T1 == 7){//4
             leds[249] = CRGB::Black;
             leds[250] = CRGB::Black;
             leds[253] = CRGB::Yellow;
             leds[254] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
else if (P4T1 == 9){//5
             leds[253] = CRGB::Black;
             leds[254] = CRGB::Black;
             leds[257] = CRGB::Yellow;
             leds[258] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 == 11){//back to 1
if ((P1T2 > 999) && (P2T2 > 999) && (P3T2 > 999) && (P4T2 > 999))
{
  P4T2 = 1;
  P4T1 = 1; 
}
else if((P1T2 < 999) || (P2T2 < 999) || (P3T2 < 999) || (P4T2 < 999))
{
  P4T1 = 1; 
}
}


//==========================================================================================================     start of tray 2 P4
else if (P4T2 == 1000){
             for (int x = 261; x < 279;x++)
            {
               leds[x] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P4T2++;
}
else if (P4T2 == 1){//1 LED
             leds[261] = CRGB::Yellow;
             leds[262] = CRGB::Yellow;
             leds[277] = CRGB::Black;
             leds[278] = CRGB::Black;
             FastLED.show();  
 P4T2++;
}
else if (P4T2 == 3){//2
             leds[261] = CRGB::Black;
             leds[262] = CRGB::Black;
             leds[265] = CRGB::Yellow;
             leds[266] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
else if (P4T2 == 5){//3
             leds[265] = CRGB::Black;
             leds[266] = CRGB::Black;
             leds[269] = CRGB::Yellow;
             leds[270] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
else if (P4T2 == 7){//4
             leds[269] = CRGB::Black;
             leds[270] = CRGB::Black;
             leds[273] = CRGB::Yellow;
             leds[274] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
else if (P4T2 == 9){//5
             leds[273] = CRGB::Black;
             leds[274] = CRGB::Black;
             leds[277] = CRGB::Yellow;
             leds[278] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 == 11){//back to 1
if ((P1T3 > 999)&&(P2T3 > 999)&&(P3T3 > 999)&&(P4T3 > 999))
{
P4T3 = 1;
P4T2 = 1;
}

if ((P1T3 < 999)||(P2T3 < 999)||(P3T3 < 999)||(P4T3 < 999))
{ 
P4T2 = 1; 
}
if (P4T1 > 999)
{
  P4T2 = 1000;
}
if (P2T1 < 999)
{
  P2T2 = 1;
}
if (P3T1 < 999)
{
  P3T2 = 1;
}
if (P1T1 < 999)
{
  P1T2 = 1;
}
}


//==========================================================================================================     start of tray 3 P4
else if (P4T3 == 1000){
            for (int i = 281; i < 299;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P4T3++;
}
else if (P4T3 == 1){//1 LED
             leds[281] = CRGB::Yellow;
             leds[282] = CRGB::Yellow;
             leds[297] = CRGB::Black;
             leds[298] = CRGB::Black;
             FastLED.show();  
 P4T3++;
}
else if (P4T3 == 3){//2
             leds[281] = CRGB::Black;
             leds[282] = CRGB::Black;
             leds[285] = CRGB::Yellow;
             leds[286] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
else if (P4T3 == 5){//3
             leds[285] = CRGB::Black;
             leds[286] = CRGB::Black;
             leds[289] = CRGB::Yellow;
             leds[290] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
else if (P4T3 == 7){//4
             leds[289] = CRGB::Black;
             leds[290] = CRGB::Black;
             leds[293] = CRGB::Yellow;
             leds[294] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
else if (P4T3 == 9){//5
             leds[293] = CRGB::Black;
             leds[294] = CRGB::Black;
             leds[297] = CRGB::Yellow;
             leds[298] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 == 11){//back to 1
if ((P1T4 > 999)&&(P2T4 > 999)&&(P3T4 > 999)&&(P4T4 > 999))
{
P4T4 = 1;
P4T3 = 1;
}

if ((P1T4 < 999)||(P2T4 < 999)||(P3T4 < 999)||(P4T4 < 999))
{ 
P4T3 = 1; 
}
if (P4T2 > 999)
{
  P4T3 = 1000;
}
if (P2T2 < 999)
{
  P2T3 = 1;
}
if (P3T2 < 999)
{
  P3T3 = 1;
}
if (P1T2 < 999)
{
  P1T3 = 1;
}
}


//==========================================================================================================     start of tray 4 P4
else if (P4T4 == 1000){
for (int i = 61; i < 79;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P4T4++;
}
else if (P4T4 == 1){//1 LED
             leds[61] = CRGB::Yellow;
             leds[62] = CRGB::Yellow;
             leds[77] = CRGB::Black;
             leds[78] = CRGB::Black;
             FastLED.show();  
 P4T4++;
}
else if (P4T4 == 3){//2
             leds[61] = CRGB::Black;
             leds[62] = CRGB::Black;
             leds[65] = CRGB::Yellow;
             leds[66] = CRGB::Yellow;
             FastLED.show();
 P4T4++;
}
else if (P4T4 == 5){//3
             leds[65] = CRGB::Black;
             leds[66] = CRGB::Black;
             leds[69] = CRGB::Yellow;
             leds[70] = CRGB::Yellow;
             FastLED.show();
 P4T4++;
}
else if (P4T4 == 7){//4
             leds[69] = CRGB::Black;
             leds[70] = CRGB::Black;
             leds[73] = CRGB::Yellow;
             leds[74] = CRGB::Yellow;
             FastLED.show();
 P4T4++;
}
else if (P4T4 == 9){//5
             leds[73] = CRGB::Black;
             leds[74] = CRGB::Black;
             leds[77] = CRGB::Yellow;
             leds[78] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
else if (P4T4 == 11){//back to 1

if (P4T3 > 999)
{
  P4T4 = 1000;
}  
if (P2T3 < 999)
{
  P2T4 = 1;
}
if (P3T3 < 999)
{
  P3T4 = 1;
}if (P1T3 < 999)
{
  P1T4 = 1;
}
if (P4T3 < 999)
{
  P4T4 = 1;
} 
}



//==========================================================================================================     products
if (P1 == HIGH)
 {

  P1T1 = 1;
  P2T1 = 1000;
  P3T1 = 1000;
  P4T1 = 1000;
  delay(500);
 }
if (P2 == HIGH)
  {
  P1T1 = 1000;
  P2T1 = 1;
  P3T1 = 1000;
  P4T1 = 1000;
  delay(500);
  }
if (P3 == HIGH)
  {
  P1T1 = 1000;
  P2T1 = 1000;
  P3T1 = 1;
  P4T1 = 1000;
  delay(500);
  }
if (P4 == HIGH)
  {
  P1T1 = 1000;
  P2T1 = 1000;
  P3T1 = 1000;
  P4T1 = 1;
  delay(500);
  }



  ex:;
}

