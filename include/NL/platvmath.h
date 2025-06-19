#ifndef _PLATVMATH_H_
#define _PLATVMATH_H_

#include "NL/nlMath.h"
#include "Dolphin/mtx.h"

/*

m[0][0] m[0][1] m[0][2] m[0][3]  // Row 0: offset 0x00, 0x04, 0x08, 0x0C
m[1][0] m[1][1] m[1][2] m[1][3]  // Row 1: offset 0x10, 0x14, 0x18, 0x1C  
m[2][0] m[2][1] m[2][2] m[2][3]  // Row 2: offset 0x20, 0x24, 0x28, 0x2C
m[3][0] m[3][1] m[3][2] m[3][3]  // Row 3: offset 0x30, 0x34, 0x38, 0x3C

*/

class nlMatrix4
{
public:
    void SetIdentity();
    void SetColumn(int col, const nlVector3& v);

    Mtx44 m;
};

void nlMakeScaleMatrix(nlMatrix4& result, float scaleX, float scaleY, float scaleZ);
void nlMakeRotationMatrixEulerAngles(nlMatrix4& result, float pitch, float yaw, float roll);
void nlMakeRotationMatrixZ(nlMatrix3& result, float angleZ);
void nlMakeRotationMatrixZ(nlMatrix4& result, float angleZ);
void nlMakeRotationMatrixY(nlMatrix4& result, float angleY);
void nlMakeRotationMatrixX(nlMatrix4& result, float angleX);
void nlMultDirVectorMatrix(nlVector3& result, const nlVector3& direction, const nlMatrix4& transformMatrix);
void nlMultVectorMatrix(nlVector4& result, const nlVector4& inputVector, const nlMatrix4& transformMatrix);
void nlMultPosVectorMatrix(nlVector3& result, const nlVector3& position, const nlMatrix4& transformMatrix);
void nlMultVectorMatrix(nlVector2& result, const nlVector2& inputVector, const nlMatrix4& transformMatrix);
void nlInvertMatrix(nlMatrix4& result, const nlMatrix4& inputMatrix);
void nlTransposeMatrix(nlMatrix4& result, const nlMatrix4& inputMatrix);
void nlMultMatrices(nlMatrix4& result, const nlMatrix4& matrixA, const nlMatrix4& matrixB);

#endif // _PLATVMATH_H_
