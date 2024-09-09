project(EX_FILE_FORMAT)


# Set the dir of the header file that you want to rely on.
set(EXFILEFORMAT_DEPENDENT_HEADER_LIST
    ExFileFormat
    Unit
    )
list(TRANSFORM EXFILEFORMAT_DEPENDENT_HEADER_LIST PREPEND "${CMAKE_SOURCE_DIR}/")
message("\n = = =   🚗 ExFileFormat dependent header file   = = = " )
foreach(TMP_HEADER_DIR ${EXFILEFORMAT_DEPENDENT_HEADER_LIST})
    message("   👉 " ${TMP_HEADER_DIR})
endforeach()
message("      ❤ ❤ ❤   🔚   ❤ ❤ ❤ \n" )

# Dependent header file
include_directories(${EXFILEFORMAT_DEPENDENT_HEADER_LIST})