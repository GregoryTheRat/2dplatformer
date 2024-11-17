#include "game_object.h"
#include "player_object.h"

#include <iostream>

GameObject::GameObject() 
    : Position(0.0f, 0.0f), Size(1.0f, 1.0f), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(), IsSolid(false), Destroyed(false) { }

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity) 
    : Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite), IsSolid(false), Destroyed(false) { }

void GameObject::DoCollisionBehaviour(GameObject *otherObject) 
{
    //for the default platform, the coll.behaviour should be to push the player away with overlap,
    //and if the player is on top of the platform to reset its jump mechanic.
    glm::vec2 otherCenter(otherObject->Position.x + otherObject->Size.x / 2, otherObject->Position.y + otherObject->Size.y / 2);
    glm::vec2 ownCenter(this->Position.x + this->Size.x / 2, this->Position.y + this->Size.y / 2);
    glm::vec2 difference (ownCenter - otherCenter);
    glm::vec2 compass[] = {
        glm::vec2(0.0f, 1.0f),	// up
        glm::vec2(1.0f, 0.0f),	// right
        glm::vec2(0.0f, -1.0f),	// down
        glm::vec2(-1.0f, 0.0f)	// left
    };
    float max = 0.0f;
    unsigned int best_match = -1;
    for (unsigned int i = 0; i < 4; i++)
    {
        float dot_product = glm::dot(glm::normalize(difference), compass[i]);
        if (dot_product > max)
        {
            max = dot_product;
            best_match = i;
        }
    }

    PlayerObject* player = dynamic_cast<PlayerObject*> (otherObject);
    switch (best_match)
    {
        case 0: //up
            //printf("up\n");
            if (player == nullptr)
            {

            }
            else
            {
                player->Jumped = false;
                //also resolve overlap
                float overlapY = std::min((player->Position.y + player->Size.y), (this->Position.y + this->Size.y)) - std::max(player->Position.y, this->Position.y);
                //player->Velocity.y = 0.0f;
                player->Position.y -= overlapY;
            }
            break;

        case 1: //right
            //printf("right\n");
            if (player == nullptr)
            {

            }
            else
            {
                player->Velocity.x = 0.0f;
                //also resolve overlap
                float overlapX = std::min((player->Position.x + player->Size.x), (this->Position.x + this->Size.x)) - std::max(player->Position.x, this->Position.x);
                player->Position.x -= overlapX;
            }
            break;

        case 2: //down
            //printf("down\n");
            //also resolve overlap
            if (player == nullptr)
            {

            }
            else
            {
                float overlapY = std::min((player->Position.y + player->Size.y), (this->Position.y + this->Size.y)) - std::max(player->Position.y, this->Position.y);
                player->Position.y += overlapY;
                //sort of "cheating time" so that the player starts to fall sooner if he hits a platform from below
                player->JumpStartT -= 0.10f; 
            }
            break;

        case 3: //left
            /*
            left side is problematic, because the player and the platforms starting point is its top left corner. 
            That is what causes the short stutter/stuck effect when moving right, as we are resolving a left side mini collision
            */
            //printf("left\n");
            //printf("angle : %f\n", max);
            if (player == nullptr)
            {

            }
            else
            {
                /*
                */
                if (max > 0.74) //this is to resovle getting stuck on upper left corner of boxes.
                {
                    float overlapX = std::min((player->Position.x + player->Size.x), (this->Position.x + this->Size.x)) - std::max(player->Position.x, this->Position.x);
                    player->Velocity.x = 0.0f;
                    player->Position.x += overlapX;
                }
            }
            break;
        
        default:
            player->Velocity.x = 0.0f;
            player->Velocity.y = 0.0f;
            break;
    }
}

void GameObject::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}