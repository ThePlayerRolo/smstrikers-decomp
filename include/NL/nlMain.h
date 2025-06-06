#ifndef _NLMAIN_H_
#define _NLMAIN_H_

void nlChecksum32(const void*, unsigned long);
void nlInit();

class RunningChecksum
{
public:
    void ChecksumData(const void*, unsigned long);
    void ChecksumInt(unsigned long);
    
    RunningChecksum();
};

#endif // _NLMAIN_H_
