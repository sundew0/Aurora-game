#include "entity.h"
#include <SDL.h>
#include <SDL_image.h>

entity::entity(Vector2f p_pos, SDL_Texture* p_texture)
	:pos(p_pos), texture(p_texture)
{
	CurrentFrame.x = 0;
	CurrentFrame.y = 0;
	CurrentFrame.w = 32;
	CurrentFrame.h = 32;
}


SDL_Texture* entity::getTexture()
{
	return texture;
}

SDL_Rect entity::getCurrentFrame()
{
	return CurrentFrame;
}
