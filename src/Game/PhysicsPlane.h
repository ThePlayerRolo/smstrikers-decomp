#ifndef _PHYSICSPLANE_H_
#define _PHYSICSPLANE_H_

#include "PhysicsObject.h"
#include "CollisionSpace.h"

class CollisionSpace;

class PhysicsPlane : public PhysicsObject
{
public:
    PhysicsPlane(CollisionSpace*, float, float, float, float);
    // virtual ~PhysicsPlane();
};

#endif // _PHYSICSPLANE_H_
