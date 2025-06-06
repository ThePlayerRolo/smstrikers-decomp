#include "NL/nlSlotPool.h"

/**
 * Offset/Address/Size: 0x0 | 0x801D23F8 | size: 0xAC
 */
void SlotPoolBase::BaseAddNewBlock(SlotPoolBase*, unsigned int)
{
}

/**
 * Offset/Address/Size: 0xAC | 0x801D24A4 | size: 0x90
 */
void SlotPoolBase::BaseFreeBlocks(SlotPoolBase*, unsigned int)
{
}

/**
 * Offset/Address/Size: 0x13C | 0x801D2534 | size: 0x3C
 */
SlotPoolBase::~SlotPoolBase()
{
}

/**
 * Offset/Address/Size: 0x178 | 0x801D2570 | size: 0x30
 */
SlotPoolBase::SlotPoolBase()
{
}

/**
 * Offset/Address/Size: 0x1A8 | 0x801D25A0 | size: 0x20
 */
void DefaultSlotPoolFree(void*)
{
}

/**
 * Offset/Address/Size: 0x1C8 | 0x801D25C0 | size: 0x28
 */
void DefaultSlotPoolAllocator(unsigned long)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801D25E8 | size: 0x28
 */
// nlListAddStart<SlotPoolEntry>(SlotPoolEntry**, SlotPoolEntry*, SlotPoolEntry**)
void nlListAddStart(SlotPoolEntry**, SlotPoolEntry*, SlotPoolEntry**)
{
}

/**
 * Offset/Address/Size: 0x28 | 0x801D2610 | size: 0x28
 */
// nlListAddStart<SlotPoolBlock>(SlotPoolBlock**, SlotPoolBlock*, SlotPoolBlock**)
void nlListAddStart(SlotPoolBlock**, SlotPoolBlock*, SlotPoolBlock**)
{
}
