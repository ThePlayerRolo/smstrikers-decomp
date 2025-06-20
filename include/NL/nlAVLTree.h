#ifndef _NLAVLTREE_H_
#define _NLAVLTREE_H_

#include "dolphin/types.h"

typedef struct AVLTreeNode {
    /* 0x00 */ struct AVLTreeNode* s_leftChild; 
    /* 0x04 */ struct AVLTreeNode* s_rightChild;
    /* 0x08 */ u8 s_balance;
    /* 0x0C */ s32 s_key;
    /* 0x10 */ void* s_data;

    // AVLTreeNode()
    // {
    //     s_leftChild = NULL;
    //     s_rightChild = NULL;
    //     s_data = NULL;
    //     s_key = 0; 
    // }

} AVLTreeNode, *AVLTreeNodePtr;

class AVLTreeUntemplated
{
public:
    virtual s32 CompareNodes(AVLTreeNode* node1, AVLTreeNode* node2) = 0;  // vtable offset 0xc
    virtual AVLTreeNode* AllocateEntry(void* key, void* value) = 0;
    
    AVLTreeNode* RemoveAVLNode(AVLTreeNode**, void*, unsigned int);
    void AddAVLNode(AVLTreeNode**, void*, void*, AVLTreeNode**, unsigned int);
};

#endif // _NLAVLTREE_H_
