#ifndef _TLINSTANCE_H_
#define _TLINSTANCE_H_

#include "NL/nlColour.h"
#include "NL/nlMath.h"

#include "Game/FE/feLibObject.h"

class TLInstance
{
public:
    void SetAssetColour(const nlColour&);
    void SetAssetScale(float, float, float);
    void SetAssetRotation(float, float, float);
    void SetAssetPosition(float, float, float);
    bool IsValidAtTime(float);
    nlColour* GetColour() const;
    nlVector3* GetScale() const;
    nlVector3* GetRotation() const;
    nlVector3* GetPosition() const;
    nlColour* GetAssetColour() const;
    nlVector3* GetAssetScale() const;
    nlVector3* GetAssetPosition() const;

    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ FELibObject* unkC; /* inferred */
    /* 0x10 */ f32 m_start;       /* inferred */
    /* 0x14 */ f32 m_duration;    /* inferred */
    /* 0x18 */ char pad18[0x24];  /* maybe part of unk14[0xA]? */
    /* 0x3C */ nlVector3 unk3C;
    /* 0x48 */ nlVector3 unk48;
    /* 0x54 */ nlVector3 unk54;
    /* 0x60 */ u8 unk60[0x14]; /* inferred */
    /* 0x74 */ s32 unk74;      /* inferred */
    // #pragma pack(pop)
};

#endif // _TLINSTANCE_H_
