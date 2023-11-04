# here we create PilotLibrary that will be used by the main program and contains the pilot class
add_library(MilitaryPlaneLibrary militaryPlane.cpp militaryPlane.hpp)

# here we specify the include directories for PilotLibrary so that the main program will be able to find the header files
target_include_directories(MilitaryPlaneLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# here we link PlaneLibrary against PilotLibrary (which is a dependency) so that PlaneLibrary can use PilotLibrary's functions
target_link_libraries(MilitaryPlaneLibrary PUBLIC PlaneLibrary)

# here we include PilotLibrary's directory for PlaneLibrary so that PlaneLibrary can use PilotLibrary's headers
target_include_directories(MilitaryPlaneLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../plane)