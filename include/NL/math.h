#ifndef _MATH_H_
#define _MATH_H_

#include "NL/platvmath.h"

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

#endif // _MATH_H_
