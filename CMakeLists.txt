cmake_minimum_required(VERSION 3.21)
project(SOUL_DEBUG)

option(DEBUG_FLAG "Enable debug mode." ON)

if(DEBUG_FLAG)
    set(CMAKE_CXX_FLAGS "-g -O0 -Wall -std=c++20")
else()
    set(CMAKE_CXX_FLAGS "-O2 -Werror -Wall -std=c++20")
endif()

add_subdirectory(SoulDebug)


SET(CMAKE_C_COMPTLER gcc)
SET(CMAKE_CXX_COMPTLER g++)
SET(CMAKE_ASM_COMPTLER gcc)