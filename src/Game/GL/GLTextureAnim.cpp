#include "GLTextureAnim.h"

/**
 * Offset/Address/Size: 0x0 | 0x801E7988 | size: 0x120
 */
void GLTextureAnim::Update(float)
{
}

/**
 * Offset/Address/Size: 0x120 | 0x801E7AA8 | size: 0xA0
 */
void GLTextureAnim::GetTextureHandle(float)
{
}

/**
 * Offset/Address/Size: 0x1C0 | 0x801E7B48 | size: 0x1C
 */
void GLTextureAnim::GetTexture(int)
{
}

/**
 * Offset/Address/Size: 0x1DC | 0x801E7B64 | size: 0x20
 */
void GLTextureAnim::SetTexture(int, const GLAnimTex&)
{
}

/**
 * Offset/Address/Size: 0x1FC | 0x801E7B84 | size: 0x18
 */
void GLTextureAnim::SetFrame(int)
{
}

/**
 * Offset/Address/Size: 0x214 | 0x801E7B9C | size: 0x74
 */
void GLTextureAnim::SetNumTextures(int)
{
}

/**
 * Offset/Address/Size: 0x288 | 0x801E7C10 | size: 0x5C
 */
GLTextureAnim::~GLTextureAnim()
{
}

/**
 * Offset/Address/Size: 0x2E4 | 0x801E7C6C | size: 0x2C
 */
GLTextureAnim::GLTextureAnim()
{
    m_unk_0x00 = -1;
    m_unk_0x04 = 0;
    m_unk_0x08 = 0;
    m_unk_0x0C = 1;
    m_unk_0x14 = 0;
    m_unk_0x1C = 0;
    m_unk_0x10 = false;
}
