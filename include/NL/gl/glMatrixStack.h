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

    /* 0x00 */ nlMatrix4 m_matrix1;
    /* 0x40 */ nlMatrix4 m_matrix2;
    /* 0x80 */ nlMatrix4 *m_matrixStack;
    /* 0x84 */ u8 m_stackCurPosition;
    /* 0x88 */ u32 m_stackSize;
    /* 0x8C */ u32 m_unk_0x8C;
};

#endif // _GLMATRIXSTACK_H_
