#include "ode/NLGAdditions.h"

#include "NL/nlMath.h"
#include "objects.h"
#include "joint.h"

static dxJoint *createJoint (dWorldID w, dJointGroupID group, dxJoint::Vtable *vtable);

/**
 * Offset/Address/Size: 0x0 | 0x802242C8 | size: 0x140
 */
void dGeomCollideAABBs(dxGeom*, dxGeom*, void*, void (*)(void*, dxGeom*, dxGeom*))
{
}

/**
 * Offset/Address/Size: 0x140 | 0x80224408 | size: 0x10
 */
void dGeomMarkAABBAsValid(dxGeom*)
{
}

/**
 * Offset/Address/Size: 0x150 | 0x80224418 | size: 0x44
 */
void dGeomComputeAABB(dxGeom*)
{
}

/**
 * Offset/Address/Size: 0x194 | 0x8022445C | size: 0x34
 */
void dVector3Add(float*, const float*)
{
}

/**
 * Offset/Address/Size: 0x1C8 | 0x80224490 | size: 0x28
 */
void dVectorScale(float*, float)
{
}

/**
 * Offset/Address/Size: 0x1F0 | 0x802244B8 | size: 0x14
 */
void dVector4Set(float*, float, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x204 | 0x802244CC | size: 0x10
 */
void dVector3Set(float*, float, float, float)
{
}

/**
 * Offset/Address/Size: 0x214 | 0x802244DC | size: 0x24
 */
void dExtractColumn3(float*, const float*, int)
{
}

/**
 * Offset/Address/Size: 0x238 | 0x80224500 | size: 0xDC
 */
void dInvertRigidTransformation(float*, const float*, const float*)
{
}

/**
 * Offset/Address/Size: 0x314 | 0x802245DC | size: 0x2C
 */
void dMultiplyMatrix4Vector4(float*, const float*, const float*)
{
}

/**
 * Offset/Address/Size: 0x340 | 0x80224608 | size: 0x88
 */
void dMultiplyMatrix3Vector3(float*, const float*, const float*, bool)
{
}

/**
 * Offset/Address/Size: 0x3C8 | 0x80224690 | size: 0x8
 */
void dGeomSetGFlags(dxGeom*, int)
{
}

/**
 * Offset/Address/Size: 0x3D0 | 0x80224698 | size: 0x8
 */
void dGeomGetGFlags(dxGeom*)
{
}

/**
 * Offset/Address/Size: 0x3D8 | 0x802246A0 | size: 0x1C
 */
void dJointSetCharacterNoMotionDirection(dxJoint* joint, nlVector3* v3)
{
    // *(undefined4 *)(param_1 + 0x50) = *param_2;
    // *(undefined4 *)(param_1 + 0x54) = param_2[1];
    // *(undefined4 *)(param_1 + 0x58) = param_2[2];
    // joint->node[0].
}

/**
 * Offset/Address/Size: 0x3F4 | 0x802246BC | size: 0x28
 */
dxJoint *dJointCreateCharacter(dxWorld* world, dxJointGroup* jointGroup)
{
    return createJoint(world, jointGroup, NULL);
}

/**
 * Offset/Address/Size: 0x41C | 0x802246E4 | size: 0x160
 */
// void characterGetInfo2(dxJointCharacter*, dxJoint::Info2*)
// {
// }

/**
 * Offset/Address/Size: 0x57C | 0x80224844 | size: 0x14
 */
// void characterGetInfo1(dxJointCharacter*, dxJoint::Info1*)
// {
// }

/**
 * Offset/Address/Size: 0x590 | 0x80224858 | size: 0x14
 */
void characterInit(dxJointCharacter*)
{
}

/**
 * Offset/Address/Size: 0x5A4 | 0x8022486C | size: 0x4
 */
void dClearCachedData()
{
}

/**
 * Offset/Address/Size: 0x5A8 | 0x80224870 | size: 0x8
 */
void dWorldSetClearAccumulators(dxWorld* world, int flags)
{
    world->adis_flag = flags;
    // *(undefined4 *)(param_1 + 0x4c) = param_2;
}

/**
 * Offset/Address/Size: 0x5B0 | 0x80224878 | size: 0x8
 */
dxBody* dBodyGetNextBody(dxBody* body)
{
    // return body->next;
    return NULL;
}

/**
 * Offset/Address/Size: 0x5B8 | 0x80224880 | size: 0x8
 */
dxBody* dWorldGetFirstBody(dxWorld* world)
{
    return world->firstbody;
}

/**
 * Offset/Address/Size: 0x5C0 | 0x80224888 | size: 0x38
 */
void dBodySetUpdateMode(dxBody*, int, int)
{
}
