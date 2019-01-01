#ifndef CZONE_INCLUDED
#define CZONE_INCLUDED

#include "CLane.h"

static uint8_t const NumberOfLanes = 4;

class CZone
{
    private:
        CLane _lanes[NumberOfLanes];

    public:
        // Preset the step length or lane length for demonstration purpose.
        // CZone()
        // {
        //     _lanes[0].LaneLength(8);
        //     _lanes[1].LaneLength(6);
        //     _lanes[2].LaneLength(4);
        //     _lanes[3].LaneLength(2);
        // }

        const CLane* lane(uint8_t index) const
        {
            if (index < NumberOfLanes) 
            {
                return _lanes + index;
            }

            return NULL;
        }
};

#endif