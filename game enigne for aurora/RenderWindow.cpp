using namespace std;
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"




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

void RenderWindow::render(SDL_Texture* p_texture)
{
	SDL_RenderCopy(renderer, p_texture, NULL, NULL);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}
