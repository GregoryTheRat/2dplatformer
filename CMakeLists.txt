cmake_minimum_required(VERSION 3.22.1)

project(2DPLATFORMER)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(external/glfw)
add_subdirectory(external/glad)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    PUBLIC external/glad/include)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
    PRIVATE external/glad/src)

target_link_libraries(${PROJECT_NAME} glfw glad)