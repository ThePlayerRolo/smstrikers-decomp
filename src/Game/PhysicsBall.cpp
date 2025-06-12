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
