#pragma once
#include <sdl/sdl.h>

class Input
{
protected:
    char key[SDLK_LAST];
    int mousex, mousey;
    int mousexrel, mouseyrel;
    char mousebuttons[8];
    char quit;
public:
    // Constructor & Destructor
    Input();

    ~Input()
    {
    }

    // Member functions
    void Update();

    // Getter & Setter

    inline char& Key(int i)
    {
        return key[i];
    }

    inline int MouseX()
    {
        return mousex;
    }

    inline int MouseY()
    {
        return mousey;
    }

    inline int MouseXrel()
    {
        return mousexrel;
    }

    inline int MouseYrel()
    {
        return mouseyrel;
    }

    inline int MouseButton(int i)
    {
        return mousebuttons[i];
    }

    inline int Quit()
    {
        return quit;
    }
};