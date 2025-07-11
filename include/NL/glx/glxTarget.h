#ifndef _GLXTARGET_H_
#define _GLXTARGET_H_

#include "NL/glx/glxGX.h"

void glPlatGrabFrameBufferToTexture(unsigned long, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void glx_UpdateWarble();
void glx_DOFUpdate(float);
void glx_DOFGrab();
void glx_ShadowTextureGrab();
void glx_ClearZBuffer();
void glx_OffsetGrab();
void glx_ColourGrab();
void glx_ShadowGrab();
void glxPostInitTargets();
void glxInitTargets();
bool glx_GetSharedLock();
void glx_UnlockSharedMemory();
void glx_LockSharedMemory();
u32 glx_GetSharedMemorySize();
u32 glx_GetSharedMemory();

#endif // _GLXTARGET_H_
