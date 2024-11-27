#ifndef LEVELENDPLATFORM_H
#define LEVELENDPLATFORM_H

#include "game_object.h"


class LevelEndPlatform : public GameObject
{
public:
    LevelEndPlatform();
    LevelEndPlatform(
        glm::vec2 pos,
        glm::vec2 size,
        Texture2D sprite,
        glm::vec3 color = glm::vec3(1.0f),
        glm::vec2 Velocity = glm::vec2(0.0f, 0.0f));

    void DoCollisionBehaviour(GameObject *otherObject) override;

private:

};

#endif