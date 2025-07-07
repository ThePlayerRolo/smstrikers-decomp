#ifndef _GLMODEL_H_
#define _GLMODEL_H_

// #include "types.h"
#include "NL/gl/glUserData.h"


struct glModel // size: 0x10
{
    u32 m_count;
    u32 m_unk_0x04;
    u32 m_unk_0x08;
    glModelPacket* m_packets;
};

// class glModelPacket;

void* glModelDupArrayNoStreams(const glModel*, unsigned long, bool, bool);
void glModelDupNoStreams(const glModel*, bool, bool);
void glModelDup(const glModel*, bool);
void glModelPacketDup(const glModelPacket*, bool);

#endif // _GLMODEL_H_
