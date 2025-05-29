#ifndef OS_DOLPHIN_DOLPHIN_TRK_GLUE_H
#define OS_DOLPHIN_DOLPHIN_TRK_GLUE_H

// #include "dolphin/os.h"
#include "PowerPC_EABI_Support/MetroTRK/trk.h"
#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

DSError TRKInitializeIntDrivenUART(u32 param_0, u32 param_1, u32 param_2,
                                   volatile u8** param_3);

void UnreserveEXI2Port(void);
void ReserveEXI2Port(void);
int TRKPollUART(void);
UARTError TRKReadUARTN(void* bytes, u32 length);
UARTError TRKWriteUARTN(const void* bytes, u32 length);
void TRKLoadContext(OSContext* ctx, u32 r4);
int InitMetroTRKCommTable(int hwId);
void EnableEXI2Interrupts(void);
void TRK_board_display(char* str);

#ifdef __cplusplus
}
#endif

#endif /* OS_DOLPHIN_DOLPHIN_TRK_GLUE_H */
