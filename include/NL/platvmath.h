#ifndef _PLATVMATH_H_
#define _PLATVMATH_H_

#include "NL/nlMath.h"
#include "Dolphin/mtx.h"

class nlMatrix4
{
public:
    void SetIdentity();

    Mtx44 m;
};

void nlMakeScaleMatrix(nlMatrix4&, float, float, float);
void nlMakeRotationMatrixEulerAngles(nlMatrix4&, float, float, float);
void nlMakeRotationMatrixZ(nlMatrix3&, float);
void nlMakeRotationMatrixZ(nlMatrix4&, float);
void nlMakeRotationMatrixY(nlMatrix4&, float);
void nlMakeRotationMatrixX(nlMatrix4&, float);
void nlMultDirVectorMatrix(nlVector3&, const nlVector3&, const nlMatrix4&);
void nlMultVectorMatrix(nlVector4&, const nlVector4&, const nlMatrix4&);
void nlMultPosVectorMatrix(nlVector3&, const nlVector3&, const nlMatrix4&);
void nlMultVectorMatrix(nlVector2&, const nlVector2&, const nlMatrix3&);
void nlInvertMatrix(nlMatrix4&, const nlMatrix4&);
void nlTransposeMatrix(nlMatrix4&, const nlMatrix4&);
void nlMultMatrices(nlMatrix4&, const nlMatrix4&, const nlMatrix4&);

#endif // _PLATVMATH_H_
