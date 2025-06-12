#ifndef _PHYSICSNPC_H_
#define _PHYSICSNPC_H_


#include "PhysicsObject.h"

class PhysicsNPC : public PhysicsObject
{
public:
    ~PhysicsNPC();
    virtual void SetContactInfo(dContact*, PhysicsObject*, bool);
    virtual void Contact(PhysicsObject*, dContact*, int);
    void SetCallbackFunction(void (*)(PhysicsObject*, PhysicsObject*, const nlVector3&));
    PhysicsNPC(float);
    virtual int GetObjectType() const;
};

#endif // _PHYSICSNPC_H_
