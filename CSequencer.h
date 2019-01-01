#ifndef CSEQUENCER_INCLUDED
#define CSEQUENCER_INCLUDED

#include "CZone.h"

static uint8_t const NumberOfZones = 1;

class CSequencer
{
    private:
        CZone _zones[NumberOfZones];
        uint32_t _position;
        bool _running;

    public:
        const CZone* zone(uint8_t index) const
        {
            if (index < NumberOfZones)
            {
                return _zones + index;
            }

            return NULL;
        }

        uint32_t position() const
        {
            return _position;
        }

        bool running() const
        {
            return _running;
        }

        void start() 
        {
            _running = true;
            _position = 0;
        }

        void stop()
        {
            _running = false;
        }

        void handlePulse()
        {
            if (_running) ++_position;
        }
};

#endif