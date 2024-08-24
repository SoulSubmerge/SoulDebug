cmake_minimum_required(VERSION 3.21)
message("\n = = =   🚗   = = = " )
message("      ❤ ❤ ❤   🔚   ❤ ❤ ❤ \n" )
message("   👉 ")

# Set compiler. Note: This must be set before project.
find_program(GCC_PATH NAMES "gcc")
find_program(GPP_PATH NAMES "g++")
find_program(CPP_PATH NAMES "c++")

message("\n = = =   🚗 compiler path   = = = ")
message("   👉 GCC Path = " ${GCC_PATH})
message("   👉 G++ Path = " ${GPP_PATH})
message("   👉 C++ Path = " ${CPP_PATH})
message("      ❤ ❤ ❤   🔚   ❤ ❤ ❤ \n" )

if(WIN32)
    SET(CMAKE_C_COMPILER "${GCC_PATH}")
    SET(CMAKE_CXX_COMPILER "${CPP_PATH}")
    SET(CMAKE_ASM_COMPILER "${GCC_PATH}")
else()
    SET(CMAKE_C_COMPILER "${GCC_PATH}")
    SET(CMAKE_CXX_COMPILER "${GPP_PATH}")
    SET(CMAKE_ASM_COMPILER "${GCC_PATH}")
endif()


project(SOUL_DEBUG)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# set the C/C++ standard
set(USE_STANDARD "c++20")

# The user specifies the parameters manually
option(ENABLE_DEBUG "The build type of the program to execute.(ON:Debug/OFF:Release)" ON)
option(ENABLE_STATIC "Executable programs enable static linking.(ON/OFF)" ON)
option(ENABLE_X64 "64-bit target platform.(ON/OFF)" ON)

# display setting params
message("\n = = =   🚗 Related setting information   = = =")
message("   👉 ENABLE_DEBUG = " ${ENABLE_DEBUG})
message("   👉 ENABLE_STATIC = " ${ENABLE_STATIC})
message("   👉 ENABLE_X64 = " ${ENABLE_X64})
message("       ❤ ❤ ❤   🔚   ❤ ❤ ❤ \n" )

# Set target platform to x64 by default.
if(ENABLE_X64)
    add_definitions(-DENABLE_X64)
    set(ADDRESS_MODEL 64)
    set(NODE_TARGET x64)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -m64")
    set(TARGET_PLATFORM "x64")
else()
    add_definitions(-DENABLE_X86)
    set(ADDRESS_MODEL 32)
    set(NODE_TARGET x86)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -m32")
    set(TARGET_PLATFORM "x86")
endif()

set(LIB_POSTFIX "")

# Set build type to debug by default.
if(ENABLE_DEBUG)
    set(CMAKE_BUILD_TYPE "Debug")
    add_definitions(-DENABLE_DEBUG)
    set(LIB_POSTFIX "d")
else()
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Compile option for C/C++
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -std=${USE_STANDARD}")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -Werror -Wall -std=${USE_STANDARD}")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG -Werror -Wall")


if(ENABLE_STATIC)
    set(BUILD_SHARED_LIBS OFF) # The global setting generates static libraries by default
    # Set the link static library
    set(CMAKE_EXE_LINKER_FLAGS "-static")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
else()
    set(BUILD_SHARED_LIBS ON) # The global setting generates shared libraries by default
endif()

# Create output directory
set(RESULT_OUTPUT_DIR ${PROJECT_BINARY_DIR}/${TARGET_PLATFORM}/${CMAKE_BUILD_TYPE})
file(MAKE_DIRECTORY ${RESULT_OUTPUT_DIR})

# Set the target path to save the results of the build.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${RESULT_OUTPUT_DIR}) # set lib folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RESULT_OUTPUT_DIR}) # set dll folder
set(EXECUTABLE_OUTPUT_PATH ${RESULT_OUTPUT_DIR}) # set bin folder


# add subproject
add_subdirectory(
    SoulDebug
    ExFileFormat
    )