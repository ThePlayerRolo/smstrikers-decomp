#ifndef _SANIM_H_
#define _SANIM_H_

#include "types.h"

#include "NL/nlMath.h"
// #include "NL/nlList.h"

#include "PoseAccumulator.h"

typedef struct cSAnimCallback
{
    /* 0x00 */ f32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ void (*unk8)(unsigned int);
    /* 0x0C */ cSAnimCallback* next;
} cSAnimCallback; // size: 0x10

struct nlChunk
{
};

class cSAnim
{
public:
    void GetMorphWeight(int, float) const;
    void CreateCallback(float, unsigned int, void (*)(unsigned int));
    void GetRootTrans(float, nlVector3*) const;
    void GetRootRot(float, unsigned short*) const;
    void Destroy();
    void BlendTrans(int, int, float, float, cPoseAccumulator*, bool) const;
    void BlendScale(int, int, float, float, cPoseAccumulator*, bool) const;
    void BlendRot(int, int, float, float, cPoseAccumulator*, bool) const;

    static cSAnim* Initialize(nlChunk*);

    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ char pad10[4];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ char pad30[4];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ cSAnimCallback* m_unk_0x3C;
};

#endif // _SANIM_H_
