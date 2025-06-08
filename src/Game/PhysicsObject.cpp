#include "types.h"
#include "ode/objects.h"
#include "ode/collision.h"

#include "PhysicsObject.h"
#include "PhysicsWorld.h"

const float PhysicsObject::DefaultGravity = -9.8f;

/**
 * Offset/Address/Size: 0x0 | 0x801FFCFC | size: 0x70
 */
void ConvertDMat3ToNLMat4(const float* mat3, nlMatrix4* mat4)
{
    // todo: regswaps all over the place...
    mat4->v[0] = (f32)mat3[0];
    mat4->v[4] = (f32)mat3[1];
    mat4->v[8] = (f32)mat3[2];
    mat4->v[1] = (f32)mat3[4];
    mat4->v[5] = (f32)mat3[5];
    mat4->v[9] = (f32)mat3[6];
    mat4->v[2] = (f32)mat3[8];
    mat4->v[6] = (f32)mat3[9];
    mat4->v[10] = (f32)mat3[10];
    mat4->v[12] = 1.0f;
    mat4->v[13] = 1.0f;
    mat4->v[14] = 1.0f;
    mat4->v[15] = 0.0f;
    mat4->v[3] = 1.0f;
    mat4->v[7] = 1.0f;
    mat4->v[11] = 1.0f;
}

/**
 * Offset/Address/Size: 0x70 | 0x801FFD6C | size: 0x1A8
 */
void PhysicsObject::CloneObject(const PhysicsObject&)
{
}

/**
 * Offset/Address/Size: 0x218 | 0x801FFF14 | size: 0x44
 */
int PhysicsObject::Contact(PhysicsObject* obj1, dContact* contact, int param, PhysicsObject* obj2)
{
    //   undefined4 uVar1;

    //   if (this->m_parentObject == (PhysicsObject *)0x0) {
    //     uVar1 = 3;
    //   }
    //   else {
    //     uVar1 = (**(code **)(*(int *)this->m_parentObject->padding + 0x24))();
    //   }
    //   return uVar1;
    int ret;
    if (m_parentObject == NULL)
    {
        ret = 3;
    }
    else
    {
        ret = this->m_parentObject->Contact(obj1, contact, param, obj2);
    }
    return ret;
}

/**
 * Offset/Address/Size: 0x25C | 0x801FFF58 | size: 0x30
 */
int PhysicsObject::Contact(PhysicsObject*, dContact*, int)
{
    // (**(code **)(*(int *)this->padding + 0x24))();
}

/**
 * Offset/Address/Size: 0x28C | 0x801FFF88 | size: 0x4C
 */
void PhysicsObject::MakeStatic()
{
    if (m_bodyID != NULL)
    {
        dBodyDestroy(m_bodyID);
        m_bodyID = NULL;
    }
    dGeomSetBody(m_geomID, NULL);
}

// /* 0x04 */ dBodyID m_bodyID;
// /* 0x08 */ dGeomID m_geomID;
// /* 0x10 */ float _gravity;

/**
 * Offset/Address/Size: 0x2D8 | 0x801FFFD4 | size: 0x6C
 */
void PhysicsObject::SetMass(float mass)
{
    dMass m;
    if (m_bodyID != nullptr)
    {
        dMassSetZero(&m);
        dBodyGetMass(m_bodyID, &m);
        dMassAdjust(&m, mass);
        dBodySetMass(m_bodyID, &m);
    }
}

/**
 * Offset/Address/Size: 0x344 | 0x80200040 | size: 0x50
 */
void PhysicsObject::Reconnect(dxSpace* space)
{
    dSpaceAdd(space, m_geomID);
    dGeomSetBody(m_geomID, m_bodyID);
    if (m_bodyID != 0)
    {
        dBodyEnable(m_bodyID);
    }
}

/**
 * Offset/Address/Size: 0x344 | 0x80200040 | size: 0x50
 */
void PhysicsObject::Disconnect()
{
    dSpaceID space;
    space = dGeomGetSpace(m_geomID);
    if (space != nullptr)
    {
        dSpaceRemove(space, m_geomID);
    }
    dGeomSetBody(m_geomID, 0);
    if (m_bodyID != nullptr)
    {
        dBodyDisable(m_bodyID);
    }
}

/**
 * Offset/Address/Size: 0x3FC | 0x802000F8 | size: 0x24
 */
void PhysicsObject::EnableCollisions()
{
    dGeomEnable(m_geomID);
}

