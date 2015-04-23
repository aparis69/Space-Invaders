#include "Input.h"

Input::Input()
{
    memset(this, 0, sizeof (*this));
}

void Input::Update()
{
    SDL_Event event;
    mousebuttons[SDL_BUTTON_WHEELUP] = 0;
    mousebuttons[SDL_BUTTON_WHEELDOWN] = 0;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                key[event.key.keysym.sym] = 1;
                break;
            case SDL_KEYUP:
                key[event.key.keysym.sym] = 0;
                break;
            case SDL_MOUSEMOTION:
                mousex = event.motion.x;
                mousey = event.motion.y;
                mousexrel = event.motion.xrel;
                mouseyrel = event.motion.yrel;
                break;
            case SDL_MOUSEBUTTONDOWN:
                mousebuttons[event.button.button] = 1;
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button != SDL_BUTTON_WHEELUP && event.button.button != SDL_BUTTON_WHEELDOWN)
                    mousebuttons[event.button.button] = 0;
                break;
            case SDL_QUIT:
                quit = 1;
                break;
            default:
                break;
        }
    }
}