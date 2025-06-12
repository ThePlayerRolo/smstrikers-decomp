#ifndef _PHYSICSFINITEPLANE_H_
#define _PHYSICSFINITEPLANE_H_

#include "NL/nlMath.h"
#include "CollisionSpace.h"
#include "PhysicsPlane.h"

class PhysicsFinitePlane //: public PhysicsPlane
{
public:
    PhysicsFinitePlane(CollisionSpace*, nlVector3&, nlVector3&, nlVector3&, bool, float);
    virtual int GetObjectType() const;
};

#endif // _PHYSICSFINITEPLANE_H_
