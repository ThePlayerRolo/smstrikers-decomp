#ifndef _SHPAUSE_H_
#define _SHPAUSE_H_

#include "types.h"

#include "Game/FE/tlComponentInstance.h"

class PauseMenuScene
{
public:
    class ScreenContext
    {
    public:
        ScreenContext();
        ~ScreenContext();
    };

    enum TransitionType
    {
        TransitionType_0 = 0
    };

    PauseMenuScene(PauseMenuScene::ScreenContext);
    ~PauseMenuScene();
    void OnSelectRESUME(TLComponentInstance*);
    void OnSelectQUIT(TLComponentInstance*);
    void OnSelectCHOOSESIDES(TLComponentInstance*);
    void OnSelectAUDIOOPTIONS(TLComponentInstance*);
    void OnSelectVISUALOPTIONS(TLComponentInstance*);
    void OnSelectSTATISTICS(TLComponentInstance*);
    void OnSelectPopupNOFORFEIT();
    void OnSelectPopupYESFORFEIT();
    void OnSelectLESSONS(TLComponentInstance*);
    void SceneCreated();
    void Update(float);
    void TransitionOut(PauseMenuScene::TransitionType);
    void OpenItem(TLComponentInstance*);
};

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

// class FEFinder<TLComponentInstance, 4>
// {
// public:
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long); void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher,
//     InlineHasher);
// };

// class Function1<void, TLComponentInstance*>
// {
// public:
//     void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)(TLComponentInstance*)>, PauseMenuScene*,
//     Placeholder<0>>>::~FunctorImpl(); void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void
//     (PauseMenuScene::*)(TLComponentInstance*)>, PauseMenuScene*, Placeholder<0>>>::operator()(TLComponentInstance*); void
//     FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)(TLComponentInstance*)>, PauseMenuScene*,
//     Placeholder<0>>>::Clone() const;
// };

// class Function0<void>
// {
// public:
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)()>, PauseMenuScene*>>::~FunctorImpl();
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)()>, PauseMenuScene*>>::operator()();
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)()>, PauseMenuScene*>>::Clone() const;
// };

// class MemFun<PauseMenuScene, void, TLComponentInstance*>(void (PauseMenuScene
// {
// public:
//     void *)(TLComponentInstance*));
// };

// class MemFun<PauseMenuScene, void>(void (PauseMenuScene
// {
// public:
//     void *)());
// };

// class Bind<void, Detail
// {
// public:
//     void MemFunImpl<void, void (PauseMenuScene::*)(TLComponentInstance*)>, PauseMenuScene*, Placeholder<0>>(Detail::MemFunImpl<void, void
//     (PauseMenuScene::*)(TLComponentInstance*)>, PauseMenuScene* const&, const Placeholder<0>&); void MemFunImpl<void, void
//     (PauseMenuScene::*)()>, PauseMenuScene*>(Detail::MemFunImpl<void, void (PauseMenuScene::*)()>, PauseMenuScene* const&);
// };

#endif // _SHPAUSE_H_
