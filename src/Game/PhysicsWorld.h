#ifndef _PHYSICSWORLD_H_
#define _PHYSICSWORLD_H_

// #include "NL/nlMath.h"

#include "ode/objects.h"
#include "ode/collision.h"

class CollisionSpace;
class PhysicsObject;

class PhysicsWorld
{
public:
    // void DoCollisions(PhysicsObject*, nlListContainer<PhysicsObject*>&);
    void SpaceCollideCallback(void*, dxGeom*, dxGeom*);
    void Update(float, bool);
    void PostUpdate();
    void PreUpdate();
    void Collide();
    void DoCollide(CollisionSpace*);
    void PostUpdate(PhysicsObject*);
    void PreUpdate(PhysicsObject*);
    void PreUpdate(CollisionSpace*);
    void PreCollide(PhysicsObject*);
    void PreCollide(CollisionSpace*);
    void AddCollisionSpace(CollisionSpace*);
    void SetERP(float);
    void SetCFM(float);

    ~PhysicsWorld();
    PhysicsWorld();
};

#endif // _PHYSICSWORLD_H_
