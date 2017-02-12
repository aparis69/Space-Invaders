#pragma once
#include <string>
#include <SDL.h>
#include "Input.h"

class MenuButton
{
private:
	SDL_Surface* buttonSurface;
	int x, y;
	int width, height;
	std::string text;

public:
	// Constructors & Destructor
	MenuButton();
	MenuButton(std::string);
	MenuButton(std::string, int, int);
	~MenuButton();

	// Member Function
	bool selected(Input&) const;

	// Getter & Setter
	const std::string& getText() const;
	int getX() const;
	int getY() const;
	SDL_Surface* getSurface() const;
	void setSurface(SDL_Surface*);
};