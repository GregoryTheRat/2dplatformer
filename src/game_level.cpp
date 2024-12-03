#include "game_level.h"

#include "pass_through_platform.h"
#include "spike_platform.h"
#include "level_end_platform.h"

#include <fstream>
#include <sstream>

/// @brief 
/// @param tileData 
/// @param lvlWidth 
/// @param lvlHeight 
/// @return loads level from file, returns the calculated unit size and spawn point.
glm::vec2 GameLevel::Load(const char *file, unsigned int levelWidth, unsigned int levelHeight)
{
    // clear old data
    this->Platforms.clear();
    // load from file
    unsigned int tileCode;
    GameLevel level;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<unsigned int>> tileData;
    if (fstream)
    {
        while (std::getline(fstream, line)) // read each line from level file
        {
            std::istringstream sstream(line);
            std::vector<unsigned int> row;
            while (sstream >> tileCode) // read each word separated by spaces
                row.push_back(tileCode);
            tileData.push_back(row);
        }
        if (tileData.size() > 0)
        {
            glm::vec2 unit_size = this->init(tileData, levelWidth, levelHeight);
            return unit_size;
        }
    }
    return glm::vec2 {0.0f, 0.0f};
}

/// @brief 
/// @param tileData 
/// @param lvlWidth 
/// @param lvlHeight 
/// @return returns the calculated unit size based on the window and the amount of tiles.
glm::vec2 GameLevel::init(std::vector<std::vector<unsigned int>> tileData, 
                     unsigned int lvlWidth, unsigned int lvlHeight)
{
    // calculate dimensions
    unsigned int height = tileData.size();
    unsigned int width  = tileData[0].size();
    float unit_width    = lvlWidth / static_cast<float>(width);
    float unit_height   = lvlHeight / height;
    // initialize level tiles based on tileData		
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            // check block type from level data (2D level array)
            if (tileData[y][x] == 1) // solid
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                std::shared_ptr<GameObject> obj = std::make_shared<GameObject>(
                    pos,
                    size, 
                    ResourceManager::GetTexture("container"), 
                    glm::vec3(1.0f, 1.0f, 1.0f)
                );
                obj->IsSolid = true;
                this->Platforms.push_back(obj);
                this->PartitionGrid.AddObjectToGrid(obj);
            }

            if (tileData[y][x] == 2) 
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                std::shared_ptr<PassThroughPlatform> obj = std::make_shared<PassThroughPlatform>(
                    pos,
                    size, 
                    ResourceManager::GetTexture("container"), 
                    glm::vec3(0.3f, 0.3f, 0.3f)
                );
                obj->IsSolid = true;
                this->Platforms.push_back(obj);
                this->PartitionGrid.AddObjectToGrid(obj);
            }

            if (tileData[y][x] == 3) 
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                std::shared_ptr<SpikePlatform> obj = std::make_shared<SpikePlatform>(
                    pos,
                    size, 
                    ResourceManager::GetTexture("container"), 
                    glm::vec3(1.0f, 0.0f, 0.0f)
                );
                obj->IsSolid = true;
                this->Platforms.push_back(obj);
                this->PartitionGrid.AddObjectToGrid(obj);
            }

            if (tileData[y][x] == 8) 
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                std::shared_ptr<LevelEndPlatform> obj = std::make_shared<LevelEndPlatform>(
                    pos,
                    size, 
                    ResourceManager::GetTexture("container"), 
                    glm::vec3(0.0f, 1.0f, 0.0f)
                );
                obj->IsSolid = true;
                this->Platforms.push_back(obj);
                this->PartitionGrid.AddObjectToGrid(obj);
                this->LevelEnd = {pos.x, pos.y};
            }

            if (tileData[y][x] == 9)
            {
               this->SpawnPoint = {unit_width * x, unit_height * y}; 
            }
        }
    }  

    return glm::vec2 {unit_width, unit_height};
}

void GameLevel::Draw(SpriteRenderer &renderer)
{
    for (const auto& tile : this->Platforms)
        if (!tile->Destroyed)
            tile->Draw(renderer);
}

bool GameLevel::IsCompleted()
{
    return false;
}

GameLevel::~GameLevel()
{
}