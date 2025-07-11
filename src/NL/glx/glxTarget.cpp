#include "NL/glx/glxTarget.h"
#include "NL/glx/glxTexture.h"
#include "Dolphin/gx.h"

struct glx_DOFTexture {
    /* 0x00 */ u32 m_unk_0x00;
    /* 0x04 */ u32 m_unk_0x04;
    /* 0x08 */ u32 m_unk_0x08;
    /* 0x0C */ u32 m_unk_0x0C;
    /* 0x10 */ u32 m_unk_0x10;
    /* 0x14 */ void* m_unk_0x14;
};

u8 glx_SharedLock = 0;
u32 DOFTextureName = 0;

/**
 * Offset/Address/Size: 0x0 | 0x801C26DC | size: 0x104
 */
void glPlatGrabFrameBufferToTexture(unsigned long, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int)
{
}

/**
 * Offset/Address/Size: 0x104 | 0x801C27E0 | size: 0x4
 */
void glx_UpdateWarble()
{
}

/**
 * Offset/Address/Size: 0x108 | 0x801C27E4 | size: 0xE0
 */
void glx_DOFUpdate(float)
{
}

/**
 * Offset/Address/Size: 0x1E8 | 0x801C28C4 | size: 0xC4
 */
void glx_DOFGrab()
{
    if ((u8) glx_SharedLock == 0) 
    {
        bool colorUpdate = gxSetColourUpdate(1);
        bool alphaUpdate = gxSetAlphaUpdate(1);
        gxSaveZMode();
        gxSetZMode(1, GX_LEQUAL, 1);
        GXSetTexCopySrc(0, 0, 0x280, 0x1C0);
        GXSetTexCopyDst(0x140, 0xE0, GX_TF_RGB565, 1);
        GXCopyTex(((glx_DOFTexture*)glx_GetTex(DOFTextureName, true, true))->m_unk_0x14, 0);
        GXPixModeSync();
        gxSetColourUpdate(colorUpdate);
        gxSetAlphaUpdate(alphaUpdate);
        gxRestoreZMode();
    }    
}

/**
 * Offset/Address/Size: 0x2AC | 0x801C2988 | size: 0x26C
 */
void glx_ShadowTextureGrab()
{
}

/**
 * Offset/Address/Size: 0x518 | 0x801C2BF4 | size: 0xB0
 */
void glx_ClearZBuffer()
{
}

/**
 * Offset/Address/Size: 0x5C8 | 0x801C2CA4 | size: 0x20
 */
void glx_OffsetGrab()
{
}

/**
 * Offset/Address/Size: 0x5E8 | 0x801C2CC4 | size: 0x20
 */
void glx_ColourGrab()
{
}

/**
 * Offset/Address/Size: 0x608 | 0x801C2CE4 | size: 0x20
 */
void glx_ShadowGrab()
{
}

/**
 * Offset/Address/Size: 0x628 | 0x801C2D04 | size: 0x54
 */
void glxPostInitTargets()
{
}

/**
 * Offset/Address/Size: 0x67C | 0x801C2D58 | size: 0x1EC
 */
void glxInitTargets()
{
}

/**
 * Offset/Address/Size: 0x868 | 0x801C2F44 | size: 0x8
 */
void glx_GetSharedLock()
{
}

/**
 * Offset/Address/Size: 0x870 | 0x801C2F4C | size: 0xC
 */
void glx_UnlockSharedMemory()
{
}

/**
 * Offset/Address/Size: 0x87C | 0x801C2F58 | size: 0xC
 */
void glx_LockSharedMemory()
{
}

/**
 * Offset/Address/Size: 0x888 | 0x801C2F64 | size: 0x8
 */
void glx_GetSharedMemorySize()
{
}

/**
 * Offset/Address/Size: 0x890 | 0x801C2F6C | size: 0x8
 */
void glx_GetSharedMemory()
{
}

/**
 * Offset/Address/Size: 0x898 | 0x801C2F74 | size: 0x3C
//  */
// void 0x8028D520..0x8028D524 | size: 0x4
// {
// }
