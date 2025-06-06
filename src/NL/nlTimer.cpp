#include "NL/nlTimer.h"

#include "PowerPC_EABI_Support/Runtime/runtime.h"

float unk_168 = 0.5f;
float unk_169 = 1024.f;
float unk_170 = 0.0009765625;
double unk_172 = 4503599627370496;

/**
 * Offset/Address/Size: 0x0 | 0x80212F6C | size: 0xB8
 */
u32 Timer::Countup(float param_1, float param_2)
{
    _unk_0x0 = (u32) ((f32) _unk_0x0 + (f32) (u32) ((unk_169 * param_1) + unk_168));
    return ((u32) _unk_0x0 >> 0x1DU) & 1;
}

/**
 * Offset/Address/Size: 0xB8 | 0x80213024 | size: 0xB8
 */
u32 Timer::Countdown(float arg8, float arg9)
{
        u32 temp_r31;
    u32 temp_r3;

    temp_r31 = _unk_0x0;
    if (temp_r31 != 0) {
        temp_r3 = (u32) ((unk_169 * arg8) + unk_168);
        if (temp_r3 > temp_r31) {
            _unk_0x0 = 0;
        } else {
            _unk_0x0 = temp_r31 - temp_r3;
        }
        // M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        // return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
        return ((u32) _unk_0x0 >> 0x1DU) & 1;
    }

    return 1;
}

/**
 * Offset/Address/Size: 0x170 | 0x802130DC | size: 0x30
 */
f32 Timer::GetSeconds() const
{
      return (double)((_unk_0x4 - unk_172) * unk_170);

    // return (f32) *arg0 * unk_170;
    // return (f32)(_unk_0x8 * _unk_0x4);
}

/**
 * Offset/Address/Size: 0x1A0 | 0x8021310C | size: 0x3C
 */
void Timer::SetSeconds(float param_1)
{
    long uVar1;
    uVar1 = __cvt_fp2unsigned((double)(unk_169 * param_1 + unk_168));
    _unk_0x0 = uVar1;
    // *(undefined4 *)this = uVar1;
//   return;
}
