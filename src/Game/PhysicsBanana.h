#ifndef _PHYSICSBANANA_H_
#define _PHYSICSBANANA_H_

#include "PhysicsObject.h"

class PhysicsBanana // : public PhysicsObject
{
public:
    ~PhysicsBanana();
    void SetContactInfo(dContact*, PhysicsObject*, bool);
    void Contact(PhysicsObject*, dContact*, int);
    void PreCollide();
    void PreUpdate();
    PhysicsBanana(float);
    virtual int GetObjectType() const;
};


class CollisionPowerupGroundData
{
public:
    void GetID();
};

#endif // _PHYSICSBANANA_H_
