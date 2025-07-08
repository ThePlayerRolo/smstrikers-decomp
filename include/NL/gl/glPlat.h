#ifndef _GLPLAT_H_
#define _GLPLAT_H_

#include "NL/nlMath.h"
#include "NL/gl/glView.h"

#include "Dolphin/gx/GXStruct.h"

enum eVideoMode
{
    eVideoMode_0,
};

struct gl_ScreenInfo // size: 0x28
{
    /* 0x00 */ u32 m_screenWidth;
    /* 0x04 */ u32 m_screenHeight;
    /* 0x08 */ u32 m_unk_0x08;
    /* 0x0C */ u32 m_unk_0x0C;
    /* 0x10 */ u32 m_unk_0x10;
    /* 0x14 */ u32 m_unk_0x14;
    /* 0x18 */ u32 m_unk_0x18;
    /* 0x1C */ u32 m_unk_0x1C;
    /* 0x20 */ u32 m_unk_0x20;
    /* 0x24 */ u32 m_unk_0x24;
};

void glplatViewProjectPoint(eGLView, const nlVector3&, nlVector3&);
void glplatEndFrame();
void glplatBeginFrame();
void glplatFinish();
void glplatAbortFrame();
void glplatSendFrame();
void glx_SendViews();
void glx_Fog(bool);
void glx_GetFog();
bool glplatPostStartup();
bool glplatStartup(gl_ScreenInfo* screenInfo);
void glx_SetPal50Mode();
void glx_SetRGB60Mode();
void glx_SetInterlacedMode();
void glx_SetProgressiveMode();
void glx_GetResetCode();
void glx_SwitchVideoMode(_GXRenderModeObj*, eVideoMode);
void glplatPreStartup();
void virt_cb(unsigned long, unsigned long, unsigned long, unsigned long, int);
void glx_ClearXFB(void*);
void glx_GetTargetFPS();
void glx_GetScaledXFBWidth();
void glx_SetFog(int);
#endif // _GLPLAT_H_
