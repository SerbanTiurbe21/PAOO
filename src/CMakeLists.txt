# Include the subdirectory containing our PlaneLibrary
add_subdirectory(pilot)
add_subdirectory(plane)

# Create an executable target
add_executable(MyExecutable main.cpp)

# Link PlaneLibrary to the executable
target_link_libraries(MyExecutable PRIVATE PlaneLibrary PilotLibrary)
# target_link_libraries(MyExecutable PRIVATE PilotLibrary)

# Include the plane directory so that plane.hpp can be found
target_include_directories(MyExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/plane)
target_include_directories(MyExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/pilot)