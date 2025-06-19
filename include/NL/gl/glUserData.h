#ifndef _GLUSERDATA_H_
#define _GLUSERDATA_H_

enum eGLUserData
{
    eGLUserData_0,
};

class glModelPacket;

void glUserHasType(eGLUserData, const glModelPacket*);
void glUserDetach(eGLUserData, glModelPacket*);
void glUserDup(glModelPacket*, const glModelPacket*, bool);
void glUserAttach(const void*, glModelPacket*, bool);
void glUserGetData(const void*);
void glUserAlloc(eGLUserData, unsigned long, bool);

#endif // _GLUSERDATA_H_
