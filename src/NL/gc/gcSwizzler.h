#ifndef _GCSWIZZLER_H_
#define _GCSWIZZLER_H_

#include "types.h"
#include "NL/glx/glxTexture.h"

void GCSwizzle(void*, const void*, unsigned short, unsigned short, eGXTextureFormat, bool);
void GCTextureSize(eGXTextureFormat, int, int, int, unsigned long);

#endif // _GCSWIZZLER_H_
