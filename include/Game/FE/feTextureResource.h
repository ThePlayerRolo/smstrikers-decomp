#ifndef _FETEXTURERESOURCE_H_
#define _FETEXTURERESOURCE_H_

#include "types.h"

class FETextureResource
{
public:
    FETextureResource();

    /* 0x00 */ s32 m_unk_0x00;
    /* 0x04 */ s32 m_unk_0x04;
    /* 0x08 */ s32 m_unk_0x08;
    /* 0x0C */ char padC[4];
    /* 0x10 */ u8 m_unk_0x10;
    // /* 0x11 */ char pad11[3];
    /* 0x14 */ s32 m_unk_0x14;
};

#endif // _FETEXTURERESOURCE_H_
