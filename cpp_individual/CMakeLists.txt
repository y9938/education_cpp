# CMake settings
cmake_minimum_required(VERSION 3.22)
project(project LANGUAGES CXX)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings
add_compile_options(-Wall -Wextra -Wpedantic)

# Source files
file(GLOB SOURCES "*.cpp")

# Targets
foreach(source_file ${SOURCES})
    get_filename_component(program_name ${source_file} NAME_WE)
    add_executable(${program_name} ${source_file})
endforeach()
