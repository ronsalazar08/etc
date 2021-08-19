#include <hidboot.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif
byte IC1,IC2,IC3,IC4,IC5,IC6;

char BarcodeBuffer[9] = {0,0,0,0,0,0,0,0,0};       // Barcode scanner buffer
int BarcodeBufferIndex = 0 ;                                              // Pointer barcode scanner buffer
boolean BarcodeComplete = false ;                                         // Scan complete?
class KbdRptParser : public KeyboardReportParser
{
    void PrintKey(uint8_t mod, uint8_t key);

  protected:
    void OnControlKeysChanged(uint8_t before, uint8_t after);

    void OnKeyDown	(uint8_t mod, uint8_t key);
    void OnKeyUp	(uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);
};

void KbdRptParser::PrintKey(uint8_t m, uint8_t key)
{
  MODIFIERKEYS mod;
  *((uint8_t*)&mod) = m;
  Serial.print((mod.bmLeftCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmLeftShift  == 1) ? "S" : " ");
  Serial.print((mod.bmLeftAlt    == 1) ? "A" : " ");
  Serial.print((mod.bmLeftGUI    == 1) ? "G" : " ");

  Serial.print(" >");
  PrintHex<uint8_t>(key, 0x80);
  Serial.print("< ");

  Serial.print((mod.bmRightCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmRightShift  == 1) ? "S" : " ");
  Serial.print((mod.bmRightAlt    == 1) ? "A" : " ");
  Serial.println((mod.bmRightGUI    == 1) ? "G" : " ");
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
 // Serial.print("DN ");
 // PrintKey(mod, key);
  uint8_t c = OemToAscii(mod, key);

  if (c)
    OnKeyPressed(c);
}

void KbdRptParser::OnControlKeysChanged(uint8_t before, uint8_t after) {

  MODIFIERKEYS beforeMod;
  *((uint8_t*)&beforeMod) = before;

  MODIFIERKEYS afterMod;
  *((uint8_t*)&afterMod) = after;

  if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
    //Serial.println("LeftCtrl changed");
  }
  if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
    //Serial.println("LeftShift changed");
  }
  if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
    //Serial.println("LeftAlt changed");
  }
  if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
   // Serial.println("LeftGUI changed");
  }
  if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
    //Serial.println("RightCtrl changed");
  }
  if (beforeMod.bmRightShift != afterMod.bmRightShift) {
   // Serial.println("RightShift changed");
  }
  if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
   // Serial.println("RightAlt changed");
  }
  if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
    //Serial.println("RightGUI changed");
  }

}

void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)
{
 // Serial.print("UP ");
  //PrintKey(mod, key);
    if (key==25)                                                         
        {                                                                  // check for "enter" new line this is end of barcode
          BarcodeComplete = true ;
        }
}

void KbdRptParser::OnKeyPressed(uint8_t key)
{
/*//Serial.print("ASCII: ");
 char i = ((char)key);
 if ( i = '1'){
  Serial.print("OLO");
  digitalWrite(9, HIGH);
 }*/
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
  IC1 = B00000000;
  IC2 = B00000000;
  IC3 = B00000000;
        SPI.transfer(IC1);
        SPI.transfer(IC2);
        SPI.transfer(IC3); 
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
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
      
     

      if ((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'A')) 
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
        
      }
       if ((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'B'))
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
        
      }
    if ((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'C'))
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
        
      }
       if ((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'D'))
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
        
      }
         if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'E'))
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
        
      }
if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'F'))
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
      }
if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'G'))
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
        
      }

          if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'H'))
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
        
      }
         /* if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'I'))
      {
        
        IC1 = B00010100;
        IC2 = B00000000;
        IC3 = B00000000;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }
          if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'J'))
      {
        
        IC1 = B00011000;
        IC2 = B00000000;
        IC3 = B00000000;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }
     


//=======================
      
               if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'K'))
      {
        
        IC1 = B00000000;
        IC2 = B00011111;
        IC3 = B00000000;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }

             if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'L'))
      {
        
        IC1 = B00000000; 
        IC2 = B00001010;
        IC3 = B00000000;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }

          if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'M'))
      {
        
        IC1 = B00000000;
        IC2 = B00001101;
        IC3 = B00000000;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }
          if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'N'))
      {
        
        IC1 = B00000000;
        IC2 = B00001010;
        IC3 = B00000000;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }
          if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'O'))
      {
        
        IC1 = B00000000;
        IC2 = B00000100;
        IC3 = B00000000;
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }


     //================
      
               if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'P'))
      {
        
        IC1 = B00000000;
        IC2 = B00000000;
        IC3 = B00011111; 
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }

             if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'Q'))
      {
        
        IC1 = B00000000;
        IC2 = B00000000; 
        IC3 = B00010101;  
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }

          if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'R'))
      {
        
        IC1 = B00000000;
        IC2 = B00000000; 
        IC3 = B00001011;  
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }
          if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'S'))
      {
        
        IC1 = B00000000;
        IC2 = B00000000; 
        IC3 = B00011110;  
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }
          if((BarcodeBuffer[0] == 'P') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == 'd') && (BarcodeBuffer[4] == 'u') && (BarcodeBuffer[5] == 'c') && (BarcodeBuffer[6] == 't') && (BarcodeBuffer[7] == '_') && (BarcodeBuffer[8] == 'T'))
      {
        
        IC1 = B00000000;
        IC2 = B00000000; 
        IC3 = B00000011;  
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }*/
          if ((BarcodeBuffer[0] == 'R') && (BarcodeBuffer[1] == 'e') && (BarcodeBuffer[2] == 's') && (BarcodeBuffer[3] == 'e') && (BarcodeBuffer[4] == 't') && (BarcodeBuffer[5] == '_') && (BarcodeBuffer[6] == 'b') && (BarcodeBuffer[7] == 't') && (BarcodeBuffer[8] == 'n'))
      {
         IC1 = B00000000;
         IC2 = B00000000;
         IC3 = B00000000;  
        SPI.transfer(IC3);
        SPI.transfer(IC2);
        SPI.transfer(IC1);
        digitalWrite(22, HIGH); // latch
        digitalWrite(22, LOW); // latch
        
      }
     
}


