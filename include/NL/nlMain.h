#ifndef _NLMAIN_H_
#define _NLMAIN_H_

#include "types.h"

void nlChecksum32(const void*, unsigned long);
void nlInit();

class RunningChecksum
{
public:
    void ChecksumData(const void*, unsigned long);
    void ChecksumInt(unsigned long);    
    RunningChecksum();

    /* 0x00 */ u32 m_unk_0x00;
};

#endif // _NLMAIN_H_
