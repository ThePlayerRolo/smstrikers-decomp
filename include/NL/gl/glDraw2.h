#ifndef _GLDRAW2_H_
#define _GLDRAW2_H_

#include "types.h"

#include "NL/nlColour.h"
#include "NL/gl/glView.h"

class glPoly2
{
public:
    bool Attach(eGLView, int, unsigned long*, unsigned long);
    void FullCoverage(const nlColour&, float);
    void SetupRectangle(float, float, float, float, float);
    void SetupRotatedRectangle(float, float, float, float, float, float);
    void SetColour(const nlColour&);

    /* 0x00 */ float x0;
    /* 0x04 */ float y0;
    /* 0x08 */ float x1;
    /* 0x0C */ float y1;
    /* 0x10 */ float x2;
    /* 0x14 */ float y2;
    /* 0x18 */ float x3;
    /* 0x1C */ float y3;
    // nlVector2 m_pos[4];

    /* 0x20 */ float u0;
    /* 0x24 */ float v0;
    /* 0x28 */ float u1;
    /* 0x2C */ float v1;
    /* 0x30 */ float u2;
    /* 0x34 */ float v2;
    /* 0x38 */ float u3;
    /* 0x3C */ float v3;

    /* 0x40 */ unsigned long c0;
    /* 0x44 */ unsigned long c1;
    /* 0x48 */ unsigned long c2;
    /* 0x4C */ unsigned long c3;

    /* 0x4C */ float depth;
};

bool glAttachPoly2(eGLView, unsigned long, glPoly2*, unsigned long*, const void*);

#endif // _GLDRAW2_H_
