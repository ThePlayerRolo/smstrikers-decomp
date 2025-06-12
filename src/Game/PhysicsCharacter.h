#ifndef _PHYSICSCHARACTER_H_
#define _PHYSICSCHARACTER_H_


class PhysicsCharacter
{
public:
    void SetCharacterVelocityXY(const nlVector3&);
    void GetCharacterVelocityXY(nlVector3*);
    void SetCharacterPositionXY(const nlVector3&);
    void GetCharacterPositionXY(nlVector3*);
    void PostUpdate();
    void ResolvePhysicsBoneIDFromName(const char*);
    void PreCollide();
    void Contact(PhysicsObject*, dContact*, int, PhysicsObject*);
    void SetContactInfo(dContact*, PhysicsObject*, bool);
    void GetRadius(float*);
    PhysicsCharacter(float, float);
    void GetObjectType() const;
};

#endif // _PHYSICSCHARACTER_H_