#include "game.h"

#include "resource_manager.h"
#include "sprite_renderer.h"


SpriteRenderer *Renderer;

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

    GameLevel one; one.Load("../../levels/first.txt", this->Width, this->Height / 2);
    this->Levels.push_back(one);
    this->Level = 0;
}

void Game::Update(float dt)
{
}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{
    if (this->State == GAME_ACTIVE)
    {
        //draw background

        this->Levels[this->Level].Draw(*Renderer);
    }
}