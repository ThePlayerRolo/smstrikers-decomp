#ifndef _GLTEXTURE_H_
#define _GLTEXTURE_H_

void glTextureReplace(unsigned long, const void*, unsigned long);
void glTextureAdd(unsigned long, const void*, unsigned long);
void glTextureGetNumBits(int);
void glTextureGetHeight();
void glTextureGetWidth();
void glTextureLoad(unsigned long);
#endif // _GLTEXTURE_H_