#ifndef _FESLIDEMENU_H_
#define _FESLIDEMENU_H_

// void 0x80375A60..0x80375A68 | size: 0x8;

class TLComponentInstance;

class FESlideMenu
{
public:
    void UpdatePresentation();
    void PrevItem();
    void NextItem();
    void SetSlideByIndex(unsigned char);
    void ApplyFunction();
    void AddMenuItem(const char*);
    ~FESlideMenu();
    // void MenuItem::~MenuItem();
    FESlideMenu(TLComponentInstance*);
    // void MenuItem::MenuItem();

    // /* 0x000 */ char pad0[0x140];
    // /* 0x140 */ u8 unk140; /* inferred */
    // /* 0x141 */ u8 unk141; /* inferred */
    // /* 0x142 */ u8 unk142; /* inferred */
    // /* 0x143 */ char pad143[1];
    // /* 0x144 */ TLComponentInstance* unk144; /* inferred */
    // /* 0x148 */ u8 unk148;                   /* inferred */
    // /* 0x149 */ char pad149[3];              /* maybe part of unk148[4]? */
    // /* 0x14C */ s32 unk14C;                  /* inferred */
    // /* 0x150 */ s32 unk150;                  /* inferred */
    // /* 0x154 */ s32 unk154;                  /* inferred */
    // /* 0x158 */ s32 unk158;                  /* inferred */
    // /* 0x15C */ f32 unk15C;                  /* inferred */
};

#endif // _FESLIDEMENU_H_
