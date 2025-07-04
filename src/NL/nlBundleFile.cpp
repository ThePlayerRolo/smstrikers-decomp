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
bool BundleFile::GetFileInfo(unsigned long arg1, BundleFileDirectoryEntry* arg2, bool arg3)
{
    s32 var_r5;
    u32 temp_r0;
    u32 var_ctr;
    u32 var_r7;

    var_r7 = 0;
    var_r5 = 0;
    temp_r0 = m_unk_0x14->m_unk_0x04;
    var_ctr = temp_r0;
    if (temp_r0 > 0U)
    {
    loop_1:
        if (arg1 == (u32) * ((u8*)m_unk_0x18 + var_r5))
        {
        }
        else
        {
            var_r5 += 0xC;
            var_r7 += 1;
            var_ctr -= 1;
            if (var_ctr == 0U)
            {
                goto block_4;
            }
            goto loop_1;
        }
    }
    else
    {
    block_4:
        if (arg3 != 0)
        {
            nlPrintf("ERROR: Failed to find file with hash ID: %d\n");
        }
        var_r7 = -1U;
    }
    if (((u32)(var_r7 + 0x10000) == -1U) && (arg3 == 0))
    {
        return 0;
    }
    if (var_r7 < (u32)m_unk_0x14->m_unk_0x04)
    {
        memcpy(arg2, m_unk_0x18 + (var_r7 * 0xC), 0xC);
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

    if ((u32)m_unk_0x18 != NULL)
    {
        delete[] m_unk_0x18;
        m_unk_0x18 = NULL;
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
    nlRead(m_file, m_unk_0x14, 0x10);
    nlSeek(m_file, m_unk_0x14->m_unk_0x08 * m_unk_0x14->m_unk_0x00, 0);
    m_unk_0x18 = (BundleFileDirectoryEntry*)nlMalloc(m_unk_0x14->m_unk_0x04 * 0xC, 0x20, 0);
    nlRead(m_file, m_unk_0x18, m_unk_0x14->m_unk_0x04 * 0xC);
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

    if (m_unk_0x18 != 0U)
    {
        delete[] m_unk_0x18;
        m_unk_0x18 = NULL;
    }

    delete m_unk_0x14;
    m_unk_0x14 = NULL;
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
    m_unk_0x14 = 0;
    m_unk_0x18 = 0;
    m_unk_0x14 = (BundleFileDirectoryEntry*)nlMalloc(0x10, 0x20, 0);
    memset(m_unk_0x14, 0, 0x10);
}
