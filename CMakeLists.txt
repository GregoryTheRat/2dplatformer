cmake_minimum_required(VERSION 3.22.1)

project(2DPLATFORMER)

add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(src)

add_executable(Game main.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2_mixer REQUIRED) #libsdl2-dev libsdl2-mixer-dev

target_include_directories(Game
    PUBLIC external/glfw/include
    PUBLIC external/glad/include
    PUBLIC external/glm
    PUBLIC include
    PRIVATE ${SDL2_INCLUDE_DIRS} 
            ${SDL2_MIXER_INCLUDE_DIRS}
)


target_link_libraries(Game glfw glad GameLibrary ${SDL2_LIBRARIES} ${SDL2_MIXER_LIBRARIES})

