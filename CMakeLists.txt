cmake_minimum_required(VERSION 3.10)
project(MogEngine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# OpenGL
find_package(OpenGL REQUIRED)

# Add Sources
set(SRC
    src/main.cpp
    src/Window.cpp
    src/Renderer.cpp
)

add_executable(MogEngine ${SRC})

# Link SDL2, OpenGL, and other libs
target_link_libraries(MogEngine ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
