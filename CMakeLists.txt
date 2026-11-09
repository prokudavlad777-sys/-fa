cmake_minimum_required(VERSION 3.20)
project(RustAim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Для Windows
if(WIN32)
    add_compile_definitions(WIN32_LEAN_AND_MEAN NOMINMAX)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
endif()

add_executable(RustAim 
    main.cpp
    Aimbot.cpp
)

target_include_directories(RustAim PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
