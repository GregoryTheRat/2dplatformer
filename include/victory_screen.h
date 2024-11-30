#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H

#include "sprite_renderer.h"
#include "game_object.h"
#include <vector>

class VictoryScreen 
{
private:
    std::vector<GameObject> VictoryTexts;

public:
    VictoryScreen();
    VictoryScreen(int Width, int Height);
    ~VictoryScreen();

    void Draw(SpriteRenderer &renderer);
};

#endif