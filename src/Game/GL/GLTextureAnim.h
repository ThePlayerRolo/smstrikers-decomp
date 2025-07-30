#ifndef _GLTEXTUREANIM_H_
#define _GLTEXTUREANIM_H_

#include "types.h"

class GLAnimTex;

class GLTextureAnim
{
public:
    void Update(float);
    void GetTextureHandle(float);
    void GetTexture(int);
    void SetTexture(int, const GLAnimTex&);
    void SetFrame(int);
    void SetNumTextures(int);

    ~GLTextureAnim();
    GLTextureAnim();

    /* 0x00 */ s32 m_unk_0x00;
    /* 0x04 */ u32 m_unk_0x04;
    /* 0x08 */ u32 m_unk_0x08;
    /* 0x0C */ u32 m_unk_0x0C;
    /* 0x10 */ bool m_unk_0x10;
    /* 0x14 */ u32 m_unk_0x14;
    /* 0x18 */ u32 m_unk_0x18_unused;
    /* 0x14 */ u32 m_unk_0x1C;
};

#endif // _GLTEXTUREANIM_H_
