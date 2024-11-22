#ifndef MENUOBJECT_H
#define MENUOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "texture.h"  
#include "sprite_renderer.h"


//used as the simplest platform, and every other platform type (and player) is inherited from this class
class MenuObject 
{
public:
    glm::vec2 Position, Size;
    glm::vec3 Color;
    float Rotation;
    Texture2D Sprite;

    MenuObject();
    GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f));

    virtual void DoCollisionBehaviour(GameObject *otherObject);
    virtual void Draw(SpriteRenderer &renderer);

};

#endif