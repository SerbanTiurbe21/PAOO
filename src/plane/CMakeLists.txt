# here we create the PlaneLibrary
add_library(PlaneLibrary plane.cpp plane.hpp)

# here we specify the include directories for PlaneLibrary
target_include_directories(PlaneLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# here we link PlaneLibrary against PilotLibrary (which is a dependency) so that PlaneLibrary can use PilotLibrary's functions
target_link_libraries(PlaneLibrary PUBLIC PilotLibrary FlightLogLibrary)

# here we include PilotLibrary's directory for PlaneLibrary so that PlaneLibrary can use PilotLibrary's headers
target_include_directories(PlaneLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../pilot)
target_include_directories(PlaneLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../flight-log)