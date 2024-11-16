#include <Arduino.h>
#include <FastLED.h>
#include "OctoWS2811.h"
#include "teensy4controller.h"

const int numPins = 4;
byte pinList[numPins] = {0, 1, 2, 3};
const int ledsPerStrip = 2;
CRGB leds[numPins * ledsPerStrip];

// These buffers need to be large enough for all the pixels.
// The total number of pixels is "ledsPerStrip * numPins".
// Each pixel needs 3 bytes, so multiply by 3.  An "int" is
// 4 bytes, so divide by 4.  The array is created using "int"
// so the compiler will align it to 32 bit memory.
DMAMEM int displayMemory[ledsPerStrip * numPins * 3 / 4];
int drawingMemory[ledsPerStrip * numPins * 3 / 4];
OctoWS2811 octo(ledsPerStrip, displayMemory, drawingMemory, WS2811_RGB | WS2811_800kHz, numPins, pinList);

CTeensy4Controller<RGB, WS2811_800kHz> *pcontroller;

void setup()
{

  octo.begin();
  pcontroller = new CTeensy4Controller<RGB,WS2811_800kHz>(&octo);

  FastLED.setBrightness(255);
  FastLED.addLeds(pcontroller, leds, numPins * ledsPerStrip);
}

void loop()
{
  uint16_t x;
  int scale;
  uint16_t t;

  x = 0;
  t = millis() / 5;
  scale = 10;

  for (uint32_t i = 0; i < (numPins * ledsPerStrip); i++)
  {
    uint8_t noise = inoise8(i * scale + x, t);
    uint8_t hue = map(noise, 50, 190, 0, 255);
    leds[i] = CHSV(hue, 255, 64);
  }

  FastLED.show();

}