/**
 * Offset/Address/Size: 0x420 | 0x8020011C | size: 0x24
 */
void PhysicsObject::DisableCollisions()
{
    dGeomDisable(m_geomID);
}

/**
 * Offset/Address/Size: 0x444 | 0x80200140 | size: 0xD4
 */
void PhysicsObject::SetWorldMatrix(const nlMatrix4& in)
{
    // todo: regswaps all over the place...
    dMatrix3 mat;
    mat[0] = in.v[0];
    mat[1] = in.v[4];
    mat[2] = in.v[8];
    mat[3] = in.v[12];
    mat[4] = in.v[1];
    mat[5] = in.v[5];
    mat[6] = in.v[9];
    mat[7] = in.v[13];
    mat[8] = in.v[2];
    mat[9] = in.v[6];
    mat[10] = in.v[10];
    mat[11] = in.v[14];

    if ((m_geomID == 0) && (m_bodyID != 0))
    {
        dBodySetRotation(m_bodyID, mat);
    }
    else
    {
        dGeomSetRotation(m_geomID, mat);
    }

    nlVector3* pos = (nlVector3*)&(in.v[12]);
    SetPosition(*pos, CoordinateType_0);
}

/**
 * Offset/Address/Size: 0x518 | 0x80200214 | size: 0x78
 */
BOOL PhysicsObject::SetContactInfo(dContact* contact, PhysicsObject* otherObject, bool param3)
{
    float fVar1;
    float fVar2;
    BOOL uVar3;

    fVar1 = 0.0001f;
    if (m_parentObject == NULL)
    {
        if (param3)
        {
            (contact->surface).mode = 0x14;
            (contact->surface).soft_cfm = 0.0001f;
            (contact->surface).mu = 0.9f;
            (contact->surface).mu2 = 0.0f;
            (contact->surface).bounce = 0.2f;
            (contact->surface).bounce_vel = 0.1f;
        }
        uVar3 = 1;
    }
    else
    {
        // uVar3 = (**(code **)(**(int **)(this + 0xc) + 0x10))();
        uVar3 = 1;
    }
    return uVar3;
}

/**
 * Offset/Address/Size: 0x590 | 0x8020028C | size: 0x34
 */
void PhysicsObject::SetDefaultContactInfo(dContact* contact)
{
    (contact->surface).mode = 0x14;
    (contact->surface).soft_cfm = 0.0001f;
    (contact->surface).mu = 0.9f;
    (contact->surface).mu2 = 0.0f;
    (contact->surface).bounce = .2f;
    (contact->surface).bounce_vel = .1f;
}

/**
 * Offset/Address/Size: 0x5C4 | 0x802002C0 | size: 0x50
 */
void PhysicsObject::ZeroForceAccumulators()
{
    dBodySetForce(m_bodyID, 0.f, 0.f, 0.f);
    dBodySetTorque(m_bodyID, 0.f, 0.f, 0.f);
}

/**
 * Offset/Address/Size: 0x614 | 0x80200310 | size: 0x30
 */
void PhysicsObject::AddForceAtCentreOfMass(const nlVector3& force)
{
    dBodyAddForce(m_bodyID, force.x, force.y, force.z);
}

/**
 * Offset/Address/Size: 0x644 | 0x80200340 | size: 0x1AC
 */
void PhysicsObject::GetAngularVelocity(nlVector3*) const
{
}

/**
 * Offset/Address/Size: 0x7F0 | 0x802004EC | size: 0x30
 */
void PhysicsObject::SetAngularVelocity(const nlVector3& velocity)
{
    dBodySetAngularVel(m_bodyID, (float)velocity.x, (float)velocity.y, (float)velocity.z);
}

/**
 * Offset/Address/Size: 0x820 | 0x8020051C | size: 0x34
 */
void PhysicsObject::GetLinearVelocity()
{
}

/**
 * Offset/Address/Size: 0x854 | 0x80200550 | size: 0x1AC
 */
