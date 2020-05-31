cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(QuickSort VERSION 1.0)

# Build with debug symbols
set(CMAKE_BUILD_TYPE Debug)

# add the executables
file(GLOB qs_demo_SRC "src/*.h" "src/*.c" )
message([STATUS] ${qs_demo_SRC})
add_executable(QS_Demo ${qs_demo_SRC})

configure_file(src/qs_config.h.in qs_config.h)

target_include_directories(QS_Demo PUBLIC "${PROJECT_BINARY_DIR}" )