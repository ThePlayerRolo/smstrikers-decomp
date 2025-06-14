#ifndef _PHYSICSCHARACTER_H_
#define _PHYSICSCHARACTER_H_


#include "PhysicsObject.h"

class PhysicsCharacter : public PhysicsObject
{
public:
    void SetCharacterVelocityXY(const nlVector3&);
    void GetCharacterVelocityXY(nlVector3*);
    void SetCharacterPositionXY(const nlVector3&);
    void GetCharacterPositionXY(nlVector3*);
    void PostUpdate();
    void ResolvePhysicsBoneIDFromName(const char*);
    virtual int PreCollide();
    virtual int Contact(PhysicsObject*, dContact*, int, PhysicsObject*);
    virtual int SetContactInfo(dContact*, PhysicsObject*, bool);
    void GetRadius(float*);
    PhysicsCharacter(float, float);
    virtual void GetObjectType() const;
};

#endif // _PHYSICSCHARACTER_H_
