#ifndef _SHLESSONSELECT_H_
#define _SHLESSONSELECT_H_

void SetTickerLesson(int);
void LessonTickerDoneCB();

class LessonSelectScene
{
public:
    LessonSelectScene();
    ~LessonSelectScene();
    void SceneCreated();
    void Update(float);
    void UpdateRow(int, bool);
    void StartLesson();
};

// class Function1<void, TLComponentInstance*>
// {
// public:
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (LessonSelectScene::*)()>, LessonSelectScene*>>::~FunctorImpl();
//     void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void (LessonSelectScene::*)()>,
//     LessonSelectScene*>>::operator()(TLComponentInstance*); void FunctorImpl<BindExp1<void, Detail::MemFunImpl<void, void
//     (LessonSelectScene::*)()>, LessonSelectScene*>>::Clone() const;
// };

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

// class FEFinder<TLImageInstance, 2>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

// class MemFun<LessonSelectScene, void>(void (LessonSelectScene
// {
// public:
//     void *)());
// };

// class Bind<void, Detail
// {
// public:
//     void MemFunImpl<void, void (LessonSelectScene::*)()>, LessonSelectScene*>(Detail::MemFunImpl<void, void (LessonSelectScene::*)()>,
//     LessonSelectScene* const&);
// };

#endif // _SHLESSONSELECT_H_
