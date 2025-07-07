#include "NL/gl/glTexture.h"
#include "NL/glx/glxTexture.h"

/**
 * Offset/Address/Size: 0x0 | 0x801DF160 | size: 0x20
 */
void glTextureReplace(unsigned long arg0, const void* arg1, unsigned long arg2)
{
    glplatTextureReplace(arg0, arg1, arg2);
}

/**
 * Offset/Address/Size: 0x20 | 0x801DF180 | size: 0x20
 */
void glTextureAdd(unsigned long arg0, const void* arg1, unsigned long arg2)
{
    glplatTextureAdd(arg0, arg1, arg2);
}

/**
 * Offset/Address/Size: 0x40 | 0x801DF1A0 | size: 0x20
 */
void glTextureGetNumBits(int arg0)
{
    glplatTextureGetNumBits(arg0);
}

/**
 * Offset/Address/Size: 0x60 | 0x801DF1C0 | size: 0x20
 */
u32 glTextureGetHeight()
{
    return glplatTextureGetHeight();
}

/**
 * Offset/Address/Size: 0x80 | 0x801DF1E0 | size: 0x20
 */
u32 glTextureGetWidth()
{   
    return glplatTextureGetWidth();
}

/**
 * Offset/Address/Size: 0xA0 | 0x801DF200 | size: 0x20
 */
void glTextureLoad(unsigned long arg0)
{
    glplatTextureLoad(arg0);
}
