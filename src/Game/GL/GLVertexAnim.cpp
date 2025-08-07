#include "GLVertexAnim.h"

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
    m_unk_0x1C = 0.0f;
    m_unk_0x18 = 1.0f;
    m_unk_0x20 = NULL;
    m_unk_0x24 = NULL;
}

/**
 * Offset/Address/Size: 0xBC | 0x801E7D54 | size: 0xDC
 */
void GLVertexAnim::GetModel(int frameIndex)
{
    int actualFrame;

    if (frameIndex < 0)
    {
        actualFrame = (int)m_unk_0x1C; // Convert float to int
    }
    else
    {
        actualFrame = frameIndex;
    }

    glModel* duplicatedModel = glModelDup(m_unk_0x24, true);

    FrameVertexData* frameVertexData = m_unk_0x20 + actualFrame * m_unk_0x08;

    glModelPacket* packet = duplicatedModel->m_packets;
    glModelPacket* endPacket = duplicatedModel->m_packets + duplicatedModel->m_count;

    while (packet < endPacket)
    {
        VertexData* packetVertexData = packet->m_unk_0x0C;
        VertexData* endVertexData = packetVertexData + packet->m_unk_0x0B;
        while (packetVertexData < endVertexData)
        {
            if (packetVertexData->m_unk_0x04 == 0)
            {
                packetVertexData->m_unk_0x00 = (FrameVertexData*)frameVertexData;
                break; // Found and updated the vertex data, move to next packet
            }
            packetVertexData++;
        }
        packet++;
    }
}

/**
 * Offset/Address/Size: 0x1C | 0x801E7CB4 | size: 0xA0
 */
void GLVertexAnim::Update(float arg0)
{
    if (m_unk_0x14)
    {
        return; // Early return if animation is stopped
    }

    // Update animation progress
    m_unk_0x1C += m_unk_0x0C * (m_unk_0x18 * arg0);

    // Check if animation has completed
    if (m_unk_0x1C >= m_unk_0x04)
    {
        if (m_unk_0x10 == 1)
        {
            // Stop animation at the end
            m_unk_0x14 = true;
            m_unk_0x1C = m_unk_0x04 - 1;
        }
        else
        {
            // Loop animation
            m_unk_0x1C = 0.0f;
        }
    }
}

/**
 * Offset/Address/Size: 0x0 | 0x801E7C98 | size: 0x1C
 */
void GLVertexAnim::Reset()
{
    m_unk_0x18 = 1.0f;
    m_unk_0x1C = 0.0f;
    m_unk_0x14 = false;
}
