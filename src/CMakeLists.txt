set(SOURCES
    game.cpp
    resource_manager.cpp
    shader.cpp
    stb_image.cpp
    texture.cpp
    sprite_renderer.cpp
    game_object.cpp
    game_level.cpp
    player_object.cpp
    pass_through_platform.cpp
    spike_platform.cpp
    level_end_platform.cpp 
    game_menu.cpp
)

add_library(GameLibrary ${SOURCES})

target_include_directories(GameLibrary 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
           ${PROJECT_SOURCE_DIR}/external/glad/include
)