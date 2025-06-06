#ifndef _NLSLOTPOOL_H_
#define _NLSLOTPOOL_H_

class SlotPoolBase
{
public:
    void BaseAddNewBlock(SlotPoolBase*, unsigned int);
    void BaseFreeBlocks(SlotPoolBase*, unsigned int);
    ~SlotPoolBase();
    SlotPoolBase();
};

class SlotPoolEntry;
class SlotPoolBlock;

void DefaultSlotPoolFree(void*);
void DefaultSlotPoolAllocator(unsigned long);
// nlListAddStart<SlotPoolEntry>(SlotPoolEntry**, SlotPoolEntry*, SlotPoolEntry**)
void nlListAddStart(SlotPoolEntry**, SlotPoolEntry*, SlotPoolEntry**);
// nlListAddStart<SlotPoolBlock>(SlotPoolBlock**, SlotPoolBlock*, SlotPoolBlock**)
void nlListAddStart(SlotPoolBlock**, SlotPoolBlock*, SlotPoolBlock**);

#endif // _NLSLOTPOOL_H_
