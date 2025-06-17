#ifndef _NLTASK_H_
#define _NLTASK_H_

#include "types.h"

#include "NL/StatsGatherer.h"

// class nlTask
// {
// public:
// 	virtual void Run(float) = 0;
// 	virtual const char* GetName() = 0;
// 	virtual void StateTransition() = 0;
// };


// bool nlDLRingIsEnd<nlTask>(nlTask*, nlTask*);
// void nlDLRingGetStart<nlTask>(nlTask*);
// void nlDLRingAddStart<nlTask>(nlTask**, nlTask*);
// void nlDLRingInsert<nlTask>(nlTask**, nlTask*, nlTask*);

class nlTaskManager
{
public:
    void SetTimeDilation(float);
    static void SetNextState(unsigned int state);
    void RunAllTasks();
    void AddTask(nlTask*, unsigned int, unsigned int);
    void Startup(unsigned int);

    static nlTaskManager* m_pInstance;

    /* 0x00 */ u8 m_padding_0x00[0x8];
    /* 0x08 */ uint m_unk_0x08;

};

#endif // _NLTASK_H_
