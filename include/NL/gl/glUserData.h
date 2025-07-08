#ifndef _GLUSERDATA_H_
#define _GLUSERDATA_H_

#include "types.h"

enum eGLUserData
{
    eGLUserData_0,
};

struct glModelPacket // size: 0x4A
{
    u32 *m_unk_0x00;
    u32 m_unk_0x04;
    u8 m_unk_0x08;
    u8 m_unk_0x09;
    u8 m_unk_0x0A;
    u8 m_unk_0x0B;
    u32 *m_unk_0x0C;
};


u32 glUserHasType(eGLUserData, const glModelPacket*);
void glUserDetach(eGLUserData, glModelPacket*);
void glUserDup(glModelPacket*, const glModelPacket*, bool);
void glUserAttach(const void*, glModelPacket*, bool);
void* glUserGetData(const void*);
void glUserAlloc(eGLUserData, unsigned long, bool);

#endif // _GLUSERDATA_H_
