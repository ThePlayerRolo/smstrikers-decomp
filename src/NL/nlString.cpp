#include "NL/nlString.h"

/**
 * Offset/Address/Size: 0x0 | 0x801D2638 | size: 0x48
 */
void nlStrToWcs(const char* arg0, unsigned short* arg1, unsigned long arg2)
{
    char *var_r3;
    s16 *var_r7;
    u8 temp_cr0_eq;
    u32 var_r8;
    u8 temp_r0;

    var_r3 = (char *)arg0;
    var_r8 = arg2;
    var_r7 = (s16 *)arg1;
loop_2:
    // temp_cr0_eq = var_r8 == 0;
    // var_r8 -= 1;
    // if (temp_cr0_eq != 0) {
    if (var_r8-- != 0) 
    {
        temp_r0 = *var_r3;
        *var_r7 = (s16)temp_r0;
        if (temp_r0 != 0) 
        {
            var_r7++;
            var_r3++;
            goto loop_2;
        }
    }
    arg1[arg2-1] = 0;  
}

/**
 * Offset/Address/Size: 0x48 | 0x801D2680 | size: 0x140
 */
void nlZeroMemory(void*, unsigned long)
{
}

/**
 * Offset/Address/Size: 0x188 | 0x801D27C0 | size: 0x64
 */
int nlStringLowerHash(const char* str)
{
  u8 cVar1;
  u8 uVar2;
  int iVar3;
  
  iVar3 = -1;
  while( true ) {
    if (*str == '\0') break;
    cVar1 = *str;
    str++;
    uVar2 = nlToLower<u8>(cVar1);
    iVar3 = iVar3 * 0x21 + (uVar2 & 0xff);
  }
  return iVar3;    
}

/**
 * Offset/Address/Size: 0x1EC | 0x801D2824 | size: 0x30
 */
int nlStringHash(const char* str)
{
  u8 cVar1;
  int iVar2;
  
  iVar2 = -1;
  while( true ) {
    if (*str == '\0') break;
    cVar1 = *str;
    str++;
    iVar2 = iVar2 * 0x21 + (cVar1 & 0xff);
  }
  return iVar2;
}

// /**
//  * Offset/Address/Size: 0x0 | 0x801D2854 | size: 0x20
//  */
// // void nlToLower<unsigned char>(unsigned char)
// void nlToLower(unsigned char param_1)
// {
//   if ((param_1 & 0xff) < 0x41) {
//     return param_1;
//   }
//   if (0x5a < (param_1 & 0xff)) {
//     return param_1;
//   }
//   return param_1 & 0xff | 0x20;    
// }
