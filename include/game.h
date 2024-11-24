#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "game_level.h"
#include "game_menu.h"

enum GameState
{
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game
{
    public:
        GameState State;
        bool Keys[1024];
        GameMenu MainMenu; 
        unsigned int Width, Height;
        std::vector<GameLevel> Levels;
        unsigned int Level;

        Game(unsigned int width, unsigned int height);
        ~Game();
        void Init();
        //game loop
        void ProcessInput(float dt);
        void Update(float dt);
        void Render();
        //check for collision based on bounding box (axis-aligned bounding box)
        bool CheckCollision(GameObject &one, GameObject &two);
        void DoCollisions();
};

#endif