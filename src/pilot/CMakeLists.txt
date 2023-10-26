# Create PilotLibrary
add_library(PilotLibrary pilot.cpp pilot.hpp)

# Specify include directories for PilotLibrary
target_include_directories(PilotLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})