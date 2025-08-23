#ifndef _FEMUSIC_H_
#define _FEMUSIC_H_


class FEMusic
{
public:
    void ResetCurrentFEStreamHash();
    void StopStream();
    void StartStreamIfDifferent(int);
};

#endif // _FEMUSIC_H_