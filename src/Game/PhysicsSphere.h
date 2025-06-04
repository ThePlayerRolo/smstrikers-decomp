#ifndef _PHYSICSSPHERE_H_
#define _PHYSICSSPHERE_H_

#include "PhysicsObject.h"
#include "CollisionSpace.h"
#include "PhysicsWorld.h"

class PhysicsSphere : public PhysicsObject
{
public:
    PhysicsSphere(CollisionSpace*, PhysicsWorld*, float);

    void SetRadius(float);
    void GetRadius(float *);
};

#endif
