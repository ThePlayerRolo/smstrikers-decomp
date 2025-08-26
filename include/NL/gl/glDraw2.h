#ifndef _GLDRAW2_H_
#define _GLDRAW2_H_

#include "types.h"

#include "NL/nlColour.h"
#include "NL/gl/glView.h"

class glPoly2
{
public:
    void SetColour(const nlColour&);
    void SetupRotatedRectangle(float, float, float, float, float, float);
    void SetupRectangle(float, float, float, float, float);
    void FullCoverage(const nlColour&, float);
    void Attach(eGLView, int, unsigned long*, unsigned long);

    /* 0x00 */ float x0;
    /* 0x04 */ float y0;
    /* 0x08 */ float x1;
    /* 0x0C */ float y1;
    /* 0x10 */ float x2;
    /* 0x14 */ float y2;
    /* 0x18 */ float x3;
    /* 0x1C */ float y3;
    /* 0x20 */ u8 _pad20[0x20];
    /* 0x40 */ unsigned long c0;
    /* 0x44 */ unsigned long c1;
    /* 0x48 */ unsigned long c2;
    /* 0x4C */ unsigned long c3;
    // /* 0x40 */ nlColour c0;
    // /* 0x44 */ nlColour c1;
    // /* 0x48 */ nlColour c2;
    // /* 0x4C */ nlColour c3;
    /* 0x4C */ float depth;
};

void glAttachPoly2(eGLView, unsigned long, glPoly2*, unsigned long*, const void*);

#endif // _GLDRAW2_H_
