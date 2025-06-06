#ifndef _NLFILE_H_
#define _NLFILE_H_

typedef void (*LoadAsyncCallback)(void*, unsigned long, void*);

enum eAllocType {
    eAllocType_0 = 0,
};

class nlFile
{
public:
    ~nlFile();
    nlFile();
};

void nlLoadEntireFileAsync(const char*, LoadAsyncCallback callback, void* userData, unsigned int size, eAllocType type);
void nlLoadEntireFileAsyncCallback(nlFile*, void*, unsigned int, unsigned long);
void nlLoadEntireFile(const char*, unsigned long*, unsigned int, eAllocType);
void nlClose(nlFile*);
void nlRead(nlFile*, void*, unsigned int);
void nlFileSize(nlFile*, unsigned int*);

#endif // _NLFILE_H_
