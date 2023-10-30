cmake_minimum_required(VERSION 3.5)

# here we set the project name and version
project(MyProject VERSION 1.0)

# here we include sub-projects (i.e., src/)
add_subdirectory(src)

# here we specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)