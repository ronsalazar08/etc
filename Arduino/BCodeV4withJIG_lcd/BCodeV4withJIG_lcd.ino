#include <LiquidCrystal.h>
#include <hidboot.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif
int Contrast=20;
byte IC1,IC2,IC3;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char BarcodeBuffer[20];
int BarcodeBufferIndex = 0 ;                                            
boolean BarcodeComplete = false ;                                        
class KbdRptParser : public KeyboardReportParser
{protected:
    void OnKeyDown	(uint8_t mod, uint8_t key);
    void OnKeyUp	(uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);
};
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  uint8_t c = OemToAscii(mod, key);
      if (c)
     if (mod != 1)OnKeyPressed(c);                                      
}

void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)
{if (key==40){BarcodeComplete = true ;}}

void KbdRptParser::OnKeyPressed(uint8_t key)
{
  BarcodeBuffer[BarcodeBufferIndex] = key;      
  BarcodeBufferIndex ++;
 }

USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
uint32_t next_time;
KbdRptParser Prs;
void setup()
{
pinMode(52, OUTPUT);//clock
pinMode(51, OUTPUT);//data
pinMode(22, OUTPUT);//latch
SPI.setBitOrder(MSBFIRST); // to send byte to shift register
SPI.setDataMode(SPI_MODE0); // to send byte to shift register
SPI.setClockDivider(SPI_CLOCK_DIV2); // to send byte to shift register
SPI.begin(); // to send byte to shift register
Serial.begin( 115200 );
#if !defined(__MIPSEL__)
while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  Serial.println("Start");
  if (Usb.Init() == -1)
  Serial.println("OSC did not start.");
  delay( 200 );
  next_time = millis() + 5000;
  HidKeyboard.SetReportParser(0, &Prs);
  
  SPI.transfer(0); 
  digitalWrite(22, HIGH); // latch
  digitalWrite(22, LOW); // latch
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   TTech NAVI");
  lcd.setCursor(0,1);
  lcd.print("      SP17    ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  LOADING....    ");
  lcd.setCursor(0,1);
  lcd.print("  Please Wait   ");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    S C A N  ");
  lcd.setCursor(0,1);
  lcd.print("    BARCODE     ");
}
void loop()
{
 BarcodeBufferIndex = 0;
      while (BarcodeComplete == false)
        {
          Usb.Task();
        }
      BarcodeComplete = false ;
      BarcodeBufferIndex --;
     Serial.write(BarcodeBuffer,BarcodeBufferIndex);
    Serial.write('\n');
   if ((BarcodeBuffer[0] == 'P') &&
         (BarcodeBuffer[1] == 'r') &&
         (BarcodeBuffer[2] == 'o') &&
         (BarcodeBuffer[3] == 'd') &&
         (BarcodeBuffer[4] == 'u') &&
         (BarcodeBuffer[5] == 'c') &&
         (BarcodeBuffer[6] == 't') &&
         (BarcodeBuffer[7] == '_') &&
         (BarcodeBuffer[8] == 'A')) 
      {
       
     /*
        IC1 = 1,13,8,9,85,7,10,t5
        IC2 = 5,3,4,6,Gr,0,0,0
        IC3 = 1,200,2,20,0,0,0,0
      */
        IC1 = B11111111;
        IC2 = B11111111;
        IC3 = B11111111;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Product_A");
        lcd.setCursor(0,1);
        lcd.print("ALL TAKE-OUT");
        lcd.noBlink();
      }
 else if ((BarcodeBuffer[0] == 'P') &&
         (BarcodeBuffer[1] == 'r') &&
         (BarcodeBuffer[2] == 'o') &&
         (BarcodeBuffer[3] == 'd') &&
         (BarcodeBuffer[4] == 'u') &&
         (BarcodeBuffer[5] == 'c') &&
         (BarcodeBuffer[6] == 't') &&
         (BarcodeBuffer[7] == '_') &&
         (BarcodeBuffer[8] == 'B')) 
      {
       
     /*
        IC1 = 11,13,8,9,85,7,10,t5
        IC2 = 5,3,4,6,Gr,0,0,0
        IC3 = 1,200,2,20,0,0,0,0
      */
        IC1 = B10010001;
        IC2 = B00010000;
        IC3 = B00000001;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Product_B");
        lcd.setCursor(0,1);
        lcd.print("STRAIGHT");
        lcd.noBlink();
      }
 else if ((BarcodeBuffer[0] == 'P') &&
         (BarcodeBuffer[1] == 'r') &&
         (BarcodeBuffer[2] == 'o') &&
         (BarcodeBuffer[3] == 'd') &&
         (BarcodeBuffer[4] == 'u') &&
         (BarcodeBuffer[5] == 'c') &&
         (BarcodeBuffer[6] == 't') &&
         (BarcodeBuffer[7] == '_') &&
         (BarcodeBuffer[8] == 'C')) 
      {
     /*
        IC1 = 11,13,8,9,85,7,10,t5
        IC2 = 5,3,4,6,Gr,0,0,0
        IC3 = 1,200,2,20,0,0,0,0
      */
        IC1 = B11011001;
        IC2 = B00011010;
        IC3 = B00000110;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Product_C");
        lcd.setCursor(0,1);
        lcd.print("SIX TAKE-OUT");
        lcd.noBlink();
      }
     else if ((BarcodeBuffer[0] == 'P') &&
         (BarcodeBuffer[1] == 'r') &&
         (BarcodeBuffer[2] == 'o') &&
         (BarcodeBuffer[3] == 'd') &&
         (BarcodeBuffer[4] == 'u') &&
         (BarcodeBuffer[5] == 'c') &&
         (BarcodeBuffer[6] == 't') &&
         (BarcodeBuffer[7] == '_') &&
         (BarcodeBuffer[8] == 'D')) 
      {
         /*
        IC1 = 11,13,8,9,85,7,10,t5
        IC2 = 5,3,4,6,Gr,0,0,0
        IC3 = 1,200,2,20,0,0,0,0
      */
        IC1 = B10110101;
        IC2 = B00010100;
        IC3 = B00001011;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
         lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Product_D");
        lcd.setCursor(0,1);
        lcd.print("SIX TAKE-OUT");
        lcd.noBlink();
      }
      else if ((BarcodeBuffer[0] == 'P') &&
         (BarcodeBuffer[1] == 'r') &&
         (BarcodeBuffer[2] == 'o') &&
         (BarcodeBuffer[3] == 'd') &&
         (BarcodeBuffer[4] == 'u') &&
         (BarcodeBuffer[5] == 'c') &&
         (BarcodeBuffer[6] == 't') &&
         (BarcodeBuffer[7] == '_') &&
         (BarcodeBuffer[8] == 'E')) 
      {
 /*
        IC1 = 11,13,8,9,85,7,10,t5
        IC2 = 5,3,4,6,Gr,0,0,0
        IC3 = 1,200,2,20,0,0,0,0
      */
        IC1 = B11010001;
        IC2 = B00010011;
        IC3 = B00001111;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);        
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
         lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Product_E");
        lcd.setCursor(0,1);
        lcd.print("SEVEN TAKE-OUT");
        lcd.noBlink();
      }
      else if ((BarcodeBuffer[0] == 'P') &&
         (BarcodeBuffer[1] == 'r') &&
         (BarcodeBuffer[2] == 'o') &&
         (BarcodeBuffer[3] == 'd') &&
         (BarcodeBuffer[4] == 'u') &&
         (BarcodeBuffer[5] == 'c') &&
         (BarcodeBuffer[6] == 't') &&
         (BarcodeBuffer[7] == '_') &&
         (BarcodeBuffer[8] == 'F')) 
      {
         /*
        IC1 = 11,13,8,9,85,7,10,t5
        IC2 = 5,3,4,6,Gr,0,0,0
        IC3 = 1,200,2,20,0,0,0,0
      */
        IC1 = B10010001;
        IC2 = B00011111;
        IC3 = B00000001;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
         lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Product_F");
        lcd.setCursor(0,1);
        lcd.print("SIX TAKE-OUT");
        lcd.noBlink();
      }
     else if ((BarcodeBuffer[0] == 'P') &&
         (BarcodeBuffer[1] == 'r') &&
         (BarcodeBuffer[2] == 'o') &&
         (BarcodeBuffer[3] == 'd') &&
         (BarcodeBuffer[4] == 'u') &&
         (BarcodeBuffer[5] == 'c') &&
         (BarcodeBuffer[6] == 't') &&
         (BarcodeBuffer[7] == '_') &&
         (BarcodeBuffer[8] == 'G')) 
      {
        
        /*
        IC1 = 11,13,8,9,85,7,10,t5
        IC2 = 5,3,4,6,Gr,0,0,0
        IC3 = 1,200,2,20,0,0,0,0
      */
        IC1 = B11110001;
        IC2 = B00010001;
        IC3 = B00001111;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
         lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Product_G");
        lcd.setCursor(0,1);
        lcd.print("SEVEN TAKE-OUT");
        lcd.noBlink();
      }

    else if ((BarcodeBuffer[0] == 'P') &&
         (BarcodeBuffer[1] == 'r') &&
         (BarcodeBuffer[2] == 'o') &&
         (BarcodeBuffer[3] == 'd') &&
         (BarcodeBuffer[4] == 'u') &&
         (BarcodeBuffer[5] == 'c') &&
         (BarcodeBuffer[6] == 't') &&
         (BarcodeBuffer[7] == '_') &&
         (BarcodeBuffer[8] == 'H')) 
      {
       /*
        IC1 = 11,13,8,9,85,7,10,t5
        IC2 = 5,3,4,6,Gr,0,0,0
        IC3 = 1,200,2,20,0,0,0,0
      */
        IC1 = B10011111;
        IC2 = B00011110;
        IC3 = B00000001;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
         lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Product_H");
        lcd.setCursor(0,1);
        lcd.print("EIGHT TAKE-OUT");
        lcd.noBlink();
      }
        
  else if ((BarcodeBuffer[0] == 'R') &&
       (BarcodeBuffer[1] == 'e') &&
       (BarcodeBuffer[2] == 's') && 
       (BarcodeBuffer[3] == 'e') && 
       (BarcodeBuffer[4] == 't') && 
       (BarcodeBuffer[5] == '_') && 
       (BarcodeBuffer[6] == 'b') && 
       (BarcodeBuffer[7] == 't') && 
       (BarcodeBuffer[8] == 'n'))
      
      {
         IC1 = B00000000;
         IC2 = B00000000;
         IC3 = B00000000;  
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("    S C A N  ");
         lcd.setCursor(0,1);
         lcd.print("    BARCODE     ");
  
      }
    else
      {
         IC1 = B00000000;
         IC2 = B00000000;
         IC3 = B00000000;  
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        lcd.setCursor(0,0);
         lcd.print("  No Data Found");
         lcd.setCursor(0,1);
         lcd.print("   REPEAT SCAN ");
  
      }
     
}


