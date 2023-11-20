#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "entity.h"
#include "Utils.h"
#include "player.h"
#include "maploading.h"
#include "collision.h"

using namespace std;

int main(int argc, char* args[])
{
	maploading loadMap;
	player player;

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << "SDL_Init has Failed: " << SDL_GetError() << endl;
	

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "IMG_Init has Failed: " << SDL_GetError() << endl;
	
	RenderWindow window("Aurora v0.1", loadMap.SCREEN_WIDTH , loadMap.SCREEN_HEIGHT);
	

	SDL_Texture* grassTexture = window.loadTexture("src/img/player/ground_grass_1.png");
	SDL_Texture* Maddie = window.loadTexture("src/img/player/maddie test.png");
	

	bool gameRunning = true;
	collision collision_tester;
	SDL_Event event;

	const float timestep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = Utils::hireTimeInSeconds();
	int test = 0;
	bool playercollision = false;
	while (gameRunning)
	{
		std::vector<entity> mapplatforms = {
		entity(Vector2f(170, 300), grassTexture, 32, 32),
		entity(Vector2f(230, 300), grassTexture, 32, 32),
		entity(Vector2f(200, 300), grassTexture, 32, 32) };


		entity playerentity(player.get_Player_Pos(), Maddie, 96, 128);// player
		
	

			while (SDL_PollEvent(&event))

			
				switch (event.type) {
					/* Keyboard event */
					/* Pass the event data onto PrintKeyInfo() */
				case SDL_KEYDOWN:
					player.control(event);

					break;
				case SDL_KEYUP:
					break;
				
				case  SDL_QUIT:
					gameRunning = false;
					break;
				}

		window.Clear();

		for (entity& e : mapplatforms) {
			window.render(e);

			playercollision = collision_tester.check_Collision(e.getCurrentFrame(), e.getPos(), playerentity.getCurrentFrame(), playerentity.getPos());
		}
		if (playercollision == true) {
			cout << "collision" << endl;
			player.collisionY();

		}
		window.render(playerentity);

		window.display();
	}

	window.CleanUp();
	SDL_Quit();
	
	return 0;
}