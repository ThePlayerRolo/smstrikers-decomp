#ifndef _GLAPPATTACH_H_
#define _GLAPPATTACH_H_

#include "NL/gl/glView.h"

class glModelPacket;

void glplatAttachPacket(eGLView, unsigned long, const glModelPacket*);
void glplatModifyPacket(eGLView, const glModelPacket*);
void glAppStartup();
void glAppGetOnePassFresnelUserData();
void glAppGetNoFogUserData();
void glAppGetCoPlanarUserData();
void gld_ViewName(int);
// void 0x8028D344..0x8028D348 | size: 0x4;
#endif // _GLAPPATTACH_H_
