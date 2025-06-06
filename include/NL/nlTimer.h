#ifndef _NLTIMER_H_
#define _NLTIMER_H_

#include "types.h"

class Timer
{
public:
    u32 Countup(float, float);
    u32 Countdown(float, float);
    f32 GetSeconds() const;
    void SetSeconds(float);

    unsigned int _unk_0x0;
    float _unk_0x4;
    double _unk_0x8;
};

#endif // _NLTIMER_H_
