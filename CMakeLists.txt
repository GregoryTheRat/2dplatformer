cmake_minimum_required(VERSION 3.22.1)

project(2DPLATFORMER)

add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(src)

add_executable(Game main.cpp)

target_include_directories(Game
    PUBLIC external/glfw/include
    PUBLIC external/glad/include
    PUBLIC external/glm
    PUBLIC include
)

target_link_libraries(Game glfw glad GameLibrary)

