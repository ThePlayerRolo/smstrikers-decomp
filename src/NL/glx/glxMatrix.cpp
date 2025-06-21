#include "NL/glx/glxMatrix.h"

/**
 * Offset/Address/Size: 0x0 | 0x801B6568 | size: 0x64
 */
void glxCopyMatrix(float(&)[3][4], const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x64 | 0x801B65CC | size: 0x24
 */
void glxCopyMatrix(float(&)[4][4], const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x88 | 0x801B65F0 | size: 0x1CC
 */
void glplatMatrixLookAt(nlMatrix4&, const nlVector3&, const nlVector3&, const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x254 | 0x801B67BC | size: 0xB8
 */
void glplatMatrixPerspective(nlMatrix4&, float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x30C | 0x801B6874 | size: 0x48
 */
void glplatMatrixOrthographicCentered(nlMatrix4&, float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x354 | 0x801B68BC | size: 0x6C
 */
void glplatMatrixOrthographic(nlMatrix4&, float, float)
{
}
