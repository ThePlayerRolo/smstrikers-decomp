#include "Game/FE/feAsyncImage.h"

#include "NL/nlMemory.h"
#include "NL/nlString.h"
#include "NL/nlMath.h"
#include "NL/nlFileGC.h"
#include "NL/nlBundleFile.h"

#include "NL/gl/gl.h"
#include "NL/gl/glTexture.h"

extern unsigned int nlDefaultSeed;

/**
 * Offset/Address/Size: 0x0 | 0x80093F10 | size: 0xC
 */
// void AsyncImage::TextureLoadComplete(void*, unsigned long, unsigned long)
// {
//     m_unk_0x18 = 1;
// }

/**
 * Offset/Address/Size: 0x3E4 | 0x80093E50 | size: 0xC0
 */
AsyncImage::AsyncImage(const char* arg0, const char* arg1)
{
    m_bundleFile = NULL;
    m_unk_0x08 = NULL;
    m_loadBuffer = NULL;
    m_bufferSize = 0;
    m_unk_0x18 = 2;

    m_bundleFile = new (nlMalloc(0x1C, 0x20, 1)) BundleFile();
    m_bundleFile->Open(arg0);

    int hash;
    if (arg1 != NULL)
    {
        hash = nlStringHash(arg1);
    }
    else
    {
        hash = nlRandom(0xFFFFFFFF, &nlDefaultSeed);
    }
    m_unk_0x10 = hash;
}

/**
 * Offset/Address/Size: 0x354 | 0x80093DC0 | size: 0x90
 */
AsyncImage::~AsyncImage()
{
    while (m_unk_0x18 == 0)
    {
        nlServiceFileSystem();
    }

    m_bundleFile->Close();
    delete m_bundleFile;

    if (m_loadBuffer != NULL)
    {
        delete[] (m_loadBuffer);
    }
}

/**
 * Offset/Address/Size: 0x284 | 0x80093CF0 | size: 0xD0
 */
void AsyncImage::QueueLoad(const char* path, bool synchronous)
{
    BundleFileDirectoryEntry info;

    if (m_unk_0x18 != 0)
    {
        m_bundleFile->GetFileInfo(path, &info, true);

        if (m_loadBuffer == NULL)
        {
            m_loadBuffer = (u8*)nlMalloc(info.m_length, 0x20, true);
            m_bufferSize = info.m_length;
        }

        m_unk_0x18 = 0;

        if (synchronous)
        {
            m_bundleFile->LoadFile(path, m_loadBuffer);
            m_unk_0x18 = 1;
            return;
        }
        m_bundleFile->ReadFileAsync(path, m_loadBuffer, m_bufferSize, &AsyncImage::TextureLoadComplete, (unsigned long)this);
    }
}

/**
 * Offset/Address/Size: 0x150 | 0x80093BBC | size: 0x134
 */
bool AsyncImage::Update(bool arg0)
{
    if (m_unk_0x08 == NULL)
    {
        return false;
    }

    bool res = false;
    if (m_unk_0x18 == 1)
    {
        if (m_unk_0x10 != m_unk_0x08->m_unk_0x80->m_unk_0x14 && (glTextureLoad(m_unk_0x10) == 0))
        {
            glTextureAdd(m_unk_0x10, m_loadBuffer, m_bufferSize);
            m_unk_0x08->m_unk_0x80->m_unk_0x14 = m_unk_0x10;
        }
    }
    if ((m_unk_0x18 == 1) && (arg0 != 0))
    {
        bool var_r29;
        if (m_unk_0x18 != 1)
        {
            var_r29 = 0;
        }
        else
        {
            var_r29 = 0;
            if ((m_unk_0x08 != NULL) && (m_unk_0x08->m_unk_0x80->m_unk_0x10) && (glTextureLoad(m_unk_0x10) != 0))
            {
                var_r29 = 1;
            }
        }
        if (var_r29 != 0)
        {
            glFinish();
            glTextureReplace(m_unk_0x08->m_unk_0x80->m_unk_0x14, m_loadBuffer, m_bufferSize);
            glDiscardFrame(1);
            res = true;
            m_unk_0x18 = 2;
        }
    }
    return res;
}

/**
 * Offset/Address/Size: 0xE0 | 0x80093B4C | size: 0x70
 */
bool AsyncImage::CanSwapTextures() const
{
    bool var_r31;

    if (m_unk_0x08 == NULL)
    {
        var_r31 = false;
    }
    else
    {
        var_r31 = false;
        if ((m_unk_0x08 != NULL) && (m_unk_0x08->m_unk_0x80->m_unk_0x10 != 0) && (glTextureLoad(m_unk_0x10) != 0))
        {
            var_r31 = true;
        }
    }
    return var_r31;
}

/**
 * Offset/Address/Size: 0x94 | 0x80093B00 | size: 0x4C
 */
void AsyncImage::SwapTextures()
{
    glFinish();
    glTextureReplace(m_unk_0x08->m_unk_0x80->m_unk_0x14, m_loadBuffer, m_bufferSize);
    glDiscardFrame(1);
}

/**
 * Offset/Address/Size: 0x64 | 0x80093AD0 | size: 0x30
 */
void AsyncImage::CopyFrom(AsyncImage* image)
{
    memcpy(m_loadBuffer, image->m_loadBuffer, image->m_bufferSize);
}

/**
 * Offset/Address/Size: 0x40 | 0x80093AAC | size: 0x24
 */
void AsyncImage::CopyFrom(void* buffer, int size)
{
    memcpy(m_loadBuffer, buffer, size);
}

/**
 * Offset/Address/Size: 0x0 | 0x80093A6C | size: 0x40
 */
void AsyncImage::FreeLoadBuffer()
{
    if (m_loadBuffer != NULL)
    {
        delete[] m_loadBuffer;
        m_loadBuffer = NULL;
    }
}

void AsyncImage::TextureLoadComplete(void* buffer, unsigned long size, unsigned long userData)
{
    AsyncImage* self = (AsyncImage*)userData;
    self->m_unk_0x18 = 1;
}
