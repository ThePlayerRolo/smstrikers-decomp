#ifndef _NLAVLTREE_H_
#define _NLAVLTREE_H_

#include "dolphin/types.h"

// AVLTreeNode structure based on the decompiled code
// unk0 = left child (offset 0x00)
// unk4 = right child (offset 0x04) 
// unk8 = balance factor (offset 0x08)
// unk10 = data pointer (offset 0x10)
typedef struct AVLTreeNode {
    struct AVLTreeNode* unk0;  // left child (offset 0x00)
    struct AVLTreeNode* unk4;  // right child (offset 0x04) 
    s8 unk8;                   // balance factor (offset 0x08)
    void* unk10;               // data (offset 0x10)
} AVLTreeNode, *AVLTreeNodePtr;

class AVLTreeUntemplated
{
public:
    // Virtual functions (vtable entries)
    virtual s8 CompareNodes(void* data1, void* data2);  // vtable offset 0xc
    virtual AVLTreeNode* CreateNode(void* data1, void* data2);  // vtable offset 0x10
    
    // Non-virtual functions
    AVLTreeNode* RemoveAVLNode(AVLTreeNode**, void*, unsigned int);
    void AddAVLNode(AVLTreeNode**, void*, void*, AVLTreeNode**, unsigned int);
};

#endif // _NLAVLTREE_H_
