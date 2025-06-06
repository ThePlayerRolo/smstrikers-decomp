#ifndef _NLTICKER_H_
#define _NLTICKER_H_

#include "types.h"

f32 nlGetTickerDifference(uint arg0, uint arg1);
uint nlSubtractTicks(uint, uint);
u32 nlGetTicker();
void nlInitTicker();

#endif // _NLTICKER_H_
