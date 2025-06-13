#include "PhysicsBall.h"

#include "CollisionSpace.h"
#include "NL/nlFont.h"
#include "NL/nlMath.h"
#include "PhysicsObject.h"

float g_BallFriction = 3.f;
float g_BallFrictionWall = 4.f;
float g_BallBounce = 0.25f;
float g_BallBounceGround = 0.375f;
float g_BallBounceWall = 0.45f;
float g_BallRollingResistance = 5.f;
float g_BallAirResistance = 0.1f;

/**
 * Offset/Address/Size: 0x0 | 0x80134D14 | size: 0xD4
 */
void PhysicsBall::CalcAngularFromLinearVelocity(nlVector3& v)
{
    nlVector3 t2, t1;
    nlVector3 velocity;
    GetLinearVelocity(&velocity);
    t1 = nlVector3(0.f, 0.f, 0.f);
    float dVar1 = 1.f / GetRadius();
    t2 = nlVector3(0.f, 0.f, 0.f);

    v.x = (t1.y * t2.z) - (dVar1 * velocity.y);
    v.y = (-t1.x * t2.z) + (dVar1 * velocity.x);
    v.z = (t1.x * velocity.y) - (t1.y * velocity.x);

    // nlVector3 velocity;
    // nlVector3 temp(0.f, 0.f, 0.f);
    // GetLinearVelocity(&velocity);
    // float dVar1 = 1.f / GetRadius();
    // v.x = - (dVar1 * velocity.y);
    // v.y = (dVar1 * velocity.x);
    // v.z = 0.f;
}

/**
 * Offset/Address/Size: 0xD4 | 0x80134DE8 | size: 0x28
 */
void PhysicsBall::SetUseAngularVelocity(bool param_1)
{
    m_unk_0x3a = 0;
    if (param_1)
    {
        m_angularVelocity = 0.08f;
        return;
    }
    m_angularVelocity = 0.f;
}

/**
 * Offset/Address/Size: 0xFC | 0x80134E10 | size: 0x80
 */
void PhysicsBall::ScaleAngularVelocity(float scale)
{
    nlVector3 v;
    if (m_unk_0x3a != 0)
    {
        GetAngularVelocity(&v);
        v.z = scale * v.z;
        v.x = scale * v.x;
        v.y = scale * v.y;
        SetAngularVelocity(v);
    }
}

/**
 * Offset/Address/Size: 0x17C | 0x80134E90 | size: 0x51C
 */
