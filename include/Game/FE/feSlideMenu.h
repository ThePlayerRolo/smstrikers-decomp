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
};

#endif // _FESLIDEMENU_H_
