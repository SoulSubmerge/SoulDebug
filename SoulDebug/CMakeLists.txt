project(SDBG)


# Set the dir of the header file that you want to rely on.
set(SDEBG_DEPENDENT_HEADER_LIST
    SoulDebug
    ExFileFormat
    )
list(TRANSFORM SDEBG_DEPENDENT_HEADER_LIST PREPEND "${CMAKE_SOURCE_DIR}/")
message("\n = = =   🚗 SoulDebug dependent header file   = = = " )
foreach(TMP_HEADER_DIR ${SDEBG_DEPENDENT_HEADER_LIST})
    message("   👉 " ${TMP_HEADER_DIR})
endforeach()
message("      ❤ ❤ ❤   🔚   ❤ ❤ ❤ \n" )

# Dependent header file
include_directories(${SDEBG_DEPENDENT_HEADER_LIST})

add_executable(sdbg main.cpp)