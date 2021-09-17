cmake_minimum_required( VERSION 2.8 )

# Create Project
project(solution)


set(CMAKE_AUTOMOC ON) # For meta object compiler
set(CMAKE_AUTORCC ON) # Resource files
set(CMAKE_AUTOUIC ON)

# Set StartUp Project (Option)
# (This setting is able to enable by using CMake 3.6.0 RC1 or later.)

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT "project" )
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# Find Packages
find_package( PCL 1.8 REQUIRED )
find_package(Qt5 REQUIRED Widgets)
find_package(VTK REQUIRED)


include_directories( ${PCL_INCLUDE_DIRS} )
add_definitions( ${PCL_DEFINITIONS} )
link_directories( ${PCL_LIBRARY_DIRS} )

add_executable(${PROJECT_NAME} ./src/main.cpp ./src/pcapviewer.cpp ./src/pcapViewer.ui)
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES})

qt5_use_modules(${PROJECT_NAME} Widgets)