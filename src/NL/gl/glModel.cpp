#include "NL/gl/glModel.h"
#include "NL/gl/glMemory.h"
#include "NL/gl/glUserData.h"
#include <string.h>

/**
 * Offset/Address/Size: 0x0 | 0x801DED34 | size: 0x160
 */
void* glModelDupArrayNoStreams(const glModel* models, unsigned long count, bool arg2, bool arg3)
{
    glModel* new_models[4];
    glModelPacket* new_packets;
    glModelPacket* dst_pack;
    glModelPacket* src_pack;
    glModel* src_model;
    glModel* dst_model;

    if (arg3 != 0)
    {
        new_models[0] = (glModel*)glResourceAlloc(count * 0x10, eGLMemory_0);
    }
    else
    {
        new_models[0] = (glModel*)glFrameAlloc(count * 0x10, eGLMemory_0);
    }

    if (new_models == NULL)
    {
        return NULL;
    }

    memcpy(new_models, models, count * 0x10);

    src_model = (glModel*)&models[0];
    dst_model = new_models[0];

    for (int i = 0; i < count; i++)
    {
        if (arg3 != 0)
        {
            new_packets = (glModelPacket*)glResourceAlloc(src_model->m_count * 0x4A, eGLMemory_0);
        }
        else
        {
            new_packets = (glModelPacket*)glFrameAlloc(src_model->m_count * 0x4A, eGLMemory_0);
        }

        if (new_packets == NULL)
        {
            return NULL;
        }

        memcpy(new_packets, src_model->m_packets, src_model->m_count * 0x4A);
        dst_model->m_packets = new_packets;
        if (arg2 != 0)
        {
            dst_pack = new_packets;
            src_pack = src_model->m_packets;
            u8* last_pack = (u8*)src_pack + src_model->m_count * 0x4A;

            while ((u8*)src_pack < last_pack)
            {
                if (*(u32*)src_pack->m_unk_0x00 != 0)
                {
                    *(u32*)&dst_pack->m_unk_0x00 = 0;
                    glUserDup((glModelPacket*)dst_pack, (glModelPacket*)src_pack, false);
                }
                src_pack = (glModelPacket*)((u8*)src_pack + 0x4A);
                dst_pack = (glModelPacket*)((u8*)dst_pack + 0x4A);
            }
        }
        src_model++;
        dst_model++;
    }
    return new_models[0];
}

/**
 * Offset/Address/Size: 0x160 | 0x801DEE94 | size: 0x12C
 */
void glModelDupNoStreams(const glModel*, bool, bool)
{
}

/**
 * Offset/Address/Size: 0x28C | 0x801DEFC0 | size: 0x114
 */
glModel* glModelDup(const glModel* src, bool arg1)
{
    glModel* model;
    glModelPacket* packets;
    glModelPacket* src_packets;
    glModelPacket* dst_packets;

    model = (glModel*)glFrameAlloc(0x10, eGLMemory_0);
    if (model == NULL)
    {
        return NULL;
    }

    packets = (glModelPacket*)glFrameAlloc(src->m_count * 0x4A, eGLMemory_0);
    if (packets == NULL)
    {
        return NULL;
    }

    memcpy(model, src, 0x10);
    memcpy(packets, src->m_packets, src->m_count * 0x4A);

    dst_packets = packets;
    src_packets = src->m_packets;
    model->m_packets = packets;
   
    u8* last_pack = (u8*)src_packets + src->m_count * 0x4A;

    while ((u8*)src_packets < last_pack)
    {
        dst_packets->m_unk_0x0C = (VertexData*)glFrameAlloc(dst_packets->m_unk_0x0B * 6, eGLMemory_0);
        memcpy(dst_packets->m_unk_0x0C, src_packets->m_unk_0x0C, dst_packets->m_unk_0x0B * 6);

        if ((arg1 != 0) && (src_packets->m_unk_0x00 != NULL))
        {
            dst_packets->m_unk_0x00 = NULL;
            glUserDup(dst_packets, src_packets, false);
        }

        src_packets = (glModelPacket*)((u8*)src_packets + 0x4A);
        dst_packets = (glModelPacket*)((u8*)dst_packets + 0x4A);        
    }

    return model;
}

/**
 * Offset/Address/Size: 0x3A0 | 0x801DF0D4 | size: 0x8C
 */
void glModelPacketDup(const glModelPacket*, bool)
{
}
