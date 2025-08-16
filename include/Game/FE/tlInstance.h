#ifndef _TLINSTANCE_H_
#define _TLINSTANCE_H_

#include "NL/nlColour.h"
#include "NL/nlMath.h"

#include "Game/FE/tlComponent.h"

class TLInstance
{
public:
    void SetAssetColour(const nlColour&);
    void SetAssetScale(float, float, float);
    void SetAssetRotation(float, float, float);
    void SetAssetPosition(float, float, float);
    bool IsValidAtTime(float);
    const nlColour* GetColour() const;
    const nlVector3* GetScale() const;
    const nlVector3* GetRotation() const;
    const nlVector3* GetPosition() const;
    const nlColour* GetAssetColour() const;
    const nlVector3* GetAssetScale() const;
    const nlVector3* GetAssetPosition() const;

    /* 0x00 */ char pad00[0xC];
    /* 0x0C */ TLComponent* m_component;
    /* 0x10 */ f32 m_start;
    /* 0x14 */ f32 m_duration;
    /* 0x18 */ char pad18[0x24];
    /* 0x3C */ nlVector3 m_pos;
    /* 0x48 */ nlVector3 m_rot;
    /* 0x54 */ nlVector3 m_scale;
    /* 0x60 */ u8 unk60[0x14];
    /* 0x74 */ s32 m_flags;
    /* 0x78 */ u8 pad78[0x6];
    /* 0x7E */ u8 m_enableSoundTriggers;
    /* 0x7F */ u8 pad7F;
};

#endif // _TLINSTANCE_H_
