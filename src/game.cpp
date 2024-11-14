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
    //glm::vec2 playerSize = {unitSize.y / 2, unitSize.x / 2};
    glm::vec2 playerSize = {levelData.y, levelData.x};
    this->Levels.push_back(one);
    this->Level = 0;

    glm::vec2 spawnPoint = {levelData.z, levelData.w};
    //Player = new PlayerObject();
    //Player->Sprite = ResourceManager::GetTexture("pepe");
    //Player->Position = playerPos;
    //Player->Size = glm::vec2(50.0f, 50.0f);
    Player = new PlayerObject(spawnPoint, playerSize, 3, ResourceManager::GetTexture("pepe"));
    Player->Velocity = {0.0f, -400.0f};
}

void Game::Update(float dt)
{
    Player->Move(dt);
    this->DoCollisions();
}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_ACTIVE)
    {
        //TODO:implement accelerating and deccelerating movement
        if (this->Keys[GLFW_KEY_D])
        {
            if (Player->Velocity.x < 400)
                Player->Velocity.x += 12.5f;
        }
        else 
        {
            /*
            if (Player->Velocity.x > 0)
                Player->Velocity.x -= 12.5f;
            */
        }

        if (this->Keys[GLFW_KEY_A])
        {
            if (Player->Velocity.x > -400)
                Player->Velocity.x -= 12.5f;
        }
        else 
        {
            /*
            if (Player->Velocity.x < 0)
                Player->Velocity.x += 15.0f;
            */
        }

        if (this->Keys[GLFW_KEY_W])
        {
            Player->Jump();
        }
    }
}

void Game::Render()
{
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
    for (GameObject &platform : this->Levels[this->Level].Platforms)
    {
        if (!platform.Destroyed)
        {
            if (CheckCollision(*Player, platform))
            {
                //TODO: depending on the type of platform, there should be different effects
                
                //check if platform is above/below, or to the right/left, or both
                
                //TODO: fix this, janky as hell, doesnt work.
                //solution: probably vectors and angles?

                float overlapX = std::min((Player->Position.x + Player->Size.x), (platform.Position.x + platform.Size.x)) 
                    - std::max(Player->Position.x, platform.Position.x);
                float overlapY = std::min((Player->Position.y + Player->Size.y), (platform.Position.y + platform.Size.y)) 
                    - std::max(Player->Position.y, platform.Position.y);

                if (overlapX < overlapY)
                {
                    if (Player->Position.x > platform.Position.x)
                    {
                        Player->Position.x += overlapX;
                    }
                    else
                    {
                        Player->Position.x -= overlapX;
                    }
                }
                else if (overlapY < overlapX) 
                {
                    if (Player->Position.y < platform.Position.y)
                    {
                        Player->Position.y -= overlapY;
                    }
                    else
                    {
                        Player->Position.y += overlapY;
                    }
                }
            }
        }
    }
}