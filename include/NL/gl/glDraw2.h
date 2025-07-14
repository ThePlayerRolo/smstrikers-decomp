#ifndef _GLDRAW2_H_
#define _GLDRAW2_H_

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

    /* 0x00 */ void* data;
    /* 0x04 */ int x;
    /* 0x08 */ int y;
    /* 0x0C */ u8 m_padding[0x34];
    /* 0x40 */ nlColour m_colour1;
    /* 0x44 */ nlColour m_colour2;
    /* 0x48 */ nlColour m_colour3;
    /* 0x4C */ nlColour m_colour4;
};

void glAttachPoly2(eGLView, unsigned long, glPoly2*, unsigned long*, const void*);

#endif // _GLDRAW2_H_
