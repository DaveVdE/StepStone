#pragma once

#include <Arduino.h>
#include "CStep.h"

// A lane describes a row of steps.
class CLane 
{
    public:
        static uint8_t const MaximumLaneLength = 8;
        static uint8_t const DefaultStepLength = 12;

    private:
        uint8_t _laneLength; // The number of steps actually played on this lane. Cannot exceed MAX_STEPS.
        uint8_t _stepLength; // The number of ppqn each step represents. For example, 24 for 1/4, 12 for 1/8, 6 for 1/16.
        uint8_t _noteNumber; // The currently assigned MIDI note number that should be played when triggered.

        // MIDI note numbers are easy. Center pitch (A4) is 69. One octave up = +12, one octave down = -12. Easy.

        CStep _steps[MaximumLaneLength]; // All of the steps for this lane.

    public:
        CLane(): _laneLength(MaximumLaneLength), _stepLength(12)
        {
        }

        // Fetches the step at the given pulse. If no step is present at this pulse, NULL is returned.
        CStep* FetchStepAtPulse(uint32_t pulse) 
        {
            uint8_t pulseInLane = pulse % (_laneLength * _stepLength);

            if (pulseInLane % _stepLength == 0) 
            {
                uint8_t index = pulseInLane / _stepLength;
                return &_steps[index];
            }

            return NULL;
        }

        uint8_t LaneLength() 
        {
            return _laneLength;
        }

        void LaneLength(uint8_t laneLength)
        {
            _laneLength = laneLength;
        }

        uint8_t StepLength()
        {
            return _stepLength;
        }

        void StepLength(uint8_t stepLength) 
        {
            _stepLength = stepLength;
        }

        uint8_t NoteNumber() 
        {
            return _noteNumber;
        }

        void NoteNumber(uint8_t noteNumber)
        {
            _noteNumber = noteNumber;
        }
};