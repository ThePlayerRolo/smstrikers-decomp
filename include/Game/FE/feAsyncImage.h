#ifndef _FEASYNCIMAGE_H_
#define _FEASYNCIMAGE_H_

#include "types.h"
#include "NL/nlBundleFile.h"

class AsyncImage
{
public:
    AsyncImage(const char*, const char*);
    virtual ~AsyncImage();
    void QueueLoad(const char*, bool);
    void Update(bool);
    void CanSwapTextures() const;
    void SwapTextures();
    void CopyFrom(AsyncImage*);
    void CopyFrom(void*, int);
    void FreeLoadBuffer();

    void TextureLoadComplete(void*, unsigned long, unsigned long) { m_unk_0x18 = 1; }

    /* 0x04 */ BundleFile* m_bundleFile;
    /* 0x08 */ u8* m_unk_0x08;
    /* 0x0C */ BundleFile* m_bundleFile2;
    /* 0x10 */ u32 m_unk_0x10;
    /* 0x14 */ u32 m_unk_0x14;
    /* 0x18 */ s32 m_unk_0x18;
};

#endif // _FEASYNCIMAGE_H_
