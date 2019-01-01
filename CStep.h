#ifndef CSTEP_INCLUDED
#define CSTEP_INCLUDED

// Represents a step in a lane. At this time, the step only signifies whether it should trigger or not.
class CStep 
{
    private:
        bool _trigger;

    public:
        CStep() : _trigger(false)
        {
        }

        bool trigger() 
        {
            return _trigger;
        }

        void trigger(bool trigger) 
        {
            _trigger = trigger;
        }
};

#endif