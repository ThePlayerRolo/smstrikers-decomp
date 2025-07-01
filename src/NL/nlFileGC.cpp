#include "NL/nlFileGC.h"

/**
 * Offset/Address/Size: 0x0 | 0x801CED54 | size: 0xEC
 */
void nlReadAsyncToVirtualMemory(nlFile*, void*, int, LoadAsyncCallback, unsigned long, unsigned long, void*)
{
}

/**
 * Offset/Address/Size: 0xEC | 0x801CEE40 | size: 0x38
 */
void nlAsyncLoadFileToVirtualMemory(nlFile*, int, void*, LoadAsyncCallback, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x124 | 0x801CEE78 | size: 0xAC
 */
void AsyncToVirMemBufferCallback(nlFile*, void*, unsigned int, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x1D0 | 0x801CEF24 | size: 0xF4
 */
// nlCancelPendingAsyncReads(nlFile*, void (*)(nlFile*, void*, unsigned int, unsigned long, LoadAsyncCallback))
void nlCancelPendingAsyncReads(nlFile*)
{
}

/**
 * Offset/Address/Size: 0x2C4 | 0x801CF018 | size: 0x34
 */
void nlAsyncReadsPending(nlFile*)
{
}

/**
 * Offset/Address/Size: 0x2F8 | 0x801CF04C | size: 0x2D0
 */
void nlLoadEntireFileToVirtualMemory(const char*, int*, unsigned int, void*, eAllocType)
{
}

/**
 * Offset/Address/Size: 0x5C8 | 0x801CF31C | size: 0x9C
 */
void nlReadToVirtualMemory(nlFile*, void*, unsigned int, unsigned int)
{
}

/**
 * Offset/Address/Size: 0x664 | 0x801CF3B8 | size: 0x8
 */
void nlGetFilePosition(nlFile*)
{
}

/**
 * Offset/Address/Size: 0x66C | 0x801CF3C0 | size: 0x8C
 */
void nlSeek(nlFile*, unsigned int, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x6F8 | 0x801CF44C | size: 0x34
 */
void nlReadAsync(nlFile*, void*, unsigned int, ReadAsyncCallback, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x72C | 0x801CF480 | size: 0x27C
 */
void nlServiceFileSystem()
{
}

/**
 * Offset/Address/Size: 0x9A8 | 0x801CF6FC | size: 0x35C
 */
void nlInitFileSystem()
{
}

/**
 * Offset/Address/Size: 0xD04 | 0x801CFA58 | size: 0x2E0
 */
void GameCubeReadBlocking(GCFile*, void*, unsigned long)
{
}

/**
 * Offset/Address/Size: 0xFE4 | 0x801CFD38 | size: 0x324
 */
void GameCubeReadAsync(GCFile*, ReadAsyncCallback, void*, unsigned long, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x1308 | 0x801D005C | size: 0x6E0
 */
void UpdateReadState(AsyncEntry*)
{
}

/**
 * Offset/Address/Size: 0x19E8 | 0x801D073C | size: 0x4
 */
void nlFlushFileCash()
{
}

/**
 * Offset/Address/Size: 0x19EC | 0x801D0740 | size: 0x18C
 */
nlFile *nlOpen(const char*)
{
}

/**
 * Offset/Address/Size: 0x1B78 | 0x801D08CC | size: 0xB0
 */
void TDEVChunkFile::GetReadStatus()
{
}

/**
 * Offset/Address/Size: 0x1C28 | 0x801D097C | size: 0x40
 */
void TDEVChunkFile::ReadAsync(void*, unsigned long, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x1C68 | 0x801D09BC | size: 0x20
 */
void GCFile::Read(void*, unsigned int)
{
}

/**
 * Offset/Address/Size: 0x1E74 | 0x801D0BC8 | size: 0xC
 */
// @unnamed@nlFileGC_cpp@::AsyncToVirMemBufferLoad::AsyncToVirMemBufferLoad()
// {
// }

/**
 * Offset/Address/Size: 0x0 | 0x801D0BD4 | size: 0x90
 */
TDEVChunkFile::~TDEVChunkFile()
{
}

/**
 * Offset/Address/Size: 0x90 | 0x801D0C64 | size: 0x8C
 */
void FileSize(unsigned int*)
{
}

/**
 * Offset/Address/Size: 0x11C | 0x801D0CF0 | size: 0x8
 */
void GetDiscPosition()
{
}

/**
 * Offset/Address/Size: 0x124 | 0x801D0CF8 | size: 0x60
 */
GCFile::~GCFile()
{
}

/**
 * Offset/Address/Size: 0x184 | 0x801D0D58 | size: 0x88
 */
DolphinFile::~DolphinFile()
{
}

/**
 * Offset/Address/Size: 0x20C | 0x801D0DE0 | size: 0x14
 */
void DolphinFile::FileSize(unsigned int*)
{
}

/**
 * Offset/Address/Size: 0x220 | 0x801D0DF4 | size: 0x24
 */
void DolphinFile::GetReadStatus()
{
}

/**
 * Offset/Address/Size: 0x244 | 0x801D0E18 | size: 0x2C
 */
void DolphinFile::ReadAsync(void*, unsigned long, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x270 | 0x801D0E44 | size: 0x8
 */
void DolphinFile::GetDiscPosition()
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801D0E4C | size: 0x38
 */
// nlDLRingRemoveStart<AsyncEntry>(AsyncEntry**)
// {
// }

/**
 * Offset/Address/Size: 0x38 | 0x801D0E84 | size: 0x18
 */
// nlDLRingGetStart<AsyncEntry>(AsyncEntry*)
// {
// }

/**
 * Offset/Address/Size: 0x50 | 0x801D0E9C | size: 0x44
 */
// nlDLRingRemove<AsyncEntry>(AsyncEntry**, AsyncEntry*)
// {
// }

/**
 * Offset/Address/Size: 0x94 | 0x801D0EE0 | size: 0x3C
 */
// nlDLRingAddEnd<AsyncEntry>(AsyncEntry**, AsyncEntry*)
// {
// }

/**
 * Offset/Address/Size: 0xD0 | 0x801D0F1C | size: 0x38
 */
// nlDLRingAddStart<AsyncEntry>(AsyncEntry**, AsyncEntry*)
// {
// }

/**
 * Offset/Address/Size: 0x0 | 0x801D0F54 | size: 0x20
 */
// nlRingIsEnd<AsyncEntry>(AsyncEntry*, AsyncEntry*)
// {
// }

/**
 * Offset/Address/Size: 0x20 | 0x801D0F74 | size: 0xCC
 */
// 0x8028D538..0x8028D53C | size: 0x4
// {
// }
