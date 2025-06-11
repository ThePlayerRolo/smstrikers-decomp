#ifndef _PHYSICSCOMPOSITEOBJECT_H_
#define _PHYSICSCOMPOSITEOBJECT_H_

#include "NL/nlMath.h"

// void nlDLRingIsEnd<DLListEntry<PhysicsTransform*>>(DLListEntry<PhysicsTransform*>*, DLListEntry<PhysicsTransform*>*);
// void nlDLRingGetStart<DLListEntry<PhysicsTransform*>>(DLListEntry<PhysicsTransform*>*);
// void nlDLRingAddEnd<DLListEntry<PhysicsTransform*>>(DLListEntry<PhysicsTransform*>**, DLListEntry<PhysicsTransform*>*);
// void nlDLRingAddStart<DLListEntry<PhysicsTransform*>>(DLListEntry<PhysicsTransform*>**, DLListEntry<PhysicsTransform*>*);

class PhysicsObject;
class PhysicsWorld;

class PhysicsCompositeObject
{
public:
    void AdjustTransform(int, nlMatrix4&);
    void AddObject(PhysicsObject*);
    virtual ~PhysicsCompositeObject();
    PhysicsCompositeObject(PhysicsWorld*);
    int GetObjectType() const;
};


// class DLListContainerBase<PhysicsTransform*, NewAdapter<DLListEntry<PhysicsTransform*>>>
// {
// public:
//     void DeleteEntry(DLListEntry<PhysicsTransform*>*);
// };


// class nlWalkDLRing<DLListEntry<PhysicsTransform*>, DLListContainerBase<PhysicsTransform*, NewAdapter<DLListEntry<PhysicsTransform*>>>>(DLListEntry<PhysicsTransform*>*, DLListContainerBase<PhysicsTransform*, NewAdapter<DLListEntry<PhysicsTransform*>>>*, void (DLListContainerBase<PhysicsTransform*, NewAdapter<DLListEntry<PhysicsTransform*>>>
// {
// public:
//     void *)(DLListEntry<PhysicsTransform*>*));
// };


// class nlWalkRing<DLListEntry<PhysicsTransform*>, DLListContainerBase<PhysicsTransform*, NewAdapter<DLListEntry<PhysicsTransform*>>>>(DLListEntry<PhysicsTransform*>*, DLListContainerBase<PhysicsTransform*, NewAdapter<DLListEntry<PhysicsTransform*>>>*, void (DLListContainerBase<PhysicsTransform*, NewAdapter<DLListEntry<PhysicsTransform*>>>
// {
// public:
//     void *)(DLListEntry<PhysicsTransform*>*));
// };

#endif // _PHYSICSCOMPOSITEOBJECT_H_
