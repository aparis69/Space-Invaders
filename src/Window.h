#pragma once
#include "SDLinclude.h"
#include <string>

class Window
{
private:
    std::string windowName;
    SDL_Surface* screen;

public:
    static int XRES, YRES, FPS;
    // Constructor & Destructor
    Window(int xres, int yres, int FPS, std::string name);
    ~Window(void);

    // Member functions
    void flipScreen();
    void blitSurface(SDL_Surface* surface, int, int);
	static void sync(unsigned int);

    // Getter & Setter
    SDL_Surface* getSurface() const;
};