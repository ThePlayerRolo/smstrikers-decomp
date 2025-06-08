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
};

#endif // _PHYSICSBALL_H_
