#ifndef _SHCUPCHOOSECAPTAIN_H_
#define _SHCUPCHOOSECAPTAIN_H_

class CupChooseCaptainSceneV2
{
public:
    enum eCupCaptainState
    {
        eCupCaptainState_0 = 0
    };

    enum eSidekickID
    {
        eSidekickID_0 = 0
    };

    CupChooseCaptainSceneV2(bool);
    ~CupChooseCaptainSceneV2();
    void SceneCreated();
    void Update(float);
    void UpdateCaptainName();
    void UpdateSKName();
    void ChangeState(CupChooseCaptainSceneV2::eCupCaptainState, CupChooseCaptainSceneV2::eCupCaptainState);
    void CreateLineup();
    void StartSidekickMiniHead(eSidekickID);
};

// class FEFinder<TLImageInstance, 2>
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

// class FEFinder<TLTextInstance, 3>
// {
// public:
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
// };

#endif // _SHCUPCHOOSECAPTAIN_H_
