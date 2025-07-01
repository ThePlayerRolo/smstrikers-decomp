#ifndef _NLFILEGC_H_
#define _NLFILEGC_H_

#include "NL/nlFile.h"
#include "Dolphin/dvd.h"
#include "file_io.h"

typedef void (*ReadAsyncCallback)(nlFile*, void*, unsigned int, unsigned long);

class GCFile;
class AsyncEntry;

void nlReadAsyncToVirtualMemory(nlFile*, void*, int, LoadAsyncCallback, unsigned long, unsigned long, void*);
void nlAsyncLoadFileToVirtualMemory(nlFile*, int, void*, LoadAsyncCallback, unsigned long);
void nlCancelPendingAsyncReads(nlFile*, void (*)(nlFile*, void*, unsigned int, unsigned long, LoadAsyncCallback));
void nlAsyncReadsPending(nlFile*);
void nlLoadEntireFileToVirtualMemory(const char*, int*, unsigned int, void*, eAllocType);
void nlReadToVirtualMemory(nlFile*, void*, unsigned int, unsigned int);
u32 nlGetFilePosition(nlFile*);
void nlSeek(nlFile*, unsigned int, unsigned long);
void nlReadAsync(nlFile*, void*, unsigned int, ReadAsyncCallback, unsigned long);
void nlServiceFileSystem();
void nlInitFileSystem();
void GameCubeReadBlocking(GCFile*, void*, unsigned long);
void GameCubeReadAsync(GCFile*, ReadAsyncCallback, void*, unsigned long, unsigned long);
void UpdateReadState(AsyncEntry*);
void nlFlushFileCash();
nlFile *nlOpen(const char*);

// void nlDLRingRemoveStart<AsyncEntry>(AsyncEntry**);
// void nlDLRingGetStart<AsyncEntry>(AsyncEntry*);
// void nlDLRingRemove<AsyncEntry>(AsyncEntry**, AsyncEntry*);
// void nlDLRingAddEnd<AsyncEntry>(AsyncEntry**, AsyncEntry*);
// void nlDLRingAddStart<AsyncEntry>(AsyncEntry**, AsyncEntry*);
// void nlRingIsEnd<AsyncEntry>(AsyncEntry*, AsyncEntry*);

// class @unnamed@nlFileGC_cpp@
// {
// public:
//     @unnamed@nlFileGC_cpp@::AsyncToVirMemBufferCallback(nlFile*, void*, unsigned int, unsigned long);
//     @unnamed@nlFileGC_cpp@::AsyncToVirMemBufferLoad::AsyncToVirMemBufferLoad();
// };


class GCFile : public nlFile
{
public:
    virtual ~GCFile();
    virtual void Read(void*, unsigned int);
};

class TDEVChunkFile: public GCFile
{
public:
    virtual ~TDEVChunkFile();
    virtual u32 FileSize(unsigned int*);
    virtual BOOL GetReadStatus();
    virtual BOOL ReadAsync(void*, unsigned long, unsigned long);
    virtual u32 GetDiscPosition();

    /* 0x0c */ FILE* m_file;
    /* 0x10 */ void* m_buffer;
    /* 0x14 */ u32 m_readOffset;
    /* 0x18 */ u32 m_readLength;
    /* 0x1c */ u32 m_bytesRead;
    /* 0x20 */ u32 m_unk_0x20;
    /* 0x24 */ u32 m_unk_0x24;
    /* 0x28 */ u32 m_unk_0x28;
};

class DolphinFile : public GCFile
{
public:
    virtual ~DolphinFile();
    virtual u32 FileSize(unsigned int*);
    virtual BOOL GetReadStatus();
    virtual BOOL ReadAsync(void*, unsigned long, unsigned long);
    virtual u32 GetDiscPosition();

    /* 0x0c */ DVDFileInfo m_fileInfo;
};

#endif // _NLFILEGC_H_
