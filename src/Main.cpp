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
	GameState currentState = MENU;
	Context c;
	Menu m(c.getWindow());
	Input in;

	srand((unsigned int)time(NULL));

	while (!in.Key(SDLK_ESCAPE) && !in.Quit())
	{
		unsigned int lastTime = SDL_GetTicks();

		in.Update();
		if (currentState == MENU)
			currentState = m.update(in);
		else if (currentState == GAME)
			currentState = c.update(in);
		else if (currentState == GAME_OVER)
			currentState = c.update(in);
		else if (currentState == QUIT)
			break;
		Window::sync(lastTime);
	}
}