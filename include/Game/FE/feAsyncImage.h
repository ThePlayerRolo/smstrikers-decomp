#ifndef _FEASYNCIMAGE_H_
#define _FEASYNCIMAGE_H_

#include "types.h"
#include "NL/nlBundleFile.h"
#include "Game/FE/feTextureResource.h"

class SomeOtherClass
{
public:
    /* 0x00 */ bool m_unk_0x00;
    /* 0x01 */ u8 pad0[0x7F];
    /* 0x80 */ FETextureResource* m_unk_0x80;
};

class AsyncImage
{
public:
    AsyncImage(const char*, const char*);
    virtual ~AsyncImage();
    void QueueLoad(const char*, bool);
    bool Update(bool);
    bool CanSwapTextures() const;
    void SwapTextures();
    void CopyFrom(AsyncImage*);
    void CopyFrom(void*, int);
    void FreeLoadBuffer();

    static void TextureLoadComplete(void*, unsigned long, unsigned long);

    /* 0x04 */ BundleFile* m_bundleFile;
    /* 0x08 */ SomeOtherClass* m_unk_0x08;
    /* 0x0C */ u8* m_loadBuffer;
    /* 0x10 */ u32 m_unk_0x10;
    /* 0x14 */ u32 m_bufferSize;
    /* 0x18 */ s32 m_unk_0x18;
};

#endif // _FEASYNCIMAGE_H_
