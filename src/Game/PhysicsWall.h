#ifndef _PHYSICSWALL_H_
#define _PHYSICSWALL_H_

#include "NL/nlMath.h"
#include "CollisionSpace.h"
#include "PhysicsPlane.h"

class PhysicsWall : public PhysicsPlane
{
public:
    PhysicsWall(CollisionSpace*, float, float, float);
    virtual ~PhysicsWall();
    virtual int GetObjectType() const;
};

#endif // _PHYSICSWALL_H_
