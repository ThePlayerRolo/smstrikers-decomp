#ifndef _NLMEMORY_H_
#define _NLMEMORY_H_

#include <stddef.h>

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

#ifdef __cplusplus
extern "C"
{
#endif

// TODO: a bit messy include structure
#ifndef memcpy
    void* memcpy(void* dest, const void* src, size_t num);
#endif
#ifndef memmove
    void* memmove(void* dest, const void* src, size_t num);
#endif
#ifndef memset
    void* memset(void* dest, int ch, size_t count);
#endif
#ifndef memcmp
    int memcmp(const void* ptr1, const void* ptr2, size_t num);
#endif

#ifdef __cplusplus
}
#endif

template <typename T>
void nlDeleteList(T** head)
{
    T* next;
    while (*head != NULL)
    {
        next = (*head)->next;
        delete *head;
        *head = next;
    }
    *head = NULL;
}

#endif // _NLMEMORY_H_
