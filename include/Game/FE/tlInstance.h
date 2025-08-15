#ifndef _TLINSTANCE_H_
#define _TLINSTANCE_H_

#include "NL/nlColour.h"

#include "Game/FE/feLibObject.h"

class TLInstance
{
public:
    void SetAssetColour(const nlColour&);
    void SetAssetScale(float, float, float);
    void SetAssetRotation(float, float, float);
    void SetAssetPosition(float, float, float);
    void IsValidAtTime(float);
    void GetColour() const;
    void GetScale() const;
    void GetRotation() const;
    void GetPosition() const;
    void GetAssetColour() const;
    void GetAssetScale() const;
    void GetAssetPosition() const;

    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ FELibObject* unkC; /* inferred */
    /* 0x10 */ f32 unk10;         /* inferred */
    /* 0x14 */ f32 unk14;         /* inferred */
    /* 0x18 */ char pad18[0x24];  /* maybe part of unk14[0xA]? */
    /* 0x3C */ f32 unk3C;         /* inferred */
    /* 0x40 */ f32 unk40;         /* inferred */
    /* 0x44 */ f32 unk44;         /* inferred */
    /* 0x48 */ f32 unk48;         /* inferred */
    /* 0x4C */ f32 unk4C;         /* inferred */
    /* 0x50 */ f32 unk50;         /* inferred */
    /* 0x54 */ f32 unk54;         /* inferred */
    /* 0x58 */ f32 unk58;         /* inferred */
    /* 0x5C */ f32 unk5C;         /* inferred */
    /* 0x60 */ u8 unk60[0x14];    /* inferred */
    /* 0x74 */ s32 unk74;         /* inferred */
    // #pragma pack(pop)
};

#endif // _TLINSTANCE_H_
