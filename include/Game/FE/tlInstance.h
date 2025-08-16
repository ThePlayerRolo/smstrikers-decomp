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
    /* 0x60 */ u8 pad78[0x8];  /* inferred */

    // /* 0x00 */ char pad0[0x0C];
    // /* 0x0C */ TLComponent* m_component; // owner; used by TLComponentInstance
    // /* 0x10 */ f32 m_start;              // start time (sec)
    // /* 0x14 */ f32 m_duration;           // duration (sec)
    // /* 0x18 */ char pad18[0x24];         // transform/flags block part
    // /* 0x3C */ nlVector3 m_pos;          // inferred: GetPosition() uses this
    // /* 0x48 */ nlVector3 m_rot;          // inferred
    // /* 0x54 */ nlVector3 m_scale;        // inferred
    // /* 0x60 */ u8 unk60[0x14];           // colour/flags spill
    // /* 0x74 */ s32 m_flags;              // includes bitfield used by SetAssetColour
    // /* 0x78 */ u8 pad78[0x06];           // alignment/unknown
    // /* 0x7E */ u8 m_enableSoundTriggers; // checked by TLComponentInstance::Update
    // /* 0x7F */ u8 pad7F;
};

#endif // _TLINSTANCE_H_
