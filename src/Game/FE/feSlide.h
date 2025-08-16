#ifndef _FESLIDE_H_
#define _FESLIDE_H_

#include "types.h"

typedef struct TLSlide
{
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ f32 m_start;
    /* 0x14 */ f32 m_duration;
    /* 0x18 */ f32 m_time;
    /* 0x1C */ s32 m_wrapMode;
} TLSlide; /* size >= 0x20 */

#endif // _FESLIDE_H_
