#include "entity.h"
#include <SDL.h>
#include <SDL_image.h>

entity::entity(float p_x, float p_y, SDL_Texture* p_texture)
	:x(p_x),y(p_y), texture(p_texture)
{
	CurrentFrame.x = 0;
	CurrentFrame.y = 0;
	CurrentFrame.w = 32;
	CurrentFrame.h = 32;
}

float entity::getX()
{
	return x;
}

float entity::getY()
{
	return y;
}

SDL_Texture* entity::getTexture()
{
	return texture;
}

SDL_Rect entity::getCurrentFrame()
{
	return CurrentFrame;
}
