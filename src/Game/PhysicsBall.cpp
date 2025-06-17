#include "PhysicsBall.h"

#include "CollisionSpace.h"
#include "NL/nlFont.h"
#include "NL/nlMath.h"
#include "PhysicsObject.h"
#include "FixedUpdateTask.h"

#include "Ball.h"

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

// const uint vec_zero[3] __attribute__((section(".rodata"))) = {0, 0, 0};
const nlVector3 vec_zero __attribute__((section(".rodata"))) = nlVector3(0.f, 0.f, 0.f);

/**
 * Offset/Address/Size: 0x17C | 0x80134E90 | size: 0x51C
 */
void PhysicsBall::AddResistanceForces()
{
    nlVector3 local_88;
    nlVector3 local_7c; // 7c, 80, 84
    nlVector3 local_94; // 94, 98, 9c
    nlVector3 local_b8;
    nlVector3 local_ac;
    nlVector3 local_a0;
    nlVector3 local_58;
    nlVector3 local_d0;
    nlVector3 local_c4;
    nlVector3 local_64;
    nlVector3 local_70;
    nlVector3 sp98; // sp98 sp9C spA0
    nlVector3 sp8C; // sp8C sp90 sp94
    nlVector3 sp38; // sp38 sp3C sp40
    nlVector3 sp2C; // sp2C sp30 sp34
    nlVector3 sp20; // sp20 sp24 sp28
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f29;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f3;
    f32 temp_f3_2;
    s8 var_r3;

    nlVector3* temp_r3 = GetLinearVelocity();
    sp98.x = temp_r3->x;
    sp98.y = temp_r3->y;
    sp98.z = temp_r3->z;
    if (m_parentObject == NULL)
    {
        if ((m_unk_0x39 != 0) && (m_unk_0x3a == 0))
        {
            temp_f2 = sp98.z * sp98.z;
            temp_f1 = nlSqrt(temp_f2 + ((sp98.x * sp98.x) + (sp98.y * sp98.x)), 1);
            if (temp_f1 > 0.01f)
            {
                temp_f3 = -g_BallRollingResistance / temp_f1;
                temp_f2_2 = temp_f3 * sp98.x;
                temp_f1_2 = temp_f3 * sp98.y;
                sp8C.x = temp_f2_2;
                sp8C.y = temp_f1_2;
                sp8C.z = temp_f3 * sp98.z;
                AddForceAtCentreOfMass(sp8C);
            }
        }
        temp_f3_2 = -g_BallAirResistance;
        temp_f2_3 = temp_f3_2 * sp98.x;
        temp_f1_3 = temp_f3_2 * sp98.y;
        sp8C.x = temp_f2_3;
        sp8C.y = temp_f1_3;
        sp8C.z = temp_f3_2 * sp98.z; // sp94=z
        AddForceAtCentreOfMass(sp8C);
    }

    if ((m_unk_0x38 != 0) && (g_pBall->m_passTargetPlayer == NULL))
    {
        var_r3 = 0;
        if ((g_pBall->m_timer_0x08 != NULL) && (g_pBall->m_unk_0xA2 != 0))
        {
            var_r3 = 1;
        }
        if (var_r3 == 0)
        {
            AddForceAtCentreOfMass(m_unk_0x2c);
        }
    }

    if (m_angularVelocity > 0.f)
    {
        m_angularVelocity = m_angularVelocity - FixedUpdateTask::GetPhysicsUpdateTick();
        if (m_angularVelocity <= 0.f)
        {
            m_unk_0x3a = 1;
        }
    }

    if ((m_parentObject == NULL) && (m_unk_0x3a != 0))
    {
        temp_f29 = 0.02 + GetRadius();
        if (GetPosition()->z < temp_f29)
        {
            float dVar4 = GetRadius();
            dVar4 = 0.02f + dVar4;
            nlVector3* iVar2 = GetPosition();
            if (iVar2->z < dVar4)
            {
                GetLinearVelocity((nlVector3*)&local_b8); // b8 bc c0

                local_ac.z = 0.0;
                local_ac.y = 0.0;
                local_ac.x = 0.0; // ac, b0, b4

                dVar4 = GetRadius();

                local_ac.x = 1.f / dVar4;

                local_a0.x = 0; // a0, a4, a8
                float dVar7 = (local_ac.y * 0.0 - local_ac.x * local_b8.y);
                float dVar6 = (-local_ac.z * 0.0 + local_ac.x * local_b8.z);
                float dVar4 = (local_ac.z * local_b8.y - local_ac.y * local_b8.z);
                local_a0.z = local_b8.z;
                local_a0.y = local_b8.y;

                GetAngularVelocity(&local_58); // 58, 5c, 60

                float dVar5 = (0.25f * (float)(dVar4 - local_58.x));
                dVar6 = (0.25f * (float)(dVar6 - local_58.y));
                dVar7 = (0.25f * (float)(dVar7 - local_58.z));
                dBodyAddTorque(m_bodyID, dVar5, dVar6, dVar7);

                GetAngularVelocity(&local_d0); // d0, d4, d8
                local_d0.x = 0.f;

                local_c4.z = 0.f;
                local_c4.y = 0.f;
                local_c4.x = GetRadius(); // c4, c8, cc

                local_64.x = local_d0.z * local_c4.y - local_d0.y * local_c4.z;
                local_64.y = -local_d0.z * local_c4.x + local_d0.x * local_c4.z;
                local_64.z = local_d0.y * local_c4.x - local_d0.x * local_c4.y;

                GetLinearVelocity(&local_70); // 70 74 78
                local_64.x = 5.f * (local_64.x - local_70.x);
                local_64.y = 5.f * (local_64.y - local_70.y);
                local_64.z = 5.f * (local_64.z - local_70.z);

                AddForceAtCentreOfMass(local_64); // 64, 68, 6c

                local_64.x = 0.f;
                if (((dVar5 * dVar5) + (dVar7 * dVar7) + (dVar6 * dVar6) < 0.0001f)
                    && ((local_64.x * local_64.x) + (local_64.z * local_64.z) + (local_64.y * local_64.y) < 0.00003f))
                {
                    m_unk_0x3a = 0;
                }
            }
        }
    }

    if ((m_parentObject == NULL) && (m_unk_0x3b != 0))
    {
        float dVar4 = GetRadius();
        dVar4 = 0.02f + dVar4;

        nlVector3* iVar2 = GetPosition();
        if ((dVar4 < iVar2->z)
            && (GetLinearVelocity(&local_7c), 1.f < local_7c.x * local_7c.x + local_7c.z * local_7c.z + local_7c.y * local_7c.y)
            && (GetAngularVelocity(&local_94), 1.f < local_94.x * local_94.x + local_94.z * local_94.z + local_94.y * local_94.y))
        {
            local_88.x = (local_94.z * local_7c.y - local_94.y * local_7c.z) * 0.04f;
            local_88.z = (local_94.y * local_7c.x - local_94.x * local_7c.y) * 0.075f;
            local_88.y = (-local_94.z * local_7c.x + local_94.x * local_7c.z) * 0.075f;
            AddForceAtCentreOfMass(local_88);
        }
    }
}

/**
 * Offset/Address/Size: 0x698 | 0x801353AC | size: 0x250
 */
int PhysicsBall::Contact(PhysicsObject*, dContact*, int)
{
    return 1;
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
int PhysicsBall::PreCollide()
{
    m_unk_0x39 = 0;
    return 0;
}

/**
 * Offset/Address/Size: 0xB7C | 0x80135890 | size: 0x114
 */
int PhysicsBall::SetContactInfo(dContact*, PhysicsObject*, bool)
{
    return 0;
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
    m_unk_0x38 = 0;
    m_unk_0x39 = 0;
    m_unk_0x3a = 0;
    m_unk_0x3b = 0;
    m_angularVelocity = 0.f;

    SetCategory(0x20);
    SetCollide(0xaf);

    m_gravity = -14.f;

    float temp = 0.f;
    m_unk_0x2c.x = temp;
    m_unk_0x2c.y = temp;
    m_unk_0x2c.z = temp;
}
