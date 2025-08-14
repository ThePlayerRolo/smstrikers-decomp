#include "feTweenFuncs.h"

#include "math.h"
#include "NL/nlMath.h"

/**
 * Offset/Address/Size: 0x0 | 0x800A2EC4 | size: 0x10
 */
float TweenFunctions::linear(float arg0, float arg1, float arg2, float arg3)
{
    return arg1 + ((arg2 * arg0) / arg3);
}

/**
 * Offset/Address/Size: 0x10 | 0x800A2ED4 | size: 0xF4
 */
float TweenFunctions::easeoutelastic(float arg0, float arg1, float arg2, float arg3)
{
    f32 temp_f28;
    f32 temp_f3;
    f64 temp_f30;

    if (arg0 == 0.0f)
    {
        return arg1;
    }
    temp_f28 = arg0 / arg3;
    if (temp_f28 == 1.0f)
    {
        return arg1 + arg2;
    }

    temp_f3 = 0.3 * arg3;
    temp_f30 = nlSin((u16)(s32)(10430.378f * ((6.2831855f * ((temp_f28 * arg3) - (temp_f3 * 0.25f))) / temp_f3)));
    return (f32)((f64)arg1 + (((f64)arg2 * (float)pow(2.0, -10.0f * temp_f28) * temp_f30) + (f64)arg2));
}

/**
 * Offset/Address/Size: 0x104 | 0x800A2FC8 | size: 0xF4
 */
float TweenFunctions::easeinelastic(float arg0, float arg1, float arg2, float arg3)
{
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f3;
    f64 temp_f31;

    if (arg0 == 0.0f)
    {
        return arg1;
    }
    temp_f28_2 = arg0 / arg3;
    if (temp_f28_2 == 1.0f)
    {
        return arg1 + arg2;
    }
    temp_f28 = temp_f28_2 - 1.0f;
    temp_f3 = (f32)(0.3 * (f64)arg3);
    temp_f31 = nlSin((u16)(s32)(10430.378f * ((6.2831855f * ((temp_f28 * arg3) - (temp_f3 * 0.25f))) / temp_f3)));
    return (f32) - (((f64)arg2 * pow(2.0, 10.0f * temp_f28) * temp_f31) - (f64)arg1);
}
