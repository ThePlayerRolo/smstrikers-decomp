#ifndef _PHYSICSGROUNDPLANE_H_
#define _PHYSICSGROUNDPLANE_H_


class PhysicsGroundPlane
{
public:
    PhysicsGroundPlane(CollisionSpace*);
    ~PhysicsGroundPlane();
    void GetObjectType() const;
};

#endif // _PHYSICSGROUNDPLANE_H_