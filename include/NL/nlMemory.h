#ifndef _NLMEMORY_H_
#define _NLMEMORY_H_

void nlFree(void*);
void nlMalloc(unsigned long, unsigned int, bool);
void* nlMalloc(unsigned long);
void* operator new(unsigned long);
void operator delete[](void*);
void operator delete(void*);
void nlVirtualTotalFree();
void nlVirtualLargestBlock();
void nlVirtualFree(void*);
void nlVirtualAlloc(unsigned long, bool);
void nlInitMemory();

#endif // _NLMEMORY_H_
