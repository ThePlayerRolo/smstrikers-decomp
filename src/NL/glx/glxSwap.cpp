#include "NL/glx/glxSwap.h"
#include "NL/nlDebug.h"

#include "Dolphin/GX.h"
#include "Dolphin/VI.h"

u32 count0 = 0;
int glx_nBuffer = 0;
int _shotno = 0;
int glx_SwapMode = 0;
u8 glx_ResetCaptureFrame = 0;
bool glx_bLoadingIndicator = false;

/**
 * Offset/Address/Size: 0x0 | 0x801BED50 | size: 0x118
 */
void DrawLoadingIndicator()
{
}

/**
 * Offset/Address/Size: 0x118 | 0x801BEE68 | size: 0x2D0
 */
void BlitImage(int, int, float, float, bool)
{
}

/**
 * Offset/Address/Size: 0x3E8 | 0x801BF138 | size: 0xC0
 */
void hitz_Post(bool arg0)
{
    s32 sp8;

    if ((u8)glx_ResetCaptureFrame != 0)
    {
        _shotno = 0;
    }
    // if ((u8) glx_ScreenShot != 0) {
    //     glx_ScreenCapture__Fb(0);
    //     glx_ScreenShot = 0;
    // }
    // if ((u8) glx_MovieOutput != 0) {
    //     glx_ScreenCapture__Fb(1);
    // }
    // sp8 = @626;
    // GXSetCopyClear(&sp8, 0xFFFFFF);
    // gxSetZMode__Fb10_GXCompareb(1, 3, 1);
    // gxSetColourUpdate__Fb(1);
    // gxSetAlphaUpdate__Fb(1);
    // GXCopyDisp(*(&glx_FrameBuffer + (glx_nBuffer * 4)), 1);
    GXSetDrawDone();
    GXFlush();
    count0 = VIGetRetraceCount();
}

/**
 * Offset/Address/Size: 0x4A8 | 0x801BF1F8 | size: 0xD4
 */
void hitz_Pre(bool)
{
}

/**
 * Offset/Address/Size: 0x57C | 0x801BF2CC | size: 0x10
 */
void hitz_SwapBuffers()
{
}

/**
 * Offset/Address/Size: 0x58C | 0x801BF2DC | size: 0x54
 */
void hitz_AdvanceFrame()
{
}

/**
 * Offset/Address/Size: 0x5E0 | 0x801BF330 | size: 0xA0
 */
void simple_Post(bool arg0)
{
    s32 temp_r0;

    // gxSetZMode__Fb10_GXCompareb(1, 3, 1);
    // gxSetColourUpdate__Fb(1);
    // gxSetAlphaUpdate__Fb(1);
    // GXCopyDisp(*(&glx_FrameBuffer + (glx_nBuffer * 4)), 1);
    GXDrawDone();
    // VISetNextFrameBuffer(*(&glx_FrameBuffer + (glx_nBuffer * 4)));
    // if ((s32) nFirstFrame > 0) {
    //     temp_r0 = nFirstFrame - 1;
    //     nFirstFrame = temp_r0;
    //     if (temp_r0 == 0) {
    //         VISetBlack(0);
    //     }
    // }
    VIFlush();
    VIWaitForRetrace();
    glx_nBuffer ^= 1;
}

/**
 * Offset/Address/Size: 0x680 | 0x801BF3D0 | size: 0x4
 */
void simple_Pre(bool)
{
    // EMPTY
}

/**
 * Offset/Address/Size: 0x684 | 0x801BF3D4 | size: 0x58
 */
void glxSwapPost(bool)
{
    if (glx_bLoadingIndicator == false)
    {
        switch ((s32)glx_SwapMode)
        { /* irregular */
        case 0:
            simple_Post(false);
            return;
        case 1:
            hitz_Post(false);
            return;
        default:
            nlBreak();
            break;
        }
    }
}

/**
 * Offset/Address/Size: 0x6DC | 0x801BF42C | size: 0x58
 */
void glxSwapPre(bool)
{
}

/**
 * Offset/Address/Size: 0x734 | 0x801BF484 | size: 0x260
 */
void glxInitSwap(void*, void*)
{
}

/**
 * Offset/Address/Size: 0x994 | 0x801BF6E4 | size: 0x28
 */
void glxSwapWaitDrawDone()
{
}

/**
 * Offset/Address/Size: 0x9BC | 0x801BF70C | size: 0x50
 */
void vi_post_cb(unsigned long)
{
}

/**
 * Offset/Address/Size: 0xA0C | 0x801BF75C | size: 0xC
 */
void vi_pre_cb(unsigned long)
{
}

/**
 * Offset/Address/Size: 0xA18 | 0x801BF768 | size: 0x88
 */
void loading_indicator()
{
}

/**
 * Offset/Address/Size: 0xAA0 | 0x801BF7F0 | size: 0x54
 */
void glxLoadRestoreState()
{
}

/**
 * Offset/Address/Size: 0xAF4 | 0x801BF844 | size: 0x40
 */
void glxLoadSaveState()
{
}

/**
 * Offset/Address/Size: 0xB34 | 0x801BF884 | size: 0x4C
 */
void glxSwapLoading(bool, bool)
{
}

/**
 * Offset/Address/Size: 0xB80 | 0x801BF8D0 | size: 0x14
 */
void glxGetBackBuffer()
{
}

/**
 * Offset/Address/Size: 0xB94 | 0x801BF8E4 | size: 0x18
 */
void glxGetDisplayedBuffer()
{
}

/**
 * Offset/Address/Size: 0xBAC | 0x801BF8FC | size: 0x1B0
 */
void glx_ScreenCapture(bool)
{
}

/**
 * Offset/Address/Size: 0xD5C | 0x801BFAAC | size: 0x48
 */
void glxSwapSetBlack(bool)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801BFAF4 | size: 0xA8
 */
// void Config::Get<BasicString<char, Detail::TempStringAllocator>>(const char*, BasicString<char, Detail::TempStringAllocator>)
// {
// }

/**
 * Offset/Address/Size: 0xA8 | 0x801BFB9C | size: 0x84
 */
// void Config::TagValuePair::Get<BasicString<char, Detail::TempStringAllocator>>() const
// {
// }
