#include "Game/FE/tlInstance.h"
#include "NL/nlMath.h"

#include "math.h"

/**
 * Offset/Address/Size: 0x0 | 0x8020FF80 | size: 0x18
 */
void TLInstance::SetAssetColour(const nlColour& color)
{
    this->m_flags |= 0x10;
    *(u32*)&this->unk60[13] = *(u32*)&color; //???
}

/**
 * Offset/Address/Size: 0x18 | 0x8020FF98 | size: 0x1C
 */
void TLInstance::SetAssetScale(float x, float y, float z)
{
    this->m_flags |= 4;
    this->m_scale.f.x = x;
    this->m_scale.f.y = y;
    this->m_scale.f.z = z;
}

/**
 * Offset/Address/Size: 0x34 | 0x8020FFB4 | size: 0x1C
 */
void TLInstance::SetAssetRotation(float x, float y, float z)
{
    this->m_flags |= 2;
    this->m_rot.f.x = x;
    this->m_rot.f.y = y;
    this->m_rot.f.z = z;
}

/**
 * Offset/Address/Size: 0x50 | 0x8020FFD0 | size: 0x1C
 */
void TLInstance::SetAssetPosition(float x, float y, float z)
{
    this->m_flags |= 1;
    this->m_pos.f.x = x;
    this->m_pos.f.y = y;
    this->m_pos.f.z = z;
}

/**
 * Offset/Address/Size: 0x6C | 0x8020FFEC | size: 0x8C
 */
bool TLInstance::IsValidAtTime(float arg0)
{
    float temp_f0;
    float temp_f2;
    float temp_f3;
    bool var_r0;

    var_r0 = true;
    temp_f0 = arg0 - m_start;
    if (!(temp_f0 > 0.0001f))
    {
        if (!((float)fabs(temp_f0) <= 0.0001f))
        {
            var_r0 = false;
        }
    }

    if (var_r0 != 0)
    {
        var_r0 = 1;
        temp_f2 = m_duration;
        temp_f3 = arg0 - m_start;
        if (!((m_duration - temp_f3) > 0.0001f))
        {
            if (!((float)fabs(temp_f3 - temp_f2) <= 0.0001f))
            {
                var_r0 = false;
            }
        }

        if (var_r0)
        {
            return true;
        }
    }

    return false;
}

/**
 * Offset/Address/Size: 0xF8 | 0x80210078 | size: 0x38
 */
const nlColour* TLInstance::GetColour() const
{
    if (this->m_flags & 0x10)
    {
        return (nlColour*)&this->unk60[13];
    }
    return m_component->GetColour();
}

/**
 * Offset/Address/Size: 0x130 | 0x802100B0 | size: 0x38
 */
const nlVector3* TLInstance::GetScale() const
{
    if (this->m_flags & 0x4)
    {
        return (nlVector3*)&this->m_scale;
    }
    return m_component->GetScale();
}

/**
 * Offset/Address/Size: 0x168 | 0x802100E8 | size: 0x38
 */
const nlVector3* TLInstance::GetRotation() const
{
    if (this->m_flags & 0x2)
    {
        return (nlVector3*)&this->m_rot;
    }
    return m_component->GetRotation();
}

/**
 * Offset/Address/Size: 0x1A0 | 0x80210120 | size: 0x38
 */
const nlVector3* TLInstance::GetPosition() const
{
    if (this->m_flags & 0x1)
    {
        return (nlVector3*)&this->m_pos;
    }
    return m_component->GetPosition();
}

/**
 * Offset/Address/Size: 0x1D8 | 0x80210158 | size: 0x8
 */
const nlColour* TLInstance::GetAssetColour() const
{
    return (nlColour*)&this->unk60[13];
}

/**
 * Offset/Address/Size: 0x1E0 | 0x80210160 | size: 0x8
 */
const nlVector3* TLInstance::GetAssetScale() const
{
    return (nlVector3*)&this->m_scale;
}

/**
 * Offset/Address/Size: 0x1E8 | 0x80210168 | size: 0x8
 */
const nlVector3* TLInstance::GetAssetPosition() const
{
    return (nlVector3*)&this->m_pos;
}
