#include "PoseNode.h"

/**
 * Offset/Address/Size: 0x1FC | 0x801E91FC | size: 0x18
 */
cPoseNode::cPoseNode()
{
    m_numChildren = 0;
}

/**
 * Offset/Address/Size: 0x1E0 | 0x801E91E0 | size: 0x1C
 */
cPoseNode::cPoseNode(int arg0)
{
    m_numChildren = 0;
    m_numChildren = arg0;
}

/**
 * Offset/Address/Size: 0x134 | 0x801E9134 | size: 0xAC
 */
cPoseNode::~cPoseNode()
{
    for (int i = 0; i < m_numChildren; ++i)
    {
        cPoseNode* ch = m_children[i];
        if (ch)
        {
            delete ch; // virtual delete via child’s vtable
        }
    }
}

/**
 * Offset/Address/Size: 0x124 | 0x801E9124 | size: 0x10
 */
cPoseNode* cPoseNode::GetChild(int idx)
{
    return m_children[idx];
    // return m_unk_0x04[index]->m_unk_0x04;
}

/**
 * Offset/Address/Size: 0x114 | 0x801E9114 | size: 0x10
 */
cPoseNode* cPoseNode::GetChild(int idx) const
{
    // return m_unk_0x04[index]->m_unk_0x04;
    return m_children[idx];
}

/**
 * Offset/Address/Size: 0x100 | 0x801E9100 | size: 0x14
 */
cPoseNode** cPoseNode::GetChildPtr(int idx)
{
    // return m_unk_0x04[index]->m_unk_0x04;
    return &m_children[idx];
}

/**
 * Offset/Address/Size: 0xF0 | 0x801E90F0 | size: 0x10
 */
void cPoseNode::SetChild(int idx, cPoseNode* child)
{
    // m_unk_0x04[index]->m_unk_0x04 = child;

    m_children[idx] = child;
}

/**
 * Offset/Address/Size: 0x44 | 0x801E9044 | size: 0xAC
 */
void cPoseNode::GetRootTrans(nlVector3* out, unsigned short ang)
{
    float baseW; // +0x1C
    float baseZ; // +0x18
    float baseY; // +0x14
    float baseX; // +0x10

    float c = 1.0f;
    float s = 0.0f;

    baseW = 0.0f;
    baseZ = 0.0f;
    baseY = 0.0f;
    baseX = 0.0f;

    // vfunc at vtable+0x1C: r4=&baseY, f1=1.0f, r5=&baseX
    V_GetRootTrans(reinterpret_cast<nlVector3*>(&baseY), 1.0f, &baseX);

    nlSinCos(&s, &c, ang);

    out->f.x = baseY * c - (baseZ * s);
    out->f.y = baseY * s + (baseZ * c);
}

/**
 * Offset/Address/Size: 0x0 | 0x801E9000 | size: 0x44
 */
void cPoseNode::GetRootRot(unsigned short* out)
{
    float temp = 0.0f;
    *out = 0;
    V_GetRootRot(out, 1.0f, &temp);
}
