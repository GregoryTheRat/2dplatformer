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
    glm::vec2 unitSize = one.Load("../../levels/first.txt", this->Width, this->Height);
    //TODO: try to find a better way to determine player size
    glm::vec2 playerSize = {unitSize.y / 2, unitSize.x / 2};
    std::cout << unitSize[0] << " " << unitSize[1] << std::endl;
    this->Levels.push_back(one);
    this->Level = 0;

    glm::vec2 playerPos = glm::vec2(20.0f, 10.0f);
    //Player = new PlayerObject();
    //Player->Sprite = ResourceManager::GetTexture("pepe");
    //Player->Position = playerPos;
    //Player->Size = glm::vec2(50.0f, 50.0f);
    Player = new PlayerObject(playerPos, playerSize, 3, ResourceManager::GetTexture("pepe"));
}

void Game::Update(float dt)
{
    Player->Move(dt);
}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_ACTIVE)
    {
        //TODO:implement accelerating and deccelerating movement
        if (this->Keys[GLFW_KEY_D])
        {
            Player->Position.x += 1.5f;
        }

        if (this->Keys[GLFW_KEY_A])
        {
            Player->Position.x -= 1.5f;
        }

        if (this->Keys[GLFW_KEY_W])
        {
            Player->Position.y -= 1.5f;
        }

        if (this->Keys[GLFW_KEY_S])
        {
            Player->Position.y += 1.5f;
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