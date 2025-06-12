#ifndef _PHYSICSCAPSULE_H_
#define _PHYSICSCAPSULE_H_

#include "PhysicsObject.h"
#include "CollisionSpace.h"

class PhysicsCapsule : public PhysicsObject
{
public:
    PhysicsCapsule(CollisionSpace*, PhysicsWorld*, float, float);
    virtual int GetObjectType() const;
};

#endif // _PHYSICSCAPSULE_H_
