#include <Arduino.h>
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

const int  buttonPin = 2;    // pause&start individual
const int  buttonPin1 = 6;    // reset&set
const int  buttonPin2 = 5;   //settings
const int  yellow = 7;
const int  red = 8;
const int  externalStart = 9;

int minutes = 3;
int seconds = 0;
int critical = 2;


// Variables will change:
int buttonPushCounter = 0;   
int buttonState = 0;         
int lastButtonState = 0;     
int buttonState1 = 0;         
int buttonPushCounter1 = 10;   
int lastButtonState1 = 0;

int lineTop = -15;
int lineBot = 128;

long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;
bool check = false;
bool fast = false;

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R2, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  pinMode(3,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(externalStart, INPUT);
  u8g2.begin(); 
  
  ttech();
  start();
}

uint8_t m = minutes;
uint8_t s = seconds;

void loop(void) {


  buttonState = digitalRead(buttonPin);
  buttonState1 = digitalRead(buttonPin1);
  if (digitalRead(buttonPin2))
  {
    buttonPushCounter1 = 0;
    set();
  } 
  if (digitalRead(externalStart))
  {
    buttonPushCounter = 1;
    
  }
//======================================================================================================== 
 
  if (buttonState != lastButtonState) {
   
    if ((buttonState == HIGH)) {
     if((buttonPushCounter1 > 9)){
      buttonPushCounter++;
      fast = false;
     }
     else if((buttonPushCounter1 <= 4))
     {
      buttonPushCounter++; 
      fast = true;
      delay(300);
     }
      if (buttonPushCounter > 59)
        {
          buttonPushCounter = 0;
        }
    } 
    else{
      
    }
 
   delay(50);
  }
  if (fast == false)
  {
  lastButtonState = buttonState;
  }
//========================================================================================================

   if (buttonState1 != lastButtonState1) {
   
    if (buttonState1 == HIGH) {
      buttonPushCounter1++;
      buttonPushCounter = 0;
    } else {
      
    }
   delay(50);
  }
  
  lastButtonState1 = buttonState1;


//if ((buttonPushCounter1 < 5) && (buttonState == HIGH)) {
//      buttonPushCounter++;
//}
if (((buttonPushCounter % 2) != 0) && (buttonPushCounter1 > 3) &&(check == false))  
{
  
  char m_str[3];
  char s_str[3];
  strcpy(m_str, u8x8_u8toa(m, 2));    /* convert m to a string with two digits */
  strcpy(s_str, u8x8_u8toa(s, 2));   /* convert m to a string with two digits */
  u8g2.firstPage();
  do {
      u8g2.setFont(u8g2_font_logisoso50_tf);
      u8g2.drawStr(-3,57,m_str);
      u8g2.drawStr(55,57,":");
      u8g2.drawStr(65,57,s_str);
      //u8g2.drawFrame(-1,0,130,62);
      u8g2.drawHLine(lineTop,0,15);
      u8g2.drawHLine(lineTop,1,15);
      u8g2.drawHLine(lineTop,2,15);
      u8g2.drawHLine(lineBot,61,15);
      u8g2.drawHLine(lineBot,62,15);
      u8g2.drawHLine(lineBot,63,15);
     }
  while ( 
      u8g2.nextPage() 
      );
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) 
  {
      previousMillis = currentMillis;
      if ( (s == 0) && (m > 0) )
      {
      s = 60;
      m--;
      }
      if  (m < (critical))
      {
          tone(3, 1100, 500);
      }
//      if  (m == 0)
//      {
//          tone(3, 500, 600);
//      }
      if  ((m == 0) && (s == 0))
      {
      
       check = true;
       m=minutes;
       s=seconds + 1;
          buttonPushCounter++;
      }
      
  
     s--;   
  }//millis
if  (m < critical)
      {
        digitalWrite(yellow, HIGH);
        lineTop++;
        lineTop++;
        lineTop++;
        lineTop++;
        lineBot--;
        lineBot--;
        lineBot--;
        lineBot--;
        if (lineTop >= 128)
        {
          lineTop = -15;
          lineBot = 128;
        }
      }
}//even


