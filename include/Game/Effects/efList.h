#ifndef _EFLIST_H_
#define _EFLIST_H_

#include "types.h"

class efBaseNode
{
public:
    /* 0x0, */ struct efBaseNode* m_nextNode;
    /* 0x4, */ struct efBaseNode* m_prevNode;
};

class efBaseList
{
public:
    void Insert(efBaseNode*);
    void Append(efBaseNode*);
    efBaseNode* Remove();
    efBaseNode* Remove(efBaseNode*);

    /* 0x0, */ struct efBaseNode* m_headNode;
    /* 0x4, */ struct efBaseNode* m_tailNode;
    /* 0x8, */ int m_numNodes;
};

#endif // _EFLIST_H_
