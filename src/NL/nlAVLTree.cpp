#include "NL/nlAVLTree.h"

#include "types.h"

// Virtual function table structure for AVLTreeUntemplated
// Based on the decompiled code, we can see calls to unkC and unk10
// struct AVLTreeVTable {
//     void* unk0;
//     void* unk4;
//     void* unk8;
//     s8 (*unkC)(void*, void*, void*);  // comparison function
//     void* (*unk10)(void*, void*);     // allocation function
// };

/**
 * Offset/Address/Size: 0x0 | 0x801CE120 | size: 0x490
 */
AVLTreeNode* AVLTreeUntemplated::RemoveAVLNode(AVLTreeNode** arg0, void* arg1, unsigned int arg2)
{
    AVLTreeNode** temp_r3_5;
    AVLTreeNode** var_r4;
    AVLTreeNode** var_r4_2;
    AVLTreeNode* temp_r4_2;
    AVLTreeNode* temp_r5;
    AVLTreeNode* temp_r5_2;
    AVLTreeNode* temp_r6_2;
    AVLTreeNode* var_r27;
    AVLTreeNode* var_r5;
    AVLTreeNode* var_r7;
    AVLTreeNode* var_r8;
    s32 temp_r30;
    s32 temp_r3;
    s32 temp_r4;
    s32 var_r25;
    s32 var_r28_2;
    s8* var_r24;
    s8* var_r3;
    u32 temp_r6;
    u32 var_ctr;
    u32 var_r28;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r7;
    u8 temp_r9;
    u8 var_r4_3;
    s32* temp_r1;
    AVLTreeNode* temp_r3_2;
    AVLTreeNode* temp_r3_3;
    AVLTreeNode* temp_r3_4;
    s8* temp_r5_3;
    
    // Stack arrays for storing path information
    s8 unksp8[32];  // Direction array
    AVLTreeNode* nodeStack[32];  // Node stack
    
    temp_r1 = (s32*)(&unksp8 - 0x30);
    if (*arg0 == NULL) {
        return NULL;
    }
    temp_r4 = arg2 + 1;
    temp_r30 = (temp_r4 * -4) & 0xFFFFFFF8;
    temp_r1[temp_r30 / 4] = 0; // sp0 equivalent
    temp_r1[(temp_r30 + ((temp_r4 * -1) & 0xFFFFFFF8)) / 4] = 0; // sp0 equivalent
    var_r28 = 0;
    var_r25 = 0;
    var_r27 = *arg0;
    var_r24 = unksp8;
loop_3:
    temp_r3 = this->CompareNodes((AVLTreeNode*)arg1, (AVLTreeNode*)var_r27);
    if (temp_r3 < 0) {
        var_r28 += 1;
        *var_r24 = -1;
        var_r24 += 1;
        nodeStack[var_r25] = var_r27;
        var_r25 += 1;
        var_r27 = var_r27->s_leftChild;
        goto block_7;
    }
    if (temp_r3 > 0) {
        var_r28 += 1;
        *var_r24 = 1;
        var_r24 += 1;
        nodeStack[var_r25] = var_r27;
        var_r25 += 1;
        var_r27 = var_r27->s_rightChild;
block_7:
        if (var_r27 == NULL) {
            return NULL;
        }
        goto loop_3;
    }
    temp_r5 = var_r27->s_leftChild;
    if (temp_r5 == NULL) {
        if (var_r28 == 0) {
            *arg0 = var_r27->s_rightChild;
        } else {
            temp_r3_2 = nodeStack[var_r28 - 1];
            if (var_r27 == temp_r3_2->s_leftChild) {
                temp_r3_2->s_leftChild = var_r27->s_rightChild;
            } else {
                temp_r3_2->s_rightChild = var_r27->s_rightChild;
            }
        }
    } else {
        var_r4_2 = &var_r27->s_rightChild;
        if (*var_r4_2 == NULL) {
            if (var_r28 == 0) {
                *arg0 = temp_r5;
            } else {
                temp_r3_3 = nodeStack[var_r28 - 1];
                if (var_r27 == temp_r3_3->s_leftChild) {
                    temp_r3_3->s_leftChild = temp_r5;
                } else {
                    temp_r3_3->s_rightChild = temp_r5;
                }
            }
        } else {
            temp_r6 = var_r28;
            unksp8[var_r28] = 1;
            var_r28_2 = var_r28 + 1;
            var_r5 = *var_r4_2;
            nodeStack[var_r28] = var_r27;
            var_r4 = &nodeStack[var_r28_2];
            var_r3 = &unksp8[var_r28_2];
            do {
                *var_r3 = -1;
                var_r28_2 += 1;
                var_r3 += 1;
                *var_r4 = var_r5;
                var_r4 += 1;
                var_r5 = var_r5->s_leftChild;
            } while (var_r5 != NULL);
            var_r28 = var_r28_2 - 1;
            temp_r5_2 = nodeStack[var_r28];
            if (temp_r6 == 0) {
                *arg0 = temp_r5_2;
            } else {
                temp_r3_4 = nodeStack[temp_r6 - 1];
                if (var_r27 == temp_r3_4->s_leftChild) {
                    temp_r3_4->s_leftChild = temp_r5_2;
                } else {
                    temp_r3_4->s_rightChild = temp_r5_2;
                }
            }
            temp_r3_5 = &nodeStack[var_r28];
            if (*temp_r3_5 != var_r27) {
                *temp_r3_5 = temp_r5_2->s_rightChild;
                temp_r5_2->s_rightChild = var_r27->s_rightChild;
            }
            temp_r5_2->s_leftChild = var_r27->s_leftChild;
            temp_r5_2->s_balance = var_r27->s_balance;
            nodeStack[temp_r6] = temp_r5_2;
        }
    }
    var_r4_2 = &nodeStack[var_r28];
    var_ctr = var_r28;
    if (var_r28 != 0) {
loop_32:
        temp_r6_2 = var_r4_2[-1];
        var_r4_2 -= 1;
        var_r28 -= 1;
        temp_r7 = temp_r6_2->s_balance;
        if ((s8)temp_r7 == 0) {
            temp_r6_2->s_balance = (u8)(temp_r7 - unksp8[var_r28]);
            return var_r27;
        }
        temp_r5_3 = &unksp8[var_r28];
        temp_r9 = *temp_r5_3;
        temp_r6_2->s_balance = (u8)(temp_r7 - temp_r9);
        if ((s8)temp_r6_2->s_balance != 0) {
            if ((s8)temp_r9 == 1) {
                var_r7 = temp_r6_2->s_leftChild;
            } else {
                var_r7 = temp_r6_2->s_rightChild;
            }
            if ((s8)var_r7->s_balance != (s8)temp_r9) {
                if ((s8)temp_r9 != 1) {
                    temp_r6_2->s_rightChild = var_r7->s_leftChild;
                    var_r7->s_leftChild = temp_r6_2;
                } else {
                    temp_r6_2->s_leftChild = var_r7->s_rightChild;
                    var_r7->s_rightChild = temp_r6_2;
                }
                if (var_r28 != 0) {
                    if ((s32)temp_r5_3[-1] == 1) {
                        var_r4_2[-1]->s_rightChild = var_r7;
                    } else {
                        var_r4_2[-1]->s_leftChild = var_r7;
                    }
                } else {
                    *arg0 = var_r7;
                }
                if ((s8)var_r7->s_balance == 0) {
                    var_r4_3 = -1U;
                    if ((s8)temp_r6_2->s_balance > 0) {
                        var_r4_3 = 1;
                    }
                    temp_r6_2->s_balance = var_r4_3;
                    var_r7->s_balance = (u8)-(s32)temp_r6_2->s_balance;
                    return var_r27;
                }
                var_r7->s_balance = 0U;
                temp_r6_2->s_balance = 0U;
                goto block_68;
            }
            if ((s8)temp_r9 != 1) {
                var_r8 = var_r7->s_leftChild;
                var_r7->s_leftChild = var_r8->s_rightChild;
                temp_r6_2->s_rightChild = var_r8->s_leftChild;
                var_r8->s_rightChild = var_r7;
                var_r8->s_leftChild = temp_r6_2;
                temp_r0 = var_r8->s_balance;
                if ((s8)temp_r0 == 1) {
                    temp_r6_2->s_balance = -1U;
                    var_r7->s_balance = 0U;
                } else if ((s8)temp_r0 == -1) {
                    temp_r6_2->s_balance = 0U;
                    var_r7->s_balance = 1U;
                } else {
                    var_r7->s_balance = 0U;
                    temp_r6_2->s_balance = 0U;
                }
            } else {
                var_r8 = var_r7->s_rightChild;
                var_r7->s_rightChild = var_r8->s_leftChild;
                temp_r6_2->s_leftChild = var_r8->s_rightChild;
                var_r8->s_leftChild = var_r7;
                var_r8->s_rightChild = temp_r6_2;
                temp_r0_2 = var_r8->s_balance;
                if ((s8)temp_r0_2 == 1) {
                    temp_r6_2->s_balance = 0U;
                    var_r7->s_balance = -1U;
                } else if ((s8)temp_r0_2 == -1) {
                    temp_r6_2->s_balance = 1U;
                    var_r7->s_balance = 0U;
                } else {
                    temp_r6_2->s_balance = 0U;
                    var_r7->s_balance = 0U;
                }
            }
            var_r8->s_balance = 0;
            if (var_r28 != 0) {
                if ((s32)temp_r5_3[-1] == 1) {
                    var_r4_2[-1]->s_rightChild = var_r8;
                } else {
                    var_r4_2[-1]->s_leftChild = var_r8;
                }
            } else {
                *arg0 = var_r8;
            }
            goto block_68;
        }
block_68:
        var_ctr -= 1;
        if (var_ctr == 0) {
            return var_r27;
        }
        goto loop_32;
    }
    return var_r27;
}

