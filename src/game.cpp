#include "game.h"

#include <iostream>
#include "resource_manager.h"
#include "sprite_renderer.h"
#include "player_object.h"
#include "sound.h"

SpriteRenderer *Renderer;
PlayerObject *Player;

#define DEBUG 0

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_MENU), Keys(), Width(width), Height(height), MainMenu(), WinScreen()
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
    //buttons
    ResourceManager::LoadTexture("../../assets/img/start.png", true, "startBtn");
    ResourceManager::LoadTexture("../../assets/img/exit.png", true, "exitBtn");
    //win screen
    ResourceManager::LoadTexture("../../assets/img/win.png", false, "win");

    this->MainMenu = GameMenu(this->Width, this->Height);
    this->WinScreen = VictoryScreen(this->Width, this->Height);

    GameLevel one; 
    GameLevel two;
    GameLevel three;
    //levelData contains unit size, spawn point and levelEnd coords
    // 73.846153, 72.000000
    glm::vec2 levelData = one.Load("../../levels/one.txt", this->Width, this->Height);
    two.Load("../../levels/two.txt", this->Width, this->Height); 
    three.Load("../../levels/three.txt", this->Width, this->Height);
    //TODO: try to find a better way to determine player size
    glm::vec2 playerSize = {levelData.y, levelData.x};
    this->Levels.push_back(one);
    this->Levels.push_back(two);
    this->Levels.push_back(three);
    this->Level = 0;
    
    glm::vec2 spawnPoint = this->Levels[this->Level].SpawnPoint;
    Player = new PlayerObject(spawnPoint, playerSize, 3, ResourceManager::GetTexture("pepe"));

    Sound::Init();
    Sound::StartBgMusic();
}

void Game::Update(float dt)
{
    if (Player->Health == 0)
    {
        this->State = GAME_MENU;
        this->Level = 0;
    }

    if (this->State == GAME_ACTIVE)
    {
        Player->Move(dt);
        this->DoCollisions();
    }

    if (this->State == GAME_MENU)
    {
        //update game menu action cooldown
        MainMenu.UpdateCooldown(dt);
    }
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

    //menu navigation
    if (this->State == GAME_MENU)
    {
        if (this->Keys[GLFW_KEY_W])
        {
            this->MainMenu.ChangeSelectedOption(MENU_UP);
        }
        //since MainMenu only has 2 options for now just do the same for KEY_S
        if (this->Keys[GLFW_KEY_S])
        {
            this->MainMenu.ChangeSelectedOption(MENU_UP);
        }

        if (this->Keys[GLFW_KEY_ENTER])
        {
            //if true then start game
            if (this->MainMenu.ActivateMenu())
            {
                this->State = GAME_ACTIVE;
                Player->Health = 3;
            }
        }
    }
}

void Game::Render()
{
    if (this->State == GAME_MENU)
    {
        //render the menu
        this->MainMenu.Draw(*Renderer);
    }
   
    if (this->State == GAME_ACTIVE)
    {
        //draw background

        if (DEBUG)
        {
            this->Levels[this->Level].PartitionGrid.Draw(*Renderer);
        }

        this->Levels[this->Level].Draw(*Renderer);
        Player->Draw(*Renderer);
    }

    if (this->State == GAME_WIN)
    {
        this->WinScreen.Draw(*Renderer);
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

    //testing grid based partitioning
    std::unordered_set<std::shared_ptr<GameObject>> platformsInCell = this->Levels[this->Level].PartitionGrid.QueryGrid(Player->Position, Player->Size);

    for(const auto& platform : platformsInCell)
    {
        if (CheckCollision(*Player, *platform))
        {
            //TODO: move this into the collision behavior of the LevelEndPlatform. needs a pointer to the current level
            glm::vec2 levelEnd = this->Levels[this->Level].LevelEnd;
            if (platform->Position.x == levelEnd.x &&
                platform->Position.y == levelEnd.y)
            {
                this->Level++;
                if (this->Level == this->Levels.size())
                {
                    this->State = GAME_WIN;
                    return;
                }
                Player->SpawnPoint = this->Levels[this->Level].SpawnPoint;
                Player->Respawn(0);
                return;
            }

            collided = true;
            platform->DoCollisionBehaviour(Player);
        }
    }

    //-------------------------------
    /*
    for (const auto& platform : this->Levels[this->Level].Platforms)
    {
        if (!platform->Destroyed)
        {
            if (CheckCollision(*Player, *platform))
            {
                //TODO: move this into the collision behavior of the LevelEndPlatform. needs a pointer to the current level
                glm::vec2 levelEnd = this->Levels[this->Level].LevelEnd;
                if (platform->Position.x == levelEnd.x &&
                    platform->Position.y == levelEnd.y)
                {
                    this->Level++;
                    if (this->Level == this->Levels.size())
                    {
                        this->State = GAME_WIN;
                        return;
                    }
                    Player->SpawnPoint = this->Levels[this->Level].SpawnPoint;
                    Player->Respawn(0);
                    return;
                }

                collided = true;
                platform->DoCollisionBehaviour(Player);
            }
        }
    }*/

    if (!collided)
    {
        Player->CanJump = false;
        if (!Player->Jumping)
        {
            Player->Fall();
        }
    }
}