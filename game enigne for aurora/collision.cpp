#include "collision.h"
#include "math.h"
#include <iostream>
#include "player.h"
using namespace std;

bool collision::check_Collision(SDL_Rect a, Vector2f& a_pos, SDL_Rect b, Vector2f& b_pos)
{
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;
    
    //Calculate the sides of rect A
 
    leftA = a_pos.x;
    rightA = a_pos.x + a.w;
    topA = a_pos.y;
    bottomA = a_pos.y + a.h;
    //Calculate the sides of rect B
    leftB = b_pos.x;
    rightB = b_pos.x + b.w;
    topB = b_pos.y;
    bottomB = b_pos.y + b.h;

    //If any of the sides from A are outside of B
    if (bottomA <= topB)
    {
        return false;
    }
    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    //If none of the sides from A are outside B

    return true;
    
}
