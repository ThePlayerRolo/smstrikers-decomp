#ifndef _GLXMEMORY_H_
#define _GLXMEMORY_H_

#include "NL/nlMath.h"

enum eGLMemory
{
    eGLMemory_0,
};

void glplatSetMatrix(unsigned long, const nlMatrix4&);
void glplatGetMatrix(unsigned long, nlMatrix4&);
void glplatFrameAllocNextFrame();
u32 glplatFrameAlloc(unsigned long, eGLMemory);
void glplatResourceRelease(unsigned long long);
void glplatResourceMark();
unsigned long glplatResourceAlloc(unsigned long, eGLMemory);
void glxInitMemory();
void glx_FreeMemory1(const char*);
void glx_FreeMemory0();
void glx_GetFreeMemory();
// void 0x8028D514..0x8028D518 | size: 0x4;

class GLXMemoryInfo
{
public:
    GLXMemoryInfo();
};

#endif // _GLXMEMORY_H_
