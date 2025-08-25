#ifndef _FERESOURCEMANAGER_H_
#define _FERESOURCEMANAGER_H_

#include "types.h"
#include "NL/nlSingleton.h"

// void nlDLRingRemoveStart<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>**);
// void nlDLRingGetStart<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>*);
// void nlDLRingRemove<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>**, DLListEntry<FEResourceHandle*>*);
// void nlDLRingAddEnd<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>**, DLListEntry<FEResourceHandle*>*);
// void nlDLRingAddStart<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>**, DLListEntry<FEResourceHandle*>*);

class FEResourceHandle
{
public:
    FEResourceHandle();
    ~FEResourceHandle();

    /* 0x00 */ FEResourceHandle* m_next;
};

class FEResourceManager
{
public:
    void GetName();
    FEResourceManager();
    ~FEResourceManager();
    void Cleanup();
    void LoadPermanentResourceBundle(const char*);
    void OpenOnDemandResourceBundle(const char*);
    void Initialize();
    void QueueResourceLoad(FEResourceHandle*);
    void UnloadResource(FEResourceHandle*);
    void UnloadPermanentResourceBundle();
    void TextureResourceLoadComplete(void*, unsigned long, unsigned long);
    void Update(float);

    static nlSingleton<FEResourceManager> s_pInstance;
};

// class AVLTreeBase<unsigned long, FEResourceHandle*, BasicSlotPool<AVLTreeEntry<unsigned long, FEResourceHandle*>>,
// DefaultKeyCompare<unsigned long>>
// {
// public:
//     void AllocateEntry(void*, void*);
//     void CompareKey(void*, AVLTreeNode*);
//     void CompareNodes(AVLTreeNode*, AVLTreeNode*);
//     void ~AVLTreeBase();
//     void CastUp(AVLTreeNode*) const;
//     void PostorderTraversal(AVLTreeEntry<unsigned long, FEResourceHandle*>*, void (AVLTreeBase<unsigned long, FEResourceHandle*,
//     BasicSlotPool<AVLTreeEntry<unsigned long, FEResourceHandle*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long,
//     FEResourceHandle*>*)); void DestroyTree(void (AVLTreeBase<unsigned long, FEResourceHandle*, BasicSlotPool<AVLTreeEntry<unsigned long,
//     FEResourceHandle*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, FEResourceHandle*>*)); void Clear(); void
//     DeleteEntry(AVLTreeEntry<unsigned long, FEResourceHandle*>*);
// };

// class nlWalkDLRing<DLListEntry<FEResourceHandle*>, DLListContainerBase<FEResourceHandle*,
// BasicSlotPool<DLListEntry<FEResourceHandle*>>>>(DLListEntry<FEResourceHandle*>*, DLListContainerBase<FEResourceHandle*,
// BasicSlotPool<DLListEntry<FEResourceHandle*>>>*, void (DLListContainerBase<FEResourceHandle*,
// BasicSlotPool<DLListEntry<FEResourceHandle*>>>
// {
// public:
//     void *)(DLListEntry<FEResourceHandle*>*));
// };

// class DLListContainerBase<FEResourceHandle*, BasicSlotPool<DLListEntry<FEResourceHandle*>>>
// {
// public:
//     void DeleteEntry(DLListEntry<FEResourceHandle*>*);
// };

// class nlDLListSlotPool<FEResourceHandle*>
// {
// public:
//     void ~nlDLListSlotPool();
// };

// class nlAVLTreeSlotPool<unsigned long, FEResourceHandle*, DefaultKeyCompare<unsigned long>>
// {
// public:
//     void ~nlAVLTreeSlotPool();
// };

// class nlWalkRing<DLListEntry<FEResourceHandle*>, DLListContainerBase<FEResourceHandle*,
// BasicSlotPool<DLListEntry<FEResourceHandle*>>>>(DLListEntry<FEResourceHandle*>*, DLListContainerBase<FEResourceHandle*,
// BasicSlotPool<DLListEntry<FEResourceHandle*>>>*, void (DLListContainerBase<FEResourceHandle*,
// BasicSlotPool<DLListEntry<FEResourceHandle*>>>
// {
// public:
//     void *)(DLListEntry<FEResourceHandle*>*));
// };

#endif // _FERESOURCEMANAGER_H_
