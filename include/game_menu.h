#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <list>

enum Direction
{
    MENU_UP,
    MENU_DOWN
};

class GameMenu
{
private:
    std::list<> options;

public:
    GameMenu();
    //direction
    ChangeSelectedMenu(Direction direction);
    ~GameMenu();
};

#endif