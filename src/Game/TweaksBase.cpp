#include "TweaksBase.h"

/**
 * Offset/Address/Size: 0x0 | 0x800661D4 | size: 0x48
 */
TweaksBase::~TweaksBase()
{
}

/**
 * Offset/Address/Size: 0x48 | 0x8006621C | size: 0x4C
 */
TweaksBase::TweaksBase(const char* param_1)
{
    m_unk_0x04[0] = 0;
    nlStrNCpy<char>(m_unk_0x04, param_1, 0x1f);
}
