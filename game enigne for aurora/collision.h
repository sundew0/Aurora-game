#pragma once
#include <SDL.h>
#include "math.h"
class collision
{
public:
	bool check_Collision(SDL_Rect a, Vector2f& a_pos, SDL_Rect b, Vector2f& b_pos);

};

