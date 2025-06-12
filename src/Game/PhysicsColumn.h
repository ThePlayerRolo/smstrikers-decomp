#ifndef _PHYSICSCOLUMN_H_
#define _PHYSICSCOLUMN_H_

#include "PhysicsObject.h"
#include "CollisionSpace.h"

class PhysicsColumn : public PhysicsObject
{
public:
    void GetRadius(float*);
    PhysicsColumn(CollisionSpace*, PhysicsWorld*, float);
    ~PhysicsColumn();
    virtual int GetObjectType() const;
};

#endif // _PHYSICSCOLUMN_H_
