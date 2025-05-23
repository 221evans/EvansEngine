cmake_minimum_required(VERSION 3.16)
project(EvansEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EvansEngine EvansEngine)

# SDL3 options
set(SDL_SHARED TRUE CACHE BOOL "Build a SDL shared library" FORCE)
set(SDL_STATIC FALSE CACHE BOOL "Build a SDL static library" FORCE)
set(SDL_TEST FALSE CACHE BOOL "Build the SDL test programs" FORCE)

# Add SDL3 as a subdirectory
add_subdirectory(external/SDL3)

# SDL3_image options
set(SDL3IMAGE_SHARED TRUE CACHE BOOL "Build a SDL_image shared library" FORCE)
set(SDL3IMAGE_STATIC FALSE CACHE BOOL "Build a SDL_image static library" FORCE)
set(SDL3IMAGE_SAMPLES FALSE CACHE BOOL "Build the SDL_image sample programs" FORCE)
set(SDL3IMAGE_VENDORED FALSE CACHE BOOL "Use vendored third-party libraries" FORCE)

# SDL3_image needs to know where to find SDL3
set(SDL3_DIR "${CMAKE_BINARY_DIR}/external/SDL3" CACHE PATH "Path to SDL3 directory" FORCE)

# Add SDL3_image as a subdirectory
add_subdirectory(external/SDL3_image)

# Your main executable
add_executable(${EvansEngine} main.cpp
        Core/game.cpp
        Core/game.hpp
        Core/Entities/player.cpp
        Core/Entities/player.hpp
        Core/Entities/Animation/animation.cpp
        Core/Entities/Animation/animation.hpp
        Core/loadTextures.cpp
        Core/loadTextures.hpp
        Core/Entities/enemy.cpp
        Core/Entities/enemy.hpp
        Core/gem.cpp
        Core/gem.hpp
)

# Link against SDL3 and SDL3_image
target_link_libraries(EvansEngine PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)