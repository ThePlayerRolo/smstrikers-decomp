#ifndef _FECAPTAINGRIDCOMPONENT_H_
#define _FECAPTAINGRIDCOMPONENT_H_

enum eTeamID
{
    TEAM_ID_0 = 0,
};

enum eFEINPUT_PAD {
    FE_PAD1_ID = 0,
    FE_PAD2_ID = 1,
    FE_PAD3_ID = 2,
    FE_PAD4_ID = 3,
    FE_PAD5_ID = 4,
    FE_PAD6_ID = 5,
    FE_PAD7_ID = 6,
    FE_PAD8_ID = 7,
    FE_ALL_PADS = 8,
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
