#ifndef _PHYSICSGROUNDPLANE_H_
#define _PHYSICSGROUNDPLANE_H_

#include "CollisionSpace.h"
#include "PhysicsPlane.h"

class PhysicsGroundPlane : public PhysicsPlane
{
public:
    PhysicsGroundPlane(CollisionSpace*);
    virtual ~PhysicsGroundPlane();
    virtual int GetObjectType() const;
};

#endif // _PHYSICSGROUNDPLANE_H_
