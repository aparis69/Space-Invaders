#pragma once
#include "GameObject.h"
#include "SDLinclude.h"

class Background : public GameObject
{
private:
    SDL_Rect scroll;
    int scrollSpeed;

public:
    // Constructor & Destructor
    Background(int scrollSpeed);

    ~Background(void)
    {
    }

    // Member functions
    void updateScroll();
    void loadSprites();

    // Getter & Setter

    SDL_Rect getPosition()
    {
        return scroll;
    }

    //Resets scroll Rect after having reached end of screen.
    void resetScroll();
};

