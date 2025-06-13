#include "NL/math.h"
#include "NL/nlMath.h"
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
    mat4->m[0][0] = (f32)mat3[0];
    mat4->m[1][0] = (f32)mat3[1];
    mat4->m[2][0] = (f32)mat3[2];
    mat4->m[0][1] = (f32)mat3[4];
    mat4->m[1][1] = (f32)mat3[5];
    mat4->m[2][1] = (f32)mat3[6];
    mat4->m[0][2] = (f32)mat3[8];
    mat4->m[1][2] = (f32)mat3[9];
    mat4->m[2][2] = (f32)mat3[10];
    mat4->m[0][3] = 1.0f;
    mat4->m[1][3] = 1.0f;
    mat4->m[2][3] = 1.0f;
    mat4->m[3][3] = 0.0f;
    mat4->m[0][3] = 1.0f;
    mat4->m[1][3] = 1.0f;
    mat4->m[2][3] = 1.0f;
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
    if (m_parentObject != NULL)
    {
        // return this->m_parentObject->Contact(obj1, contact, param, obj2);
        return this->m_parentObject->PreCollide();
    }
    return 3;
}

/**
 * Offset/Address/Size: 0x25C | 0x801FFF58 | size: 0x30
 */
int PhysicsObject::Contact(PhysicsObject* obj1, dContact* contact, int param)
{
    // return obj1->Contact(obj1, contact, param, NULL);
    // return obj1->Contact(obj1, contact, param);
    return obj1->PreCollide();
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
void PhysicsObject::Reconnect(dSpaceID space)
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
dSpaceID PhysicsObject::Disconnect()
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
    return space;
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
    mat[0] = in.m[0][0];
    mat[1] = in.m[1][0];
    mat[2] = in.m[2][0];
    mat[3] = in.m[3][0];
    mat[4] = in.m[0][1];
    mat[5] = in.m[1][1];
    mat[6] = in.m[2][1];
    mat[7] = in.m[3][1];
    mat[8] = in.m[0][2];
    mat[9] = in.m[1][2];
    mat[10] = in.m[2][2];
    mat[11] = in.m[3][2];

    if ((m_geomID == 0) && (m_bodyID != 0))
    {
        dBodySetRotation(m_bodyID, mat);
    }
    else
    {
        dGeomSetRotation(m_geomID, mat);
    }

    nlVector3* pos = (nlVector3*)&(in.m[0][3]);
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
nlVector3* PhysicsObject::GetLinearVelocity()
{
    GetLinearVelocity(&m_linearVelocity);
    return &m_linearVelocity;
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

// /* 0x04 */ dBodyID m_bodyID;
// /* 0x08 */ dGeomID m_geomID;
// /* 0x0c */ PhysicsObject *m_parentObject;
// /* 0x10 */ float m_gravity;
// /* 0x14 */ nlVector3 m_position;
// /* 0x20 */ nlVector3 m_linearVelocity;
// typedef dReal dMatrix3[4*3];
void PhysicsObject::GetRotation(nlMatrix4* m_out) const
{
    volatile dMatrix3* rot;
    if ((m_geomID == NULL) && (m_bodyID != NULL))
    {
        rot = (dMatrix3*)dBodyGetRotation(m_bodyID);
    }
    else
    {
        rot = (dMatrix3*)dGeomGetRotation(m_geomID);
    }

    // # .sdata2:0x0 | 0x80377460 | size: 0x4
    // .obj "@442", local
    // 	.float 0
    // .endobj "@442"

    // # .sdata2:0x4 | 0x80377464 | size: 0x4
    // .obj "@443", local
    // 	.float 1
    // .endobj "@443"

    m_out->m[0][0] = *rot[0];
    m_out->m[1][0] = *rot[1];
    m_out->m[2][0] = *rot[2];
    m_out->m[0][1] = *rot[4];
    m_out->m[1][1] = *rot[5];
    m_out->m[2][1] = *rot[6];
    m_out->m[0][2] = *rot[8];
    m_out->m[1][2] = *rot[9];
    m_out->m[2][2] = *rot[10];
    m_out->m[3][0] = 0.f;
    m_out->m[3][1] = 0.f;
    m_out->m[3][2] = 0.f;
    m_out->m[3][3] = 1.f;
    m_out->m[0][3] = 0.f;
    m_out->m[1][3] = 0.f;
    m_out->m[2][3] = 0.f;

    if (m_parentObject != NULL)
    {
        dMatrix3* parent_rot; // var_r30
        if ((m_parentObject->m_geomID == NULL) && (m_parentObject->m_bodyID != NULL))
        {
            parent_rot = (dMatrix3*)dBodyGetRotation(m_parentObject->m_bodyID);
        }
        else
        {
            parent_rot = (dMatrix3*)dGeomGetRotation(m_parentObject->m_geomID);
        }

        nlMatrix4 sp88;
        sp88.SetColumn(0, *(nlVector3*)parent_rot);
        sp88.SetColumn(1, *(nlVector3*)parent_rot[4]);
        sp88.SetColumn(2, *(nlVector3*)parent_rot[8]);
        sp88.m[3][0] = 0.f;
        sp88.m[3][1] = 0.f;
        sp88.m[3][2] = 0.f;
        sp88.m[3][3] = 1.f;
        sp88.m[0][3] = 0.f;
        sp88.m[1][3] = 0.f;
        sp88.m[2][3] = 0.f;

        PhysicsObject* temp_r29_2 = m_parentObject;
        if (temp_r29_2 != NULL)
        {
            dGeomID temp_r0_3 = temp_r29_2->m_geomID;
            dMatrix3* parent_parent_rot; // var_r30
            if ((temp_r0_3 == 0U) && ((u32)temp_r29_2->m_bodyID != 0U))
            {
                parent_parent_rot = (dMatrix3*)dBodyGetRotation(temp_r29_2->m_bodyID);
            }
            else
            {
                parent_parent_rot = (dMatrix3*)dGeomGetRotation(temp_r0_3);
            }

            nlMatrix4 sp48;
            ConvertDMat3ToNLMat4((float*)parent_parent_rot, &sp48);
            if (temp_r29_2->m_parentObject != 0U)
            {
                nlMatrix4 sp8;
                GetRotation(&sp8);
                nlMultMatrices(sp48, sp48, sp8);
            }
            nlMultMatrices(sp88, sp88, sp48);
        }
        nlMultMatrices(*m_out, *m_out, sp88);
    }
}

/**
 * Offset/Address/Size: 0xC10 | 0x8020090C | size: 0xAC
 */
void PhysicsObject::SetRotation(const nlMatrix4& m4_in)
{
    // f32 sp34;
    // f32 sp30;
    // f32 sp2C;
    // f32 sp28;
    // f32 sp24;
    // f32 sp20;
    // f32 sp1C;
    // f32 sp18;
    // f32 sp14;
    // f32 sp10;
    // f32 spC;
    // f32 sp8;

    dMatrix3 mat;
    mat[0] = m4_in.m[0][0];
    mat[1] = m4_in.m[1][0];
    mat[2] = m4_in.m[2][0];
    mat[3] = m4_in.m[3][0];
    mat[4] = m4_in.m[0][1];
    mat[5] = m4_in.m[1][1];
    mat[6] = m4_in.m[2][1];
    mat[7] = m4_in.m[3][1];
    mat[8] = m4_in.m[0][2];
    mat[9] = m4_in.m[1][2];
    mat[10] = m4_in.m[2][2];
    mat[11] = m4_in.m[3][2];
    // sp8 = arg1->unk0;
    // spC = arg1->unk10;
    // sp10 = arg1->unk20;
    // sp14 = arg1->unk30;
    // sp18 = arg1->unk4;
    // sp1C = arg1->unk14;
    // sp20 = arg1->unk24;
    // sp24 = arg1->unk34;
    // sp28 = arg1->unk8;
    // sp2C = arg1->unk18;
    // sp30 = arg1->unk28;
    // sp34 = arg1->unk38;

    if ((m_geomID == NULL) && (m_bodyID != NULL))
    {
        dBodySetRotation(m_bodyID, mat);
        return;
    }
    dGeomSetRotation(m_geomID, mat);
}

/**
 * Offset/Address/Size: 0xCBC | 0x802009B8 | size: 0x94
 */
void PhysicsObject::SetRotation(const nlMatrix3& m3_in)
{
    dMatrix3 mat;
    mat[1] = m3_in.m[3];
    mat[2] = m3_in.m[6];
    mat[0] = m3_in.m[0];
    mat[6] = m3_in.m[7];
    mat[5] = m3_in.m[4];
    mat[4] = m3_in.m[1];
    mat[10] = m3_in.m[8];
    mat[9] = m3_in.m[5];
    mat[8] = m3_in.m[2];

    if ((m_geomID == NULL) && (m_bodyID != NULL))
    {
        dBodySetRotation(m_bodyID, mat);
        return;
    }
    dGeomSetRotation(m_geomID, mat);
}

/**
 * Offset/Address/Size: 0xD50 | 0x80200A4C | size: 0x34
 */
nlVector3* PhysicsObject::GetPosition()
{
    GetPosition(&m_position);
    return &m_position;
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
void PhysicsObject::SetPosition(const nlVector3& pos, PhysicsObject::CoordinateType type)
{
    nlMatrix4 rot;         // sp54
    nlMatrix4 inv_rot;     // sp14
    nlVector3* p;          // temp_r3
    volatile nlVector4 v4; // sp84...sp90
    nlVector3 _pos;        // sp8...sp10

    if ((m_parentObject != NULL) && (type == 0))
    {
        m_parentObject->GetRotation(&rot);
        p = m_parentObject->GetPosition();
        v4.w = 1.f;
        v4.z = p->z;
        v4.y = p->y;
        v4.x = p->x;
        nlInvertRotTransMatrix(inv_rot, rot);
        nlMultPosVectorMatrix(_pos, pos, inv_rot);
        if ((m_geomID == NULL) && (m_bodyID != NULL))
        {
            dBodySetPosition(m_bodyID, _pos.x, _pos.y, _pos.z);
            return;
        }
        dGeomSetPosition(m_geomID, _pos.x, _pos.y, _pos.z);
        return;
    }

    if ((m_geomID == NULL) && (m_bodyID != NULL))
    {
        dBodySetPosition(m_bodyID, pos.x, pos.y, pos.z);
        return;
    }
    dGeomSetPosition(m_geomID, pos.x, pos.y, pos.z);
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

/**
 * Offset/Address/Size: 0x0 | 0x80201130 | size: 0x10
 */
void nlVector3::Set(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

/**
 * Offset/Address/Size: 0x10 | 0x80201140 | size: 0x24
 */
void nlMatrix4::SetColumn(int col, const nlVector3& v)
{
    m[0][col] = v.x;
    m[1][col] = v.y;
    m[2][col] = v.z;
}

/**
 * Offset/Address/Size: 0x34 | 0x80201164 | size: 0x34
 */
void nlVecAdd(nlVector3& v0, const nlVector3& v1, const nlVector3& v2)
{
    v0.x = v1.x + v2.x;
    v0.y = v1.y + v2.y;
    v0.z = v1.z + v2.z;
}
