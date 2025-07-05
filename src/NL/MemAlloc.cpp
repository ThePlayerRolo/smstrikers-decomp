#include "NL/MemAlloc.h"

/**
 * Offset/Address/Size: 0x0 | 0x801CD74C | size: 0x58
 */
unsigned int MemoryAllocator::LargestFreeBlock()
{
    return 0;
}

/**
 * Offset/Address/Size: 0x58 | 0x801CD7A4 | size: 0x1C
 */
void LargestFreeBlockCallback::Callback(FreeBlockList*)
{
}

/**
 * Offset/Address/Size: 0x74 | 0x801CD7C0 | size: 0x58
 */
unsigned int MemoryAllocator::TotalFreeMemory()
{
    return 0;
}

/**
 * Offset/Address/Size: 0xCC | 0x801CD818 | size: 0x14
 */
void TotalFreeMemCallback::Callback(FreeBlockList*)
{
}

/**
 * Offset/Address/Size: 0xE0 | 0x801CD82C | size: 0xF8
 */
void MemoryAllocator::Initialize(void*, unsigned int)
{
}

/**
 * Offset/Address/Size: 0x1D8 | 0x801CD924 | size: 0x35C
 */
void* MemoryAllocator::Allocate(unsigned long, unsigned int, bool)
{
}

/**
 * Offset/Address/Size: 0x534 | 0x801CDC80 | size: 0x130
 */
void MemoryAllocator::Free(void*)
{
}

// /**
//  * Offset/Address/Size: 0x0 | 0x801CDDB0 | size: 0x3C
//  */
// void nlWalkDLRing<FreeBlockList, LargestFreeBlockCallback>(FreeBlockList*, LargestFreeBlockCallback*,
//                                                            void (LargestFreeBlockCallback::*)(FreeBlockList*))
// {
// }

// /**
//  * Offset/Address/Size: 0x3C | 0x801CDDEC | size: 0x3C
//  */
// void nlWalkDLRing<FreeBlockList, TotalFreeMemCallback>(FreeBlockList*, TotalFreeMemCallback*,
//                                                        void (TotalFreeMemCallback::*)(FreeBlockList*))
// {
// }

// /**
//  * Offset/Address/Size: 0x78 | 0x801CDE28 | size: 0x10
//  */
// void nlDLRingGetEnd<FreeBlockList>(FreeBlockList*)
// {
// }

// /**
//  * Offset/Address/Size: 0x88 | 0x801CDE38 | size: 0x18
//  */
// void nlDLRingGetStart<FreeBlockList>(FreeBlockList*)
// {
// }

// /**
//  * Offset/Address/Size: 0xA0 | 0x801CDE50 | size: 0x44
//  */
// void nlDLRingRemove<FreeBlockList>(FreeBlockList**, FreeBlockList*)
// {
// }

// /**
//  * Offset/Address/Size: 0xE4 | 0x801CDE94 | size: 0x38
//  */
// void nlDLRingAddStart<FreeBlockList>(FreeBlockList**, FreeBlockList*)
// {
// }

// /**
//  * Offset/Address/Size: 0x11C | 0x801CDECC | size: 0x2C
//  */
// void nlDLRingInsert<FreeBlockList>(FreeBlockList**, FreeBlockList*, FreeBlockList*)
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x801CDEF8 | size: 0x60
//  */
// void nlWalkRing<FreeBlockList, TotalFreeMemCallback>(FreeBlockList*, TotalFreeMemCallback*, void (TotalFreeMemCallback::*)(FreeBlockList*))
// {
// }

// /**
//  * Offset/Address/Size: 0x60 | 0x801CDF58 | size: 0x60
//  */
// void nlWalkRing<FreeBlockList, LargestFreeBlockCallback>(FreeBlockList*, LargestFreeBlockCallback*,
//                                                          void (LargestFreeBlockCallback::*)(FreeBlockList*))
// {
// }
