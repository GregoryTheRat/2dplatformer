#include "level_end_platform.h"
#include "player_object.h"

LevelEndPlatform::LevelEndPlatform()
    : GameObject() {}

LevelEndPlatform::LevelEndPlatform(
    glm::vec2 pos,
    glm::vec2 size,
    Texture2D sprite, 
    glm::vec3 color,
    glm::vec2 velocity)
        : GameObject(pos, size, sprite, color, velocity) {}

void LevelEndPlatform::DoCollisionBehaviour(GameObject *otherObject)
{
    PlayerObject* player = dynamic_cast<PlayerObject*> (otherObject);

    if (player == nullptr)
    {
        return;
    }


    //end current level, load next one

}