#include <iostream>
#include <time.h>
#include "Input.h"
#include "Context.h"
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

	while(!in.Key(SDLK_ESCAPE) && !in.Quit())
	{
		unsigned int elapsed;
		unsigned int lasttime = SDL_GetTicks();

		in.Update();
		c.update(in);

		elapsed = SDL_GetTicks() - lasttime;  
		if (elapsed < 10)							
			SDL_Delay(10 - elapsed); // synchronisation à 60 FPS		 
	}
}