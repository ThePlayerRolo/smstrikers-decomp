#ifndef _GLMATRIXSTACK_H_
#define _GLMATRIXSTACK_H_

#include "NL/nlMath.h"

class GLMatrixStack
{
public:
    void GetTop(nlMatrix4&);
    void PopMatrix();
    void PushMatrix();
    void MultMatrix(const nlMatrix4&);
    void LoadIdentity();
    ~GLMatrixStack();
    GLMatrixStack(int);
};

#endif // _GLMATRIXSTACK_H_
