#ifndef _GLMATRIX_H_
#define _GLMATRIX_H_

#include "NL/nlMath.h"

void glMatrixLookAt(nlMatrix4&, const nlVector3&, const nlVector3&, const nlVector3&);
void glMatrixPerspective(nlMatrix4&, float, float, float, float);
void glMatrixOrthographicCentered(nlMatrix4&, float, float, float, float);
void glMatrixOrthographic(nlMatrix4&, float, float);
void glSetMatrix(unsigned long, const nlMatrix4&);
void glGetMatrix(unsigned long, nlMatrix4&);
void glAllocMatrix();
unsigned long glGetIdentityMatrix();
void gl_MatrixStartup();

class GLMatrix
{
public:
    void Set(const nlMatrix4&);
    void Get(nlMatrix4&) const;
};

#endif // _GLMATRIX_H_
