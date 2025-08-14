#ifndef _FERESOURCEMANAGER_H_
#define _FERESOURCEMANAGER_H_

// void nlDLRingRemoveStart<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>**);
// void nlDLRingGetStart<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>*);
// void nlDLRingRemove<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>**, DLListEntry<FEResourceHandle*>*);
// void nlDLRingAddEnd<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>**, DLListEntry<FEResourceHandle*>*);
// void nlDLRingAddStart<DLListEntry<FEResourceHandle*>>(DLListEntry<FEResourceHandle*>**, DLListEntry<FEResourceHandle*>*);

class FEResourceHandle;

class FEResourceManager
{
public:
    void Update(float);
    void TextureResourceLoadComplete(void*, unsigned long, unsigned long);
    void UnloadPermanentResourceBundle();
    void UnloadResource(FEResourceHandle*);
    void QueueResourceLoad(FEResourceHandle*);
    void Initialize();
    void OpenOnDemandResourceBundle(const char*);
    void LoadPermanentResourceBundle(const char*);
    void Cleanup();
    ~FEResourceManager();
    FEResourceManager();
    void GetName();
};

// class AVLTreeBase<unsigned long, FEResourceHandle*, BasicSlotPool<AVLTreeEntry<unsigned long, FEResourceHandle*>>,
// DefaultKeyCompare<unsigned long>>
// {
// public:
//     void DeleteEntry(AVLTreeEntry<unsigned long, FEResourceHandle*>*);
//     void Clear();
//     void DestroyTree(void (AVLTreeBase<unsigned long, FEResourceHandle*, BasicSlotPool<AVLTreeEntry<unsigned long, FEResourceHandle*>>,
//     DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, FEResourceHandle*>*)); void
//     PostorderTraversal(AVLTreeEntry<unsigned long, FEResourceHandle*>*, void (AVLTreeBase<unsigned long, FEResourceHandle*,
//     BasicSlotPool<AVLTreeEntry<unsigned long, FEResourceHandle*>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long,
//     FEResourceHandle*>*)); void CastUp(AVLTreeNode*) const; void ~AVLTreeBase(); void CompareNodes(AVLTreeNode*, AVLTreeNode*); void
//     CompareKey(void*, AVLTreeNode*); void AllocateEntry(void*, void*);
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
