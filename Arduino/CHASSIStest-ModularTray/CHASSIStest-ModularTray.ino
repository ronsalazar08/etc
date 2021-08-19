//tray 1 p2 tray 1 p4 unfinished
#include "FastLED.h"

#define NUM_LEDS 1750            //heto ang bilang ng LED
#define DATA_PIN 12             // data pin for digital LED strip
#define BUTTON_PINP1 2          //P1 319
#define BUTTON_PINP2 3          //P2 320
#define BUTTON_PINP3 4          //P3 321
#define BUTTON_PINP4 5          //P4 322
#define BUTTON_PIN1 6           //next button tray 1
#define BUTTON_PIN2 7           //next button tray 2
#define BUTTON_PIN3 8           //next button tray 3
#define BUTTON_PIN4 9           //next button tray 4
#define BRIGHTNESS 100           //Heto yung adjustment ng brightness

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
      /*
             int j=0;  
       while (j<1750) {j++; leds[j] = CRGB::Blue;
       FastLED.show();
       FastLED.clear();}          
*/
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
      Serial.println( "---------------------------------tray 1 P4" );
      
      
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
      Serial.println( "---------------------------------tray 2 P4" );
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
      Serial.println( "---------------------------------tray 3 P4" );
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
      Serial.println( "---------------------------------tray 4 P4" );
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

