#ifndef _NLTIMER_H_
#define _NLTIMER_H_

class Timer
{
public:
    void Countup(float, float);
    void Countdown(float, float);
    void GetSeconds() const;
    void SetSeconds(float);
};

#endif // _NLTIMER_H_
