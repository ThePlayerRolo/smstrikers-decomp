#ifndef _GLDRAW2_H_
#define _GLDRAW2_H_

#include "NL/gl/glView.h"

// Forward declaration
struct nlColour;

class glPoly2;

void glAttachPoly2(eGLView, unsigned long, glPoly2*, unsigned long*, const void*);
// void 0x8028D53C..0x8028D540 | size: 0x4;

class glPoly2
{
public:
    void SetColour(const nlColour&);
    void SetupRotatedRectangle(float, float, float, float, float, float);
    void SetupRectangle(float, float, float, float, float);
    void FullCoverage(const nlColour&, float);
    void Attach(eGLView, int, unsigned long*, unsigned long);
};

#endif // _GLDRAW2_H_
