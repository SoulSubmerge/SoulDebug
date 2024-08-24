#ifndef _TYPE_UNIT_H_
#define _TYEP_UNIT_H_

#ifdef _WIN32
    #ifdef _WIN64
        // 64-bit Windows
        namespace sdbg
        {
            typedef signed char int8;
            typedef unsigned char uint8;
            typedef signed short int16;
            typedef unsigned short uint16;
            typedef signed int int32;
            typedef unsigned int uint32;
            typedef signed long long int64;
            typedef unsigned long long uint64;
        }
    #else
        // 32-bit Windows
        namespace sdbg
        {
            typedef signed char int8;
            typedef unsigned char uint8;
            typedef signed short int16;
            typedef unsigned short uint16;
            typedef signed long int32;
            typedef unsigned long uint32;
            typedef signed long long int64;
            typedef unsigned long long uint64;
        }
    #endif
#elif __linux__
    #if defined(__x86_64__) || defined(__ppc64__)
        // 64-bit Linux
        namespace sdbg
        {
            typedef signed char int8;
            typedef unsigned char uint8;
            typedef signed short int16;
            typedef unsigned short uint16;
            typedef signed int int32;
            typedef unsigned int uint32;
            typedef signed long long int64;
            typedef unsigned long long uint64;
        }
    #else
        // 32-bit Linux
        namespace sdbg
        {
            typedef signed char int8;
            typedef unsigned char uint8;
            typedef signed short int16;
            typedef unsigned short uint16;
            typedef signed long int32;
            typedef unsigned long uint32;
            typedef signed long long int64;
            typedef unsigned long long uint64;
        }
    #endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
         // iOS Simulator
    #elif TARGET_OS_IPHONE
        // iOS device
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
        namespace sdbg
        {
            typedef signed char int8;
            typedef unsigned char uint8;
            typedef signed short int16;
            typedef unsigned short uint16;
            typedef signed int int32;
            typedef unsigned int uint32;
            typedef signed long long int64;
            typedef unsigned long long uint64;
        }
    #else
    #   error "Unknown Apple platform"
    #endif
#elif __unix__

#elif __ANDROID__

#endif

#endif