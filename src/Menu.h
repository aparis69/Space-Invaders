#pragma once
#include "Input.h"
#include "MenuButton.h"
#include "Params.h"

#include <SDL_ttf.h>
#include <vector>

class Window;

class Menu
{
private:
	Window* window;
	std::vector<MenuButton> buttons;

	TTF_Font* menuFont;
	SDL_Color menuFontColor;
	SDL_Color menuFontColorSelected;
	SDL_Color menuBackgroundColor;
	unsigned int timerToogleMenu;

	void processEvents(Input&, GameState&);
	void render(Input&);

public:
	// Constructors & Destructors
	Menu();
	Menu(Window*);
	~Menu();

	// Member function
	GameState update(Input&);
};