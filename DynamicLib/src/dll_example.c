#include "dll_example.h"
#include "example_module/source_header.h"

//==============================================================================
// DLL main entry-point functions

// DLL main best practices here
// https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-best-practices

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
        case DLL_PROCESS_DETACH:
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
            break;
    }

    return TRUE;
}
