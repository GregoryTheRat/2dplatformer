#include "game.h"

#include <iostream>

#include "resource_manager.h"
#include "sprite_renderer.h"
#include "player_object.h"


SpriteRenderer *Renderer;
PlayerObject *Player;

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game() 
{
    delete Renderer;
}

void Game::Init()
{

    ResourceManager::LoadShader("../../shaders/sprite.vs", "../../shaders/sprite.frag", nullptr, "sprite");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    ResourceManager::LoadTexture("../../assets/img/pepe.png", true, "pepe");
    ResourceManager::LoadTexture("../../assets/img/platforms/container.png", false, "container");


    GameLevel one; 
    //levelData contains unit size and spawn point
    glm::vec4 levelData = one.Load("../../levels/first.txt", this->Width, this->Height);
    //TODO: try to find a better way to determine player size
    glm::vec2 playerSize = {levelData.y, levelData.x};
    this->Levels.push_back(one);
    this->Level = 0;

    glm::vec2 spawnPoint = {levelData.z + playerSize.x, levelData.w};
    Player = new PlayerObject(spawnPoint, playerSize, 3, ResourceManager::GetTexture("pepe"));
}

void Game::Update(float dt)
{
    Player->Move(dt);
    this->DoCollisions();
    //printf("player pos: %f, %f\n", Player->Position.x, Player->Position.y);
}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_ACTIVE)
    {
        int xDirection = 0;
        if (this->Keys[GLFW_KEY_D])
        {
            xDirection = 1;
        }
        if (this->Keys[GLFW_KEY_A])
        {
            xDirection = -1;
        }

        if (xDirection != 0)
        {
            Player->AccelerateOnX(xDirection, dt);
        }
        else 
        {
            Player->DeccelerateOnX(dt);
        }

        if (this->Keys[GLFW_KEY_W])
        {
            Player->Jump();
        }

        if (this->Keys[GLFW_KEY_LEFT_SHIFT])
        {
           Player->Dash(); 
        }
    }
}

void Game::Render()
{
    /*
    if (this->State == GAME_MENU)
    {
        //render the menu
    }
    */
   
    if (this->State == GAME_ACTIVE)
    {
        //draw background

        Player->Draw(*Renderer);
        this->Levels[this->Level].Draw(*Renderer);
    }
}

bool Game::CheckCollision(GameObject &one, GameObject &two)
{
    bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
        two.Position.x + two.Size.x >= one.Position.x;

    bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
        two.Position.y + two.Size.y >= one.Position.y;

    return collisionX && collisionY;
}

void Game::DoCollisions()
{
    bool collided = false;
    for (GameObject *platform : this->Levels[this->Level].Platforms)
    {
        if (!platform->Destroyed)
        {
            if (CheckCollision(*Player, *platform))
            {
                collided = true;
                platform->DoCollisionBehaviour(Player);
            }
        }
    }

    if (!collided)
    {
        Player->CanJump = false;
        if (!Player->Jumping)
        {
            Player->Fall();
        }
    }
}