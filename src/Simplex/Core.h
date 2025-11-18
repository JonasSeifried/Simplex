//
// Created by Jonas Seifried on 08.11.25.
//

#ifndef SIMPLEX_CORE_H
#define SIMPLEX_CORE_H

#if defined(_WIN32) || defined(_WIN64)
    #define SX_PLATFORM_WINDOWS
#elif defined(__APPLE__)
    #define SX_PLATFORM_MACOS
#else
    #error "Simplex only supports Windows and macOS!"
#endif

#include "include/simplex/export.h"

#define BIT(x) (1 << x)

#ifdef SX_ENABLE_ASSERTS
    #define SX_ASSERT(x, ...) { if(!(x)) { SX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define SX_CORE_ASSERT(x, ...) { if(!(x)) { SX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define SX_ASSERT(x, ...)
    #define SX_CORE_ASSERT(x, ...)
#endif


#endif //SIMPLEX_CORE_H