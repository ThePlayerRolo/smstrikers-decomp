#include "NL/gl/glMatrix.h"

/**
 * Offset/Address/Size: 0x0 | 0x801D8A74 | size: 0x20
 */
void glMatrixLookAt(nlMatrix4&, const nlVector3&, const nlVector3&, const nlVector3&)
{
}

/**
 * Offset/Address/Size: 0x20 | 0x801D8A94 | size: 0x20
 */
void glMatrixPerspective(nlMatrix4&, float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x40 | 0x801D8AB4 | size: 0x20
 */
void glMatrixOrthographicCentered(nlMatrix4&, float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x60 | 0x801D8AD4 | size: 0x20
 */
void glMatrixOrthographic(nlMatrix4&, float, float)
{
}

/**
 * Offset/Address/Size: 0x80 | 0x801D8AF4 | size: 0x20
 */
void glSetMatrix(unsigned long, const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0xA0 | 0x801D8B14 | size: 0x20
 */
void glGetMatrix(unsigned long, nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0xC0 | 0x801D8B34 | size: 0x34
 */
void glAllocMatrix()
{
}

/**
 * Offset/Address/Size: 0xF4 | 0x801D8B68 | size: 0x8
 */
 unsigned long glGetIdentityMatrix()
{
    return 0; // probably a pointer to a matrix
}

/**
 * Offset/Address/Size: 0xFC | 0x801D8B70 | size: 0x3C
 */
void gl_MatrixStartup()
{
}

/**
 * Offset/Address/Size: 0x138 | 0x801D8BAC | size: 0x24
 */
void GLMatrix::Set(const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0x15C | 0x801D8BD0 | size: 0x30
 */
void GLMatrix::Get(nlMatrix4&) const
{
}
