#include "victory_screen.h"
#include <glm/glm.hpp>
#include "resource_manager.h"

VictoryScreen::VictoryScreen() {}

VictoryScreen::VictoryScreen(int Width, int Height)
{
    glm::vec2 size = {Width * 1.0, Height * 1.0};
    //glm::vec2 pos = {(Width - size.x)/2, (Height - size.y) / 2};
    glm::vec2 pos = {0.0f, 0.0f};
    Texture2D texture = ResourceManager::GetTexture("win");
    glm::vec3 color = {1.0f, 1.0f, 1.0f};
    GameObject winScreen(pos, size, texture, color);
    //this->VictoryText = GameObject(pos, size, texture, color); 
    this->VictoryTexts.push_back(winScreen);
    
}

void VictoryScreen::Draw(SpriteRenderer &renderer) 
{
    this->VictoryTexts[0].Draw(renderer);
}

VictoryScreen::~VictoryScreen()
{
}