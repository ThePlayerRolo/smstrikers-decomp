#ifndef _SHPAUSEPOSTGAME_H_
#define _SHPAUSEPOSTGAME_H_

// void nlStrNCpy<unsigned short>(unsigned short*, const unsigned short*, unsigned long);

#include "types.h"
#include "Game/FE/tlTextInstance.h"

class PausePostGameScene
{
public:
    PausePostGameScene();
    ~PausePostGameScene();
    void SceneCreated();
    void Update(float);
    void OnSelectRematch();
    void OnSelectQuit();
    void OnSelectChangeTeams();
    // void SetText(TLTextInstance&, const BasicString<unsigned short, Detail::TempStringAllocator>&);
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
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class Function1<void, TLComponentInstance*>
// {
// public:
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (PausePostGameScene::*)()>, PausePostGameScene*>>::~FunctorImpl();
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (PausePostGameScene::*)()>,
//     PausePostGameScene*>>::operator()(TLComponentInstance*); void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void
//     (PausePostGameScene::*)()>, PausePostGameScene*>>::Clone() const;
// };

// class MemFun<PausePostGameScene, void>(void (PausePostGameScene
// {
// public:
//     void *)());
// };

// class Bind<void, Detail
// {
// public:
//     void MemFunImpl<void, void (PausePostGameScene::*)()>, PausePostGameScene*>(Detail::MemFunImpl<void, void (PausePostGameScene::*)()>,
//     PausePostGameScene* const&);
// };

// class Format<BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>, unsigned short[8]>(const BasicString<unsigned short, Detail::TempStringAllocator>&, const unsigned
//     short(&)[8]);
// };

// class FormatImpl<BasicString<unsigned short, Detail
// {
// public:
//     void TempStringAllocator>>::operator%<const unsigned short*>(const unsigned short* const&);
// };

#endif // _SHPAUSEPOSTGAME_H_
