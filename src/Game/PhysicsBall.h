#ifndef _PHYSICSBALL_H_
#define _PHYSICSBALL_H_

#include "PhysicsSphere.h"

class PhysicsBall : public PhysicsSphere
{
public:
    void CalcAngularFromLinearVelocity(nlVector3&);
    void SetUseAngularVelocity(bool);
    void ScaleAngularVelocity(float);
    void AddResistanceForces();
    virtual void Contact(PhysicsObject*, dContact*, int);
    void CloneBall(const PhysicsBall&);
    virtual void PostUpdate();
    virtual void PreUpdate();
    virtual void PreCollide();
    virtual void SetContactInfo(dContact*, PhysicsObject*, bool);
    float GetBallMaxVelocity();

    PhysicsBall(CollisionSpace*, PhysicsWorld*, float);

    u8 _padding0[10];
    /* 0x37 */ u8 m_unk_0x37;
    /* 0x38 */ u8 m_unk_0x38;
    /* 0x39 */ u8 m_unk_0x39;
    /* 0x3a */ u8 m_unk_0x3a;
    /* 0x3b */ u8 m_unk_0x3b;
    /* 0x3c */ float m_angularVelocity;
};

#endif // _PHYSICSBALL_H_
