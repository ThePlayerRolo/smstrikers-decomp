#ifndef _GLUSERDATA_H_
#define _GLUSERDATA_H_

#include "types.h"

enum eGLUserData
{
    eGLUserData_0,
};

struct glModelPacket // size: 0x4A
{
    /* 0x00 */ u32 *m_unk_0x00;
    /* 0x04 */ u32 m_unk_0x04;
    /* 0x08 */ u8 m_unk_0x08;
    /* 0x09 */ u8 m_unk_0x09;
    /* 0x0A */ u8 m_unk_0x0A;
    /* 0x0B */ u8 m_unk_0x0B;
    /* 0x0C */ u32 *m_unk_0x0C;
    /* 0x10 */ u8 m_padding_0x10[0x0C];
    /* 0x1C */ u32 m_unk_0x1C;
    /* 0x20 */ u32 m_unk_0x20;
    /* 0x24 */ u32 m_unk_0x24;
    /* 0x28 */ u32 m_unk_0x28;
    /* 0x2C */ u32 m_unk_0x2C;
    /* 0x30 */ u32 m_unk_0x30;
    /* 0x34 */ u32 m_unk_0x34;
    /* 0x38 */ u32 m_unk_0x38;
    /* 0x3C */ u32 m_unk_0x3C;
    /* 0x40 */ u8 m_unk_0x40;
    /* 0x41 */ u8 m_unk_0x41; // used? or alignment?
    /* 0x42 */ u8 m_unk_0x42; // used? or alignment?
    /* 0x43 */ u8 m_unk_0x43; // used? or alignment?
};


u32 glUserHasType(eGLUserData, const glModelPacket*);
void glUserDetach(eGLUserData, glModelPacket*);
void glUserDup(glModelPacket*, const glModelPacket*, bool);
void glUserAttach(const void*, glModelPacket*, bool);
void* glUserGetData(const void*);
void glUserAlloc(eGLUserData, unsigned long, bool);

#endif // _GLUSERDATA_H_
