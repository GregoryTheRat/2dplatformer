#include "player_object.h"
#include "GLFW/glfw3.h"

PlayerObject::PlayerObject()
    : GameObject(), Health(3), BoostFrames(0), Stuck(false), Jumped(false) {}

PlayerObject::PlayerObject(glm::vec2 pos, glm::vec2 size, unsigned int health, Texture2D sprite)
    : GameObject(pos, size, sprite, glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2 (0.0f, 0.0f)), Health(health), BoostFrames(0), Stuck(false), Jumped(false) {}

glm::vec2 PlayerObject::Move(float dt) 
{
    if (!this->Stuck)
    {
        glm::vec2 revYVelocity(this->Velocity.x, this->Velocity.y * -1.0f);
        this->Position += revYVelocity * dt;
        if (Jumped)
        {
            double t = glfwGetTime() - this->JumpStartT;
            //printf("time: %f ", t);
            //printf("velocity.y: %f\n", this->Velocity.y);
            this->Velocity.y = 400.0f * sin(45.0f) - (400.0f * t);

            if (this->Velocity.y <= -400.0f){
                this->Velocity.y = -400.0f;
            }
            //printf("velocity.y: %f\n", this->Velocity.y);
            printf("elapsed time: %f\n", t);
        }
    }

    return this->Position;
}

void PlayerObject::Jump() {
    if (!Jumped)
    {
        this->JumpStartT = glfwGetTime(); 
        this->Velocity.x = this->Velocity.x * cos(45.0f);    
        this->Velocity.y = 400.0f * sin(45.0f);    
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