void PhysicsObject::GetLinearVelocity(nlVector3* out) const
{
    PhysicsObject* temp_r3;
    PhysicsObject* temp_r3_2;
    PhysicsObject* temp_r3_3;

    PhysicsObject* temp_r5;
    PhysicsObject* temp_r5_2;
    PhysicsObject* temp_r5_3;
    PhysicsObject* temp_r5_4;

    temp_r5 = m_parentObject;
    if (temp_r5 != NULL)
    {
        temp_r3 = temp_r5->m_parentObject;
        if (temp_r3 != NULL)
        {
            temp_r5_2 = temp_r3->m_parentObject;
            if (temp_r5_2 != NULL)
            {
                temp_r3_2 = temp_r5_2->m_parentObject;
                if (temp_r3_2 != NULL)
                {
                    temp_r5_3 = temp_r3_2->m_parentObject;
                    if (temp_r5_3 != NULL)
                    {
                        temp_r3_3 = temp_r5_3->m_parentObject;
                        if (temp_r3_3 != NULL)
                        {
                            temp_r5_4 = temp_r3_3->m_parentObject;
                            if (temp_r5_4 != NULL)
                            {
                                if ((u32)temp_r5_4->m_parentObject != 0U)
                                {
                                    temp_r5_4->m_parentObject->GetLinearVelocity(out);
                                    return;
                                }
                                float* v = (float*)dBodyGetLinearVel(temp_r5_4->m_bodyID);
                                nlVector3::Set(out, v[0], v[1], v[2]);
                                return;
                            }
                            float* v = (float*)dBodyGetLinearVel(temp_r3_3->m_bodyID);
                            out->x = v[0];
                            out->y = v[1];
                            out->z = v[2];
                            return;
                        }
                        float* v = (float*)dBodyGetLinearVel(temp_r5_3->m_bodyID);
                        out->x = v[0];
                        out->y = v[1];
                        out->z = v[2];
                        return;
                    }
                    float* v = (float*)dBodyGetLinearVel(temp_r3_2->m_bodyID);
                    out->x = v[0];
                    out->y = v[1];
                    out->z = v[2];
                    return;
                }
                float* v = (float*)dBodyGetLinearVel(temp_r5_2->m_bodyID);
                out->x = v[0];
                out->y = v[1];
                out->z = v[2];
                return;
            }
            float* v = (float*)dBodyGetLinearVel(temp_r3->m_bodyID);
            out->x = v[0];
            out->y = v[1];
            out->z = v[2];
            return;
        }
        float* v = (float*)dBodyGetLinearVel(temp_r5->m_bodyID);
        out->x = v[0];
        out->y = v[1];
        out->z = v[2];
        return;
    }
    float* v = (float*)dBodyGetLinearVel(m_bodyID);
    out->x = v[0];
    out->y = v[1];
    out->z = v[2];
}

/**
 * Offset/Address/Size: 0xA00 | 0x802006FC | size: 0x30
 */
void PhysicsObject::SetLinearVelocity(const nlVector3& velocity)
{
    dBodySetLinearVel(m_bodyID, velocity.x, velocity.y, velocity.z);
}

/**
 * Offset/Address/Size: 0xA30 | 0x8020072C | size: 0x1E0
 */
void PhysicsObject::GetRotation(nlMatrix4*) const
{
}

/**
 * Offset/Address/Size: 0xC10 | 0x8020090C | size: 0xAC
 */
void PhysicsObject::SetRotation(const nlMatrix4&)
{
}

/**
 * Offset/Address/Size: 0xCBC | 0x802009B8 | size: 0x94
 */
void PhysicsObject::SetRotation(const nlMatrix3&)
{
}

/**
 * Offset/Address/Size: 0xD50 | 0x80200A4C | size: 0x34
 */
nlVector3* PhysicsObject::GetPosition()
{
    GetPosition((nlVector3*)m_position);
    return this->m_position;
}

/**
 * Offset/Address/Size: 0xD84 | 0x80200A80 | size: 0x32C
 */
