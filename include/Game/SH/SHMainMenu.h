#ifndef _SHMAINMENU_H_
#define _SHMAINMENU_H_

#include "types.h"

#include "Game/FE/tlComponentInstance.h"

// void onSelectOptions(TLComponentInstance*);
// void onSelectTrophies(TLComponentInstance*);
// void onSelectTournament(TLComponentInstance*);
// void confirmNewTourn();
// void continueTourn();
// void newTourn();
// void onSelect101(TLComponentInstance*);
// void onSelectSuperCup(TLComponentInstance*);
// void onSelectCup(TLComponentInstance*);
// void onSelectFriendly(TLComponentInstance*);
// void 0x800AC504..0x800AC560 | size: 0x5C;

class SHMainMenu
{
public:
    SHMainMenu();
    ~SHMainMenu();
    void SceneCreated();
    void OpenItem(TLComponentInstance*);
    void CloseItem(TLComponentInstance*);
    void Update(float);
};

// class MenuItem<TLComponentInstance>
// {
// public:
//     void MenuItem();
//     void ~MenuItem();
// };

// class FEFinder<TLImageInstance, 2>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class FEFinder<TLComponentInstance, 4>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class FEFinder<TLTextInstance, 3>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class FEFinder<TLInstance, 4>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class Function1<void, TLComponentInstance*>
// {
// public:
//     void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void (SHMainMenu::*)(TLComponentInstance*)>, SHMainMenu*,
//     Placeholder<0>>>::~FunctorImpl(); void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void
//     (SHMainMenu::*)(TLComponentInstance*)>, SHMainMenu*, Placeholder<0>>>::operator()(TLComponentInstance*); void
//     FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void (SHMainMenu::*)(TLComponentInstance*)>, SHMainMenu*,
//     Placeholder<0>>>::Clone() const; void FunctorBase::~FunctorBase();
// };

// class MenuList<TLComponentInstance>
// {
// public:
//     void ~MenuList();
// };

// class FEPopupMenu
// {
// public:
//     void Create(ePopupMenu);
//     void Nothing();
// };

// class MemFun<SHMainMenu, void, TLComponentInstance*>(void (SHMainMenu
// {
// public:
//     void *)(TLComponentInstance*));
// };

// class Bind<void, Detail
// {
// public:
//     void MemFunImpl<void, void (SHMainMenu::*)(TLComponentInstance*)>, SHMainMenu*, Placeholder<0>>(Detail::MemFunImpl<void, void
//     (SHMainMenu::*)(TLComponentInstance*)>, SHMainMenu* const&, const Placeholder<0>&);
// };

#endif // _SHMAINMENU_H_
