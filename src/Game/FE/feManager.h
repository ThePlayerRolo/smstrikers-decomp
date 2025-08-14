#ifndef _FEMANAGER_H_
#define _FEMANAGER_H_

class Event;

class FrontEnd
{
public:
    enum MenuEnterType
    {
        MenuEnterType_0 = 0
    };

    void ReturnToFE();
    void UpdateForGame(float);
    void Update(float);
    void ExitMenuState();
    void EnterMenuState(FrontEnd::MenuEnterType);
    void ExitWinnerScreen();
    void EnterStartScreen(bool);
    void SetControllerState();
    void Destroy();
    void Initialize();
    void FEEventHandler(Event*, void*);

    static int m_feStateCurrent;
};

#endif // _FEMANAGER_H_
