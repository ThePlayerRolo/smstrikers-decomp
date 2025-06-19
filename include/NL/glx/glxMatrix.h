#ifndef _GLXMATRIX_H_
#define _GLXMATRIX_H_

#include "NL/nlMath.h"

void glxCopyMatrix(float(&)[3][4], const nlMatrix4&);
void glxCopyMatrix(float(&)[4][4], const nlMatrix4&);
void glplatMatrixLookAt(nlMatrix4&, const nlVector3&, const nlVector3&, const nlVector3&);
void glplatMatrixPerspective(nlMatrix4&, float, float, float, float);
void glplatMatrixOrthographicCentered(nlMatrix4&, float, float, float, float);
void glplatMatrixOrthographic(nlMatrix4&, float, float);

#endif // _GLXMATRIX_H_
