#include "game_menu.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

const float CdTime = 0.2f;

GameMenu::GameMenu(){}

GameMenu::GameMenu(int Width, int Height)
{
    this->CooldownT = CdTime;
    float optionWidth = Width * 0.6;
    float optionHeight = Height * 0.2;
    glm::vec2 optionSize(optionWidth, optionHeight);
    float optionPosX = (Width - optionWidth) / 2;
    GameObject start(glm::vec2(optionPosX, optionHeight), glm::vec2(optionWidth, optionHeight), ResourceManager::GetTexture("startBtn"), glm::vec3(0.0f, 1.0f, 0.0f));
    GameObject quit(glm::vec2(optionPosX, start.Position.y + optionHeight * 2), glm::vec2(optionWidth, optionHeight), ResourceManager::GetTexture("exitBtn"), glm::vec3(1.0f, 1.0f, 1.0f));
    this->Options.push_back(start);
    this->Options.push_back(quit);
    this->Idx = 0;
}

GameMenu::~GameMenu()
{

}

void GameMenu::UpdateCooldown(float dt)
{
    if (this->CooldownT < CdTime)
    {
        this->CooldownT += dt;
    }
}

void GameMenu::ChangeSelectedOption(Direction direction)
{
    if (this->CooldownT < CdTime)
    {
       return;
    }

    if (direction == MENU_UP)
    {
        if (this->Idx == 0)
        {
            //prev.opt. set to red
            this->Options[this->Idx].Color = {1.0f, 1.0f, 1.0f};
            Idx = 1;
            //new current option set to green
            this->Options[this->Idx].Color = {0.0f, 1.0f, 0.0f};
        }
        else
        {
            //prev.opt. set to red
            this->Options[this->Idx].Color = {1.0f, 1.0f, 1.0f};
            Idx = 0;
            //new current option set to green
            this->Options[this->Idx].Color = {0.0f, 1.0f, 0.0f};
        }
    }

    if (direction == MENU_DOWN)
    {

    }

    this->CooldownT = 0.0f;
}

bool GameMenu::ActivateMenu()
{
    if (this->Idx == 0)
    {
        //menu action 1
        //start game
        return true;
    }
    else{
        //menu action 2
        //exit 
        glfwTerminate();
        return false;
    }
}

void GameMenu::Draw(SpriteRenderer &renderer)
{
    for (GameObject &option : this->Options)
    {
        option.Draw(renderer);
    }
}