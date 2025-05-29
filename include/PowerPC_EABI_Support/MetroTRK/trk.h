#ifndef __METROTRK_TRK_H__
#define __METROTRK_TRK_H__

#include "dolphin/types.h"
#include "PowerPC_EABI_Support/MetroTRK/trktypes.h"

#ifdef __cplusplus
extern "C" {
#endif

void TRKSaveExtended1Block();

////////// OTHER FUNCTIONS /////////
DSError TRK_main(void);
UARTError InitializeUART(UARTBaudRate baudRate);
DSError TRKInitializeIntDrivenUART(u32, u32, u32, volatile u8**);
int TRKPollUART();
UARTError TRKReadUARTN(void*, u32);
UARTError TRKWriteUARTN(const void* bytes, u32 length);
void usr_put_initialize();
void TRKTargetSetInputPendingPtr(void*);
void SetUseSerialIO(u8);
u8 GetUseSerialIO(void);
u8 TRKTargetCPUMinorType();

DSError TRKTargetAddStopInfo(TRKBuffer*);
DSError TRKTargetAddExceptionInfo(TRKBuffer*);
void TRKInterruptHandler();
BOOL usr_puts_serial(const char* msg);
////////////////////////////////////

#define SPR_XER    1
#define SPR_LR     8
#define SPR_CTR    9
#define SPR_DSISR  18
#define SPR_DAR    19
#define SPR_DEC    22
#define SPR_SDR1   25
#define SPR_SRR0   26
#define SPR_SRR1   27
#define SPR_SPRG0  272
#define SPR_SPRG1  273
#define SPR_SPRG2  274
#define SPR_SPRG3  275
#define SPR_EAR    282
#define SPR_TBL    284
#define SPR_TBU    285
#define SPR_PVR    287
#define SPR_IBAT0U 528
#define SPR_IBAT0L 529
#define SPR_IBAT1U 530
#define SPR_IBAT1L 531
#define SPR_IBAT2U 532
#define SPR_IBAT2L 533
#define SPR_IBAT3U 534
#define SPR_IBAT3L 535
#define SPR_IBAT4U 560
#define SPR_IBAT4L 561
#define SPR_IBAT5U 562
#define SPR_IBAT5L 563
#define SPR_IBAT6U 564
#define SPR_IBAT6L 565
#define SPR_IBAT7U 566
#define SPR_IBAT7L 567
#define SPR_DBAT0U 536
#define SPR_DBAT0L 537
#define SPR_DBAT1U 538
#define SPR_DBAT1L 539
#define SPR_DBAT2U 540
#define SPR_DBAT2L 541
#define SPR_DBAT3U 542
#define SPR_DBAT3L 543
#define SPR_DBAT4U 568
#define SPR_DBAT4L 569
#define SPR_DBAT5U 570
#define SPR_DBAT5L 571
#define SPR_DBAT6U 572
#define SPR_DBAT6L 573
#define SPR_DBAT7U 574
#define SPR_DBAT7L 575
#define SPR_GQR0   912
#define SPR_GQR1   913
#define SPR_GQR2   914
#define SPR_GQR3   915
#define SPR_GQR4   916
#define SPR_GQR5   917
#define SPR_GQR6   918
#define SPR_GQR7   919
#define SPR_HID2   920
#define SPR_WPAR   921
#define SPR_DMA_U  922
#define SPR_DMA_L  923
#define SPR_UMMCR0 936
#define SPR_UPMC1  937
#define SPR_UPMC2  938
#define SPR_USIA   939
#define SPR_UMMCR1 940
#define SPR_UPMC3  941
#define SPR_UPMC4  942
#define SPR_USDA   943
#define SPR_MMCR0  952
#define SPR_PMC1   953
#define SPR_PMC2   954
#define SPR_SIA    955
#define SPR_MMCR1  956
#define SPR_PMC3   957
#define SPR_PMC4   958
#define SPR_SDA    959
#define SPR_HID0   1008
#define SPR_HID1   1009
#define SPR_IABR   1010
#define SPR_HID4   1011
#define SPR_DABR   1013
#define SPR_L2CR   1017
#define SPR_ICTC   1019
#define SPR_THRM1  1020
#define SPR_THRM2  1021
#define SPR_FPECR  1022

// PPC exceptions
// 0x000 is reserved
#define PPC_SystemReset             0x100
#define PPC_MachineCheck            0x200
#define PPC_DataStorage             0x300
#define PPC_InstructionStorage      0x400
#define PPC_ExternalInterrupt       0x500
#define PPC_Alignment               0x600
#define PPC_Program                 0x700
#define PPC_FloatingPointUnavaiable 0x800
#define PPC_Decrementer             0x900
// 0xA00-0xB00 are reserved
#define PPC_SystemCall          0xC00
#define PPC_Trace               0xD00
#define PPC_FloatingPointAssist 0xE00 // unimplemented in 750CL
#define PPC_PerformanceMonitor  0xF00 // Dolphin/Broadway specific
// 0x1000-0x1200 are unimplemented in 750CL
#define PPC_InstructionAddressBreakpoint 0x1300 // Dolphin/Broadway specific
// 0x1400-0x2F00 are reserved, but TRK uses some
#define PPC_SystemManagementInterrupt 0x1400
// 0x1500-0x1600 are unimplemented in 750CL
#define PPC_ThermalManagementInterrupt 0x1700
#define PPC_1800Exception              0x1800
#define PPC_1900Exception              0x1900
#define PPC_1A00Exception              0x1A00
#define PPC_1B00Exception              0x1B00
#define PPC_1C00Exception              0x1C00 // Data breakpoint?
#define PPC_1D00Exception              0x1D00 // Instruction breakpoint?
#define PPC_1E00Exception              0x1E00 // Peripheral breakpoint?
#define PPC_1F00Exception              0x1F00 // Non maskable development port?
#define PPC_2000Exception              0x2000

/////////// MW FUNCTIONS ///////////
void MWTRACE(u8, char*, ...);
////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __METROTRK_TRK_H__ */
