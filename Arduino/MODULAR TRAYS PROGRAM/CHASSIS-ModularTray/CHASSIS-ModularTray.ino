//loc 26 p4t3 change color din
#include "FastLED.h"

#define NUM_LEDS 1600            //heto ang bilang ng LED
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

if (P1T1 == 1000){                                   // to clear P1 in tray 1
            for (int i = 1271; i < 1468;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P1T1++;
}
//===================================================     P1 in Layer1
else if (P1T1 == 1){//1 LED
             leds[1271] = CRGB::Blue;
             leds[1272] = CRGB::Blue;
             leds[1371] = CRGB::Black;
             leds[1372] = CRGB::Black;
             FastLED.show();  
 P1T1++;
}
else if (P1T1 == 3){//2
             leds[1271] = CRGB::Black;
             leds[1272] = CRGB::Black;
             leds[1275] = CRGB::Blue;
             leds[1276] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
else if (P1T1 == 5){//3
             leds[1275] = CRGB::Black;
             leds[1276] = CRGB::Black;
             leds[1279] = CRGB::Blue;
             leds[1280] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
else if (P1T1 == 7){//4
             leds[1279] = CRGB::Black;
             leds[1280] = CRGB::Black;
             leds[1283] = CRGB::Blue;
             leds[1284] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
else if (P1T1 == 9){//5
             leds[1283] = CRGB::Black;
             leds[1284] = CRGB::Black;
             leds[1287] = CRGB::Blue;
             leds[1288] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==11){//6
             leds[1287] = CRGB::Black;
             leds[1288] = CRGB::Black;
             leds[1291] = CRGB::Blue;
             leds[1292] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==13){//7
             leds[1291] = CRGB::Black;
             leds[1292] = CRGB::Black;
             leds[1295] = CRGB::Blue;
             leds[1296] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==15){//8
             leds[1295] = CRGB::Black;
             leds[1296] = CRGB::Black;
             leds[1299] = CRGB::Blue;
             leds[1300] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==17){//9
             leds[1299] = CRGB::Black;
             leds[1300] = CRGB::Black;
             leds[1303] = CRGB::Blue;
             leds[1304] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==19){//10
             leds[1303] = CRGB::Black;
             leds[1304] = CRGB::Black;
             leds[1307] = CRGB::Blue;
             leds[1308] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==21){//11
             leds[1307] = CRGB::Black;
             leds[1308] = CRGB::Black;
             leds[1311] = CRGB::Blue;
             leds[1312] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==23){//12
             leds[1311] = CRGB::Black;
             leds[1312] = CRGB::Black;
             leds[1315] = CRGB::Blue;
             leds[1316] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==25){//13
             leds[1315] = CRGB::Black;
             leds[1316] = CRGB::Black;
             leds[1319] = CRGB::Blue;
             leds[1320] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==27){//14
             leds[1319] = CRGB::Black;
             leds[1320] = CRGB::Black;
             leds[1323] = CRGB::Blue;
             leds[1324] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==29){//15
             leds[1323] = CRGB::Black;
             leds[1324] = CRGB::Black;
             leds[1327] = CRGB::Blue;
             leds[1328] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==31){//16
             leds[1327] = CRGB::Black;
             leds[1328] = CRGB::Black;
             leds[1331] = CRGB::Blue;
             leds[1332] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==33){//17
             leds[1331] = CRGB::Black;
             leds[1332] = CRGB::Black;
             leds[1335] = CRGB::Blue;
             leds[1336] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==35){//18
             leds[1335] = CRGB::Black;
             leds[1336] = CRGB::Black;
             leds[1339] = CRGB::Blue;
             leds[1340] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==37){//19
             leds[1339] = CRGB::Black;
             leds[1340] = CRGB::Black;
             leds[1343] = CRGB::Blue;
             leds[1344] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==39){//20
             leds[1343] = CRGB::Black;
             leds[1344] = CRGB::Black;
             leds[1347] = CRGB::Blue;
             leds[1348] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==41){//21
             leds[1347] = CRGB::Black;
             leds[1348] = CRGB::Black;
             leds[1351] = CRGB::Blue;
             leds[1352] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==43){//22
             leds[1351] = CRGB::Black;
             leds[1352] = CRGB::Black;
             leds[1355] = CRGB::Blue;
             leds[1356] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==45){//23
             leds[1355] = CRGB::Black;
             leds[1356] = CRGB::Black;
             leds[1359] = CRGB::Blue;
             leds[1360] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==47){//24
             leds[1359] = CRGB::Black;
             leds[1360] = CRGB::Black;
             leds[1363] = CRGB::Blue;
             leds[1364] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==49){//25
             leds[1363] = CRGB::Black;
             leds[1364] = CRGB::Black;
             leds[1367] = CRGB::Blue;
             leds[1368] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
//===================================================     P1 in Layer2

else if (P1T1 ==51){//26   
             leds[1367] = CRGB::Black;
             leds[1368] = CRGB::Black;
             leds[1467] = CRGB::Blue;
             leds[1468] = CRGB::Blue;
             FastLED.show();  
 P1T1++;
}
else if (P1T1 ==53){//27
             leds[1467] = CRGB::Black;
             leds[1468] = CRGB::Black;
             leds[1463] = CRGB::Blue;
             leds[1464] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
else if (P1T1 ==55){//28
             leds[1463] = CRGB::Black;
             leds[1464] = CRGB::Black;
             leds[1459] = CRGB::Blue;
             leds[1460] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
else if (P1T1 ==57){//29
             leds[1459] = CRGB::Black;
             leds[1460] = CRGB::Black;
             leds[1455] = CRGB::Blue;
             leds[1456] = CRGB::Blue;
             FastLED.show();
 P1T1++;
}
else if (P1T1 ==59){//30
             leds[1455] = CRGB::Black;
             leds[1456] = CRGB::Black;
             leds[1451] = CRGB::Blue;
             leds[1452] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==61){//31
             leds[1451] = CRGB::Black;
             leds[1452] = CRGB::Black;
             leds[1447] = CRGB::Blue;
             leds[1448] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==63){//32
             leds[1447] = CRGB::Black;
             leds[1448] = CRGB::Black;
             leds[1443] = CRGB::Blue;
             leds[1444] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==65){//33
             leds[1443] = CRGB::Black;
             leds[1444] = CRGB::Black;
             leds[1439] = CRGB::Blue;
             leds[1440] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==67){//34
             leds[1439] = CRGB::Black;
             leds[1440] = CRGB::Black;
             leds[1435] = CRGB::Blue;
             leds[1436] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==69){//35
             leds[1435] = CRGB::Black;
             leds[1436] = CRGB::Black;
             leds[1431] = CRGB::Blue;
             leds[1432] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==71){//36
             leds[1431] = CRGB::Black;
             leds[1432] = CRGB::Black;
             leds[1427] = CRGB::Blue;
             leds[1428] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==73){//37
             leds[1427] = CRGB::Black;
             leds[1428] = CRGB::Black;
             leds[1423] = CRGB::Blue;
             leds[1424] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==75){//38
             leds[1423] = CRGB::Black;
             leds[1424] = CRGB::Black;
             leds[1419] = CRGB::Blue;
             leds[1420] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==77){//39
             leds[1419] = CRGB::Black;
             leds[1420] = CRGB::Black;
             leds[1415] = CRGB::Blue;
             leds[1416] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==79){//40
             leds[1415] = CRGB::Black;
             leds[1416] = CRGB::Black;
             leds[1411] = CRGB::Blue;
             leds[1412] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==81){//41
             leds[1411] = CRGB::Black;
             leds[1412] = CRGB::Black;
             leds[1407] = CRGB::Blue;
             leds[1408] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==83){//42
             leds[1407] = CRGB::Black;
             leds[1408] = CRGB::Black;
             leds[1403] = CRGB::Blue;
             leds[1404] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==85){//43
             leds[1403] = CRGB::Black;
             leds[1404] = CRGB::Black;
             leds[1399] = CRGB::Blue;
             leds[1400] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==87){//44
             leds[1399] = CRGB::Black;
             leds[1400] = CRGB::Black;
             leds[1395] = CRGB::Blue;
             leds[1396] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==89){//45
             leds[1395] = CRGB::Black;
             leds[1396] = CRGB::Black;
             leds[1391] = CRGB::Blue;
             leds[1392] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==91){//46
             leds[1391] = CRGB::Black;
             leds[1392] = CRGB::Black;
             leds[1387] = CRGB::Blue;
             leds[1388] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==93){//47
             leds[1387] = CRGB::Black;
             leds[1388] = CRGB::Black;
             leds[1383] = CRGB::Blue;
             leds[1384] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==95){//48
             leds[1383] = CRGB::Black;
             leds[1384] = CRGB::Black;
             leds[1379] = CRGB::Blue;
             leds[1380] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==97){//49
             leds[1379] = CRGB::Black;
             leds[1380] = CRGB::Black;
             leds[1375] = CRGB::Blue;
             leds[1376] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}
else if (P1T1 ==99){//50
             leds[1375] = CRGB::Black;
             leds[1376] = CRGB::Black;
             leds[1371] = CRGB::Blue;
             leds[1372] = CRGB::Blue;
             FastLED.show();
   
 P1T1++;
}

else if (P1T1 ==101){//back to 1 of P1 tray 1
if ((P1T2 > 999) && (P2T2 > 999) && (P3T2 > 999) && (P4T2 > 999))// IF TRAY 2 HAS NO VALUE FROM ANY PRODUCT
{
  P1T2 = 1; //TURN ON P1 ON TRAY 2
  P1T1 = 1; //P1 BACK TO 1 IN TRAY 1
}
else if((P1T2 < 999) || (P2T2 < 999) || (P3T2 < 999) || (P3T2 < 999))//IF TRAY 2 HAS A VALUE FROM ANY PRODUCT
{
  P1T1 = 1; //P1 BACK TO 1 IN TRAY 1
}
}


//==========================================================================================================     start of tray 2 P1

//===================================================     P1 in Layer1
else if (P1T2 == 1000){
             for (int x = 876; x < 1072;x++)
            {
               leds[x] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P1T2++;
}
else if (P1T2 == 1){//1 LED
             leds[876] = CRGB::Blue;
             leds[877] = CRGB::Blue;
             leds[974] = CRGB::Black;
             leds[975] = CRGB::Black;
             FastLED.show();  
 P1T2++;
}
else if (P1T2 == 3){//2
             leds[876] = CRGB::Black;
             leds[877] = CRGB::Black;
             leds[880] = CRGB::Blue;
             leds[881] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
else if (P1T2 == 5){//3
             leds[880] = CRGB::Black;
             leds[881] = CRGB::Black;
             leds[884] = CRGB::Blue;
             leds[885] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
else if (P1T2 == 7){//4
             leds[884] = CRGB::Black;
             leds[885] = CRGB::Black;
             leds[888] = CRGB::Blue;
             leds[889] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
else if (P1T2 == 9){//5
             leds[888] = CRGB::Black;
             leds[889] = CRGB::Black;
             leds[892] = CRGB::Blue;
             leds[893] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==11){//6
             leds[892] = CRGB::Black;
             leds[893] = CRGB::Black;
             leds[896] = CRGB::Blue;
             leds[897] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==13){//7
             leds[896] = CRGB::Black;
             leds[897] = CRGB::Black;
             leds[900] = CRGB::Blue;
             leds[901] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==15){//8
             leds[900] = CRGB::Black;
             leds[901] = CRGB::Black;
             leds[904] = CRGB::Blue;
             leds[905] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==17){//9
             leds[904] = CRGB::Black;
             leds[905] = CRGB::Black;
             leds[908] = CRGB::Blue;
             leds[909] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==19){//10
             leds[908] = CRGB::Black;
             leds[909] = CRGB::Black;
             leds[912] = CRGB::Blue;
             leds[913] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 == 21){//11
             leds[912] = CRGB::Black;
             leds[913] = CRGB::Black;
             leds[916] = CRGB::Blue;
             leds[917] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==23){//12
             leds[916] = CRGB::Black;
             leds[917] = CRGB::Black;
             leds[920] = CRGB::Blue;
             leds[921] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==25){//13
             leds[920] = CRGB::Black;
             leds[921] = CRGB::Black;
             leds[924] = CRGB::Blue;
             leds[925] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==27){//14
             leds[924] = CRGB::Black;
             leds[925] = CRGB::Black;
             leds[928] = CRGB::Blue;
             leds[929] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==29){//15
             leds[928] = CRGB::Black;
             leds[929] = CRGB::Black;
             leds[932] = CRGB::Blue;
             leds[933] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==31){//16
             leds[932] = CRGB::Black;
             leds[933] = CRGB::Black;
             leds[936] = CRGB::Blue;
             leds[937] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==33){//17
             leds[936] = CRGB::Black;
             leds[937] = CRGB::Black;
             leds[940] = CRGB::Blue;
             leds[941] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==35){//18
             leds[940] = CRGB::Black;
             leds[941] = CRGB::Black;
             leds[944] = CRGB::Blue;
             leds[945] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==37){//19
             leds[944] = CRGB::Black;
             leds[945] = CRGB::Black;
             leds[948] = CRGB::Blue;
             leds[949] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==39){//20
             leds[948] = CRGB::Black;
             leds[949] = CRGB::Black;
             leds[952] = CRGB::Blue;
             leds[953] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==41){//21
             leds[952] = CRGB::Black;
             leds[953] = CRGB::Black;
             leds[956] = CRGB::Blue;
             leds[957] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==43){//22
             leds[956] = CRGB::Black;
             leds[957] = CRGB::Black;
             leds[960] = CRGB::Blue;
             leds[961] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==45){//23
             leds[960] = CRGB::Black;
             leds[961] = CRGB::Black;
             leds[964] = CRGB::Blue;
             leds[965] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==47){//24
             leds[964] = CRGB::Black;
             leds[965] = CRGB::Black;
             leds[968] = CRGB::Blue;
             leds[969] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==49){//25
             leds[968] = CRGB::Black;
             leds[969] = CRGB::Black;
             leds[972] = CRGB::Blue;
             leds[973] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}

//===================================================     P1 in Layer2

else if (P1T2 ==51){//26LED
             leds[1070] = CRGB::Blue;
             leds[1071] = CRGB::Blue;
             leds[972] = CRGB::Black;
             leds[973] = CRGB::Black;
             FastLED.show();  
 P1T2++;
}
else if (P1T2 ==53){//27
             leds[1070] = CRGB::Black;
             leds[1071] = CRGB::Black;
             leds[1066] = CRGB::Blue;
             leds[1067] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
else if (P1T2 ==55){//28
             leds[1066] = CRGB::Black;
             leds[1067] = CRGB::Black;
             leds[1062] = CRGB::Blue;
             leds[1063] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
else if (P1T2 ==57){//29
             leds[1062] = CRGB::Black;
             leds[1063] = CRGB::Black;
             leds[1058] = CRGB::Blue;
             leds[1059] = CRGB::Blue;
             FastLED.show();
 P1T2++;
}
else if (P1T2 ==59){//30
             leds[1058] = CRGB::Black;
             leds[1059] = CRGB::Black;
             leds[1054] = CRGB::Blue;
             leds[1055] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==61){//31
             leds[1054] = CRGB::Black;
             leds[1055] = CRGB::Black;
             leds[1050] = CRGB::Blue;
             leds[1051] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==63){//32
             leds[1050] = CRGB::Black;
             leds[1051] = CRGB::Black;
             leds[1046] = CRGB::Blue;
             leds[1047] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==65){//33
             leds[1046] = CRGB::Black;
             leds[1047] = CRGB::Black;
             leds[1042] = CRGB::Blue;
             leds[1043] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==67){//34
             leds[1042] = CRGB::Black;
             leds[1043] = CRGB::Black;
             leds[1038] = CRGB::Blue;
             leds[1039] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==69){//35
             leds[1038] = CRGB::Black;
             leds[1039] = CRGB::Black;
             leds[1034] = CRGB::Blue;
             leds[1035] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 == 71){//36
             leds[1034] = CRGB::Black;
             leds[1035] = CRGB::Black;
             leds[1030] = CRGB::Blue;
             leds[1031] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==73){//37
             leds[1030] = CRGB::Black;
             leds[1031] = CRGB::Black;
             leds[1026] = CRGB::Blue;
             leds[1027] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==75){//38
             leds[1026] = CRGB::Black;
             leds[1027] = CRGB::Black;
             leds[1022] = CRGB::Blue;
             leds[1023] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==77){//39
             leds[1022] = CRGB::Black;
             leds[1023] = CRGB::Black;
             leds[1018] = CRGB::Blue;
             leds[1019] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==79){//40
             leds[1018] = CRGB::Black;
             leds[1019] = CRGB::Black;
             leds[1014] = CRGB::Blue;
             leds[1015] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==81){//41
             leds[1014] = CRGB::Black;
             leds[1015] = CRGB::Black;
             leds[1010] = CRGB::Blue;
             leds[1011] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==83){//42
             leds[1010] = CRGB::Black;
             leds[1011] = CRGB::Black;
             leds[1006] = CRGB::Blue;
             leds[1007] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==85){//43
             leds[1006] = CRGB::Black;
             leds[1007] = CRGB::Black;
             leds[1002] = CRGB::Blue;
             leds[1003] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==87){//44
             leds[1002] = CRGB::Black;
             leds[1003] = CRGB::Black;
             leds[998] = CRGB::Blue;
             leds[999] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==89){//45
             leds[998] = CRGB::Black;
             leds[999] = CRGB::Black;
             leds[994] = CRGB::Blue;
             leds[995] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==91){//46
             leds[994] = CRGB::Black;
             leds[995] = CRGB::Black;
             leds[990] = CRGB::Blue;
             leds[991] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==93){//47
             leds[990] = CRGB::Black;
             leds[991] = CRGB::Black;
             leds[986] = CRGB::Blue;
             leds[987] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==95){//48
             leds[986] = CRGB::Black;
             leds[987] = CRGB::Black;
             leds[982] = CRGB::Blue;
             leds[983] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==97){//49
             leds[982] = CRGB::Black;
             leds[983] = CRGB::Black;
             leds[978] = CRGB::Blue;
             leds[979] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}
else if (P1T2 ==99){//50
             leds[978] = CRGB::Black;
             leds[979] = CRGB::Black;
             leds[974] = CRGB::Blue;
             leds[975] = CRGB::Blue;
             FastLED.show();
   
 P1T2++;
}

else if (P1T2 ==101){//back to 1
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
else if (P1T3 == 1000){
            for (int i = 480; i < 677;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P1T3++;
}

else if (P1T3 == 1){//1 LED
             leds[480] = CRGB::Blue;
             leds[481] = CRGB::Blue;
             leds[579] = CRGB::Black;
             leds[580] = CRGB::Black;
             FastLED.show();  
 P1T3++;
}
else if (P1T3 == 3){//2
             leds[480] = CRGB::Black;
             leds[481] = CRGB::Black;
             leds[484] = CRGB::Blue;
             leds[485] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
else if (P1T3 == 5){//3
             leds[484] = CRGB::Black;
             leds[485] = CRGB::Black;
             leds[488] = CRGB::Blue;
             leds[489] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
else if (P1T3 == 7){//4
             leds[488] = CRGB::Black;
             leds[489] = CRGB::Black;
             leds[492] = CRGB::Blue;
             leds[493] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
else if (P1T3 == 9){//5
             leds[492] = CRGB::Black;
             leds[493] = CRGB::Black;
             leds[496] = CRGB::Blue;
             leds[497] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==11){//6
             leds[496] = CRGB::Black;
             leds[497] = CRGB::Black;
             leds[501] = CRGB::Blue;
             leds[502] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==13){//7
             leds[501] = CRGB::Black;
             leds[502] = CRGB::Black;
             leds[505] = CRGB::Blue;
             leds[506] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==15){//8
             leds[505] = CRGB::Black;
             leds[506] = CRGB::Black;
             leds[509] = CRGB::Blue;
             leds[510] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==17){//9
             leds[509] = CRGB::Black;
             leds[510] = CRGB::Black;
             leds[513] = CRGB::Blue;
             leds[514] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==19){//10
             leds[513] = CRGB::Black;
             leds[514] = CRGB::Black;
             leds[517] = CRGB::Blue;
             leds[518] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 == 21){//11
             leds[517] = CRGB::Black;
             leds[518] = CRGB::Black;
             leds[521] = CRGB::Blue;
             leds[522] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==23){//12
             leds[521] = CRGB::Black;
             leds[522] = CRGB::Black;
             leds[525] = CRGB::Blue;
             leds[526] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==25){//13
             leds[525] = CRGB::Black;
             leds[526] = CRGB::Black;
             leds[529] = CRGB::Blue;
             leds[530] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==27){//14
             leds[529] = CRGB::Black;
             leds[530] = CRGB::Black;
             leds[533] = CRGB::Blue;
             leds[534] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==29){//15
             leds[533] = CRGB::Black;
             leds[534] = CRGB::Black;
             leds[537] = CRGB::Blue;
             leds[538] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==31){//16
             leds[537] = CRGB::Black;
             leds[538] = CRGB::Black;
             leds[541] = CRGB::Blue;
             leds[542] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==33){//17
             leds[541] = CRGB::Black;
             leds[542] = CRGB::Black;
             leds[545] = CRGB::Blue;
             leds[546] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==35){//18
             leds[545] = CRGB::Black;
             leds[546] = CRGB::Black;
             leds[549] = CRGB::Blue;
             leds[550] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==37){//19
             leds[549] = CRGB::Black;
             leds[550] = CRGB::Black;
             leds[553] = CRGB::Blue;
             leds[554] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==39){//20
             leds[553] = CRGB::Black;
             leds[554] = CRGB::Black;
             leds[557] = CRGB::Blue;
             leds[558] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==41){//21
             leds[557] = CRGB::Black;
             leds[558] = CRGB::Black;
             leds[561] = CRGB::Blue;
             leds[562] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==43){//22
             leds[561] = CRGB::Black;
             leds[562] = CRGB::Black;
             leds[565] = CRGB::Blue;
             leds[566] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==45){//23
             leds[565] = CRGB::Black;
             leds[566] = CRGB::Black;
             leds[569] = CRGB::Blue;
             leds[570] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==47){//24
             leds[569] = CRGB::Black;
             leds[570] = CRGB::Black;
             leds[573] = CRGB::Blue;
             leds[574] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==49){//25
             leds[573] = CRGB::Black;
             leds[574] = CRGB::Black;
             leds[577] = CRGB::Blue;
             leds[578] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}

//===================================================     P1 in Layer2

else if (P1T3 ==51){//26LED
             leds[676] = CRGB::Blue;
             leds[677] = CRGB::Blue;
             leds[577] = CRGB::Black;
             leds[578] = CRGB::Black;
             FastLED.show();  
 P1T3++;
}
else if (P1T3 ==53){//27
             leds[676] = CRGB::Black;
             leds[677] = CRGB::Black;
             leds[672] = CRGB::Blue;
             leds[673] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
else if (P1T3 ==55){//28
             leds[672] = CRGB::Black;
             leds[673] = CRGB::Black;
             leds[668] = CRGB::Blue;
             leds[669] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
else if (P1T3 ==57){//29
             leds[668] = CRGB::Black;
             leds[669] = CRGB::Black;
             leds[664] = CRGB::Blue;
             leds[665] = CRGB::Blue;
             FastLED.show();
 P1T3++;
}
else if (P1T3 ==59){//30
             leds[664] = CRGB::Black;
             leds[665] = CRGB::Black;
             leds[659] = CRGB::Blue;
             leds[660] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==61){//31
             leds[659] = CRGB::Black;
             leds[660] = CRGB::Black;
             leds[655] = CRGB::Blue;
             leds[656] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==63){//32
             leds[655] = CRGB::Black;
             leds[656] = CRGB::Black;
             leds[651] = CRGB::Blue;
             leds[652] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==65){//33
             leds[651] = CRGB::Black;
             leds[652] = CRGB::Black;
             leds[647] = CRGB::Blue;
             leds[648] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==67){//34
             leds[647] = CRGB::Black;
             leds[648] = CRGB::Black;
             leds[643] = CRGB::Blue;
             leds[644] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==69){//35
             leds[643] = CRGB::Black;
             leds[644] = CRGB::Black;
             leds[639] = CRGB::Blue;
             leds[640] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 == 71){//36
             leds[639] = CRGB::Black;
             leds[640] = CRGB::Black;
             leds[635] = CRGB::Blue;
             leds[636] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==73){//37
             leds[635] = CRGB::Black;
             leds[636] = CRGB::Black;
             leds[631] = CRGB::Blue;
             leds[632] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==75){//38
             leds[631] = CRGB::Black;
             leds[632] = CRGB::Black;
             leds[627] = CRGB::Blue;
             leds[628] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==77){//39
             leds[627] = CRGB::Black;
             leds[628] = CRGB::Black;
             leds[623] = CRGB::Blue;
             leds[624] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==79){//40
             leds[623] = CRGB::Black;
             leds[624] = CRGB::Black;
             leds[619] = CRGB::Blue;
             leds[620] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==81){//41
             leds[619] = CRGB::Black;
             leds[620] = CRGB::Black;
             leds[615] = CRGB::Blue;
             leds[616] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==83){//42
             leds[615] = CRGB::Black;
             leds[616] = CRGB::Black;
             leds[611] = CRGB::Blue;
             leds[612] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==85){//43
             leds[611] = CRGB::Black;
             leds[612] = CRGB::Black;
             leds[607] = CRGB::Blue;
             leds[608] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==87){//44
             leds[607] = CRGB::Black;
             leds[608] = CRGB::Black;
             leds[603] = CRGB::Blue;
             leds[604] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==89){//45
             leds[603] = CRGB::Black;
             leds[604] = CRGB::Black;
             leds[599] = CRGB::Blue;
             leds[600] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==91){//46
             leds[599] = CRGB::Black;
             leds[600] = CRGB::Black;
             leds[595] = CRGB::Blue;
             leds[596] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==93){//47
             leds[595] = CRGB::Black;
             leds[596] = CRGB::Black;
             leds[591] = CRGB::Blue;
             leds[592] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==95){//48
             leds[591] = CRGB::Black;
             leds[592] = CRGB::Black;
             leds[587] = CRGB::Blue;
             leds[588] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==97){//49
             leds[587] = CRGB::Black;
             leds[588] = CRGB::Black;
             leds[583] = CRGB::Blue;
             leds[584] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}
else if (P1T3 ==99){//50
             leds[583] = CRGB::Black;
             leds[584] = CRGB::Black;
             leds[579] = CRGB::Blue;
             leds[580] = CRGB::Blue;
             FastLED.show();
   
 P1T3++;
}

else if (P1T3 == 101){//back to 1
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
for (int i = 1; i < 118;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P1T4++;
}


//===================================================     P1 in Layer1
else if (P1T4 == 1){//1 LED
             leds[1] = CRGB::Blue;
             leds[2] = CRGB::Blue;
             leds[116] = CRGB::Black;
             leds[117] = CRGB::Black;
             FastLED.show();  
 P1T4++;
}
else if (P1T4 == 3){//2
             leds[1] = CRGB::Black;
             leds[2] = CRGB::Black;
             leds[5] = CRGB::Blue;
             leds[6] = CRGB::Blue;
             FastLED.show();
 P1T4++;
}
else if (P1T4 == 5){//3
             leds[5] = CRGB::Black;
             leds[6] = CRGB::Black;
             leds[9] = CRGB::Blue;
             leds[10] = CRGB::Blue;
             FastLED.show();
 P1T4++;
}
else if (P1T4 == 7){//4
             leds[9] = CRGB::Black;
             leds[10] = CRGB::Black;
             leds[13] = CRGB::Blue;
             leds[14] = CRGB::Blue;
             FastLED.show();
 P1T4++;
}
else if (P1T4 == 9){//5
             leds[13] = CRGB::Black;
             leds[14] = CRGB::Black;
             leds[17] = CRGB::Blue;
             leds[18] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==11){//6
             leds[17] = CRGB::Black;
             leds[18] = CRGB::Black;
             leds[21] = CRGB::Blue;
             leds[22] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==13){//7
             leds[21] = CRGB::Black;
             leds[22] = CRGB::Black;
             leds[25] = CRGB::Blue;
             leds[26] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==15){//8
             leds[25] = CRGB::Black;
             leds[26] = CRGB::Black;
             leds[29] = CRGB::Blue;
             leds[30] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==17){//9
             leds[29] = CRGB::Black;
             leds[30] = CRGB::Black;
             leds[33] = CRGB::Blue;
             leds[34] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==19){//10
             leds[33] = CRGB::Black;
             leds[34] = CRGB::Black;
             leds[37] = CRGB::Blue;
             leds[38] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 == 21){//11
             leds[37] = CRGB::Black;
             leds[38] = CRGB::Black;
             leds[41] = CRGB::Blue;
             leds[42] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==23){//12
             leds[41] = CRGB::Black;
             leds[42] = CRGB::Black;
             leds[45] = CRGB::Blue;
             leds[46] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==25){//13
             leds[45] = CRGB::Black;
             leds[46] = CRGB::Black;
             leds[49] = CRGB::Blue;
             leds[50] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==27){//14
             leds[49] = CRGB::Black;
             leds[50] = CRGB::Black;
             leds[53] = CRGB::Blue;
             leds[54] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==29){//15
             leds[53] = CRGB::Black;
             leds[54] = CRGB::Black;
             leds[57] = CRGB::Blue;
             leds[58] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==31){//16
             leds[57] = CRGB::Black;
             leds[58] = CRGB::Black;
             leds[61] = CRGB::Blue;
             leds[62] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==33){//17
             leds[61] = CRGB::Black;
             leds[62] = CRGB::Black;
             leds[65] = CRGB::Blue;
             leds[66] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==35){//18
             leds[65] = CRGB::Black;
             leds[66] = CRGB::Black;
             leds[69] = CRGB::Blue;
             leds[70] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==37){//19
             leds[69] = CRGB::Black;
             leds[70] = CRGB::Black;
             leds[73] = CRGB::Blue;
             leds[74] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==39){//20
             leds[73] = CRGB::Black;
             leds[74] = CRGB::Black;
             leds[77] = CRGB::Blue;
             leds[78] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==41){//21
             leds[77] = CRGB::Black;
             leds[78] = CRGB::Black;
             leds[81] = CRGB::Blue;
             leds[82] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==43){//22
             leds[81] = CRGB::Black;
             leds[82] = CRGB::Black;
             leds[85] = CRGB::Blue;
             leds[86] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==45){//23
             leds[85] = CRGB::Black;
             leds[86] = CRGB::Black;
             leds[89] = CRGB::Blue;
             leds[90] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==47){//24
             leds[89] = CRGB::Black;
             leds[90] = CRGB::Black;
             leds[93] = CRGB::Blue;
             leds[94] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==49){//25
             leds[93] = CRGB::Black;
             leds[94] = CRGB::Black;
             leds[97] = CRGB::Blue;
             leds[98] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==51){//26
             leds[97] = CRGB::Black;
             leds[98] = CRGB::Black;
             leds[100] = CRGB::Blue;
             leds[101] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==53){//27
             leds[100] = CRGB::Black;
             leds[101] = CRGB::Black;
             leds[104] = CRGB::Blue;
             leds[105] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==55){//28
             leds[104] = CRGB::Black;
             leds[105] = CRGB::Black;
             leds[108] = CRGB::Blue;
             leds[109] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==57){//29
             leds[108] = CRGB::Black;
             leds[109] = CRGB::Black;
             leds[112] = CRGB::Blue;
             leds[113] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}
else if (P1T4 ==59){//30
             leds[112] = CRGB::Black;
             leds[113] = CRGB::Black;
             leds[116] = CRGB::Blue;
             leds[117] = CRGB::Blue;
             FastLED.show();
   
 P1T4++;
}


else if (P1T4 == 61){//back to 1

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
        for (int i = 1469; i < 1667;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P2T1++;
}

//===================================================     P2 in Layer1
else if (P2T1 == 1){//1 LED
             leds[1469] = CRGB::Red;
             leds[1470] = CRGB::Red;
             leds[1569] = CRGB::Black;
             leds[1570] = CRGB::Black;
             FastLED.show();  
 P2T1++;
}
else if (P2T1 == 3){//2
             leds[1469] = CRGB::Black;
             leds[1470] = CRGB::Black;
             leds[1473] = CRGB::Red;
             leds[1474] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
else if (P2T1 == 5){//3
             leds[1473] = CRGB::Black;
             leds[1474] = CRGB::Black;
             leds[1477] = CRGB::Red;
             leds[1478] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
else if (P2T1 == 7){//4
             leds[1477] = CRGB::Black;
             leds[1478] = CRGB::Black;
             leds[1481] = CRGB::Red;
             leds[1482] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
else if (P2T1 == 9){//5
             leds[1481] = CRGB::Black;
             leds[1482] = CRGB::Black;
             leds[1485] = CRGB::Red;
             leds[1486] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==11){//6
             leds[1485] = CRGB::Black;
             leds[1486] = CRGB::Black;
             leds[1489] = CRGB::Red;
             leds[1490] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==13){//7
             leds[1489] = CRGB::Black;
             leds[1490] = CRGB::Black;
             leds[1493] = CRGB::Red;
             leds[1494] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==15){//8
             leds[1493] = CRGB::Black;
             leds[1494] = CRGB::Black;
             leds[1497] = CRGB::Red;
             leds[1498] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==17){//9
             leds[1497] = CRGB::Black;
             leds[1498] = CRGB::Black;
             leds[1501] = CRGB::Red;
             leds[1502] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==19){//10
             leds[1501] = CRGB::Black;
             leds[1502] = CRGB::Black;
             leds[1505] = CRGB::Red;
             leds[1506] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==21){//11
             leds[1505] = CRGB::Black;
             leds[1506] = CRGB::Black;
             leds[1509] = CRGB::Red;
             leds[1510] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==23){//12
             leds[1509] = CRGB::Black;
             leds[1510] = CRGB::Black;
             leds[1513] = CRGB::Red;
             leds[1514] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==25){//13
             leds[1513] = CRGB::Black;
             leds[1514] = CRGB::Black;
             leds[1517] = CRGB::Red;
             leds[1518] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==27){//14
             leds[1517] = CRGB::Black;
             leds[1518] = CRGB::Black;
             leds[1521] = CRGB::Red;
             leds[1522] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==29){//15
             leds[1521] = CRGB::Black;
             leds[1522] = CRGB::Black;
             leds[1525] = CRGB::Red;
             leds[1526] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==31){//16
             leds[1525] = CRGB::Black;
             leds[1526] = CRGB::Black;
             leds[1529] = CRGB::Red;
             leds[1530] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==33){//17
             leds[1529] = CRGB::Black;
             leds[1530] = CRGB::Black;
             leds[1533] = CRGB::Red;
             leds[1534] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==35){//18
             leds[1533] = CRGB::Black;
             leds[1534] = CRGB::Black;
             leds[1537] = CRGB::Red;
             leds[1538] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==37){//19
             leds[1537] = CRGB::Black;
             leds[1538] = CRGB::Black;
             leds[1541] = CRGB::Red;
             leds[1542] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==39){//20
             leds[1541] = CRGB::Black;
             leds[1542] = CRGB::Black;
             leds[1545] = CRGB::Red;
             leds[1546] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==41){//21
             leds[1545] = CRGB::Black;
             leds[1546] = CRGB::Black;
             leds[1549] = CRGB::Red;
             leds[1550] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==43){//22
             leds[1549] = CRGB::Black;
             leds[1550] = CRGB::Black;
             leds[1553] = CRGB::Red;
             leds[1554] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==45){//23
             leds[1553] = CRGB::Black;
             leds[1554] = CRGB::Black;
             leds[1557] = CRGB::Red;
             leds[1558] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==47){//24
             leds[1557] = CRGB::Black;
             leds[1558] = CRGB::Black;
             leds[1561] = CRGB::Red;
             leds[1562] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==49){//25
             leds[1561] = CRGB::Black;
             leds[1562] = CRGB::Black;
             leds[1565] = CRGB::Red;
             leds[1566] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
//===================================================     P2 in Layer2

else if (P2T1 ==51){//26   
             leds[1565] = CRGB::Black;
             leds[1566] = CRGB::Black;
             leds[1665] = CRGB::Red;
             leds[1666] = CRGB::Red;
             FastLED.show();  
 P2T1++;
}
else if (P2T1 ==53){//27
             leds[1665] = CRGB::Black;
             leds[1666] = CRGB::Black;
             leds[1661] = CRGB::Red;
             leds[1662] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
else if (P2T1 ==55){//28
             leds[1661] = CRGB::Black;
             leds[1662] = CRGB::Black;
             leds[1657] = CRGB::Red;
             leds[1658] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
else if (P2T1 ==57){//29
             leds[1657] = CRGB::Black;
             leds[1658] = CRGB::Black;
             leds[1653] = CRGB::Red;
             leds[1654] = CRGB::Red;
             FastLED.show();
 P2T1++;
}
else if (P2T1 ==59){//30
             leds[1653] = CRGB::Black;
             leds[1654] = CRGB::Black;
             leds[1649] = CRGB::Red;
             leds[1650] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==61){//31
             leds[1649] = CRGB::Black;
             leds[1650] = CRGB::Black;
             leds[1645] = CRGB::Red;
             leds[1646] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==63){//32
             leds[1645] = CRGB::Black;
             leds[1646] = CRGB::Black;
             leds[1641] = CRGB::Red;
             leds[1642] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==65){//33
             leds[1641] = CRGB::Black;
             leds[1642] = CRGB::Black;
             leds[1637] = CRGB::Red;
             leds[1638] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==67){//34
             leds[1637] = CRGB::Black;
             leds[1638] = CRGB::Black;
             leds[1633] = CRGB::Red;
             leds[1634] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==69){//35
             leds[1633] = CRGB::Black;
             leds[1634] = CRGB::Black;
             leds[1630] = CRGB::Red;
             leds[1629] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==71){//36
             leds[1629] = CRGB::Black;
             leds[1630] = CRGB::Black;
             leds[1625] = CRGB::Red;
             leds[1626] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==73){//37
             leds[1625] = CRGB::Black;
             leds[1626] = CRGB::Black;
             leds[1621] = CRGB::Red;
             leds[1622] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==75){//38
             leds[1621] = CRGB::Black;
             leds[1622] = CRGB::Black;
             leds[1617] = CRGB::Red;
             leds[1618] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==77){//39
             leds[1617] = CRGB::Black;
             leds[1618] = CRGB::Black;
             leds[1613] = CRGB::Red;
             leds[1614] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==79){//40
             leds[1613] = CRGB::Black;
             leds[1614] = CRGB::Black;
             leds[1609] = CRGB::Red;
             leds[1610] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==81){//41
             leds[1609] = CRGB::Black;
             leds[1610] = CRGB::Black;
             leds[1605] = CRGB::Red;
             leds[1606] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==83){//42
             leds[1605] = CRGB::Black;
             leds[1606] = CRGB::Black;
             leds[1601] = CRGB::Red;
             leds[1602] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==85){//43
             leds[1601] = CRGB::Black;
             leds[1602] = CRGB::Black;
             leds[1597] = CRGB::Red;
             leds[1598] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==87){//44
             leds[1597] = CRGB::Black;
             leds[1598] = CRGB::Black;
             leds[1593] = CRGB::Red;
             leds[1594] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==89){//45
             leds[1593] = CRGB::Black;
             leds[1594] = CRGB::Black;
             leds[1589] = CRGB::Red;
             leds[1590] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==91){//46
             leds[1589] = CRGB::Black;
             leds[1590] = CRGB::Black;
             leds[1585] = CRGB::Red;
             leds[1586] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==93){//47
             leds[1585] = CRGB::Black;
             leds[1586] = CRGB::Black;
             leds[1581] = CRGB::Red;
             leds[1582] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==95){//48
             leds[1581] = CRGB::Black;
             leds[1582] = CRGB::Black;
             leds[1577] = CRGB::Red;
             leds[1578] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==97){//49
             leds[1577] = CRGB::Black;
             leds[1578] = CRGB::Black;
             leds[1573] = CRGB::Red;
             leds[1574] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}
else if (P2T1 ==99){//50
             leds[1573] = CRGB::Black;
             leds[1574] = CRGB::Black;
             leds[1569] = CRGB::Red;
             leds[1570] = CRGB::Red;
             FastLED.show();
   
 P2T1++;
}

else if (P2T1 == 101){//back to 1
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
            for (int i = 1074; i < 1270;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P2T2++;
}

//===================================================     P2 in Layer1
else if (P2T2 == 1){//1 LED
             leds[1074] = CRGB::Red;
             leds[1075] = CRGB::Red;
             leds[1172] = CRGB::Black;
             leds[1173] = CRGB::Black;
             FastLED.show();  
 P2T2++;
}
else if (P2T2 == 3){//2
             leds[1074] = CRGB::Black;
             leds[1075] = CRGB::Black;
             leds[1078] = CRGB::Red;
             leds[1079] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
else if (P2T2 == 5){//3
             leds[1078] = CRGB::Black;
             leds[1079] = CRGB::Black;
             leds[1082] = CRGB::Red;
             leds[1083] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
else if (P2T2 == 7){//4
             leds[1082] = CRGB::Black;
             leds[1083] = CRGB::Black;
             leds[1086] = CRGB::Red;
             leds[1087] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
else if (P2T2 == 9){//5
             leds[1086] = CRGB::Black;
             leds[1087] = CRGB::Black;
             leds[1090] = CRGB::Red;
             leds[1091] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==11){//6
             leds[1090] = CRGB::Black;
             leds[1091] = CRGB::Black;
             leds[1094] = CRGB::Red;
             leds[1095] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==13){//7
             leds[1094] = CRGB::Black;
             leds[1095] = CRGB::Black;
             leds[1098] = CRGB::Red;
             leds[1099] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==15){//8
             leds[1098] = CRGB::Black;
             leds[1099] = CRGB::Black;
             leds[1102] = CRGB::Red;
             leds[1103] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==17){//9
             leds[1102] = CRGB::Black;
             leds[1103] = CRGB::Black;
             leds[1106] = CRGB::Red;
             leds[1107] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==19){//10
             leds[1106] = CRGB::Black;
             leds[1107] = CRGB::Black;
             leds[1110] = CRGB::Red;
             leds[1111] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==21){//11
             leds[1110] = CRGB::Black;
             leds[1111] = CRGB::Black;
             leds[1114] = CRGB::Red;
             leds[1115] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==23){//12
             leds[1114] = CRGB::Black;
             leds[1115] = CRGB::Black;
             leds[1118] = CRGB::Red;
             leds[1119] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==25){//13
             leds[1118] = CRGB::Black;
             leds[1119] = CRGB::Black;
             leds[1122] = CRGB::Red;
             leds[1123] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==27){//14
             leds[1122] = CRGB::Black;
             leds[1123] = CRGB::Black;
             leds[1126] = CRGB::Red;
             leds[1127] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==29){//15
             leds[1126] = CRGB::Black;
             leds[1127] = CRGB::Black;
             leds[1130] = CRGB::Red;
             leds[1131] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==31){//16
             leds[1130] = CRGB::Black;
             leds[1131] = CRGB::Black;
             leds[1134] = CRGB::Red;
             leds[1135] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==33){//17
             leds[1134] = CRGB::Black;
             leds[1135] = CRGB::Black;
             leds[1138] = CRGB::Red;
             leds[1139] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==35){//18
             leds[1138] = CRGB::Black;
             leds[1139] = CRGB::Black;
             leds[1142] = CRGB::Red;
             leds[1143] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==37){//19
             leds[1142] = CRGB::Black;
             leds[1143] = CRGB::Black;
             leds[1146] = CRGB::Red;
             leds[1147] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==39){//20
             leds[1146] = CRGB::Black;
             leds[1147] = CRGB::Black;
             leds[1150] = CRGB::Red;
             leds[1151] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==41){//21
             leds[1150] = CRGB::Black;
             leds[1151] = CRGB::Black;
             leds[1154] = CRGB::Red;
             leds[1155] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==43){//22
             leds[1154] = CRGB::Black;
             leds[1155] = CRGB::Black;
             leds[1158] = CRGB::Red;
             leds[1159] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
//===================================================     P2 in Layer2

else if (P2T2 ==45){//26   
             leds[1158] = CRGB::Black;
             leds[1159] = CRGB::Black;
             leds[1268] = CRGB::Red;
             leds[1269] = CRGB::Red;
             FastLED.show();  
 P2T2++;
}
else if (P2T2 ==47){//27
             leds[1268] = CRGB::Black;
             leds[1269] = CRGB::Black;
             leds[1264] = CRGB::Red;
             leds[1265] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
else if (P2T2 ==49){//28
             leds[1264] = CRGB::Black;
             leds[1265] = CRGB::Black;
             leds[1260] = CRGB::Red;
             leds[1261] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
else if (P2T2 ==51){//29
             leds[1260] = CRGB::Black;
             leds[1261] = CRGB::Black;
             leds[1256] = CRGB::Red;
             leds[1257] = CRGB::Red;
             FastLED.show();
 P2T2++;
}
else if (P2T2 ==53){//30
             leds[1256] = CRGB::Black;
             leds[1257] = CRGB::Black;
             leds[1252] = CRGB::Red;
             leds[1253] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==55){//31
             leds[1252] = CRGB::Black;
             leds[1253] = CRGB::Black;
             leds[1248] = CRGB::Red;
             leds[1249] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==57){//32
             leds[1248] = CRGB::Black;
             leds[1249] = CRGB::Black;
             leds[1244] = CRGB::Red;
             leds[1245] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==59){//33
             leds[1244] = CRGB::Black;
             leds[1245] = CRGB::Black;
             leds[1240] = CRGB::Red;
             leds[1241] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==61){//34
             leds[1240] = CRGB::Black;
             leds[1241] = CRGB::Black;
             leds[1236] = CRGB::Red;
             leds[1237] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==63){//35
             leds[1236] = CRGB::Black;
             leds[1237] = CRGB::Black;
             leds[1232] = CRGB::Red;
             leds[1233] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==65){//36
             leds[1232] = CRGB::Black;
             leds[1233] = CRGB::Black;
             leds[1228] = CRGB::Red;
             leds[1229] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==67){//37
             leds[1228] = CRGB::Black;
             leds[1229] = CRGB::Black;
             leds[1224] = CRGB::Red;
             leds[1225] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==69){//38
             leds[1224] = CRGB::Black;
             leds[1225] = CRGB::Black;
             leds[1220] = CRGB::Red;
             leds[1221] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==71){//39
             leds[1220] = CRGB::Black;
             leds[1221] = CRGB::Black;
             leds[1216] = CRGB::Red;
             leds[1217] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==73){//40
             leds[1216] = CRGB::Black;
             leds[1217] = CRGB::Black;
             leds[1212] = CRGB::Red;
             leds[1213] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==75){//41
             leds[1212] = CRGB::Black;
             leds[1213] = CRGB::Black;
             leds[1208] = CRGB::Red;
             leds[1209] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==77){//42
             leds[1208] = CRGB::Black;
             leds[1209] = CRGB::Black;
             leds[1204] = CRGB::Red;
             leds[1205] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==79){//43
             leds[1204] = CRGB::Black;
             leds[1205] = CRGB::Black;
             leds[1200] = CRGB::Red;
             leds[1201] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==81){//44
             leds[1200] = CRGB::Black;
             leds[1201] = CRGB::Black;
             leds[1196] = CRGB::Red;
             leds[1197] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==83){//45
             leds[1196] = CRGB::Black;
             leds[1197] = CRGB::Black;
             leds[1192] = CRGB::Red;
             leds[1193] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==85){//46
             leds[1192] = CRGB::Black;
             leds[1193] = CRGB::Black;
             leds[1188] = CRGB::Red;
             leds[1189] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==87){//47
             leds[1188] = CRGB::Black;
             leds[1189] = CRGB::Black;
             leds[1184] = CRGB::Red;
             leds[1185] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==89){//48
             leds[1184] = CRGB::Black;
             leds[1185] = CRGB::Black;
             leds[1180] = CRGB::Red;
             leds[1181] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==91){//49
             leds[1180] = CRGB::Black;
             leds[1181] = CRGB::Black;
             leds[1176] = CRGB::Red;
             leds[1177] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}
else if (P2T2 ==93){//50
             leds[1176] = CRGB::Black;
             leds[1177] = CRGB::Black;
             leds[1172] = CRGB::Red;
             leds[1173] = CRGB::Red;
             FastLED.show();
   
 P2T2++;
}

else if (P2T2 == 95){//back to 1
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
          for (int i = 678; i < 875;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P2T3++;
}

//===================================================     P2 in Layer1

else if (P2T3 == 1){//2
             leds[777] = CRGB::Black;
             leds[778] = CRGB::Black;
             leds[682] = CRGB::Red;
             leds[683] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
else if (P2T3 == 3){//3
             leds[682] = CRGB::Black;
             leds[683] = CRGB::Black;
             leds[686] = CRGB::Red;
             leds[687] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
else if (P2T3 == 5){//4
             leds[686] = CRGB::Black;
             leds[687] = CRGB::Black;
             leds[690] = CRGB::Red;
             leds[691] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
else if (P2T3 == 7){//5
             leds[690] = CRGB::Black;
             leds[691] = CRGB::Black;
             leds[694] = CRGB::Red;
             leds[695] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 == 9){//7
             leds[694] = CRGB::Black;
             leds[695] = CRGB::Black;
             leds[702] = CRGB::Red;
             leds[703] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==11){//10
             leds[702] = CRGB::Black;
             leds[703] = CRGB::Black;
             leds[714] = CRGB::Red;
             leds[715] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==13){//13
             leds[714] = CRGB::Black;
             leds[715] = CRGB::Black;
             leds[726] = CRGB::Red;
             leds[727] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==15){//14
             leds[726] = CRGB::Black;
             leds[727] = CRGB::Black;
             leds[730] = CRGB::Red;
             leds[731] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==17){//15
             leds[730] = CRGB::Black;
             leds[731] = CRGB::Black;
             leds[734] = CRGB::Red;
             leds[735] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==19){//16
             leds[734] = CRGB::Black;
             leds[735] = CRGB::Black;
             leds[738] = CRGB::Red;
             leds[739] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==21){//17
             leds[738] = CRGB::Black;
             leds[739] = CRGB::Black;
             leds[742] = CRGB::Red;
             leds[743] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==23){//18
             leds[742] = CRGB::Black;
             leds[743] = CRGB::Black;
             leds[746] = CRGB::Red;
             leds[747] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==25){//19
             leds[746] = CRGB::Black;
             leds[747] = CRGB::Black;
             leds[750] = CRGB::Red;
             leds[751] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

//===================================================     P2 in Layer2

else if (P2T3 ==27){//26LED
             leds[873] = CRGB::Red;
             leds[874] = CRGB::Red;
             leds[750] = CRGB::Black;
             leds[751] = CRGB::Black;
             FastLED.show();  
 P2T3++;
}
else if (P2T3 ==29){//27
             leds[873] = CRGB::Black;
             leds[874] = CRGB::Black;
             leds[869] = CRGB::Red;
             leds[870] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
else if (P2T3 ==31){//28
             leds[869] = CRGB::Black;
             leds[870] = CRGB::Black;
             leds[865] = CRGB::Red;
             leds[866] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
else if (P2T3 ==33){//29
             leds[865] = CRGB::Black;
             leds[866] = CRGB::Black;
             leds[861] = CRGB::Red;
             leds[862] = CRGB::Red;
             FastLED.show();
 P2T3++;
}
else if (P2T3 ==35){//30
             leds[861] = CRGB::Black;
             leds[862] = CRGB::Black;
             leds[857] = CRGB::Red;
             leds[858] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==37){//31
             leds[857] = CRGB::Black;
             leds[858] = CRGB::Black;
             leds[853] = CRGB::Red;
             leds[854] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==39){//32
             leds[853] = CRGB::Black;
             leds[854] = CRGB::Black;
             leds[849] = CRGB::Red;
             leds[850] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==41){//33
             leds[849] = CRGB::Black;
             leds[850] = CRGB::Black;
             leds[845] = CRGB::Red;
             leds[846] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==43){//34
             leds[845] = CRGB::Black;
             leds[846] = CRGB::Black;
             leds[841] = CRGB::Red;
             leds[842] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==45){//35
             leds[841] = CRGB::Black;
             leds[842] = CRGB::Black;
             leds[837] = CRGB::Red;
             leds[838] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==47){//36
             leds[837] = CRGB::Black;
             leds[838] = CRGB::Black;
             leds[833] = CRGB::Red;
             leds[834] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==49){//37
             leds[833] = CRGB::Black;
             leds[834] = CRGB::Black;
             leds[829] = CRGB::Red;
             leds[830] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==51){//38
             leds[829] = CRGB::Black;
             leds[830] = CRGB::Black;
             leds[825] = CRGB::Red;
             leds[826] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==53){//39
             leds[825] = CRGB::Black;
             leds[826] = CRGB::Black;
             leds[821] = CRGB::Red;
             leds[822] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==55){//40
             leds[821] = CRGB::Black;
             leds[822] = CRGB::Black;
             leds[817] = CRGB::Red;
             leds[818] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==57){//41
             leds[817] = CRGB::Black;
             leds[818] = CRGB::Black;
             leds[813] = CRGB::Red;
             leds[814] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}
else if (P2T3 ==59){//42
             leds[813] = CRGB::Black;
             leds[814] = CRGB::Black;
             leds[809] = CRGB::Red;
             leds[810] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

else if (P2T3 ==61){//43
             leds[809] = CRGB::Black;
             leds[810] = CRGB::Black;
             leds[805] = CRGB::Red;
             leds[806] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

else if (P2T3 ==63){//44
             leds[805] = CRGB::Black;
             leds[806] = CRGB::Black;
             leds[801] = CRGB::Red;
             leds[802] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

else if (P2T3 ==65){//45
             leds[801] = CRGB::Black;
             leds[802] = CRGB::Black;
             leds[797] = CRGB::Red;
             leds[798] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

else if (P2T3 ==67){//46
             leds[797] = CRGB::Black;
             leds[798] = CRGB::Black;
             leds[793] = CRGB::Red;
             leds[794] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

else if (P2T3 ==69){//47
             leds[793] = CRGB::Black;
             leds[794] = CRGB::Black;
             leds[789] = CRGB::Red;
             leds[790] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

else if (P2T3 ==71){//48
             leds[789] = CRGB::Black;
             leds[790] = CRGB::Black;
             leds[785] = CRGB::Red;
             leds[786] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

else if (P2T3 ==73){//49
             leds[785] = CRGB::Black;
             leds[786] = CRGB::Black;
             leds[781] = CRGB::Red;
             leds[782] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}

else if (P2T3 ==75){//50
             leds[781] = CRGB::Black;
             leds[782] = CRGB::Black;
             leds[777] = CRGB::Red;
             leds[778] = CRGB::Red;
             FastLED.show();
   
 P2T3++;
}



else if (P2T3 == 77){//back to 1
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
             for (int i = 380; i < 478;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P2T4++;
}


//===================================================     P2 in Layer4
else if (P2T4 == 1){//1 LED
             leds[476] = CRGB::Red;
             leds[477] = CRGB::Red;
             leds[380] = CRGB::Black;
             leds[381] = CRGB::Black;
             FastLED.show();  
 P2T4++;
}
else if (P2T4 == 3){//2
             leds[476] = CRGB::Black;
             leds[477] = CRGB::Black;
             leds[472] = CRGB::Red;
             leds[473] = CRGB::Red;
             FastLED.show();
 P2T4++;
}
else if (P2T4 == 5){//3
             leds[472] = CRGB::Black;
             leds[473] = CRGB::Black;
             leds[468] = CRGB::Red;
             leds[469] = CRGB::Red;
             FastLED.show();
 P2T4++;
}
else if (P2T4 == 7){//4
             leds[468] = CRGB::Black;
             leds[469] = CRGB::Black;
             leds[464] = CRGB::Red;
             leds[465] = CRGB::Red;
             FastLED.show();
 P2T4++;
}
else if (P2T4 == 9){//5
             leds[465] = CRGB::Black;
             leds[464] = CRGB::Black;
             leds[460] = CRGB::Red;
             leds[461] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==11){//6
             leds[460] = CRGB::Black;
             leds[461] = CRGB::Black;
             leds[456] = CRGB::Red;
             leds[457] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==13){//7
             leds[456] = CRGB::Black;
             leds[457] = CRGB::Black;
             leds[452] = CRGB::Red;
             leds[453] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==15){//8
             leds[452] = CRGB::Black;
             leds[453] = CRGB::Black;
             leds[448] = CRGB::Red;
             leds[449] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==17){//9
             leds[448] = CRGB::Black;
             leds[449] = CRGB::Black;
             leds[444] = CRGB::Red;
             leds[445] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==19){//10
             leds[444] = CRGB::Black;
             leds[445] = CRGB::Black;
             leds[440] = CRGB::Red;
             leds[441] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==21){//11
             leds[440] = CRGB::Black;
             leds[441] = CRGB::Black;
             leds[436] = CRGB::Red;
             leds[437] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==23){//12
             leds[436] = CRGB::Black;
             leds[437] = CRGB::Black;
             leds[433] = CRGB::Red;
             leds[432] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==25){//13
             leds[433] = CRGB::Black;
             leds[432] = CRGB::Black;
             leds[428] = CRGB::Red;
             leds[429] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==27){//14
             leds[428] = CRGB::Black;
             leds[429] = CRGB::Black;
             leds[424] = CRGB::Red;
             leds[425] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==29){//15
             leds[424] = CRGB::Black;
             leds[425] = CRGB::Black;
             leds[420] = CRGB::Red;
             leds[421] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==31){//16
             leds[420] = CRGB::Black;
             leds[421] = CRGB::Black;
             leds[416] = CRGB::Red;
             leds[417] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==33){//17
             leds[416] = CRGB::Black;
             leds[417] = CRGB::Black;
             leds[412] = CRGB::Red;
             leds[413] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==35){//18
             leds[412] = CRGB::Black;
             leds[413] = CRGB::Black;
             leds[408] = CRGB::Red;
             leds[409] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==37){//19
             leds[408] = CRGB::Black;
             leds[409] = CRGB::Black;
             leds[404] = CRGB::Red;
             leds[405] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==39){//20
             leds[404] = CRGB::Black;
             leds[405] = CRGB::Black;
             leds[400] = CRGB::Red;
             leds[401] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==41){//21
             leds[400] = CRGB::Black;
             leds[401] = CRGB::Black;
             leds[396] = CRGB::Red;
             leds[397] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==43){//22
             leds[396] = CRGB::Black;
             leds[397] = CRGB::Black;
             leds[392] = CRGB::Red;
             leds[393] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==45){//23
             leds[393] = CRGB::Black;
             leds[392] = CRGB::Black;
             leds[388] = CRGB::Red;
             leds[389] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==47){//24
             leds[388] = CRGB::Black;
             leds[389] = CRGB::Black;
             leds[384] = CRGB::Red;
             leds[385] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}
else if (P2T4 ==49){//25
             leds[384] = CRGB::Black;
             leds[385] = CRGB::Black;
             leds[380] = CRGB::Red;
             leds[381] = CRGB::Red;
             FastLED.show();
   
 P2T4++;
}

else if (P2T4 == 51){//back to 1
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
            for (int i = 1271; i < 1469;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P3T1++;
}

//===================================================     P3 in Layer1

else if (P3T1 == 1){//1 LED
             leds[1271] = CRGB::Green;
             leds[1272] = CRGB::Green;
             leds[1371] = CRGB::Black;
             leds[1372] = CRGB::Black;
             FastLED.show();  
 P3T1++;
}
else if (P3T1 == 3){//2
             leds[1271] = CRGB::Black;
             leds[1272] = CRGB::Black;
             leds[1275] = CRGB::Green;
             leds[1276] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
else if (P3T1 == 5){//3
             leds[1275] = CRGB::Black;
             leds[1276] = CRGB::Black;
             leds[1279] = CRGB::Green;
             leds[1280] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
else if (P3T1 == 7){//4
             leds[1279] = CRGB::Black;
             leds[1280] = CRGB::Black;
             leds[1283] = CRGB::Green;
             leds[1284] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
else if (P3T1 == 9){//5
             leds[1283] = CRGB::Black;
             leds[1284] = CRGB::Black;
             leds[1287] = CRGB::Green;
             leds[1288] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==11){//6
             leds[1287] = CRGB::Black;
             leds[1288] = CRGB::Black;
             leds[1291] = CRGB::Green;
             leds[1292] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==13){//7
             leds[1291] = CRGB::Black;
             leds[1292] = CRGB::Black;
             leds[1295] = CRGB::Green;
             leds[1296] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==15){//8
             leds[1295] = CRGB::Black;
             leds[1296] = CRGB::Black;
             leds[1299] = CRGB::Green;
             leds[1300] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==17){//9
             leds[1299] = CRGB::Black;
             leds[1300] = CRGB::Black;
             leds[1303] = CRGB::Green;
             leds[1304] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==19){//10
             leds[1303] = CRGB::Black;
             leds[1304] = CRGB::Black;
             leds[1307] = CRGB::Green;
             leds[1308] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==21){//11
             leds[1307] = CRGB::Black;
             leds[1308] = CRGB::Black;
             leds[1311] = CRGB::Green;
             leds[1312] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==23){//12
             leds[1311] = CRGB::Black;
             leds[1312] = CRGB::Black;
             leds[1315] = CRGB::Green;
             leds[1316] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==25){//13
             leds[1315] = CRGB::Black;
             leds[1316] = CRGB::Black;
             leds[1319] = CRGB::Green;
             leds[1320] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==27){//14
             leds[1319] = CRGB::Black;
             leds[1320] = CRGB::Black;
             leds[1323] = CRGB::Green;
             leds[1324] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==29){//15
             leds[1323] = CRGB::Black;
             leds[1324] = CRGB::Black;
             leds[1327] = CRGB::Green;
             leds[1328] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==31){//16
             leds[1327] = CRGB::Black;
             leds[1328] = CRGB::Black;
             leds[1331] = CRGB::Green;
             leds[1332] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==33){//17
             leds[1331] = CRGB::Black;
             leds[1332] = CRGB::Black;
             leds[1335] = CRGB::Green;
             leds[1336] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==35){//18
             leds[1335] = CRGB::Black;
             leds[1336] = CRGB::Black;
             leds[1339] = CRGB::Green;
             leds[1340] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==37){//19
             leds[1339] = CRGB::Black;
             leds[1340] = CRGB::Black;
             leds[1343] = CRGB::Green;
             leds[1344] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==39){//20
             leds[1343] = CRGB::Black;
             leds[1344] = CRGB::Black;
             leds[1347] = CRGB::Green;
             leds[1348] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==41){//21
             leds[1347] = CRGB::Black;
             leds[1348] = CRGB::Black;
             leds[1351] = CRGB::Green;
             leds[1352] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==43){//22
             leds[1351] = CRGB::Black;
             leds[1352] = CRGB::Black;
             leds[1355] = CRGB::Green;
             leds[1356] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==45){//23
             leds[1355] = CRGB::Black;
             leds[1356] = CRGB::Black;
             leds[1359] = CRGB::Green;
             leds[1360] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==47){//24
             leds[1359] = CRGB::Black;
             leds[1360] = CRGB::Black;
             leds[1363] = CRGB::Green;
             leds[1364] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==49){//25
             leds[1363] = CRGB::Black;
             leds[1364] = CRGB::Black;
             leds[1367] = CRGB::Green;
             leds[1368] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
//===================================================     P3 in Layer2

else if (P3T1 ==51){//26   
             leds[1367] = CRGB::Black;
             leds[1368] = CRGB::Black;
             leds[1467] = CRGB::Green;
             leds[1468] = CRGB::Green;
             FastLED.show();  
 P3T1++;
}
else if (P3T1 ==53){//27
             leds[1467] = CRGB::Black;
             leds[1468] = CRGB::Black;
             leds[1463] = CRGB::Green;
             leds[1464] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
else if (P3T1 ==55){//28
             leds[1463] = CRGB::Black;
             leds[1464] = CRGB::Black;
             leds[1459] = CRGB::Green;
             leds[1460] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
else if (P3T1 ==57){//29
             leds[1459] = CRGB::Black;
             leds[1460] = CRGB::Black;
             leds[1455] = CRGB::Green;
             leds[1456] = CRGB::Green;
             FastLED.show();
 P3T1++;
}
else if (P3T1 ==59){//30
             leds[1455] = CRGB::Black;
             leds[1456] = CRGB::Black;
             leds[1451] = CRGB::Green;
             leds[1452] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==61){//31
             leds[1451] = CRGB::Black;
             leds[1452] = CRGB::Black;
             leds[1447] = CRGB::Green;
             leds[1448] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==63){//32
             leds[1447] = CRGB::Black;
             leds[1448] = CRGB::Black;
             leds[1443] = CRGB::Green;
             leds[1444] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==65){//33
             leds[1443] = CRGB::Black;
             leds[1444] = CRGB::Black;
             leds[1439] = CRGB::Green;
             leds[1440] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==67){//34
             leds[1439] = CRGB::Black;
             leds[1440] = CRGB::Black;
             leds[1435] = CRGB::Green;
             leds[1436] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==69){//35
             leds[1435] = CRGB::Black;
             leds[1436] = CRGB::Black;
             leds[1431] = CRGB::Green;
             leds[1432] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==71){//36
             leds[1431] = CRGB::Black;
             leds[1432] = CRGB::Black;
             leds[1427] = CRGB::Green;
             leds[1428] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==73){//37
             leds[1427] = CRGB::Black;
             leds[1428] = CRGB::Black;
             leds[1423] = CRGB::Green;
             leds[1424] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==75){//38
             leds[1423] = CRGB::Black;
             leds[1424] = CRGB::Black;
             leds[1419] = CRGB::Green;
             leds[1420] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==77){//39
             leds[1419] = CRGB::Black;
             leds[1420] = CRGB::Black;
             leds[1415] = CRGB::Green;
             leds[1416] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==79){//40
             leds[1415] = CRGB::Black;
             leds[1416] = CRGB::Black;
             leds[1411] = CRGB::Green;
             leds[1412] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==81){//41
             leds[1411] = CRGB::Black;
             leds[1412] = CRGB::Black;
             leds[1407] = CRGB::Green;
             leds[1408] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==83){//42
             leds[1407] = CRGB::Black;
             leds[1408] = CRGB::Black;
             leds[1403] = CRGB::Green;
             leds[1404] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==85){//43
             leds[1403] = CRGB::Black;
             leds[1404] = CRGB::Black;
             leds[1399] = CRGB::Green;
             leds[1400] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==87){//44
             leds[1399] = CRGB::Black;
             leds[1400] = CRGB::Black;
             leds[1395] = CRGB::Green;
             leds[1396] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==89){//45
             leds[1395] = CRGB::Black;
             leds[1396] = CRGB::Black;
             leds[1391] = CRGB::Green;
             leds[1392] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==91){//46
             leds[1391] = CRGB::Black;
             leds[1392] = CRGB::Black;
             leds[1387] = CRGB::Green;
             leds[1388] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==93){//47
             leds[1387] = CRGB::Black;
             leds[1388] = CRGB::Black;
             leds[1383] = CRGB::Green;
             leds[1384] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==95){//48
             leds[1383] = CRGB::Black;
             leds[1384] = CRGB::Black;
             leds[1379] = CRGB::Green;
             leds[1380] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==97){//49
             leds[1379] = CRGB::Black;
             leds[1380] = CRGB::Black;
             leds[1375] = CRGB::Green;
             leds[1376] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}
else if (P3T1 ==99){//50
             leds[1375] = CRGB::Black;
             leds[1376] = CRGB::Black;
             leds[1371] = CRGB::Green;
             leds[1372] = CRGB::Green;
             FastLED.show();
   
 P3T1++;
}

else if (P3T1 == 101){//back to 1
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
             for (int x = 1078; x < 876;x++)
            {
               leds[x] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P3T2++;
}
else if (P3T2 == 1){//1 LED
             leds[876] = CRGB::Green;
             leds[877] = CRGB::Green;
             leds[974] = CRGB::Black;
             leds[975] = CRGB::Black;
             FastLED.show();  
 P3T2++;
}
else if (P3T2 == 3){//2
             leds[876] = CRGB::Black;
             leds[877] = CRGB::Black;
             leds[880] = CRGB::Green;
             leds[881] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
else if (P3T2 == 5){//3
             leds[880] = CRGB::Black;
             leds[881] = CRGB::Black;
             leds[884] = CRGB::Green;
             leds[885] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
else if (P3T2 == 7){//4
             leds[884] = CRGB::Black;
             leds[885] = CRGB::Black;
             leds[888] = CRGB::Green;
             leds[889] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
else if (P3T2 == 9){//5
             leds[888] = CRGB::Black;
             leds[889] = CRGB::Black;
             leds[892] = CRGB::Green;
             leds[893] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==11){//6
             leds[892] = CRGB::Black;
             leds[893] = CRGB::Black;
             leds[896] = CRGB::Green;
             leds[897] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==13){//7
             leds[896] = CRGB::Black;
             leds[897] = CRGB::Black;
             leds[900] = CRGB::Green;
             leds[901] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==15){//8
             leds[900] = CRGB::Black;
             leds[901] = CRGB::Black;
             leds[904] = CRGB::Green;
             leds[905] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==17){//9
             leds[904] = CRGB::Black;
             leds[905] = CRGB::Black;
             leds[908] = CRGB::Green;
             leds[909] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==19){//10
             leds[908] = CRGB::Black;
             leds[909] = CRGB::Black;
             leds[912] = CRGB::Green;
             leds[913] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 == 21){//11
             leds[912] = CRGB::Black;
             leds[913] = CRGB::Black;
             leds[916] = CRGB::Green;
             leds[917] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==23){//12
             leds[916] = CRGB::Black;
             leds[917] = CRGB::Black;
             leds[920] = CRGB::Green;
             leds[921] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==25){//13
             leds[920] = CRGB::Black;
             leds[921] = CRGB::Black;
             leds[924] = CRGB::Green;
             leds[925] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==27){//14
             leds[924] = CRGB::Black;
             leds[925] = CRGB::Black;
             leds[928] = CRGB::Green;
             leds[929] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==29){//15
             leds[928] = CRGB::Black;
             leds[929] = CRGB::Black;
             leds[932] = CRGB::Green;
             leds[933] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==31){//16
             leds[932] = CRGB::Black;
             leds[933] = CRGB::Black;
             leds[936] = CRGB::Green;
             leds[937] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==33){//17
             leds[936] = CRGB::Black;
             leds[937] = CRGB::Black;
             leds[940] = CRGB::Green;
             leds[941] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==35){//18
             leds[940] = CRGB::Black;
             leds[941] = CRGB::Black;
             leds[944] = CRGB::Green;
             leds[945] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==37){//19
             leds[944] = CRGB::Black;
             leds[945] = CRGB::Black;
             leds[948] = CRGB::Green;
             leds[949] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==39){//20
             leds[948] = CRGB::Black;
             leds[949] = CRGB::Black;
             leds[952] = CRGB::Green;
             leds[953] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==41){//21
             leds[952] = CRGB::Black;
             leds[953] = CRGB::Black;
             leds[956] = CRGB::Green;
             leds[957] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==43){//22
             leds[956] = CRGB::Black;
             leds[957] = CRGB::Black;
             leds[960] = CRGB::Green;
             leds[961] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==45){//23
             leds[960] = CRGB::Black;
             leds[961] = CRGB::Black;
             leds[964] = CRGB::Green;
             leds[965] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==47){//24
             leds[964] = CRGB::Black;
             leds[965] = CRGB::Black;
             leds[968] = CRGB::Green;
             leds[969] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==49){//25
             leds[968] = CRGB::Black;
             leds[969] = CRGB::Black;
             leds[972] = CRGB::Green;
             leds[973] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}

//===================================================     P3 in Layer2

else if (P3T2 ==51){//26LED
             leds[1070] = CRGB::Green;
             leds[1071] = CRGB::Green;
             leds[972] = CRGB::Black;
             leds[973] = CRGB::Black;
             FastLED.show();  
 P3T2++;
}
else if (P3T2 ==53){//27
             leds[1070] = CRGB::Black;
             leds[1071] = CRGB::Black;
             leds[1066] = CRGB::Green;
             leds[1067] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
else if (P3T2 ==55){//28
             leds[1066] = CRGB::Black;
             leds[1067] = CRGB::Black;
             leds[1062] = CRGB::Green;
             leds[1063] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
else if (P3T2 ==57){//29
             leds[1062] = CRGB::Black;
             leds[1063] = CRGB::Black;
             leds[1058] = CRGB::Green;
             leds[1059] = CRGB::Green;
             FastLED.show();
 P3T2++;
}
else if (P3T2 ==59){//30
             leds[1058] = CRGB::Black;
             leds[1059] = CRGB::Black;
             leds[1054] = CRGB::Green;
             leds[1055] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==61){//31
             leds[1054] = CRGB::Black;
             leds[1055] = CRGB::Black;
             leds[1050] = CRGB::Green;
             leds[1051] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==63){//32
             leds[1050] = CRGB::Black;
             leds[1051] = CRGB::Black;
             leds[1046] = CRGB::Green;
             leds[1047] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==65){//33
             leds[1046] = CRGB::Black;
             leds[1047] = CRGB::Black;
             leds[1042] = CRGB::Green;
             leds[1043] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==67){//34
             leds[1042] = CRGB::Black;
             leds[1043] = CRGB::Black;
             leds[1038] = CRGB::Green;
             leds[1039] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==69){//35
             leds[1038] = CRGB::Black;
             leds[1039] = CRGB::Black;
             leds[1034] = CRGB::Green;
             leds[1035] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 == 71){//36
             leds[1034] = CRGB::Black;
             leds[1035] = CRGB::Black;
             leds[1030] = CRGB::Green;
             leds[1031] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==73){//37
             leds[1030] = CRGB::Black;
             leds[1031] = CRGB::Black;
             leds[1026] = CRGB::Green;
             leds[1027] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==75){//38
             leds[1026] = CRGB::Black;
             leds[1027] = CRGB::Black;
             leds[1022] = CRGB::Green;
             leds[1023] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==77){//39
             leds[1022] = CRGB::Black;
             leds[1023] = CRGB::Black;
             leds[1018] = CRGB::Green;
             leds[1019] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==79){//40
             leds[1018] = CRGB::Black;
             leds[1019] = CRGB::Black;
             leds[1014] = CRGB::Green;
             leds[1015] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==81){//41
             leds[1014] = CRGB::Black;
             leds[1015] = CRGB::Black;
             leds[1010] = CRGB::Green;
             leds[1011] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==83){//42
             leds[1010] = CRGB::Black;
             leds[1011] = CRGB::Black;
             leds[1006] = CRGB::Green;
             leds[1007] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==85){//43
             leds[1006] = CRGB::Black;
             leds[1007] = CRGB::Black;
             leds[1002] = CRGB::Green;
             leds[1003] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==87){//44
             leds[1002] = CRGB::Black;
             leds[1003] = CRGB::Black;
             leds[998] = CRGB::Green;
             leds[999] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==89){//45
             leds[998] = CRGB::Black;
             leds[999] = CRGB::Black;
             leds[994] = CRGB::Green;
             leds[995] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==91){//46
             leds[994] = CRGB::Black;
             leds[995] = CRGB::Black;
             leds[990] = CRGB::Green;
             leds[991] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==93){//47
             leds[990] = CRGB::Black;
             leds[991] = CRGB::Black;
             leds[986] = CRGB::Green;
             leds[987] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==95){//48
             leds[986] = CRGB::Black;
             leds[987] = CRGB::Black;
             leds[982] = CRGB::Green;
             leds[983] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==97){//49
             leds[982] = CRGB::Black;
             leds[983] = CRGB::Black;
             leds[978] = CRGB::Green;
             leds[979] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 ==99){//50
             leds[978] = CRGB::Black;
             leds[979] = CRGB::Black;
             leds[974] = CRGB::Green;
             leds[975] = CRGB::Green;
             FastLED.show();
   
 P3T2++;
}
else if (P3T2 == 101){//back to 1
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
            for (int i = 678; i < 480;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
            
             leds[774] = CRGB::Black;
             leds[775] = CRGB::Black;
 P3T3++;
}
//===============================================P3 Layer1
else if (P3T3 == 1){//1 LED
             leds[480] = CRGB::Green;
             leds[481] = CRGB::Green;
             leds[774] = CRGB::Black;
             leds[775] = CRGB::Black;
             FastLED.show();  
 P3T3++;
}
else if (P3T3 == 3){//2
             leds[480] = CRGB::Black;
             leds[481] = CRGB::Black;
             leds[484] = CRGB::Green;
             leds[485] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
else if (P3T3 == 5){//3
             leds[484] = CRGB::Black;
             leds[485] = CRGB::Black;
             leds[488] = CRGB::Green;
             leds[489] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
else if (P3T3 == 7){//4
             leds[488] = CRGB::Black;
             leds[489] = CRGB::Black;
             leds[492] = CRGB::Green;
             leds[493] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
else if (P3T3 == 9){//5
             leds[492] = CRGB::Black;
             leds[493] = CRGB::Black;
             leds[496] = CRGB::Green;
             leds[497] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==11){//6
             leds[496] = CRGB::Black;
             leds[497] = CRGB::Black;
             leds[501] = CRGB::Green;
             leds[502] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==13){//7
             leds[501] = CRGB::Black;
             leds[502] = CRGB::Black;
             leds[505] = CRGB::Green;
             leds[506] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==15){//8
             leds[505] = CRGB::Black;
             leds[506] = CRGB::Black;
             leds[509] = CRGB::Green;
             leds[510] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==17){//9
             leds[509] = CRGB::Black;
             leds[510] = CRGB::Black;
             leds[513] = CRGB::Green;
             leds[514] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==19){//10
             leds[513] = CRGB::Black;
             leds[514] = CRGB::Black;
             leds[517] = CRGB::Green;
             leds[518] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 == 21){//11
             leds[517] = CRGB::Black;
             leds[518] = CRGB::Black;
             leds[521] = CRGB::Green;
             leds[522] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==23){//12
             leds[521] = CRGB::Black;
             leds[522] = CRGB::Black;
             leds[525] = CRGB::Green;
             leds[526] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==25){//13
             leds[525] = CRGB::Black;
             leds[526] = CRGB::Black;
             leds[529] = CRGB::Green;
             leds[530] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==27){//14
             leds[529] = CRGB::Black;
             leds[530] = CRGB::Black;
             leds[533] = CRGB::Green;
             leds[534] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==29){//15
             leds[533] = CRGB::Black;
             leds[534] = CRGB::Black;
             leds[537] = CRGB::Green;
             leds[538] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==31){//16
             leds[537] = CRGB::Black;
             leds[538] = CRGB::Black;
             leds[541] = CRGB::Green;
             leds[542] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==33){//17
             leds[541] = CRGB::Black;
             leds[542] = CRGB::Black;
             leds[545] = CRGB::Green;
             leds[546] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==35){//18
             leds[545] = CRGB::Black;
             leds[546] = CRGB::Black;
             leds[549] = CRGB::Green;
             leds[550] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==37){//19
             leds[549] = CRGB::Black;
             leds[550] = CRGB::Black;
             leds[553] = CRGB::Green;
             leds[554] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==39){//20
             leds[553] = CRGB::Black;
             leds[554] = CRGB::Black;
             leds[557] = CRGB::Green;
             leds[558] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==41){//21
             leds[557] = CRGB::Black;
             leds[558] = CRGB::Black;
             leds[561] = CRGB::Green;
             leds[562] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==43){//22
             leds[561] = CRGB::Black;
             leds[562] = CRGB::Black;
             leds[565] = CRGB::Green;
             leds[566] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==45){//23
             leds[565] = CRGB::Black;
             leds[566] = CRGB::Black;
             leds[569] = CRGB::Green;
             leds[570] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==47){//24
             leds[569] = CRGB::Black;
             leds[570] = CRGB::Black;
             leds[573] = CRGB::Green;
             leds[574] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==49){//25
             leds[573] = CRGB::Black;
             leds[574] = CRGB::Black;
             leds[577] = CRGB::Green;
             leds[578] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}

//===================================================     P1 in Layer2

else if (P3T3 ==51){//26LED
             leds[676] = CRGB::Green;
             leds[677] = CRGB::Green;
             leds[577] = CRGB::Black;
             leds[578] = CRGB::Black;
             FastLED.show();  
 P3T3++;
}
else if (P3T3 ==53){//27
             leds[676] = CRGB::Black;
             leds[677] = CRGB::Black;
             leds[672] = CRGB::Green;
             leds[673] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
else if (P3T3 ==55){//28
             leds[672] = CRGB::Black;
             leds[673] = CRGB::Black;
             leds[668] = CRGB::Green;
             leds[669] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
else if (P3T3 ==57){//29
             leds[668] = CRGB::Black;
             leds[669] = CRGB::Black;
             leds[664] = CRGB::Green;
             leds[665] = CRGB::Green;
             FastLED.show();
 P3T3++;
}
else if (P3T3 ==59){//30
             leds[664] = CRGB::Black;
             leds[665] = CRGB::Black;
             leds[659] = CRGB::Green;
             leds[660] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==61){//31
             leds[659] = CRGB::Black;
             leds[660] = CRGB::Black;
             leds[655] = CRGB::Green;
             leds[656] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==63){//32
             leds[655] = CRGB::Black;
             leds[656] = CRGB::Black;
             leds[651] = CRGB::Green;
             leds[652] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==65){//33
             leds[651] = CRGB::Black;
             leds[652] = CRGB::Black;
             leds[647] = CRGB::Green;
             leds[648] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==67){//34
             leds[647] = CRGB::Black;
             leds[648] = CRGB::Black;
             leds[643] = CRGB::Green;
             leds[644] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==69){//35
             leds[643] = CRGB::Black;
             leds[644] = CRGB::Black;
             leds[639] = CRGB::Green;
             leds[640] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 == 71){//36
             leds[639] = CRGB::Black;
             leds[640] = CRGB::Black;
             leds[635] = CRGB::Green;
             leds[636] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==73){//37
             leds[635] = CRGB::Black;
             leds[636] = CRGB::Black;
             leds[631] = CRGB::Green;
             leds[632] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==75){//38
             leds[631] = CRGB::Black;
             leds[632] = CRGB::Black;
             leds[627] = CRGB::Green;
             leds[628] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==77){//39
             leds[627] = CRGB::Black;
             leds[628] = CRGB::Black;
             leds[623] = CRGB::Green;
             leds[624] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==79){//40
             leds[623] = CRGB::Black;
             leds[624] = CRGB::Black;
             leds[619] = CRGB::Green;
             leds[620] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==81){//41
             leds[619] = CRGB::Black;
             leds[620] = CRGB::Black;
             leds[615] = CRGB::Green;
             leds[616] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==83){//42
             leds[615] = CRGB::Black;
             leds[616] = CRGB::Black;
             leds[611] = CRGB::Green;
             leds[612] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==85){//43
             leds[611] = CRGB::Black;
             leds[612] = CRGB::Black;
             leds[607] = CRGB::Green;
             leds[608] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==87){//44
             leds[607] = CRGB::Black;
             leds[608] = CRGB::Black;
             leds[603] = CRGB::Green;
             leds[604] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==89){//45
             leds[603] = CRGB::Black;
             leds[604] = CRGB::Black;
             leds[599] = CRGB::Green;
             leds[600] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==91){//46
             leds[599] = CRGB::Black;
             leds[600] = CRGB::Black;
             leds[595] = CRGB::Green;
             leds[596] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==93){//47
             leds[595] = CRGB::Black;
             leds[596] = CRGB::Black;
             leds[591] = CRGB::Green;
             leds[592] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==95){//48
             leds[591] = CRGB::Black;
             leds[592] = CRGB::Black;
             leds[587] = CRGB::Green;
             leds[588] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==97){//49
             leds[587] = CRGB::Black;
             leds[588] = CRGB::Black;
             leds[583] = CRGB::Green;
             leds[584] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}
else if (P3T3 ==99){//50
             leds[583] = CRGB::Black;
             leds[584] = CRGB::Black;
             leds[579] = CRGB::Green;
             leds[580] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}

else if (P3T3 ==101){//51
             leds[579] = CRGB::Black;
             leds[580] = CRGB::Black;
             leds[774] = CRGB::Green;
             leds[775] = CRGB::Green;
             FastLED.show();
   
 P3T3++;
}

else if (P3T3 == 103){//back to 1
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
for (int i = 120; i < 240;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P3T4++;
}

//===================================================     P3 in Layer2
else if (P3T4 == 1){//1 LED
             leds[238] = CRGB::Green;
             leds[239] = CRGB::Green;
             leds[120] = CRGB::Black;
             leds[121] = CRGB::Black;
             FastLED.show();  
 P3T4++;
}
else if (P3T4 == 3){//2
             leds[238] = CRGB::Black;
             leds[239] = CRGB::Black;
             leds[234] = CRGB::Green;
             leds[235] = CRGB::Green;
             FastLED.show();
 P3T4++;
}
else if (P3T4 == 5){//3
             leds[235] = CRGB::Black;
             leds[234] = CRGB::Black;
             leds[230] = CRGB::Green;
             leds[231] = CRGB::Green;
             FastLED.show();
 P3T4++;
}
else if (P3T4 == 7){//4
             leds[230] = CRGB::Black;
             leds[231] = CRGB::Black;
             leds[226] = CRGB::Green;
             leds[227] = CRGB::Green;
             FastLED.show();
 P3T4++;
}
else if (P3T4 == 9){//5
             leds[226] = CRGB::Black;
             leds[227] = CRGB::Black;
             leds[222] = CRGB::Green;
             leds[223] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==11){//6
             leds[222] = CRGB::Black;
             leds[223] = CRGB::Black;
             leds[218] = CRGB::Green;
             leds[219] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==13){//7
             leds[218] = CRGB::Black;
             leds[219] = CRGB::Black;
             leds[214] = CRGB::Green;
             leds[215] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==15){//8
             leds[215] = CRGB::Black;
             leds[214] = CRGB::Black;
             leds[210] = CRGB::Green;
             leds[211] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==17){//9
             leds[210] = CRGB::Black;
             leds[211] = CRGB::Black;
             leds[206] = CRGB::Green;
             leds[207] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==19){//10
             leds[206] = CRGB::Black;
             leds[207] = CRGB::Black;
             leds[203] = CRGB::Green;
             leds[202] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 == 21){//11
             leds[202] = CRGB::Black;
             leds[203] = CRGB::Black;
             leds[194] = CRGB::Green;
             leds[195] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==23){//12
             leds[194] = CRGB::Black;
             leds[195] = CRGB::Black;
             leds[190] = CRGB::Green;
             leds[191] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==25){//13
             leds[190] = CRGB::Black;
             leds[191] = CRGB::Black;
             leds[186] = CRGB::Green;
             leds[187] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==27){//14
             leds[186] = CRGB::Black;
             leds[187] = CRGB::Black;
             leds[182] = CRGB::Green;
             leds[183] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==29){//15
             leds[182] = CRGB::Black;
             leds[183] = CRGB::Black;
             leds[178] = CRGB::Green;
             leds[179] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==31){//16
             leds[178] = CRGB::Black;
             leds[179] = CRGB::Black;
             leds[174] = CRGB::Green;
             leds[175] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==33){//17
             leds[174] = CRGB::Black;
             leds[175] = CRGB::Black;
             leds[170] = CRGB::Green;
             leds[171] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==35){//18
             leds[170] = CRGB::Black;
             leds[171] = CRGB::Black;
             leds[166] = CRGB::Green;
             leds[167] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==37){//19
             leds[166] = CRGB::Black;
             leds[167] = CRGB::Black;
             leds[162] = CRGB::Green;
             leds[163] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==39){//20
             leds[162] = CRGB::Black;
             leds[163] = CRGB::Black;
             leds[158] = CRGB::Green;
             leds[159] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==41){//21
             leds[158] = CRGB::Black;
             leds[159] = CRGB::Black;
             leds[154] = CRGB::Green;
             leds[155] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==43){//22
             leds[154] = CRGB::Black;
             leds[155] = CRGB::Black;
             leds[150] = CRGB::Green;
             leds[151] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==45){//23
             leds[150] = CRGB::Black;
             leds[151] = CRGB::Black;
             leds[146] = CRGB::Green;
             leds[147] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==47){//24
             leds[146] = CRGB::Black;
             leds[147] = CRGB::Black;
             leds[142] = CRGB::Green;
             leds[143] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==49){//25
             leds[142] = CRGB::Black;
             leds[143] = CRGB::Black;
             leds[139] = CRGB::Green;
             leds[140] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==51){//26
             leds[139] = CRGB::Black;
             leds[140] = CRGB::Black;
             leds[136] = CRGB::Green;
             leds[135] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==53){//27
             leds[136] = CRGB::Black;
             leds[135] = CRGB::Black;
             leds[132] = CRGB::Green;
             leds[131] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==55){//29
             leds[131] = CRGB::Black;
             leds[132] = CRGB::Black;
             leds[124] = CRGB::Green;
             leds[125] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}
else if (P3T4 ==57){//30
             leds[124] = CRGB::Black;
             leds[125] = CRGB::Black;
             leds[120] = CRGB::Green;
             leds[121] = CRGB::Green;
             FastLED.show();
   
 P3T4++;
}



else if (P3T4 == 59){//back to 1

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
else if (P4T1 == 1000){
        for (int i = 1469; i < 1667;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P4T1++;
}

//===================================================     P4 in Layer1
else if (P4T1 == 1){//1 LED
             leds[1469] = CRGB::Yellow;
             leds[1470] = CRGB::Yellow;
             leds[1569] = CRGB::Black;
             leds[1570] = CRGB::Black;
             FastLED.show();  
 P4T1++;
}
else if (P4T1 == 3){//2
             leds[1469] = CRGB::Black;
             leds[1470] = CRGB::Black;
             leds[1473] = CRGB::Yellow;
             leds[1474] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
else if (P4T1 == 5){//3
             leds[1473] = CRGB::Black;
             leds[1474] = CRGB::Black;
             leds[1477] = CRGB::Yellow;
             leds[1478] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
else if (P4T1 == 7){//4
             leds[1477] = CRGB::Black;
             leds[1478] = CRGB::Black;
             leds[1481] = CRGB::Yellow;
             leds[1482] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
else if (P4T1 == 9){//5
             leds[1481] = CRGB::Black;
             leds[1482] = CRGB::Black;
             leds[1485] = CRGB::Yellow;
             leds[1486] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==11){//6
             leds[1485] = CRGB::Black;
             leds[1486] = CRGB::Black;
             leds[1489] = CRGB::Yellow;
             leds[1490] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==13){//7
             leds[1489] = CRGB::Black;
             leds[1490] = CRGB::Black;
             leds[1493] = CRGB::Yellow;
             leds[1494] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==15){//8
             leds[1493] = CRGB::Black;
             leds[1494] = CRGB::Black;
             leds[1497] = CRGB::Yellow;
             leds[1498] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==17){//9
             leds[1497] = CRGB::Black;
             leds[1498] = CRGB::Black;
             leds[1501] = CRGB::Yellow;
             leds[1502] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==19){//10
             leds[1501] = CRGB::Black;
             leds[1502] = CRGB::Black;
             leds[1505] = CRGB::Yellow;
             leds[1506] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==21){//11
             leds[1505] = CRGB::Black;
             leds[1506] = CRGB::Black;
             leds[1509] = CRGB::Yellow;
             leds[1510] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==23){//12
             leds[1509] = CRGB::Black;
             leds[1510] = CRGB::Black;
             leds[1513] = CRGB::Yellow;
             leds[1514] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==25){//13
             leds[1513] = CRGB::Black;
             leds[1514] = CRGB::Black;
             leds[1517] = CRGB::Yellow;
             leds[1518] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==27){//14
             leds[1517] = CRGB::Black;
             leds[1518] = CRGB::Black;
             leds[1521] = CRGB::Yellow;
             leds[1522] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==29){//15
             leds[1521] = CRGB::Black;
             leds[1522] = CRGB::Black;
             leds[1525] = CRGB::Yellow;
             leds[1526] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==31){//16
             leds[1525] = CRGB::Black;
             leds[1526] = CRGB::Black;
             leds[1529] = CRGB::Yellow;
             leds[1530] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==33){//17
             leds[1529] = CRGB::Black;
             leds[1530] = CRGB::Black;
             leds[1533] = CRGB::Yellow;
             leds[1534] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==35){//18
             leds[1533] = CRGB::Black;
             leds[1534] = CRGB::Black;
             leds[1537] = CRGB::Yellow;
             leds[1538] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==37){//19
             leds[1537] = CRGB::Black;
             leds[1538] = CRGB::Black;
             leds[1541] = CRGB::Yellow;
             leds[1542] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==39){//20
             leds[1541] = CRGB::Black;
             leds[1542] = CRGB::Black;
             leds[1545] = CRGB::Yellow;
             leds[1546] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==41){//21
             leds[1545] = CRGB::Black;
             leds[1546] = CRGB::Black;
             leds[1549] = CRGB::Yellow;
             leds[1550] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==43){//22
             leds[1549] = CRGB::Black;
             leds[1550] = CRGB::Black;
             leds[1553] = CRGB::Yellow;
             leds[1554] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==45){//23
             leds[1553] = CRGB::Black;
             leds[1554] = CRGB::Black;
             leds[1557] = CRGB::Yellow;
             leds[1558] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==47){//24
             leds[1557] = CRGB::Black;
             leds[1558] = CRGB::Black;
             leds[1561] = CRGB::Yellow;
             leds[1562] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==49){//25
             leds[1561] = CRGB::Black;
             leds[1562] = CRGB::Black;
             leds[1565] = CRGB::Yellow;
             leds[1566] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
//===================================================     P4 in Layer2

else if (P4T1 ==51){//26   
             leds[1565] = CRGB::Black;
             leds[1566] = CRGB::Black;
             leds[1665] = CRGB::Yellow;
             leds[1666] = CRGB::Yellow;
             FastLED.show();  
 P4T1++;
}
else if (P4T1 ==53){//27
             leds[1665] = CRGB::Black;
             leds[1666] = CRGB::Black;
             leds[1661] = CRGB::Yellow;
             leds[1662] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
else if (P4T1 ==55){//28
             leds[1661] = CRGB::Black;
             leds[1662] = CRGB::Black;
             leds[1657] = CRGB::Yellow;
             leds[1658] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
else if (P4T1 ==57){//29
             leds[1657] = CRGB::Black;
             leds[1658] = CRGB::Black;
             leds[1653] = CRGB::Yellow;
             leds[1654] = CRGB::Yellow;
             FastLED.show();
 P4T1++;
}
else if (P4T1 ==59){//30
             leds[1653] = CRGB::Black;
             leds[1654] = CRGB::Black;
             leds[1649] = CRGB::Yellow;
             leds[1650] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==61){//31
             leds[1649] = CRGB::Black;
             leds[1650] = CRGB::Black;
             leds[1645] = CRGB::Yellow;
             leds[1646] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==63){//32
             leds[1645] = CRGB::Black;
             leds[1646] = CRGB::Black;
             leds[1641] = CRGB::Yellow;
             leds[1642] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==65){//33
             leds[1641] = CRGB::Black;
             leds[1642] = CRGB::Black;
             leds[1637] = CRGB::Yellow;
             leds[1638] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==67){//34
             leds[1637] = CRGB::Black;
             leds[1638] = CRGB::Black;
             leds[1633] = CRGB::Yellow;
             leds[1634] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==69){//35
             leds[1633] = CRGB::Black;
             leds[1634] = CRGB::Black;
             leds[1630] = CRGB::Yellow;
             leds[1629] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==71){//36
             leds[1629] = CRGB::Black;
             leds[1630] = CRGB::Black;
             leds[1625] = CRGB::Yellow;
             leds[1626] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==73){//37
             leds[1625] = CRGB::Black;
             leds[1626] = CRGB::Black;
             leds[1621] = CRGB::Yellow;
             leds[1622] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==75){//38
             leds[1621] = CRGB::Black;
             leds[1622] = CRGB::Black;
             leds[1617] = CRGB::Yellow;
             leds[1618] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==77){//39
             leds[1617] = CRGB::Black;
             leds[1618] = CRGB::Black;
             leds[1613] = CRGB::Yellow;
             leds[1614] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==79){//40
             leds[1613] = CRGB::Black;
             leds[1614] = CRGB::Black;
             leds[1609] = CRGB::Yellow;
             leds[1610] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==81){//41
             leds[1609] = CRGB::Black;
             leds[1610] = CRGB::Black;
             leds[1605] = CRGB::Yellow;
             leds[1606] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==83){//42
             leds[1605] = CRGB::Black;
             leds[1606] = CRGB::Black;
             leds[1601] = CRGB::Yellow;
             leds[1602] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==85){//43
             leds[1601] = CRGB::Black;
             leds[1602] = CRGB::Black;
             leds[1597] = CRGB::Yellow;
             leds[1598] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==87){//44
             leds[1597] = CRGB::Black;
             leds[1598] = CRGB::Black;
             leds[1593] = CRGB::Yellow;
             leds[1594] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==89){//45
             leds[1593] = CRGB::Black;
             leds[1594] = CRGB::Black;
             leds[1589] = CRGB::Yellow;
             leds[1590] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==91){//46
             leds[1589] = CRGB::Black;
             leds[1590] = CRGB::Black;
             leds[1585] = CRGB::Yellow;
             leds[1586] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==93){//47
             leds[1585] = CRGB::Black;
             leds[1586] = CRGB::Black;
             leds[1581] = CRGB::Yellow;
             leds[1582] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==95){//48
             leds[1581] = CRGB::Black;
             leds[1582] = CRGB::Black;
             leds[1577] = CRGB::Yellow;
             leds[1578] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==97){//49
             leds[1577] = CRGB::Black;
             leds[1578] = CRGB::Black;
             leds[1573] = CRGB::Yellow;
             leds[1574] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}
else if (P4T1 ==99){//50
             leds[1573] = CRGB::Black;
             leds[1574] = CRGB::Black;
             leds[1569] = CRGB::Yellow;
             leds[1570] = CRGB::Yellow;
             FastLED.show();
   
 P4T1++;
}

else if (P4T1 == 101){//back to 1
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
            for (int i = 1074; i < 1270;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P4T2++;
}

//===================================================     P4 in Layer1
else if (P4T2 == 1){//1 LED
             leds[1074] = CRGB::Yellow;
             leds[1075] = CRGB::Yellow;
             leds[1180] = CRGB::Black;
             leds[1181] = CRGB::Black;
             FastLED.show();  
 P4T2++;
}
else if (P4T2 == 3){//2
             leds[1074] = CRGB::Black;
             leds[1075] = CRGB::Black;
             leds[1078] = CRGB::Yellow;
             leds[1079] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
else if (P4T2 == 5){//3
             leds[1078] = CRGB::Black;
             leds[1079] = CRGB::Black;
             leds[1082] = CRGB::Yellow;
             leds[1083] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
else if (P4T2 == 7){//4
             leds[1082] = CRGB::Black;
             leds[1083] = CRGB::Black;
             leds[1086] = CRGB::Yellow;
             leds[1087] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
else if (P4T2 == 9){//5
             leds[1086] = CRGB::Black;
             leds[1087] = CRGB::Black;
             leds[1090] = CRGB::Yellow;
             leds[1091] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==11){//6
             leds[1090] = CRGB::Black;
             leds[1091] = CRGB::Black;
             leds[1094] = CRGB::Yellow;
             leds[1095] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==13){//7
             leds[1094] = CRGB::Black;
             leds[1095] = CRGB::Black;
             leds[1098] = CRGB::Yellow;
             leds[1099] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==15){//8
             leds[1098] = CRGB::Black;
             leds[1099] = CRGB::Black;
             leds[1102] = CRGB::Yellow;
             leds[1103] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==17){//9
             leds[1102] = CRGB::Black;
             leds[1103] = CRGB::Black;
             leds[1106] = CRGB::Yellow;
             leds[1107] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==19){//10
             leds[1106] = CRGB::Black;
             leds[1107] = CRGB::Black;
             leds[1110] = CRGB::Yellow;
             leds[1111] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==21){//11
             leds[1110] = CRGB::Black;
             leds[1111] = CRGB::Black;
             leds[1114] = CRGB::Yellow;
             leds[1115] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==23){//12
             leds[1114] = CRGB::Black;
             leds[1115] = CRGB::Black;
             leds[1118] = CRGB::Yellow;
             leds[1119] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==25){//13
             leds[1118] = CRGB::Black;
             leds[1119] = CRGB::Black;
             leds[1122] = CRGB::Yellow;
             leds[1123] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==27){//14
             leds[1122] = CRGB::Black;
             leds[1123] = CRGB::Black;
             leds[1126] = CRGB::Yellow;
             leds[1127] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==29){//15
             leds[1126] = CRGB::Black;
             leds[1127] = CRGB::Black;
             leds[1130] = CRGB::Yellow;
             leds[1131] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==31){//16
             leds[1130] = CRGB::Black;
             leds[1131] = CRGB::Black;
             leds[1134] = CRGB::Yellow;
             leds[1135] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==33){//17
             leds[1134] = CRGB::Black;
             leds[1135] = CRGB::Black;
             leds[1138] = CRGB::Yellow;
             leds[1139] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==35){//18
             leds[1138] = CRGB::Black;
             leds[1139] = CRGB::Black;
             leds[1142] = CRGB::Yellow;
             leds[1143] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==37){//19
             leds[1142] = CRGB::Black;
             leds[1143] = CRGB::Black;
             leds[1146] = CRGB::Yellow;
             leds[1147] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==39){//20
             leds[1146] = CRGB::Black;
             leds[1147] = CRGB::Black;
             leds[1150] = CRGB::Yellow;
             leds[1151] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==41){//21
             leds[1150] = CRGB::Black;
             leds[1151] = CRGB::Black;
             leds[1154] = CRGB::Yellow;
             leds[1155] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==43){//22
             leds[1154] = CRGB::Black;
             leds[1155] = CRGB::Black;
             leds[1158] = CRGB::Yellow;
             leds[1159] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==45){//23
             leds[1158] = CRGB::Black;
             leds[1159] = CRGB::Black;
             leds[1162] = CRGB::Yellow;
             leds[1163] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==47){//24
             leds[1162] = CRGB::Black;
             leds[1163] = CRGB::Black;
             leds[1166] = CRGB::Yellow;
             leds[1167] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==49){//25
             leds[1166] = CRGB::Black;
             leds[1167] = CRGB::Black;
             leds[1170] = CRGB::Yellow;
             leds[1171] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
//===================================================     P4 in Layer2

else if (P4T2 ==51){//26   
             leds[1158] = CRGB::Black;
             leds[1159] = CRGB::Black;
             leds[1268] = CRGB::Yellow;
             leds[1269] = CRGB::Yellow;
             FastLED.show();  
 P4T2++;
}
else if (P4T2 ==53){//27
             leds[1268] = CRGB::Black;
             leds[1269] = CRGB::Black;
             leds[1264] = CRGB::Yellow;
             leds[1265] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
else if (P4T2 ==55){//28
             leds[1264] = CRGB::Black;
             leds[1265] = CRGB::Black;
             leds[1260] = CRGB::Yellow;
             leds[1261] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
else if (P4T2 ==57){//29
             leds[1260] = CRGB::Black;
             leds[1261] = CRGB::Black;
             leds[1256] = CRGB::Yellow;
             leds[1257] = CRGB::Yellow;
             FastLED.show();
 P4T2++;
}
else if (P4T2 ==59){//30
             leds[1256] = CRGB::Black;
             leds[1257] = CRGB::Black;
             leds[1252] = CRGB::Yellow;
             leds[1253] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==61){//31
             leds[1252] = CRGB::Black;
             leds[1253] = CRGB::Black;
             leds[1248] = CRGB::Yellow;
             leds[1249] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==63){//32
             leds[1248] = CRGB::Black;
             leds[1249] = CRGB::Black;
             leds[1244] = CRGB::Yellow;
             leds[1245] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==65){//33
             leds[1244] = CRGB::Black;
             leds[1245] = CRGB::Black;
             leds[1240] = CRGB::Yellow;
             leds[1241] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==67){//34
             leds[1240] = CRGB::Black;
             leds[1241] = CRGB::Black;
             leds[1236] = CRGB::Yellow;
             leds[1237] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==69){//35
             leds[1236] = CRGB::Black;
             leds[1237] = CRGB::Black;
             leds[1232] = CRGB::Yellow;
             leds[1233] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==71){//36
             leds[1232] = CRGB::Black;
             leds[1233] = CRGB::Black;
             leds[1228] = CRGB::Yellow;
             leds[1229] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==73){//37
             leds[1228] = CRGB::Black;
             leds[1229] = CRGB::Black;
             leds[1224] = CRGB::Yellow;
             leds[1225] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==75){//38
             leds[1224] = CRGB::Black;
             leds[1225] = CRGB::Black;
             leds[1220] = CRGB::Yellow;
             leds[1221] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==77){//39
             leds[1220] = CRGB::Black;
             leds[1221] = CRGB::Black;
             leds[1216] = CRGB::Yellow;
             leds[1217] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==79){//40
             leds[1216] = CRGB::Black;
             leds[1217] = CRGB::Black;
             leds[1212] = CRGB::Yellow;
             leds[1213] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==81){//41
             leds[1212] = CRGB::Black;
             leds[1213] = CRGB::Black;
             leds[1208] = CRGB::Yellow;
             leds[1209] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==83){//42
             leds[1208] = CRGB::Black;
             leds[1209] = CRGB::Black;
             leds[1204] = CRGB::Yellow;
             leds[1205] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==85){//43
             leds[1204] = CRGB::Black;
             leds[1205] = CRGB::Black;
             leds[1200] = CRGB::Yellow;
             leds[1201] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==87){//44
             leds[1200] = CRGB::Black;
             leds[1201] = CRGB::Black;
             leds[1196] = CRGB::Yellow;
             leds[1197] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==89){//45
             leds[1196] = CRGB::Black;
             leds[1197] = CRGB::Black;
             leds[1192] = CRGB::Yellow;
             leds[1193] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==91){//46
             leds[1192] = CRGB::Black;
             leds[1193] = CRGB::Black;
             leds[1188] = CRGB::Yellow;
             leds[1189] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==93){//47
             leds[1188] = CRGB::Black;
             leds[1189] = CRGB::Black;
             leds[1184] = CRGB::Yellow;
             leds[1185] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}
else if (P4T2 ==95){//48
             leds[1184] = CRGB::Black;
             leds[1185] = CRGB::Black;
             leds[1180] = CRGB::Yellow;
             leds[1181] = CRGB::Yellow;
             FastLED.show();
   
 P4T2++;
}

else if (P4T2 == 97){//back to 1
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
          for (int i = 678; i < 875;i++)
            {
               leds[i] = CRGB::Black; delay(10);
             FastLED.show();  
            }
 P4T3++;
}

//===================================================     P2 in Layer1
else if (P4T3 == 1){//1
             leds[809] = CRGB::Black;
             leds[810] = CRGB::Black;
             leds[678] = CRGB::Red;
             leds[679] = CRGB::Red;
             FastLED.show();
 P4T3++;
}
else if (P4T3 == 1){//2
             leds[678] = CRGB::Black;
             leds[679] = CRGB::Black;
             leds[682] = CRGB::Red;
             leds[683] = CRGB::Red;
             FastLED.show();
 P4T3++;
}
else if (P4T3 == 3){//3
             leds[682] = CRGB::Black;
             leds[683] = CRGB::Black;
             leds[686] = CRGB::Red;
             leds[687] = CRGB::Red;
             FastLED.show();
 P4T3++;
}
else if (P4T3 == 5){//4
             leds[686] = CRGB::Black;
             leds[687] = CRGB::Black;
             leds[690] = CRGB::Red;
             leds[691] = CRGB::Red;
             FastLED.show();
 P4T3++;
}
else if (P4T3 == 7){//5
             leds[690] = CRGB::Black;
             leds[691] = CRGB::Black;
             leds[694] = CRGB::Red;
             leds[695] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 == 9){//6
             leds[694] = CRGB::Black;
             leds[695] = CRGB::Black;
             leds[698] = CRGB::Red;
             leds[699] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==11){//7
             leds[698] = CRGB::Black;
             leds[699] = CRGB::Black;
             leds[702] = CRGB::Red;
             leds[703] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==13){//8
             leds[702] = CRGB::Black;
             leds[703] = CRGB::Black;
             leds[706] = CRGB::Red;
             leds[707] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==15){//9
             leds[706] = CRGB::Black;
             leds[707] = CRGB::Black;
             leds[710] = CRGB::Red;
             leds[711] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==17){//10
             leds[710] = CRGB::Black;
             leds[711] = CRGB::Black;
             leds[714] = CRGB::Red;
             leds[715] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==19){//11
             leds[714] = CRGB::Black;
             leds[715] = CRGB::Black;
             leds[718] = CRGB::Red;
             leds[719] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==21){//12
             leds[718] = CRGB::Black;
             leds[719] = CRGB::Black;
             leds[722] = CRGB::Red;
             leds[723] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==23){//13
             leds[722] = CRGB::Black;
             leds[723] = CRGB::Black;
             leds[726] = CRGB::Red;
             leds[727] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==25){//14
             leds[726] = CRGB::Black;
             leds[727] = CRGB::Black;
             leds[730] = CRGB::Red;
             leds[731] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==27){//15
             leds[730] = CRGB::Black;
             leds[731] = CRGB::Black;
             leds[734] = CRGB::Red;
             leds[735] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==29){//16
             leds[734] = CRGB::Black;
             leds[735] = CRGB::Black;
             leds[738] = CRGB::Red;
             leds[739] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==31){//17
             leds[738] = CRGB::Black;
             leds[739] = CRGB::Black;
             leds[742] = CRGB::Red;
             leds[743] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==33){//18
             leds[742] = CRGB::Black;
             leds[743] = CRGB::Black;
             leds[746] = CRGB::Red;
             leds[747] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==35){//19
             leds[746] = CRGB::Black;
             leds[747] = CRGB::Black;
             leds[750] = CRGB::Red;
             leds[751] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==37){//20
             leds[750] = CRGB::Black;
             leds[751] = CRGB::Black;
             leds[754] = CRGB::Red;
             leds[755] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==39){//21
             leds[754] = CRGB::Black;
             leds[755] = CRGB::Black;
             leds[758] = CRGB::Red;
             leds[759] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==41){//22
             leds[758] = CRGB::Black;
             leds[759] = CRGB::Black;
             leds[762] = CRGB::Red;
             leds[763] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==43){//23
             leds[762] = CRGB::Black;
             leds[763] = CRGB::Black;
             leds[766] = CRGB::Red;
             leds[767] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==45){//24
             leds[766] = CRGB::Black;
             leds[767] = CRGB::Black;
             leds[770] = CRGB::Red;
             leds[771] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}


//===================================================     P2 in Layer2

else if (P4T3 ==27){//26LED
             leds[873] = CRGB::Red;
             leds[874] = CRGB::Red;
             leds[750] = CRGB::Black;
             leds[751] = CRGB::Black;
             FastLED.show();  
 P4T3++;
}
else if (P4T3 ==29){//27
             leds[873] = CRGB::Black;
             leds[874] = CRGB::Black;
             leds[869] = CRGB::Red;
             leds[870] = CRGB::Red;
             FastLED.show();
 P4T3++;
}
else if (P4T3 ==31){//28
             leds[869] = CRGB::Black;
             leds[870] = CRGB::Black;
             leds[865] = CRGB::Red;
             leds[866] = CRGB::Red;
             FastLED.show();
 P4T3++;
}
else if (P4T3 ==33){//29
             leds[865] = CRGB::Black;
             leds[866] = CRGB::Black;
             leds[861] = CRGB::Red;
             leds[862] = CRGB::Red;
             FastLED.show();
 P4T3++;
}
else if (P4T3 ==35){//30
             leds[861] = CRGB::Black;
             leds[862] = CRGB::Black;
             leds[857] = CRGB::Red;
             leds[858] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==37){//31
             leds[857] = CRGB::Black;
             leds[858] = CRGB::Black;
             leds[853] = CRGB::Red;
             leds[854] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==39){//32
             leds[853] = CRGB::Black;
             leds[854] = CRGB::Black;
             leds[849] = CRGB::Red;
             leds[850] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==41){//33
             leds[849] = CRGB::Black;
             leds[850] = CRGB::Black;
             leds[845] = CRGB::Red;
             leds[846] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==43){//34
             leds[845] = CRGB::Black;
             leds[846] = CRGB::Black;
             leds[841] = CRGB::Red;
             leds[842] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==45){//35
             leds[841] = CRGB::Black;
             leds[842] = CRGB::Black;
             leds[837] = CRGB::Red;
             leds[838] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==47){//36
             leds[837] = CRGB::Black;
             leds[838] = CRGB::Black;
             leds[833] = CRGB::Red;
             leds[834] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==49){//37
             leds[833] = CRGB::Black;
             leds[834] = CRGB::Black;
             leds[829] = CRGB::Red;
             leds[830] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==51){//38
             leds[829] = CRGB::Black;
             leds[830] = CRGB::Black;
             leds[825] = CRGB::Red;
             leds[826] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==53){//39
             leds[825] = CRGB::Black;
             leds[826] = CRGB::Black;
             leds[821] = CRGB::Red;
             leds[822] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==55){//40
             leds[821] = CRGB::Black;
             leds[822] = CRGB::Black;
             leds[817] = CRGB::Red;
             leds[818] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==57){//41
             leds[817] = CRGB::Black;
             leds[818] = CRGB::Black;
             leds[813] = CRGB::Red;
             leds[814] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}
else if (P4T3 ==59){//42
             leds[813] = CRGB::Black;
             leds[814] = CRGB::Black;
             leds[809] = CRGB::Red;
             leds[810] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==61){//43
             leds[809] = CRGB::Black;
             leds[810] = CRGB::Black;
             leds[805] = CRGB::Red;
             leds[806] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==63){//44
             leds[805] = CRGB::Black;
             leds[806] = CRGB::Black;
             leds[801] = CRGB::Red;
             leds[802] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==65){//45
             leds[801] = CRGB::Black;
             leds[802] = CRGB::Black;
             leds[797] = CRGB::Red;
             leds[798] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==67){//46
             leds[797] = CRGB::Black;
             leds[798] = CRGB::Black;
             leds[793] = CRGB::Red;
             leds[794] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==69){//47
             leds[793] = CRGB::Black;
             leds[794] = CRGB::Black;
             leds[789] = CRGB::Red;
             leds[790] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==71){//48
             leds[789] = CRGB::Black;
             leds[790] = CRGB::Black;
             leds[785] = CRGB::Red;
             leds[786] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==73){//49
             leds[785] = CRGB::Black;
             leds[786] = CRGB::Black;
             leds[781] = CRGB::Red;
             leds[782] = CRGB::Red;
             FastLED.show();
   
 P4T3++;
}

else if (P4T3 ==75){//50
             leds[781] = CRGB::Black;
             leds[782] = CRGB::Black;
             leds[777] = CRGB::Red;
             leds[778] = CRGB::Red;
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

