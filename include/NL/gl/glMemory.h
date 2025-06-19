#ifndef _GLMEMORY_H_
#define _GLMEMORY_H_

enum eGLMemory
{
    eGLMemory_0,
};

void glResourceRelease(unsigned long long);
void glResourceMark();
void glFrameAlloc(unsigned long, eGLMemory);
void glResourceAlloc(unsigned long, eGLMemory);
#endif // _GLMEMORY_H_
