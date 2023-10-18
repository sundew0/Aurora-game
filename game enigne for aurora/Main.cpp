#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "entity.h"

using namespace std;

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << "SDL_Init has Failed: " << SDL_GetError() << endl;
	

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "IMG_Init has Failed: " << SDL_GetError() << endl;
	
	RenderWindow window("Aurora v0.1", 1280, 720);

	SDL_Texture* grassTexture = window.loadTexture("src/img/player/ground_grass_1.png");
	SDL_Texture* Maddie = window.loadTexture("src/img/player/Maddie.png");
	
	//entity platforms[3] = {
	//	entity(0, 0, grassTexture),
	//	entity(30, 0, grassTexture),
	//	entity(30, 30, grassTexture)
	//};
	std::vector<entity> entities = {
		entity(0, 0, grassTexture),
		entity(30, 0, grassTexture),
		entity(30, 30, grassTexture) };
	

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
		
		window.Clear();

		for (int i = 0; i < 3; i++) {
			window.render(entities[i]);
		}

		window.display();
	}

	window.CleanUp();
	SDL_Quit();
	
	return 0;
}