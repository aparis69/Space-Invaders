#pragma once
#include "SDLinclude.h"
#include <vector>

class AssetManager
{
private:
    // vector (with iterator) of all the possible assets that can be load in the game scene
    static std::vector<SDL_Surface*> graphicsRessources;
    static std::vector<SDL_Surface*>::iterator gIt;

    // Load all the assets into the graphicsRessources vector
    static void loadRessources();
    // Load image with black transparency applied
    static SDL_Surface* loadImage(char const *);

	// Private constructor : AssetManager class is static & singleton
	AssetManager();
public:
    ~AssetManager();

	// Init & release method
	static void init();
	static void releaseData();

    // Return X/Y Size of an asset based on his index in the vector
    static int getSpriteXSize(int);
    static int getSpriteYSize(int);

    // Getter & Setter
    static SDL_Surface* getSurface(int);
    static int getSurfaceCount();
};