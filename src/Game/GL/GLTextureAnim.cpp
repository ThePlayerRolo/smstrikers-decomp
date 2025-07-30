#include "GLTextureAnim.h"
#include "NL/nlMemory.h"

/**
 * Offset/Address/Size: 0x0 | 0x801E7988 | size: 0x120
 */
void GLTextureAnim::Update(float deltaTime)
{
    // Early return if animation is stopped
    if (m_isStopped)
    {
        return;
    }

    // Early return if we have less than 2 textures
    if (m_numTextures < 2)
    {
        return;
    }

    // Update current time
    m_currentTime += deltaTime;

    // Get the time threshold for the current frame
    u32 frameIndex = m_currentFrame;
    GLAnimTex* textureArray = m_textureArray;
    u32 offset = frameIndex * 8 + 4; // 8 bytes per GLAnimTex, +4 for time field
    f32 timeThreshold = *(f32*)((u8*)textureArray + offset);

    // Check if we've reached the time threshold for the current frame
    if (m_currentTime >= timeThreshold)
    {
        // Reset current time
        m_currentTime = 0.0f;

        // Handle different animation types
        switch (m_animationType)
        {
            case 0: // Loop
                m_currentFrame++;
                if (m_currentFrame >= m_numTextures)
                {
                    m_currentFrame = 0;
                }
                break;

            case 1: // Ping-pong
                if (m_direction > 0)
                {
                    m_currentFrame++;
                    if (m_currentFrame >= m_numTextures)
                    {
                        m_currentFrame = m_numTextures - 2;
                        m_direction = -1;
                    }
                }
                else
                {
                    m_currentFrame--;
                    if (m_currentFrame < 0)
                    {
                        m_currentFrame = 1;
                        m_direction = 1;
                    }
                }
                break;

            case 2: // Once
                m_currentFrame++;
                if (m_currentFrame >= m_numTextures)
                {
                    m_currentFrame = m_numTextures - 1;
                }
                break;

            case 3: // Reverse
                m_currentFrame++;
                if (m_currentFrame >= m_numTextures)
                {
                    m_currentFrame = m_numTextures - 1;
                }
                break;
        }
    }
}

/**
 * Offset/Address/Size: 0x120 | 0x801E7AA8 | size: 0xA0
 */
u32 GLTextureAnim::GetTextureHandle(float time)
{
    GLAnimTex* textureArray = m_textureArray;
    u32 frameIndex = 0;

    while (true)
    {
        u32 actualFrame;
        if (frameIndex < 0)
        {
            actualFrame = m_currentFrame;
        }
        else
        {
            actualFrame = frameIndex;
        }

        u32 offset = actualFrame * 8;
        GLAnimTex* currentTex = (GLAnimTex*)((u8*)textureArray + offset);
        f32 timeThreshold = currentTex->m_time;
        u32 textureHandle = currentTex->m_textureHandle;

        // Check if we've found the right time slot
        if (time < timeThreshold)
        {
            return textureHandle;
        }

        // Handle different animation types for frame progression
        switch (m_animationType)
        {
            case 0: // Loop
                frameIndex++;
                if (frameIndex >= m_numTextures)
                {
                    frameIndex = 0;
                }
                break;

            case 1: // Ping-pong
                frameIndex++;
                if (frameIndex >= m_numTextures)
                {
                    frameIndex = 0;
                }
                break;

            case 2: // Once
                frameIndex++;
                if (frameIndex >= m_numTextures)
                {
                    return textureHandle; // Return last texture
                }
                break;

            case 3: // Reverse
                frameIndex++;
                if (frameIndex >= m_numTextures)
                {
                    return textureHandle; // Return last texture
                }
                break;
        }
    }
}

/**
 * Offset/Address/Size: 0x1C0 | 0x801E7B48 | size: 0x1C
 */
GLAnimTex* GLTextureAnim::GetTexture(int frameIndex)
{
    GLAnimTex* textureArray = m_textureArray;
    
    // If frameIndex is negative, use current frame
    if (frameIndex < 0)
    {
        frameIndex = m_currentFrame;
    }

    u32 offset = frameIndex * 8;
    return (GLAnimTex*)((u8*)textureArray + offset);
}

/**
 * Offset/Address/Size: 0x1DC | 0x801E7B64 | size: 0x20
 */
void GLTextureAnim::SetTexture(int frameIndex, const GLAnimTex& animTex)
{
    GLAnimTex* textureArray = m_textureArray;
    u32 offset = frameIndex * 8;
    GLAnimTex* targetTex = (GLAnimTex*)((u8*)textureArray + offset);
    
    targetTex->m_textureHandle = animTex.m_textureHandle;
    targetTex->m_time = animTex.m_time;
}

/**
 * Offset/Address/Size: 0x1FC | 0x801E7B84 | size: 0x18
 */
void GLTextureAnim::SetFrame(int frameIndex)
{
    m_currentFrame = frameIndex % m_numTextures;
}

/**
 * Offset/Address/Size: 0x214 | 0x801E7B9C | size: 0x74
 */
void GLTextureAnim::SetNumTextures(int numTextures)
{
    if (m_textureArray != nullptr)
    {
        delete [] m_textureArray;
    }

    // Allocate new texture array
    u32 size = numTextures * 8; // 8 bytes per GLAnimTex
    m_textureArray = (GLAnimTex*)nlMalloc(size, 8, 0);
    
    m_numTextures = numTextures;
    m_direction = 1;
    m_currentFrame = 0;
    m_currentTime = 0.0f;
}

/**
 * Offset/Address/Size: 0x288 | 0x801E7C10 | size: 0x5C
 */
GLTextureAnim::~GLTextureAnim()
{
    // Free texture array if it exists
    if (m_textureArray != nullptr)
    {
        delete [] m_textureArray;
    }
}

/**
 * Offset/Address/Size: 0x2E4 | 0x801E7C6C | size: 0x2C
 */
GLTextureAnim::GLTextureAnim()
{
    m_unk_0x00 = -1;
    m_numTextures = 0;
    m_animationType = 0;
    m_direction = 1;
    m_currentFrame = 0;
    m_textureArray = nullptr;
    m_isStopped = false;
}
