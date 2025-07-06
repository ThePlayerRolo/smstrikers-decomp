#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "NL/nlDLRing.h"

// void nlDLRingAppendRing<Clock>(Clock**, Clock*);
// void nlDLRingRemoveSafely<Clock>(Clock**, const Clock*);
// void nlDLRingValidateContainsElement<Clock>(Clock*, const Clock*);
// void nlDLRingRemove<Clock>(Clock**, Clock*);
// void nlDLRingAddEnd<Clock>(Clock**, Clock*);
// void nlDLRingAddStart<Clock>(Clock**, Clock*);

typedef void (*ClockCallback)(unsigned long, unsigned long);

class Clock
{
public:
    void Stop();
    void Start();
    void Reset(float, float, float);
    virtual ~Clock();
    Clock(float, float, float, unsigned long, ClockCallback);

    /* 0x04 */ float m_unk_0x04;
    /* 0x08 */ float m_unk_0x08;
    /* 0x0C */ float m_unk_0x0C;
    /* 0x10 */ ClockCallback m_callback;
    /* 0x14 */ unsigned long m_unk_0x14;
    /* 0x18 */ s32 m_unk_0x18;

    /* 0x1C */ unsigned long m_unk_0x1C;
    /* 0x20 */ unsigned long m_unk_0x20;

    /* 0x24 */ Clock* m_next;
    /* 0x28 */ Clock* m_prev;
};


class ClockManager
{
public:
    void Update(float);
    void Initialize();

    /* 0x00 */ static Clock* m_inactiveList;
    /* 0x04 */ static Clock* m_activeList;
    /* 0x08 */ static Clock* m_pendingActiveList;
    /* 0x0C */ static bool m_bUpdatingClocks;
};

#endif // _CLOCK_H_
