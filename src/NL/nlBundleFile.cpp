#include "NL/nlBundleFile.h"

/**
 * Offset/Address/Size: 0x9E4 | 0x801E8FB0 | size: 0x50
 */
void cbFileReadAsyncCallback(nlFile*, void*, unsigned int, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x801E85CC | size: 0xD4
 */
void BundleFile::ReadFileAsync(unsigned long, void*, unsigned long, void (*)(void*, unsigned long, unsigned long), unsigned long)
{
}

/**
 * Offset/Address/Size: 0xD4 | 0x801E86A0 | size: 0x138
 */
void BundleFile::ReadFileAsync(const char*, void*, unsigned long, void (*)(void*, unsigned long, unsigned long), unsigned long)
{
}

/**
 * Offset/Address/Size: 0x20C | 0x801E87D8 | size: 0x118
 */
void BundleFile::LoadFile(const char*, void*)
{
}

/**
 * Offset/Address/Size: 0x324 | 0x801E88F0 | size: 0x74
 */
void BundleFile::ReadFileByIndex(unsigned long, void*, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x398 | 0x801E8964 | size: 0xC4
 */
void BundleFile::ReadFile(unsigned long, void*, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x45C | 0x801E8A28 | size: 0x118
 */
void BundleFile::ReadFile(const char*, void*, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x574 | 0x801E8B40 | size: 0x50
 */
void BundleFile::GetFileInfoByIndex(unsigned long, BundleFileDirectoryEntry*)
{
}

/**
 * Offset/Address/Size: 0x5C4 | 0x801E8B90 | size: 0xE8
 */
void BundleFile::GetFileInfo(unsigned long, BundleFileDirectoryEntry*, bool)
{
}

/**
 * Offset/Address/Size: 0x6AC | 0x801E8C78 | size: 0x13C
 */
void BundleFile::GetFileInfo(const char*, BundleFileDirectoryEntry*, bool)
{
}

/**
 * Offset/Address/Size: 0x7E8 | 0x801E8DB4 | size: 0x58
 */
void BundleFile::Close()
{
}

/**
 * Offset/Address/Size: 0x840 | 0x801E8E0C | size: 0xA8
 */
void BundleFile::Open(const char*)
{
}

/**
 * Offset/Address/Size: 0x8E8 | 0x801E8EB4 | size: 0x8C
 */
BundleFile::~BundleFile()
{
}

/**
 * Offset/Address/Size: 0x974 | 0x801E8F40 | size: 0x70
 */
BundleFile::BundleFile()
{
}
