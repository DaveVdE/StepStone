#pragma once

#include <Arduino.h>

// Represents a step in a lane. At this time, the step only signifies whether it should trigger or not.
class CStep 
{
    private:
        bool _trigger;

    public:
        CStep() : _trigger(false)
        {
        }

        bool Trigger() 
        {
            return _trigger;
        }

        void Trigger(bool trigger) 
        {
            _trigger = trigger;
        }
};
