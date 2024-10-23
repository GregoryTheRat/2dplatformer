#include "player_object.h"

PlayerObject::PlayerObject()
    : GameObject(), Health(3), BoostFrames(0), Stuck(false) {}

PlayerObject::PlayerObject(glm::vec2 pos, glm::vec2 size, unsigned int health, Texture2D sprite)
    : GameObject(pos, size, sprite, glm::vec3(1.0f, 0.5f, 0.5f), glm::vec2 (0.0f, 0.0f)), Health(health), BoostFrames(0), Stuck(false) {}

glm::vec2 PlayerObject::Move(float dt) 
{
    if (!this->Stuck)
    {
        this->Position += this->Velocity * dt;
    }

    return this->Position;
}

void PlayerObject::Respawn(glm::vec2 pos) {
    this->Position = pos;
    this->Velocity = glm::vec2(0.0f, 0.0f);
    this->Health = 3;
    this->BoostFrames = 0;
    this->Stuck = false;
}