#ifndef _NLBUNDLEFILE_H_
#define _NLBUNDLEFILE_H_

#include "NL/nlFileGC.h"

typedef struct {
    /* 0x00 */ u32 m_unk_0x00;  
    /* 0x04 */ u32 m_count;
    /* 0x08 */ u32 m_unk_0x08;  
    /* 0x0C */ u32 m_unk_0x0C;
} BundleFileDirectoryHeader;


typedef struct {
    /* 0x00 */ u32 m_hash;  
    /* 0x04 */ u32 m_unk_0x04;
    /* 0x08 */ u32 m_unk_0x08;  
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
    bool GetFileInfo(unsigned long, BundleFileDirectoryEntry*, bool);
    bool GetFileInfo(const char*, BundleFileDirectoryEntry*, bool);
    void Close();
    bool Open(const char*);

    ~BundleFile();
    BundleFile();

private:
    /* 0x00 */ nlFile* m_file;  
    /* 0x04 */ u32 m_unk_0x04;  
    /* 0x08 */ u32 m_unk_0x08;  
    /* 0x0C */ u32 m_unk_0x0C;  
    /* 0x10 */ u32 m_unk_0x10;  
    /* 0x14 */ BundleFileDirectoryHeader* m_bundleHeader;
    /* 0x18 */ BundleFileDirectoryEntry* m_bundleEntries;  // most probably another struct
};

#endif // _NLBUNDLEFILE_H_
