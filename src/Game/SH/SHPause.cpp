#include "Game/SH/SHPause.h"

// /**
//  * Offset/Address/Size: 0x38 | 0x800B01B4 | size: 0x40
//  */
// void Bind<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)(TLComponentInstance*)>, PauseMenuScene*, Placeholder<0>>(
//     Detail::MemFunImpl<void, void (PauseMenuScene::*)(TLComponentInstance*)>, PauseMenuScene* const&, const Placeholder<0>&)
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x800B017C | size: 0x38
//  */
// void Bind<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)()>, PauseMenuScene*>(Detail::MemFunImpl<void, void
// (PauseMenuScene::*)()>,
//                                                                                        PauseMenuScene* const&)
// {
// }

// /**
//  * Offset/Address/Size: 0x1C | 0x800B0160 | size: 0x1C
//  */
// void MemFun<PauseMenuScene, void>(void (PauseMenuScene::*)())
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x800B0144 | size: 0x1C
//  */
// void MemFun<PauseMenuScene, void, TLComponentInstance*>(void (PauseMenuScene::*)(TLComponentInstance*))
// {
// }

// /**
//  * Offset/Address/Size: 0x5C | 0x800B00E8 | size: 0x5C
//  */
// void Function1<void, TLComponentInstance*>::FunctorImpl<BindExp2<
//     void, Detail::MemFunImpl<void, void (PauseMenuScene::*)(TLComponentInstance*)>, PauseMenuScene*, Placeholder<0>>>::~FunctorImpl()
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x800B008C | size: 0x5C
//  */
// void Function0<void>::FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)()>, PauseMenuScene*>>::~FunctorImpl()
// {
// }

// /**
//  * Offset/Address/Size: 0x128 | 0x800B005C | size: 0x30
//  */
// void Function0<void>::FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)()>, PauseMenuScene*>>::operator()()
// {
// }

// /**
//  * Offset/Address/Size: 0xB0 | 0x800AFFE4 | size: 0x78
//  */
// void Function0<void>::FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)()>, PauseMenuScene*>>::Clone() const
// {
// }

// /**
//  * Offset/Address/Size: 0x80 | 0x800AFFB4 | size: 0x30
//  */
// void Function1<void,
//                TLComponentInstance*>::FunctorImpl<BindExp2<void, Detail::MemFunImpl<void, void
//                (PauseMenuScene::*)(TLComponentInstance*)>,
//                                                            PauseMenuScene*, Placeholder<0>>>::operator()(TLComponentInstance*)
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x800AFF34 | size: 0x80
//  */
// void Function1<void, TLComponentInstance*>::FunctorImpl<
//     BindExp2<void, Detail::MemFunImpl<void, void (PauseMenuScene::*)(TLComponentInstance*)>, PauseMenuScene*, Placeholder<0>>>::Clone()
//     const
// {
// }

// /**
//  * Offset/Address/Size: 0x6CC | 0x800AFEFC | size: 0x38
//  */
// void FEFinder<TLComponentInstance, 4>::Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher,
//                                                      InlineHasher)
// {
// }

// /**
//  * Offset/Address/Size: 0x570 | 0x800AFDA0 | size: 0x15C
//  */
// void FEFinder<TLComponentInstance, 4>::_Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long,
//                                                          unsigned long, unsigned long)
// {
// }

// /**
//  * Offset/Address/Size: 0x4EC | 0x800AFD1C | size: 0x84
//  */
// void FEFinder<TLComponentInstance, 4>::_Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
// long,
//                                                       unsigned long)
// {
// }

// /**
//  * Offset/Address/Size: 0x468 | 0x800AFC98 | size: 0x84
//  */
// void FEFinder<TLComponentInstance, 4>::_Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long,
//                                                              unsigned long, unsigned long)
// {
// }

// /**
//  * Offset/Address/Size: 0x430 | 0x800AFC60 | size: 0x38
//  */
// void FEFinder<TLComponentInstance, 4>::Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher,
//                                                             InlineHasher, InlineHasher)
// {
// }

