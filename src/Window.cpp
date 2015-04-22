#include "Window.h"

Window::Window(void)
{
}

Window::Window(int xres, int yres, std::string name)
{
	SDL_Init(SDL_INIT_VIDEO);

	XRES = xres;
	YRES = yres;
	screen = SDL_SetVideoMode(XRES,YRES,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

	if (screen==NULL)
		return;
}

Window::~Window(void)
{
	SDL_FreeSurface(screen);

	SDL_Quit();
}

void Window::blitSurface(SDL_Surface* surface, int xPos, int yPos)
{
	SDL_Rect R;
    R.x = xPos;
    R.y = yPos;
    R.w = R.h = 0;
	
	SDL_BlitSurface(surface, NULL, screen, &R);
}

void Window::flipScreen()
{
	while (SDL_Flip(screen) != 0)  
		SDL_Delay(1); // synchro balayage vertical, meilleur pour carte graphique
}