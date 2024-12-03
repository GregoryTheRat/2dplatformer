#ifndef GRID_H
#define GRID_H

#include "game_object.h"
#include "sprite_renderer.h"
#include <vector>
#include <unordered_set>
#include <memory>

/*
grid size :
    width = 1920 / 3 = 640
    height = 1080 / 3 = 360
*/


class Grid
{
public:
    Grid();

    void AddObjectToGrid(const std::shared_ptr<GameObject> &object);
    std::unordered_set<std::shared_ptr<GameObject>> QueryGrid(glm::vec2 position, glm::vec2 size);

    //debug
    void Draw(SpriteRenderer &Renderer);

private:
    const unsigned int CellWidth = 640;
    const unsigned int CellHeight = 360;

    std::vector<std::shared_ptr<GameObject>> Cells[3][3];

};




#endif