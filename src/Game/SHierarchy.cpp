#include "SHierarchy.h"

/**
 * Offset/Address/Size: 0x0 | 0x801EDFEC | size: 0x18
 */
u32 cSHierarchy::PreserveBoneLength(int arg0) const
{
    u8 temp_r3;

    temp_r3 = *((u8*)this->m_unk_0x30 + arg0);
    return (-temp_r3 | temp_r3) >> 0x1F;
}

/**
 * Offset/Address/Size: 0x18 | 0x801EE004 | size: 0x10
 */
void* cSHierarchy::GetTranslationOffset(int arg0) const
{
    return (void*)((char*)this->m_unk_0x2C + (arg0 * 0xC));
}

/**
 * Offset/Address/Size: 0x28 | 0x801EE014 | size: 0x10
 */
s32 cSHierarchy::GetParent(int arg0) const
{
    return *((s32*)this->m_unk_0x10 + arg0);
}

/**
 * Offset/Address/Size: 0x38 | 0x801EE024 | size: 0x10
 */
s32 cSHierarchy::GetPushPop(int arg0) const
{
    return *((s32*)this->m_unk_0x1C + arg0);
}

/**
 * Offset/Address/Size: 0x48 | 0x801EE034 | size: 0x10
 */
s32 cSHierarchy::GetMirroredNode(int arg0) const
{
    return *((s32*)this->m_unk_0x20 + arg0);
}

/**
 * Offset/Address/Size: 0x58 | 0x801EE044 | size: 0x10
 */
s32 cSHierarchy::GetNumChildren(int arg0) const
{
    return *((s32*)this->m_unk_0x14 + arg0);
}

/**
 * Offset/Address/Size: 0x68 | 0x801EE054 | size: 0x10
 */
u32 cSHierarchy::GetNodeID(int arg0) const
{
    return this->m_unk_0x0C[arg0];
}

/**
 * Offset/Address/Size: 0x78 | 0x801EE064 | size: 0x40
 */
s32 cSHierarchy::GetNodeIndexByID(unsigned int arg0) const
{
    s32 temp_r0;
    s32 var_ctr;
    s32 var_r6;
    u32 *var_r5;

    temp_r0 = this->m_unk_0x08;
    var_r6 = 0;
    var_r5 = this->m_unk_0x0C;
    var_ctr = temp_r0;
    if (temp_r0 > 0) {
loop_1:
        if (arg0 == *var_r5) {
            return var_r6;
        }
        var_r5 += 4;
        var_r6 += 1;
        var_ctr -= 1;
        if (var_ctr == 0) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            return -1;
        }
        goto loop_1;
    }
    return -1;
}

/**
 * Offset/Address/Size: 0xB8 | 0x801EE0A4 | size: 0x18
 */
s32 cSHierarchy::GetChild(int arg0, int arg1) const
{
    return *((s32*)((s32**)this->m_unk_0x18)[arg0] + arg1);
}

/**
 * Offset/Address/Size: 0xD0 | 0x801EE0BC | size: 0x284
 */
