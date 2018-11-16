#include <iostream>
#include "Game.h"

using namespace std;

bool Game::init(const char*title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, fullscreen);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}

	}
	else
	{
		return false;
	}
	return true;

}