// /**
//  * Offset/Address/Size: 0x2D4 | 0x800AFB04 | size: 0x15C
//  */
// void FEFinder<TLInstance, 4>::_Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long,
//                                                 unsigned long)
// {
// }

// /**
//  * Offset/Address/Size: 0x250 | 0x800AFA80 | size: 0x84
//  */
// void FEFinder<TLInstance, 4>::_Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long,
//                                              unsigned long)
// {
// }

// /**
//  * Offset/Address/Size: 0x218 | 0x800AFA48 | size: 0x38
//  */
// void FEFinder<TLInstance, 4>::Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher)
// {
// }

// /**
//  * Offset/Address/Size: 0xBC | 0x800AF8EC | size: 0x15C
//  */
// void FEFinder<TLTextInstance, 3>::_Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
// long,
//                                                     unsigned long)
// {
// }

// /**
//  * Offset/Address/Size: 0x38 | 0x800AF868 | size: 0x84
//  */
// void FEFinder<TLTextInstance, 3>::_Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long,
//                                                  unsigned long)
// {
// }

// /**
//  * Offset/Address/Size: 0x0 | 0x800AF830 | size: 0x38
//  */
// void FEFinder<TLTextInstance, 3>::Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher,
//                                                 InlineHasher)
// {
// }

/**
 * Offset/Address/Size: 0x225C | 0x800AF754 | size: 0xDC
 */
PauseMenuScene::PauseMenuScene(PauseMenuScene::ScreenContext)
{
}

/**
 * Offset/Address/Size: 0x21AC | 0x800AF6A4 | size: 0xB0
 */
PauseMenuScene::~PauseMenuScene()
{
}

/**
 * Offset/Address/Size: 0x2158 | 0x800AF650 | size: 0x54
 */
void PauseMenuScene::OnSelectRESUME(TLComponentInstance*)
{
}

/**
 * Offset/Address/Size: 0x18CC | 0x800AEDC4 | size: 0x88C
 */
void PauseMenuScene::OnSelectQUIT(TLComponentInstance*)
{
}

/**
 * Offset/Address/Size: 0x1890 | 0x800AED88 | size: 0x3C
 */
void PauseMenuScene::OnSelectCHOOSESIDES(TLComponentInstance*)
{
}

/**
 * Offset/Address/Size: 0x1854 | 0x800AED4C | size: 0x3C
 */
void PauseMenuScene::OnSelectAUDIOOPTIONS(TLComponentInstance*)
{
}

/**
 * Offset/Address/Size: 0x1818 | 0x800AED10 | size: 0x3C
 */
void PauseMenuScene::OnSelectVISUALOPTIONS(TLComponentInstance*)
{
}

/**
 * Offset/Address/Size: 0x17CC | 0x800AECC4 | size: 0x4C
 */
void PauseMenuScene::OnSelectSTATISTICS(TLComponentInstance*)
{
}

/**
 * Offset/Address/Size: 0x17C8 | 0x800AECC0 | size: 0x4
 */
void PauseMenuScene::OnSelectPopupNOFORFEIT()
{
}

/**
 * Offset/Address/Size: 0x1684 | 0x800AEB7C | size: 0x144
 */
void PauseMenuScene::OnSelectPopupYESFORFEIT()
{
}

/**
 * Offset/Address/Size: 0x1640 | 0x800AEB38 | size: 0x44
 */
void PauseMenuScene::OnSelectLESSONS(TLComponentInstance*)
{
}

/**
 * Offset/Address/Size: 0x84C | 0x800ADD44 | size: 0xDF4
 */
void PauseMenuScene::SceneCreated()
{
}

/**
 * Offset/Address/Size: 0x268 | 0x800AD760 | size: 0x5E4
 */
void PauseMenuScene::Update(float)
{
}

/**
 * Offset/Address/Size: 0xD0 | 0x800AD5C8 | size: 0x198
 */
void PauseMenuScene::TransitionOut(PauseMenuScene::TransitionType)
{
}

/**
 * Offset/Address/Size: 0x0 | 0x800AD4F8 | size: 0xD0
 */
void PauseMenuScene::OpenItem(TLComponentInstance*)
{
}
