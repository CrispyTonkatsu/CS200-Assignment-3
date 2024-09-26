cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cs200-assignment-3 VERSION 1)

set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})

find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(GLEW REQUIRED)

add_compile_options (-fdiagnostics-color=always)
add_compile_options(-Wextra -Wall -Wpedantic -std=c++11)

# Assignment 1
add_library(Affine Affine.cpp)
target_link_libraries(Affine PRIVATE glm::glm)

# Assignment 2
add_library(MyMesh MyMesh.cpp SquareMesh.cpp)
target_link_libraries(MyMesh PRIVATE glm::glm)

# Assignment 3
add_library(SolidRender SolidRender.cpp)
target_link_libraries(SolidRender PRIVATE glm::glm)

# Linking all to demo driver
add_executable(render-demo MeshRenderDemo.cpp)
target_link_libraries(render-demo PRIVATE SolidRender Affine MyMesh OpenGL glm::glm SDL2::SDL2 ${GLEW_LIBRARIES})
include_directories(render-demo ${GLEW_INCLUDE_DIRS})

# Linking all to test driver
add_executable(solid-test SolidRenderTest.cpp)
target_link_libraries(solid-test PRIVATE SolidRender Affine MyMesh OpenGL glm::glm SDL2::SDL2 ${GLEW_LIBRARIES})
include_directories(solid-test ${GLEW_INCLUDE_DIRS})

# vim:shiftwidth=2:
