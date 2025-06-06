#ifndef _NLBUNDLEFILE_H_
#define _NLBUNDLEFILE_H_

#include "NL/nlFile.h"

typedef struct {
    // todo..
} BundleFileDirectoryEntry, *BundleFileDirectoryEntryPtr;

void cbFileReadAsyncCallback(nlFile*, void*, unsigned int, unsigned long);

class BundleFile
{
public:
    void ReadFileAsync(unsigned long, void*, unsigned long, void (*)(void*, unsigned long, unsigned long), unsigned long);
    void ReadFileAsync(const char*, void*, unsigned long, void (*)(void*, unsigned long, unsigned long), unsigned long);
    void LoadFile(const char*, void*);
    void ReadFileByIndex(unsigned long, void*, unsigned long);
    void ReadFile(unsigned long, void*, unsigned long);
    void ReadFile(const char*, void*, unsigned long);
    void GetFileInfoByIndex(unsigned long, BundleFileDirectoryEntry*);
    void GetFileInfo(unsigned long, BundleFileDirectoryEntry*, bool);
    void GetFileInfo(const char*, BundleFileDirectoryEntry*, bool);
    void Close();
    void Open(const char*);

    ~BundleFile();
    BundleFile();
};

#endif // _NLBUNDLEFILE_H_
