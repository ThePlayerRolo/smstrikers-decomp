#include "NL/gl/glUserData.h"
#include "NL/gl/glMemory.h"
#include "NL/nlString.h"
#include <string.h>

/**
 * Offset/Address/Size: 0x0 | 0x801DEB78 | size: 0x2C
 */
u32 glUserHasType(eGLUserData arg0, const glModelPacket* arg1)
{
    // s32 temp_r3;
    u32 *temp_r4 = (u32*)arg1->m_unk_0x00;
    if (temp_r4 == 0U) {
        return 0U;
    }
    s32 temp_r3 = *(s32*)(temp_r4 + arg0);
    return (u32) (-temp_r3 | temp_r3) >> 0x1FU;
}

/**
 * Offset/Address/Size: 0x2C | 0x801DEBA4 | size: 0x14
 */
void glUserDetach(eGLUserData arg0, glModelPacket* arg1)
{
    u32 *temp_r4 = (u32*)arg1->m_unk_0x00;
    temp_r4[arg0] = 0;
}

/**
 * Offset/Address/Size: 0x40 | 0x801DEBB8 | size: 0x88
 */
void glUserDup(glModelPacket* arg0, const glModelPacket* arg1, bool arg2)
{
    // if (arg1->m_unk_0x00 != 0) 
    if (*(u32*)arg1 != 0) 
    {
        u32 *var_r31;
        if (arg2 != 0) {
            var_r31 = (u32*)glResourceAlloc(0x48, eGLMemory_0);
        } else {
            var_r31 = (u32*)glFrameAlloc(0x48, eGLMemory_0);
        }
        memcpy(var_r31, arg1, 0x48);
        arg0->m_unk_0x00 = var_r31;
    }
}

/**
 * Offset/Address/Size: 0xC8 | 0x801DEC40 | size: 0x94
 */
void glUserAttach(const void* arg0, glModelPacket* arg1, bool arg2)
{
    if ((u32*)arg1 == NULL) {
        u32 *var_r31;
        if (arg2 != 0) {
            var_r31 = (u32*)glResourceAlloc(0x48, eGLMemory_0);
        } else {
            var_r31 = (u32*)glFrameAlloc(0x48, eGLMemory_0);
        }
        nlZeroMemory(var_r31, 0x48);
        arg1->m_unk_0x00 = var_r31;
    }
    arg1->m_unk_0x00[*(u32*)arg0] = *(u32*)arg0;
}

/**
 * Offset/Address/Size: 0x15C | 0x801DECD4 | size: 0x8
 */
void* glUserGetData(const void* arg0)
{
    return (u8*)arg0 + 4;
}

/**
 * Offset/Address/Size: 0x164 | 0x801DECDC | size: 0x58
 */
void glUserAlloc(eGLUserData arg0, unsigned long size, bool resourceAlloc)
{
    s32** var_r3;

    if (resourceAlloc != 0)
    {
        var_r3 = (s32**)glResourceAlloc(size, eGLMemory_0);
    }
    else
    {
        var_r3 = (s32**)glFrameAlloc(size, eGLMemory_0);
    }
    
    if (var_r3 == NULL)
    {
        return;
    }

    *(eGLUserData*)var_r3 = arg0;
}
