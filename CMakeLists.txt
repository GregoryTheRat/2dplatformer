cmake_minimum_required(VERSION 3.22.1)

project(2DPLATFORMER)

set(SOURCES src/shader_loader/shader.cpp src/resource_manager/resource_manager.cpp
            src/img_loader/stb_image.cpp src/texture_loader/texture.cpp )

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

add_subdirectory(external/glfw)
add_subdirectory(external/glad)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    PUBLIC external/glad/include
    PUBLIC src/resource_manager
    PUBLIC src/texture_loader
    PUBLIC src/shader_loader
    PUBLIC src/img_loader
    PUBLIC external/glm)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
    PRIVATE external/glad/src)

target_link_libraries(${PROJECT_NAME} glfw glad)