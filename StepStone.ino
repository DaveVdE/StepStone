#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoTrellisM4.h>
#include "MIDIUSB.h"

#define PIN 10

Adafruit_NeoPixel strip = Adafruit_NeoPixel(32, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoTrellisM4 trellis = Adafruit_NeoTrellisM4();


void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(31);
  //trellis.enableUSBMIDI(true); 
}

uint32_t counter = 0;

void loop() {
  midiEventPacket_t rx;

  do 
  {
      rx = MidiUSB.read();

      if (rx.byte1 == 0xFA)
      {
        counter = 0;
      }

      if (rx.byte1 == 0xF8)
      {
        if (counter % 24 == 0)
        {
          strip.setPixelColor(0, strip.Color(255, 255, 255));
        }
        else {
          strip.setPixelColor(0, 0);
        }

        strip.show();

        ++counter;
      }
  }
  while (rx.header != 0);
}
