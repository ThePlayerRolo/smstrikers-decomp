#include "Game/Sys/FloatingPointExceptions.h"

#include "Dolphin/os.h"
#include "Dolphin/os/OSError.h"

static const char sInvalidOpHdr[] = "FPE: Invalid operation: ";
static const char sSNaN[] = "SNaN\n";
static const char sInfMinusInf[] = "Infinity - Infinity\n";
static const char sInfDivInf[] = "Infinity / Infinity\n";
static const char sZeroDivZero[] = "0 / 0\n";
static const char sInfTimesZero[] = "Infinity * 0\n";
static const char sInvalidCompare[] = "Invalid compare\n";
static const char sSoftwareRequest[] = "Software request\n";
static const char sInvalidSqrt[] = "Invalid square root\n";
static const char sInvalidIntCvt[] = "Invalid integer convert\n";
static const char sOverflow[] = "FPE: Overflow\n";
static const char sUnderflow[] = "FPE: Underflow\n";
static const char sZeroDivision[] = "FPE: Zero division\n";
static const char sInexact[] = "FPE: Inexact result\n";

enum
{
    BIT_2 = 0x20000000, // Invalid operation summary
    BIT_3 = 0x10000000, // Overflow
    BIT_4 = 0x08000000, // Underflow
    BIT_5 = 0x04000000, // Zero division
    BIT_6 = 0x02000000, // Inexact

    BIT_7 = 0x01000000,  // SNaN
    BIT_8 = 0x00800000,  // Infinity - Infinity
    BIT_9 = 0x00400000,  // Infinity / Infinity
    BIT_10 = 0x00200000, // 0 / 0
    BIT_11 = 0x00100000, // Infinity * 0
    BIT_12 = 0x00080000, // Invalid compare

    BIT_21 = 0x00000400, // Software request
    BIT_22 = 0x00000200, // Invalid square root
    BIT_23 = 0x00000100  // Invalid integer convert
};

/**
 * Offset/Address/Size: 0x38 | 0x801ACCCC | size: 0x198
 */
void FloatingPointErrorHandler(u16 /*error*/, OSContext* ctx, u32 /*dsisr*/, u32 /*dar*/)
{
    u32 fpscr = ctx->fpscr;

    u32 r0 = ((fpscr << 22) & 0x3E000000) | 0x01F80000u | 0x00000700u;
    fpscr &= r0;

    if (fpscr & BIT_2)
    {
        OSReport(sInvalidOpHdr);
        if (fpscr & BIT_7)
            OSReport(sSNaN);
        if (fpscr & BIT_8)
            OSReport(sInfMinusInf);
        if (fpscr & BIT_9)
            OSReport(sInfDivInf);
        if (fpscr & BIT_10)
            OSReport(sZeroDivZero);
        if (fpscr & BIT_11)
            OSReport(sInfTimesZero);
        if (fpscr & BIT_12)
            OSReport(sInvalidCompare);
        if (fpscr & BIT_21)
            OSReport(sSoftwareRequest);
        if (fpscr & BIT_22)
            OSReport(sInvalidSqrt);
        if (fpscr & BIT_23)
            OSReport(sInvalidIntCvt);
    }

    // Other FP exceptions
    if (fpscr & BIT_3)
        OSReport(sOverflow);
    if (fpscr & BIT_4)
        OSReport(sUnderflow);
    if (fpscr & BIT_5)
        OSReport(sZeroDivision);
    if (fpscr & BIT_6)
        OSReport(sInexact);

    ctx->srr0 += 4;

    // s32 temp_r31;
    // s32 temp_r31_2;

    // temp_r31 = arg1->unk194;
    // temp_r31_2 = temp_r31 & (((temp_r31 << 0x16) & 0x3E000000) | 0x01F80000 | 0x700);
    // if (temp_r31_2 & 0x20000000)
    // {
    //     OSReport("FPE: Invalid operation: ");
    //     if (temp_r31_2 & 0x01000000)
    //     {
    //         OSReport("SNaN\n");
    //     }
    //     if (temp_r31_2 & 0x800000)
    //     {
    //         OSReport("Infinity - Infinity\n");
    //     }
    //     if (temp_r31_2 & 0x400000)
    //     {
    //         OSReport("Infinity / Infinity\n");
    //     }
    //     if (temp_r31_2 & 0x200000)
    //     {
    //         OSReport("0 / 0\n");
    //     }
    //     if (temp_r31_2 & 0x100000)
    //     {
    //         OSReport("Infinity * 0\n");
    //     }
    //     if (temp_r31_2 & 0x80000)
    //     {
    //         OSReport("Invalid compare\n");
    //     }
    //     if (temp_r31_2 & 0x400)
    //     {
    //         OSReport("Software request\n");
    //     }
    //     if (temp_r31_2 & 0x200)
    //     {
    //         OSReport("Invalid square root\n");
    //     }
    //     if (temp_r31_2 & 0x100)
    //     {
    //         OSReport("Invalid integer convert\n");
    //     }
    // }
    // if (temp_r31_2 & 0x10000000)
    // {
    //     OSReport("FPE: Overflow\n");
    // }
    // if (temp_r31_2 & 0x08000000)
    // {
    //     OSReport("FPE: Underflow\n");
    // }
    // if (temp_r31_2 & 0x04000000)
    // {
    //     OSReport("FPE: Zero division\n");
    // }
    // if (temp_r31_2 & 0x02000000)
    // {
    //     OSReport("FPE: Inexact result\n");
    // }
    // arg1->unk198 += 4;
}

/**
 * Offset/Address/Size: 0x0 | 0x801ACC94 | size: 0x38
 */
void InstallFloatingPointExceptionHandler()
{
    __OSFpscrEnableBits = 0x31F80210;
    OSSetErrorHandler((unsigned short)0x10, (OSErrorHandler)FloatingPointErrorHandler);
}
