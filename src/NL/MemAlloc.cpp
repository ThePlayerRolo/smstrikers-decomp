#include "NL/MemAlloc.h"

extern void nlPrintf(const char*, ...);
extern void nlBreak();

/**
 * Offset/Address/Size: 0x0 | 0x801CD74C | size: 0x58
 */
unsigned int MemoryAllocator::LargestFreeBlock()
{
    LargestFreeBlockCallback callback;
    callback.m_unk_0x00 = 0;
    nlWalkDLRing<FreeBlockList, LargestFreeBlockCallback>(m_free_block_list, &callback, &LargestFreeBlockCallback::Callback);
    return callback.m_unk_0x00;
}

/**
 * Offset/Address/Size: 0x58 | 0x801CD7A4 | size: 0x1C
 */
void LargestFreeBlockCallback::Callback(FreeBlockList* fbl)
{
    u32 temp_r0;
    u32 var_r5;

    var_r5 = m_unk_0x00;
    temp_r0 = fbl->m_unk_0x08;
    if (temp_r0 >= var_r5)
    {
        var_r5 = temp_r0;
    }
    m_unk_0x00 = var_r5;
}

/**
 * Offset/Address/Size: 0x74 | 0x801CD7C0 | size: 0x58
 */
unsigned int MemoryAllocator::TotalFreeMemory()
{
    TotalFreeMemCallback callback;
    callback.m_unk_0x00 = 0;
    nlWalkDLRing<FreeBlockList, TotalFreeMemCallback>(m_free_block_list, &callback, &TotalFreeMemCallback::Callback);
    return callback.m_unk_0x00;
}

/**
 * Offset/Address/Size: 0xCC | 0x801CD818 | size: 0x14
 */
void TotalFreeMemCallback::Callback(FreeBlockList* fbl)
{
    m_unk_0x00 = m_unk_0x00 + fbl->m_unk_0x08;
}

/**
 * Offset/Address/Size: 0xE0 | 0x801CD82C | size: 0xF8
 */
void MemoryAllocator::Initialize(void* arg0, unsigned int arg1)
{
    FreeBlockList* temp_r3;
    FreeBlockList* temp_r4;
    FreeBlockList* var_r4;
    s32 temp_r5_2;
    u32 temp_r5;
    void* temp_r6;

    this->m_free_block_list = NULL;
    ((FreeBlockList*)arg0)->m_unk_0x08 = arg1;
    temp_r3 = nlDLRingGetStart<FreeBlockList>((FreeBlockList*)this->m_free_block_list);
    if ((temp_r3 > (FreeBlockList*)arg0) || (temp_r3 == NULL))
    {
        nlDLRingAddStart<FreeBlockList>(&this->m_free_block_list, (FreeBlockList*)arg0);
    }
    else
    {
        var_r4 = temp_r3;
    loop_6:
        if (var_r4 != temp_r3)
        {
            if (var_r4 <= (FreeBlockList*)arg0)
            {
                var_r4 = var_r4->m_next;
                goto loop_6;
            }
        }
        nlDLRingInsert<FreeBlockList>(&this->m_free_block_list, var_r4->m_prev, (FreeBlockList*)arg0);
    }
    temp_r4 = ((FreeBlockList*)arg0)->m_next;
    if (temp_r4 > (FreeBlockList*)arg0)
    {
        temp_r5 = ((FreeBlockList*)arg0)->m_unk_0x08;
        if (((FreeBlockList*)arg0 + temp_r5) == temp_r4)
        {
            ((FreeBlockList*)arg0)->m_unk_0x08 = temp_r5 + temp_r4->m_unk_0x08;
            nlDLRingRemove<FreeBlockList>(&this->m_free_block_list, temp_r4);
        }
    }
    temp_r6 = ((FreeBlockList*)arg0)->m_prev;
    if (temp_r6 < (FreeBlockList*)arg0)
    {
        temp_r5_2 = ((FreeBlockList*)temp_r6)->m_unk_0x08;
        if (((FreeBlockList*)temp_r6 + temp_r5_2) == (FreeBlockList*)arg0)
        {
            ((FreeBlockList*)temp_r6)->m_unk_0x08 = temp_r5_2 + ((FreeBlockList*)arg0)->m_unk_0x08;
            nlDLRingRemove<FreeBlockList>(&this->m_free_block_list, (FreeBlockList*)arg0);
        }
    }
}

