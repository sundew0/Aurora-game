using namespace std;
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"
#include "entity.h"



RenderWindow::RenderWindow(const char* p_Title, int p_Width, int p_Height)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_Width, p_Height, SDL_WINDOW_RESIZABLE);

	if (window == NULL)
	{
		cout << "Window Failed to INIT, ERROR: " << SDL_GetError() << endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		cout << "Renderer Failed to INIT, ERROR: " << SDL_GetError() << endl;
	}
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		cout << "Failed to load texture. Error:" << SDL_GetError << endl;

	return texture;
}

void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(entity& p_entity)
{
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getX() * 4;
	dst.y = p_entity.getY() * 4;
	dst.w = p_entity.getCurrentFrame().w * 4;
	dst.h = p_entity.getCurrentFrame().h * 4;


	SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}
