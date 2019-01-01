#ifndef CGRID_INCLUDED
#define CGRID_INCLUDED

#include <Adafruit_NeoPixel.h>
#include "CSequencer.h"

#define PIN 10

static uint8_t GridRows = 4;
static uint8_t GridColumns = 8;

class CGrid
{
    private:
        const CSequencer& _sequencer;
        Adafruit_NeoPixel _strip = Adafruit_NeoPixel(32, PIN, NEO_GRB + NEO_KHZ800);

    public:
        CGrid(const CSequencer& sequencer) : _sequencer(sequencer)
        {
        }

        void initialize()
        {
            _strip.begin();
            _strip.show();
            _strip.setBrightness(31);
        }

        void render()
        {
            auto on = _strip.Color(255, 255, 255);
            auto off = _strip.Color(0, 0, 0);
            auto position = _sequencer.position();

            for (uint8_t row = 0; row < GridRows; ++row)
            {
                auto lane = _sequencer.zone(0)->lane(row);
                auto index = lane->CalculateStepIndex(position);
                auto offset = row * GridColumns;

                for (uint8_t column = 0; column < GridColumns; ++column)
                {
                    auto coordinate = offset + column;

                    if (column == index)
                    {
                        _strip.setPixelColor(coordinate, on);
                    }
                    else
                    {
                        _strip.setPixelColor(coordinate, off);
                    }
                }
            }

            _strip.show();
        }
};

#endif