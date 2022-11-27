file(GLOB_RECURSE SOURCES "*.c")

set(CMAKE_CXX_STANDARD 11)

add_executable(browser main.c ${SOURCES})
set_target_properties(browser PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED OFF
        CXX_EXTENSIONS OFF
)