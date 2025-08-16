#ifndef _TLTEXTINSTANCE_H_
#define _TLTEXTINSTANCE_H_

#include "types.h"
#include "NL/nlColour.h"
#include "NL/GL/gl.h"

#include "Game/FE/tlInstance.h"

class TLTextInstance : public TLInstance
{
public:
    void SetScissorBox(u16 left, u16 top, u16 width, u16 height);
    void SetString(const unsigned short* utf16);
    void SetStringId(const char* name);
    const unsigned short* GetString() const;
    void Render(eGLView, const nlColour&) const;

    /* 0x80 */ u32 m_stringIdHash;
    /* 0x84 */ char pad84[0x0C];
    /* 0x90 */ u32 m_flags;
    /* 0x94 */ char pad94[0x60];
    /* 0xF4 */ const unsigned short* m_pString;
    /* 0xF8 */ u8 m_scissorEnable;
    /* 0xF9 */ u8 padF9;
    /* 0xFA */ u16 m_scLeft;
    /* 0xFC */ u16 m_scTop;
    /* 0xFE */ u16 m_scWidth;
    /* 0x100 */ u16 m_scHeight;
};

#endif // _TLTEXTINSTANCE_H_
