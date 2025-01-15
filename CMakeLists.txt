
# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(default_project)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(/usr/local/include)

# Link directories
link_directories(/usr/local/lib)

# Add the executable
add_executable(default default.cpp)

# Link libraries
target_link_libraries(default muparser)
