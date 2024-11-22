#ifndef PASSTHROUGHPLATFORM_H
#define PASSTHROUGHPLATFORM_H

#include "game_object.h"

class PassThroughPlatform : public GameObject
{
private:

public:
    PassThroughPlatform();
    PassThroughPlatform(
        glm::vec2 pos,
        glm::vec2 size,
        Texture2D sprite,
        glm::vec3 color = glm::vec3(1.0f),
        glm::vec2 Velocity = glm::vec2(0.0f, 0.0f));

    void DoCollisionBehaviour(GameObject *otherObject) override;
};

#endif