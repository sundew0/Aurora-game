#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.h"

using namespace std;

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << "SDL_Init has Failed: " << SDL_GetError() << endl;
	

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "IMG_Init has Failed: " << SDL_GetError() << endl;
	
	RenderWindow window("Aurora v0.1", 1280, 720);
	
	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
	}

	window.CleanUp();
	SDL_Quit();
	
	return 0;
}