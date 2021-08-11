#include <usbhid.h>
#include <hiduniversal.h>
#include <Usb.h>
#include <hidboot.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

#include "FastLED.h"

#define NUM_LEDS 300          //heto ang bilang ng LED
#define DATA_PIN 12
#define BRIGHTNESS 10        //Heto yung adjustment ng brightness

CRGB leds[NUM_LEDS];

char BarcodeBuffer[20];
int BarcodeBufferIndex = 0 ;                                            
boolean BarcodeComplete = false ;


                                        
class KbdRptParser : public KeyboardReportParser
{
  
  
  protected:
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
USBHub     Hub(&Usb);
HIDUniversal      Hid(&Usb);  
//HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
uint32_t next_time;
KbdRptParser Prs;
void setup() {

Serial.begin( 115200 );

#if !defined(__MIPSEL__)
while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif

  
  Serial.println("Start");
  if (Usb.Init() == -1)
  Serial.println("OSC did not start.");
  delay( 200 );
  next_time = millis() + 5000;
  //HidKeyboard.SetReportParser(0, &Prs);
  Hid.SetReportParser(0, (HIDReportParser*)&Prs);
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

 
    clearLED();

 
}
void loop() {

  BarcodeBufferIndex = 0;
  while (BarcodeComplete == false) {
    Usb.Task();
  }
  BarcodeComplete = false ;
  BarcodeBufferIndex --;
  Serial.write(BarcodeBuffer,BarcodeBufferIndex);
  Serial.write('\n');
  String myString = (char*)BarcodeBuffer;           //set array as string
  int c = myString.length()-1;                      //get last index of string
  myString.remove(c);                               //remove last index of string
  memset(BarcodeBuffer, 0, sizeof(BarcodeBuffer));  // reset array index to none
  
  if (myString == "SE" || myString == "SD") {
    clearLED();
    delay(10);
     leds[121] = CRGB::Blue;leds[122] = CRGB::Blue;
     leds[125] = CRGB::Blue;leds[126] = CRGB::Blue;
     leds[129] = CRGB::Blue;leds[130] = CRGB::Blue;
     leds[117] = CRGB::Blue;leds[118] = CRGB::Blue;
     leds[113] = CRGB::Blue;leds[114] = CRGB::Blue;
     leds[109] = CRGB::Blue;leds[110] = CRGB::Blue;
     leds[197] = CRGB::Blue;leds[198] = CRGB::Blue;
     leds[193] = CRGB::Blue;leds[194] = CRGB::Blue;
     leds[221] = CRGB::Blue;leds[222] = CRGB::Blue;
     FastLED.show();
  } else if (myString == "RC") {
    clearLED();
    delay(10);
    leds[41] = CRGB::Blue;leds[42] = CRGB::Blue;
    leds[45] = CRGB::Blue;leds[46] = CRGB::Blue;
    leds[49] = CRGB::Blue;leds[50] = CRGB::Blue;
    leds[133] = CRGB::Blue;leds[134] = CRGB::Blue;
    leds[137] = CRGB::Blue;leds[138] = CRGB::Blue;
    leds[141] = CRGB::Blue;leds[142] = CRGB::Blue;
    leds[145] = CRGB::Blue;leds[146] = CRGB::Blue;
    leds[209] = CRGB::Blue;leds[210] = CRGB::Blue;
    leds[213] = CRGB::Blue;leds[214] = CRGB::Blue;
    leds[185] = CRGB::Blue;leds[186] = CRGB::Blue;
    leds[189] = CRGB::Blue;leds[190] = CRGB::Blue;
     FastLED.show();
  } else if (myString == "PC") {
    clearLED();
    delay(10);
    leds[149] = CRGB::Blue;leds[150] = CRGB::Blue;
    leds[153] = CRGB::Blue;leds[154] = CRGB::Blue;
    leds[157] = CRGB::Blue;leds[158] = CRGB::Blue;
    leds[65] = CRGB::Blue;leds[66] = CRGB::Blue;
    leds[69] = CRGB::Blue;leds[70] = CRGB::Blue;
    leds[73] = CRGB::Blue;leds[74] = CRGB::Blue;
     
     FastLED.show();
  }
  
  if (myString == "SS") {
    clearLED();
    delay(10);
  }  

}

void clearLED(){
  
    for (int j=0;j <= 300; j++) {
     leds[j] = CRGB::Black;
   } 
     
     FastLED.show();
     FastLED.clear();
}
