#include "NL/gl/glMemory.h"

/**
 * Offset/Address/Size: 0x0 | 0x801D8FBC | size: 0x20
 */
void glResourceRelease(unsigned long long arg0)
{
    glplatResourceRelease(arg0);
}

/**
 * Offset/Address/Size: 0x20 | 0x801D8FDC | size: 0x20
 */
void glResourceMark()
{
    glplatResourceMark();
}

/**
 * Offset/Address/Size: 0x40 | 0x801D8FFC | size: 0x20
 */
void* glFrameAlloc(unsigned long size, eGLMemory arg1)
{
    return (void*)glplatFrameAlloc(size, arg1);
}

/**
 * Offset/Address/Size: 0x60 | 0x801D901C | size: 0x20
 */
void* glResourceAlloc(unsigned long size, eGLMemory arg1)
{
    return (void*)glplatResourceAlloc(size, arg1);
}
