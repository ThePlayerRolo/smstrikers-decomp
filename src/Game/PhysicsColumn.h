#ifndef _PHYSICSCOLUMN_H_
#define _PHYSICSCOLUMN_H_


class PhysicsColumn
{
public:
    void GetRadius(float*);
    PhysicsColumn(CollisionSpace*, PhysicsWorld*, float);
    ~PhysicsColumn();
    void GetObjectType() const;
};

#endif // _PHYSICSCOLUMN_H_