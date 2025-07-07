#ifndef _GLUSERDATA_H_
#define _GLUSERDATA_H_

#include "types.h"

enum eGLUserData
{
    eGLUserData_0,
};

// struct glModelPacket // size: 0x48
// {
// public:
//     u32 m_unk_0x00;
//     u8 m_unk_0x02[0x44];
// };


// struct glModelPacket
// {
// public:
//     s32 *m_unk_0x00[4];
// };

struct glModelPacket
{
    // s32 m_unk_0x00[0x12];
    // u8 *m_unk_0x00;
    u32 *m_unk_0x00;
};


u32 glUserHasType(eGLUserData, const glModelPacket*);
void glUserDetach(eGLUserData, glModelPacket*);
void glUserDup(glModelPacket*, const glModelPacket*, bool);
void glUserAttach(const void*, glModelPacket*, bool);
void* glUserGetData(const void*);
void glUserAlloc(eGLUserData, unsigned long, bool);

#endif // _GLUSERDATA_H_
