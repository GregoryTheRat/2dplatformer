#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H

#include "sprite_renderer.h"
#include "resource_manager.h"
#include "game_object.h"

class VictoryScreen 
{
private:
    GameObject VictoryText;

public:
    VictoryScreen();
    VictoryScreen(int Width, int Height);
    ~VictoryScreen();

    void Draw(SpriteRenderer &renderer);
};

#endif