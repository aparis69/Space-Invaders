#include "AssetManager.h"
using namespace std;

AssetManager::AssetManager(void)
{
    graphicsRessources = vector<SDL_Surface*>();

    loadRessources();
}

AssetManager::~AssetManager(void)
{
    for (gIterator = graphicsRessources.begin(); gIterator != graphicsRessources.end(); gIterator++)
        SDL_FreeSurface(*gIterator);

    graphicsRessources.clear();
}

void AssetManager::loadRessources()
{
    // Background : 0
    graphicsRessources.push_back(loadImage("Assets/Background/Background01.bmp"));

    // Player : 1 a 4
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipPlayer01.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipPlayer02.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipPlayer03.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipPlayer04.bmp"));

    // Basic Missile : 5 à 8
    graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile01.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile02.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile03.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile04.bmp"));
}

SDL_Surface* AssetManager::loadImage(char* file)
{
    SDL_Surface* loadImg = SDL_LoadBMP(file);
    SDL_Surface *OptimizedImg = SDL_DisplayFormat(loadImg);
    SDL_SetColorKey(OptimizedImg, SDL_SRCCOLORKEY, SDL_MapRGB(OptimizedImg->format, 0, 0, 0));

    return OptimizedImg;
}