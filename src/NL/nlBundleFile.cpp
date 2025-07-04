#include "NL/nlBundleFile.h"
#include "NL/nlMemory.h"
#include <string.h>

extern void nlPrintf(const char*, ...);

/**
 * Offset/Address/Size: 0x9E4 | 0x801E8FB0 | size: 0x50
 */
void cbFileReadAsyncCallback(nlFile*, void*, unsigned int, unsigned long)
{
    // arg3->unkC(arg1, arg2, arg3->unk10);
    // arg3->unkC = NULL;
    // arg3->unk10 = 0;
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
    // if (arg1 < (u32) unk14->unk4) {
    //     memcpy(arg2, unk18 + (arg1 * 0xC), 0xC);
    //     return 1;
    // }
    // return 0;
}

/**
 * Offset/Address/Size: 0x5C4 | 0x801E8B90 | size: 0xE8
 */
bool BundleFile::GetFileInfo(unsigned long hash, BundleFileDirectoryEntry* arg2, bool printError)
{
    u32 var_r7 = 0;
    
    // Search for the hash
    for (u32 i = m_bundleHeader->m_count; i != 0; i--) 
    {
        if (hash == m_bundleEntries[var_r7].m_hash) {
            // break;
            goto block_4;
        }
        var_r7++;            
    }
    
    if (printError != 0) {
        nlPrintf("ERROR: Failed to find file with hash ID: %d\n", hash);
    }
    var_r7 = -1U;

block_4:
    if ((var_r7 == -1U) && (printError == 0))
    {
        return 0;
    }

    if (var_r7 < (u32)m_bundleHeader->m_count)
    {
        memcpy(arg2, &m_bundleEntries[var_r7], 0xC);
        return 1;
    }

    return 0;
}

/**
 * Offset/Address/Size: 0x6AC | 0x801E8C78 | size: 0x13C
 */
bool BundleFile::GetFileInfo(const char*, BundleFileDirectoryEntry*, bool)
{
    return false;
}

/**
 * Offset/Address/Size: 0x7E8 | 0x801E8DB4 | size: 0x58
 */
void BundleFile::Close()
{
    if ((u32)m_file != NULL)
    {
        nlClose(m_file);
        m_file = NULL;
    }

    if ((u32)m_bundleEntries != NULL)
    {
        delete[] m_bundleEntries;
        m_bundleEntries = NULL;
    }
}

/**
 * Offset/Address/Size: 0x840 | 0x801E8E0C | size: 0xA8
 */
bool BundleFile::Open(const char* filename)
{
    m_file = nlOpen(filename);
    if ((void*)m_file == NULL)
    {
        return 0;
    }
    nlRead(m_file, m_bundleHeader, 0x10);
    nlSeek(m_file, m_bundleHeader->m_unk_0x08 * m_bundleHeader->m_unk_0x00, 0);
    m_bundleEntries = (BundleFileDirectoryEntry*)nlMalloc(m_bundleHeader->m_count * 0xC, 0x20, 0);
    nlRead(m_file, m_bundleEntries, m_bundleHeader->m_count * 0xC);
    return 1;
}

/**
 * Offset/Address/Size: 0x8E8 | 0x801E8EB4 | size: 0x8C
 */
BundleFile::~BundleFile()
{
    if (m_file != NULL)
    {
        nlClose(m_file);
        m_file = NULL;
    }

    if (m_bundleEntries != 0U)
    {
        delete[] m_bundleEntries;
        m_bundleEntries = NULL;
    }

    delete m_bundleHeader;
    m_bundleHeader = NULL;
}

/**
 * Offset/Address/Size: 0x974 | 0x801E8F40 | size: 0x70
 */
BundleFile::BundleFile()
{
    m_file = 0;
    m_unk_0x04 = 0;
    m_unk_0x08 = 0;
    m_unk_0x0C = 0;
    m_unk_0x10 = 0;
    m_bundleHeader = 0;
    m_bundleEntries = 0;
    m_bundleHeader = (BundleFileDirectoryHeader*)nlMalloc(0x10, 0x20, 0);
    memset(m_bundleHeader, 0, 0x10);
}
