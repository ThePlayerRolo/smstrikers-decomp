#ifndef _GLVERTEXANIM_H_
#define _GLVERTEXANIM_H_

#include "types.h"

class GLVertexAnim
{
public:
    void Reset();
    void Update(float);
    void GetModel(int);
    GLVertexAnim();

    /* 0x00 */ s32 m_unk_0x00;
    /* 0x00 */ s32 m_unk_0x04;
    /* 0x00 */ s32 m_unk_0x08;
    /* 0x00 */ f32 m_unk_0x0C;
    /* 0x00 */ s32 m_unk_0x10;
    /* 0x00 */ bool m_unk_0x14;
    /* 0x00 */ f32 m_unk_0x1C;
    /* 0x00 */ f32 m_unk_0x18;
    /* 0x00 */ s32 m_unk_0x20;
    /* 0x00 */ void* m_unk_0x24;
};

#endif // _GLVERTEXANIM_H_
