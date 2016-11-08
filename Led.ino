#include "FastLED.h"

#define NUMLEDS 130

CRGB leds[NUMLEDS];
int mode = 1;
unsigned long last;

void setupLeds()
{
  FastLED.addLeds<WS2812B, 2, GRB>(leds, NUMLEDS);
  FastLED.setBrightness(20);
  last = micros();
}

void loopLeds()
{
  unsigned long now = micros();
  while(((signed long)(now - last)) > 0)
  {
    animationStep();
    last += 20000;
  }
}

int phase;
void animationStep()
{
  switch(mode)
  {
    case 1:
    {
      FastLED.setBrightness(100);
      phase++;
      phase %= NUMLEDS;
      for(int i = 0; i < NUMLEDS; i++) {
        leds[i] = CHSV(((i + phase) % NUMLEDS) * 255 / NUMLEDS, 255, 255);
      }
      break;
    }
    case 2:
    {
      FastLED.setBrightness(255);
      phase++;
      phase %= NUMLEDS;
      //fadeLightBy(leds, NUMLEDS, 50);
      fadeToBlackBy(leds, NUMLEDS, 50);
      leds[phase] = CHSV(random8(), 192, 255);
      break;
    }
    case 3:
    {
      FastLED.setBrightness(20);
      break;
    }
    case 4:
    {
      return;
    }
    default:
    {
      FastLED.setBrightness(20);
      for(int i = 0; i < NUMLEDS; i++) {
        leds[i] = CRGB::Black;
      }
    }
  }
  FastLED.show();  
}

