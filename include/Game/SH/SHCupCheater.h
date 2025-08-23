#ifndef _SHCUPCHEATER_H_
#define _SHCUPCHEATER_H_

class CupCheaterScene
{
public:
    CupCheaterScene();
    ~CupCheaterScene();
    void SceneCreated();
    void Update(float);
    void OnSelectGameplay();
    void OnSelectHomeWin();
    void OnSelectAwayWin();
    void OnSelectHomeOTWin();
    void OnSelectAwayOTWin();
    void UpdateSlides();
};

// class FEFinder<TLTextInstance, 3>
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
//     void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long); void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher,
//     InlineHasher);
// };

// class Function0<void>
// {
// public:
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (CupCheaterScene::*)()>, CupCheaterScene*>>::~FunctorImpl();
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (CupCheaterScene::*)()>, CupCheaterScene*>>::operator()();
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (CupCheaterScene::*)()>, CupCheaterScene*>>::Clone() const;
// };

// class MemFun<CupCheaterScene, void>(void (CupCheaterScene
// {
// public:
//     void *)());
// };

// class Bind<void, Detail
// {
// public:
//     void MemFunImpl<void, void (CupCheaterScene::*)()>, CupCheaterScene*>(Detail::MemFunImpl<void, void (CupCheaterScene::*)()>,
//     CupCheaterScene* const&);
// };

#endif // _SHCUPCHEATER_H_
