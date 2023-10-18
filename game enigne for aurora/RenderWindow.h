#pragma once
#include <SDL.h>
#include <SDL_image.h>
class RenderWindow
{
public:
	RenderWindow(const char* p_Title, int p_Width, int p_Height);
	SDL_Texture* loadTexture(const char* p_filePath);
	void CleanUp();
	void Clear();
	void render(SDL_Texture* p_texture);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

