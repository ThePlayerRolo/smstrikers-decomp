#ifndef _GLPLAT_H_
#define _GLPLAT_H_

#include "NL/nlMath.h"
#include "NL/gl/glView.h"

#include "Dolphin/gx/GXStruct.h"

enum eVideoMode
{
    eVideoMode_0,
};

class gl_ScreenInfo;

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
bool glplatStartup(gl_ScreenInfo*);
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
