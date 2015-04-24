#pragma once
#include "SDLinclude.h"
#include <string>

class Window
{
private:
    static int XRES, YRES;
    std::string windowName;
    SDL_Surface* screen;

public:
    // Constructor & Destructor
    Window(int xres, int yres, std::string name);
    ~Window(void);

    // Member functions
    void flipScreen();
    void blitSurface(SDL_Surface* surface, int xPos, int yPos);

    // Getter & Setter

    inline int getXRES() const
    {
        return XRES;
    }

    inline int getYRES() const
    {
        return YRES;
    }

    inline SDL_Surface* getSurface() const
    {
        return screen;
    }
};

