#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <vector>
#include <memory>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "sprite_renderer.h"
#include "resource_manager.h"

class GameLevel 
{
public:
    // level state
    std::vector<std::shared_ptr<GameObject>> Platforms;
    glm::vec2 SpawnPoint;
    glm::vec2 LevelEnd;
    // constructor
    GameLevel() { }
    ~GameLevel();
    // loads level from file, returns the calculated unit size and spawn point.
    glm::vec2 Load(const char *file, unsigned int levelWidth, unsigned int levelHeight);
    // render level
    void Draw(SpriteRenderer &renderer);
    // check if the level is completed 
    bool IsCompleted();
private:
    // initialize level from tile data
    glm::vec2 init(std::vector<std::vector<unsigned int>> tileData, 
              unsigned int levelWidth, unsigned int levelHeight);
};









#endif