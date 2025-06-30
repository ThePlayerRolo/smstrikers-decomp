#include "ode/NLGAdditions.h"

#include "NL/nlMath.h"
#include "objects.h"
#include "joint.h"
#include "collision_kernel.h"

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
void dGeomMarkAABBAsValid(dxGeom* geomID)
{
    geomID->gflags = geomID->gflags & 0xFFFFFFFC;
}

/**
 * Offset/Address/Size: 0x150 | 0x80224418 | size: 0x44
 */
void dGeomComputeAABB(dxGeom* geomID)
{
    geomID->computeAABB();
    geomID->gflags = (s32) (geomID->gflags & 0xFFFFFFFC);    
}

/**
 * Offset/Address/Size: 0x194 | 0x8022445C | size: 0x34
 */
void dVector3Add(float* v1, const float* v2)
{
    v1[0] += v2[0];
    v1[1] += v2[1];
    v1[2] += v2[2];
}

/**
 * Offset/Address/Size: 0x1C8 | 0x80224490 | size: 0x28
 */
void dVectorScale(float* v1, float arg8)
{
    v1[0] = (f32) (v1[0] * arg8);
    v1[1] = (f32) (v1[1] * arg8);
    v1[2] = (f32) (v1[2] * arg8);    
}

/**
 * Offset/Address/Size: 0x1F0 | 0x802244B8 | size: 0x14
 */
void dVector4Set(float* v, float x, float y, float z, float w)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
}

/**
 * Offset/Address/Size: 0x204 | 0x802244CC | size: 0x10
 */
void dVector3Set(float* v, float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
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
void characterGetInfo2(dxJointCharacter*, dxJoint::Info2*)
{
}

/**
 * Offset/Address/Size: 0x57C | 0x80224844 | size: 0x14
 */
void characterGetInfo1(dxJointCharacter*, dxJoint::Info1*)
{
}

/**
 * Offset/Address/Size: 0x590 | 0x80224858 | size: 0x14
 */
void characterInit(dxJointCharacter* character)
{
    // character->unk50 = 0.f;
    // character->unk54 = 0.f;
    // character->unk58 = 0.f;
    character->m_unk_0x50[0] = 0.f;
    character->m_unk_0x50[1] = 0.f;
    character->m_unk_0x50[2] = 0.f;
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
    // world->adis_flag = flags;
    *(int *)((u8*)world + 0x4c) = flags; //?
}

/**
 * Offset/Address/Size: 0x5B0 | 0x80224878 | size: 0x8
 */
dxBody* dBodyGetNextBody(dxBody* body)
{
    return (dxBody*)body->next;
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
void dBodySetUpdateMode(dxBody* body, int arg1, int arg2)
{
    body->flags = (s32) (body->flags & 0xFFFFFF9F);
    if (arg1 == 0) {
        body->flags = (s32) (body->flags | 0x20);
    }
    if (arg2 == 0) {
        body->flags = (s32) (body->flags | 0x40);
    }    
}
