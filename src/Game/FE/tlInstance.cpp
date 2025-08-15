#include "Game/FE/tlInstance.h"
#include "NL/nlMath.h"

#include "math.h"

/**
 * Offset/Address/Size: 0x0 | 0x8020FF80 | size: 0x18
 */
void TLInstance::SetAssetColour(const nlColour& color)
{
    this->unk74 |= 0x10;
    *(u32*)&this->unk60[13] = *(u32*)&color; //???
}

/**
 * Offset/Address/Size: 0x18 | 0x8020FF98 | size: 0x1C
 */
void TLInstance::SetAssetScale(float x, float y, float z)
{
    this->unk74 |= 4;
    this->unk54.f.x = x;
    this->unk54.f.y = y;
    this->unk54.f.z = z;
}

/**
 * Offset/Address/Size: 0x34 | 0x8020FFB4 | size: 0x1C
 */
void TLInstance::SetAssetRotation(float x, float y, float z)
{
    this->unk74 |= 2;
    this->unk48.f.x = x;
    this->unk48.f.y = y;
    this->unk48.f.z = z;
}

/**
 * Offset/Address/Size: 0x50 | 0x8020FFD0 | size: 0x1C
 */
void TLInstance::SetAssetPosition(float x, float y, float z)
{
    this->unk74 |= 1;
    this->unk3C.f.x = x;
    this->unk3C.f.y = y;
    this->unk3C.f.z = z;
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
nlColour* TLInstance::GetColour() const
{
    if (this->unk74 & 0x10)
    {
        return (nlColour*)&this->unk60[13];
    }
    return unkC->GetColour();
}

/**
 * Offset/Address/Size: 0x130 | 0x802100B0 | size: 0x38
 */
nlVector3* TLInstance::GetScale() const
{
    if (this->unk74 & 0x4)
    {
        return (nlVector3*)&this->unk54;
    }
    return unkC->GetScale();
}

/**
 * Offset/Address/Size: 0x168 | 0x802100E8 | size: 0x38
 */
nlVector3* TLInstance::GetRotation() const
{
    if (this->unk74 & 0x2)
    {
        return (nlVector3*)&this->unk48;
    }
    return unkC->GetRotation();
}

/**
 * Offset/Address/Size: 0x1A0 | 0x80210120 | size: 0x38
 */
nlVector3* TLInstance::GetPosition() const
{
    if (this->unk74 & 0x1)
    {
        return (nlVector3*)&this->unk3C;
    }
    return unkC->GetPosition();
}

/**
 * Offset/Address/Size: 0x1D8 | 0x80210158 | size: 0x8
 */
nlColour* TLInstance::GetAssetColour() const
{
    return (nlColour*)&this->unk60[13];
}

/**
 * Offset/Address/Size: 0x1E0 | 0x80210160 | size: 0x8
 */
nlVector3* TLInstance::GetAssetScale() const
{
    return (nlVector3*)&this->unk54;
}

/**
 * Offset/Address/Size: 0x1E8 | 0x80210168 | size: 0x8
 */
nlVector3* TLInstance::GetAssetPosition() const
{
    return (nlVector3*)&this->unk3C;
}
