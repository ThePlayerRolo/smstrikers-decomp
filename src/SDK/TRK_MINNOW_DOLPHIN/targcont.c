#include "PowerPC_EABI_Support/MetroTRK/trk.h"

DSError TRKTargetContinue(void)
{
    TRKTargetSetStopped(0);
    UnreserveEXI2Port();
    TRKSwapAndGo();
    ReserveEXI2Port();

    return DS_NoError;
}
