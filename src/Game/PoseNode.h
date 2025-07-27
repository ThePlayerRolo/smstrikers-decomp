#ifndef _POSENODE_H_
#define _POSENODE_H_

#include "NL/nlMath.h"

class cPoseNode;

struct cPoseNodeData {
/* 0x00 */ void *m_unk_0x00;
/* 0x04 */ cPoseNode *m_unk_0x04;
};

class cPoseNode
{
public:
    virtual void unk8(int) = 0;
    virtual void unkC() = 0;
    virtual void unk10() = 0;
    virtual void unk14() = 0;
    virtual void unk18() = 0;
    virtual void unk1C(float*, float*, float) = 0;
    virtual void unk20(float*, float) = 0;

    void GetRootRot(unsigned short*);
    void GetRootTrans(nlVector3*, unsigned short);
    void SetChild(int, cPoseNode*);
    cPoseNode* GetChildPtr(int);
    cPoseNode* GetChild(int) const;
    cPoseNode* GetChild(int);

    cPoseNode();
    cPoseNode(int);
    virtual ~cPoseNode();

    /* 0x04 */ cPoseNodeData **m_unk_0x04;
    /* 0x08 */ u8 m_padding_0x08[0x8];
    /* 0x10 */ s32 m_unk_0x10;
};

#endif // _POSENODE_H_
