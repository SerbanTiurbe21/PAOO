# here we create the PlaneLibrary
add_library(UtilitiesLibrary INTERFACE)

# here we specify the include directories for PlaneLibrary
target_include_directories(UtilitiesLibrary INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})