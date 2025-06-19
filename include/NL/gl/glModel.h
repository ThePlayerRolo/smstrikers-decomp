#ifndef _GLMODEL_H_
#define _GLMODEL_H_

class glModel;
class glModelPacket;

void glModelDupArrayNoStreams(const glModel*, unsigned long, bool, bool);
void glModelDupNoStreams(const glModel*, bool, bool);
void glModelDup(const glModel*, bool);
void glModelPacketDup(const glModelPacket*, bool);
#endif // _GLMODEL_H_
