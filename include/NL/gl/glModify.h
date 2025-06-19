#ifndef _GLMODIFY_H_
#define _GLMODIFY_H_

class glModelPacket;

enum eGLModifier
{
    eGLModifier_0,
};

void gl_ModifyAddMapping(eGLModifier, unsigned long);
void gl_ModifyAddMapping(eGLModifier, unsigned long, unsigned long);
void gl_ModifyClearLastMapping();
void gl_ModifyClearMappings();
void gl_Modify(const glModelPacket*);
void gl_ModifyGetNum();
#endif // _GLMODIFY_H_
