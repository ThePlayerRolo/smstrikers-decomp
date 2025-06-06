#ifndef _NLTASK_H_
#define _NLTASK_H_

typedef struct {
    // todo..
} nlTask;

// bool nlDLRingIsEnd<nlTask>(nlTask*, nlTask*);
// void nlDLRingGetStart<nlTask>(nlTask*);
// void nlDLRingAddStart<nlTask>(nlTask**, nlTask*);
// void nlDLRingInsert<nlTask>(nlTask**, nlTask*, nlTask*);

class nlTaskManager
{
public:
    void SetTimeDilation(float);
    void SetNextState(unsigned int);
    void RunAllTasks();
    void AddTask(nlTask*, unsigned int, unsigned int);
    void Startup(unsigned int);
};

#endif // _NLTASK_H_
