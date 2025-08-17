#include "Game/FE/tlTextInstance.h"

/**
 * Offset/Address/Size: 0x0 | 0x802101D8 | size: 0x1C
 */
void TLTextInstance::SetScissorBox(u16 left, u16 top, u16 width, u16 height)
{
    m_scissorEnable = true;
    m_scLeft = left;
    m_scTop = top;
    m_scWidth = width;
    m_scHeight = height;
}

/**
 * Offset/Address/Size: 0x1C | 0x802101F4 | size: 0x1C
 */
void TLTextInstance::SetString(const unsigned short* utf16)
{
    m_pString = utf16;
    m_unk_0xEC = 0;
    m_flags &= 0xFFFFFFF7;
}

/**
 * Offset/Address/Size: 0x38 | 0x80210210 | size: 0x250
 */
void TLTextInstance::Render(eGLView, const nlColour&) const
{
}

/**
 * Offset/Address/Size: 0x288 | 0x80210460 | size: 0x94
 */
const unsigned short* TLTextInstance::GetString() const
{
    u32 sp8;
    // nlLocalization::StringLookup* temp_r4;
    u16* var_r0 = NULL;
    void* temp_r31;
    void* temp_r3;

    if (m_flags & 8)
    {
        // temp_r31 = g_pLocalization;
        // sp8 = m_stringIdHash;
        // temp_r4 = temp_r31->unk4;
        // if (temp_r4 == NULL)
        // {
        //     var_r0 = &LocalizationTableNotFound;
        // }
        // else
        // {
        //     temp_r3 = nlBSearch<Q214nlLocalization12StringLookup, Ul> __FRCUlPQ214nlLocalization12StringLookupi(&sp8, temp_r4,
        //                                                                                                         temp_r31->unk0->unkC);
        //     if (temp_r3 != NULL)
        //     {
        //         var_r0 = temp_r31->unk8 + (temp_r3->unk4 * 2);
        //     }
        //     else
        //     {
        //         var_r0 = &MissingLocString;
        //     }
        // }
        return var_r0;
    }
    return m_pString;
}
