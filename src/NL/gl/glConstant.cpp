#include "NL/gl/glConstant.h"
#include "NL/nlAVLTreeBase.h"
#include "NL/nlString.h"

int level = 0;

AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4> >, DefaultKeyCompare<unsigned long> > *constants[16] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL  };

// Global zero vector
static const nlVector4 vZero(0.0f, 0.0f, 0.0f, 0.0f);

/**
 * Inlineable helper method to search for a constant in the AVL tree
 * Returns pointer to the found nlVector4 or NULL if not found
 */
inline nlVector4* FindConstantInTree(AVLTreeEntry<unsigned long, nlVector4>* root, u32 hash)
{
    AVLTreeEntry<unsigned long, nlVector4>* current = root;
    
    while (current != NULL) {
        u32 currentHash = current->GetKey();
        
        if (hash == currentHash) {
            return &current->GetValue();
        } else if (hash < currentHash) {
            current = current->m_left;
        } else {
            current = current->m_right;
        }
    }
    
    return NULL;
}

/**
 * Offset/Address/Size: 0x0 | 0x801DF220 | size: 0x10C
 */
 nlVector4 glConstantGet(const char* arg1)
{
    nlVector4* sp8;
    nlVector4* var_r4_2;
    s32 var_ctr;
    s32 var_r0_2;
    s8 var_r0;
    u32 temp_r0;
    u32 temp_r3;
    AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4> >, DefaultKeyCompare<unsigned long> > **var_r5;
    AVLTreeEntry<unsigned long, nlVector4>* var_r4;

    temp_r3 = nlStringHash(arg1);
    var_r5 = &constants[level];
    var_ctr = level + 1;
    if ((s32) level >= 0) {
loop_1:
        var_r4 = (*var_r5)->m_root_entry_0x08;
loop_14:
        if (var_r4 == NULL) {
            var_r0 = 0;
        } else {
            temp_r0 = var_r4->GetKey();
            if (temp_r3 == temp_r0) {
                var_r0_2 = 0;
            } else if (temp_r3 < temp_r0) {
                var_r0_2 = -1;
            } else {
                var_r0_2 = 1;
            }
            if (var_r0_2 == 0) {
                if (&sp8 != NULL) {
                    sp8 = &var_r4->GetValue();
                }
                var_r0 = 1;
            } else {
                if (var_r0_2 < 0) {
                    var_r4 = var_r4->m_left;
                } else {
                    var_r4 = var_r4->m_right;
                }
                goto loop_14;
            }
        }
        if (var_r0 != 0) {
            var_r4_2 = sp8;
        } else {
            var_r5 -= 4;
            var_ctr -= 1;
            if (var_ctr == 0) {
                goto block_19;
            }
            goto loop_1;
        }
    } else {
block_19:
        var_r4_2 = NULL;
    }
    if (var_r4_2 == NULL) {
        var_r4_2 = (nlVector4*)&vZero;
    }
    // M2C_STRUCT_COPY(arg0, var_r4_2, 0x10);    
    return *var_r4_2;
}

/**
 * Offset/Address/Size: 0x10C | 0x801DF32C | size: 0x10C
 */
bool glConstantGet(const char*, nlVector4&)
{
    return false;
}

/**
 * Offset/Address/Size: 0x218 | 0x801DF438 | size: 0x14C
 */
void glConstantSet(const char*, const nlVector4&)
{
}

/**
 * Offset/Address/Size: 0x364 | 0x801DF584 | size: 0x60
 */
void gl_ConstantMarkerBackup(int arg)
{
    while (level != arg)
    {
        constants[level]->Clear();
        level--;
    }
}

/**
 * Offset/Address/Size: 0x3C4 | 0x801DF5E4 | size: 0x10
 */
void gl_ConstantMarkerAdvance()
{
    level++;
}

/**
 * Offset/Address/Size: 0x3D4 | 0x801DF5F4 | size: 0x98
 */
void gl_ConstantStartup()
{
}

// /*
// // Fake template specialization implementations - these were never in the original code
// // They are decompiler artifacts from template instantiation

// /**
//  * Offset/Address/Size: 0x0 | 0x801DF68C | size: 0x24
//  */
// void AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::DeleteEntry(AVLTreeEntry<unsigned long, nlVector4>*)
// {
// }

// /**
//  * Offset/Address/Size: 0x24 | 0x801DF6B0 | size: 0x58
//  */
// void AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::Clear()
// {
// }

// /**
//  * Offset/Address/Size: 0x7C | 0x801DF708 | size: 0x64
//  */
// void AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::DestroyTree(void (AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, nlVector4>*))
// {
// }

// /**
//  * Offset/Address/Size: 0xE0 | 0x801DF76C | size: 0x758
//  */
// void AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::PostorderTraversal(AVLTreeEntry<unsigned long, nlVector4>*, void (AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::*)(AVLTreeEntry<unsigned long, nlVector4>*))
// {
// }

// /**
//  * Offset/Address/Size: 0x838 | 0x801DFEC4 | size: 0x8
//  */
// void AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::CastUp(AVLTreeNode*) const
// {
// }

// /**
//  * Offset/Address/Size: 0x840 | 0x801DFECC | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::CompareNodes(AVLTreeNode*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x86C | 0x801DFEF8 | size: 0x2C
//  */
// void AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::CompareKey(void*, AVLTreeNode*)
// {
// }

// /**
//  * Offset/Address/Size: 0x898 | 0x801DFF24 | size: 0x7C
//  */
// void AVLTreeBase<unsigned long, nlVector4, NewAdapter<AVLTreeEntry<unsigned long, nlVector4>>, DefaultKeyCompare<unsigned long>>::AllocateEntry(void*, void*)
// {
// }
// */