void PhysicsObject::GetPosition(nlVector3* position) const
{

    //   undefined4 uVar1;
    //   undefined4 *puVar2;
    //   float *pfVar3;
    //   undefined4 uVar4;
    //   nlVector3 *pnVar5;
    //   int iVar6;
    //   int iVar7;
    //   nlVector3 anStack_1b8 [12];
    //   float local_1ac;
    //   float local_1a8;
    //   float local_1a4;
    //   float local_1a0;
    //   float local_19c;
    //   float local_198;
    //   nlMatrix4 anStack_194 [64];
    //   nlMatrix4 anStack_154 [64];
    //   nlMatrix4 anStack_114 [64];
    //   undefined1 auStack_d4 [64];
    //   undefined1 auStack_94 [64];
    //   nlMatrix4 anStack_54 [12];
    //   float local_48;
    //   float local_38;
    //   float local_28;
    //   float local_24;
    //   float local_20;
    //   float local_1c;
    //   float local_18;

    //   if ((*(int *)(this + 8) == 0) && (*(int *)(this + 4) != 0)) {
    //     puVar2 = (undefined4 *)ode::dBodyGetPosition();
    //   }
    //   else {
    //     puVar2 = (undefined4 *)collision_kernel::dGeomGetPosition(*(int *)(this + 8));
    //   }

    // /* 0x04 */ dBodyID m_bodyID;
    // /* 0x08 */ dGeomID m_geomID;

    const float* pos;
    if (m_geomID == NULL && m_bodyID != NULL)
    {
        pos = dBodyGetPosition(m_bodyID);
    }
    else
    {
        pos = dGeomGetPosition(m_geomID);
    }

    //   uVar4 = puVar2[2];
    //   uVar1 = puVar2[1];
    //   iVar7 = *(int *)(this + 0xc);
    //   *(undefined4 *)param_1 = *puVar2;
    //   *(undefined4 *)(param_1 + 4) = uVar1;
    //   *(undefined4 *)(param_1 + 8) = uVar4;
    //   if (iVar7 != 0) {
    //     if ((*(int *)(iVar7 + 8) == 0) && (*(int *)(iVar7 + 4) != 0)) {
    //       pfVar3 = (float *)ode::dBodyGetPosition();
    //     }
    //     else {
    //       pfVar3 = (float *)collision_kernel::dGeomGetPosition(*(int *)(iVar7 + 8));
    //     }
    //     local_198 = pfVar3[2];
    //     local_19c = pfVar3[1];
    //     local_1a0 = *pfVar3;
    //     iVar6 = *(int *)(iVar7 + 0xc);
    //     if (iVar6 != 0) {
    //       if ((*(int *)(iVar6 + 8) == 0) && (*(int *)(iVar6 + 4) != 0)) {
    //         pfVar3 = (float *)ode::dBodyGetPosition();
    //       }
    //       else {
    //         pfVar3 = (float *)collision_kernel::dGeomGetPosition(*(int *)(iVar6 + 8));
    //       }
    //       ::nlVector3::Set((nlVector3 *)&local_1ac,*pfVar3,pfVar3[1],pfVar3[2]);
    //       if (*(PhysicsObject **)(iVar6 + 0xc) != NULL) {
    //         GetPosition(*(PhysicsObject **)(iVar6 + 0xc),anStack_1b8);
    //         GetRotation(*(PhysicsObject **)(iVar6 + 0xc),anStack_114);
    //         platvmath::nlMultPosVectorMatrix(&local_1ac,&local_1ac,anStack_114);
    //         nlVecAdd(&local_1ac,anStack_1b8,&local_1ac);
    //       }
    //       iVar7 = *(int *)(iVar7 + 0xc);
    //       if ((*(int *)(iVar7 + 8) == 0) && (*(int *)(iVar7 + 4) != 0)) {
    //         uVar4 = ode::dBodyGetRotation();
    //       }
    //       else {
    //         uVar4 = collision_kernel::dGeomGetRotation(*(int *)(iVar7 + 8));
    //       }
    //       ConvertDMat3ToNLMat4(uVar4,auStack_94);
    //       if (*(PhysicsObject **)(iVar7 + 0xc) != NULL) {
    //         GetRotation(*(PhysicsObject **)(iVar7 + 0xc),anStack_154);
    //         platvmath::nlMultMatrices(auStack_94,auStack_94,anStack_154);
    //       }
    //       platvmath::nlMultPosVectorMatrix(&local_1a0,&local_1a0,auStack_94);
    //       ::nlVector3::Set((nlVector3 *)&local_1a0,local_1ac + local_1a0,local_1a8 + local_19c,
    //                        local_1a4 + local_198);
    //     }
    //     iVar7 = *(int *)(this + 0xc);
    //     if ((*(int *)(iVar7 + 8) == 0) && (*(int *)(iVar7 + 4) != 0)) {
    //       pnVar5 = (nlVector3 *)ode::dBodyGetRotation();
    //     }
    //     else {
    //       pnVar5 = (nlVector3 *)collision_kernel::dGeomGetRotation(*(int *)(iVar7 + 8));
    //     }
    //     ::nlMatrix4::SetColumn(anStack_54,0,pnVar5);
    //     ::nlMatrix4::SetColumn(anStack_54,1,pnVar5 + 0x10);
    //     ::nlMatrix4::SetColumn(anStack_54,2,pnVar5 + 0x20);
    //     local_24 = @442;
    //     local_20 = @442;
    //     local_1c = @442;
    //     local_18 = @443;
    //     local_48 = @442;
    //     local_38 = @442;
    //     local_28 = @442;
    //     iVar7 = *(int *)(iVar7 + 0xc);
    //     if (iVar7 != 0) {
    //       if ((*(int *)(iVar7 + 8) == 0) && (*(int *)(iVar7 + 4) != 0)) {
    //         uVar4 = ode::dBodyGetRotation();
    //       }
    //       else {
    //         uVar4 = collision_kernel::dGeomGetRotation(*(int *)(iVar7 + 8));
    //       }
    //       ConvertDMat3ToNLMat4(uVar4,auStack_d4);
    //       if (*(PhysicsObject **)(iVar7 + 0xc) != NULL) {
    //         GetRotation(*(PhysicsObject **)(iVar7 + 0xc),anStack_194);
    //         platvmath::nlMultMatrices(auStack_d4,auStack_d4,anStack_194);
    //       }
    //       platvmath::nlMultMatrices(anStack_54,anStack_54,auStack_d4);
    //     }
    //     platvmath::nlMultPosVectorMatrix(param_1,param_1,anStack_54);
    //     *(float *)param_1 = local_1a0 + *(float *)param_1;
    //     *(float *)(param_1 + 4) = local_19c + *(float *)(param_1 + 4);
    //     *(float *)(param_1 + 8) = local_198 + *(float *)(param_1 + 8);
    //   }
}

