#ifndef _NLAVLTREE_H_
#define _NLAVLTREE_H_

typedef struct {
    // todo..
} AVLTreeNode, *AVLTreeNodePtr;

class AVLTreeUntemplated
{
public:
    void RemoveAVLNode(AVLTreeNode**, void*, unsigned int);
    void AddAVLNode(AVLTreeNode**, void*, void*, AVLTreeNode**, unsigned int);
};

#endif // _NLAVLTREE_H_
