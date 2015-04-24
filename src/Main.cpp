#include <iostream>
#include <time.h>

#include "Input.h"
#include "Context.h"

#include "Global.h"

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
    srand(time(NULL));

    while (!in.Key(SDLK_ESCAPE) && !in.Quit())
    {
        unsigned int elapsed;
        unsigned int lasttime = SDL_GetTicks();
        //cout << "Cycle at " << lasttime << endl;
        in.Update();
        c.update(in);

        elapsed = SDL_GetTicks() - lasttime;
        if (elapsed < 1000/FPS)
            SDL_Delay(1000/FPS - elapsed); // synchronisation à 60 FPS
    }
}
