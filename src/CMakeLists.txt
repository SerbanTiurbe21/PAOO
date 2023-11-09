# here we include the subdirectory containing our PlaneLibrary and PilotLibrary
add_subdirectory(crew-member)
add_subdirectory(military-plane)
add_subdirectory(pilot)
add_subdirectory(plane)
add_subdirectory(copilot)
add_subdirectory(utilities)

# here we create an executable target
add_executable(MyExecutable main.cpp)

# here we link PlaneLibrary and PilotLibrary to the executable
target_link_libraries(MyExecutable PRIVATE PlaneLibrary PilotLibrary MilitaryPlaneLibrary CrewMemberLibrary CopilotLibrary)

# here we include the plane directory and pilot directory so that plane.hpp and pilot.hpp can be found
target_include_directories(MyExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/plane)
target_include_directories(MyExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/pilot)
target_include_directories(MyExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/military-plane)
target_include_directories(MyExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/crew-member)
target_include_directories(MyExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/copilot)
target_include_directories(MyExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/utilities)