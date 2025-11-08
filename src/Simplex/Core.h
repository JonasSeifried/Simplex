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

#endif //SIMPLEX_CORE_H