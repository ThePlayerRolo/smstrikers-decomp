#ifndef _MEMALLOC_H_
#define _MEMALLOC_H_

// void nlDLRingGetEnd<FreeBlockList>(FreeBlockList*);
// void nlDLRingGetStart<FreeBlockList>(FreeBlockList*);
// void nlDLRingRemove<FreeBlockList>(FreeBlockList**, FreeBlockList*);
// void nlDLRingAddStart<FreeBlockList>(FreeBlockList**, FreeBlockList*);
// void nlDLRingInsert<FreeBlockList>(FreeBlockList**, FreeBlockList*, FreeBlockList*);

class FreeBlockList;

class MemoryAllocator
{
public:
    unsigned int LargestFreeBlock();
    unsigned int TotalFreeMemory();
    void Initialize(void*, unsigned int);
    void* Allocate(unsigned long, unsigned int, bool);
    void Free(void*);
};


class LargestFreeBlockCallback
{
public:
    static void Callback(FreeBlockList*);
};


class TotalFreeMemCallback
{
public:
    static void Callback(FreeBlockList*);
};


// class nlWalkDLRing<FreeBlockList, LargestFreeBlockCallback>(FreeBlockList*, LargestFreeBlockCallback*, void (LargestFreeBlockCallback
// {
// public:
//     void *)(FreeBlockList*));
// };


// class nlWalkDLRing<FreeBlockList, TotalFreeMemCallback>(FreeBlockList*, TotalFreeMemCallback*, void (TotalFreeMemCallback
// {
// public:
//     void *)(FreeBlockList*));
// };


// class nlWalkRing<FreeBlockList, TotalFreeMemCallback>(FreeBlockList*, TotalFreeMemCallback*, void (TotalFreeMemCallback
// {
// public:
//     void *)(FreeBlockList*));
// };


// class nlWalkRing<FreeBlockList, LargestFreeBlockCallback>(FreeBlockList*, LargestFreeBlockCallback*, void (LargestFreeBlockCallback
// {
// public:
//     void *)(FreeBlockList*));
// };

#endif // _MEMALLOC_H_