if (((buttonPushCounter % 2) == 0) && (buttonPushCounter1 > 3) && (check == false))
{
  digitalWrite(yellow, LOW);
}

if  ((buttonPushCounter1 > 4) && (buttonState1 == HIGH))
{

 noTone(3);
 check = false;
 m=minutes;
 s=seconds;
 buttonPushCounter = 0;
 
  lineTop = -15;
  lineBot = 128;
 start();
}// not even

if (check == true)
{
  tone(3, 2000);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(2000);
  digitalWrite(red, LOW);
  noTone(3);
 check = false;
 m=minutes;
 s=seconds;
 buttonPushCounter = 0;
  lineTop = -15;
  lineBot = 128;
 start();
}




if (buttonPushCounter1 == 1)
{
    m = buttonPushCounter;    
  char m_str[3];
  char s_str[3];
  strcpy(m_str, u8x8_u8toa(m, 2));    /* convert m to a string with two digits */
  strcpy(s_str, u8x8_u8toa(s, 2));   /* convert m to a string with two digits */
  u8g2.firstPage();
  do {
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_logisoso50_tf);
    u8g2.drawStr(0,56,m_str);
    u8g2.drawStr(57,56,":");
    u8g2.drawStr(66,56,s_str);
    u8g2.drawFrame(3,0,60,62);
  } while ( u8g2.nextPage() );
    minutes = m;
}




if (buttonPushCounter1 == 2)
{
 // buttonPushCounter = 0;
    s = buttonPushCounter;    
  char m_str[3];
  char s_str[3];
  strcpy(m_str, u8x8_u8toa(m, 2));    /* convert m to a string with two digits */
  strcpy(s_str, u8x8_u8toa(s, 2));   /* convert m to a string with two digits */
  u8g2.firstPage();
  do {
    
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_logisoso50_tf);
    u8g2.drawStr(0,56,m_str);
      u8g2.drawStr(57,56,":");
      u8g2.drawStr(66,56,s_str);
    u8g2.drawFrame(69,0,59,62);
  } while ( u8g2.nextPage() );
    seconds = s;
}


if (buttonPushCounter1 == 3)
{
 // buttonPushCounter = 0;
  if (buttonPushCounter > m)
 {
  buttonPushCounter = 0;
 }
    critical = buttonPushCounter;    
  char critical_str[3];
  strcpy(critical_str, u8x8_u8toa(critical, 2));    /* convert m to a string with two digits */
  u8g2.firstPage();
  do {
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_freedoomr10_tu);
    u8g2.drawStr(0,15,"BUZZ UNDER:");
    u8g2.drawStr(95,45,"MIN");
    u8g2.setFont(u8g2_font_inb21_mf);
    u8g2.drawStr(40,47,critical_str);
    u8g2.drawFrame(32,15,54,43);
  } while ( u8g2.nextPage() );
   
}


if (buttonPushCounter1 == 4)
{
  lineTop = -15;
  lineBot = 128;
 start();
 buttonPushCounter=10;
}


}//loop



void ttech()
{
  u8g2.clearBuffer(); 
    u8g2.setFont(u8g2_font_inb21_mf);
  u8g2.drawStr(7,42,"T-TECH");
  u8g2.drawFrame(0,0,128,62);
  u8g2.sendBuffer();
  delay(1500);
  buttonPushCounter1 = 10;
}
void start()
{
  u8g2.clearBuffer(); 
  u8g2.setFont(u8g2_font_inb21_mf);
  u8g2.drawStr(17,42,"START");
  u8g2.drawFrame(0,0,128,62);
  u8g2.sendBuffer();
  delay(100);
  buttonPushCounter1 = 10;
}

void set()
{
  u8g2.clearBuffer(); 
  u8g2.setFont(u8g2_font_inb21_mf);
  u8g2.drawStr(37,42,"SET");
  u8g2.drawFrame(0,0,128,62);
  u8g2.sendBuffer();
  delay(100);
}

