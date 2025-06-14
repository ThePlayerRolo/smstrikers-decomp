#ifndef _PHYSICSBALL_H_
#define _PHYSICSBALL_H_

#include "NL/nlMath.h"
#include "PhysicsSphere.h"

class PhysicsBall : public PhysicsSphere
{
public:
    void CalcAngularFromLinearVelocity(nlVector3&);
    void SetUseAngularVelocity(bool);
    void ScaleAngularVelocity(float);
    void AddResistanceForces();
    virtual int Contact(PhysicsObject*, dContact*, int);
    void CloneBall(const PhysicsBall&);
    virtual void PostUpdate();
    virtual void PreUpdate();
    virtual int PreCollide();
    virtual int SetContactInfo(dContact*, PhysicsObject*, bool);
    float GetBallMaxVelocity();

    PhysicsBall(CollisionSpace*, PhysicsWorld*, float);

    /* 0x2c */ nlVector3 m_unk_v3;
    /* 0x38 */ u8 m_unk_0x38;
    /* 0x39 */ u8 m_unk_0x39;
    /* 0x3a */ u8 m_unk_0x3a;
    /* 0x3b */ u8 m_unk_0x3b;
    /* 0x3c */ float m_angularVelocity;
};

#endif // _PHYSICSBALL_H_
