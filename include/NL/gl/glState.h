#ifndef _GLSTATE_H_
#define _GLSTATE_H_

#include "Dolphin/gx/GXEnum.h"
#include "NL/gl/glView.h"
#include "NL/glx/glxTexture.h"

enum eGLState
{
    eGLState_0 = 0,
    eGLState_1,
    eGLState_2,
    eGLState_3,
    eGLState_4,
    eGLState_5,
    eGLState_6,
    eGLState_7,
    eGLState_8,
    eGLState_9,
    eGLState_10,
};

class glStateBundle
{
public:
    /* 0x00 */ u8 pad0[0x030];
    /* 0x30 */ u8 m_nFlags;
};

void glSetDefaultState(bool);
void glUnHandleizeTextureState(unsigned long long);
unsigned long long glHandleizeTextureState();
void glUnHandleizeRasterState(unsigned long);
unsigned long glHandleizeRasterState();
void glSetTextureStateDefaults();
void glSetRasterStateDefaults();
void glSetTextureState(unsigned long long&, eGLTextureState, unsigned long);
void glSetTextureState(eGLTextureState, unsigned long);
void glGetTextureState(unsigned long long, eGLTextureState);
void glGetTextureState(eGLTextureState);
void glSetRasterState(unsigned long&, eGLState, unsigned long);
void glSetRasterState(eGLState, unsigned long);
void glGetRasterState(unsigned long, eGLState);
void glGetRasterState(eGLState);
u32 glGetTexture(const char*);
u32 glGetProgram(const char*);
u32 glSetCurrentMatrix(unsigned long);
void glSetCurrentTextureState(unsigned long long state);
void glGetCurrentTextureState();
void glSetCurrentRasterState(unsigned long state = 0);
void glGetCurrentRasterState();
u32 glSetCurrentProgram(unsigned long);
void glSetCurrentTexture(unsigned long, eGLTextureType);
void glStateRestore(const glStateBundle&);
void glStateSave(glStateBundle&);
glStateBundle* gl_GetCurrentStateBundle();
void gl_StateStartup();

#endif // _GLSTATE_H_
