/*
 
Portable barcode scanner. Uses USB HID barcode scanner, Arduino Board, USB Host Shield and HD44780-compatible LCD display
 
  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
*/
 
#include <hid.h>
#include <hiduniversal.h>
#include <LiquidCrystal.h>
#include <avr/pgmspace.h>
/*#include <avrpins.h>
#include <max3421e.h>
#include <usbhost.h>
#include <usb_ch9.h>*/
#include <Usb.h>
#include <usbhub.h>
#include <avr/pgmspace.h>
//#include <address.h>
#include <hidboot.h>
 /*
#include <printhex.h>
#include <message.h>
#include <hexdump.h>
#include <parsetools.h>
 */
#define DISPLAY_WIDTH 16
 
// initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 
USB     Usb;
USBHub     Hub(&Usb);
HIDUniversal  Hid(&Usb);
HIDBoot<HID_PROTOCOL_KEYBOARD>    Keyboard(&Usb);
 
class KbdRptParser : public KeyboardReportParser
{
  void PrintKey(uint8_t mod, uint8_t key);
protected:
  virtual void OnKeyDown  (uint8_t mod, uint8_t key);
  virtual void OnKeyPressed(uint8_t key);
};
 
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)  
{
    uint8_t c = OemToAscii(mod, key);
 
    if (c)
        OnKeyPressed(c);
}
 
/* what to do when symbol arrives */
void KbdRptParser::OnKeyPressed(uint8_t key)  
{
static uint32_t next_time = 0;      //watchdog
static uint8_t current_cursor = 0;  //tracks current cursor position  
 
    if( millis() > next_time ) {
      lcd.clear();
      current_cursor = 0;
      delay( 5 );  //LCD-specific 
      lcd.setCursor( 0,0 );
    }//if( millis() > next_time ...
 
    next_time = millis() + 200;  //reset watchdog
 
    if( current_cursor++ == ( DISPLAY_WIDTH + 1 )) {  //switch to second line if cursor outside the screen
      lcd.setCursor( 0,1 );
    }
 
    Serial.println((char)key );
    lcd.print( (char)key );
};
 
KbdRptParser Prs;
 
void setup()
{
    Serial.begin( 115200 );
    Serial.println("Start");
 
    if (Usb.Init() == -1) {
        Serial.println("OSC did not start.");
    }
 
    delay( 200 );
 
    Hid.SetReportParser(0, (HIDReportParser*)&Prs);
    // set up the LCD's number of columns and rows: 
    lcd.begin(DISPLAY_WIDTH, 2);
    lcd.clear();
    lcd.noAutoscroll();
    lcd.print("Ready");
    delay( 200 );
}
 
void loop()
{
  Usb.Task();
}
