#ifndef _FESCENEMANAGER_H_
#define _FESCENEMANAGER_H_

#include "NL/nlSingleton.h"

// void nlDLRingRemoveStart<DLListEntry<PackagePushPopMessage*>>(DLListEntry<PackagePushPopMessage*>**);
// void nlDLRingIsEnd<DLListEntry<PackagePushPopMessage*>>(DLListEntry<PackagePushPopMessage*>*, DLListEntry<PackagePushPopMessage*>*);
// void nlDLRingIsEnd<DLListEntry<BaseSceneHandler*>>(DLListEntry<BaseSceneHandler*>*, DLListEntry<BaseSceneHandler*>*);
// void nlDLRingGetStart<DLListEntry<PackagePushPopMessage*>>(DLListEntry<PackagePushPopMessage*>*);
// void nlDLRingGetStart<DLListEntry<BaseSceneHandler*>>(DLListEntry<BaseSceneHandler*>*);
// void nlDLRingRemove<DLListEntry<PackagePushPopMessage*>>(DLListEntry<PackagePushPopMessage*>**, DLListEntry<PackagePushPopMessage*>*);
// void nlDLRingRemove<DLListEntry<BaseSceneHandler*>>(DLListEntry<BaseSceneHandler*>**, DLListEntry<BaseSceneHandler*>*);
// void nlDLRingAddEnd<DLListEntry<PackagePushPopMessage*>>(DLListEntry<PackagePushPopMessage*>**, DLListEntry<PackagePushPopMessage*>*);
// void nlDLRingAddStart<DLListEntry<PackagePushPopMessage*>>(DLListEntry<PackagePushPopMessage*>**, DLListEntry<PackagePushPopMessage*>*);
// void nlDLRingAddStart<DLListEntry<BaseSceneHandler*>>(DLListEntry<BaseSceneHandler*>**, DLListEntry<BaseSceneHandler*>*);

class BaseSceneHandler;

class FESceneManager
{
public:
    void Update(float);
    void RenderActiveScenes();
    void QueueScenePop();
    void QueueScenePush(BaseSceneHandler*, const char*);
    void ProcessPushPopQueue();
    void GetSceneHandler(unsigned long);
    void ForceImmediateStackProcessing();
    void AreAllScenesValid();
    ~FESceneManager();
    FESceneManager();

    static nlSingleton<FESceneManager> s_pInstance;
};

// class DLListContainerBase<BaseSceneHandler*, BasicSlotPool<DLListEntry<BaseSceneHandler*>>>
// {
// public:
//     void DeleteEntry(DLListEntry<BaseSceneHandler*>*);
// };

// class DLListContainerBase<PackagePushPopMessage*, BasicSlotPool<DLListEntry<PackagePushPopMessage*>>>
// {
// public:
//     void DeleteEntry(DLListEntry<PackagePushPopMessage*>*);
// };

// class nlDLListSlotPool<PackagePushPopMessage*>
// {
// public:
//     void ~nlDLListSlotPool();
// };

// class SlotPool<PackagePushPopMessage>
// {
// public:
//     void ~SlotPool();
// };

// class nlWalkDLRing<DLListEntry<BaseSceneHandler*>, DLListContainerBase<BaseSceneHandler*,
// BasicSlotPool<DLListEntry<BaseSceneHandler*>>>>(DLListEntry<BaseSceneHandler*>*, DLListContainerBase<BaseSceneHandler*,
// BasicSlotPool<DLListEntry<BaseSceneHandler*>>>*, void (DLListContainerBase<BaseSceneHandler*,
// BasicSlotPool<DLListEntry<BaseSceneHandler*>>>
// {
// public:
//     void *)(DLListEntry<BaseSceneHandler*>*));
// };

// class nlWalkDLRing<DLListEntry<PackagePushPopMessage*>, DLListContainerBase<PackagePushPopMessage*,
// BasicSlotPool<DLListEntry<PackagePushPopMessage*>>>>(DLListEntry<PackagePushPopMessage*>*, DLListContainerBase<PackagePushPopMessage*,
// BasicSlotPool<DLListEntry<PackagePushPopMessage*>>>*, void (DLListContainerBase<PackagePushPopMessage*,
// BasicSlotPool<DLListEntry<PackagePushPopMessage*>>>
// {
// public:
//     void *)(DLListEntry<PackagePushPopMessage*>*));
// };

// class nlWalkRing<DLListEntry<BaseSceneHandler*>, DLListContainerBase<BaseSceneHandler*,
// BasicSlotPool<DLListEntry<BaseSceneHandler*>>>>(DLListEntry<BaseSceneHandler*>*, DLListContainerBase<BaseSceneHandler*,
// BasicSlotPool<DLListEntry<BaseSceneHandler*>>>*, void (DLListContainerBase<BaseSceneHandler*,
// BasicSlotPool<DLListEntry<BaseSceneHandler*>>>
// {
// public:
//     void *)(DLListEntry<BaseSceneHandler*>*));
// };

// class nlWalkRing<DLListEntry<PackagePushPopMessage*>, DLListContainerBase<PackagePushPopMessage*,
// BasicSlotPool<DLListEntry<PackagePushPopMessage*>>>>(DLListEntry<PackagePushPopMessage*>*, DLListContainerBase<PackagePushPopMessage*,
// BasicSlotPool<DLListEntry<PackagePushPopMessage*>>>*, void (DLListContainerBase<PackagePushPopMessage*,
// BasicSlotPool<DLListEntry<PackagePushPopMessage*>>>
// {
// public:
//     void *)(DLListEntry<PackagePushPopMessage*>*));
// };

#endif // _FESCENEMANAGER_H_