void cSHierarchy::BuildPushPopFlags(int arg0, int arg1, int& arg2)
{
    s32 spC;
    s32 sp8;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r16;
    s32 temp_r19;
    s32 temp_r21;
    s32 temp_r22;
    s32 temp_r23;
    s32 temp_r24;
    s32 temp_r26;
    s32 temp_r27;
    s32 temp_r29;
    s32 temp_r30;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 var_r14;
    s32 var_r18;
    s32 var_r20;
    s32 var_r25;
    s32 var_r28;
    s32 var_r31;

    temp_r6 = arg2;
    if (arg1 != temp_r6) {
        ((s32*)this->m_unk_0x1C)[arg0 - 1] = arg1 - temp_r6;
        arg2 = arg1;
    }
    temp_r0 = arg0 * 4;
    spC = temp_r0;
    temp_r0_2 = ((s32*)this->m_unk_0x14)[arg0];
    sp8 = temp_r0_2;
    if (temp_r0_2 != 0) {
        var_r18 = 0;
        var_r14 = 0;
        ((s32*)this->m_unk_0x1C)[arg0] = 1;
        arg2 += 1;
        temp_r16 = arg2;
loop_29:
        if (var_r18 < sp8) {
            temp_r5 = arg2;
            temp_r6_2 = ((s32*)((s32**)this->m_unk_0x18)[arg0])[var_r18];
            if (temp_r16 != temp_r5) {
                ((s32*)this->m_unk_0x1C)[temp_r6_2 - 1] = temp_r16 - temp_r5;
                arg2 = temp_r16;
            }
            temp_r19 = temp_r6_2 * 4;
            temp_r30 = ((s32*)this->m_unk_0x14)[temp_r6_2];
            if (temp_r30 != 0) {
                var_r31 = 0;
                ((s32*)this->m_unk_0x1C)[temp_r6_2] = 1;
                var_r20 = 0;
                arg2 += 1;
                temp_r29 = arg2;
loop_25:
                if (var_r31 < temp_r30) {
                    temp_r5_2 = arg2;
                    temp_r21 = ((s32*)((s32**)this->m_unk_0x18)[temp_r6_2])[var_r31];
                    if (temp_r29 != temp_r5_2) {
                        ((s32*)this->m_unk_0x1C)[temp_r21 - 1] = temp_r29 - temp_r5_2;
                        arg2 = temp_r29;
                    }
                    temp_r4 = temp_r21 * 4;
                    temp_r27 = ((s32*)this->m_unk_0x14)[temp_r21];
                    if (temp_r27 != 0) {
                        var_r28 = 0;
                        ((s32*)this->m_unk_0x1C)[temp_r21] = 1;
                        arg2 += 1;
                        temp_r26 = arg2;
loop_21:
                        if (var_r28 < temp_r27) {
                            temp_r0_3 = arg2;
                            temp_r23 = GetChild(temp_r21, var_r28);
                            if (temp_r26 != temp_r0_3) {
                                ((s32*)this->m_unk_0x1C)[temp_r23 - 1] = temp_r26 - temp_r0_3;
                                arg2 = temp_r26;
                            }
                            temp_r4_2 = temp_r23 * 4;
                            temp_r24 = ((s32*)this->m_unk_0x14)[temp_r23];
                            if (temp_r24 != 0) {
                                var_r25 = 0;
                                ((s32*)this->m_unk_0x1C)[temp_r23] = 1;
                                arg2 += 1;
                                temp_r22 = arg2;
loop_17:
                                if (var_r25 < temp_r24) {
                                    BuildPushPopFlags(GetChild(temp_r23, var_r25), temp_r22, arg2);
                                    var_r25 += 1;
                                    goto loop_17;
                                }
                            } else {
                                ((s32*)this->m_unk_0x1C)[temp_r23] = 0;
                            }
                            var_r28 += 1;
                            goto loop_21;
                        }
                    } else {
                        ((s32*)this->m_unk_0x1C)[temp_r21] = 0;
                    }
                    var_r20 += 4;
                    var_r31 += 1;
                    goto loop_25;
                }
            } else {
                ((s32*)this->m_unk_0x1C)[temp_r6_2] = 0;
            }
            var_r14 += 4;
            var_r18 += 1;
            goto loop_29;
        }
        return;
    }
    ((s32*)this->m_unk_0x1C)[arg0] = 0;
}

/**
 * Offset/Address/Size: 0x354 | 0x801EE340 | size: 0x3E0
 */
