#include "PhysicsBall.h"

#include "CollisionSpace.h"
#include "NL/nlFont.h"
#include "NL/nlMath.h"
#include "PhysicsObject.h"
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

/**
 * Offset/Address/Size: 0x17C | 0x80134E90 | size: 0x51C
 */
void PhysicsBall::AddResistanceForces()
{
    // f32 spA0;
    // f32 sp9C;
    nlVector3 sp98; // sp98 sp9C spA0
    // f32 sp94;
    // f32 sp90;
    nlVector3 sp8C; // sp8C sp90 sp94
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp68;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f29_3;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f2_8;
    f32 temp_f30;
    f32 temp_f31;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f3_5;
    f32 temp_f3_6;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 temp_f5_3;
    f32 temp_f6;
    f64 temp_f1_5;
    s8 var_r3;
    nlVector3* temp_r3;

    //     /* 0x04 */ dBodyID m_bodyID;
    //     /* 0x08 */ dGeomID m_geomID;
    //     /* 0x0c */ PhysicsObject *m_parentObject;
    //     /* 0x10 */ float m_gravity;
    //     /* 0x14 */ nlVector3 m_position;
    //     /* 0x20 */ nlVector3 m_linearVelocity;

    // /* 0x2c */ nlVector3 m_unk_v3; ???

    // /* 0x2c */ nlVector3 *m_unk_0x2c;
    // /* 0x30 */ nlVector3 *m_unk_0x30;
    // /* 0x34 */ nlVector3 *m_unk_0x34;

    // /* 0x38 */ u8 m_unk_0x38;
    // /* 0x39 */ u8 m_unk_0x39;
    // /* 0x3a */ u8 m_unk_0x3a;
    // /* 0x3b */ u8 m_unk_0x3b;
    // /* 0x3c */ float m_angularVelocity;

    temp_r3 = GetLinearVelocity();
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

    // // if (((u8) arg0->unk38 != 0) && ((u32) g_pBall->unk30 == 0U)) {
    // if ((this->m_unk_0x38 != 0) && (g_pBall->m_unk_0x38 == NULL))
    // {
    //     var_r3 = 0;
    //     if ((g_pBall->m_geomID != NULL) && (g_pBall->m_unk_0xA2 != 0))
    //     {
    //         var_r3 = 1;
    //     }
    //     if (var_r3 == 0)
    //     {
    //         AddForceAtCentreOfMass(m_unk_0x2c);
    //     }
    // }
    /*
            if (this->unk3C > @393)
            {
                this->unk3C = (f32)(this->unk3C - GetPhysicsUpdateTick());
                M2C_ERROR(unknown instruction: cror eq, lt, eq);
                if (this->unk3C == @393)
                {
                    this->unk3A = 1U;
                }
            }
            if (((u32)this->unkC == NULL) && ((u8)this->unk3A != 0))
            {
                temp_f29 = @576 + GetRadius(this);
                if (GetPosition(this)->unk8 < temp_f29)
                {
                    GetLinearVelocity(this, &sp20);
                    sp2C = @364.unk0;
                    sp30 = @364.unk4;
                    sp34 = @364.unk8;
                    temp_f6 = @411 / GetRadius(this, @364.unk4, @364.unk0, &@364);
                    temp_f3_3 = temp_f6 * sp24;
                    sp40 = @365.unk8;
                    temp_f2_4 = -sp2C;
                    temp_f1_4 = temp_f6 * sp20;
                    sp38 = @365.unk0;
                    sp3C = @365.unk4;
                    sp34 = temp_f6;
                    sp38 = sp20;
                    sp3C = sp24;
                    GetAngularVelocity(this, &sp80, @365.unk0, &@365, temp_f1_4, temp_f2_4, temp_f3_3, sp24, sp20,
                                                                     temp_f6, sp40, sp30, sp2C);
                    temp_f29_2 = @577 * (((sp2C * sp24) - (sp30 * sp20)) - sp88);
                    temp_f30 = @577 * (((temp_f2_4 * sp40) + temp_f1_4) - sp84);
                    temp_f31 = @577 * (((sp30 * sp40) - temp_f3_3) - sp80);
                    dBodyAddTorque(this->unk4, temp_f31, temp_f30, temp_f29_2);
                    GetAngularVelocity(this, &sp8);
                    sp10 = @393;
                    sp14 = @369.unk0;
                    sp18 = @369.unk4;
                    sp1C = @369.unk8;
                    temp_f1_5 = GetRadius(this, @369.unk4, @369.unk0, &@369);
                    temp_f5 = (f32)temp_f1_5;
                    temp_f3_4 = -sp8;
                    sp1C = (f32)temp_f1_5;
                    temp_f2_5 = (temp_f3_4 * temp_f5) + (sp10 * sp14);
                    temp_f1_6 = (spC * temp_f5) - (sp10 * sp18);
                    sp7C = (sp8 * sp18) - (spC * sp14);
                    sp74 = temp_f1_6;
                    sp78 = temp_f2_5;
                    GetLinearVelocity(this, &sp68, temp_f1_6, temp_f2_5, temp_f3_4, sp10, temp_f5, spC, sp18, sp8);
                    temp_f4 = sp7C - sp70;
                    temp_f3_5 = sp78 - sp6C;
                    temp_f5_2 = @578 * temp_f4;
                    sp7C = temp_f4;
                    temp_f1_7 = sp74 - sp68;
                    temp_f2_6 = @578 * temp_f3_5;
                    sp78 = temp_f3_5;
                    sp74 = temp_f1_7;
                    sp78 = temp_f2_6;
                    sp74 = @578 * temp_f1_7;
                    sp7C = temp_f5_2;
                    AddForceAtCentreOfMass(this, &sp74, temp_f1_7, temp_f2_6, temp_f3_5, temp_f4, temp_f5_2);
                    sp7C = @393;
                    if ((((temp_f29_2 * temp_f29_2) + ((temp_f31 * temp_f31) + (temp_f30 * temp_f30))) < @579)
                        && (((@393 * @393) + ((sp74 * sp74) + (sp78 * sp78))) < @580))
                    {
                        this->unk3A = NULL;
                    }
                }
            }
            if (((u32)this->unkC == NULL) && ((u8)this->unk3B != 0))
            {
                temp_f29_3 = @576 + GetRadius(this);
                if (GetPosition(this)->unk8 > temp_f29_3)
                {
                    GetLinearVelocity(this, &sp5C);
                    if (((sp64 * sp64) + ((sp5C * sp5C) + (sp60 * sp60))) > @411)
                    {
                        GetAngularVelocity(this, &sp44);
                        if (((sp4C * sp4C) + ((sp44 * sp44) + (sp48 * sp48))) > @411)
                        {
                            temp_f4_2 = -sp44;
                            temp_f2_7 = (sp44 * sp60) - (sp48 * sp5C);
                            temp_f5_3 = (sp48 * sp64) - (sp4C * sp60);
                            temp_f3_6 = (temp_f4_2 * sp64) + (sp4C * sp5C);
                            sp58 = temp_f2_7;
                            temp_f2_8 = temp_f5_3 * @581;
                            sp50 = temp_f5_3;
                            temp_f1_8 = temp_f3_6 * @581;
                            sp54 = temp_f3_6;
                            sp50 = temp_f2_8;
                            sp54 = temp_f1_8;
                            sp58 = temp_f2_7 * @582;
                            AddForceAtCentreOfMass(this, &sp50, temp_f1_8, temp_f2_8, temp_f3_6, temp_f4_2, temp_f5_3, sp64);
                        }
                    }
                }
            }
        */
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
