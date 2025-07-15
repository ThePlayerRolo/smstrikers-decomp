#ifndef _GLXDISPLAYLIST_H_
#define _GLXDISPLAYLIST_H_

#include "NL/gl/glView.h"

// class glModelPacket;

void dlMakeDisplayList(const glModelPacket*, bool);
u32 dlGetSize(unsigned long);
void* dlGetDisplayList(unsigned long);
bool dlIsDisplayList(unsigned long);
unsigned long dlGetStruct(unsigned long);

#endif // _GLXDISPLAYLIST_H_
