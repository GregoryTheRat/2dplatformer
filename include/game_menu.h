#ifndef GAMEMENU_H
#define GAMEMENU_H


enum Direction
{
    MENU_UP,
    MENU_DOWN
};

class GameMenu
{
private:

public:
    GameMenu();
    ~GameMenu();
    //direction
    void ChangeSelectedMenu(Direction direction);
};

#endif