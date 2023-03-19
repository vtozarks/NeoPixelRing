//================================================================================
// Example NeoPixel code for Arduino Nano using FastLED library
// Library Manager: DastLED by Daniel Garcia V3.5.0 
//                  https://github.com/FastLED/FastLED
//================================================================================
#include <FastLED.h>

#define NUM_LEDS 8    //<- Number of LEDs on Ring
#define DATA_PIN 3    //<- Arduino Nano pin for "Data" output

CRGB leds[NUM_LEDS];    //<- FastLED required array for LEDs

//=================================================================================
// Setup before main loop
//   - assume AdaFruit NeoPixel (WS2812 / GRB ordering )
//=================================================================================
void setup() 
{ 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  
}

//=================================================================================
// Main loop 
//   - Nexted loops for brightness -> Color -> LED position
//=================================================================================
void loop() 
{ 

  HSVHue colors[3];
  colors[0] = HUE_RED;
  colors[1] = HUE_GREEN;
  colors[2] = HUE_BLUE;

  //___ Brightness ________________________________________________________________
  for (int brightness = 0x10; brightness < 0x100; brightness+= 0x10)
  {
    //___ Color ___________________________________________________________________
    for (int colorIdx = 0; colorIdx < 3; colorIdx++)
    {
      //___ LED position __________________________________________________________
      for (int ledIdx = 0; ledIdx < 8; ledIdx++)
      {
        //___ Turn LEDs on ________________________________________________________
        leds[ledIdx] = CHSV(colors[colorIdx], 255, brightness);
        FastLED.show();
        delay(25);

        //___ Turn off LEDs _______________________________________________________
        leds[ledIdx] = CRGB::Black;
        FastLED.show();
        delay(5);
      }
    }
  }



}

