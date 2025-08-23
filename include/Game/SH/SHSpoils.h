#ifndef _SHSPOILS_H_
#define _SHSPOILS_H_

class SpoilsScene
{
public:
    enum eSpoils
    {
        eSpoils_0 = 0
    };

    SpoilsScene();
    ~SpoilsScene();
    void Update(float);
    void SceneCreated();
    void ShowSpoils(SpoilsScene::eSpoils);
};

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

// class Function1<void, TLComponentInstance*>
// {
// public:
//     void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void (SpoilsScene::*)(SpoilsScene::eSpoils)>, SpoilsScene*,
//                               SpoilsScene::eSpoils>>::~FunctorImpl();
//     void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void (SpoilsScene::*)(SpoilsScene::eSpoils)>, SpoilsScene*,
//                               SpoilsScene::eSpoils>>::operator()(TLComponentInstance*);
//     void FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void (SpoilsScene::*)(SpoilsScene::eSpoils)>, SpoilsScene*,
//                               SpoilsScene::eSpoils>>::Clone() const;
// };

// class MemFun < SpoilsScene, void, SpoilsScene
// {
// public:
//     void eSpoils > (void (SpoilsScene::*)(SpoilsScene::eSpoils));
// };

// class Bind < void, Detail
// {
// public:
//     void MemFunImpl<void, void (SpoilsScene::*)(SpoilsScene::eSpoils)>, SpoilsScene *,
//         SpoilsScene::eSpoils
//             > (Detail::MemFunImpl<void, void (SpoilsScene::*)(SpoilsScene::eSpoils)>, SpoilsScene* const&, const SpoilsScene::eSpoils&);
// };

#endif // _SHSPOILS_H_
