#ifndef _MSL_COMMON_WCHAR_T_H
#define _MSL_COMMON_WCHAR_T_H

#if (!defined(__cplusplus))
    #ifdef __cplusplus
        extern "C" {
    #endif

    typedef unsigned short wchar_t;
    typedef wchar_t wint_t;	

    #ifdef __cplusplus
    }
    #endif
#endif

#endif // _MSL_COMMON_WCHAR_T_H
