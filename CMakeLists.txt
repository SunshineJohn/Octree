cmake_minimum_required(VERSION 2.8)

project(TreeLib)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCE_EXE "main.cpp")

set(HEADER_LIB "octree.h" "utils.h")
set(SOURCE_LIB "octree.cpp" "utils.cpp")

add_library(TreeLib STATIC ${SOURCE_LIB} ${HEADER_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main TreeLib)
