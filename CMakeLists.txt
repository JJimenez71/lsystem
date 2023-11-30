# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(LSystem)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Locate raylib
find_package(raylib 3.0 REQUIRED)

# Add the executable
add_executable(MyExecutable lsystem.cpp)

# Link raylib to the executable
target_link_libraries(MyExecutable PRIVATE raylib)
