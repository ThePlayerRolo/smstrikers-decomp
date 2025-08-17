#ifndef _TLINSTANCE_H_
#define _TLINSTANCE_H_

#include "NL/nlColour.h"
#include "NL/nlMath.h"

#include "Game/FE/tlComponent.h"
#include "Game/FE/FEAudio.h"

struct UnkStruct
{
    /* 0x00 */ char unk0;
    /* 0x01 */ char unk1;
    /* 0x02 */ char unk2;
    /* 0x03 */ char unk3;
};

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

    // /* 0x00 */ char pad00[0xC];
    // /* 0x00 */ FEAudio* m_unk_0x00;
    /* 0x00 */ TLInstance* m_next;
    /* 0x04 */ TLInstance* m_prev;
    /* 0x08 */ char pad08[0x4];
    /* 0x0C */ TLComponent* m_component;
    /* 0x10 */ f32 m_start;
    /* 0x14 */ f32 m_duration;
    /* 0x18 */ UnkStruct* m_unk_0x18;
    /* 0x1C */ char pad18[0x1C];
    /* 0x38 */ FEAudio* m_unk_0x38;
    // /* 0x38 */ u32 m_unk_0x38;
    /* 0x3C */ nlVector3 m_pos;
    /* 0x48 */ nlVector3 m_rot;
    /* 0x54 */ nlVector3 m_scale;
    /* 0x60 */ u8 unk60[0x14];
    /* 0x74 */ s32 m_flags;
    /* 0x78 */ s32 m_unk_0x78;
    /* 0x7C */ u8 pad7C[0x2];
    /* 0x7E */ u8 m_enableSoundTriggers;
    /* 0x7F */ u8 pad7F;
};

#endif // _TLINSTANCE_H_
