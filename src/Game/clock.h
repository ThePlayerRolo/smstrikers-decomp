#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "NL/nlDLRing.h"

// void nlDLRingAppendRing<Clock>(Clock**, Clock*);
// void nlDLRingRemoveSafely<Clock>(Clock**, const Clock*);
// void nlDLRingValidateContainsElement<Clock>(Clock*, const Clock*);
// void nlDLRingRemove<Clock>(Clock**, Clock*);
// void nlDLRingAddEnd<Clock>(Clock**, Clock*);
// void nlDLRingAddStart<Clock>(Clock**, Clock*);

class Clock
{
public:
    void Stop();
    void Start();
    void Reset(float, float, float);
    ~Clock();
    Clock(float, float, float, unsigned long, void (*)(unsigned long, unsigned long));
};


class ClockManager
{
public:
    void Update(float);
    void Initialize();
};

#endif // _CLOCK_H_
