#include "spike_platform.h"
#include "player_object.h"

SpikePlatform::SpikePlatform()
    : GameObject() {}

SpikePlatform::SpikePlatform(
    glm::vec2 pos,
    glm::vec2 size,
    Texture2D sprite,
    glm::vec3 color,
    glm::vec2 Velocity) 
        : GameObject(pos, size, sprite, color, Velocity) {}


void SpikePlatform::DoCollisionBehaviour(GameObject *otherObject)
{
    PlayerObject* player = dynamic_cast<PlayerObject*> (otherObject);

    if (player == nullptr)
    {
        return;
    }
    
    //hurt the respawn the player with -1 hp
    player->Respawn(1);
}