#ifndef _GLTEXTUREANIM_H_
#define _GLTEXTUREANIM_H_

#include "types.h"

struct GLAnimTex // size: 8 bytes
{
    /* 0x00 */ u32 m_textureHandle;
    /* 0x04 */ f32 m_time;
};

class GLTextureAnim
{
public:
    void Update(float deltaTime);
    u32 GetTextureHandle(float time);
    GLAnimTex* GetTexture(int frameIndex);
    void SetTexture(int frameIndex, const GLAnimTex& animTex);
    void SetFrame(int frameIndex);
    void SetNumTextures(int numTextures);

    ~GLTextureAnim();
    GLTextureAnim();

    /* 0x00 */ s32 m_unk_0x00;
    /* 0x04 */ s32 m_numTextures;
    /* 0x08 */ u32 m_animationType; // ?? 0=loop, 1=ping-pong, 2=once, 3=reverse
    /* 0x0C */ s32 m_direction; // ?? 1=forward, -1=backward (for ping-pong)
    /* 0x10 */ bool m_isStopped;
    /* 0x14 */ u32 m_currentFrame;
    /* 0x18 */ f32 m_currentTime;
    /* 0x1C */ GLAnimTex* m_textureArray;
};

#endif // _GLTEXTUREANIM_H_