void PhysicsBall::AddResistanceForces()
{
    // float fVar1;
    // FixedUpdateTask* this_00;
    // int iVar2;
    // undefined4 uVar3;
    // double dVar4;
    // undefined8 in_f29;
    // double dVar5;
    // undefined8 in_f30;
    // double dVar6;
    // undefined8 in_f31;
    // double dVar7;
    // float local_d8;
    // float local_d4;
    // float local_d0;
    // float local_cc;
    // float local_c8;
    // float local_c4;
    // float local_c0;
    // float local_bc;
    // float local_b4;
    // float local_b0;
    // float local_ac;
    // float local_a8;
    // float local_a4;
    // undefined4 local_a0;
    // float local_9c;
    // float local_98;
    // float local_94;
    // float local_90;
    // float local_8c;
    // float local_88;
    // float local_84;
    // float local_80;
    // float local_7c;
    // float local_78;
    // float local_74;
    // float local_70;
    // float local_6c;
    // float local_68;
    // float local_64;
    // float local_60;
    // float local_5c;
    // float local_58;
    // float local_54;
    // float local_50;
    // float local_4c;
    // float local_48;
    // float local_44;
    // float local_40;
    // undefined1 auStack_28[16];
    // undefined1 auStack_18[16];
    // undefined1 auStack_8[8];

    // uVar3 = 0;
    // __psq_st0(auStack_8, (int)((ulonglong)in_f31 >> 0x20), 0);
    // __psq_st1(auStack_8, (int)in_f31, 0);
    // __psq_st0(auStack_18, (int)((ulonglong)in_f30 >> 0x20), 0);
    // __psq_st1(auStack_18, (int)in_f30, 0);
    // __psq_st0(auStack_28, (int)((ulonglong)in_f29 >> 0x20), 0);
    // __psq_st1(auStack_28, (int)in_f29, 0);
    // this_00 = (FixedUpdateTask*)PhysicsObject::GetLinearVelocity((PhysicsObject*)this);
    // local_48 = *(float*)this_00;
    // local_44 = *(float*)(this_00 + 4);
    // local_40 = *(float*)(this_00 + 8);
    // if (*(int*)&this->field_0xc == 0)
    // {
    //     if ((this->field_0x39 != '\0') && (*(char*)&this->m_unk_0x3a == '\0'))
    //     {
    //         dVar5 = (double)local_44;
    //         dVar6 = (double)local_40;
    //         dVar4 = (double)nlMath::nlSqrt((double)((float)(dVar6 * dVar6) + local_48 * local_48 + (float)(dVar5 * dVar5)), 1);
    //         if ((double)@575 < dVar4)
    //         {
    //             dVar4 = (double)(float)(-(double)g_BallRollingResistance / dVar4);
    //             local_54 = (float)(dVar4 * (double)local_48);
    //             local_50 = (float)(dVar4 * dVar5);
    //             local_4c = (float)(dVar4 * dVar6);
    //             PhysicsObject::AddForceAtCentreOfMass((PhysicsObject*)this, (nlVector3*)&local_54);
    //         }
    //     }
    //     local_4c = -g_BallAirResistance;
    //     local_54 = local_4c * local_48;
    //     local_50 = local_4c * local_44;
    //     local_4c = local_4c * local_40;
    //     this_00 = (FixedUpdateTask*)PhysicsObject::AddForceAtCentreOfMass((PhysicsObject*)this, (nlVector3*)&local_54);
    // }

    // if ((this->field_0x38 != '\0') && (*(int*)(Ball::g_pBall + 0x30) == 0))
    // {
    //     this_00 = (FixedUpdateTask*)0x0;
    //     if ((*(int*)(Ball::g_pBall + 8) != 0) && (*(char*)(Ball::g_pBall + 0xa2) != '\0'))
    //     {
    //         this_00 = (FixedUpdateTask*)0x1;
    //     }
    //     if (this_00 == (FixedUpdateTask*)0x0)
    //     {
    //         this_00 = (FixedUpdateTask*)PhysicsObject::AddForceAtCentreOfMass((PhysicsObject*)this, &this->field_0x2c);
    //     }
    // }

    // if (@393 < this->m_angularVelocity)
    // {
    //     dVar4 = (double)FixedUpdateTask::GetPhysicsUpdateTick(this_00);
    //     fVar1 = @393;
    //     this->m_angularVelocity = (float)((double)this->m_angularVelocity - dVar4);
    //     if (this->m_angularVelocity <= fVar1)
    //     {
    //         *(undefined1*)&this->m_unk_0x3a = 1;
    //     }
    // }

    // if ((*(int*)&this->field_0xc == 0) && (*(char*)&this->m_unk_0x3a != '\0'))
    // {
    //     dVar4 = (double)PhysicsSphere::GetRadius((PhysicsSphere*)this);
    //     dVar4 = (double)(float)((double)@576 + dVar4);
    //     iVar2 = PhysicsObject::GetPosition((PhysicsObject*)this);
    //     if ((double)*(float*)(iVar2 + 8) < dVar4)
    //     {
    //         PhysicsObject::GetLinearVelocity((PhysicsObject*)this, (nlVector3*)&local_c0);
    //         local_b4 = 0.0;
    //         local_b0 = 0.0;
    //         local_ac = 0.0;
    //         dVar4 = (double)PhysicsSphere::GetRadius((PhysicsSphere*)this);
    //         local_ac = (float)((double)@411 / dVar4);
    //         local_a0 = 0;
    //         dVar7 = (double)(local_b0 * 0.0 - local_ac * local_bc);
    //         dVar6 = (double)(-local_b4 * 0.0 + local_ac * local_c0);
    //         dVar4 = (double)(local_b4 * local_bc - local_b0 * local_c0);
    //         local_a8 = local_c0;
    //         local_a4 = local_bc;
    //         PhysicsObject::GetAngularVelocity((PhysicsObject*)this, (nlVector3*)&local_60);
    //         dVar5 = (double)(@577 * (float)(dVar4 - (double)local_58));
    //         dVar6 = (double)(@577 * (float)(dVar6 - (double)local_5c));
    //         dVar7 = (double)(@577 * (float)(dVar7 - (double)local_60));
    //         ode::dBodyAddTorque(dVar7, dVar6, dVar5, *(undefined4*)&this->field_0x4);
    //         PhysicsObject::GetAngularVelocity((PhysicsObject*)this, (nlVector3*)&local_d8);
    //         local_d0 = @393;
    //         local_cc = 0.0;
    //         local_c8 = 0.0;
    //         local_c4 = 0.0;
    //         dVar4 = (double)PhysicsSphere::GetRadius((PhysicsSphere*)this);
    //         local_c4 = (float)dVar4;
    //         local_64 = local_d8 * local_c8 - local_d4 * local_cc;
    //         local_68 = -local_d8 * (float)dVar4 + local_d0 * local_cc;
    //         local_6c = local_d4 * (float)dVar4 - local_d0 * local_c8;
    //         PhysicsObject::GetLinearVelocity((PhysicsObject*)this, (nlVector3*)&local_78);
    //         local_64 = @578 * (local_64 - local_70);
    //         local_68 = @578 * (local_68 - local_74);
    //         local_6c = @578 * (local_6c - local_78);
    //         PhysicsObject::AddForceAtCentreOfMass((PhysicsObject*)this, (nlVector3*)&local_6c);
    //         local_64 = @393;
    //         if (((float)(dVar5 * dVar5 + (double)(float)(dVar7 * dVar7 + (double)(float)(dVar6 * dVar6))) < @579)
    //             && (@393 * @393 + local_6c * local_6c + local_68 * local_68 < @580))
    //         {
    //             *(undefined1*)&this->m_unk_0x3a = 0;
    //         }
    //     }
    // }
    // if ((*(int*)&this->field_0xc == 0) && ((char)this->m_unk_0x3a != '\0'))
    // {
    //     dVar4 = (double)PhysicsSphere::GetRadius((PhysicsSphere*)this);
    //     dVar4 = (double)(float)((double)@576 + dVar4);
    //     iVar2 = PhysicsObject::GetPosition((PhysicsObject*)this);
    //     if ((dVar4 < (double)*(float*)(iVar2 + 8))
    //         && ((PhysicsObject::GetLinearVelocity((PhysicsObject*)this, (nlVector3*)&local_84),
    //              @411 < local_7c * local_7c + local_84 * local_84 + local_80 * local_80
    //                  && (PhysicsObject::GetAngularVelocity((PhysicsObject*)this, (nlVector3*)&local_9c),
    //                      @411 < local_94 * local_94 + local_9c * local_9c + local_98 * local_98))))
    //     {
    //         local_88 = (local_9c * local_80 - local_98 * local_84) * @582;
    //         local_90 = (local_98 * local_7c - local_94 * local_80) * @581;
    //         local_8c = (-local_9c * local_7c + local_94 * local_84) * @581;
    //         PhysicsObject::AddForceAtCentreOfMass((PhysicsObject*)this, (nlVector3*)&local_90);
    //     }
    // }

    nlVector3* vp = GetLinearVelocity();
    float local_48 = vp->x;
    float local_44 = vp->y;
    float local_40 = vp->z;
    if (m_parentObject == 0)
    {
        if (m_unk_0x39 != 0 && m_unk_0x3a == 0)
        {
            float dVar5 = local_44;
            float dVar6 = local_40;
            float dVar4 = nlSqrt((dVar6 * dVar6) + (local_48 * local_48) + (dVar5 * dVar5), 1);
            if (0.01 < dVar4)
            {
                dVar4 = -g_BallRollingResistance / dVar4;
                float local_54 = dVar4 * local_48;
                float local_50 = dVar4 * dVar5;
                float local_4c = dVar4 * dVar6;
                AddForceAtCentreOfMass(nlVector3(local_54, local_50, local_4c));
            }
        }
        float local_4c = -g_BallAirResistance;
        float local_54 = local_4c * local_48;
        float local_50 = local_4c * local_44;
        local_4c = local_4c * local_40;
        AddForceAtCentreOfMass(nlVector3(local_54, local_50, local_4c));
    }

    // bool b;
    // if ((m_unk_0x38 != 0) /*&& (*(int*)(Ball::g_pBall + 0x30) == 0)*/)
    // {
    //     b = false;
    //     if ((*(int*)(Ball::g_pBall + 8) != 0) && (*(char*)(Ball::g_pBall + 0xa2) != '\0'))
    //     {
    //         b = true;
    //     }
    //     if (!b)
    //     {
    //         AddForceAtCentreOfMass(field_0x2c);
    //     }
    // }

    // if (0.f < m_angularVelocity)
    // {
    //     dVar4 = (double)FixedUpdateTask::GetPhysicsUpdateTick(this_00);
    //     fVar1 = 0.f;
    //     this->m_angularVelocity = (float)((double)this->m_angularVelocity - dVar4);
    //     if (this->m_angularVelocity <= fVar1)
    //     {
    //         *(undefined1*)&this->m_unk_0x3a = 1;
    //     }
    // }

    if ((m_parentObject == 0) && (m_unk_0x3a != 0))
    {
        float dVar4 = GetRadius();
        dVar4 = 0.02f + dVar4;
        // iVar2 = PhysicsObject::GetPosition((PhysicsObject*)this);
        nlVector3* pos = GetPosition();
        // if ((dVar4 < (double)*(float*)(iVar2 + 8))
        // && ((PhysicsObject::GetLinearVelocity((PhysicsObject*)this, (nlVector3*)&local_84),
        // if ((dVar4 < pos.z) && (GetLinearVelocity((PhysicsObject*)this, (nlVector3*)&local_84),
        //          @411 < local_7c * local_7c + local_84 * local_84 + local_80 * local_80
        //              && (PhysicsObject::GetAngularVelocity((PhysicsObject*)this, (nlVector3*)&local_9c),
        //                  @411 < local_94 * local_94 + local_9c * local_9c + local_98 * local_98))))
        // {
        //     local_88 = (local_9c * local_80 - local_98 * local_84) * @582;
        //     local_90 = (local_98 * local_7c - local_94 * local_80) * @581;
        //     local_8c = (-local_9c * local_7c + local_94 * local_84) * @581;
        //     PhysicsObject::AddForceAtCentreOfMass((PhysicsObject*)this, (nlVector3*)&local_90);
        // }
    }
}

