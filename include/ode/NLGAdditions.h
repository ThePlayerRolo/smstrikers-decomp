#ifndef _NLGADDITIONS_H_
#define _NLGADDITIONS_H_

#include "ode/common.h"
#include "ode/objects.h"
#include "ode/collision.h"
#include "ode/joint.h"

class dxJointCharacter;

void dGeomCollideAABBs(dxGeom*, dxGeom*, void*, void (*)(void*, dxGeom*, dxGeom*));
void dGeomMarkAABBAsValid(dxGeom*);
void dGeomComputeAABB(dxGeom*);
void dVector3Add(float*, const float*);
void dVectorScale(float*, float);
void dVector4Set(float*, float, float, float, float);
void dVector3Set(float*, float, float, float);
void dExtractColumn3(float*, const float*, int);
void dInvertRigidTransformation(float*, const float*, const float*);
void dMultiplyMatrix4Vector4(float*, const float*, const float*);
void dMultiplyMatrix3Vector3(float*, const float*, const float*, bool);
void dGeomSetGFlags(dxGeom*, int);
void dGeomGetGFlags(dxGeom*);
void dJointSetCharacterNoMotionDirection(dxJoint*, float*);
void dJointCreateCharacter(dxWorld*, dxJointGroup*);
void characterInit(dxJointCharacter*);
void dClearCachedData();
void dWorldSetClearAccumulators(dxWorld*, int);
dxBody* dBodyGetNextBody(dxBody*);
dxBody* dWorldGetFirstBody(dxWorld*);
void dBodySetUpdateMode(dxBody*, int, int);

// class characterGetInfo2(dxJointCharacter*, dxJoint
// {
// public:
//     void Info2*);
// };


// class characterGetInfo1(dxJointCharacter*, dxJoint
// {
// public:
//     void Info1*);
// };

#endif // _NLGADDITIONS_H_
