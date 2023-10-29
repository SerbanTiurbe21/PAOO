cmake_minimum_required(VERSION 3.1.0)

# Set the project name and version
project(MyProject VERSION 1.0)

# Include sub-projects (i.e., src/)
add_subdirectory(src)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
