#include "Game/GL/GLSkinMesh.h"

/**
 * Offset/Address/Size: 0xD8 | 0x801E05E0 | size: 0x64
 */
void SkinMatrix::Set(const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x5C | 0x801E0564 | size: 0x7C
 */
void SkinMatrix::Get(nlMatrix4&) const
{
}

/**
 * Offset/Address/Size: 0x2C | 0x801E0534 | size: 0x30
 */
void SkinMatrix::Get4x3(float*) const
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801E0508 | size: 0x2C
 */
void nlMultMatrices(SkinMatrix&, const SkinMatrix&, const SkinMatrix&)
{
}
