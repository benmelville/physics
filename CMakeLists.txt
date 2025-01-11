

cmake_minimum_required(VERSION 3.23)
project(physics)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)

# Gives bare necessities required for rendering to screen
find_package(glfw3 REQUIRED)

# provides runtime mechanisms for determining what OpenGL extensions are supported on target platform
find_package(GLEW REQUIRED)

add_executable(physics
        main.cpp)

target_link_libraries(physics OpenGL::GL glfw GLEW::GLEW)
