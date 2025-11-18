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

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.4
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)


add_library(Simplex SHARED
        src/Simplex/Core.h
        src/Simplex/Application.cpp
        src/Simplex/Application.h
        src/Simplex/EntryPoint.h
        src/Simplex.h
        src/Simplex/Log.cpp
        src/Simplex/Log.h
        src/Simplex/Events/ApplicationEvent.h
        src/Simplex/Events/Event.h
        src/Simplex/Events/KeyEvent.h
        src/Simplex/Events/MouseEvent.h
        src/Simplex/Window.h
        src/Platform/MacOS/MacOSWindow.cpp
        src/Platform/MacOS/MacOSWindow.h
)

target_precompile_headers(Simplex PRIVATE
        src/sxpch.h
)

target_link_libraries(Simplex
        PUBLIC
            spdlog::spdlog
        PRIVATE
            glfw
            OpenGL::GL
)

target_compile_definitions(Simplex
        PRIVATE
        GL_SILENCE_DEPRECATION
)


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