#ifndef _NLSTRCHR_H_
#define _NLSTRCHR_H_

#include "types.h"

template<typename CharT>
CharT* nlStrChr(const CharT* str, CharT ch) 
{
    // if (!str) return nullptr;
    while (*str != static_cast<CharT>(0)) 
    {
        if (*str == ch)
            return const_cast<CharT*>(str);
        ++str;
    }
    return nullptr;
}

#endif // _NLSTRCHR_H_
