using namespace std;
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"




RenderWindow::RenderWindow(const char* p_Title, int p_Width, int p_Height)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_Width, p_Height, SDL_WINDOW_SHOWN);

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

void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
}
