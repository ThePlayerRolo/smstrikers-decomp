#ifndef _COLLISIONSPACE_H_
#define _COLLISIONSPACE_H_

#include "ode/collision.h"

class PhysicsWorld;
class PhysicsObject;

class SimpleCollisionSpace
{
public:
    SimpleCollisionSpace(PhysicsWorld*);
    ~SimpleCollisionSpace();
};


class CollisionSpace
{
public:
    void PreUpdate();
    void PreCollide();
    void CallPreCollide(PhysicsObject*);
    void DoCollide(void*, void (*)(void*, dxGeom*, dxGeom*));

    ~CollisionSpace();
};

#endif // _COLLISIONSPACE_H_
