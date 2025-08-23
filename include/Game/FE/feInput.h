#ifndef _FEINPUT_H_
#define _FEINPUT_H_

class BaseSceneHandler;

enum eFEINPUT_PAD
{
    FEINPUT_PAD_0 = 0,
};

class FEInput
{
public:
    void EnableAnalogToDPadMapping(eFEINPUT_PAD, bool);
    void SetAutoRepeatParams(eFEINPUT_PAD, int, float, float);
    void Update(float);
    void HasInputLock(BaseSceneHandler*) const;
    void PopExclusiveInputLock(BaseSceneHandler*);
    void PushExclusiveInputLock(BaseSceneHandler*, int);
    void EnableInputIfSceneHasFocus(BaseSceneHandler*);
    void JustReleased(eFEINPUT_PAD, int, bool, eFEINPUT_PAD*);
    void JustPressed(eFEINPUT_PAD, int, bool, eFEINPUT_PAD*);
    void IsAutoPressed(eFEINPUT_PAD, int, bool, eFEINPUT_PAD*);
    void IsPressed(eFEINPUT_PAD, int, bool, eFEINPUT_PAD*);
    void IsConnected(eFEINPUT_PAD);
    void GetGlobalPad(eFEINPUT_PAD) const;
    void Reset();
    FEInput();
    void Initialize();
    ~FEInput();
};

class cGlobalPad
{
public:
    void DisableLeftAnalogToDPadMap();
    void EnableLeftAnalogToDPadMap();
};

class cPadManager
{
public:
    void GetRemapArray();
};

#endif // _FEINPUT_H_
