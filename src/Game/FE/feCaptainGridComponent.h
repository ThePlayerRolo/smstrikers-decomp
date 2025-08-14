#ifndef _FECAPTAINGRIDCOMPONENT_H_
#define _FECAPTAINGRIDCOMPONENT_H_

enum eTeamID
{
    TEAM_ID_0 = 0,
};

enum eFEINPUT_PAD
{
    FEINPUT_PAD_0 = 0,
};

class TLComponentInstance;
class TLInstance;
class TLSlide;
class InlineHasher;

class ICaptainGridComponent
{
public:
    void SetAllItemsActive();
    void MoveHighlightToTarget(eTeamID);
    void GetSelectedItem() const;
    void IsValid(eTeamID);
    void SetValid(eTeamID, bool);
    void UpdateSuperTeamIconState();
    void Update(eFEINPUT_PAD);
    void RebuildInstanceTable();
    void BuildMapMenu();
    ~ICaptainGridComponent();
    ICaptainGridComponent(TLComponentInstance*, bool);
};

// class FEFinder<TLInstance, 2>
// {
// public:
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
// };

// class FEFinder<TLComponentInstance, 4>
// {
// public:
//     void Find<TLSlide>(TLSlide*, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher, InlineHasher);
//     void _Find<TLSlide>(TLSlide*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
//     void _Find<TLInstance>(TLInstance*, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);
// };

// class IGridComponent<eTeamID>
// {
// public:
//     void ~IGridComponent();
//     void IGridComponent(TLComponentInstance*, const char*, bool);
// };

#endif // _FECAPTAINGRIDCOMPONENT_H_
