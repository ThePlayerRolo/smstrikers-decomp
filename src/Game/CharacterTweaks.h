#ifndef _CHARACTERTWEAKS_H_
#define _CHARACTERTWEAKS_H_

#include "NL/nlLexicalCast.h"

// void LexicalCast<int, const char*>(const char* const&);
// void LexicalCast<float, const char*>(const char* const&);
// void LexicalCast<float, bool>(const bool&);
// void LexicalCast<float, int>(const int&);
// void LexicalCast<float, float>(const float&);
// void LexicalCast<int, bool>(const bool&);
// void LexicalCast<int, int>(const int&);
// void LexicalCast<int, float>(const float&);

class GoalieTweaks
{
public:
    void Init();
    ~GoalieTweaks();
    GoalieTweaks(const char*);
};


class FielderTweaks
{
public:
    void Init();
    ~FielderTweaks();
    FielderTweaks(const char*);
};


class PlayerTweaks
{
public:
    void Init();
    ~PlayerTweaks();

    /* 0x00 */ u8 m_padding_0x00[0x44];
    /* 0x44 */ float m_unk_0x44;
    /* 0x48 */ float m_unk_0x48;    
};

#endif // _CHARACTERTWEAKS_H_
