#ifndef __EXAMPLE_DLL_H__
#define __EXAMPLE_DLL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>

#ifdef _EXAMPLE_DLL_EXPORTS_
    #define EXAMPLE_DLL_API __declspec(dllexport)
#else
    #define EXAMPLE_DLL_API __declspec(dllimport)
#endif

#ifdef _CVI_LIB_
        #define EXAMPLE_DLL_API __cdecl
#elifdef _STATIC_LIB_
    #define EXAMPLE_DLL_API __cdecl

#endif



#endif