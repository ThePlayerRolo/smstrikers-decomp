#include "GLVertexAnim.h"

/**
 * Offset/Address/Size: 0x0 | 0x801E7C98 | size: 0x1C
 */
void GLVertexAnim::Reset()
{
}

/**
 * Offset/Address/Size: 0x1C | 0x801E7CB4 | size: 0xA0
 */
void GLVertexAnim::Update(float)
{
}

/**
 * Offset/Address/Size: 0xBC | 0x801E7D54 | size: 0xDC
 */
void GLVertexAnim::GetModel(int)
{
}

/**
 * Offset/Address/Size: 0x198 | 0x801E7E30 | size: 0x40
 */
GLVertexAnim::GLVertexAnim()
{
    m_unk_0x00 = -1;
    m_unk_0x04 = 0;
    m_unk_0x08 = 0;
    m_unk_0x0C = 30.0f;
    m_unk_0x10 = 0;
    m_unk_0x14 = false;
    m_unk_0x18 = 1.0f;
    m_unk_0x1C = 0.0f;
    m_unk_0x20 = 0;
    m_unk_0x24 = NULL;    
}
