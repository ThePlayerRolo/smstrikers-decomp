#include "NL/nlMath.h"

/**
 * Offset/Address/Size: 0x0 | 0x801C439C | size: 0x2C
 */
void nlQuatScale(nlQuaternion&, const nlQuaternion&, float)
{
}

/**
 * Offset/Address/Size: 0x2C | 0x801C43C8 | size: 0x20
 */
void nlQuatDot(const nlQuaternion&, const nlQuaternion&)
{
}

/**
 * Offset/Address/Size: 0x4C | 0x801C43E8 | size: 0x74
 */
void nlMultQuat(nlQuaternion&, const nlQuaternion&, const nlQuaternion&)
{
}

/**
 * Offset/Address/Size: 0xC0 | 0x801C445C | size: 0x278
 */
void nlMatrixToQuat(nlQuaternion&, const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x338 | 0x801C46D4 | size: 0xF4
 */
void nlQuatToMatrix(nlMatrix4&, const nlQuaternion&)
{
}

/**
 * Offset/Address/Size: 0x42C | 0x801C47C8 | size: 0x34
 */
void nlQuatSlerp(nlQuaternion&, const nlQuaternion&, const nlQuaternion&, float)
{
}
