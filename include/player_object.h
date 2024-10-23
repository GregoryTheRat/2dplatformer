#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "texture.h"

class PlayerObject : public GameObject 
{
public: 
    //player state vars:
    unsigned int Health;
    unsigned int BoostFrames;
    bool Stuck;

    //constructors
    PlayerObject();
    PlayerObject(glm::vec2 pos, glm::vec2 size, unsigned int health, Texture2D sprite);

    glm::vec2 Move(float dt);
    void Respawn(glm::vec2 pos);
};

#endif