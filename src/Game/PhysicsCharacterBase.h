#ifndef _PHYSICSCHARACTERBASE_H_
#define _PHYSICSCHARACTERBASE_H_

#include "PhysicsObject.h"
#include "CollisionSpace.h"

class PhysicsCharacterBase
{
public:
    void GetBoneIDForSubObject(const PhysicsObject*) const;
    void AddBoneVolumes(PhysicsWorld*, CollisionSpace*, cPoseAccumulator*, const CharacterPhysicsData*, unsigned long, unsigned long);
    void UpdatePose(cPoseAccumulator*, float);
    void SetFacingDirection(unsigned short);
    void ReleaseObject();
    void ContainObject(PhysicsObject*);
    void BasePreCollide();
    void BaseSetContactInfo(dContact*, PhysicsObject*, bool);
    void SetCharacterPosition(const nlVector3&);
    ~PhysicsCharacterBase();
    PhysicsCharacterBase(CollisionSpace*, PhysicsWorld*, float);
    void GetBoneVolumePoints(nlVector3*, bool);
    void GetNumBoneVolumePoints(bool) const;
    virtual int GetObjectType() const;
    void PhysicsCapsuleBone::GetObjectType() const;
    void PhysicsSphereBone::~PhysicsSphereBone();
    void PhysicsSphereBone::GetObjectType() const;
    void PhysicsCapsuleBone::~PhysicsCapsuleBone();
};


class ListContainerBase<PhysicsCharacterBase
{
public:
    void PhysicsBoneVolume*, NewAdapter<ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>>>::DeleteEntry(ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>*);
};


class nlWalkList<ListEntry<PhysicsCharacterBase
{
public:
    void PhysicsBoneVolume*>, ListContainerBase<PhysicsCharacterBase::PhysicsBoneVolume*, NewAdapter<ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>>>>(ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>*, ListContainerBase<PhysicsCharacterBase::PhysicsBoneVolume*, NewAdapter<ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>>>*, void (ListContainerBase<PhysicsCharacterBase::PhysicsBoneVolume*, NewAdapter<ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>>>::*)(ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>*));
};


class nlListAddStart<ListEntry<PhysicsCharacterBase
{
public:
    void PhysicsBoneVolume*>>(ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>**, ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>*, ListEntry<PhysicsCharacterBase::PhysicsBoneVolume*>**);
};

#endif // _PHYSICSCHARACTERBASE_H_
