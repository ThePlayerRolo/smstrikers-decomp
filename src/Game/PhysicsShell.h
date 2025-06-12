#ifndef _PHYSICSSHELL_H_
#define _PHYSICSSHELL_H_

#include "PhysicsObject.h"

class PhysicsShell : public PhysicsObject
{
public:
    void SetContactInfo(dContact*, PhysicsObject*, bool);
    void PostUpdate();
    void Contact(PhysicsObject*, dContact*, int);
    PhysicsShell(float);
    virtual int GetObjectType() const;
};

#endif // _PHYSICSSHELL_H_
