#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "sprite_renderer.h"
#include "resource_manager.h"
#include "game_object.h"
#include <vector>

enum Direction
{
    MENU_UP,
    MENU_DOWN
};

class GameMenu
{
private:
    //TODO:possibly have menu options as a seperate class?
    std::vector<GameObject> Options;
    unsigned int Idx;
    float CooldownT;
     
public:
    GameMenu();
    GameMenu(int Width, int Height);
    ~GameMenu();
    //direction of menu option change
    void UpdateCooldown(float dt);
    void ChangeSelectedOption(Direction direction);
    //activates the selected menu option, returns true if game can proceed to GAME_ACTIVE state
    bool ActivateMenu();
    void Draw(SpriteRenderer &renderer);
};

#endif