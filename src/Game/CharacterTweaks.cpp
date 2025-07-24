#include "CharacterTweaks.h"
#include "NL/nlConfig.h"

/* LexicalCast<float, bool> */
f32 LexicalCast<float, bool>(const u8 &arg0) {
    return static_cast<f32>(arg0);
}

/* LexicalCast<float, int> */
f32 LexicalCast<float, int>(const s32 &arg0) {
    return static_cast<f32>(arg0);
}

/* LexicalCast<float, float> */
f32 LexicalCast<float, float>(const f32 &arg0) {
    return arg0;
}

/* LexicalCast<float, char const *> */
f32 LexicalCast<float, const char*>(const char* const &arg0) {
    return static_cast<f32>(atof(arg0));
}

/* LexicalCast<int, bool> */
s32 LexicalCast<int, bool>(const u8 &arg0) {
    return static_cast<s32>(arg0);
}

/* LexicalCast<int, int> */
s32 LexicalCast<int, int>(const s32 &arg0) {
    return arg0;
}

/* LexicalCast<int, float> */
s32 LexicalCast<int, float>(const f32 &arg0) {
    return static_cast<s32>(arg0);
}

/* LexicalCast<int, char const *> */
s32 LexicalCast<int, const char*>(const char* const &arg0) {
    return static_cast<s32>(atof(arg0));
}

/**
 * Offset/Address/Size: 0x0 | 0x800149F0 | size: 0x1904
 */
void GoalieTweaks::Init()
{
}

/**
 * Offset/Address/Size: 0x1904 | 0x800162F4 | size: 0x70
 */
GoalieTweaks::~GoalieTweaks()
{
}

/**
 * Offset/Address/Size: 0x1974 | 0x80016364 | size: 0x80
 */
GoalieTweaks::GoalieTweaks(const char* arg0)
// : TweaksBase(arg0)
{
    // PlayerTweaks::Init();
    // GoalieTweaks::Init();
    // Init();
}

/**
 * Offset/Address/Size: 0x19F4 | 0x800163E4 | size: 0x13B8
 */
void FielderTweaks::Init()
{
}

/**
 * Offset/Address/Size: 0x2DAC | 0x8001779C | size: 0x70
 */
FielderTweaks::~FielderTweaks()
{
}

/**
 * Offset/Address/Size: 0x2E1C | 0x8001780C | size: 0x80
 */
FielderTweaks::FielderTweaks(const char*)
{
}

/**
 * Offset/Address/Size: 0x2E9C | 0x8001788C | size: 0x590
 */
void PlayerTweaks::Init()
{
    float var_f1;
    Config cfg(Config::AllocateWhere_1);
    cfg.LoadFromFile(m_unk_0x04);

    SetTagValuePair *tvp = cfg.FindTvp("Jog Speed");
    if (tvp->m_unk_0x00 == NULL) 
    {
        cfg.Set("Jog Speed", 1.6f);
        var_f1 = 1.6f;        
    } 
    else
    {
        switch (tvp->m_unk_0x04) 
        {
        case 0:
            var_f1 = LexicalCast<float,bool>(tvp->m_unk_0x08);
            break;
        case 1:
            var_f1 = LexicalCast<float,int>(tvp->m_unk_0x08);
            break;
        case 2:
            var_f1 = LexicalCast<float,float>(tvp->m_unk_0x08);
            break;
        case 3:
            var_f1 = LexicalCast<float,char*>(tvp->m_unk_0x08);
            break;
        default:
            var_f1 = 0.0f;
            break;
        }
    }     
    m_unk_0x24 = var_f1;  
}

/**
 * Offset/Address/Size: 0x342C | 0x80017E1C | size: 0x60
 */
PlayerTweaks::~PlayerTweaks()
{
}

// /**
//  * Offset/Address/Size: 0x0 | 0x80017E7C | size: 0x30
//  */
// void LexicalCast<int, const char*>(const char* const&)
// {
// }

// /**
//  * Offset/Address/Size: 0x30 | 0x80017EAC | size: 0x28
//  */
// void LexicalCast<float, const char*>(const char* const&)
// {
// }

// /**
//  * Offset/Address/Size: 0x58 | 0x80017ED4 | size: 0x28
//  */
// void LexicalCast<float, bool>(const bool&)
// {
// }

// /**
//  * Offset/Address/Size: 0x80 | 0x80017EFC | size: 0x2C
//  */
// void LexicalCast<float, int>(const int&)
// {
// }

// /**
//  * Offset/Address/Size: 0xAC | 0x80017F28 | size: 0x8
//  */
// void LexicalCast<float, float>(const float&)
// {
// }

// /**
//  * Offset/Address/Size: 0xB4 | 0x80017F30 | size: 0x8
//  */
// void LexicalCast<int, bool>(const bool&)
// {
// }

// /**
//  * Offset/Address/Size: 0xBC | 0x80017F38 | size: 0x8
//  */
// void LexicalCast<int, int>(const int&)
// {
// }

// /**
//  * Offset/Address/Size: 0xC4 | 0x80017F40 | size: 0x1C
//  */
// void LexicalCast<int, float>(const float&)
// {
// }
