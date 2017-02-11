#pragma once
#include "SDLinclude.h"
#include <vector>

class AssetManager
{
private:
    // vector (with iterator) of all the possible assets that can be load in the game scene
    static std::vector<SDL_Surface*> graphicsRessources;
    std::vector<SDL_Surface*>::iterator gIt;

    // Load all the assets into the graphicsRessources vector
    void loadRessources();
    // Load image with black transparency applied
    SDL_Surface* loadImage(char const *);

public:
    // Contructor & Destructor
    AssetManager();
    ~AssetManager();

    // Return X/Y Size of an asset based on his index in the vector
    static int getSpriteXSize(int);
    static int getSpriteYSize(int);

    // Getter & Setter
    SDL_Surface* getSurface(int) const;
    int getSurfaceCount() const;
};