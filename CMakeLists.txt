cmake_minimum_required(VERSION 4.0)
project(Simplex)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG        v1.16.0
)

FetchContent_MakeAvailable(spdlog)

add_library(Simplex SHARED
        src/Simplex/Core.h
        src/Simplex/Application.cpp
        src/Simplex/Application.h
        src/Simplex/EntryPoint.h
        src/Simplex.h
        src/Simplex/Log.cpp
        src/Simplex/Log.h)

target_link_libraries(Simplex PUBLIC spdlog::spdlog)


target_include_directories(Simplex PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(Simplex PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

include(GenerateExportHeader)

generate_export_header(Simplex
        BASE_NAME SIMPLEX
        EXPORT_FILE_NAME include/simplex/export.h
)

target_include_directories(Simplex PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_compile_definitions(Simplex PRIVATE "SIMPLEX_EXPORTS")




add_subdirectory(Sandbox)