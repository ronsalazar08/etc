#include <hidboot.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif
byte Input, Output,Output1, Output2, Output3, Output4, Output5;

char BarcodeBuffer[5] = {0,0,0,0,0};       // Barcode scanner buffer
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
    Serial.println("LeftCtrl changed");
  }
  if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
    Serial.println("LeftShift changed");
  }
  if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
    Serial.println("LeftAlt changed");
  }
  if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
    Serial.println("LeftGUI changed");
  }p
  if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
    Serial.println("RightCtrl changed");
  }
  if (beforeMod.bmRightShift != afterMod.bmRightShift) {
    Serial.println("RightShift changed");
  }
  if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
    Serial.println("RightAlt changed");
  }
  if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
    Serial.println("RightGUI changed");
  }

}

void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)
{
 // Serial.print("UP ");
  //PrintKey(mod, key);
    if (key==10)                                                         
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
//  pinMode(9, OUTPUT);
  pinMode(52, OUTPUT);//clock
pinMode(51, OUTPUT);//data
pinMode(4, OUTPUT);//latch
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
  Output = B00000000;
        SPI.transfer(Output);
        digitalWrite(4, HIGH); // latch
        digitalWrite(4, LOW); // latch
        delay(50);
}

void loop()
{
 BarcodeBufferIndex = 0;
      while (!BarcodeComplete)
        {
          Usb.Task();
        }
      BarcodeComplete = false ;
      BarcodeBufferIndex --;
      Serial.write(BarcodeBuffer,BarcodeBufferIndex);
      Serial.write('\n');
      
     

      if ((BarcodeBuffer[0] == 'p') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == '-') && (BarcodeBuffer[4] == 'a')) 
      {
       // digitalWrite(9,HIGH);
        //Serial.println("ON");
        Output = B11111111;
        SPI.transfer(Output);
        digitalWrite(4, HIGH); // latch
        digitalWrite(4, LOW); // latch
        delay(50);
      }
       if ((BarcodeBuffer[0] == 'p') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == '-') && (BarcodeBuffer[4] == 'b')) 
      {
        Output = B0000010;
        SPI.transfer(Output);
        digitalWrite(4, HIGH); // latch
        digitalWrite(4, LOW); // latch
        delay(50);
      }
    if ((BarcodeBuffer[0] == 'p') && (BarcodeBuffer[1] == 'r') && (BarcodeBuffer[2] == 'o') && (BarcodeBuffer[3] == '-') && (BarcodeBuffer[4] == 'c')) 
      {
        Output = B0001000;
        SPI.transfer(Output);
        digitalWrite(4, HIGH); // latch
        digitalWrite(4, LOW); // latch
        delay(50);
      }
}


