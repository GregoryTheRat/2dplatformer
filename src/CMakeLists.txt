set(SOURCES
    game.cpp
    resource_manager.cpp
    shader.cpp
    stb_image.cpp
    texture.cpp
)

add_library(GameLibrary ${SOURCES})

target_include_directories(GameLibrary 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
           ${PROJECT_SOURCE_DIR}/external/glad/include
)