// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.

#include "FastLED.h"

#define NUM_STRIPS 3
#define NUM_LEDS_PER_STRIP 180
//CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];





CRGB una[NUM_LEDS_PER_STRIP];
CRGB gilid[NUM_LEDS_PER_STRIP];
CRGB likod[NUM_LEDS_PER_STRIP];
// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {

//     
//  // tell FastLED there's 60 NEOPIXEL leds on pin 10
//  FastLED.addLeds<NEOPIXEL, 4>(leds[0], NUM_LEDS_PER_STRIP);
//
//  // tell FastLED there's 60 NEOPIXEL leds on pin 11
//  FastLED.addLeds<NEOPIXEL, 6>(leds[1], NUM_LEDS_PER_STRIP);
//  
//  // tell FastLED there's 60 NEOPIXEL leds on pin 11
// FastLED.addLeds<NEOPIXEL, 8>(leds[2], NUM_LEDS_PER_STRIP);

  FastLED.addLeds<NEOPIXEL, 4>(una, NUM_LEDS_PER_STRIP);

  FastLED.addLeds<NEOPIXEL, 6>(gilid, NUM_LEDS_PER_STRIP);

  FastLED.addLeds<NEOPIXEL, 8>(likod, NUM_LEDS_PER_STRIP);



FastLED.setBrightness(60);


 una[33] = CRGB::White;
 FastLED.show();
}

void loop() {
  // This outer loop will go over each strip, one at a time
//  for(int x = 0; x < NUM_STRIPS; x++) {
//    // This inner loop will go over each led in the current strip, one at a time
//    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
//      leds[0][i] = CRGB::Red;
//      FastLED.show();
//      leds[0][i] = CRGB::Black;
//      
//      delay(100);
//      leds[1][i] = CRGB::Red;
//      FastLED.show();
//      leds[1][i] = CRGB::Black;
//      delay(100);
//    }
//  }
 int hood=31;  
 int hood1=31;
 int left=166;
 int right=0;
 int back ;

 una[31] = CRGB::White;
//back 
for( back = 0 ; back < 70; back++)
{
       likod[back] = CRGB::Red;
}
       FastLED.show();


//out     
for( int i = 41 ; i >= 0; i--){
static uint8_t hue = 0;
hue++;
hood--;
hood1++;
right = right+2;
left = left-2;
       una[hood] = CHSV(hue, 255, 255);
       una[hood1] = CHSV(hue, 255, 255);
       gilid[right]=CHSV(hue, 255, 255);
       gilid[right-1]=CHSV(hue, 255, 255);
       gilid[right-2]=CHSV(hue, 255, 255);
       gilid[right-3]=CHSV(hue, 255, 255);
       gilid[right-4]=CHSV(hue, 255, 255);
       gilid[left]=CHSV(hue, 255, 255);
       gilid[left+1]=CHSV(hue, 255, 255);
       gilid[left+2]=CHSV(hue, 255, 255);
       gilid[left+3]=CHSV(hue, 255, 255);
       gilid[left+4]=CHSV(hue, 255, 255);
       FastLED.show();
       gilid[right]= CRGB::Black;
       gilid[right-1]= CRGB::Black;
       gilid[right-2]= CRGB::Black;
       gilid[right-3]= CRGB::Black;
       gilid[right-4]= CRGB::Black;
       gilid[left]= CRGB::Black;
       gilid[left+1]= CRGB::Black;
       gilid[left+2]= CRGB::Black;
       gilid[left+3]= CRGB::Black;
       gilid[left+4]= CRGB::Black;
       if (hood==-11){
        
      right = 0;
      left = 166;
      hood = -3;
      hood1=65;
      for( int i = 41 ; i >= 0; i--)
        {
            hood++;
            hood1--;
          right = right+2;
          left = left-2;
          
 una[31] = CRGB::White;
       una[hood] = CRGB::Black;
       una[hood1] = CRGB::Black;
       gilid[right]=CHSV(hue, 255, 255);
       gilid[right-1]=CHSV(hue, 255, 255);
       gilid[right-2]=CHSV(hue, 255, 255);
       gilid[right-3]=CHSV(hue, 255, 255);
       gilid[right-4]=CHSV(hue, 255, 255);
       gilid[left]=CHSV(hue, 255, 255);
       gilid[left+1]=CHSV(hue, 255, 255);
       gilid[left+2]=CHSV(hue, 255, 255);
       gilid[left+3]=CHSV(hue, 255, 255);
       gilid[left+4]=CHSV(hue, 255, 255);
       FastLED.show();
       gilid[right]= CRGB::Black;
       gilid[right-1]= CRGB::Black;
       gilid[right-2]= CRGB::Black;
       gilid[right-3]= CRGB::Black;
       gilid[right-4]= CRGB::Black;
       gilid[left]= CRGB::Black;
       gilid[left+1]= CRGB::Black;
       gilid[left+2]= CRGB::Black;
       gilid[left+3]= CRGB::Black;
       gilid[left+4]= CRGB::Black;
       }
       
      break;
      
}

}












////out     
//for( hood ; hood >= 0; hood--){
//static uint8_t hue = 0;
//hue++;
//hood1++;
//       una[hood] = CHSV(hue, 255, 255);
//       una[hood1] = CHSV(hue, 255, 255);
//       FastLED.show();
//}
//
////in
//for( hood1 ; hood1 >= 0; hood1--){
//hood++;
//       una[hood] = CRGB::Black;
//       una[hood1] = CRGB::Black;
//       FastLED.show();
//}
//
////left&right
//for( right ; right < 83; right ++){
//static uint8_t hue = 0;
//hue++;
//left--;
//gilid[right] = CHSV(hue, 255, 255);
//gilid[left] = CHSV(hue, 255, 255);
//       FastLED.show();
//}
FastLED.clear();




}
