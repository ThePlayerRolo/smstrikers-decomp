#ifndef _TLSLIDE_H_
#define _TLSLIDE_H_

#include "types.h"

#include "Game/FE/tlInstance.h"
#include "Game/FE/feAnimation.h"

class TLSlide
{
public:
    void Update(float);
    void UpdateAsset(TLInstance*, float);

    /* 0x00 */ TLSlide* m_next;
    /* 0x04 */ char pad0[0x4];
    /* 0x08 */ TLInstance* m_instances;
    /* 0x0C */ FEAnimation* m_animations;
    /* 0x10 */ f32 m_start;
    /* 0x14 */ f32 m_duration;
    /* 0x18 */ f32 m_time;
    /* 0x1C */ s32 m_wrapMode;
    /* 0x20 */ char pad20[0x20];
    /* 0x40 */ u32 m_hash;
};

#endif // _TLSLIDE_H_
