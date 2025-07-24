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

class TweaksBase
{
public:
    TweaksBase(const char*);
    virtual ~TweaksBase() {};
    virtual void Init() = 0;
};

class PlayerTweaks : public TweaksBase
{
public:
    virtual ~PlayerTweaks();
    virtual void Init();

    /* 0x04 */ char m_unk_0x04[0x20]; // most probably config file name
    /* 0x04 */ float m_unk_0x24;
    /* 0x28 */ u8 m_padding_0x28[0x1C];
    /* 0x44 */ float m_unk_0x44;
    /* 0x48 */ float m_unk_0x48;    
};

class GoalieTweaks //: public PlayerTweaks
{
public:
    GoalieTweaks(const char*);
    virtual ~GoalieTweaks();
    virtual void Init();
};

class FielderTweaks //: public PlayerTweaks
{
public:
    FielderTweaks(const char*);
    virtual ~FielderTweaks();
    virtual void Init();
};

#endif // _CHARACTERTWEAKS_H_
