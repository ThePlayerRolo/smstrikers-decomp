#ifndef _PLATQMATH_H_
#define _PLATQMATH_H_

#include "types.h"

struct nlMatrix4;
struct nlVector3;

struct nlQuaternion
{
    float x;
    float y;
    float z;
    float w;
};

void nlQuatScale(nlQuaternion& result, const nlQuaternion& input, float scaleFactor);
f32 nlQuatDot(const nlQuaternion& quat1, const nlQuaternion& quat2);
void nlMultQuat(nlQuaternion& result, const nlQuaternion& quat1, const nlQuaternion& quat2);
void nlMatrixToQuat(nlQuaternion& result, const nlMatrix4& rotationMatrix);
void nlQuatToMatrix(nlMatrix4& resultMatrix, const nlQuaternion& inputQuat);
void nlQuatSlerp(nlQuaternion& result, const nlQuaternion& startQuat, const nlQuaternion& endQuat, float interpolationFactor);

void nlInvertRotTransMatrix(nlMatrix4&, const nlMatrix4&);
void nlQuatNLerp(nlQuaternion&, const nlQuaternion&, const nlQuaternion&, float);
void nlQuatInverse(nlQuaternion&, const nlQuaternion&);
void nlQuatNormalize(nlQuaternion&, const nlQuaternion&);
void nlMakeQuat(nlQuaternion&, const nlVector3&, float);
// void nlCartesianToPolar(nlPolar&, const nlVector3&);
// void nlAddPolarToCartesian(nlVector3&, const nlPolar&);
// void nlPolarToCartesian(nlVector3&, const nlPolar&);
void nlPolarToCartesian(float&, float&, unsigned short, float);
// void nlCartesianToPolar(nlPolar&, float, float);

#endif // _PLATQMATH_H_
