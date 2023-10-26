# Create PlaneLibrary
add_library(PlaneLibrary plane.cpp plane.hpp)

# Specify include directories for PlaneLibrary
target_include_directories(PlaneLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
