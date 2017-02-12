#include <iostream>
#include <time.h>
#include <vld.h> // Comment this line if you don't want to detect memory leaks (visual leaks extension, VS2015)

#include "Input.h"
#include "Context.h"
#include "Window.h"
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
	Input in;
	srand((unsigned int)time(NULL));

	while (!in.Key(SDLK_ESCAPE) && !in.Quit())
	{
		unsigned int lastTime = SDL_GetTicks();

		in.Update();
		c.update(in);

		Window::sync(lastTime);
	}
}