#ifndef _FECHOOSESIDECOMPONENT_H_
#define _FECHOOSESIDECOMPONENT_H_

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


class IChooseSide
{
public:
    void SaveChanges();
    void TweenSetPosCallback(void*, const float*);
    void AllControllersAreCentred() const;
    void AtLeastOnePlayerReady() const;
    void AllPluggedInAreReady() const;
    void AllPlayersReady() const;
    void PositionController(int, bool, bool);
    void SetReady(int, bool);
    void ResetAndPositionControllers(bool);
    void CheckControllers(int);
    void UpdateForPause(float, eFEINPUT_PAD*);
    void UpdateForFE(float, eFEINPUT_PAD*);
    void Update(float, eFEINPUT_PAD*, int);
    ~IChooseSide();
    IChooseSide();
};

#endif // _FECHOOSESIDECOMPONENT_H_
