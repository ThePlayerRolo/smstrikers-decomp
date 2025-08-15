#include "Game/FE/tlInstance.h"

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
void TLInstance::SetAssetScale(float, float, float)
{
}

/**
 * Offset/Address/Size: 0x34 | 0x8020FFB4 | size: 0x1C
 */
void TLInstance::SetAssetRotation(float, float, float)
{
}

/**
 * Offset/Address/Size: 0x50 | 0x8020FFD0 | size: 0x1C
 */
void TLInstance::SetAssetPosition(float, float, float)
{
}

/**
 * Offset/Address/Size: 0x6C | 0x8020FFEC | size: 0x8C
 */
void TLInstance::IsValidAtTime(float)
{
}

/**
 * Offset/Address/Size: 0xF8 | 0x80210078 | size: 0x38
 */
void TLInstance::GetColour() const
{
}

/**
 * Offset/Address/Size: 0x130 | 0x802100B0 | size: 0x38
 */
void TLInstance::GetScale() const
{
}

/**
 * Offset/Address/Size: 0x168 | 0x802100E8 | size: 0x38
 */
void TLInstance::GetRotation() const
{
}

/**
 * Offset/Address/Size: 0x1A0 | 0x80210120 | size: 0x38
 */
void TLInstance::GetPosition() const
{
}

/**
 * Offset/Address/Size: 0x1D8 | 0x80210158 | size: 0x8
 */
void TLInstance::GetAssetColour() const
{
}

/**
 * Offset/Address/Size: 0x1E0 | 0x80210160 | size: 0x8
 */
void TLInstance::GetAssetScale() const
{
}

/**
 * Offset/Address/Size: 0x1E8 | 0x80210168 | size: 0x8
 */
void TLInstance::GetAssetPosition() const
{
}
