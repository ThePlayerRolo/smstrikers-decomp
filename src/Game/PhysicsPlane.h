#ifndef _PHYSICSPLANE_H_
#define _PHYSICSPLANE_H_

#include "PhysicsObject.h"

class CollisionSpace;

class PhysicsPlane
{
public:
    PhysicsPlane(CollisionSpace*, float, float, float, float);
};

#endif // _PHYSICSPLANE_H_
