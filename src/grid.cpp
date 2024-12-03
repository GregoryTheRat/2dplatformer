#include "grid.h"
#include "resource_manager.h"


Grid::Grid() {}

//adds the object to the cell it occupies, or multiple if it overlaps (endX and endY are for this reason)
void Grid::AddObjectToGrid(const std::shared_ptr<GameObject> &object)
{
    int startX = std::max(0, static_cast<int>(object->Position.x / this->CellWidth));
    int startY = std::max(0, static_cast<int>(object->Position.y / this->CellHeight));
    int endX = std::min(2, static_cast<int>((object->Position.x + object->Size.x) / this->CellWidth));
    int endY = std::min(2, static_cast<int>((object->Position.y + object->Size.y) / this->CellHeight));

    for (int x = startX; x <= endX; ++x)
    {
        for (int y = startY; y <= endY; ++y)
        {
            this->Cells[x][y].push_back(object);
            //printf("object added to cell: [%i][%i]\n", x, y);
        }
    }
}


//returns the objects from all the cells that the given position+size overlap
std::unordered_set<std::shared_ptr<GameObject>> Grid::QueryGrid(glm::vec2 position, glm::vec2 size)
{
    int startX = std::max(0, static_cast<int>(position.x / this->CellWidth));
    int startY = std::max(0, static_cast<int>(position.y / this->CellHeight));
    int endX = std::min(2, static_cast<int>((position.x + size.x) / this->CellWidth));
    int endY = std::min(2, static_cast<int>((position.y + size.y) / this->CellHeight));

    //printf("querying from [%i - %i][%i - %i]\n", startX, endX, startY, endY);
    std::unordered_set<std::shared_ptr<GameObject>> result;
    for (int x = startX; x <= endX; ++x)
    {
        for (int y = startY; y <= endY; ++y)
        {
            for (const auto& obj : this->Cells[x][y])
            {
                result.insert(obj);
            }
        }
    }

    return result;
}


void Grid::Draw(SpriteRenderer &Renderer)
{
    //draw the grid sections
    for (int x = 0; x <= 2; ++x)
    {
        for (int y = 0; y <= 2; ++y)
        {
            GameObject cell(
                glm::vec2(x * this->CellWidth, y * CellHeight),
                glm::vec2(this->CellWidth, this->CellHeight),
                ResourceManager::GetTexture("container"), glm::vec3(0.5f, 1.0f, 0.5f));

            cell.Draw(Renderer);
        }
    }
}