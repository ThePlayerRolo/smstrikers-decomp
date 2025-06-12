#ifndef _PHYSICSNPC_H_
#define _PHYSICSNPC_H_


class PhysicsNPC
{
public:
    ~PhysicsNPC();
    void SetContactInfo(dContact*, PhysicsObject*, bool);
    void Contact(PhysicsObject*, dContact*, int);
    void SetCallbackFunction(void (*)(PhysicsObject*, PhysicsObject*, const nlVector3&));
    PhysicsNPC(float);
    void GetObjectType() const;
};

#endif // _PHYSICSNPC_H_