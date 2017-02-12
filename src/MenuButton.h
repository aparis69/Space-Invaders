#pragma once
#include <string>
#include <SDL.h>
#include "Input.h"

class MenuButton
{
private:
	// Button surface - initialized after the first blit
	SDL_Surface* buttonSurface;
	// x/y position on screen
	int x, y;
	// Automatically computed from buttonSurface
	int width, height;
	// button text shown on screen
	std::string text;

public:
	// Constructors & Destructor
	MenuButton();
	MenuButton(std::string);
	MenuButton(std::string, int, int);
	~MenuButton();

	// Member Function
	// Return true if mouse coordinates are in button rectangle
	bool selected(Input&) const;

	// Getter & Setter
	const std::string& getText() const;
	int getX() const;
	int getY() const;
	SDL_Surface* getSurface() const;
	void setSurface(SDL_Surface*);
};