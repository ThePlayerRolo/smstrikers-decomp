#ifndef _SHOPTIONS_H_
#define _SHOPTIONS_H_

void RevertChangesCB();
void ApplyChangesCB();

enum eMenuState
{
    eMenuState_0 = 0
};

class OptionsScene
{
public:
    OptionsScene();
    ~OptionsScene();
    void SceneCreated();
    void Update(float);
    void UpdateForMain(float);
    void UpdateForSubOptionMenus(float);
    void ChangeMenuState(eMenuState);
};

// class Function1<void, TLComponentInstance*>
// {
// public:
//     void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void (OptionsScene::*)(eMenuState)>, OptionsScene*,
//     eMenuState>>::~FunctorImpl(); void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void (OptionsScene::*)(eMenuState)>,
//     OptionsScene*, eMenuState>>::operator()(TLComponentInstance*); void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void
//     (OptionsScene::*)(eMenuState)>, OptionsScene*, eMenuState>>::Clone() const;
// };

// class FEFinder<TLComponentInstance, 4>
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

// class MemFun<OptionsScene, void, eMenuState>(void (OptionsScene
// {
// public:
//     void *)(eMenuState));
// };

// class Bind<void, Detail
// {
// public:
//     void MemFunImpl<void, void (OptionsScene::*)(eMenuState)>, OptionsScene*, eMenuState>(Detail::MemFunImpl<void, void
//     (OptionsScene::*)(eMenuState)>, OptionsScene* const&, const eMenuState&);
// };

#endif // _SHOPTIONS_H_
