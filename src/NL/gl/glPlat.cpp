#include "NL/gl/glPlat.h"
#include "NL/glx/glxSwap.h"
#include "NL/glx/glxMemory.h"
#include "NL/glx/glxTarget.h"
#include "Dolphin/vi/vifuncs.h"
#include "Dolphin/gx/GXFrameBuffer.h"
#include "Dolphin/os/OSCache.h"

GXRenderModeObj glx_rmode;

GXRenderModeObj glPal480IntDf = { 
    VI_TVMODE_PAL_INT,
    640,
    480,
    542,
    40,
    16,
    640,
    542,
    VI_XFBMODE_SF,
    1,
    0,
    { 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
    { 6, 6, 8, 8, 10, 12, 10 } 
};

bool glx_bFog = false;
bool glx_bProgressiveMode = false;
u32 glx_TargetFPS = 60;
s32 glx_FBSize;
u32 glx_NumVirtMisses = 0;
u32 glx_VirtLatency = 0;
s32 glx_VIWidth = 0x00000294;
s32 prev_VIWidth = 0x00000294;

/**
 * Offset/Address/Size: 0x0 | 0x801B45F4 | size: 0xB0
 */
void glplatViewProjectPoint(eGLView view, const nlVector3& arg1, nlVector3& arg2)
{
    nlVector3 v_out;
    nlMatrix4* temp_r31 = glViewGetViewMatrix(view);
    nlMatrix4* temp_r30 = glViewGetProjectionMatrix(view);
    nlMultPosVectorMatrix(v_out, arg1, *temp_r31);
    nlMultPosVectorMatrix(arg2, v_out, *temp_r30);
    float temp_f1 = 1.f / -v_out.z;
    arg2.x = arg2.x * temp_f1;
    arg2.y = -arg2.y * temp_f1;
    arg2.z = arg2.z * temp_f1;    
}

/**
 * Offset/Address/Size: 0xB0 | 0x801B46A4 | size: 0x4
 */
void glplatEndFrame()
{
    // EMPTY
}

/**
 * Offset/Address/Size: 0xB4 | 0x801B46A8 | size: 0x58
 */
void glplatBeginFrame()
{
    // u32 temp_r3;
    if (glx_VIWidth != prev_VIWidth) 
    {
        s32 temp_r3 = 0x2D0 - glx_VIWidth;
        prev_VIWidth = glx_VIWidth;
        glx_rmode.viWidth = (s16) glx_VIWidth;
        glx_rmode.viXOrigin = (s16) ((s32) ((temp_r3 >> 0x1FU) + temp_r3) >> 1);
        VIConfigure(&glx_rmode);
        VIFlush();
    }
}

/**
 * Offset/Address/Size: 0x10C | 0x801B4700 | size: 0x20
 */
void glplatFinish()
{
    glxSwapWaitDrawDone();
}

/**
 * Offset/Address/Size: 0x12C | 0x801B4720 | size: 0x34
 */
void glplatAbortFrame()
{
    glplatFrameAllocNextFrame();
    glx_NumVirtMisses = 0;
    glx_VirtLatency = 0;
    glxSwapWaitDrawDone();
    VIWaitForRetrace();    
}

/**
 * Offset/Address/Size: 0x160 | 0x801B4754 | size: 0x2FC
 */
void glplatSendFrame()
{
}

/**
 * Offset/Address/Size: 0x45C | 0x801B4A50 | size: 0x470
 */
void glx_SendViews()
{
}

/**
 * Offset/Address/Size: 0x8CC | 0x801B4EC0 | size: 0x110
 */
void glx_Fog(bool)
{
}

/**
 * Offset/Address/Size: 0x9DC | 0x801B4FD0 | size: 0x8
 */
bool glx_GetFog()
{
    return glx_bFog;
}

/**
 * Offset/Address/Size: 0x9E4 | 0x801B4FD8 | size: 0x24
 */
bool glplatPostStartup()
{
    glxPostInitTargets();
    return true;
}

/**
 * Offset/Address/Size: 0xA08 | 0x801B4FFC | size: 0x524
 */
bool glplatStartup(gl_ScreenInfo*)
{
    return false;
}

/**
 * Offset/Address/Size: 0xF2C | 0x801B5520 | size: 0x2C
 */
void glx_SetPal50Mode()
{
    glx_SwitchVideoMode(&glPal480IntDf, eVideoMode_1);
}

/**
 * Offset/Address/Size: 0xF58 | 0x801B554C | size: 0x2C
 */
void glx_SetRGB60Mode()
{
    glx_SwitchVideoMode(&GXEurgb60Hz480IntDf, eVideoMode_3);
}

/**
 * Offset/Address/Size: 0xF84 | 0x801B5578 | size: 0x34
 */
void glx_SetInterlacedMode()
{
    glx_SwitchVideoMode(&GXNtsc480IntDf, eVideoMode_0);
    glx_bProgressiveMode = 0;
}

/**
 * Offset/Address/Size: 0xFB8 | 0x801B55AC | size: 0x34
 */
void glx_SetProgressiveMode()
{
    glx_SwitchVideoMode(&GXNtsc480Prog, eVideoMode_0);
    glx_bProgressiveMode = 1;
}

/**
 * Offset/Address/Size: 0xFEC | 0x801B55E0 | size: 0x1C
 */
u32 glx_GetResetCode()
{
    // return 0x17 & ((s32) (-(s32) glx_bProgressiveMode | glx_bProgressiveMode) >> 0x1F);
    return glx_bProgressiveMode ? 0x17 : 0;
}

/**
 * Offset/Address/Size: 0x1008 | 0x801B55FC | size: 0x18C
 */
void glx_SwitchVideoMode(_GXRenderModeObj*, eVideoMode)
{
}

/**
 * Offset/Address/Size: 0x1194 | 0x801B5788 | size: 0x8
 */
bool glplatPreStartup()
{
    return true;
}

/**
 * Offset/Address/Size: 0x119C | 0x801B5790 | size: 0x1C
 */
void virt_cb(unsigned long arg0, unsigned long arg1, unsigned long arg2, unsigned long arg3, int arg4)
{
    glx_NumVirtMisses += 1;
    glx_VirtLatency += arg3;
}

/**
 * Offset/Address/Size: 0x11B8 | 0x801B57AC | size: 0x4C
 */
void glx_ClearXFB(void* cache)
{
    u8 *var_r5 = (u8*) cache;
    s32 var_r6 = 0;

    while (var_r6 < (s32) glx_FBSize) \
    {
        *(u32*)var_r5 = 0x10801080;
        var_r6 += 4;
        var_r5 += 4;
    }
    DCFlushRange(cache, glx_FBSize);    
}

/**
 * Offset/Address/Size: 0x1204 | 0x801B57F8 | size: 0x8
 */
u32 glx_GetTargetFPS()
{
    return glx_TargetFPS;
}

/**
 * Offset/Address/Size: 0x120C | 0x801B5800 | size: 0x8
 */
u32 glx_GetScaledXFBWidth()
{
    return glx_VIWidth;
}

/**
 * Offset/Address/Size: 0x1214 | 0x801B5808 | size: 0x110
 */
void glx_SetFog(int)
{
}
