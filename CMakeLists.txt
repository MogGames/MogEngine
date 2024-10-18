cmake_minimum_required(VERSION 3.10)
project(MogEngine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE)
endif()

# Add debug symbols and optimization flags for different build types
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# OpenGL
find_package(OpenGL REQUIRED)

# GLAD
add_library(glad external/glad/glad.c)
target_include_directories(glad PUBLIC external/glad)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/glad)

# Add Sources
set(SRC
    src/main.cpp
    src/Window.cpp
    src/Renderer.cpp
)

add_executable(MogEngine ${SRC})

# Link SDL2, OpenGL, and other libs
target_link_libraries(MogEngine ${SDL2_LIBRARIES} glad ${OPENGL_LIBRARIES})
