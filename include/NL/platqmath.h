#ifndef _PLATQMATH_H_
#define _PLATQMATH_H_

#include "NL/nlMath.h"
#include "Dolphin/mtx.h"

class nlQuaternion
{
public:
    float x;
    float y;
    float z;
    float w;
};

void nlQuatScale(nlQuaternion& result, const nlQuaternion& input, float scaleFactor);
void nlQuatDot(const nlQuaternion& quat1, const nlQuaternion& quat2);
void nlMultQuat(nlQuaternion& result, const nlQuaternion& quat1, const nlQuaternion& quat2);
void nlMatrixToQuat(nlQuaternion& result, const nlMatrix4& rotationMatrix);
void nlQuatToMatrix(nlMatrix4& resultMatrix, const nlQuaternion& inputQuat);
void nlQuatSlerp(nlQuaternion& result, const nlQuaternion& startQuat, const nlQuaternion& endQuat, float interpolationFactor);

#endif // _PLATQMATH_H_
