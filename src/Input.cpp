#include "Input.h"

using namespace std;
Input::Input()
{
    memset(this, 0, sizeof (*this));
    quit = false;
}

void Input::Update()
{
    SDL_Event event;
    mousebuttons[SDL_BUTTON_WHEELUP] = 0;
    mousebuttons[SDL_BUTTON_WHEELDOWN] = 0;
    uppedKeys.clear();

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                key[event.key.keysym.sym] = true;
                break;
            case SDL_KEYUP:
                key[event.key.keysym.sym] = false;
                uppedKeys.push_back(event.key.keysym.sym);
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
                quit = true;
                break;
            default:
                break;
        }
    }
}

bool Input::isMoving() const
{
    return key[SDLK_UP] || key[SDLK_LEFT] || key[SDLK_RIGHT] || key[SDLK_DOWN];
}

bool Input::wasKeyUpped(SDLKey k) const
{
    bool ret = false;
    for(SDLKey key : uppedKeys)
    {
        if(key == k)
        {
            ret = true;
            break;
        }
    }
    return ret;
}