/**
 * Offset/Address/Size: 0x1D8 | 0x801CD924 | size: 0x35C
 */
void* MemoryAllocator::Allocate(unsigned long arg0, unsigned int arg1, bool arg2)
{
    s32 sp44;
    s32 sp40;
    TotalFreeMemCallback sp3C;
    s32 sp38;
    s32 sp34;
    LargestFreeBlockCallback sp30;
    s32 sp2C;
    s32 sp28;
    TotalFreeMemCallback sp24;
    s32 sp20;
    s32 sp1C;
    LargestFreeBlockCallback sp18;
    s32 sp14;
    s32 sp10;
    // s32 spC;
    s32 sp8;
    FreeBlockList** temp_r3_3;
    FreeBlockList** var_r29;
    FreeBlockList* temp_r25;
    FreeBlockList* temp_r25_prev = NULL; // Added missing declaration
    FreeBlockList* temp_r3 = NULL;
    FreeBlockList* temp_r5_4 = NULL;
    FreeBlockList* var_r30 = NULL;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r23;
    u32 temp_r0_3;
    u32 temp_r23_2;
    u32 temp_r24;
    u32 temp_r24_2;
    u32 temp_r28;
    u32 temp_r28_2;
    u32 temp_r4;
    u32 temp_r4_2;
    u32 temp_r5_3;
    u32 temp_r6;
    u32 temp_r6_2;
    u32 var_r23;
    u32 var_r25;
    u32 var_r25_2;
    u32 var_r4;
    u32 var_r4_2;
    void* temp_r3_2;
    void* temp_r5;
    void* temp_r5_2;

    var_r25 = arg1;
    var_r23 = arg0;
    if (var_r25 < 4)
    {
        var_r25 = 4;
    }
    if (var_r23 < 0xC)
    {
        var_r23 = 0xC;
    }
    if (arg2 != 0)
    {
        temp_r3 = nlDLRingGetEnd<FreeBlockList>(this->m_free_block_list);
        temp_r0 = var_r25 - 1;
        var_r30 = temp_r3;
        temp_r28 = (var_r23 + 3) & 0xFFFFFFFC;
    loop_6:
        temp_r4 = var_r30->m_unk_0x08;
        if (temp_r4 <= temp_r28)
        {
        block_8:
            var_r30 = var_r30->m_next;
            if (var_r30 == temp_r3)
            {
                sp14 = 0;
                sp3C.m_unk_0x00 = 0;
                nlWalkDLRing<FreeBlockList, TotalFreeMemCallback>(this->m_free_block_list, &sp3C, &TotalFreeMemCallback::Callback);
                nlPrintf("Total Free Memory: %d\n", sp3C.m_unk_0x00 = 0);
                sp10 = 0;
                sp30.m_unk_0x00 = 0;
                nlWalkDLRing<FreeBlockList, LargestFreeBlockCallback>(this->m_free_block_list, &sp30, &LargestFreeBlockCallback::Callback);
                nlPrintf("Largest Free Block: %d\n", sp30.m_unk_0x00);
                nlBreak();
            }
            goto loop_6;
        }
        temp_r3_2 = (void*)((char*)var_r30 + temp_r4);
        temp_r23 = ((u32)temp_r3_2 - temp_r28) & ~(temp_r0 | temp_r0);
        temp_r24 = ((u32)temp_r3_2 - temp_r23) + 4;
        if (temp_r24 > temp_r4)
        {
            goto block_8;
        }
        temp_r5_3 = temp_r4 - temp_r24;
        var_r25_2 = 4;
        if (temp_r5_3 > 0xC)
        {
            var_r30->m_unk_0x08 = temp_r5_3;
        }
        else
        {
            var_r25_2 = temp_r5_3 + 4;
            nlDLRingRemove<FreeBlockList>(&this->m_free_block_list, var_r30);
        }
        var_r4 = var_r23;
        temp_r6 = (temp_r24 - temp_r28) - 4;
        temp_r5_2 = (void*)((char*)temp_r23 - var_r25_2 + var_r25_2);
        if (var_r25_2 > 4)
        {
            var_r4 = var_r23 | 0x80000000;
            *(u32*)((char*)temp_r5_2 - 8) = var_r25_2 - 4;
        }
        if (temp_r6 != 0)
        {
            var_r4 |= 0x40000000;
            *(u32*)((char*)temp_r5_2 + ((var_r23 + 3) & 0xFFFFFFFC)) = temp_r6; // Fixed casting issue
        }
        *(u32*)((char*)temp_r5_2 - 4) = var_r4;
        return temp_r5_2;
    }
    temp_r3_3 = &this->m_free_block_list; // Fixed: get address of member variable
    temp_r0_2 = var_r25 - 1;
    var_r29 = temp_r3_3;
    temp_r28_2 = (var_r23 + 3) & 0xFFFFFFFC;
loop_19:
    temp_r4_2 = (*var_r29)->m_unk_0x08;
    if (temp_r4_2 <= temp_r28_2)
    {
    block_21:
        var_r29 = &(*var_r29)->m_next;
        if (var_r29 == temp_r3_3)
        {
            // spC = 0;
            sp24.m_unk_0x00 = 0;
            nlWalkDLRing<FreeBlockList, TotalFreeMemCallback>(this->m_free_block_list, &sp24, &TotalFreeMemCallback::Callback);
            nlPrintf("Total Free Memory: %d\n", sp24.m_unk_0x00);
            // sp8 = 0;
            sp18.m_unk_0x00 = 0;
            nlWalkDLRing<FreeBlockList, LargestFreeBlockCallback>(this->m_free_block_list, &sp18, &LargestFreeBlockCallback::Callback);
            nlPrintf("Largest Free Block: %d\n", sp18.m_unk_0x00);
            nlBreak();
        }
        goto loop_19;
    }
    temp_r24_2 = (~(temp_r0_2 | temp_r0_2) & ((u32)*var_r29 + var_r25 + 3)) - (u32)*var_r29;
    temp_r23_2 = temp_r24_2 + temp_r28_2;
    if (temp_r23_2 > temp_r4_2)
    {
        goto block_21;
    }
    temp_r25_prev = (*var_r29)->m_prev;
    nlDLRingRemove<FreeBlockList>(&this->m_free_block_list, *var_r29);
    temp_r0_3 = (*var_r29)->m_unk_0x08 - temp_r23_2;
    if (temp_r0_3 > 0xC)
    {
        temp_r5_4 = (FreeBlockList*)((char*)*var_r29 + temp_r23_2);
        temp_r5_4->m_unk_0x08 = temp_r0_3;
        if ((this->m_free_block_list == NULL) || (*var_r29 == temp_r3))
        {
            nlDLRingAddStart<FreeBlockList>(&this->m_free_block_list, temp_r5_4);
        }
        else
        {
            nlDLRingInsert<FreeBlockList>(&this->m_free_block_list, temp_r25_prev, temp_r5_4);
        }
        (*var_r29)->m_unk_0x08 = temp_r23_2;
    }
    var_r4_2 = var_r23;
    temp_r5 = (void*)((char*)*var_r29 + temp_r24_2);
    temp_r6_2 = (*var_r29)->m_unk_0x08 - temp_r23_2;
    if (temp_r24_2 > 4)
    {
        var_r4_2 = var_r23 | 0x80000000;
        *(u32*)((char*)temp_r5 - 8) = temp_r24_2 - 4;
    }
    if (temp_r6_2 != 0)
    {
        var_r4_2 |= 0x40000000;
        *(u32*)((char*)temp_r5 + ((var_r23 + 3) & 0xFFFFFFFC)) = temp_r6_2; // Fixed casting issue
    }
    *(u32*)((char*)temp_r5 - 4) = var_r4_2;
    return temp_r5;
}

