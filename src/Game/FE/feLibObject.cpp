#include "Game/FE/feLibObject.h"

/**
 * Offset/Address/Size: 0x0 | 0x80209D28 | size: 0x8
 */
const nlVector3* FELibObject::GetScale() const
{
    return &this->m_scale;
}

/**
 * Offset/Address/Size: 0x8 | 0x80209D30 | size: 0x8
 */
const nlVector3* FELibObject::GetRotation() const
{
    return &this->m_rotation;
}

/**
 * Offset/Address/Size: 0x10 | 0x80209D38 | size: 0x8
 */
const nlVector3* FELibObject::GetPosition() const
{
    return &this->m_position;
}

/**
 * Offset/Address/Size: 0x18 | 0x80209D40 | size: 0x8
 */
const nlColour* FELibObject::GetColour() const
{
    return &this->m_colour;
}
