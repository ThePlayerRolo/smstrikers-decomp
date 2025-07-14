#ifndef _GLSTATE_H_
#define _GLSTATE_H_

#include "Dolphin/gx/GXEnum.h"
#include "NL/gl/glView.h"
#include "NL/glx/glxTexture.h"

enum eGLState
{
    eGLState_0,
    eGLState_1,
    eGLState_2,
    eGLState_3,
};

class glStateBundle;

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
void* glGetTexture(const char*);
void glGetProgram(const char*);
void glSetCurrentMatrix(unsigned long);
void glSetCurrentTextureState(unsigned long long state);
void glGetCurrentTextureState();
void glSetCurrentRasterState(unsigned long state = 0);
void glGetCurrentRasterState();
void glSetCurrentProgram(unsigned long);
void glSetCurrentTexture(unsigned long, eGLTextureType);
void glStateRestore(const glStateBundle&);
void glStateSave(glStateBundle&);
void gl_GetCurrentStateBundle();
void gl_StateStartup();

#endif // _GLSTATE_H_
