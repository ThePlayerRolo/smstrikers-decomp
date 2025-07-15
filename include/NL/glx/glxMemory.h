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
bool glxInitMemory();
void glx_FreeMemory1(const char*);
void glx_FreeMemory0();
u32 glx_GetFreeMemory();
// void 0x8028D514..0x8028D518 | size: 0x4;

class GLXMemoryInfo
{
public:
    GLXMemoryInfo();

    /* 0x00 */ u32 m_unk_0x00;
    /* 0x04 */ u32 m_unk_0x04;
    /* 0x08 */ u32 m_unk_0x08;
    /* 0x0C */ u32 m_unk_0x0C;
    /* 0x10 */ u32 m_unk_0x10;
    /* 0x14 */ u32 m_unk_0x14;
    /* 0x18 */ u32 m_unk_0x18;
};

#endif // _GLXMEMORY_H_
