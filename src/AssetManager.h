#pragma once
#include "SDLinclude.h"
#include <vector>

class AssetManager
{
private:
    // Variables
    static std::vector<SDL_Surface*> graphicsRessources;
    std::vector<SDL_Surface*>::iterator gIterator;

    // Private function
    SDL_Surface* loadImage(char const *file);
    void loadRessources();

public:
    // Contructor & Destructor
    AssetManager(void);
    ~AssetManager(void);

    // Member functions
    static int getSpriteXSize(int index);
    static int getSpriteYSize(int index);

    // Getter & Setter

    inline SDL_Surface* getSurface(int index) const
    {
        return graphicsRessources.at(index);
    }

    inline int getNumberOfSurface() const
    {
        return graphicsRessources.size();
    }
};