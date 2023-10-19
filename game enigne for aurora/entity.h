#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "math.h"

class entity
{
public: 
	entity(Vector2f p_pos, SDL_Texture* p_texture);
	Vector2f& getPos()
	{
		return pos;
	};
	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();
private:
	Vector2f pos;

	SDL_Rect CurrentFrame;
	SDL_Texture* texture;
};

