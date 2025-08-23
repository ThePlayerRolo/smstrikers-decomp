#ifndef _SHTOURNSETPARAMS_H_
#define _SHTOURNSETPARAMS_H_

#include "types.h"
#include "Game/FE/tlComponentInstance.h"

class TournSetParamsScene
{
public:
    TournSetParamsScene();
    ~TournSetParamsScene();
    void BuildSubMenuList(int, TLComponentInstance*, bool, int);
    void SceneCreated();
    void Update(float);
    void SetInitialParams(bool, int, int);
    void ApplyMenuDefaults();
    void InitializeMenu();
};

// class FEFinder<TLComponentInstance, 4>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

#endif // _SHTOURNSETPARAMS_H_
