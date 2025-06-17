#ifndef _NLTASK_H_
#define _NLTASK_H_

class nlTask
{
public:
	virtual void Run(float) = 0;
	virtual const char* GetName() = 0;
	virtual void StateTransition() = 0;
};


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
};

#endif // _NLTASK_H_
