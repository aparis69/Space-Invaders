#pragma once
#include "SDLinclude.h"
#include <vector>

class AssetManager
{
	private:
		// Variables
		std::vector<SDL_Surface*> graphicsRessources;
		std::vector<SDL_Surface*>::iterator gIterator;

		// Private function
		SDL_Surface* loadImage(char* file);
		void loadRessources();

	public:
		// Contructor & Destructor
		AssetManager(void);
		~AssetManager(void);

		// Member functions

		// Getter & Setter
		inline SDL_Surface* getSurface(int index) const { return graphicsRessources.at(index); }
		inline int getNumberOfSurface() const { return graphicsRessources.size() ; }
};