/**
 * Offset/Address/Size: 0x10B0 | 0x80200DAC | size: 0x118
 */
void PhysicsObject::SetPosition(const nlVector3&, PhysicsObject::CoordinateType)
{
}

/**
 * Offset/Address/Size: 0x11C8 | 0x80200EC4 | size: 0x20
 */
void PhysicsObject::PostUpdate()
{
    CheckForNaN();
}

/**
 * Offset/Address/Size: 0x11E8 | 0x80200EE4 | size: 0x78
 */
void PhysicsObject::PreUpdate()
{
    dMass m;
    if ((m_bodyID != 0) && (m_parentObject == 0))
    {
        dMassSetZero(&m);
        dBodyGetMass(m_bodyID, &m);
        dBodyAddForce(m_bodyID, 0.f, 0.f, m_gravity * m.mass);
    }
    CheckForNaN();
}

/**
 * Offset/Address/Size: 0x1260 | 0x80200F5C | size: 0x48
 */
void PhysicsObject::CheckForNaN()
{
    dBodyGetForce(m_bodyID);
    dBodyGetTorque(m_bodyID);
    // GetPosition();
    // GetLinearVelocity();
}

/**
 * Offset/Address/Size: 0x12A8 | 0x80200FA4 | size: 0x24
 */
void PhysicsObject::SetCategory(unsigned int categoryBits)
{
    dGeomSetCategoryBits(m_geomID, categoryBits);
}

/**
 * Offset/Address/Size: 0x12CC | 0x80200FC8 | size: 0x24
 */
void PhysicsObject::SetCollide(unsigned int collideBits)
{
    dGeomSetCollideBits(m_geomID, collideBits);
}

/**
 * Offset/Address/Size: 0x12F0 | 0x80200FEC | size: 0x40
 */
void PhysicsObject::SetDefaultCollideBits()
{
    dGeomSetCollideBits(m_geomID, 2);
    dGeomSetCategoryBits(m_geomID, 2);
}

/**
 * Offset/Address/Size: 0x1330 | 0x8020102C | size: 0x88
 */
PhysicsObject::~PhysicsObject()
{
    //   if (this != NULL) {
    //     *(undefined1 **)this = &__vt;
    //     if (*(int *)(this + 4) != 0) {

    if (m_bodyID != nullptr)
    {
        dBodyDestroy(m_bodyID);
        m_bodyID = nullptr;
    }

    if (m_geomID != nullptr)
    {
        dGeomDestroy(m_geomID);
        m_geomID = nullptr;
    }
}

/**
 * Offset/Address/Size: 0x13B8 | 0x802010B4 | size: 0x7C
 */
PhysicsObject::PhysicsObject(PhysicsWorld* world)
{
    //   undefined4 uVar1;
    //   *(undefined1 **)this = &__vt;

    m_bodyID = NULL;
    m_geomID = NULL;
    m_parentObject = NULL;
    m_gravity = DefaultGravity;

    if (world != NULL)
    {
        m_bodyID = dBodyCreate(world->m_worldID);
        dBodySetData(m_bodyID, this);
        dBodySetGravityMode(m_bodyID, 0);
    }
}
