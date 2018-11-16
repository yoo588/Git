#include <iostream>
#include "Game.h"

using namespace std;

bool Game::init(const char*title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

	}
	else
	{
		return false;
	}
	return true;

	SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
		pTempSurface);
	SDL_FreeSurface(pTempSurface);

	SDL_QueryTexture(m_pTexture, NULL, NULL,
		&m_sourceRectangle.w, &m_sourceRectangle.h);
}

void Game::render()
{
	m_destinatioRectangle.x = m_sourceRectangle.x = 0;
	m_destinatioRectangle.y = m_sourceRectangle.y = 0;
	m_destinatioRectangle.w = m_sourceRectangle.w;
	m_destinatioRectangle.h = m_sourceRectangle.h;

	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_sourceRectangle, &m_destinatioRectangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleanning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}