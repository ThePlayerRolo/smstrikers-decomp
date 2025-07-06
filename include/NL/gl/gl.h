#ifndef _GL_H_
#define _GL_H_

#include "types.h"

// GL View system enums
enum eGLView
{
    eGLView_0 = 0
};

enum eGLTarget
{
    eGLTarget_0 = 0
};

enum eGLFilter
{
    eGLFilter_0 = 0
};

enum eGLViewSort
{
    eGLViewSort_0 = 0
};

// General GL functions
void glEndLoadTextureBundle(void*, unsigned long);
void glBeginLoadTextureBundle(const char*, void (*)(void*, unsigned long, void*), void*);
void glEndLoadModel(void*, unsigned long, unsigned long*);
void glBeginLoadModel(const char*, void (*)(void*, unsigned long, void*), void*);
u32* glGetClearColour();
float glGetOrthographicHeight();
float glGetOrthographicWidth();
void glLoadTextureBundle(const char*);
void glLoadModel(const char*, unsigned long*);
void glFinish();
void glDiscardFrame(int);
void glSendFrame();
void glEndFrame();
void glBeginFrame();
bool glHasQuads();
s32 glGetCurrentFrame();
int glHash(const char*);
bool glStartup();

#endif // _GL_H_
