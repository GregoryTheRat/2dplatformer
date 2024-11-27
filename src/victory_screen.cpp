#include "victory_screen.h"
#include <glm/glm.hpp>

VictoryScreen::VictoryScreen() : VictoryText() {}

VictoryScreen::VictoryScreen(int Width, int Height)
{
    printf("in victory screen constructor");
    glm::vec2 size = {Width * 0.6, Height * 0.4};
    glm::vec2 pos = {(Width - size.x)/2, (Height - size.y)};
    Texture2D texture = ResourceManager::GetTexture("container");
    glm::vec3 color = {1.0f, 1.0f, 1.0f};
    VictoryText = GameObject(pos, size, texture, color); 
}

void VictoryScreen::Draw(SpriteRenderer &renderer) 
{
    VictoryText.Draw(renderer);
}

VictoryScreen::~VictoryScreen()
{

}