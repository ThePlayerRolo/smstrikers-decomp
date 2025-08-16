#ifndef _TLSLIDE_H_
#define _TLSLIDE_H_

#include "types.h"

#include "Game/FE/tlInstance.h"
// #include "Game/FE/feAnimation.h"

#include "NL/nlDLRing.h"

// void nlDLRingIsEnd<TLInstance>(TLInstance*, TLInstance*);
// void nlDLRingGetStart<TLInstance>(TLInstance*);

class FEAnimation;

class TLSlide
{
public:
    void Update(float);
    void UpdateAsset(TLInstance*, float);

    /* 0x00 */ TLSlide* m_next;
    /* 0x04 */ char pad0[0x4];
    /* 0x08 */ TLInstance* unk8;
    /* 0x0C */ FEAnimation* unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ char pad20[0x20];
    /* 0x40 */ u32 m_hash;
};

// /* 0x00 */ char pad0[0x08];
// /* 0x08 */ TLInstance* m_instances;   // linked-ring head of TLInstance
// /* 0x0C */ FEAnimation* m_animations; // linked-ring head of FEAnimation
// /* 0x10 */ f32 m_start;               // start time (sec)
// /* 0x14 */ f32 m_duration;            // duration (sec)
// /* 0x18 */ f32 m_time;                // current slide-local time
// /* 0x1C */ s32 m_wrapMode;            // 0 = clamp, 1 = loop (others: unknown)

#endif // _TLSLIDE_H_
