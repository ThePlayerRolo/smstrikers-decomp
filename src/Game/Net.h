#ifndef _NET_H_
#define _NET_H_

#include "NL/nlMath.h"

class cNet
{
public:
    void SetNetDimensions(float, float, float, float);
    void GetPostLocation(nlVector3&, unsigned int, float) const;
    void GetGoalLineX() const;
    ~cNet();
    cNet(int);
};

#endif // _NET_H_