if (P1T1 == 1000){                                   // to clear P1 in tray 1
            for (int i = 1281; i < 1478;i++)
            {
               leds[i] = CRGB::Black;  
           }  FastLED.show();  
            
 P1T1++;
}
//===================================================     P1 in Layer1
if (P1T1 == 1){//1 LED
             leds[1281] = CRGB::Blue;
             leds[1282] = CRGB::Blue;
             leds[1381] = CRGB::Black;
             leds[1382] = CRGB::Black;
             FastLED.show();  
 P1T1++;
}
if (P1T1 == 3){//2
             leds[1281] = CRGB::Black;
             leds[1282] = CRGB::Black;
             leds[1285] = CRGB::Blue;
             leds[1286] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
if (P1T1 == 5){//3
             leds[1285] = CRGB::Black;
             leds[1286] = CRGB::Black;
             leds[1289] = CRGB::Blue;
             leds[1290] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
if (P1T1 == 7){//4
             leds[1289] = CRGB::Black;
             leds[1290] = CRGB::Black;
             leds[1293] = CRGB::Blue;
             leds[1294] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
if (P1T1 == 9){//5
             leds[1293] = CRGB::Black;
             leds[1294] = CRGB::Black;
             leds[1297] = CRGB::Blue;
             leds[1298] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==11){//6
             leds[1297] = CRGB::Black;
             leds[1298] = CRGB::Black;
             leds[1301] = CRGB::Blue;
             leds[1302] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==13){//7
             leds[1301] = CRGB::Black;
             leds[1302] = CRGB::Black;
             leds[1305] = CRGB::Blue;
             leds[1306] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==15){//8
             leds[1305] = CRGB::Black;
             leds[1306] = CRGB::Black;
             leds[1309] = CRGB::Blue;
             leds[1310] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==17){//9
             leds[1309] = CRGB::Black;
             leds[1310] = CRGB::Black;
             leds[1313] = CRGB::Blue;
             leds[1314] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==19){//10
             leds[1313] = CRGB::Black;
             leds[1314] = CRGB::Black;
             leds[1317] = CRGB::Blue;
             leds[1318] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==21){//11
             leds[1317] = CRGB::Black;
             leds[1318] = CRGB::Black;
             leds[1321] = CRGB::Blue;
             leds[1322] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==23){//12
             leds[1321] = CRGB::Black;
             leds[1322] = CRGB::Black;
             leds[1325] = CRGB::Blue;
             leds[1326] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==25){//13
             leds[1325] = CRGB::Black;
             leds[1326] = CRGB::Black;
             leds[1329] = CRGB::Blue;
             leds[1330] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==27){//14
             leds[1329] = CRGB::Black;
             leds[1330] = CRGB::Black;
             leds[1333] = CRGB::Blue;
             leds[1334] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==29){//15
             leds[1333] = CRGB::Black;
             leds[1334] = CRGB::Black;
             leds[1337] = CRGB::Blue;
             leds[1338] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==31){//16
             leds[1337] = CRGB::Black;
             leds[1338] = CRGB::Black;
             leds[1341] = CRGB::Blue;
             leds[1342] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==33){//17
             leds[1341] = CRGB::Black;
             leds[1342] = CRGB::Black;
             leds[1345] = CRGB::Blue;
             leds[1346] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==35){//18
             leds[1345] = CRGB::Black;
             leds[1346] = CRGB::Black;
             leds[1349] = CRGB::Blue;
             leds[1350] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==37){//19
             leds[1349] = CRGB::Black;
             leds[1350] = CRGB::Black;
             leds[1353] = CRGB::Blue;
             leds[1354] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==39){//20
             leds[1353] = CRGB::Black;
             leds[1354] = CRGB::Black;
             leds[1357] = CRGB::Blue;
             leds[1358] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==41){//21
             leds[1357] = CRGB::Black;
             leds[1358] = CRGB::Black;
             leds[1361] = CRGB::Blue;
             leds[1362] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==43){//22
             leds[1361] = CRGB::Black;
             leds[1362] = CRGB::Black;
             leds[1365] = CRGB::Blue;
             leds[1366] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==45){//23
             leds[1365] = CRGB::Black;
             leds[1366] = CRGB::Black;
             leds[1369] = CRGB::Blue;
             leds[1370] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==47){//24
             leds[1369] = CRGB::Black;
             leds[1370] = CRGB::Black;
             leds[1373] = CRGB::Blue;
             leds[1374] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==49){//25
             leds[1373] = CRGB::Black;
             leds[1374] = CRGB::Black;
             leds[1377] = CRGB::Blue;
             leds[1378] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
//===================================================     P1 in Layer2

if (P1T1 ==51){//26   
             leds[1377] = CRGB::Black;
             leds[1378] = CRGB::Black;
             leds[1477] = CRGB::Blue;
             leds[1478] = CRGB::Blue;
             FastLED.show();  
 P1T1++;
}
if (P1T1 ==53){//27
             leds[1477] = CRGB::Black;
             leds[1478] = CRGB::Black;
             leds[1473] = CRGB::Blue;
             leds[1474] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
if (P1T1 ==55){//28
             leds[1473] = CRGB::Black;
             leds[1474] = CRGB::Black;
             leds[1469] = CRGB::Blue;
             leds[1470] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
if (P1T1 ==57){//29
             leds[1469] = CRGB::Black;
             leds[1470] = CRGB::Black;
             leds[1465] = CRGB::Blue;
             leds[1466] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
if (P1T1 ==59){//30
             leds[1465] = CRGB::Black;
             leds[1466] = CRGB::Black;
             leds[1461] = CRGB::Blue;
             leds[1462] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==61){//31
             leds[1461] = CRGB::Black;
             leds[1462] = CRGB::Black;
             leds[1457] = CRGB::Blue;
             leds[1458] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==63){//32
             leds[1457] = CRGB::Black;
             leds[1458] = CRGB::Black;
             leds[1453] = CRGB::Blue;
             leds[1454] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==65){//33
             leds[1453] = CRGB::Black;
             leds[1454] = CRGB::Black;
             leds[1449] = CRGB::Blue;
             leds[1450] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==67){//34
             leds[1449] = CRGB::Black;
             leds[1450] = CRGB::Black;
             leds[1445] = CRGB::Blue;
             leds[1446] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==69){//35
             leds[1445] = CRGB::Black;
             leds[1446] = CRGB::Black;
             leds[1441] = CRGB::Blue;
             leds[1442] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==71){//36
             leds[1441] = CRGB::Black;
             leds[1442] = CRGB::Black;
             leds[1437] = CRGB::Blue;
             leds[1438] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==73){//37
             leds[1437] = CRGB::Black;
             leds[1438] = CRGB::Black;
             leds[1433] = CRGB::Blue;
             leds[1434] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==75){//38
             leds[1433] = CRGB::Black;
             leds[1434] = CRGB::Black;
             leds[1429] = CRGB::Blue;
             leds[1430] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==77){//39
             leds[1429] = CRGB::Black;
             leds[1430] = CRGB::Black;
             leds[1425] = CRGB::Blue;
             leds[1426] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==79){//40
             leds[1425] = CRGB::Black;
             leds[1426] = CRGB::Black;
             leds[1421] = CRGB::Blue;
             leds[1422] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==81){//41
             leds[1421] = CRGB::Black;
             leds[1422] = CRGB::Black;
             leds[1417] = CRGB::Blue;
             leds[1418] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==83){//42
             leds[1417] = CRGB::Black;
             leds[1418] = CRGB::Black;
             leds[1413] = CRGB::Blue;
             leds[1414] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==85){//43
             leds[1413] = CRGB::Black;
             leds[1414] = CRGB::Black;
             leds[1409] = CRGB::Blue;
             leds[1410] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==87){//44
             leds[1409] = CRGB::Black;
             leds[1410] = CRGB::Black;
             leds[1405] = CRGB::Blue;
             leds[1406] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==89){//45
             leds[1405] = CRGB::Black;
             leds[1406] = CRGB::Black;
             leds[1401] = CRGB::Blue;
             leds[1402] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==91){//46
             leds[1401] = CRGB::Black;
             leds[1402] = CRGB::Black;
             leds[1397] = CRGB::Blue;
             leds[1398] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==93){//47
             leds[1397] = CRGB::Black;
             leds[1398] = CRGB::Black;
             leds[1393] = CRGB::Blue;
             leds[1394] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==95){//48
             leds[1393] = CRGB::Black;
             leds[1394] = CRGB::Black;
             leds[1389] = CRGB::Blue;
             leds[1390] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==97){//49
             leds[1389] = CRGB::Black;
             leds[1390] = CRGB::Black;
             leds[1385] = CRGB::Blue;
             leds[1386] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
if (P1T1 ==99){//50
             leds[1385] = CRGB::Black;
             leds[1386] = CRGB::Black;
             leds[1381] = CRGB::Blue;
             leds[1382] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}

if (P1T1 ==101){//back to 1 of P1 tray 1
if ((P1T2 > 999) && (P2T2 > 999) && (P3T2 > 999) && (P4T2 > 999))// IF TRAY 2 HAS NO VALUE FROM ANY PRODUCT
{
  P1T2 = 1; //TURN ON P1 ON TRAY 2
  P1T1 = 1; //P1 BACK TO 1 IN TRAY 1
}
if((P1T2 < 999) || (P2T2 < 999) || (P3T2 < 999) || (P3T2 < 999))//IF TRAY 2 HAS A VALUE FROM ANY PRODUCT
{
  P1T1 = 1; //P1 BACK TO 1 IN TRAY 1
}
}


//==========================================================================================================     start of tray 2 P1

//===================================================     P1 in Layer1
if (P1T2 == 1000){
             for (int x = 881; x < 1079;x++)
            {
               leds[x] = CRGB::Black;  
            } FastLED.show();  
            
 P1T2++;
}
if (P1T2 == 1){//1 LED
             leds[881] = CRGB::Blue;
             leds[882] = CRGB::Blue;
             leds[981] = CRGB::Black;
             leds[982] = CRGB::Black;
             FastLED.show();  
 P1T2++;
}
if (P1T2 == 3){//2
             leds[881] = CRGB::Black;
             leds[882] = CRGB::Black;
             leds[885] = CRGB::Blue;
             leds[886] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
if (P1T2 == 5){//3
             leds[885] = CRGB::Black;
             leds[886] = CRGB::Black;
             leds[889] = CRGB::Blue;
             leds[890] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
if (P1T2 == 7){//4
             leds[889] = CRGB::Black;
             leds[890] = CRGB::Black;
             leds[893] = CRGB::Blue;
             leds[894] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
if (P1T2 == 9){//5
             leds[893] = CRGB::Black;
             leds[894] = CRGB::Black;
             leds[897] = CRGB::Blue;
             leds[898] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==11){//6
             leds[897] = CRGB::Black;
             leds[898] = CRGB::Black;
             leds[901] = CRGB::Blue;
             leds[902] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==13){//7
             leds[901] = CRGB::Black;
             leds[902] = CRGB::Black;
             leds[905] = CRGB::Blue;
             leds[906] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==15){//8
             leds[905] = CRGB::Black;
             leds[906] = CRGB::Black;
             leds[909] = CRGB::Blue;
             leds[910] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==17){//9
             leds[909] = CRGB::Black;
             leds[910] = CRGB::Black;
             leds[913] = CRGB::Blue;
             leds[914] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==19){//10
             leds[913] = CRGB::Black;
             leds[914] = CRGB::Black;
             leds[917] = CRGB::Blue;
             leds[918] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 == 21){//11
             leds[917] = CRGB::Black;
             leds[918] = CRGB::Black;
             leds[921] = CRGB::Blue;
             leds[922] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==23){//12
             leds[921] = CRGB::Black;
             leds[922] = CRGB::Black;
             leds[925] = CRGB::Blue;
             leds[926] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==25){//13
             leds[925] = CRGB::Black;
             leds[926] = CRGB::Black;
             leds[929] = CRGB::Blue;
             leds[930] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==27){//14
             leds[929] = CRGB::Black;
             leds[930] = CRGB::Black;
             leds[933] = CRGB::Blue;
             leds[934] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==29){//15
             leds[933] = CRGB::Black;
             leds[934] = CRGB::Black;
             leds[937] = CRGB::Blue;
             leds[938] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==31){//16
             leds[937] = CRGB::Black;
             leds[938] = CRGB::Black;
             leds[941] = CRGB::Blue;
             leds[942] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==33){//17
             leds[941] = CRGB::Black;
             leds[942] = CRGB::Black;
             leds[945] = CRGB::Blue;
             leds[946] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==35){//18
             leds[945] = CRGB::Black;
             leds[946] = CRGB::Black;
             leds[949] = CRGB::Blue;
             leds[950] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==37){//19
             leds[949] = CRGB::Black;
             leds[950] = CRGB::Black;
             leds[953] = CRGB::Blue;
             leds[954] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==39){//20
             leds[953] = CRGB::Black;
             leds[954] = CRGB::Black;
             leds[957] = CRGB::Blue;
             leds[958] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==41){//21
             leds[957] = CRGB::Black;
             leds[958] = CRGB::Black;
             leds[961] = CRGB::Blue;
             leds[962] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==43){//22
             leds[961] = CRGB::Black;
             leds[962] = CRGB::Black;
             leds[965] = CRGB::Blue;
             leds[966] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==45){//23
             leds[965] = CRGB::Black;
             leds[966] = CRGB::Black;
             leds[969] = CRGB::Blue;
             leds[970] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==47){//24
             leds[969] = CRGB::Black;
             leds[970] = CRGB::Black;
             leds[973] = CRGB::Blue;
             leds[974] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==49){//25
             leds[973] = CRGB::Black;
             leds[974] = CRGB::Black;
             leds[977] = CRGB::Blue;
             leds[978] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}

//===================================================     P1 in Layer2

if (P1T2 ==51){//26LED
             leds[1077] = CRGB::Blue;
             leds[1078] = CRGB::Blue;
             leds[977] = CRGB::Black;
             leds[978] = CRGB::Black;
             FastLED.show();  
 P1T2++;
}
if (P1T2 ==53){//27
             leds[1077] = CRGB::Black;
             leds[1078] = CRGB::Black;
             leds[1073] = CRGB::Blue;
             leds[1074] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
if (P1T2 ==55){//28
             leds[1073] = CRGB::Black;
             leds[1074] = CRGB::Black;
             leds[1070] = CRGB::Blue;
             leds[1069] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
if (P1T2 ==57){//29
             leds[1069] = CRGB::Black;
             leds[1070] = CRGB::Black;
             leds[1065] = CRGB::Blue;
             leds[1066] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
if (P1T2 ==59){//30
             leds[1065] = CRGB::Black;
             leds[1066] = CRGB::Black;
             leds[1061] = CRGB::Blue;
             leds[1062] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==61){//31
             leds[1061] = CRGB::Black;
             leds[1062] = CRGB::Black;
             leds[1057] = CRGB::Blue;
             leds[1058] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==63){//32
             leds[1057] = CRGB::Black;
             leds[1058] = CRGB::Black;
             leds[1053] = CRGB::Blue;
             leds[1054] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==65){//33
             leds[1053] = CRGB::Black;
             leds[1054] = CRGB::Black;
             leds[1049] = CRGB::Blue;
             leds[1050] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==67){//34
             leds[1049] = CRGB::Black;
             leds[1050] = CRGB::Black;
             leds[1045] = CRGB::Blue;
             leds[1046] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==69){//35
             leds[1045] = CRGB::Black;
             leds[1046] = CRGB::Black;
             leds[1041] = CRGB::Blue;
             leds[1042] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 == 71){//36
             leds[1041] = CRGB::Black;
             leds[1042] = CRGB::Black;
             leds[1037] = CRGB::Blue;
             leds[1038] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==73){//37
             leds[1037] = CRGB::Black;
             leds[1038] = CRGB::Black;
             leds[1033] = CRGB::Blue;
             leds[1034] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==75){//38
             leds[1033] = CRGB::Black;
             leds[1034] = CRGB::Black;
             leds[1029] = CRGB::Blue;
             leds[1030] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==77){//39
             leds[1029] = CRGB::Black;
             leds[1030] = CRGB::Black;
             leds[1025] = CRGB::Blue;
             leds[1026] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==79){//40
             leds[1025] = CRGB::Black;
             leds[1026] = CRGB::Black;
             leds[1021] = CRGB::Blue;
             leds[1022] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==81){//41
             leds[1021] = CRGB::Black;
             leds[1022] = CRGB::Black;
             leds[1017] = CRGB::Blue;
             leds[1018] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==83){//42
             leds[1017] = CRGB::Black;
             leds[1018] = CRGB::Black;
             leds[1013] = CRGB::Blue;
             leds[1014] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==85){//43
             leds[1013] = CRGB::Black;
             leds[1014] = CRGB::Black;
             leds[1009] = CRGB::Blue;
             leds[1010] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==87){//44
             leds[1010] = CRGB::Black;
             leds[1009] = CRGB::Black;
             leds[1005] = CRGB::Blue;
             leds[1006] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==89){//45
             leds[1005] = CRGB::Black;
             leds[1006] = CRGB::Black;
             leds[1001] = CRGB::Blue;
             leds[1002] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==91){//46
             leds[1001] = CRGB::Black;
             leds[1002] = CRGB::Black;
             leds[997] = CRGB::Blue;
             leds[998] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==93){//47
             leds[997] = CRGB::Black;
             leds[998] = CRGB::Black;
             leds[993] = CRGB::Blue;
             leds[994] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==95){//48
             leds[993] = CRGB::Black;
             leds[994] = CRGB::Black;
             leds[989] = CRGB::Blue;
             leds[990] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==97){//49
             leds[989] = CRGB::Black;
             leds[990] = CRGB::Black;
             leds[985] = CRGB::Blue;
             leds[986] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
if (P1T2 ==99){//50
             leds[985] = CRGB::Black;
             leds[986] = CRGB::Black;
             leds[981] = CRGB::Blue;
             leds[982] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}

if (P1T2 ==101){//back to 1
if ((P1T3 > 999)&&(P2T3 > 999)&&(P3T3 > 999)&&(P3T3 > 999))//IF TRAY 3 HAS NO VALUE FROM ANY PRODUCT
{
P1T3 = 1;//TURN ON P1 ON TRAY 3
P1T2 = 1;//P1 ON TRAY 2 BACK TO 1
}

if ((P1T3 < 999)||(P2T3 < 999)||(P3T3 < 999)||(P3T3 < 999))//IF TRAY 3 HAS ANY VALUE FROM ANY PRODUCT
{ 
P1T2 = 1; //P1 ON TRAY 2 BACK TO 1
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

//===================================================     P1 in Layer1
if (P1T3 == 1000){
            for (int i = 481; i < 679;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P1T3++;
}

if (P1T3 == 1){//1 LED
             leds[482] = CRGB::Blue;
             leds[481] = CRGB::Blue;
             leds[581] = CRGB::Black;
             leds[582] = CRGB::Black;
             FastLED.show();  
 P1T3++;
}
if (P1T3 == 3){//2
             leds[482] = CRGB::Black;
             leds[481] = CRGB::Black;
             leds[486] = CRGB::Blue;
             leds[485] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
if (P1T3 == 5){//3
             leds[486] = CRGB::Black;
             leds[485] = CRGB::Black;
             leds[490] = CRGB::Blue;
             leds[489] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
if (P1T3 == 7){//4
             leds[490] = CRGB::Black;
             leds[489] = CRGB::Black;
             leds[494] = CRGB::Blue;
             leds[493] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
if (P1T3 == 9){//5
             leds[494] = CRGB::Black;
             leds[493] = CRGB::Black;
             leds[498] = CRGB::Blue;
             leds[497] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==11){//6
             leds[498] = CRGB::Black;
             leds[497] = CRGB::Black;
             leds[501] = CRGB::Blue;
             leds[502] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==13){//7
             leds[501] = CRGB::Black;
             leds[502] = CRGB::Black;
             leds[505] = CRGB::Blue;
             leds[506] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==15){//8
             leds[505] = CRGB::Black;
             leds[506] = CRGB::Black;
             leds[509] = CRGB::Blue;
             leds[510] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==17){//9
             leds[509] = CRGB::Black;
             leds[510] = CRGB::Black;
             leds[513] = CRGB::Blue;
             leds[514] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==19){//10
             leds[513] = CRGB::Black;
             leds[514] = CRGB::Black;
             leds[517] = CRGB::Blue;
             leds[518] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 == 21){//11
             leds[517] = CRGB::Black;
             leds[518] = CRGB::Black;
             leds[521] = CRGB::Blue;
             leds[522] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==23){//12
             leds[521] = CRGB::Black;
             leds[522] = CRGB::Black;
             leds[525] = CRGB::Blue;
             leds[526] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==25){//13
             leds[525] = CRGB::Black;
             leds[526] = CRGB::Black;
             leds[529] = CRGB::Blue;
             leds[530] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==27){//14
             leds[529] = CRGB::Black;
             leds[530] = CRGB::Black;
             leds[533] = CRGB::Blue;
             leds[534] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==29){//15
             leds[533] = CRGB::Black;
             leds[534] = CRGB::Black;
             leds[537] = CRGB::Blue;
             leds[538] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==31){//16
             leds[537] = CRGB::Black;
             leds[538] = CRGB::Black;
             leds[541] = CRGB::Blue;
             leds[542] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==33){//17
             leds[541] = CRGB::Black;
             leds[542] = CRGB::Black;
             leds[545] = CRGB::Blue;
             leds[546] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==35){//18
             leds[545] = CRGB::Black;
             leds[546] = CRGB::Black;
             leds[549] = CRGB::Blue;
             leds[550] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==37){//19
             leds[549] = CRGB::Black;
             leds[550] = CRGB::Black;
             leds[553] = CRGB::Blue;
             leds[554] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==39){//20
             leds[553] = CRGB::Black;
             leds[554] = CRGB::Black;
             leds[557] = CRGB::Blue;
             leds[558] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==41){//21
             leds[557] = CRGB::Black;
             leds[558] = CRGB::Black;
             leds[561] = CRGB::Blue;
             leds[562] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==43){//22
             leds[561] = CRGB::Black;
             leds[562] = CRGB::Black;
             leds[565] = CRGB::Blue;
             leds[566] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==45){//23
             leds[565] = CRGB::Black;
             leds[566] = CRGB::Black;
             leds[569] = CRGB::Blue;
             leds[570] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==47){//24
             leds[569] = CRGB::Black;
             leds[570] = CRGB::Black;
             leds[573] = CRGB::Blue;
             leds[574] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==49){//25
             leds[573] = CRGB::Black;
             leds[574] = CRGB::Black;
             leds[577] = CRGB::Blue;
             leds[578] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}

//===================================================     P1 in Layer2

if (P1T3 ==51){//26LED
             leds[678] = CRGB::Blue;
             leds[677] = CRGB::Blue;
             leds[577] = CRGB::Black;
             leds[578] = CRGB::Black;
             FastLED.show();  
 P1T3++;
}
if (P1T3 ==53){//27
             leds[678] = CRGB::Black;
             leds[677] = CRGB::Black;
             leds[674] = CRGB::Blue;
             leds[673] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
if (P1T3 ==55){//28
             leds[674] = CRGB::Black;
             leds[673] = CRGB::Black;
             leds[670] = CRGB::Blue;
             leds[669] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
if (P1T3 ==57){//29
             leds[670] = CRGB::Black;
             leds[669] = CRGB::Black;
             leds[666] = CRGB::Blue;
             leds[665] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
if (P1T3 ==59){//30
             leds[666] = CRGB::Black;
             leds[665] = CRGB::Black;
             leds[662] = CRGB::Blue;
             leds[661] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==61){//31
             leds[662] = CRGB::Black;
             leds[661] = CRGB::Black;
             leds[658] = CRGB::Blue;
             leds[657] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==63){//32
             leds[658] = CRGB::Black;
             leds[657] = CRGB::Black;
             leds[654] = CRGB::Blue;
             leds[653] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==65){//33
             leds[654] = CRGB::Black;
             leds[653] = CRGB::Black;
             leds[650] = CRGB::Blue;
             leds[649] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==67){//34
             leds[650] = CRGB::Black;
             leds[649] = CRGB::Black;
             leds[646] = CRGB::Blue;
             leds[645] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==69){//35
             leds[646] = CRGB::Black;
             leds[645] = CRGB::Black;
             leds[642] = CRGB::Blue;
             leds[641] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 == 71){//36
             leds[642] = CRGB::Black;
             leds[641] = CRGB::Black;
             leds[638] = CRGB::Blue;
             leds[637] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==73){//37
             leds[638] = CRGB::Black;
             leds[637] = CRGB::Black;
             leds[634] = CRGB::Blue;
             leds[633] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==75){//38
             leds[634] = CRGB::Black;
             leds[633] = CRGB::Black;
             leds[630] = CRGB::Blue;
             leds[629] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==77){//39
             leds[630] = CRGB::Black;
             leds[629] = CRGB::Black;
             leds[626] = CRGB::Blue;
             leds[625] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==79){//40
             leds[626] = CRGB::Black;
             leds[625] = CRGB::Black;
             leds[622] = CRGB::Blue;
             leds[621] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==81){//41
             leds[622] = CRGB::Black;
             leds[621] = CRGB::Black;
             leds[618] = CRGB::Blue;
             leds[617] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==83){//42
             leds[618] = CRGB::Black;
             leds[617] = CRGB::Black;
             leds[614] = CRGB::Blue;
             leds[613] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==85){//43
             leds[614] = CRGB::Black;
             leds[613] = CRGB::Black;
             leds[610] = CRGB::Blue;
             leds[609] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==87){//44
             leds[610] = CRGB::Black;
             leds[609] = CRGB::Black;
             leds[606] = CRGB::Blue;
             leds[605] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==89){//45
             leds[606] = CRGB::Black;
             leds[605] = CRGB::Black;
             leds[602] = CRGB::Blue;
             leds[601] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==91){//46
             leds[602] = CRGB::Black;
             leds[601] = CRGB::Black;
             leds[598] = CRGB::Blue;
             leds[597] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==93){//47
             leds[598] = CRGB::Black;
             leds[597] = CRGB::Black;
             leds[594] = CRGB::Blue;
             leds[593] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==95){//48
             leds[594] = CRGB::Black;
             leds[593] = CRGB::Black;
             leds[590] = CRGB::Blue;
             leds[589] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==97){//49
             leds[590] = CRGB::Black;
             leds[589] = CRGB::Black;
             leds[586] = CRGB::Blue;
             leds[585] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
if (P1T3 ==99){//50
             leds[586] = CRGB::Black;
             leds[585] = CRGB::Black;
             leds[582] = CRGB::Blue;
             leds[581] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}

if (P1T3 == 101){//back to 1
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
if (P1T4 == 1000){
for (int i = 1; i < 118;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P1T4++;
}


//===================================================     P1 in Layer1
if (P1T4 == 1){//1 LED
             leds[1] = CRGB::Blue;
             leds[2] = CRGB::Blue;
             leds[116] = CRGB::Black;
             leds[117] = CRGB::Black;
             FastLED.show();  
 P1T4++;
}
if (P1T4 == 3){//2
             leds[1] = CRGB::Black;
             leds[2] = CRGB::Black;
             leds[5] = CRGB::Blue;
             leds[6] = CRGB::Blue;
             FastLED.show();
 P1T4++;
}
if (P1T4 == 5){//3
             leds[5] = CRGB::Black;
             leds[6] = CRGB::Black;
             leds[9] = CRGB::Blue;
             leds[10] = CRGB::Blue;
             FastLED.show();
 P1T4++;
}
if (P1T4 == 7){//4
             leds[9] = CRGB::Black;
             leds[10] = CRGB::Black;
             leds[13] = CRGB::Blue;
             leds[14] = CRGB::Blue;
             FastLED.show();
 P1T4++;
}
if (P1T4 == 9){//5
             leds[13] = CRGB::Black;
             leds[14] = CRGB::Black;
             leds[17] = CRGB::Blue;
             leds[18] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==11){//6
             leds[17] = CRGB::Black;
             leds[18] = CRGB::Black;
             leds[21] = CRGB::Blue;
             leds[22] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==13){//7
             leds[21] = CRGB::Black;
             leds[22] = CRGB::Black;
             leds[25] = CRGB::Blue;
             leds[26] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==15){//8
             leds[25] = CRGB::Black;
             leds[26] = CRGB::Black;
             leds[29] = CRGB::Blue;
             leds[30] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==17){//9
             leds[29] = CRGB::Black;
             leds[30] = CRGB::Black;
             leds[33] = CRGB::Blue;
             leds[34] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==19){//10
             leds[33] = CRGB::Black;
             leds[34] = CRGB::Black;
             leds[37] = CRGB::Blue;
             leds[38] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 == 21){//11
             leds[37] = CRGB::Black;
             leds[38] = CRGB::Black;
             leds[41] = CRGB::Blue;
             leds[42] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==23){//12
             leds[41] = CRGB::Black;
             leds[42] = CRGB::Black;
             leds[45] = CRGB::Blue;
             leds[46] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==25){//13
             leds[45] = CRGB::Black;
             leds[46] = CRGB::Black;
             leds[49] = CRGB::Blue;
             leds[50] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==27){//14
             leds[49] = CRGB::Black;
             leds[50] = CRGB::Black;
             leds[53] = CRGB::Blue;
             leds[54] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==29){//15
             leds[53] = CRGB::Black;
             leds[54] = CRGB::Black;
             leds[57] = CRGB::Blue;
             leds[58] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==31){//16
             leds[57] = CRGB::Black;
             leds[58] = CRGB::Black;
             leds[61] = CRGB::Blue;
             leds[62] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==33){//17
             leds[61] = CRGB::Black;
             leds[62] = CRGB::Black;
             leds[65] = CRGB::Blue;
             leds[66] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==35){//18
             leds[65] = CRGB::Black;
             leds[66] = CRGB::Black;
             leds[69] = CRGB::Blue;
             leds[70] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==37){//19
             leds[69] = CRGB::Black;
             leds[70] = CRGB::Black;
             leds[73] = CRGB::Blue;
             leds[74] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==39){//20
             leds[73] = CRGB::Black;
             leds[74] = CRGB::Black;
             leds[77] = CRGB::Blue;
             leds[78] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==41){//21
             leds[77] = CRGB::Black;
             leds[78] = CRGB::Black;
             leds[81] = CRGB::Blue;
             leds[82] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==43){//22
             leds[81] = CRGB::Black;
             leds[82] = CRGB::Black;
             leds[85] = CRGB::Blue;
             leds[86] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==45){//23
             leds[85] = CRGB::Black;
             leds[86] = CRGB::Black;
             leds[89] = CRGB::Blue;
             leds[90] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==47){//24
             leds[89] = CRGB::Black;
             leds[90] = CRGB::Black;
             leds[93] = CRGB::Blue;
             leds[94] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==49){//25
             leds[93] = CRGB::Black;
             leds[94] = CRGB::Black;
             leds[97] = CRGB::Blue;
             leds[98] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==51){//26
             leds[97] = CRGB::Black;
             leds[98] = CRGB::Black;
             leds[100] = CRGB::Blue;
             leds[101] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==53){//27
             leds[100] = CRGB::Black;
             leds[101] = CRGB::Black;
             leds[104] = CRGB::Blue;
             leds[105] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==55){//28
             leds[104] = CRGB::Black;
             leds[105] = CRGB::Black;
             leds[108] = CRGB::Blue;
             leds[109] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==57){//29
             leds[108] = CRGB::Black;
             leds[109] = CRGB::Black;
             leds[112] = CRGB::Blue;
             leds[113] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
if (P1T4 ==59){//30
             leds[112] = CRGB::Black;
             leds[113] = CRGB::Black;
             leds[116] = CRGB::Blue;
             leds[117] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}


if (P1T4 == 61){//back to 1

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
 if (P2T1 == 1000){
        for (int i = 1469; i < 1667;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P2T1++;
}

//===================================================     P2 in Layer1
if (P2T1 == 1){//1 LED
             leds[1469] = CRGB::Red;
             leds[1470] = CRGB::Red;
             leds[1569] = CRGB::Black;
             leds[1570] = CRGB::Black;
             FastLED.show();  
 P2T1++;
}
if (P2T1 == 3){//2
             leds[1469] = CRGB::Black;
             leds[1470] = CRGB::Black;
             leds[1473] = CRGB::Red;
             leds[1474] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
if (P2T1 == 5){//3
             leds[1473] = CRGB::Black;
             leds[1474] = CRGB::Black;
             leds[1477] = CRGB::Red;
             leds[1478] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
if (P2T1 == 7){//4
             leds[1477] = CRGB::Black;
             leds[1478] = CRGB::Black;
             leds[1481] = CRGB::Red;
             leds[1482] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
if (P2T1 == 9){//5
             leds[1481] = CRGB::Black;
             leds[1482] = CRGB::Black;
             leds[1485] = CRGB::Red;
             leds[1486] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==11){//6
             leds[1485] = CRGB::Black;
             leds[1486] = CRGB::Black;
             leds[1489] = CRGB::Red;
             leds[1490] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==13){//7
             leds[1489] = CRGB::Black;
             leds[1490] = CRGB::Black;
             leds[1493] = CRGB::Red;
             leds[1494] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==15){//8
             leds[1493] = CRGB::Black;
             leds[1494] = CRGB::Black;
             leds[1497] = CRGB::Red;
             leds[1498] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==17){//9
             leds[1497] = CRGB::Black;
             leds[1498] = CRGB::Black;
             leds[1501] = CRGB::Red;
             leds[1502] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==19){//10
             leds[1501] = CRGB::Black;
             leds[1502] = CRGB::Black;
             leds[1505] = CRGB::Red;
             leds[1506] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==21){//11
             leds[1505] = CRGB::Black;
             leds[1506] = CRGB::Black;
             leds[1509] = CRGB::Red;
             leds[1510] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==23){//12
             leds[1509] = CRGB::Black;
             leds[1510] = CRGB::Black;
             leds[1513] = CRGB::Red;
             leds[1514] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==25){//13
             leds[1513] = CRGB::Black;
             leds[1514] = CRGB::Black;
             leds[1517] = CRGB::Red;
             leds[1518] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==27){//14
             leds[1517] = CRGB::Black;
             leds[1518] = CRGB::Black;
             leds[1521] = CRGB::Red;
             leds[1522] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==29){//15
             leds[1521] = CRGB::Black;
             leds[1522] = CRGB::Black;
             leds[1525] = CRGB::Red;
             leds[1526] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==31){//16
             leds[1525] = CRGB::Black;
             leds[1526] = CRGB::Black;
             leds[1529] = CRGB::Red;
             leds[1530] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==33){//17
             leds[1529] = CRGB::Black;
             leds[1530] = CRGB::Black;
             leds[1533] = CRGB::Red;
             leds[1534] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==35){//18
             leds[1533] = CRGB::Black;
             leds[1534] = CRGB::Black;
             leds[1537] = CRGB::Red;
             leds[1538] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==37){//19
             leds[1537] = CRGB::Black;
             leds[1538] = CRGB::Black;
             leds[1541] = CRGB::Red;
             leds[1542] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==39){//20
             leds[1541] = CRGB::Black;
             leds[1542] = CRGB::Black;
             leds[1545] = CRGB::Red;
             leds[1546] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==41){//21
             leds[1545] = CRGB::Black;
             leds[1546] = CRGB::Black;
             leds[1549] = CRGB::Red;
             leds[1550] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==43){//22
             leds[1549] = CRGB::Black;
             leds[1550] = CRGB::Black;
             leds[1553] = CRGB::Red;
             leds[1554] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==45){//23
             leds[1553] = CRGB::Black;
             leds[1554] = CRGB::Black;
             leds[1557] = CRGB::Red;
             leds[1558] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==47){//24
             leds[1557] = CRGB::Black;
             leds[1558] = CRGB::Black;
             leds[1561] = CRGB::Red;
             leds[1562] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==49){//25
             leds[1561] = CRGB::Black;
             leds[1562] = CRGB::Black;
             leds[1565] = CRGB::Red;
             leds[1566] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
//===================================================     P2 in Layer2

if (P2T1 ==51){//26   
             leds[1565] = CRGB::Black;
             leds[1566] = CRGB::Black;
             leds[1665] = CRGB::Red;
             leds[1666] = CRGB::Red;
             FastLED.show();  
 P2T1++;
}
if (P2T1 ==53){//27
             leds[1665] = CRGB::Black;
             leds[1666] = CRGB::Black;
             leds[1661] = CRGB::Red;
             leds[1662] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
if (P2T1 ==55){//28
             leds[1661] = CRGB::Black;
             leds[1662] = CRGB::Black;
             leds[1657] = CRGB::Red;
             leds[1658] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
if (P2T1 ==57){//29
             leds[1657] = CRGB::Black;
             leds[1658] = CRGB::Black;
             leds[1653] = CRGB::Red;
             leds[1654] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
if (P2T1 ==59){//30
             leds[1653] = CRGB::Black;
             leds[1654] = CRGB::Black;
             leds[1649] = CRGB::Red;
             leds[1650] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==61){//31
             leds[1649] = CRGB::Black;
             leds[1650] = CRGB::Black;
             leds[1645] = CRGB::Red;
             leds[1646] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==63){//32
             leds[1645] = CRGB::Black;
             leds[1646] = CRGB::Black;
             leds[1641] = CRGB::Red;
             leds[1642] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==65){//33
             leds[1641] = CRGB::Black;
             leds[1642] = CRGB::Black;
             leds[1637] = CRGB::Red;
             leds[1638] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==67){//34
             leds[1637] = CRGB::Black;
             leds[1638] = CRGB::Black;
             leds[1633] = CRGB::Red;
             leds[1634] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==69){//35
             leds[1633] = CRGB::Black;
             leds[1634] = CRGB::Black;
             leds[1630] = CRGB::Red;
             leds[1629] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==71){//36
             leds[1629] = CRGB::Black;
             leds[1630] = CRGB::Black;
             leds[1625] = CRGB::Red;
             leds[1626] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==73){//37
             leds[1625] = CRGB::Black;
             leds[1626] = CRGB::Black;
             leds[1621] = CRGB::Red;
             leds[1622] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==75){//38
             leds[1621] = CRGB::Black;
             leds[1622] = CRGB::Black;
             leds[1617] = CRGB::Red;
             leds[1618] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==77){//39
             leds[1617] = CRGB::Black;
             leds[1618] = CRGB::Black;
             leds[1613] = CRGB::Red;
             leds[1614] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==79){//40
             leds[1613] = CRGB::Black;
             leds[1614] = CRGB::Black;
             leds[1609] = CRGB::Red;
             leds[1610] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==81){//41
             leds[1609] = CRGB::Black;
             leds[1610] = CRGB::Black;
             leds[1605] = CRGB::Red;
             leds[1606] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==83){//42
             leds[1605] = CRGB::Black;
             leds[1606] = CRGB::Black;
             leds[1601] = CRGB::Red;
             leds[1602] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==85){//43
             leds[1601] = CRGB::Black;
             leds[1602] = CRGB::Black;
             leds[1597] = CRGB::Red;
             leds[1598] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==87){//44
             leds[1597] = CRGB::Black;
             leds[1598] = CRGB::Black;
             leds[1593] = CRGB::Red;
             leds[1594] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==89){//45
             leds[1593] = CRGB::Black;
             leds[1594] = CRGB::Black;
             leds[1589] = CRGB::Red;
             leds[1590] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==91){//46
             leds[1589] = CRGB::Black;
             leds[1590] = CRGB::Black;
             leds[1585] = CRGB::Red;
             leds[1586] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==93){//47
             leds[1585] = CRGB::Black;
             leds[1586] = CRGB::Black;
             leds[1581] = CRGB::Red;
             leds[1582] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==95){//48
             leds[1581] = CRGB::Black;
             leds[1582] = CRGB::Black;
             leds[1577] = CRGB::Red;
             leds[1578] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==97){//49
             leds[1577] = CRGB::Black;
             leds[1578] = CRGB::Black;
             leds[1573] = CRGB::Red;
             leds[1574] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
if (P2T1 ==99){//50
             leds[1573] = CRGB::Black;
             leds[1574] = CRGB::Black;
             leds[1569] = CRGB::Red;
             leds[1570] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}

if (P2T1 == 101){//back to 1
if ((P1T2 > 999) && (P2T2 > 999)&& (P3T2 > 999)&& (P4T2 > 999))
{
  P2T2 = 1;
  P2T1 = 1; 
}
if((P1T2 < 999) || (P2T2 < 999)|| (P3T2 < 999)|| (P3T2 < 999))
{
  P2T1 = 1; 
}   
}


//==========================================================================================================     start of tray 2 P2
if (P2T2 == 1000){
            for (int i = 1081; i < 1279;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P2T2++;
}

//===================================================     P2 in Layer3
if (P2T2 == 1){//1 LED
             leds[1081] = CRGB::Red;
             leds[1082] = CRGB::Red;
             leds[1181] = CRGB::Black;
             leds[1182] = CRGB::Black;
             FastLED.show();  
 P2T2++;
}
if (P2T2 == 3){//2
             leds[1081] = CRGB::Black;
             leds[1082] = CRGB::Black;
             leds[1085] = CRGB::Red;
             leds[1086] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
if (P2T2 == 5){//3
             leds[1085] = CRGB::Black;
             leds[1086] = CRGB::Black;
             leds[1089] = CRGB::Red;
             leds[1090] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
if (P2T2 == 7){//4
             leds[1089] = CRGB::Black;
             leds[1090] = CRGB::Black;
             leds[1093] = CRGB::Red;
             leds[1094] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
if (P2T2 == 9){//5
             leds[1093] = CRGB::Black;
             leds[1094] = CRGB::Black;
             leds[1097] = CRGB::Red;
             leds[1098] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==11){//6
             leds[1097] = CRGB::Black;
             leds[1098] = CRGB::Black;
             leds[1101] = CRGB::Red;
             leds[1102] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==13){//7
             leds[1101] = CRGB::Black;
             leds[1102] = CRGB::Black;
             leds[1105] = CRGB::Red;
             leds[1106] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==15){//8
             leds[1105] = CRGB::Black;
             leds[1106] = CRGB::Black;
             leds[1109] = CRGB::Red;
             leds[1110] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==17){//9
             leds[1109] = CRGB::Black;
             leds[1110] = CRGB::Black;
             leds[1113] = CRGB::Red;
             leds[1114] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==19){//10
             leds[1113] = CRGB::Black;
             leds[1114] = CRGB::Black;
             leds[1117] = CRGB::Red;
             leds[1118] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==21){//11
             leds[1117] = CRGB::Black;
             leds[1118] = CRGB::Black;
             leds[1121] = CRGB::Red;
             leds[1122] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==23){//12
             leds[1121] = CRGB::Black;
             leds[1122] = CRGB::Black;
             leds[1125] = CRGB::Red;
             leds[1126] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==25){//13
             leds[1125] = CRGB::Black;
             leds[1126] = CRGB::Black;
             leds[1129] = CRGB::Red;
             leds[1130] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==27){//14
             leds[1129] = CRGB::Black;
             leds[1130] = CRGB::Black;
             leds[1133] = CRGB::Red;
             leds[1134] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==29){//15
             leds[1133] = CRGB::Black;
             leds[1134] = CRGB::Black;
             leds[1137] = CRGB::Red;
             leds[1138] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==31){//16
             leds[1137] = CRGB::Black;
             leds[1138] = CRGB::Black;
             leds[1141] = CRGB::Red;
             leds[1142] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==33){//17
             leds[1141] = CRGB::Black;
             leds[1142] = CRGB::Black;
             leds[1145] = CRGB::Red;
             leds[1146] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==35){//18
             leds[1145] = CRGB::Black;
             leds[1146] = CRGB::Black;
             leds[1149] = CRGB::Red;
             leds[1150] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==37){//19
             leds[1149] = CRGB::Black;
             leds[1150] = CRGB::Black;
             leds[1153] = CRGB::Red;
             leds[1154] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==39){//20
             leds[1153] = CRGB::Black;
             leds[1154] = CRGB::Black;
             leds[1157] = CRGB::Red;
             leds[1158] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==41){//21
             leds[1157] = CRGB::Black;
             leds[1158] = CRGB::Black;
             leds[1161] = CRGB::Red;
             leds[1162] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==43){//22
             leds[1161] = CRGB::Black;
             leds[1162] = CRGB::Black;
             leds[1165] = CRGB::Red;
             leds[1166] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
//===================================================     P2 in Layer4

if (P2T2 ==45){//26   
             leds[1165] = CRGB::Black;
             leds[1166] = CRGB::Black;
             leds[1277] = CRGB::Red;
             leds[1278] = CRGB::Red;
             FastLED.show();  
 P2T2++;
}
if (P2T2 ==47){//27
             leds[1277] = CRGB::Black;
             leds[1278] = CRGB::Black;
             leds[1273] = CRGB::Red;
             leds[1274] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
if (P2T2 ==49){//28
             leds[1273] = CRGB::Black;
             leds[1274] = CRGB::Black;
             leds[1269] = CRGB::Red;
             leds[1270] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
if (P2T2 ==51){//29
             leds[1269] = CRGB::Black;
             leds[1270] = CRGB::Black;
             leds[1265] = CRGB::Red;
             leds[1266] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
if (P2T2 ==53){//30
             leds[1265] = CRGB::Black;
             leds[1266] = CRGB::Black;
             leds[1261] = CRGB::Red;
             leds[1262] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==55){//31
             leds[1261] = CRGB::Black;
             leds[1262] = CRGB::Black;
             leds[1257] = CRGB::Red;
             leds[1258] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==57){//32
             leds[1257] = CRGB::Black;
             leds[1258] = CRGB::Black;
             leds[1253] = CRGB::Red;
             leds[1254] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==59){//33
             leds[1253] = CRGB::Black;
             leds[1254] = CRGB::Black;
             leds[1249] = CRGB::Red;
             leds[1250] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==61){//34
             leds[1249] = CRGB::Black;
             leds[1250] = CRGB::Black;
             leds[1245] = CRGB::Red;
             leds[1246] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==63){//35
             leds[1245] = CRGB::Black;
             leds[1246] = CRGB::Black;
             leds[1241] = CRGB::Red;
             leds[1242] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==65){//36
             leds[1241] = CRGB::Black;
             leds[1242] = CRGB::Black;
             leds[1237] = CRGB::Red;
             leds[1238] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==67){//37
             leds[1237] = CRGB::Black;
             leds[1238] = CRGB::Black;
             leds[1233] = CRGB::Red;
             leds[1234] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==69){//38
             leds[1233] = CRGB::Black;
             leds[1234] = CRGB::Black;
             leds[1229] = CRGB::Red;
             leds[1230] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==71){//39
             leds[1229] = CRGB::Black;
             leds[1230] = CRGB::Black;
             leds[1225] = CRGB::Red;
             leds[1226] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==73){//40
             leds[1225] = CRGB::Black;
             leds[1226] = CRGB::Black;
             leds[1221] = CRGB::Red;
             leds[1222] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==75){//41
             leds[1221] = CRGB::Black;
             leds[1222] = CRGB::Black;
             leds[1217] = CRGB::Red;
             leds[1218] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==77){//42
             leds[1217] = CRGB::Black;
             leds[1218] = CRGB::Black;
             leds[1213] = CRGB::Red;
             leds[1214] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==79){//43
             leds[1213] = CRGB::Black;
             leds[1214] = CRGB::Black;
             leds[1209] = CRGB::Red;
             leds[1210] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==81){//44
             leds[1209] = CRGB::Black;
             leds[1210] = CRGB::Black;
             leds[1205] = CRGB::Red;
             leds[1206] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==83){//45
             leds[1205] = CRGB::Black;
             leds[1206] = CRGB::Black;
             leds[1201] = CRGB::Red;
             leds[1202] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==85){//46
             leds[1201] = CRGB::Black;
             leds[1202] = CRGB::Black;
             leds[1197] = CRGB::Red;
             leds[1198] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==87){//47
             leds[1197] = CRGB::Black;
             leds[1198] = CRGB::Black;
             leds[1193] = CRGB::Red;
             leds[1194] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==89){//48
             leds[1193] = CRGB::Black;
             leds[1194] = CRGB::Black;
             leds[1189] = CRGB::Red;
             leds[1190] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==91){//49
             leds[1189] = CRGB::Black;
             leds[1190] = CRGB::Black;
             leds[1185] = CRGB::Red;
             leds[1186] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
if (P2T2 ==93){//50
             leds[1185] = CRGB::Black;
             leds[1186] = CRGB::Black;
             leds[1181] = CRGB::Red;
             leds[1182] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}

if (P2T2 == 95){//back to 1
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

if (P2T3 == 1000){
          for (int i = 681; i < 879;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P2T3++;
}

//===================================================     P2 in Layer3

if (P2T3 == 1){//2
             leds[781] = CRGB::Black;
             leds[782] = CRGB::Black;
             leds[685] = CRGB::Red;
             leds[686] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
if (P2T3 == 3){//3
             leds[685] = CRGB::Black;
             leds[686] = CRGB::Black;
             leds[689] = CRGB::Red;
             leds[690] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
if (P2T3 == 5){//4
             leds[689] = CRGB::Black;
             leds[690] = CRGB::Black;
             leds[693] = CRGB::Red;
             leds[694] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
if (P2T3 == 7){//5
             leds[693] = CRGB::Black;
             leds[694] = CRGB::Black;
             leds[697] = CRGB::Red;
             leds[698] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 == 9){//7
             leds[698] = CRGB::Black;
             leds[697] = CRGB::Black;
             leds[705] = CRGB::Red;
             leds[706] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==11){//10
             leds[705] = CRGB::Black;
             leds[706] = CRGB::Black;
             leds[717] = CRGB::Red;
             leds[718] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==13){//13
             leds[717] = CRGB::Black;
             leds[718] = CRGB::Black;
             leds[729] = CRGB::Red;
             leds[730] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==15){//14
             leds[729] = CRGB::Black;
             leds[730] = CRGB::Black;
             leds[733] = CRGB::Red;
             leds[734] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==17){//15
             leds[733] = CRGB::Black;
             leds[734] = CRGB::Black;
             leds[737] = CRGB::Red;
             leds[738] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==19){//16
             leds[737] = CRGB::Black;
             leds[738] = CRGB::Black;
             leds[741] = CRGB::Red;
             leds[742] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==21){//17
             leds[741] = CRGB::Black;
             leds[742] = CRGB::Black;
             leds[745] = CRGB::Red;
             leds[746] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==23){//18
             leds[745] = CRGB::Black;
             leds[746] = CRGB::Black;
             leds[749] = CRGB::Red;
             leds[750] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==25){//19
             leds[749] = CRGB::Black;
             leds[750] = CRGB::Black;
             leds[753] = CRGB::Red;
             leds[754] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

//===================================================     P2 in Layer2

if (P2T3 ==27){//26LED
             leds[878] = CRGB::Red;
             leds[877] = CRGB::Red;
             leds[753] = CRGB::Black;
             leds[754] = CRGB::Black;
             FastLED.show();  
 P2T3++;
}
if (P2T3 ==29){//27
             leds[878] = CRGB::Black;
             leds[877] = CRGB::Black;
             leds[873] = CRGB::Red;
             leds[874] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
if (P2T3 ==31){//28
             leds[873] = CRGB::Black;
             leds[874] = CRGB::Black;
             leds[869] = CRGB::Red;
             leds[870] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
if (P2T3 ==33){//29
             leds[869] = CRGB::Black;
             leds[870] = CRGB::Black;
             leds[865] = CRGB::Red;
             leds[866] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
if (P2T3 ==35){//30
             leds[865] = CRGB::Black;
             leds[866] = CRGB::Black;
             leds[861] = CRGB::Red;
             leds[862] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==37){//31
             leds[861] = CRGB::Black;
             leds[862] = CRGB::Black;
             leds[857] = CRGB::Red;
             leds[858] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==39){//32
             leds[857] = CRGB::Black;
             leds[858] = CRGB::Black;
             leds[853] = CRGB::Red;
             leds[854] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==41){//33
             leds[853] = CRGB::Black;
             leds[854] = CRGB::Black;
             leds[849] = CRGB::Red;
             leds[850] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==43){//34
             leds[849] = CRGB::Black;
             leds[850] = CRGB::Black;
             leds[845] = CRGB::Red;
             leds[846] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==45){//35
             leds[845] = CRGB::Black;
             leds[846] = CRGB::Black;
             leds[841] = CRGB::Red;
             leds[842] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==47){//36
             leds[841] = CRGB::Black;
             leds[842] = CRGB::Black;
             leds[837] = CRGB::Red;
             leds[838] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==49){//37
             leds[837] = CRGB::Black;
             leds[838] = CRGB::Black;
             leds[833] = CRGB::Red;
             leds[834] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==51){//38
             leds[833] = CRGB::Black;
             leds[834] = CRGB::Black;
             leds[829] = CRGB::Red;
             leds[830] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==53){//39
             leds[829] = CRGB::Black;
             leds[830] = CRGB::Black;
             leds[825] = CRGB::Red;
             leds[826] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==55){//40
             leds[825] = CRGB::Black;
             leds[826] = CRGB::Black;
             leds[821] = CRGB::Red;
             leds[822] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==57){//41
             leds[821] = CRGB::Black;
             leds[822] = CRGB::Black;
             leds[817] = CRGB::Red;
             leds[818] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
if (P2T3 ==59){//42
             leds[817] = CRGB::Black;
             leds[818] = CRGB::Black;
             leds[813] = CRGB::Red;
             leds[814] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

if (P2T3 ==61){//43
             leds[813] = CRGB::Black;
             leds[814] = CRGB::Black;
             leds[809] = CRGB::Red;
             leds[810] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

if (P2T3 ==63){//44
             leds[809] = CRGB::Black;
             leds[810] = CRGB::Black;
             leds[805] = CRGB::Red;
             leds[806] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

if (P2T3 ==65){//45
             leds[805] = CRGB::Black;
             leds[806] = CRGB::Black;
             leds[801] = CRGB::Red;
             leds[802] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

if (P2T3 ==67){//46
             leds[801] = CRGB::Black;
             leds[802] = CRGB::Black;
             leds[797] = CRGB::Red;
             leds[798] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

if (P2T3 ==69){//47
             leds[797] = CRGB::Black;
             leds[798] = CRGB::Black;
             leds[793] = CRGB::Red;
             leds[794] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

if (P2T3 ==71){//48
             leds[793] = CRGB::Black;
             leds[794] = CRGB::Black;
             leds[789] = CRGB::Red;
             leds[790] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

if (P2T3 ==73){//49
             leds[789] = CRGB::Black;
             leds[790] = CRGB::Black;
             leds[785] = CRGB::Red;
             leds[786] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

if (P2T3 ==75){//50
             leds[785] = CRGB::Black;
             leds[786] = CRGB::Black;
             leds[781] = CRGB::Red;
             leds[782] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}



if (P2T3 == 77){//back to 1
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

if (P2T4 == 1000){
             for (int i = 313; i < 478;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P2T4++;
}


//===================================================     P2 in Layer4
if (P2T4 == 1){//1 LED
             leds[478] = CRGB::Red;
             leds[477] = CRGB::Red;
             leds[313] = CRGB::Black;
             leds[314] = CRGB::Black;
             FastLED.show();  
 P2T4++;
}
if (P2T4 == 3){//2
             leds[478] = CRGB::Black;
             leds[477] = CRGB::Black;
             leds[474] = CRGB::Red;
             leds[473] = CRGB::Red;
             FastLED.show();
 P2T4++;
}
if (P2T4 == 5){//3
             leds[474] = CRGB::Black;
             leds[473] = CRGB::Black;
             leds[470] = CRGB::Red;
             leds[469] = CRGB::Red;
             FastLED.show();
 P2T4++;
}
if (P2T4 == 7){//4
             leds[470] = CRGB::Black;
             leds[469] = CRGB::Black;
             leds[466] = CRGB::Red;
             leds[465] = CRGB::Red;
             FastLED.show();
 P2T4++;
}
if (P2T4 == 9){//5
             leds[465] = CRGB::Black;
             leds[466] = CRGB::Black;
             leds[462] = CRGB::Red;
             leds[461] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==11){//6
             leds[462] = CRGB::Black;
             leds[461] = CRGB::Black;
             leds[458] = CRGB::Red;
             leds[457] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==13){//7
             leds[458] = CRGB::Black;
             leds[457] = CRGB::Black;
             leds[454] = CRGB::Red;
             leds[453] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==15){//8
             leds[454] = CRGB::Black;
             leds[453] = CRGB::Black;
             leds[450] = CRGB::Red;
             leds[449] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==17){//9
             leds[450] = CRGB::Black;
             leds[449] = CRGB::Black;
             leds[446] = CRGB::Red;
             leds[445] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==19){//10
             leds[446] = CRGB::Black;
             leds[445] = CRGB::Black;
             leds[442] = CRGB::Red;
             leds[441] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==21){//11
             leds[442] = CRGB::Black;
             leds[441] = CRGB::Black;
             leds[438] = CRGB::Red;
             leds[437] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==23){//12
             leds[438] = CRGB::Black;
             leds[437] = CRGB::Black;
             leds[433] = CRGB::Red;
             leds[434] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==25){//13
             leds[433] = CRGB::Black;
             leds[434] = CRGB::Black;
             leds[430] = CRGB::Red;
             leds[429] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==27){//14
             leds[430] = CRGB::Black;
             leds[429] = CRGB::Black;
             leds[426] = CRGB::Red;
             leds[425] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==29){//15
             leds[426] = CRGB::Black;
             leds[425] = CRGB::Black;
             leds[422] = CRGB::Red;
             leds[421] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==31){//16
             leds[422] = CRGB::Black;
             leds[421] = CRGB::Black;
             leds[418] = CRGB::Red;
             leds[417] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==33){//17
             leds[418] = CRGB::Black;
             leds[417] = CRGB::Black;
             leds[414] = CRGB::Red;
             leds[413] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==35){//18
             leds[414] = CRGB::Black;
             leds[413] = CRGB::Black;
             leds[410] = CRGB::Red;
             leds[409] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==37){//19
             leds[410] = CRGB::Black;
             leds[409] = CRGB::Black;
             leds[406] = CRGB::Red;
             leds[405] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==39){//20
             leds[406] = CRGB::Black;
             leds[405] = CRGB::Black;
             leds[402] = CRGB::Red;
             leds[401] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==41){//21
             leds[402] = CRGB::Black;
             leds[401] = CRGB::Black;
             leds[398] = CRGB::Red;
             leds[397] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==43){//22
             leds[398] = CRGB::Black;
             leds[397] = CRGB::Black;
             leds[394] = CRGB::Red;
             leds[393] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==45){//23
             leds[393] = CRGB::Black;
             leds[394] = CRGB::Black;
             leds[390] = CRGB::Red;
             leds[389] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==47){//24
             leds[390] = CRGB::Black;
             leds[389] = CRGB::Black;
             leds[386] = CRGB::Red;
             leds[385] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==49){//25
             leds[386] = CRGB::Black;
             leds[385] = CRGB::Black;
             leds[382] = CRGB::Red;
             leds[381] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
//=================================== P2 in Layer 3

if (P2T4 ==51){//8
             leds[382] = CRGB::Black;
             leds[381] = CRGB::Black;
             leds[269] = CRGB::Red;
             leds[270] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==53){//9
             leds[269] = CRGB::Black;
             leds[270] = CRGB::Black;
             leds[273] = CRGB::Red;
             leds[274] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==55){//10
             leds[273] = CRGB::Black;
             leds[274] = CRGB::Black;
             leds[277] = CRGB::Red;
             leds[278] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==57){//11
             leds[277] = CRGB::Black;
             leds[278] = CRGB::Black;
             leds[281] = CRGB::Red;
             leds[282] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==59){//12
             leds[281] = CRGB::Black;
             leds[282] = CRGB::Black;
             leds[285] = CRGB::Red;
             leds[286] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==61){//13
             leds[285] = CRGB::Black;
             leds[286] = CRGB::Black;
             leds[289] = CRGB::Red;
             leds[290] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==63){//14
             leds[289] = CRGB::Black;
             leds[290] = CRGB::Black;
             leds[293] = CRGB::Red;
             leds[294] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==65){//15
             leds[293] = CRGB::Black;
             leds[294] = CRGB::Black;
             leds[297] = CRGB::Red;
             leds[298] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==67){//16
             leds[297] = CRGB::Black;
             leds[298] = CRGB::Black;
             leds[301] = CRGB::Red;
             leds[302] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==69){//17
             leds[301] = CRGB::Black;
             leds[302] = CRGB::Black;
             leds[305] = CRGB::Red;
             leds[306] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==71){//18
             leds[305] = CRGB::Black;
             leds[306] = CRGB::Black;
             leds[309] = CRGB::Red;
             leds[310] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
if (P2T4 ==73){//19
             leds[309] = CRGB::Black;
             leds[310] = CRGB::Black;
             leds[313] = CRGB::Red;
             leds[314] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}


if (P2T4 == 75){//back to 1
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

if (P3T1 == 1000){                                   // to clear P1 in tray 1
            for (int i = 1281; i < 1478;i++)
            {
               leds[i] = CRGB::Black;  
           }  FastLED.show();  
            
 P3T1++;
}
//===================================================     P3 in Layer1
if (P3T1 == 1){//1 LED
             leds[1281] = CRGB::Green;
             leds[1282] = CRGB::Green;
             leds[1381] = CRGB::Black;
             leds[1382] = CRGB::Black;
             FastLED.show();  
 P3T1++;
}
if (P3T1 == 3){//2
             leds[1281] = CRGB::Black;
             leds[1282] = CRGB::Black;
             leds[1285] = CRGB::Green;
             leds[1286] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
if (P3T1 == 5){//3
             leds[1285] = CRGB::Black;
             leds[1286] = CRGB::Black;
             leds[1289] = CRGB::Green;
             leds[1290] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
if (P3T1 == 7){//4
             leds[1289] = CRGB::Black;
             leds[1290] = CRGB::Black;
             leds[1293] = CRGB::Green;
             leds[1294] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
if (P3T1 == 9){//5
             leds[1293] = CRGB::Black;
             leds[1294] = CRGB::Black;
             leds[1297] = CRGB::Green;
             leds[1298] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==11){//6
             leds[1297] = CRGB::Black;
             leds[1298] = CRGB::Black;
             leds[1301] = CRGB::Green;
             leds[1302] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==13){//7
             leds[1301] = CRGB::Black;
             leds[1302] = CRGB::Black;
             leds[1305] = CRGB::Green;
             leds[1306] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==15){//8
             leds[1305] = CRGB::Black;
             leds[1306] = CRGB::Black;
             leds[1309] = CRGB::Green;
             leds[1310] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==17){//9
             leds[1309] = CRGB::Black;
             leds[1310] = CRGB::Black;
             leds[1313] = CRGB::Green;
             leds[1314] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==19){//10
             leds[1313] = CRGB::Black;
             leds[1314] = CRGB::Black;
             leds[1317] = CRGB::Green;
             leds[1318] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==21){//11
             leds[1317] = CRGB::Black;
             leds[1318] = CRGB::Black;
             leds[1321] = CRGB::Green;
             leds[1322] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==23){//12
             leds[1321] = CRGB::Black;
             leds[1322] = CRGB::Black;
             leds[1325] = CRGB::Green;
             leds[1326] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==25){//13
             leds[1325] = CRGB::Black;
             leds[1326] = CRGB::Black;
             leds[1329] = CRGB::Green;
             leds[1330] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==27){//14
             leds[1329] = CRGB::Black;
             leds[1330] = CRGB::Black;
             leds[1333] = CRGB::Green;
             leds[1334] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==29){//15
             leds[1333] = CRGB::Black;
             leds[1334] = CRGB::Black;
             leds[1337] = CRGB::Green;
             leds[1338] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==31){//16
             leds[1337] = CRGB::Black;
             leds[1338] = CRGB::Black;
             leds[1341] = CRGB::Green;
             leds[1342] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==33){//17
             leds[1341] = CRGB::Black;
             leds[1342] = CRGB::Black;
             leds[1345] = CRGB::Green;
             leds[1346] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==35){//18
             leds[1345] = CRGB::Black;
             leds[1346] = CRGB::Black;
             leds[1349] = CRGB::Green;
             leds[1350] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==37){//19
             leds[1349] = CRGB::Black;
             leds[1350] = CRGB::Black;
             leds[1353] = CRGB::Green;
             leds[1354] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==39){//20
             leds[1353] = CRGB::Black;
             leds[1354] = CRGB::Black;
             leds[1357] = CRGB::Green;
             leds[1358] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==41){//21
             leds[1357] = CRGB::Black;
             leds[1358] = CRGB::Black;
             leds[1361] = CRGB::Green;
             leds[1362] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==43){//22
             leds[1361] = CRGB::Black;
             leds[1362] = CRGB::Black;
             leds[1365] = CRGB::Green;
             leds[1366] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==45){//23
             leds[1365] = CRGB::Black;
             leds[1366] = CRGB::Black;
             leds[1369] = CRGB::Green;
             leds[1370] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==47){//24
             leds[1369] = CRGB::Black;
             leds[1370] = CRGB::Black;
             leds[1373] = CRGB::Green;
             leds[1374] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==49){//25
             leds[1373] = CRGB::Black;
             leds[1374] = CRGB::Black;
             leds[1377] = CRGB::Green;
             leds[1378] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
//===================================================     P3 in Layer2

if (P3T1 ==51){//26   
             leds[1377] = CRGB::Black;
             leds[1378] = CRGB::Black;
             leds[1477] = CRGB::Green;
             leds[1478] = CRGB::Green;
             FastLED.show();  
 P3T1++;
}
if (P3T1 ==53){//27
             leds[1477] = CRGB::Black;
             leds[1478] = CRGB::Black;
             leds[1473] = CRGB::Green;
             leds[1474] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
if (P3T1 ==55){//28
             leds[1473] = CRGB::Black;
             leds[1474] = CRGB::Black;
             leds[1469] = CRGB::Green;
             leds[1470] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
if (P3T1 ==57){//29
             leds[1469] = CRGB::Black;
             leds[1470] = CRGB::Black;
             leds[1465] = CRGB::Green;
             leds[1466] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
if (P3T1 ==59){//30
             leds[1465] = CRGB::Black;
             leds[1466] = CRGB::Black;
             leds[1461] = CRGB::Green;
             leds[1462] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==61){//31
             leds[1461] = CRGB::Black;
             leds[1462] = CRGB::Black;
             leds[1457] = CRGB::Green;
             leds[1458] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==63){//32
             leds[1457] = CRGB::Black;
             leds[1458] = CRGB::Black;
             leds[1453] = CRGB::Green;
             leds[1454] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==65){//33
             leds[1453] = CRGB::Black;
             leds[1454] = CRGB::Black;
             leds[1449] = CRGB::Green;
             leds[1450] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==67){//34
             leds[1449] = CRGB::Black;
             leds[1450] = CRGB::Black;
             leds[1445] = CRGB::Green;
             leds[1446] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==69){//35
             leds[1445] = CRGB::Black;
             leds[1446] = CRGB::Black;
             leds[1441] = CRGB::Green;
             leds[1442] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==71){//36
             leds[1441] = CRGB::Black;
             leds[1442] = CRGB::Black;
             leds[1437] = CRGB::Green;
             leds[1438] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==73){//37
             leds[1437] = CRGB::Black;
             leds[1438] = CRGB::Black;
             leds[1433] = CRGB::Green;
             leds[1434] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==75){//38
             leds[1433] = CRGB::Black;
             leds[1434] = CRGB::Black;
             leds[1429] = CRGB::Green;
             leds[1430] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==77){//39
             leds[1429] = CRGB::Black;
             leds[1430] = CRGB::Black;
             leds[1425] = CRGB::Green;
             leds[1426] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==79){//40
             leds[1425] = CRGB::Black;
             leds[1426] = CRGB::Black;
             leds[1421] = CRGB::Green;
             leds[1422] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==81){//41
             leds[1421] = CRGB::Black;
             leds[1422] = CRGB::Black;
             leds[1417] = CRGB::Green;
             leds[1418] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==83){//42
             leds[1417] = CRGB::Black;
             leds[1418] = CRGB::Black;
             leds[1413] = CRGB::Green;
             leds[1414] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==85){//43
             leds[1413] = CRGB::Black;
             leds[1414] = CRGB::Black;
             leds[1409] = CRGB::Green;
             leds[1410] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==87){//44
             leds[1409] = CRGB::Black;
             leds[1410] = CRGB::Black;
             leds[1405] = CRGB::Green;
             leds[1406] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==89){//45
             leds[1405] = CRGB::Black;
             leds[1406] = CRGB::Black;
             leds[1401] = CRGB::Green;
             leds[1402] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==91){//46
             leds[1401] = CRGB::Black;
             leds[1402] = CRGB::Black;
             leds[1397] = CRGB::Green;
             leds[1398] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==93){//47
             leds[1397] = CRGB::Black;
             leds[1398] = CRGB::Black;
             leds[1393] = CRGB::Green;
             leds[1394] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==95){//48
             leds[1393] = CRGB::Black;
             leds[1394] = CRGB::Black;
             leds[1389] = CRGB::Green;
             leds[1390] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==97){//49
             leds[1389] = CRGB::Black;
             leds[1390] = CRGB::Black;
             leds[1385] = CRGB::Green;
             leds[1386] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
if (P3T1 ==99){//50
             leds[1385] = CRGB::Black;
             leds[1386] = CRGB::Black;
             leds[1381] = CRGB::Green;
             leds[1382] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}

if (P3T1 == 101){//back to 1
if ((P1T2 > 999) && (P2T2 > 999) && (P3T2 > 999) && (P4T2 > 999))
{
  P3T2 = 1;
  P3T1 = 1; 
}
if((P1T2 < 999) || (P2T2 < 999) || (P3T2 < 999) || (P3T2 < 999))
{
  P3T1 = 1; 
}
}


//==========================================================================================================     start of tray 2 P3

//===================================================     P3 in Layer1
if (P3T2 == 1000){
             for (int x = 881; x < 1079;x++)
            {
               leds[x] = CRGB::Black;  
            } FastLED.show();  
            
 P3T2++;
}
if (P3T2 == 1){//1 LED
             leds[881] = CRGB::Green;
             leds[882] = CRGB::Green;
             leds[981] = CRGB::Black;
             leds[982] = CRGB::Black;
             FastLED.show();  
 P3T2++;
}
if (P3T2 == 3){//2
             leds[881] = CRGB::Black;
             leds[882] = CRGB::Black;
             leds[885] = CRGB::Green;
             leds[886] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
if (P3T2 == 5){//3
             leds[885] = CRGB::Black;
             leds[886] = CRGB::Black;
             leds[889] = CRGB::Green;
             leds[890] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
if (P3T2 == 7){//4
             leds[889] = CRGB::Black;
             leds[890] = CRGB::Black;
             leds[893] = CRGB::Green;
             leds[894] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
if (P3T2 == 9){//5
             leds[893] = CRGB::Black;
             leds[894] = CRGB::Black;
             leds[897] = CRGB::Green;
             leds[898] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==11){//6
             leds[897] = CRGB::Black;
             leds[898] = CRGB::Black;
             leds[901] = CRGB::Green;
             leds[902] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==13){//7
             leds[901] = CRGB::Black;
             leds[902] = CRGB::Black;
             leds[905] = CRGB::Green;
             leds[906] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==15){//8
             leds[905] = CRGB::Black;
             leds[906] = CRGB::Black;
             leds[909] = CRGB::Green;
             leds[910] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==17){//9
             leds[909] = CRGB::Black;
             leds[910] = CRGB::Black;
             leds[913] = CRGB::Green;
             leds[914] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==19){//10
             leds[913] = CRGB::Black;
             leds[914] = CRGB::Black;
             leds[917] = CRGB::Green;
             leds[918] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 == 21){//11
             leds[917] = CRGB::Black;
             leds[918] = CRGB::Black;
             leds[921] = CRGB::Green;
             leds[922] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==23){//12
             leds[921] = CRGB::Black;
             leds[922] = CRGB::Black;
             leds[925] = CRGB::Green;
             leds[926] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==25){//13
             leds[925] = CRGB::Black;
             leds[926] = CRGB::Black;
             leds[929] = CRGB::Green;
             leds[930] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==27){//14
             leds[929] = CRGB::Black;
             leds[930] = CRGB::Black;
             leds[933] = CRGB::Green;
             leds[934] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==29){//15
             leds[933] = CRGB::Black;
             leds[934] = CRGB::Black;
             leds[937] = CRGB::Green;
             leds[938] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==31){//16
             leds[937] = CRGB::Black;
             leds[938] = CRGB::Black;
             leds[941] = CRGB::Green;
             leds[942] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==33){//17
             leds[941] = CRGB::Black;
             leds[942] = CRGB::Black;
             leds[945] = CRGB::Green;
             leds[946] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==35){//18
             leds[945] = CRGB::Black;
             leds[946] = CRGB::Black;
             leds[949] = CRGB::Green;
             leds[950] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==37){//19
             leds[949] = CRGB::Black;
             leds[950] = CRGB::Black;
             leds[953] = CRGB::Green;
             leds[954] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==39){//20
             leds[953] = CRGB::Black;
             leds[954] = CRGB::Black;
             leds[957] = CRGB::Green;
             leds[958] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==41){//21
             leds[957] = CRGB::Black;
             leds[958] = CRGB::Black;
             leds[961] = CRGB::Green;
             leds[962] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==43){//22
             leds[961] = CRGB::Black;
             leds[962] = CRGB::Black;
             leds[965] = CRGB::Green;
             leds[966] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==45){//23
             leds[965] = CRGB::Black;
             leds[966] = CRGB::Black;
             leds[969] = CRGB::Green;
             leds[970] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==47){//24
             leds[969] = CRGB::Black;
             leds[970] = CRGB::Black;
             leds[973] = CRGB::Green;
             leds[974] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==49){//25
             leds[973] = CRGB::Black;
             leds[974] = CRGB::Black;
             leds[977] = CRGB::Green;
             leds[978] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}

//===================================================     P3 in Layer2

if (P3T2 ==51){//26LED
             leds[1077] = CRGB::Green;
             leds[1078] = CRGB::Green;
             leds[977] = CRGB::Black;
             leds[978] = CRGB::Black;
             FastLED.show();  
 P3T2++;
}
if (P3T2 ==53){//27
             leds[1077] = CRGB::Black;
             leds[1078] = CRGB::Black;
             leds[1073] = CRGB::Green;
             leds[1074] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
if (P3T2 ==55){//28
             leds[1073] = CRGB::Black;
             leds[1074] = CRGB::Black;
             leds[1070] = CRGB::Green;
             leds[1069] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
if (P3T2 ==57){//29
             leds[1069] = CRGB::Black;
             leds[1070] = CRGB::Black;
             leds[1065] = CRGB::Green;
             leds[1066] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
if (P3T2 ==59){//30
             leds[1065] = CRGB::Black;
             leds[1066] = CRGB::Black;
             leds[1061] = CRGB::Green;
             leds[1062] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==61){//31
             leds[1061] = CRGB::Black;
             leds[1062] = CRGB::Black;
             leds[1057] = CRGB::Green;
             leds[1058] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==63){//32
             leds[1057] = CRGB::Black;
             leds[1058] = CRGB::Black;
             leds[1053] = CRGB::Green;
             leds[1054] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==65){//33
             leds[1053] = CRGB::Black;
             leds[1054] = CRGB::Black;
             leds[1049] = CRGB::Green;
             leds[1050] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==67){//34
             leds[1049] = CRGB::Black;
             leds[1050] = CRGB::Black;
             leds[1045] = CRGB::Green;
             leds[1046] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==69){//35
             leds[1045] = CRGB::Black;
             leds[1046] = CRGB::Black;
             leds[1041] = CRGB::Green;
             leds[1042] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 == 71){//36
             leds[1041] = CRGB::Black;
             leds[1042] = CRGB::Black;
             leds[1037] = CRGB::Green;
             leds[1038] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==73){//37
             leds[1037] = CRGB::Black;
             leds[1038] = CRGB::Black;
             leds[1033] = CRGB::Green;
             leds[1034] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==75){//38
             leds[1033] = CRGB::Black;
             leds[1034] = CRGB::Black;
             leds[1029] = CRGB::Green;
             leds[1030] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==77){//39
             leds[1029] = CRGB::Black;
             leds[1030] = CRGB::Black;
             leds[1025] = CRGB::Green;
             leds[1026] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==79){//40
             leds[1025] = CRGB::Black;
             leds[1026] = CRGB::Black;
             leds[1021] = CRGB::Green;
             leds[1022] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==81){//41
             leds[1021] = CRGB::Black;
             leds[1022] = CRGB::Black;
             leds[1017] = CRGB::Green;
             leds[1018] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==83){//42
             leds[1017] = CRGB::Black;
             leds[1018] = CRGB::Black;
             leds[1013] = CRGB::Green;
             leds[1014] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==85){//43
             leds[1013] = CRGB::Black;
             leds[1014] = CRGB::Black;
             leds[1009] = CRGB::Green;
             leds[1010] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==87){//44
             leds[1010] = CRGB::Black;
             leds[1009] = CRGB::Black;
             leds[1005] = CRGB::Green;
             leds[1006] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==89){//45
             leds[1005] = CRGB::Black;
             leds[1006] = CRGB::Black;
             leds[1001] = CRGB::Green;
             leds[1002] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==91){//46
             leds[1001] = CRGB::Black;
             leds[1002] = CRGB::Black;
             leds[997] = CRGB::Green;
             leds[998] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==93){//47
             leds[997] = CRGB::Black;
             leds[998] = CRGB::Black;
             leds[993] = CRGB::Green;
             leds[994] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==95){//48
             leds[993] = CRGB::Black;
             leds[994] = CRGB::Black;
             leds[989] = CRGB::Green;
             leds[990] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==97){//49
             leds[989] = CRGB::Black;
             leds[990] = CRGB::Black;
             leds[985] = CRGB::Green;
             leds[986] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 ==99){//50
             leds[985] = CRGB::Black;
             leds[986] = CRGB::Black;
             leds[981] = CRGB::Green;
             leds[982] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
if (P3T2 == 101){//back to 1
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
//===================================================     P3 in Layer1
if (P3T3 == 1000){
            for (int i = 481; i < 679;i++)
            {
               leds[i] = CRGB::Black;  
            }   
             leds[777] = CRGB::Black;
             leds[778] = CRGB::Black;
            FastLED.show();
 P3T3++;
}

if (P3T3 == 1){//1 LED
             leds[482] = CRGB::Green;
             leds[481] = CRGB::Green;
             leds[777] = CRGB::Black;
             leds[778] = CRGB::Black;
             FastLED.show();  
 P3T3++;
}
if (P3T3 == 3){//2
             leds[482] = CRGB::Black;
             leds[481] = CRGB::Black;
             leds[486] = CRGB::Green;
             leds[485] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
if (P3T3 == 5){//3
             leds[486] = CRGB::Black;
             leds[485] = CRGB::Black;
             leds[490] = CRGB::Green;
             leds[489] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
if (P3T3 == 7){//4
             leds[490] = CRGB::Black;
             leds[489] = CRGB::Black;
             leds[494] = CRGB::Green;
             leds[493] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
if (P3T3 == 9){//5
             leds[494] = CRGB::Black;
             leds[493] = CRGB::Black;
             leds[498] = CRGB::Green;
             leds[497] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==11){//6
             leds[498] = CRGB::Black;
             leds[497] = CRGB::Black;
             leds[501] = CRGB::Green;
             leds[502] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==13){//7
             leds[501] = CRGB::Black;
             leds[502] = CRGB::Black;
             leds[505] = CRGB::Green;
             leds[506] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==15){//8
             leds[505] = CRGB::Black;
             leds[506] = CRGB::Black;
             leds[509] = CRGB::Green;
             leds[510] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==17){//9
             leds[509] = CRGB::Black;
             leds[510] = CRGB::Black;
             leds[513] = CRGB::Green;
             leds[514] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==19){//10
             leds[513] = CRGB::Black;
             leds[514] = CRGB::Black;
             leds[517] = CRGB::Green;
             leds[518] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
 P3T3++;
 P3T3++;
}
if (P3T3 ==23){//12
             leds[521] = CRGB::Black;
             leds[522] = CRGB::Black;
             leds[525] = CRGB::Green;
             leds[526] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==25){//13
             leds[525] = CRGB::Black;
             leds[526] = CRGB::Black;
             leds[529] = CRGB::Green;
             leds[530] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==27){//14
             leds[529] = CRGB::Black;
             leds[530] = CRGB::Black;
             leds[533] = CRGB::Green;
             leds[534] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==29){//15
             leds[533] = CRGB::Black;
             leds[534] = CRGB::Black;
             leds[537] = CRGB::Green;
             leds[538] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==31){//16
             leds[537] = CRGB::Black;
             leds[538] = CRGB::Black;
             leds[541] = CRGB::Green;
             leds[542] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==33){//17
             leds[541] = CRGB::Black;
             leds[542] = CRGB::Black;
             leds[545] = CRGB::Green;
             leds[546] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==35){//18
             leds[545] = CRGB::Black;
             leds[546] = CRGB::Black;
             leds[549] = CRGB::Green;
             leds[550] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==37){//19
             leds[549] = CRGB::Black;
             leds[550] = CRGB::Black;
             leds[553] = CRGB::Green;
             leds[554] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==39){//20
             leds[553] = CRGB::Black;
             leds[554] = CRGB::Black;
             leds[557] = CRGB::Green;
             leds[558] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==41){//21
             leds[557] = CRGB::Black;
             leds[558] = CRGB::Black;
             leds[561] = CRGB::Green;
             leds[562] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==43){//22
             leds[561] = CRGB::Black;
             leds[562] = CRGB::Black;
             leds[565] = CRGB::Green;
             leds[566] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==45){//23
             leds[565] = CRGB::Black;
             leds[566] = CRGB::Black;
             leds[569] = CRGB::Green;
             leds[570] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==47){//24
             leds[569] = CRGB::Black;
             leds[570] = CRGB::Black;
             leds[573] = CRGB::Green;
             leds[574] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==49){//25
             leds[573] = CRGB::Black;
             leds[574] = CRGB::Black;
             leds[577] = CRGB::Green;
             leds[578] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}

//===================================================     P3 in Layer2

if (P3T3 ==51){//26LED
             leds[678] = CRGB::Green;
             leds[677] = CRGB::Green;
             leds[577] = CRGB::Black;
             leds[578] = CRGB::Black;
             FastLED.show();  
 P3T3++;
}
if (P3T3 ==53){//27
             leds[678] = CRGB::Black;
             leds[677] = CRGB::Black;
             leds[674] = CRGB::Green;
             leds[673] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
if (P3T3 ==55){//28
             leds[674] = CRGB::Black;
             leds[673] = CRGB::Black;
             leds[670] = CRGB::Green;
             leds[669] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
if (P3T3 ==57){//29
             leds[670] = CRGB::Black;
             leds[669] = CRGB::Black;
             leds[666] = CRGB::Green;
             leds[665] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
if (P3T3 ==59){//30
             leds[666] = CRGB::Black;
             leds[665] = CRGB::Black;
             leds[662] = CRGB::Green;
             leds[661] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==61){//31
             leds[662] = CRGB::Black;
             leds[661] = CRGB::Black;
             leds[658] = CRGB::Green;
             leds[657] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==63){//32
             leds[658] = CRGB::Black;
             leds[657] = CRGB::Black;
             leds[654] = CRGB::Green;
             leds[653] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==65){//33
             leds[654] = CRGB::Black;
             leds[653] = CRGB::Black;
             leds[650] = CRGB::Green;
             leds[649] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==67){//34
             leds[650] = CRGB::Black;
             leds[649] = CRGB::Black;
             leds[646] = CRGB::Green;
             leds[645] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==69){//35
             leds[646] = CRGB::Black;
             leds[645] = CRGB::Black;
             leds[642] = CRGB::Green;
             leds[641] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 == 71){//36
             leds[642] = CRGB::Black;
             leds[641] = CRGB::Black;
             leds[638] = CRGB::Green;
             leds[637] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==73){//37
             leds[638] = CRGB::Black;
             leds[637] = CRGB::Black;
             leds[634] = CRGB::Green;
             leds[633] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==75){//38
             leds[634] = CRGB::Black;
             leds[633] = CRGB::Black;
             leds[630] = CRGB::Green;
             leds[629] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==77){//39
             leds[630] = CRGB::Black;
             leds[629] = CRGB::Black;
             leds[626] = CRGB::Green;
             leds[625] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==79){//40
             leds[626] = CRGB::Black;
             leds[625] = CRGB::Black;
             leds[622] = CRGB::Green;
             leds[621] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==81){//41
             leds[622] = CRGB::Black;
             leds[621] = CRGB::Black;
             leds[618] = CRGB::Green;
             leds[617] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==83){//42
             leds[618] = CRGB::Black;
             leds[617] = CRGB::Black;
             leds[614] = CRGB::Green;
             leds[613] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==85){//43
             leds[614] = CRGB::Black;
             leds[613] = CRGB::Black;
             leds[610] = CRGB::Green;
             leds[609] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==87){//44
             leds[610] = CRGB::Black;
             leds[609] = CRGB::Black;
             leds[606] = CRGB::Green;
             leds[605] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==89){//45
             leds[606] = CRGB::Black;
             leds[605] = CRGB::Black;
             leds[602] = CRGB::Green;
             leds[601] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==91){//46
             leds[602] = CRGB::Black;
             leds[601] = CRGB::Black;
             leds[598] = CRGB::Green;
             leds[597] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==93){//47
             leds[598] = CRGB::Black;
             leds[597] = CRGB::Black;
             leds[594] = CRGB::Green;
             leds[593] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==95){//48
             leds[594] = CRGB::Black;
             leds[593] = CRGB::Black;
             leds[590] = CRGB::Green;
             leds[589] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==97){//49
             leds[590] = CRGB::Black;
             leds[589] = CRGB::Black;
             leds[586] = CRGB::Green;
             leds[585] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
if (P3T3 ==99){//50
             leds[586] = CRGB::Black;
             leds[585] = CRGB::Black;
             leds[582] = CRGB::Green;
             leds[581] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}

if (P3T3 ==101){//51
             leds[582] = CRGB::Black;
             leds[581] = CRGB::Black;
             leds[777] = CRGB::Green;
             leds[778] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}

if (P3T3 == 103){//back to 1
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
if (P3T4 == 1000){
for (int i = 120; i < 238;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P3T4++;
}

//===================================================     P3 in Layer2
if (P3T4 == 1){//1 LED
             leds[237] = CRGB::Green;
             leds[236] = CRGB::Green;
             leds[120] = CRGB::Black;
             leds[121] = CRGB::Black;
             FastLED.show();  
 P3T4++;
}
if (P3T4 == 3){//2
             leds[237] = CRGB::Black;
             leds[236] = CRGB::Black;
             leds[233] = CRGB::Green;
             leds[232] = CRGB::Green;
             FastLED.show();
 P3T4++;
}
if (P3T4 == 5){//3
             leds[233] = CRGB::Black;
             leds[232] = CRGB::Black;
             leds[229] = CRGB::Green;
             leds[228] = CRGB::Green;
             FastLED.show();
 P3T4++;
}
if (P3T4 == 7){//4
             leds[229] = CRGB::Black;
             leds[228] = CRGB::Black;
             leds[225] = CRGB::Green;
             leds[224] = CRGB::Green;
             FastLED.show();
 P3T4++;
}
if (P3T4 == 9){//5
             leds[225] = CRGB::Black;
             leds[224] = CRGB::Black;
             leds[221] = CRGB::Green;
             leds[220] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==11){//6
             leds[221] = CRGB::Black;
             leds[220] = CRGB::Black;
             leds[217] = CRGB::Green;
             leds[216] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==13){//7
             leds[217] = CRGB::Black;
             leds[216] = CRGB::Black;
             leds[213] = CRGB::Green;
             leds[212] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==15){//8
             leds[213] = CRGB::Black;
             leds[212] = CRGB::Black;
             leds[209] = CRGB::Green;
             leds[208] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==17){//9
             leds[209] = CRGB::Black;
             leds[208] = CRGB::Black;
             leds[205] = CRGB::Green;
             leds[204] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==19){//10
             leds[205] = CRGB::Black;
             leds[204] = CRGB::Black;
             leds[201] = CRGB::Green;
             leds[200] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 == 21){//11
             leds[201] = CRGB::Black;
             leds[200] = CRGB::Black;
             leds[197] = CRGB::Green;
             leds[196] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==23){//12
             leds[197] = CRGB::Black;
             leds[196] = CRGB::Black;
             leds[193] = CRGB::Green;
             leds[192] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==25){//13
             leds[193] = CRGB::Black;
             leds[192] = CRGB::Black;
             leds[189] = CRGB::Green;
             leds[188] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==27){//14
             leds[189] = CRGB::Black;
             leds[188] = CRGB::Black;
             leds[185] = CRGB::Green;
             leds[184] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==29){//15
             leds[185] = CRGB::Black;
             leds[184] = CRGB::Black;
             leds[181] = CRGB::Green;
             leds[180] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==31){//16
             leds[181] = CRGB::Black;
             leds[180] = CRGB::Black;
             leds[177] = CRGB::Green;
             leds[176] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==33){//17
             leds[177] = CRGB::Black;
             leds[176] = CRGB::Black;
             leds[173] = CRGB::Green;
             leds[172] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==35){//18
             leds[173] = CRGB::Black;
             leds[172] = CRGB::Black;
             leds[169] = CRGB::Green;
             leds[168] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==37){//19
             leds[169] = CRGB::Black;
             leds[168] = CRGB::Black;
             leds[165] = CRGB::Green;
             leds[164] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==39){//20
             leds[165] = CRGB::Black;
             leds[164] = CRGB::Black;
             leds[161] = CRGB::Green;
             leds[160] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==41){//21
             leds[161] = CRGB::Black;
             leds[160] = CRGB::Black;
             leds[157] = CRGB::Green;
             leds[156] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==43){//22
             leds[157] = CRGB::Black;
             leds[156] = CRGB::Black;
             leds[153] = CRGB::Green;
             leds[152] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==45){//23
             leds[153] = CRGB::Black;
             leds[152] = CRGB::Black;
             leds[149] = CRGB::Green;
             leds[148] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==47){//24
             leds[149] = CRGB::Black;
             leds[148] = CRGB::Black;
             leds[145] = CRGB::Green;
             leds[144] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==49){//25
             leds[145] = CRGB::Black;
             leds[144] = CRGB::Black;
             leds[141] = CRGB::Green;
             leds[140] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==51){//26
             leds[141] = CRGB::Black;
             leds[140] = CRGB::Black;
             leds[137] = CRGB::Green;
             leds[136] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==53){//27
             leds[137] = CRGB::Black;
             leds[136] = CRGB::Black;
             leds[133] = CRGB::Green;
             leds[132] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==55){//29
             leds[129] = CRGB::Black;
             leds[128] = CRGB::Black;
             leds[124] = CRGB::Green;
             leds[125] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
if (P3T4 ==57){//30
             leds[124] = CRGB::Black;
             leds[125] = CRGB::Black;
             leds[120] = CRGB::Green;
             leds[121] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}



if (P3T4 == 59){//back to 1

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
        for (int i = 1469; i < 1667;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P4T1++;
}

//===================================================     P4 in Layer1
if (P4T1 == 1){//1 LED
             leds[1469] = CRGB::Yellow;
             leds[1470] = CRGB::Yellow;
             leds[1569] = CRGB::Black;
             leds[1570] = CRGB::Black;
             FastLED.show();  
 P4T1++;
}
if (P4T1 == 3){//2
             leds[1469] = CRGB::Black;
             leds[1470] = CRGB::Black;
             leds[1473] = CRGB::Yellow;
             leds[1474] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
if (P4T1 == 5){//3
             leds[1473] = CRGB::Black;
             leds[1474] = CRGB::Black;
             leds[1477] = CRGB::Yellow;
             leds[1478] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
if (P4T1 == 7){//4
             leds[1477] = CRGB::Black;
             leds[1478] = CRGB::Black;
             leds[1481] = CRGB::Yellow;
             leds[1482] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
if (P4T1 == 9){//5
             leds[1481] = CRGB::Black;
             leds[1482] = CRGB::Black;
             leds[1485] = CRGB::Yellow;
             leds[1486] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==11){//6
             leds[1485] = CRGB::Black;
             leds[1486] = CRGB::Black;
             leds[1489] = CRGB::Yellow;
             leds[1490] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==13){//7
             leds[1489] = CRGB::Black;
             leds[1490] = CRGB::Black;
             leds[1493] = CRGB::Yellow;
             leds[1494] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==15){//8
             leds[1493] = CRGB::Black;
             leds[1494] = CRGB::Black;
             leds[1497] = CRGB::Yellow;
             leds[1498] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==17){//9
             leds[1497] = CRGB::Black;
             leds[1498] = CRGB::Black;
             leds[1501] = CRGB::Yellow;
             leds[1502] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==19){//10
             leds[1501] = CRGB::Black;
             leds[1502] = CRGB::Black;
             leds[1505] = CRGB::Yellow;
             leds[1506] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==21){//11
             leds[1505] = CRGB::Black;
             leds[1506] = CRGB::Black;
             leds[1509] = CRGB::Yellow;
             leds[1510] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==23){//12
             leds[1509] = CRGB::Black;
             leds[1510] = CRGB::Black;
             leds[1513] = CRGB::Yellow;
             leds[1514] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==25){//13
             leds[1513] = CRGB::Black;
             leds[1514] = CRGB::Black;
             leds[1517] = CRGB::Yellow;
             leds[1518] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==27){//14
             leds[1517] = CRGB::Black;
             leds[1518] = CRGB::Black;
             leds[1521] = CRGB::Yellow;
             leds[1522] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==29){//15
             leds[1521] = CRGB::Black;
             leds[1522] = CRGB::Black;
             leds[1525] = CRGB::Yellow;
             leds[1526] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==31){//16
             leds[1525] = CRGB::Black;
             leds[1526] = CRGB::Black;
             leds[1529] = CRGB::Yellow;
             leds[1530] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==33){//17
             leds[1529] = CRGB::Black;
             leds[1530] = CRGB::Black;
             leds[1533] = CRGB::Yellow;
             leds[1534] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==35){//18
             leds[1533] = CRGB::Black;
             leds[1534] = CRGB::Black;
             leds[1537] = CRGB::Yellow;
             leds[1538] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==37){//19
             leds[1537] = CRGB::Black;
             leds[1538] = CRGB::Black;
             leds[1541] = CRGB::Yellow;
             leds[1542] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==39){//20
             leds[1541] = CRGB::Black;
             leds[1542] = CRGB::Black;
             leds[1545] = CRGB::Yellow;
             leds[1546] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==41){//21
             leds[1545] = CRGB::Black;
             leds[1546] = CRGB::Black;
             leds[1549] = CRGB::Yellow;
             leds[1550] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==43){//22
             leds[1549] = CRGB::Black;
             leds[1550] = CRGB::Black;
             leds[1553] = CRGB::Yellow;
             leds[1554] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==45){//23
             leds[1553] = CRGB::Black;
             leds[1554] = CRGB::Black;
             leds[1557] = CRGB::Yellow;
             leds[1558] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==47){//24
             leds[1557] = CRGB::Black;
             leds[1558] = CRGB::Black;
             leds[1561] = CRGB::Yellow;
             leds[1562] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==49){//25
             leds[1561] = CRGB::Black;
             leds[1562] = CRGB::Black;
             leds[1565] = CRGB::Yellow;
             leds[1566] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
//===================================================     P4 in Layer2

if (P4T1 ==51){//26   
             leds[1565] = CRGB::Black;
             leds[1566] = CRGB::Black;
             leds[1665] = CRGB::Yellow;
             leds[1666] = CRGB::Yellow;
             FastLED.show();  
 P4T1++;
}
if (P4T1 ==53){//27
             leds[1665] = CRGB::Black;
             leds[1666] = CRGB::Black;
             leds[1661] = CRGB::Yellow;
             leds[1662] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
if (P4T1 ==55){//28
             leds[1661] = CRGB::Black;
             leds[1662] = CRGB::Black;
             leds[1657] = CRGB::Yellow;
             leds[1658] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
if (P4T1 ==57){//29
             leds[1657] = CRGB::Black;
             leds[1658] = CRGB::Black;
             leds[1653] = CRGB::Yellow;
             leds[1654] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
if (P4T1 ==59){//30
             leds[1653] = CRGB::Black;
             leds[1654] = CRGB::Black;
             leds[1649] = CRGB::Yellow;
             leds[1650] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==61){//31
             leds[1649] = CRGB::Black;
             leds[1650] = CRGB::Black;
             leds[1645] = CRGB::Yellow;
             leds[1646] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==63){//32
             leds[1645] = CRGB::Black;
             leds[1646] = CRGB::Black;
             leds[1641] = CRGB::Yellow;
             leds[1642] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==65){//33
             leds[1641] = CRGB::Black;
             leds[1642] = CRGB::Black;
             leds[1637] = CRGB::Yellow;
             leds[1638] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==67){//34
             leds[1637] = CRGB::Black;
             leds[1638] = CRGB::Black;
             leds[1633] = CRGB::Yellow;
             leds[1634] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==69){//35
             leds[1633] = CRGB::Black;
             leds[1634] = CRGB::Black;
             leds[1630] = CRGB::Yellow;
             leds[1629] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==71){//36
             leds[1629] = CRGB::Black;
             leds[1630] = CRGB::Black;
             leds[1625] = CRGB::Yellow;
             leds[1626] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==73){//37
             leds[1625] = CRGB::Black;
             leds[1626] = CRGB::Black;
             leds[1621] = CRGB::Yellow;
             leds[1622] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==75){//38
             leds[1621] = CRGB::Black;
             leds[1622] = CRGB::Black;
             leds[1617] = CRGB::Yellow;
             leds[1618] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==77){//39
             leds[1617] = CRGB::Black;
             leds[1618] = CRGB::Black;
             leds[1613] = CRGB::Yellow;
             leds[1614] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==79){//40
             leds[1613] = CRGB::Black;
             leds[1614] = CRGB::Black;
             leds[1609] = CRGB::Yellow;
             leds[1610] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==81){//41
             leds[1609] = CRGB::Black;
             leds[1610] = CRGB::Black;
             leds[1605] = CRGB::Yellow;
             leds[1606] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==83){//42
             leds[1605] = CRGB::Black;
             leds[1606] = CRGB::Black;
             leds[1601] = CRGB::Yellow;
             leds[1602] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==85){//43
             leds[1601] = CRGB::Black;
             leds[1602] = CRGB::Black;
             leds[1597] = CRGB::Yellow;
             leds[1598] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==87){//44
             leds[1597] = CRGB::Black;
             leds[1598] = CRGB::Black;
             leds[1593] = CRGB::Yellow;
             leds[1594] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==89){//45
             leds[1593] = CRGB::Black;
             leds[1594] = CRGB::Black;
             leds[1589] = CRGB::Yellow;
             leds[1590] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==91){//46
             leds[1589] = CRGB::Black;
             leds[1590] = CRGB::Black;
             leds[1585] = CRGB::Yellow;
             leds[1586] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==93){//47
             leds[1585] = CRGB::Black;
             leds[1586] = CRGB::Black;
             leds[1581] = CRGB::Yellow;
             leds[1582] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==95){//48
             leds[1581] = CRGB::Black;
             leds[1582] = CRGB::Black;
             leds[1577] = CRGB::Yellow;
             leds[1578] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==97){//49
             leds[1577] = CRGB::Black;
             leds[1578] = CRGB::Black;
             leds[1573] = CRGB::Yellow;
             leds[1574] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
if (P4T1 ==99){//50
             leds[1573] = CRGB::Black;
             leds[1574] = CRGB::Black;
             leds[1569] = CRGB::Yellow;
             leds[1570] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}

if (P4T1 == 101){//back to 1
if ((P1T2 > 999) && (P2T2 > 999) && (P3T2 > 999) && (P4T2 > 999))
{
  P4T2 = 1;
  P4T1 = 1; 
}
if((P1T2 < 999) || (P2T2 < 999) || (P3T2 < 999) || (P4T2 < 999))
{
  P4T1 = 1; 
}
}


//==========================================================================================================     start of tray 2 P4
if (P4T2 == 1000){
            for (int i = 1081; i < 1279;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P4T2++;
}

//===================================================     P4 in Layer3
if (P4T2 == 1){//1 LED
             leds[1081] = CRGB::Yellow;
             leds[1082] = CRGB::Yellow;
             leds[1181] = CRGB::Black;
             leds[1182] = CRGB::Black;
             FastLED.show();  
 P4T2++;
}
if (P4T2 == 3){//2
             leds[1081] = CRGB::Black;
             leds[1082] = CRGB::Black;
             leds[1085] = CRGB::Yellow;
             leds[1086] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
if (P4T2 == 5){//3
             leds[1085] = CRGB::Black;
             leds[1086] = CRGB::Black;
             leds[1089] = CRGB::Yellow;
             leds[1090] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
if (P4T2 == 7){//4
             leds[1089] = CRGB::Black;
             leds[1090] = CRGB::Black;
             leds[1093] = CRGB::Yellow;
             leds[1094] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
if (P4T2 == 9){//5
             leds[1093] = CRGB::Black;
             leds[1094] = CRGB::Black;
             leds[1097] = CRGB::Yellow;
             leds[1098] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==11){//6
             leds[1097] = CRGB::Black;
             leds[1098] = CRGB::Black;
             leds[1101] = CRGB::Yellow;
             leds[1102] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==13){//7
             leds[1101] = CRGB::Black;
             leds[1102] = CRGB::Black;
             leds[1105] = CRGB::Yellow;
             leds[1106] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==15){//8
             leds[1105] = CRGB::Black;
             leds[1106] = CRGB::Black;
             leds[1109] = CRGB::Yellow;
             leds[1110] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==17){//9
             leds[1109] = CRGB::Black;
             leds[1110] = CRGB::Black;
             leds[1113] = CRGB::Yellow;
             leds[1114] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==19){//10
             leds[1113] = CRGB::Black;
             leds[1114] = CRGB::Black;
             leds[1117] = CRGB::Yellow;
             leds[1118] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==21){//11
             leds[1117] = CRGB::Black;
             leds[1118] = CRGB::Black;
             leds[1121] = CRGB::Yellow;
             leds[1122] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==23){//12
             leds[1121] = CRGB::Black;
             leds[1122] = CRGB::Black;
             leds[1125] = CRGB::Yellow;
             leds[1126] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==25){//13
             leds[1125] = CRGB::Black;
             leds[1126] = CRGB::Black;
             leds[1129] = CRGB::Yellow;
             leds[1130] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==27){//14
             leds[1129] = CRGB::Black;
             leds[1130] = CRGB::Black;
             leds[1133] = CRGB::Yellow;
             leds[1134] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==29){//15
             leds[1133] = CRGB::Black;
             leds[1134] = CRGB::Black;
             leds[1137] = CRGB::Yellow;
             leds[1138] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==31){//16
             leds[1137] = CRGB::Black;
             leds[1138] = CRGB::Black;
             leds[1141] = CRGB::Yellow;
             leds[1142] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==33){//17
             leds[1141] = CRGB::Black;
             leds[1142] = CRGB::Black;
             leds[1145] = CRGB::Yellow;
             leds[1146] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==35){//18
             leds[1145] = CRGB::Black;
             leds[1146] = CRGB::Black;
             leds[1149] = CRGB::Yellow;
             leds[1150] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==37){//19
             leds[1149] = CRGB::Black;
             leds[1150] = CRGB::Black;
             leds[1153] = CRGB::Yellow;
             leds[1154] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==39){//20
             leds[1153] = CRGB::Black;
             leds[1154] = CRGB::Black;
             leds[1157] = CRGB::Yellow;
             leds[1158] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==41){//21
             leds[1157] = CRGB::Black;
             leds[1158] = CRGB::Black;
             leds[1161] = CRGB::Yellow;
             leds[1162] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==43){//22
             leds[1161] = CRGB::Black;
             leds[1162] = CRGB::Black;
             leds[1165] = CRGB::Yellow;
             leds[1166] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==45){//23
             leds[1165] = CRGB::Black;
             leds[1166] = CRGB::Black;
             leds[1169] = CRGB::Yellow;
             leds[1170] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==47){//24
             leds[1169] = CRGB::Black;
             leds[1170] = CRGB::Black;
             leds[1173] = CRGB::Yellow;
             leds[1174] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==49){//25
             leds[1173] = CRGB::Black;
             leds[1174] = CRGB::Black;
             leds[1177] = CRGB::Yellow;
             leds[1178] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
//===================================================     P4 in Layer4

if (P4T2 ==51){//26   
             leds[1177] = CRGB::Black;
             leds[1178] = CRGB::Black;
             leds[1277] = CRGB::Yellow;
             leds[1278] = CRGB::Yellow;
             FastLED.show();  
 P4T2++;
}
if (P4T2 ==53){//27
             leds[1277] = CRGB::Black;
             leds[1278] = CRGB::Black;
             leds[1273] = CRGB::Yellow;
             leds[1274] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
if (P4T2 ==55){//28
             leds[1273] = CRGB::Black;
             leds[1274] = CRGB::Black;
             leds[1269] = CRGB::Yellow;
             leds[1270] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
if (P4T2 ==57){//29
             leds[1269] = CRGB::Black;
             leds[1270] = CRGB::Black;
             leds[1265] = CRGB::Yellow;
             leds[1266] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
if (P4T2 ==59){//30
             leds[1265] = CRGB::Black;
             leds[1266] = CRGB::Black;
             leds[1261] = CRGB::Yellow;
             leds[1262] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==61){//31
             leds[1261] = CRGB::Black;
             leds[1262] = CRGB::Black;
             leds[1257] = CRGB::Yellow;
             leds[1258] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==63){//32
             leds[1257] = CRGB::Black;
             leds[1258] = CRGB::Black;
             leds[1253] = CRGB::Yellow;
             leds[1254] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==65){//33
             leds[1253] = CRGB::Black;
             leds[1254] = CRGB::Black;
             leds[1249] = CRGB::Yellow;
             leds[1250] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==67){//34
             leds[1249] = CRGB::Black;
             leds[1250] = CRGB::Black;
             leds[1245] = CRGB::Yellow;
             leds[1246] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==69){//35
             leds[1245] = CRGB::Black;
             leds[1246] = CRGB::Black;
             leds[1241] = CRGB::Yellow;
             leds[1242] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==71){//36
             leds[1241] = CRGB::Black;
             leds[1242] = CRGB::Black;
             leds[1237] = CRGB::Yellow;
             leds[1238] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==73){//37
             leds[1237] = CRGB::Black;
             leds[1238] = CRGB::Black;
             leds[1233] = CRGB::Yellow;
             leds[1234] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==75){//38
             leds[1233] = CRGB::Black;
             leds[1234] = CRGB::Black;
             leds[1229] = CRGB::Yellow;
             leds[1230] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==77){//39
             leds[1229] = CRGB::Black;
             leds[1230] = CRGB::Black;
             leds[1225] = CRGB::Yellow;
             leds[1226] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==79){//40
             leds[1225] = CRGB::Black;
             leds[1226] = CRGB::Black;
             leds[1221] = CRGB::Yellow;
             leds[1222] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==81){//41
             leds[1221] = CRGB::Black;
             leds[1222] = CRGB::Black;
             leds[1217] = CRGB::Yellow;
             leds[1218] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==83){//42
             leds[1217] = CRGB::Black;
             leds[1218] = CRGB::Black;
             leds[1213] = CRGB::Yellow;
             leds[1214] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==85){//43
             leds[1213] = CRGB::Black;
             leds[1214] = CRGB::Black;
             leds[1209] = CRGB::Yellow;
             leds[1210] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==87){//44
             leds[1209] = CRGB::Black;
             leds[1210] = CRGB::Black;
             leds[1205] = CRGB::Yellow;
             leds[1206] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==89){//45
             leds[1205] = CRGB::Black;
             leds[1206] = CRGB::Black;
             leds[1201] = CRGB::Yellow;
             leds[1202] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==91){//46
             leds[1201] = CRGB::Black;
             leds[1202] = CRGB::Black;
             leds[1197] = CRGB::Yellow;
             leds[1198] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==93){//47
             leds[1197] = CRGB::Black;
             leds[1198] = CRGB::Black;
             leds[1193] = CRGB::Yellow;
             leds[1194] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
if (P4T2 ==95){//48
             leds[1193] = CRGB::Black;
             leds[1194] = CRGB::Black;
             leds[1189] = CRGB::Yellow;
             leds[1190] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}

if (P4T2 == 97){//back to 1
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

if (P4T3 == 1000){
          for (int i = 681; i < 879;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P4T3++;
}

//===================================================     P4 in Layer3
if (P4T3 == 1){//1
             leds[813] = CRGB::Black;
             leds[814] = CRGB::Black;
             leds[681] = CRGB::Yellow;
             leds[682] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
if (P4T3 == 3){//2
             leds[681] = CRGB::Black;
             leds[682] = CRGB::Black;
             leds[685] = CRGB::Yellow;
             leds[686] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
if (P4T3 == 5){//3
             leds[685] = CRGB::Black;
             leds[686] = CRGB::Black;
             leds[689] = CRGB::Yellow;
             leds[690] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
if (P4T3 == 7){//4
             leds[689] = CRGB::Black;
             leds[690] = CRGB::Black;
             leds[693] = CRGB::Yellow;
             leds[694] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
if (P4T3 == 9){//5
             leds[693] = CRGB::Black;
             leds[694] = CRGB::Black;
             leds[697] = CRGB::Yellow;
             leds[698] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==11){//6
             leds[697] = CRGB::Black;
             leds[698] = CRGB::Black;
             leds[701] = CRGB::Yellow;
             leds[702] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==13){//7
             leds[701] = CRGB::Black;
             leds[702] = CRGB::Black;
             leds[705] = CRGB::Yellow;
             leds[706] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==15){//8
             leds[705] = CRGB::Black;
             leds[706] = CRGB::Black;
             leds[709] = CRGB::Yellow;
             leds[710] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==17){//9
             leds[709] = CRGB::Black;
             leds[710] = CRGB::Black;
             leds[713] = CRGB::Yellow;
             leds[714] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==19){//10
             leds[713] = CRGB::Black;
             leds[714] = CRGB::Black;
             leds[717] = CRGB::Yellow;
             leds[718] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==21){//11
             leds[717] = CRGB::Black;
             leds[718] = CRGB::Black;
             leds[721] = CRGB::Yellow;
             leds[722] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==23){//12
             leds[721] = CRGB::Black;
             leds[722] = CRGB::Black;
             leds[725] = CRGB::Yellow;
             leds[726] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==25){//13
             leds[725] = CRGB::Black;
             leds[726] = CRGB::Black;
             leds[729] = CRGB::Yellow;
             leds[730] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==27){//14
             leds[729] = CRGB::Black;
             leds[730] = CRGB::Black;
             leds[733] = CRGB::Yellow;
             leds[734] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==29){//15
             leds[733] = CRGB::Black;
             leds[734] = CRGB::Black;
             leds[737] = CRGB::Yellow;
             leds[738] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==31){//16
             leds[737] = CRGB::Black;
             leds[738] = CRGB::Black;
             leds[741] = CRGB::Yellow;
             leds[742] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==33){//17
             leds[741] = CRGB::Black;
             leds[742] = CRGB::Black;
             leds[745] = CRGB::Yellow;
             leds[746] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==35){//18
             leds[745] = CRGB::Black;
             leds[746] = CRGB::Black;
             leds[749] = CRGB::Yellow;
             leds[750] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==37){//19
             leds[749] = CRGB::Black;
             leds[750] = CRGB::Black;
             leds[753] = CRGB::Yellow;
             leds[754] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}

if (P4T3 ==39){//20
             leds[753] = CRGB::Black;
             leds[754] = CRGB::Black;
             leds[757] = CRGB::Yellow;
             leds[758] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}

if (P4T3 ==41){//21
             leds[757] = CRGB::Black;
             leds[758] = CRGB::Black;
             leds[761] = CRGB::Yellow;
             leds[762] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}

if (P4T3 ==43){//22
             leds[761] = CRGB::Black;
             leds[762] = CRGB::Black;
             leds[765] = CRGB::Yellow;
             leds[766] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}

if (P4T3 ==45){//23
             leds[765] = CRGB::Black;
             leds[766] = CRGB::Black;
             leds[769] = CRGB::Yellow;
             leds[770] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}

if (P4T3 ==47){//24
             leds[769] = CRGB::Black;
             leds[770] = CRGB::Black;
             leds[773] = CRGB::Yellow;
             leds[774] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}


//===================================================     P4 in Layer4

if (P4T3 ==49){//26LED
             leds[878] = CRGB::Yellow;
             leds[877] = CRGB::Yellow;
             leds[773] = CRGB::Black;
             leds[774] = CRGB::Black;
             FastLED.show();  
 P4T3++;
}
if (P4T3 ==51){//27
             leds[877] = CRGB::Black;
             leds[878] = CRGB::Black;
             leds[873] = CRGB::Yellow;
             leds[874] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
if (P4T3 ==53){//28
             leds[873] = CRGB::Black;
             leds[874] = CRGB::Black;
             leds[869] = CRGB::Yellow;
             leds[870] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
if (P4T3 ==55){//29
             leds[869] = CRGB::Black;
             leds[870] = CRGB::Black;
             leds[865] = CRGB::Yellow;
             leds[866] = CRGB::Yellow;
             FastLED.show();
 P4T3++;
}
if (P4T3 ==57){//30
             leds[865] = CRGB::Black;
             leds[866] = CRGB::Black;
             leds[861] = CRGB::Yellow;
             leds[862] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==59){//31
             leds[861] = CRGB::Black;
             leds[862] = CRGB::Black;
             leds[857] = CRGB::Yellow;
             leds[858] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==61){//32
             leds[857] = CRGB::Black;
             leds[858] = CRGB::Black;
             leds[853] = CRGB::Yellow;
             leds[854] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==63){//33
             leds[853] = CRGB::Black;
             leds[854] = CRGB::Black;
             leds[849] = CRGB::Yellow;
             leds[850] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==65){//34
             leds[849] = CRGB::Black;
             leds[850] = CRGB::Black;
             leds[845] = CRGB::Yellow;
             leds[846] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==67){//35
             leds[845] = CRGB::Black;
             leds[846] = CRGB::Black;
             leds[841] = CRGB::Yellow;
             leds[842] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==69){//36
             leds[841] = CRGB::Black;
             leds[842] = CRGB::Black;
             leds[837] = CRGB::Yellow;
             leds[838] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==71){//37
             leds[837] = CRGB::Black;
             leds[838] = CRGB::Black;
             leds[833] = CRGB::Yellow;
             leds[834] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==73){//38
             leds[833] = CRGB::Black;
             leds[834] = CRGB::Black;
             leds[829] = CRGB::Yellow;
             leds[830] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==75){//39
             leds[829] = CRGB::Black;
             leds[830] = CRGB::Black;
             leds[825] = CRGB::Yellow;
             leds[826] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==77){//40
             leds[825] = CRGB::Black;
             leds[826] = CRGB::Black;
             leds[821] = CRGB::Yellow;
             leds[822] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==79){//41
             leds[821] = CRGB::Black;
             leds[822] = CRGB::Black;
             leds[817] = CRGB::Yellow;
             leds[818] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}
if (P4T3 ==81){//42
             leds[817] = CRGB::Black;
             leds[818] = CRGB::Black;
             leds[813] = CRGB::Yellow;
             leds[814] = CRGB::Yellow;
             FastLED.show();
   
 P4T3++;
}

if (P4T3 == 83){//back to 1
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
if (P4T4 == 1000){
for (int i = 241; i < 351;i++)
            {
               leds[i] = CRGB::Black;  
            } FastLED.show();  
            
 P4T4++;
}

//===================================================     P4 in Layer3
if (P4T4 == 1){//1 LED
             leds[242] = CRGB::Yellow;
             leds[241] = CRGB::Yellow;
             leds[349] = CRGB::Black;
             leds[350] = CRGB::Black;
             FastLED.show();  
 P4T4++;
}
if (P4T4 == 3){//2
             leds[242] = CRGB::Black;
             leds[241] = CRGB::Black;
             leds[246] = CRGB::Yellow;
             leds[245] = CRGB::Yellow;
             FastLED.show();
 P4T4++;
}
if (P4T4 == 5){//3
             leds[246] = CRGB::Black;
             leds[245] = CRGB::Black;
             leds[250] = CRGB::Yellow;
             leds[249] = CRGB::Yellow;
             FastLED.show();
 P4T4++;
}
if (P4T4 == 7){//4
             leds[249] = CRGB::Black;
             leds[250] = CRGB::Black;
             leds[254] = CRGB::Yellow;
             leds[253] = CRGB::Yellow;
             FastLED.show();
 P4T4++;
}
if (P4T4 == 9){//5
             leds[254] = CRGB::Black;
             leds[253] = CRGB::Black;
             leds[258] = CRGB::Yellow;
             leds[257] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==11){//6
             leds[257] = CRGB::Black;
             leds[258] = CRGB::Black;
             leds[262] = CRGB::Yellow;
             leds[261] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==13){//7
             leds[261] = CRGB::Black;
             leds[262] = CRGB::Black;
             leds[265] = CRGB::Yellow;
             leds[266] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==15){//8
             leds[265] = CRGB::Black;
             leds[266] = CRGB::Black;
             leds[269] = CRGB::Yellow;
             leds[270] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==17){//9
             leds[269] = CRGB::Black;
             leds[270] = CRGB::Black;
             leds[274] = CRGB::Yellow;
             leds[273] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==19){//10
             leds[274] = CRGB::Black;
             leds[273] = CRGB::Black;
             leds[278] = CRGB::Yellow;
             leds[277] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 == 21){//11
             leds[278] = CRGB::Black;
             leds[277] = CRGB::Black;
             leds[282] = CRGB::Yellow;
             leds[281] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==23){//12
             leds[282] = CRGB::Black;
             leds[281] = CRGB::Black;
             leds[286] = CRGB::Yellow;
             leds[285] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==25){//13
             leds[286] = CRGB::Black;
             leds[285] = CRGB::Black;
             leds[289] = CRGB::Yellow;
             leds[290] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==27){//14
             leds[290] = CRGB::Black;
             leds[289] = CRGB::Black;
             leds[294] = CRGB::Yellow;
             leds[293] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==29){//15
             leds[294] = CRGB::Black;
             leds[293] = CRGB::Black;
             leds[298] = CRGB::Yellow;
             leds[297] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==31){//16
             leds[298] = CRGB::Black;
             leds[297] = CRGB::Black;
             leds[302] = CRGB::Yellow;
             leds[301] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==33){//17
             leds[302] = CRGB::Black;
             leds[301] = CRGB::Black;
             leds[306] = CRGB::Yellow;
             leds[305] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==35){//18
             leds[305] = CRGB::Black;
             leds[306] = CRGB::Black;
             leds[309] = CRGB::Yellow;
             leds[310] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==37){//19
             leds[309] = CRGB::Black;
             leds[310] = CRGB::Black;
             leds[313] = CRGB::Yellow;
             leds[314] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==39){//20
             leds[313] = CRGB::Black;
             leds[314] = CRGB::Black;
             leds[317] = CRGB::Yellow;
             leds[318] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==41){//21
             leds[317] = CRGB::Black;
             leds[318] = CRGB::Black;
             leds[321] = CRGB::Yellow;
             leds[322] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==43){//22
             leds[321] = CRGB::Black;
             leds[322] = CRGB::Black;
             leds[325] = CRGB::Yellow;
             leds[326] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==45){//23
             leds[325] = CRGB::Black;
             leds[326] = CRGB::Black;
             leds[329] = CRGB::Yellow;
             leds[330] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==47){//24
             leds[329] = CRGB::Black;
             leds[330] = CRGB::Black;
             leds[333] = CRGB::Yellow;
             leds[334] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==49){//25
             leds[333] = CRGB::Black;
             leds[334] = CRGB::Black;
             leds[337] = CRGB::Yellow;
             leds[338] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==51){//26
             leds[337] = CRGB::Black;
             leds[338] = CRGB::Black;
             leds[341] = CRGB::Yellow;
             leds[342] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==53){//27
             leds[341] = CRGB::Black;
             leds[342] = CRGB::Black;
             leds[345] = CRGB::Yellow;
             leds[346] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}
if (P4T4 ==55){//28
             leds[345] = CRGB::Black;
             leds[346] = CRGB::Black;
             leds[349] = CRGB::Yellow;
             leds[350] = CRGB::Yellow;
             FastLED.show();
   
 P4T4++;
}

if (P4T4 == 57){//back to 1

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
Serial.println("Product1");
  P1T1 = 1;
  P2T1 = 1000;
  P3T1 = 1000;
  P4T1 = 1000;
  delay(100);
 }
if (P2 == HIGH)
  {
Serial.println("Product2");
  P1T1 = 1000;
  P2T1 = 1;
  P3T1 = 1000;
  P4T1 = 1000;
  delay(100);
  }
if (P3 == HIGH)
  {
Serial.println("Product3");
  P1T1 = 1000;
  P2T1 = 1000;
  P3T1 = 1;
  P4T1 = 1000;
  delay(100);
  }
if (P4 == HIGH)
  {
Serial.println("Product4");
  P1T1 = 1000;
  P2T1 = 1000;
  P3T1 = 1000;
  P4T1 = 1;
  delay(100);
  }



  ex:;
}

