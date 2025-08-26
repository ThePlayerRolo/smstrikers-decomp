#ifndef _GLMODEL_H_
#define _GLMODEL_H_

#include "NL/gl/glUserData.h"

struct glModel // size: 0x10
{
    /* 0x00 */ u32 m_count;
    /* 0x04 */ u32 m_unk_0x04;
    /* 0x08 */ u32 m_unk_0x08;
    /* 0x0C */ glModelPacket* m_packets;
};

void* glModelDupArrayNoStreams(const glModel*, unsigned long, bool, bool);
glModel* glModelDupNoStreams(const glModel*, bool, bool);
glModel* glModelDup(const glModel*, bool);
void glModelPacketDup(const glModelPacket*, bool);

#endif // _GLMODEL_H_
