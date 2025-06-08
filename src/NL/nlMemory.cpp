#include "NL/nlMemory.h"

#include <types.h>

/**
 * Offset/Address/Size: 0x0 | 0x801D1EE4 | size: 0x40
 */
void nlFree(void*)
{
}

/**
 * Offset/Address/Size: 0x40 | 0x801D1F24 | size: 0x64
 */
void nlMalloc(unsigned long, unsigned int, bool)
{
}

/**
 * Offset/Address/Size: 0xA4 | 0x801D1F88 | size: 0x4C
 */
void* nlMalloc(unsigned long)
{
    return nullptr;
}

/**
 * Offset/Address/Size: 0xF0 | 0x801D1FD4 | size: 0x4C
 */
void* operator new(unsigned long size)
{
    return nlMalloc(size);
}

/**
 * Offset/Address/Size: 0x13C | 0x801D2020 | size: 0x40
 */
void operator delete[](void* ptr)
{
}

/**
 * Offset/Address/Size: 0x17C | 0x801D2060 | size: 0x40
 */
void operator delete(void* ptr)
{
    if (ptr != nullptr)
    {
        nlFree(ptr);
    }
}

/**
 * Offset/Address/Size: 0x0 | 0x801D20A0 | size: 0x24
 */
void nlVirtualTotalFree()
{
}

/**
 * Offset/Address/Size: 0x24 | 0x801D20C4 | size: 0x24
 */
void nlVirtualLargestBlock()
{
}

/**
 * Offset/Address/Size: 0x48 | 0x801D20E8 | size: 0x28
 */
void nlVirtualFree(void*)
{
}

/**
 * Offset/Address/Size: 0x70 | 0x801D2110 | size: 0x30
 */
void nlVirtualAlloc(unsigned long, bool)
{
}

/**
 * Offset/Address/Size: 0xA0 | 0x801D2140 | size: 0x1B8
 */
void nlInitMemory()
{
}
