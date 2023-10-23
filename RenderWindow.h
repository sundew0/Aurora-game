#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "entity.h"
class RenderWindow
{
public:
	RenderWindow(const char* p_Title, int p_Width, int p_Height);
	SDL_Texture* loadTexture(const char* p_filePath);

	int getRefreshRate();

	void CleanUp();
	void Clear();
	void render(entity& p_entity);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

