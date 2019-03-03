find_path(OpenFST_INCLUDE_DIR fst/fstlib.h)

find_library(OpenFST_LIBRARY
        NAMES libfst.a libfst.so libfst.dylib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OpenFST DEFAULT_MSG OpenFST_INCLUDE_DIR OpenFST_LIBRARY)

mark_as_advanced(OpenFST_INCLUDE_DIR OpenFST_LIBRARY)

if (OpenFST_FOUND)
    set(OpenFST_LIBRARIES "${OpenFST_LIBRARY}")
    set(OpenFST_INCLUDE_DIRS "${OpenFST_INCLUDE_DIR}")
endif ()