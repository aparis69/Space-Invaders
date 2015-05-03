#include "AssetManager.h"
using namespace std;

std::vector<SDL_Surface*> AssetManager::graphicsRessources = std::vector<SDL_Surface*>();

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

    // Basic Missile : 5 a 8
    graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile01.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile02.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile03.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile04.bmp"));

    // Enemy easy : 9 
    graphicsRessources.push_back(loadImage("Assets/Spaceships/Neutron01.bmp"));

    // Enemy medium : 10 a 13 
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipE01.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipE02.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipE03.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipE04.bmp"));

    // Enemy hard : 14 à 17
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipM01.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipM02.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipM03.bmp"));
    graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipM04.bmp"));
}

SDL_Surface* AssetManager::loadImage(char const *file)
{
    SDL_Surface* loadImg = SDL_LoadBMP(file);
    SDL_Surface *OptimizedImg = SDL_DisplayFormat(loadImg);
    SDL_SetColorKey(OptimizedImg, SDL_SRCCOLORKEY, SDL_MapRGB(OptimizedImg->format, 0, 0, 0));

    return OptimizedImg;
}

int AssetManager::getSpriteXSize(int index)
{
    return graphicsRessources.at(index)->w;
}

int AssetManager::getSpriteYSize(int index)
{
    return graphicsRessources.at(index)->h;
}

SDL_Surface* AssetManager::getSurface(int index) const
{
    return graphicsRessources.at(index);
}

int AssetManager::getNumberOfSurface() const
{
    return graphicsRessources.size();
}