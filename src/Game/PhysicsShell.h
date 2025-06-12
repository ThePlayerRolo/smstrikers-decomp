#ifndef _PHYSICSSHELL_H_
#define _PHYSICSSHELL_H_


class PhysicsShell
{
public:
    void SetContactInfo(dContact*, PhysicsObject*, bool);
    void PostUpdate();
    void Contact(PhysicsObject*, dContact*, int);
    PhysicsShell(float);
    void GetObjectType() const;
};

#endif // _PHYSICSSHELL_H_