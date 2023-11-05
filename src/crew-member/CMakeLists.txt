# here we create PilotLibrary that will be used by the main program and contains the pilot class
add_library(CrewMemberLibrary crewMember.hpp crewMember.cpp)

# here we specify the include directories for PilotLibrary so that the main program will be able to find the header files
target_include_directories(CrewMemberLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})