#ifndef _SHHEALTHWARNING_H_
#define _SHHEALTHWARNING_H_

#include "types.h"
#include "Game/BaseSceneHandler.h"
#include "Game/FE/feAsyncImage.h"

class HealthWarningSceneV2 : public BaseSceneHandler
{
public:
    HealthWarningSceneV2();
    virtual ~HealthWarningSceneV2();
    virtual void SceneCreated();
    virtual void Update(float);

    // /* 0x04 */ char pad4[4];
    // /* 0x08 */ bool unk8;
    // /* 0x09 */ char pad9[3];
    // /* 0x0C */ s32 unkC;
    // /* 0x10 */ s32 unk10;
    // /* 0x14 */ void* unk14;
    // /* 0x18 */ s32 unk18;
    /* 0x1C */ AsyncImage* m_unk_0x1C;
    /* 0x20 */ AsyncImage* m_unk_0x20;
    /* 0x24 */ f32 m_unk_0x24;
    /* 0x28 */ u8 m_unk_0x28;
};

// class FEFinder<TLImageInstance, 2>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class FEFinder<TLComponentInstance, 4>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

#endif // _SHHEALTHWARNING_H_
