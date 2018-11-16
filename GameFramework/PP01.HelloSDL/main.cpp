#include<iostream>
#include<SDL.h>
#include"Game.h"
using namespace std;

bool g_bRunning = true;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

Game* g_game = 0;

int main()
{
	g_game = new Game();
	g_game->init("Chapter 1", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}