/**
 * Offset/Address/Size: 0x534 | 0x801CDC80 | size: 0x130
 */
void MemoryAllocator::Free(void* arg0)
{
    FreeBlockList** temp_r3;
    FreeBlockList* temp_r4;
    FreeBlockList* temp_r6;
    FreeBlockList* var_r31;
    FreeBlockList* var_r4;
    s32 temp_r0;
    s32 temp_r5;
    s32 var_r3;
    u32 temp_r5_2;
    u32 temp_r5_3;
    u32 var_r3_2;

    if (arg0 != NULL)
    {
        temp_r5 = *(u32*)((char*)arg0 - 4);
        var_r31 = (FreeBlockList*)((char*)arg0 - 4);
        var_r3 = ((temp_r5 & 0x3FFFFFFF) + 3) & 0xFFFFFFFC;
        if (temp_r5 & 0x40000000)
        {
            var_r3 += *(u32*)((char*)arg0 + var_r3);
        }
        var_r3_2 = var_r3 + 4;
        if (temp_r5 & 0x80000000)
        {
            temp_r0 = *(u32*)((char*)var_r31 - 4);
            var_r31 = (FreeBlockList*)((char*)var_r31 - temp_r0);
            var_r3_2 += temp_r0;
        }
        var_r31->m_unk_0x08 = var_r3_2;
        temp_r3 = &this->m_free_block_list;
        if ((*temp_r3 > var_r31) || (*temp_r3 == NULL))
        {
            nlDLRingAddStart<FreeBlockList>(&this->m_free_block_list, var_r31);
        }
        else
        {
            var_r4 = *temp_r3;
        loop_11:
            if (var_r4 != *temp_r3)
            {
                if (var_r4 <= var_r31)
                {
                    var_r4 = var_r4->m_next;
                    goto loop_11;
                }
            }
            nlDLRingInsert<FreeBlockList>(&this->m_free_block_list, var_r4->m_prev, var_r31);
        }
        temp_r4 = var_r31->m_next;
        if (temp_r4 > var_r31)
        {
            temp_r5_2 = var_r31->m_unk_0x08;
            if (((char*)var_r31 + temp_r5_2) == (char*)temp_r4)
            {
                var_r31->m_unk_0x08 = temp_r5_2 + temp_r4->m_unk_0x08;
                nlDLRingRemove<FreeBlockList>(&this->m_free_block_list, temp_r4);
            }
        }
        temp_r6 = var_r31->m_prev;
        if (temp_r6 < var_r31)
        {
            temp_r5_3 = temp_r6->m_unk_0x08;
            if (((char*)temp_r6 + temp_r5_3) == (char*)var_r31)
            {
                temp_r6->m_unk_0x08 = temp_r5_3 + var_r31->m_unk_0x08;
                nlDLRingRemove<FreeBlockList>(&this->m_free_block_list, var_r31);
            }
        }
    }
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
// void nlWalkRing<FreeBlockList, TotalFreeMemCallback>(FreeBlockList*, TotalFreeMemCallback*, void
// (TotalFreeMemCallback::*)(FreeBlockList*))
// {
// }

// /**
//  * Offset/Address/Size: 0x60 | 0x801CDF58 | size: 0x60
//  */
// void nlWalkRing<FreeBlockList, LargestFreeBlockCallback>(FreeBlockList*, LargestFreeBlockCallback*,
//                                                          void (LargestFreeBlockCallback::*)(FreeBlockList*))
// {
// }
