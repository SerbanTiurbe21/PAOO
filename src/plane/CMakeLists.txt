# Create PlaneLibrary
add_library(PlaneLibrary plane.cpp plane.hpp)

# Specify include directories for PlaneLibrary
target_include_directories(PlaneLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link PlaneLibrary against PilotLibrary
target_link_libraries(PlaneLibrary PUBLIC PilotLibrary)

# Include PilotLibrary's directory for PlaneLibrary
target_include_directories(PlaneLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../pilot)