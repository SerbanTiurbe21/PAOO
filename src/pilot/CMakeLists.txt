# here we create PilotLibrary that will be used by the main program and contains the pilot class
add_library(PilotLibrary pilot.cpp pilot.hpp)

# here we specify the include directories for PilotLibrary so that the main program will be able to find the header files
target_include_directories(PilotLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# here we link PilotLibrary against CrewMemberLibrary (which is a dependency) so that PilotLibrary can use CrewMemberLibrary's functions
target_link_libraries(PilotLibrary PUBLIC CrewMemberLibrary)

# here we include PilotLibrary's directory for PilotLibrary so that PilotLibrary can use CrewMemberLibrary's headers
target_include_directories(PilotLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../crew-member)