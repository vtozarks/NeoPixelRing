/// @file    Blink.ino
/// @brief   Blink the first LED of an LED strip
/// @example Blink.ino

#include <FastLED.h>

#define NUM_LEDS 8
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

//================================================================
// Setup before main loop
//   - assume AdaFruit NeoPixel (WS2812 / GRB ordering )
//================================================================
void setup() 
{ 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  
}

void loop() 
{ 

  HSVHue colors[3];
  colors[0] = HUE_RED;
  colors[1] = HUE_GREEN;
  colors[2] = HUE_BLUE;

  for (int brightness = 0x10; brightness < 0x100; brightness+= 0x10)
  {
    for (int colorIdx = 0; colorIdx < 3; colorIdx++)
    {
      for (int ledIdx = 0; ledIdx < 8; ledIdx++)
      {
        //___ Turn LEDs on ______________________________________________
        leds[ledIdx] = CHSV(colors[colorIdx], 255, brightness);
        FastLED.show();
        delay(25);

        //___ Turn off LEDs _____________________________________________
        leds[ledIdx] = CRGB::Black;
        FastLED.show();
        delay(5);

      }
    }
  }



}

