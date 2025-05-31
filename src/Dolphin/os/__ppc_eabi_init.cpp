// //
// // __ppc_eabi_init
// //

// #include "dol2asm.h"
// #include "dolphin/base/PPCArch.h"

// #ifdef __cplusplus
// extern "C" {
// #endif

// //
// // Forward References:
// //

// void __init_user();
// void __init_cpp();
// void _ExitProcess();

// //
// // External References:
// //

// typedef void (*voidfunctionptr)(); // pointer to function returning void
// extern voidfunctionptr _ctors[];

// /* 80342B78-80342B98 33D4B8 0020+00 0/0 1/1 0/0 .text            __init_user */
// void __init_user(void) {
//     __init_cpp();
// }

// /* 80342B98-80342BEC 33D4D8 0054+00 1/1 0/0 0/0 .text            __init_cpp */
// #pragma peephole off
// void __init_cpp(void) {
//     /**
//      *	call static initializers
//      */
//     voidfunctionptr* constructor;
//     for (constructor = _ctors; *constructor; constructor++) {
//         (*constructor)();
//     }
// }
// #pragma peephole reset

// /* 80342BEC-80342C0C 33D52C 0020+00 0/0 2/2 0/0 .text            _ExitProcess */
// void _ExitProcess(void) {
//     PPCHalt();
// }

// #ifdef __cplusplus
// }
// #endif

#include <dolphin/base/PPCArch.h>
#include <dolphin/os/__ppc_eabi_init.h>

#ifdef __cplusplus
extern "C" {
#endif
void __OSPSInit();
void __OSFPRInit();
void __OSCacheInit();

asm void __init_hardware(void)
{
    // clang-format off
    nofralloc
    mfmsr r0
    ori r0, r0, 0x2000
    mtmsr r0

    mflr r31
    bl __OSPSInit
    bl __OSFPRInit
    bl __OSCacheInit
    mtlr r31
    blr
    // clang-format on
}

asm void __flush_cache(register void *address, register unsigned int size)
{
    // clang-format off
  nofralloc
  lis r5,  ~0
  ori r5, r5, ~14
  and r5, r5, r3
  subf r3, r5, r3
  add r4, r4, r3

loop:    
  dcbst r0, r5
  sync
  icbi r0, r5
  addic r5, r5, 8
  subic. r4, r4, 8    
  bge loop
  isync
  blr
    // clang-format on
}

void __init_user()
{
    __init_cpp();
}

typedef void (*voidfunctionptr)(void); // pointer to function returning void
__declspec(section ".init") extern voidfunctionptr _ctors[];
__declspec(section ".init") extern voidfunctionptr _dtors[];

void __init_cpp(void)
{
    voidfunctionptr *constructor;

    /*
     *	call static initializers
     */
    for (constructor = _ctors; *constructor; constructor++) {
        (*constructor)();
    }
}

void _ExitProcess(void)
{
    PPCHalt();
}

#ifdef __cplusplus
}
#endif