/**
 * Offset/Address/Size: 0x698 | 0x801353AC | size: 0x250
 */
void PhysicsBall::Contact(PhysicsObject*, dContact*, int)
{
}

/**
 * Offset/Address/Size: 0x8E8 | 0x801355FC | size: 0x78
 */
void PhysicsBall::CloneBall(const PhysicsBall&)
{
}

/**
 * Offset/Address/Size: 0x960 | 0x80135674 | size: 0x164
 */
void PhysicsBall::PostUpdate()
{
}

/**
 * Offset/Address/Size: 0xAC4 | 0x801357D8 | size: 0xAC
 */
void PhysicsBall::PreUpdate()
{
    float l, n;
    nlVector3 vec;
    GetLinearVelocity(&vec);

    if (2500.f < vec.x * vec.x + vec.y * vec.y + vec.z * vec.z)
    {
        float l = nlSqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z, true);
        float n = 50.f / l;
        vec.x = vec.x * n;
        vec.y = vec.y * n;
        vec.z = vec.z * n;
        SetLinearVelocity(vec);
    }
    PhysicsObject::PreUpdate();
    AddResistanceForces();
}

/**
 * Offset/Address/Size: 0xB70 | 0x80135884 | size: 0xC
 */
void PhysicsBall::PreCollide()
{
}

/**
 * Offset/Address/Size: 0xB7C | 0x80135890 | size: 0x114
 */
void PhysicsBall::SetContactInfo(dContact*, PhysicsObject*, bool)
{
}

/**
 * Offset/Address/Size: 0xC90 | 0x801359A4 | size: 0x8
 */
float PhysicsBall::GetBallMaxVelocity()
{
    return 50.0;
}

/**
 * Offset/Address/Size: 0xC98 | 0x801359AC | size: 0x88
 */
PhysicsBall::PhysicsBall(CollisionSpace* space, PhysicsWorld* world, float radius)
    : PhysicsSphere(space, world, radius)
{
    SetCategory(0x20);
    SetCollide(0xaf);
}
