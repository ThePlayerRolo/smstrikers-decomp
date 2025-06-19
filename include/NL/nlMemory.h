#ifndef _NLMEMORY_H_
#define _NLMEMORY_H_

inline void* operator new(unsigned long, void* p)
{
    return p;
}

void nlFree(void*);
void* nlMalloc(unsigned long, unsigned int, bool);
void* nlMalloc(unsigned long);
void* operator new(unsigned long);
void operator delete[](void*);
void operator delete(void*);
unsigned int nlVirtualTotalFree();
unsigned int nlVirtualLargestBlock();
void nlVirtualFree(void*);
void* nlVirtualAlloc(unsigned long, bool);
void nlInitMemory();

#endif // _NLMEMORY_H_
