#include "pass_through_platform.h"
#include "player_object.h"

PassThroughPlatform::PassThroughPlatform()
    : GameObject() {}

PassThroughPlatform::PassThroughPlatform(
    glm::vec2 pos,
    glm::vec2 size,
    Texture2D sprite,
    glm::vec3 color,
    glm::vec2 Velocity) 
        : GameObject(pos, size, sprite, color, Velocity) {}


void PassThroughPlatform::DoCollisionBehaviour(GameObject *otherObject)
{
    PlayerObject* player = dynamic_cast<PlayerObject*> (otherObject);

    if (player == nullptr)
    {
        return;
    }

    //TODO: dont let player get stuck inside, push him out left or right
    if (player->Dashing)
    {
        //let the player pass
        //extend dash so that player doesnt get stuck
        player->DashT = 0.0f;
    }
    else
    {
        //push him back like a normal wall
        GameObject::DoCollisionBehaviour(otherObject);
    }
}