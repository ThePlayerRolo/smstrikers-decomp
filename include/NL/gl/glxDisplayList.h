#ifndef _GLXDISPLAYLIST_H_
#define _GLXDISPLAYLIST_H_

class glModelPacket;

void dlMakeDisplayList(const glModelPacket*, bool);
void dlGetSize(unsigned long);
void dlGetDisplayList(unsigned long);
void dlIsDisplayList(unsigned long);
void dlGetStruct(unsigned long);

#endif // _GLXDISPLAYLIST_H_
