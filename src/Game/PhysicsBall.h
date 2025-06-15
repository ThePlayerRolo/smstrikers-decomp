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
    ~PhysicsBall();

    // /* ???? 0x2c */ nlVector3 m_unk_v3;
    /* 0x2c */ nlVector3 *m_unk_0x2c;
    /* 0x30 */ nlVector3 *m_unk_0x30;
    /* 0x34 */ nlVector3 *m_unk_0x34;

    /* 0x38 */ u8 m_unk_0x38;
    /* 0x39 */ u8 m_unk_0x39;
    /* 0x3a */ u8 m_unk_0x3a;
    /* 0x3b */ u8 m_unk_0x3b;
    /* 0x3c */ float m_angularVelocity;
    /* 0x40 */ int m_unk_0x40;
    /* 0x44 */ nlVector3 m_unk_0x44;
    /* 0x50 */ int m_unk_0x50;

};

#endif // _PHYSICSBALL_H_
