#include "player_object.h"
#include "GLFW/glfw3.h"

PlayerObject::PlayerObject()
    : GameObject(), Health(3), BoostFrames(0), Stuck(false), Jumped(false), CanJump(false) {}

PlayerObject::PlayerObject(glm::vec2 pos, glm::vec2 size, unsigned int health, Texture2D sprite)
    : GameObject(pos, size, sprite, glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2 (0.0f, 0.0f)), Health(health), BoostFrames(0), Stuck(false), Jumped(false), CanJump(false) {}

float jumpAngle = 45.0f;
float growthFactorOnX = 3.0f;
float decelerationFactorOnX = 6.0f; 
float maxVelocityX = 400.0f;
float maxVelocityY = 400.0f;
float gravity = 600.0f;

glm::vec2 PlayerObject::Move(float dt) 
{
    if (!this->Stuck)
    {
        if (Jumped)
        {
            CalcYJumpVelocity();
        }
        printf("player velocity x: %f, velocity y: %f\n", this->Velocity.x, this->Velocity.y);
        glm::vec2 revYVelocity(this->Velocity.x, this->Velocity.y * -1.0f);
        this->Position += revYVelocity * dt;
    }

    return this->Position;
}

void PlayerObject::AccelerateOnX(int x, float dt)
{
    // Reset acceleration time when switching directions
    if ((x > 0 && this->Velocity.x < 0) || (x < 0 && this->Velocity.x > 0)) {
        AccelerationT = 0.0f;
    }

    //update acceleration time for the exp.growth
    AccelerationT += dt;

    //QUESTION: should the player be able to change acceleration while jumping?

    //TODO?: if this->Velocity.x is already at ~399.1 (close to max velocity, maybe even sooner than that)
    //then dont do exp.calc for small changes like 399.123333 -> 399.13444444 etc. and just clamp to max?

    // Calculate velocity using exponential growth
    float velocityX = maxVelocityX * (1 - exp(-growthFactorOnX * AccelerationT));

    // Apply direction (x = 1 for right, x = -1 for left)
    this->Velocity.x = velocityX * x;
}

void PlayerObject::DeccelerateOnX(float dt)
{
    // Reset acceleration time since we're decelerating
    AccelerationT  = 0.0f;

    // Apply exponential decay
    this->Velocity.x *= exp(-decelerationFactorOnX * dt);

    // Stop completely if velocity is very small
    if (fabs(this->Velocity.x) < 0.1f) {
        this->Velocity.x = 0.0f;
    }
}

void PlayerObject::Fall()
{
    this->Velocity.y = -gravity;
}

void PlayerObject::CalcYJumpVelocity()
{
    double t = glfwGetTime() - this->JumpStartT;
    //printf("time: %f ", t);
    //printf("velocity.y: %f\n", this->Velocity.y);
    this->Velocity.y = maxVelocityY * sin(jumpAngle) - (gravity * t);

    if (this->Velocity.y <= -gravity){
        this->Velocity.y = -gravity;
    }
}

void PlayerObject::Jump() {
    if (!CanJump)
    {
        return;
    }

    if (!Jumped)
    {
        this->JumpStartT = glfwGetTime(); 
        this->Velocity.x = this->Velocity.x * cos(jumpAngle);    
        this->Velocity.y = maxVelocityY * sin(jumpAngle);    
        Jumped = true;
    }
}

void PlayerObject::Respawn(glm::vec2 pos) {
    this->Position = pos;
    this->Velocity = glm::vec2(0.0f, 0.0f);
    this->Health = 3;
    this->BoostFrames = 0;
    this->Stuck = false;
}