#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "game_object.h"

class PlayerObject : public GameObject 
{
public: 
    //player state vars:
    unsigned int Health;
    bool Stuck;
    bool CanJump;
    bool Jumping;
    bool CanDash;
    bool Dashing;
    float JumpStartT;
    float AccelerationT;
    float DashT;
    float DashCooldownT;
    glm::vec2 SpawnPoint;

    //constructors
    PlayerObject();
    PlayerObject(glm::vec2 pos, glm::vec2 size, unsigned int health, Texture2D sprite);

    void Jump();
    void Fall();
    //1 for x+ direction(right), -1 for -x direction(left)
    void AccelerateOnX(int direction, float dt);
    void DeccelerateOnX(float dt);
    void Dash();

    glm::vec2 Move(float dt);
    void Respawn(int dmg);

private:
    void CalcYJumpVelocity();
    void CalcDash(float dt);
};

#endif