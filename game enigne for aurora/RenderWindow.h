#pragma once
#include <SDL.h>
#include <SDL_image.h>
class RenderWindow
{
public:
	RenderWindow(const char* p_Title, int p_Width, int p_Height);
	void CleanUp();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

