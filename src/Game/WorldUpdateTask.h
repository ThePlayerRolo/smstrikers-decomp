#ifndef _WORLDUPDATETASK_H_
#define _WORLDUPDATETASK_H_


class WorldUpdateTask
{
public:
    virtual void Run(float dt);
    virtual const char*  GetName();
};

#endif // _WORLDUPDATETASK_H_