cSHierarchy* cSHierarchy::Initialize(nlChunk* arg0)
{
    s32 sp8;
    void *temp_r5;
    void *temp_r5_6;
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r3_10;
    s32 temp_r3_11;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 temp_r3_9;
    s32 temp_r4;
    s32 temp_r4_10;
    s32 temp_r4_11;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r4_5;
    s32 temp_r4_6;
    s32 temp_r4_7;
    s32 temp_r4_8;
    s32 temp_r4_9;
    s32 var_r0;
    s32 var_r0_10;
    s32 var_r0_11;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r0_7;
    s32 var_r0_8;
    s32 var_r0_9;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    void *temp_r31;
    void *temp_r5_2;
    void *temp_r5_3;
    void *temp_r5_4;
    void *temp_r5_5;
    void *temp_r6;
    void *temp_r6_2;
    void *temp_r6_3;
    void *temp_r6_4;

    temp_r5 = (void*)&this->m_unk_0x08;
    temp_r3 = this->m_unk_0x08 & 0x7F000000;
    if (((-temp_r3 | temp_r3) >> 0x1F) != 0) {
        temp_r4 = 1 << (temp_r3 >> 0x18);
        var_r0 = (s32)((char*)temp_r5 + temp_r4 + 7) & ~(temp_r4 - 1);
    } else {
        var_r0 = (s32)((char*)temp_r5 + 8);
    }
    temp_r6 = (void*)((char*)temp_r5 + (*(s32*)((char*)temp_r5 + 4) + 8));
    temp_r3_2 = *(s32*)temp_r6 & 0x7F000000;
    if (((-temp_r3_2 | temp_r3_2) >> 0x1F) != 0) {
        temp_r4_2 = 1 << (temp_r3_2 >> 0x18);
        var_r0_2 = (s32)((char*)temp_r6 + temp_r4_2 + 7) & ~(temp_r4_2 - 1);
    } else {
        var_r0_2 = (s32)((char*)temp_r6 + 8);
    }
    ((cSHierarchy*)var_r0)->m_unk_0x00 = (void*)var_r0_2;
    temp_r5_2 = (void*)((char*)temp_r6 + (*(s32*)((char*)temp_r6 + 4) + 8));
    temp_r3_3 = *(s32*)temp_r5_2 & 0x7F000000;
    if (((-temp_r3_3 | temp_r3_3) >> 0x1F) != 0) {
        temp_r4_3 = 1 << (temp_r3_3 >> 0x18);
        var_r0_3 = (s32)((char*)temp_r5_2 + temp_r4_3 + 7) & ~(temp_r4_3 - 1);
    } else {
        var_r0_3 = (s32)((char*)temp_r5_2 + 8);
    }
    ((cSHierarchy*)var_r0)->m_unk_0x0C = (u32*)var_r0_3;
    temp_r6_2 = (void*)((char*)temp_r5_2 + (*(s32*)((char*)temp_r5_2 + 4) + 8));
    temp_r3_4 = *(s32*)temp_r6_2 & 0x7F000000;
    if (((-temp_r3_4 | temp_r3_4) >> 0x1F) != 0) {
        temp_r4_4 = 1 << (temp_r3_4 >> 0x18);
        var_r0_4 = (s32)((char*)temp_r6_2 + temp_r4_4 + 7) & ~(temp_r4_4 - 1);
    } else {
        var_r0_4 = (s32)((char*)temp_r6_2 + 8);
    }
    ((cSHierarchy*)var_r0)->m_unk_0x10 = (void*)var_r0_4;
    temp_r5_3 = (void*)((char*)temp_r6_2 + (*(s32*)((char*)temp_r6_2 + 4) + 8));
    temp_r3_5 = *(s32*)temp_r5_3 & 0x7F000000;
    if (((-temp_r3_5 | temp_r3_5) >> 0x1F) != 0) {
        temp_r4_5 = 1 << (temp_r3_5 >> 0x18);
        var_r0_5 = (s32)((char*)temp_r5_3 + temp_r4_5 + 7) & ~(temp_r4_5 - 1);
    } else {
        var_r0_5 = (s32)((char*)temp_r5_3 + 8);
    }
    ((cSHierarchy*)var_r0)->m_unk_0x14 = (void*)var_r0_5;
    temp_r6_3 = (void*)((char*)temp_r5_3 + (*(s32*)((char*)temp_r5_3 + 4) + 8));
    temp_r3_6 = *(s32*)temp_r6_3 & 0x7F000000;
    if (((-temp_r3_6 | temp_r3_6) >> 0x1F) != 0) {
        temp_r4_6 = 1 << (temp_r3_6 >> 0x18);
        var_r0_6 = (s32)((char*)temp_r6_3 + temp_r4_6 + 7) & ~(temp_r4_6 - 1);
    } else {
        var_r0_6 = (s32)((char*)temp_r6_3 + 8);
    }
    ((cSHierarchy*)var_r0)->m_unk_0x18 = (void*)var_r0_6;
    temp_r5_4 = (void*)((char*)temp_r6_3 + (*(s32*)((char*)temp_r6_3 + 4) + 8));
    temp_r3_7 = *(s32*)temp_r5_4 & 0x7F000000;
    if (((-temp_r3_7 | temp_r3_7) >> 0x1F) != 0) {
        temp_r4_7 = 1 << (temp_r3_7 >> 0x18);
        var_r0_7 = (s32)((char*)temp_r5_4 + temp_r4_7 + 7) & ~(temp_r4_7 - 1);
    } else {
        var_r0_7 = (s32)((char*)temp_r5_4 + 8);
    }
    ((cSHierarchy*)var_r0)->m_unk_0x1C = (void*)var_r0_7;
    temp_r31 = (void*)((char*)temp_r5_4 + (*(s32*)((char*)temp_r5_4 + 4) + 8));
    temp_r3_8 = *(s32*)temp_r31 & 0x7F000000;
    if (((-temp_r3_8 | temp_r3_8) >> 0x1F) != 0) {
        temp_r4_8 = 1 << (temp_r3_8 >> 0x18);
        var_r0_8 = (s32)((char*)temp_r31 + temp_r4_8 + 7) & ~(temp_r4_8 - 1);
    } else {
        var_r0_8 = (s32)((char*)temp_r31 + 8);
    }
    var_r5 = 0;
    var_r6 = var_r0_8;
    var_r7 = 0;
loop_29:
    if (var_r7 < ((cSHierarchy*)var_r0)->m_unk_0x08) {
        if (*((s32*)((cSHierarchy*)var_r0)->m_unk_0x14 + var_r5) > 0) {
            *((s32*)((cSHierarchy*)var_r0)->m_unk_0x18 + var_r5) = var_r6;
        } else {
            *((s32*)((cSHierarchy*)var_r0)->m_unk_0x18 + var_r5) = 0;
        }
        var_r7 += 1;
        temp_r0 = *((s32*)((cSHierarchy*)var_r0)->m_unk_0x14 + var_r5);
        var_r5 += 4;
        var_r6 += temp_r0 * 4;
        goto loop_29;
    }
    sp8 = 0;
    int sp8_ref = sp8;
    BuildPushPopFlags(0, 0, sp8_ref);
    temp_r5_5 = (void*)((char*)temp_r31 + (*(s32*)((char*)temp_r31 + 4) + 8));
    temp_r3_9 = *(s32*)temp_r5_5 & 0x7F000000;
    if (((-temp_r3_9 | temp_r3_9) >> 0x1F) != 0) {
        temp_r4_9 = 1 << (temp_r3_9 >> 0x18);
        var_r0_9 = (s32)((char*)temp_r5_5 + temp_r4_9 + 7) & ~(temp_r4_9 - 1);
    } else {
        var_r0_9 = (s32)((char*)temp_r5_5 + 8);
    }
    ((cSHierarchy*)var_r0)->m_unk_0x20 = (void*)var_r0_9;
    temp_r6_4 = (void*)((char*)temp_r5_5 + (*(s32*)((char*)temp_r5_5 + 4) + 8));
    temp_r3_10 = *(s32*)temp_r6_4 & 0x7F000000;
    if (((-temp_r3_10 | temp_r3_10) >> 0x1F) != 0) {
        temp_r4_10 = 1 << (temp_r3_10 >> 0x18);
        var_r0_10 = (s32)((char*)temp_r6_4 + temp_r4_10 + 7) & ~(temp_r4_10 - 1);
    } else {
        var_r0_10 = (s32)((char*)temp_r6_4 + 8);
    }
    ((cSHierarchy*)var_r0)->m_unk_0x2C = (void*)var_r0_10;
    temp_r5_6 = (void*)((char*)temp_r6_4 + (*(s32*)((char*)temp_r6_4 + 4) + 8));
    temp_r3_11 = *(s32*)temp_r5_6 & 0x7F000000;
    if (((-temp_r3_11 | temp_r3_11) >> 0x1F) != 0) {
        temp_r4_11 = 1 << (temp_r3_11 >> 0x18);
        var_r0_11 = (s32)((char*)temp_r5_6 + temp_r4_11 + 7) & ~(temp_r4_11 - 1);
    } else {
        var_r0_11 = (s32)((char*)temp_r5_6 + 8);
    }
    ((cSHierarchy*)var_r0)->m_unk_0x30 = (void*)var_r0_11;
    return (cSHierarchy*)var_r0;
}
