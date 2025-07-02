#include "NL/nlSlotPool.h"
#include "NL/nlMemory.h"

/**
 * Offset/Address/Size: 0x0 | 0x801D23F8 | size: 0xAC
 */
void SlotPoolBase::BaseAddNewBlock(SlotPoolBase* slotPool, unsigned int slotSize)
{
    u32 totalSlotMemory;
    u32 primarySlotCount;
    u32 numSlots;
    void* memoryBlock;

    primarySlotCount = slotPool->m_unk_0x04;
    if ((primarySlotCount != 0) || ((u32)slotPool->m_unk_0x08 == 0U))
    {
        numSlots = primarySlotCount;
        if ((u32)slotPool->m_unk_0x08 == 0U)
        {
            numSlots = slotPool->m_unk_0x00;
        }

        totalSlotMemory = slotSize * numSlots;
        memoryBlock = slotPool->m_slotPoolAllocator(totalSlotMemory + 4);
        nlListAddStart<SlotPoolBlock>(&slotPool->m_unk_0x08, (SlotPoolBlock*)((u8*)memoryBlock + totalSlotMemory), 0);
        
        for (u32 i = 0; i < numSlots; i++)
        {
            nlListAddStart<SlotPoolEntry>(&slotPool->m_unk_0x0C, (SlotPoolEntry*)memoryBlock, 0);
            memoryBlock = (u8*)memoryBlock + slotSize;
        }
    }
}

/**
 * Offset/Address/Size: 0xAC | 0x801D24A4 | size: 0x90
 */
void SlotPoolBase::BaseFreeBlocks(SlotPoolBase* slotPool, unsigned int slotSize)
{
    SlotPoolBlock* nextBlock;
    SlotPoolBlock* currentBlock;
    s32 blockOffset;

    currentBlock = slotPool->m_unk_0x08;
    blockOffset = slotSize * slotPool->m_unk_0x04;
    while(currentBlock != NULL)
    {
        nextBlock = currentBlock->m_next;
        if (nextBlock == NULL) {
            blockOffset = slotSize * slotPool->m_unk_0x00;
        }
        slotPool->m_slotPoolFree((u8*)currentBlock - blockOffset);
        currentBlock = nextBlock;
    }
    slotPool->m_unk_0x08 = NULL;
    slotPool->m_unk_0x0C = NULL;
}

/**
 * Offset/Address/Size: 0x13C | 0x801D2534 | size: 0x3C
 */
SlotPoolBase::~SlotPoolBase()
{
    // EMPTY
}

/**
 * Offset/Address/Size: 0x178 | 0x801D2570 | size: 0x30
 */
SlotPoolBase::SlotPoolBase()
{
    m_unk_0x08 = 0;
    m_unk_0x0C = 0;
    m_slotPoolAllocator = DefaultSlotPoolAllocator;
    m_slotPoolFree = DefaultSlotPoolFree;
    m_unk_0x00 = 0;
    m_unk_0x04 = 0;
}

/**
 * Offset/Address/Size: 0x1A8 | 0x801D25A0 | size: 0x20
 */
void DefaultSlotPoolFree(void* data)
{
    nlFree(data);
}

/**
 * Offset/Address/Size: 0x1C8 | 0x801D25C0 | size: 0x28
 */
void* DefaultSlotPoolAllocator(unsigned long size)
{
    return nlMalloc(size, 8, false);
}

// /**
//  * Offset/Address/Size: 0x0 | 0x801D25E8 | size: 0x28
//  */
// // nlListAddStart<SlotPoolEntry>(SlotPoolEntry**, SlotPoolEntry*, SlotPoolEntry**)
// void nlListAddStart(SlotPoolEntry**, SlotPoolEntry*, SlotPoolEntry**)
// {
// }

// /**
//  * Offset/Address/Size: 0x28 | 0x801D2610 | size: 0x28
//  */
// // nlListAddStart<SlotPoolBlock>(SlotPoolBlock**, SlotPoolBlock*, SlotPoolBlock**)
// void nlListAddStart(SlotPoolBlock**, SlotPoolBlock*, SlotPoolBlock**)
// {
// }
