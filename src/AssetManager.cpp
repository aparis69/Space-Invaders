#include "AssetManager.h"
#include <iostream>
using namespace std;

std::vector<SDL_Surface*> AssetManager::graphicsRessources = std::vector<SDL_Surface*>();
std::vector<SDL_Surface*>::iterator AssetManager::gIt = std::vector<SDL_Surface*>::iterator();

AssetManager::AssetManager(void)
{
	std::cout << "Error : Asset Manager constructor called - Singleton & Static should not be instancied" << std::endl;
}

AssetManager::~AssetManager(void)
{
	for (gIt = graphicsRessources.begin(); gIt != graphicsRessources.end(); gIt++)
		SDL_FreeSurface(*gIt);
	graphicsRessources.clear();
}

void AssetManager::init()
{
	loadRessources();
}

void AssetManager::releaseData()
{
	for (gIt = graphicsRessources.begin(); gIt != graphicsRessources.end(); gIt++)
		SDL_FreeSurface(*gIt);
	graphicsRessources.clear();
}

void AssetManager::loadRessources()
{
	// Background : 0
	graphicsRessources.push_back(loadImage("Assets/Background/Background01.bmp"));

	// Player : 1 to 4
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipPlayer01.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipPlayer02.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipPlayer03.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipPlayer04.bmp"));

	// Basic Missile : 5 to 8
	graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile01.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile02.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile03.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Missiles/basicMissile04.bmp"));

	// Enemy easy : 9 
	graphicsRessources.push_back(loadImage("Assets/Spaceships/Neutron01.bmp"));

	// Enemy medium : 10 to 13 
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipE01.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipE02.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipE03.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipE04.bmp"));

	// Enemy hard : 14 to 17
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipM01.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipM02.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipM03.bmp"));
	graphicsRessources.push_back(loadImage("Assets/Spaceships/ShipM04.bmp"));
}

SDL_Surface* AssetManager::loadImage(char const *file)
{
	SDL_Surface* loadImg = SDL_LoadBMP(file);
	SDL_Surface* optImg = SDL_DisplayFormat(loadImg);
	SDL_SetColorKey(optImg, SDL_SRCCOLORKEY, SDL_MapRGB(optImg->format, 0, 0, 0));
	return optImg;
}

int AssetManager::getSpriteXSize(int index)
{
	return graphicsRessources.at(index)->w;
}

int AssetManager::getSpriteYSize(int index)
{
	return graphicsRessources.at(index)->h;
}

SDL_Surface* AssetManager::getSurface(int index)
{
	return graphicsRessources.at(index);
}

int AssetManager::getSurfaceCount()
{
	return graphicsRessources.size();
}