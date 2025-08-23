#ifndef _SHMOVIEPLAYER_H_
#define _SHMOVIEPLAYER_H_

class NLGLogoMovieScene
{
public:
    void PlayScreenBackSFX();
    void PlayScreenForwardSFX();
    ~NLGLogoMovieScene();
    void OverrideMovieDimensions();
};

class LessonMoviePlayerScene
{
public:
    ~LessonMoviePlayerScene();
    void SceneCreated();
    void CheckMoviePlayerAbort();
    void Update(float);
};

class MoviePlayerScene
{
public:
    MoviePlayerScene();
    ~MoviePlayerScene();
    void SceneCreated();
    void SetMovieDetails(const char*, bool, bool);
    void Update(float);
    void CheckMoviePlayerAbort();
    void PlayScreenForwardSFX();
    void PlayScreenBackSFX();
    void OverrideMovieDimensions();
};

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

#endif // _SHMOVIEPLAYER_H_
