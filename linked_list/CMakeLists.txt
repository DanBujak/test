cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(LinkedList VERSION 1.0)

# Build with debug symbols
set(CMAKE_BUILD_TYPE Debug)

# add the executables
file(GLOB ll_demo_SRC "src/*.h" "src/*.c" )
message([STATUS] ${ll_demo_SRC})
add_executable(LL_Demo ${ll_demo_SRC})

configure_file(src/ll_config.h.in ll_config.h)

target_include_directories(LL_Demo PUBLIC "${PROJECT_BINARY_DIR}" )