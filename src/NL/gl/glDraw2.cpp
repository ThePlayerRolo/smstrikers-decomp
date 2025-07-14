#include "NL/gl/glDraw2.h"

/**
 * Offset/Address/Size: 0x0 | 0x801D7600 | size: 0x18
 */
void glPoly2::SetColour(const nlColour& col)
{
    u32 rgb = *(u32*)&col;
    *(u32*)&m_colour1 = rgb;
    *(u32*)&m_colour2 = rgb;
    *(u32*)&m_colour3 = rgb;
    *(u32*)&m_colour4 = rgb;
}

/**
 * Offset/Address/Size: 0x18 | 0x801D7618 | size: 0x1D4
 */
void glPoly2::SetupRotatedRectangle(float, float, float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x1EC | 0x801D77EC | size: 0x64
 */
void glPoly2::SetupRectangle(float, float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x250 | 0x801D7850 | size: 0xEC
 */
void glPoly2::FullCoverage(const nlColour&, float)
{
}

/**
 * Offset/Address/Size: 0x33C | 0x801D793C | size: 0x2D4
 */
void glAttachPoly2(eGLView, unsigned long, glPoly2*, unsigned long*, const void*)
{
}

/**
 * Offset/Address/Size: 0x610 | 0x801D7C10 | size: 0x210
 */
void glPoly2::Attach(eGLView, int, unsigned long*, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x820 | 0x801D7E20 | size: 0x2C
//  */
// void 0x8028D53C..0x8028D540 | size: 0x4
// {
// }
