#ifndef _FEANIMATION_H_
#define _FEANIMATION_H_

#include "types.h"

#include "Game/FE/tlInstance.h"
#include "NL/nlDLRing.h"

typedef struct fAnimationKeyframe
{
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ fAnimationKeyframe* m_next;
    /* 0x14 */ fAnimationKeyframe* m_prev;
} fAnimationKeyframe; /* size >= 0x18 */

typedef struct v3AnimationKeyframe
{
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ v3AnimationKeyframe* m_next;
    /* 0x34 */ v3AnimationKeyframe* m_prev;
} v3AnimationKeyframe; /* size >= 0x38 */

class FEAnimation /* size >= 0x1C */
{
public:
    void Update(float);
    void AnimateTargetAtTimeWithVector3(float);

    /* 0x00 */ char pad0[4];
    /* 0x04 */ FEAnimation* m_next;
    /* 0x08 */ char pad8[4]; // probably m_prev
    /* 0x0C */ TLInstance* m_instance;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ char pad12[2];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ void* m_DLRingHead;
};

// // Template function declarations
// template <typename T>
// T* nlDLRingGetStart(T* current);

// template <typename T>
// bool nlDLRingIsEnd(T* head, T* current);

#endif // _FEANIMATION_H_
