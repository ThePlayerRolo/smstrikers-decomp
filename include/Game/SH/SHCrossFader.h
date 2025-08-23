#ifndef _SHCROSSFADER_H_
#define _SHCROSSFADER_H_

class CrossFaderScene
{
public:
    CrossFaderScene();
    ~CrossFaderScene();
    void SceneCreated();
    void Update(float);
};

// class FEFinder<TLImageInstance, 2>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<FEPresentation>(FEPresentation*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned
//     long); void Find<FEPresentation>(FEPresentation*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher,
//     InlineHasher);
// };

// class FEResourceManager
// {
// public:
//     void Run(float);
// };

#endif // _SHCROSSFADER_H_
