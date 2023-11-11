# here we create the PlaneLibrary
add_library(FlightLogLibrary flight-log.cpp flight-log.hpp)

# here we specify the include directories for PlaneLibrary
target_include_directories(FlightLogLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})