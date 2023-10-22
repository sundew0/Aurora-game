#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "entity.h"
#include "Utils.h"
//#include "player.h"

using namespace std;

int main(int argc, char* args[])
{

	//player player;

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << "SDL_Init has Failed: " << SDL_GetError() << endl;
	

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "IMG_Init has Failed: " << SDL_GetError() << endl;
	
	RenderWindow window("Aurora v0.1", 1280, 720);
	

	SDL_Texture* grassTexture = window.loadTexture("src/img/player/ground_grass_1.png");
	float grassTextureSize = (32, 32);
	SDL_Texture* Maddie = window.loadTexture("src/img/player/maddie test.png");
	
	//entity platforms[3] = {
	//	entity(0, 0, grassTexture),
	//	entity(30, 0, grassTexture),
	//	entity(30, 30, grassTexture)
	//};
	std::vector<entity> entities = {
		entity(Vector2f(0, 120), grassTexture, 32, 32),
		entity(Vector2f(30, 120), grassTexture, 32, 32),
		entity(Vector2f(60, 120), grassTexture, 32, 32)};
	{
		entity maddie(Vector2f(80, 120), Maddie, 96, 128);
		entities.push_back(maddie);
	}

	bool gameRunning = true;

	SDL_Event event;

	const float timestep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = Utils::hireTimeInSeconds();

	while (gameRunning)
	{
		int startTicks = SDL_GetTicks();
		
		float newTime = Utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= timestep)
		{

			while (SDL_PollEvent(&event))

				switch (event.type) {
					/* Keyboard event */
					/* Pass the event data onto PrintKeyInfo() */
				case SDL_KEYDOWN:
				//	player.control();
				case SDL_KEYUP:
					
				case  SDL_QUIT:
					gameRunning = false;


					accumulator -= timestep;

				}
		}

		const float alpha = accumulator / timestep;


		window.Clear();

		for (entity& e : entities) {
			window.render(e);
		}

		window.display();

		int frameTicks = SDL_GetTicks() - startTicks;
		
		if (frameTicks < 1000 / window.getRefreshRate())
		{
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
		}
	
	}

	window.CleanUp();
	SDL_Quit();
	
	return 0;
}