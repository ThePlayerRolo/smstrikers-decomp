#include "PoseNode.h"

/**
 * Offset/Address/Size: 0x0 | 0x801E9000 | size: 0x44
 */
void cPoseNode::GetRootRot(unsigned short* arg0)
{
    f32 sp8;
    sp8 = 0.0f;
    *arg0 = 0;
    unk20(&sp8, 1.0f);
}

/**
 * Offset/Address/Size: 0x44 | 0x801E9044 | size: 0xAC
 */
void cPoseNode::GetRootTrans(nlVector3* vec, unsigned short arg1)
{
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp10 = 0.0f;
    sp14 = 0.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;

    unk1C(&sp14, &sp10, 1.0f);
    nlSinCos(&sp8, &spC, arg1);
    vec->x = (sp14 * spC) - (sp18 * sp8);
    vec->y = (sp18 * spC) + (sp14 * sp8);
}

/**
 * Offset/Address/Size: 0xF0 | 0x801E90F0 | size: 0x10
 */
void cPoseNode::SetChild(int index, cPoseNode* child)
{
    m_unk_0x04[index]->m_unk_0x04 = child;
}

/**
 * Offset/Address/Size: 0x100 | 0x801E9100 | size: 0x14
 */
 cPoseNode* cPoseNode::GetChildPtr(int index)
{
    return m_unk_0x04[index]->m_unk_0x04;
}

/**
 * Offset/Address/Size: 0x114 | 0x801E9114 | size: 0x10
 */
 cPoseNode* cPoseNode::GetChild(int index) const
{
    return m_unk_0x04[index]->m_unk_0x04;
}

/**
 * Offset/Address/Size: 0x124 | 0x801E9124 | size: 0x10
 */
 cPoseNode* cPoseNode::GetChild(int index)
{
    return m_unk_0x04[index]->m_unk_0x04;
}

/**
 * Offset/Address/Size: 0x134 | 0x801E9134 | size: 0xAC
 */
cPoseNode::~cPoseNode()
{
    for (int i = 0; i < m_unk_0x10; i++) {
        cPoseNodeData *ptr = m_unk_0x04[i];
        if (ptr->m_unk_0x04 != NULL) {
            ptr->m_unk_0x04->unk8(1);
        }
    }
}

/**
 * Offset/Address/Size: 0x1E0 | 0x801E91E0 | size: 0x1C
 */
cPoseNode::cPoseNode(int arg0)
{
    m_unk_0x10 = 0;
    m_unk_0x10 = arg0;
}

/**
 * Offset/Address/Size: 0x1FC | 0x801E91FC | size: 0x18
 */
cPoseNode::cPoseNode()
{
    m_unk_0x10 = 0;
}
