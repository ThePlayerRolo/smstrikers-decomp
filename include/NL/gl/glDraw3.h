#ifndef _GLDRAW3_H_
#define _GLDRAW3_H_

#include "NL/nlMath.h"
#include "NL/gl/glView.h"

// Forward declaration
struct nlColour;

class glQuad3;

void glAttachQuad3(eGLView, unsigned long, glQuad3*, bool);

class glQuad3
{
public:
    void SetColour(unsigned char, unsigned char, unsigned char, unsigned char);
    void SetColour(const nlColour&);
    void SetupRotatedRectangle(float, float, const nlMatrix4&, bool, bool);
    void Attach(eGLView, int, bool);
    void GetModel(bool) const;
};

#endif // _GLDRAW3_H_
