#ifndef _FETWEENER_H_
#define _FETWEENER_H_

class FETweener;

class FETweenManager
{
public:
    void startTween(FETweener*);
    void clearTweensOnObj(void*);
    void clearTweens();
    void Update(float);
    void createTween(float*, float*, float, float, unsigned char, float (*)(float, float, float, float), void*,
                     void (*)(void*, const float*));
    ~FETweenManager();
    FETweenManager();
};

class FETweener
{
public:
    void setDoneCallFunc(void (*)(void*), void*);
    void setNextTween(FETweener*);
    ~FETweener();
};

// class DLListContainerBase<FETweener*, BasicSlotPool<DLListEntry<FETweener*>>>
// {
// public:
//     void DeleteEntry(DLListEntry<FETweener*>*);
// };

// class nlWalkDLRing<DLListEntry<FETweener*>, DLListContainerBase<FETweener*,
// BasicSlotPool<DLListEntry<FETweener*>>>>(DLListEntry<FETweener*>*, DLListContainerBase<FETweener*,
// BasicSlotPool<DLListEntry<FETweener*>>>*, void (DLListContainerBase<FETweener*, BasicSlotPool<DLListEntry<FETweener*>>>
// {
// public:
//     void *)(DLListEntry<FETweener*>*));
// };

// class nlWalkRing<DLListEntry<FETweener*>, DLListContainerBase<FETweener*,
// BasicSlotPool<DLListEntry<FETweener*>>>>(DLListEntry<FETweener*>*, DLListContainerBase<FETweener*,
// BasicSlotPool<DLListEntry<FETweener*>>>*, void (DLListContainerBase<FETweener*, BasicSlotPool<DLListEntry<FETweener*>>>
// {
// public:
//     void *)(DLListEntry<FETweener*>*));
// };

#endif // _FETWEENER_H_
