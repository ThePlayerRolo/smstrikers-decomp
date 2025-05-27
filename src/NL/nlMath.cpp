#include "types.h"

/* 
 * Calculates a Bezier curve point using input parameters and stores result in out array
 * Address: 0x801D1474, Size: 0x1D4, Scope: global 
 */
void nlBezier(float *out, int in1, float in2)
{
// todo
} 

/* 
 * Calculates the arctangent of f1/f2 (y/x) in radians
 * Address: 0x801D1648, Size: 0x244, Scope: global 
 */
void nlATan2f(float f1, float f2)
{
// todo
}

/* 
 * Calculates the tangent of an angle in degrees
 * Address: 0x801D188C, Size: 0x48, Scope: global 
 */
void nlTan(unsigned short in1)
{
// todo
}

/* 
 * Calculates the arccosine of a value in radians
 * Address: 0x801D18D4, Size: 0x12C, Scope: global 
 */
void nlACos(float in1)
{
// todo
}

/* 
 * Calculates both sine and cosine of an angle in degrees, stores results in out array
 * Address: 0x801D1A00, Size: 0x164, Scope: global 
 */
void nlSinCos(float *out, float in1, unsigned short in2)
{
// todo
}

/* 
 * Calculates the sine of an angle in degrees
 * Address: 0x801D1B64, Size: 0xA0, Scope: global 
 */
void nlSin(unsigned short in1)
{
// todo
}

/* 
 * Calculates the reciprocal of the square root (1/sqrt(x))
 * Address: 0x801D1C04, Size: 0x70, Scope: global 
 */
void nlRecipSqrt(float in1, BOOL in2)
{
// todo
}

/* 
 * Calculates the square root of a value
 * Address: 0x801D1C74, Size: 0xEC, Scope: global 
 */
void nlSqrt(float in1, BOOL in2)
{
// todo
}

/* 
 * Generates a random float between in1 and in2, stores result in out
 * Address: 0x801D1D60, Size: 0x84, Scope: global 
 */
void nlRandomf(float in1, float in2, unsigned int *out)
{
// todo
}

/* 
 * Generates a random float between 0 and in1, stores result in out
 * Address: 0x801D1DE4, Size: 0x7C, Scope: global 
 */
void nlRandomf(float in1, unsigned int *out)
{
// todo
}

/* 
 * Generates a random integer between 0 and in1, stores result in out
 * Address: 0x801D1E60, Size: 0x34, Scope: global 
 */
void nlRandom(unsigned int in1, unsigned int *out)
{
// todo
}

/* 
 * Sets the random number generator seed
 * Address: 0x801D1E94, Size: 0x2C, Scope: global 
 */
void nlSetRandomSeed(unsigned int initialSeed, unsigned int *seedStorage)
{
    unsigned int mixedValue;
    unsigned int shiftedValue;
    
    *seedStorage = initialSeed;
    
    mixedValue = *seedStorage ^ 0x1d872b41;  // Mix with constant   
    shiftedValue = mixedValue ^ (mixedValue >> 5);  // Mix with right-shifted value
    
    *seedStorage = mixedValue ^ shiftedValue ^ (shiftedValue << 0x1b);  // Final mixing
}

/* 
 * Initializes the random number generator
 * Address: 0x801D1EC0, Size: 0x24, Scope: global 
 */
void nlInitRandom()
{
// todo
}
