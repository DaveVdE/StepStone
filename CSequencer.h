#pragma once

#include "CZone.h"

static uint8_t const NumberOfZones = 1;

class CSequencer
{
    private:
        CZone _zones[NumberOfZones];
        uint32_t _position;
        bool _running;

    public:
        const CZone* GetZone(uint8_t index) const
        {
            if (index < NumberOfZones)
            {
                return _zones + index;
            }

            return NULL;
        }

        void Start() 
        {
            _running = true;
            _position = 0;
        }

        void Stop()
        {
            _running = false;
        }

        void HandlePulse()
        {
            if (_running) ++_position;
        }

        uint32_t GetPosition() const
        {
            return _position;
        }
};