cmake_minimum_required(VERSION 2.8.4)
project(RenderCylinder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(VTK_DIR "/usr/local/vtk/lib/cmake/vtk-6.1")
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

set(SOURCE_FILES RenderCylinder.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})

