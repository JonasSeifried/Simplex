//
// Created by Jonas Seifried on 08.11.25.
//

#pragma once

#include <memory>

#include "include/simplex/export.h"
#include "spdlog/logger.h"

namespace Simplex {
    class SIMPLEX_EXPORT Log {
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    };
} // Simplex


#if !defined(NDEBUG) || defined(SX_LOG)
    #define SX_CORE_ERROR(...)  ::Simplex::Log::GetCoreLogger()->error(__VA_ARGS__)
    #define SX_CORE_WARN(...)   ::Simplex::Log::GetCoreLogger()->warn(__VA_ARGS__)
    #define SX_CORE_INFO(...)   ::Simplex::Log::GetCoreLogger()->info(__VA_ARGS__)
    #define SX_CORE_TRACE(...)  ::Simplex::Log::GetCoreLogger()->trace(__VA_ARGS__)
    #define SX_CORE_FATAL(...)  ::Simplex::Log::GetCoreLogger()->fatal(__VA_ARGS__)

    #define SX_ERROR(...)       ::Simplex::Log::GetClientLogger()->error(__VA_ARGS__)
    #define SX_WARN(...)        ::Simplex::Log::GetClientLogger()->warn(__VA_ARGS__)
    #define SX_INFO(...)        ::Simplex::Log::GetClientLogger()->info(__VA_ARGS__)
    #define SX_TRACE(...)       ::Simplex::Log::GetClientLogger()->trace(__VA_ARGS__)
    #define SX_FATAL(...)       ::Simplex::Log::GetClientLogger()->fatal(__VA_ARGS__)
#else
    #define SX_CORE_ERROR(...)
    #define SX_CORE_WARN(...)
    #define SX_CORE_INFO(...)
    #define SX_CORE_TRACE(...)
    #define SX_CORE_FATAL(...)
    #define SX_ERROR(...)
    #define SX_WARN(...)
    #define SX_INFO(...)
    #define SX_TRACE(...)
    #define SX_FATAL(...)
#endif