/**
 * Offset/Address/Size: 0x490 | 0x801CE5B0 | size: 0x398
 */
void AVLTreeUntemplated::AddAVLNode(AVLTreeNode** arg0, void* arg1, void* arg2, AVLTreeNode** arg4, unsigned int arg5)
{
    s8 sp8[32];  // Stack array for storing comparison results
    s32 var_r19;
    s32 var_r26;
    s8* var_r20;
    s8* var_r5;
    s8 temp_r3;
    u32 temp_r9;
    u8 temp_r3_2;
    u8 temp_r3_3;
    u8 temp_r5;
    u8 temp_r5_2;
    u8 temp_r7;
    AVLTreeNode* temp_r4;
    AVLTreeNode* var_r28;
    AVLTreeNode* var_r29;
    AVLTreeNode* var_r30;
    AVLTreeNode* var_r3;
    AVLTreeNode* var_r3_2;
    AVLTreeNode* var_r3_3;
    AVLTreeNode* var_r4;
    AVLTreeNode* var_r8;

    *arg4 = NULL;
    temp_r4 = *(AVLTreeNode**)arg1;
    if (temp_r4 == NULL) {
        // Virtual function call: this->AllocateEntry(arg2, arg1)
        AVLTreeNode* newNode = this->AllocateEntry(arg2, arg1);
        *(AVLTreeNode**)arg1 = newNode;
        return;
    }
    var_r30 = temp_r4;
    var_r28 = temp_r4;
    var_r29 = NULL;
    var_r19 = 0;
    var_r26 = 0;
    var_r20 = sp8;
loop_3:
    // Virtual function call: this->CompareNodes(arg2, var_r28)
    temp_r3 = this->CompareNodes((AVLTreeNode*)arg2, (AVLTreeNode*)var_r28);
    *var_r20 = temp_r3;
    var_r19 += 1;
    var_r20 += 1;
    if (temp_r3 == 0) {
        *arg4 = var_r28;
        return;
    }
    if (temp_r3 > 0) {
        var_r3 = var_r28->s_rightChild;
        if (var_r3 == NULL) {
            var_r3_2 = this->AllocateEntry(arg2, arg1);
            var_r28->s_rightChild = var_r3_2;
            goto block_13;
        }
        goto block_10;
    }
    var_r3 = var_r28->s_leftChild;
    if (var_r3 == NULL) {
        var_r3_2 = this->AllocateEntry(arg2, arg1);
        var_r28->s_leftChild = var_r3_2;
block_13:
        temp_r9 = (sp8[var_r26] >> 31) & 1;
        if (temp_r9 != 0) {
            var_r4 = var_r30->s_leftChild;
        } else {
            var_r4 = var_r30->s_rightChild;
        }
        var_r8 = var_r4;
        var_r5 = &(sp8)[var_r26];
loop_20:
        if (var_r8 != var_r3_2) {
            temp_r7 = var_r5[1];
            var_r5 += 1;
            if ((s8)temp_r7 < 0) {
                var_r8->s_balance = -1;
                var_r8 = var_r8->s_leftChild;
            } else {
                var_r8->s_balance = 1;
                var_r8 = var_r8->s_rightChild;
            }
            goto loop_20;
        }
        if (temp_r9 != 0) {
            temp_r3_2 = var_r30->s_balance;
            if ((s8)temp_r3_2 == 0) {
                var_r30->s_balance = -1;
                return;
            }
            if ((s8)temp_r3_2 < 0) {
                if ((s8)var_r4->s_balance < 0) {
                    var_r3_3 = var_r4;
                    var_r30->s_leftChild = var_r4->s_rightChild;
                    var_r4->s_rightChild = var_r30;
                    var_r30->s_balance = 0;
                    var_r4->s_balance = 0;
                } else {
                    var_r3_3 = var_r4->s_rightChild;
                    var_r4->s_rightChild = var_r3_3->s_leftChild;
                    var_r3_3->s_leftChild = var_r4;
                    var_r30->s_leftChild = var_r3_3->s_rightChild;
                    var_r3_3->s_rightChild = var_r30;
                    temp_r5 = var_r3_3->s_balance;
                    if ((s8)temp_r5 == 0) {
                        var_r30->s_balance = 0;
                        var_r4->s_balance = 0;
                    } else if ((s8)temp_r5 < 0) {
                        var_r30->s_balance = 1;
                        var_r4->s_balance = 0;
                    } else {
                        var_r30->s_balance = 0;
                        var_r4->s_balance = -1;
                    }
                    var_r3_3->s_balance = 0;
                }
                goto block_46;
            }
            var_r30->s_balance = 0;
            return;
        }
        temp_r3_3 = var_r30->s_balance;
        if ((s8)temp_r3_3 == 0) {
            var_r30->s_balance = 1;
            return;
        }
        if ((s8)temp_r3_3 > 0) {
            if ((s8)var_r4->s_balance > 0) {
                var_r3_3 = var_r4;
                var_r30->s_rightChild = var_r4->s_leftChild;
                var_r4->s_leftChild = var_r30;
                var_r30->s_balance = 0;
                var_r4->s_balance = 0;
            } else {
                var_r3_3 = var_r4->s_leftChild;
                var_r4->s_leftChild = var_r3_3->s_rightChild;
                var_r3_3->s_rightChild = var_r4;
                var_r30->s_rightChild = var_r3_3->s_leftChild;
                var_r3_3->s_leftChild = var_r30;
                temp_r5_2 = var_r3_3->s_balance;
                if ((s8)temp_r5_2 == 0) {
                    var_r30->s_balance = 0;
                    var_r4->s_balance = 0;
                } else if ((s8)temp_r5_2 > 0) {
                    var_r30->s_balance = -1;
                    var_r4->s_balance = 0;
                } else {
                    var_r30->s_balance = 0;
                    var_r4->s_balance = 1;
                }
                var_r3_3->s_balance = 0;
            }
block_46:
            if (var_r29 == NULL) {
                *(AVLTreeNode**)arg1 = var_r3_3;
            } else if (var_r30 == var_r29->s_rightChild) {
                var_r29->s_rightChild = var_r3_3;
            } else {
                var_r29->s_leftChild = var_r3_3;
            }
            return;
        }
        var_r30->s_balance = 0;
        return;
    }
block_10:
    if ((s8)var_r3->s_balance != 0) {
        var_r29 = var_r28;
        var_r30 = var_r3;
        var_r26 = var_r19;
    }
    var_r28 = var_r3;
    goto loop_3;
}
