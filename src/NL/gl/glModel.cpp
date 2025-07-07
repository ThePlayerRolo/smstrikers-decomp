#include "NL/gl/glModel.h"
#include "NL/gl/glMemory.h"
#include "NL/gl/glUserData.h"
#include <string.h>

/**
 * Offset/Address/Size: 0x0 | 0x801DED34 | size: 0x160
 */
void* glModelDupArrayNoStreams(const glModel* models, unsigned long count, bool arg2, bool arg3)
{
    glModelPacket* src_element;
    glModelPacket* dst_element;
    glModel* dst_model;
    glModel* src_model;
    glModel* new_models;
    glModelPacket* new_elements;

    if (arg3 != 0)
    {
        new_models = (glModel*)glResourceAlloc(count * 0x10, eGLMemory_0);
    }
    else
    {
        new_models = (glModel*)glFrameAlloc(count * 0x10, eGLMemory_0);
    }

    if (new_models == NULL)
    {
        return NULL;
    }

    memcpy(new_models, models, count * 0x10);

    src_model = (glModel*)&models[0];
    dst_model = &new_models[0];

    for (int i = 0; i < count; i++)
    {
        // var_r24 = 0;

        // loop_18:
        //     if (var_r24 >= cntModels)
        //     {
        //         return new_model_array;
        //     }

        if (arg3 != 0)
        {
            new_elements = (glModelPacket*)glResourceAlloc(src_model->m_count * 0x4A, eGLMemory_0);
        }
        else
        {
            new_elements = (glModelPacket*)glFrameAlloc(src_model->m_count * 0x4A, eGLMemory_0);
        }

        if (new_elements == NULL)
        {
            return NULL;
        }

        memcpy(new_elements, src_model->m_packets, src_model->m_count * 0x4A);
        dst_model->m_packets = new_elements;
        if (arg2 != 0)
        {
            dst_element = new_elements;
            src_element = src_model->m_packets;

            for (int e = 0; e < src_model->m_count; e++)
            {

        //     last_element = src_element + (src_model->m_count * 0x4A);
        // loop_16:
        //     if (src_element < last_element)
        //     {
                if (*(u32*)src_element->m_unk_0x00 != 0)
                {
                    *(u32*)&dst_element->m_unk_0x00 = 0;
                    glUserDup((glModelPacket*)dst_element, (glModelPacket*)src_element, false);
                }
                src_element++;
                dst_element++;
                // goto loop_16;
            }
        }
        src_model++;
        dst_model++;
    }
    // var_r24 += 1;
    // goto loop_18;
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
void glModelDup(const glModel*, bool)
{
}

/**
 * Offset/Address/Size: 0x3A0 | 0x801DF0D4 | size: 0x8C
 */
void glModelPacketDup(const glModelPacket*, bool)
{
}
