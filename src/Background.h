#pragma once
#include "GameObject.h"
#include "SDLinclude.h"

class Background : public GameObject
{
private:
    SDL_Rect scroll;

public:
    // Constructor & Destructor
    Background(void);

    ~Background(void)
    {
    }

    // Member functions
    void updateScroll(int YRES);
    void loadSprites();

    // Getter & Setter

    SDL_Rect getPosition()
    {
        return scroll;
    }
};

