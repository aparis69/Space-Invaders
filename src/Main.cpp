#include <iostream>
#include <time.h>
#include <vld.h> // Comment this line if you don't want to detect memory leaks (visual leaks extension, VS2015)

#include "Input.h"
#include "Context.h"
#include "Menu.h"
#include "Window.h"
#include "Params.h"
using namespace std;

void GameLoop();

int main(int argc, char *argv[])
{
	GameLoop();
	return EXIT_SUCCESS;
}

void GameLoop()
{
	Context c;
	Menu m(c.getWindow());
	Input in;
	unsigned int timerToogleMenu = SDL_GetTicks() + 500;
	bool menuShown = true;
	srand((unsigned int)time(NULL));

	while (!in.Key(SDLK_ESCAPE) && !in.Quit() && !m.quit())
	{
		unsigned int lastTime = SDL_GetTicks();

		in.Update();
		if ((in.wasKeyUpped(MENU_KEY) || m.getLastEvent() == RESUME) 
			&& timerToogleMenu < lastTime)
		{
			menuShown = !menuShown;
			timerToogleMenu = SDL_GetTicks() + 500;
		}

		if (menuShown)
			m.update(in);
		else
			c.update(in);

		Window::sync(lastTime);
	}
}