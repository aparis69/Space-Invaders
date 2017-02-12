#pragma once
#include "Input.h"
#include "MenuButton.h"
#include "MenuEvents.h"
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
	MenuEvents lastEvent;

	void processEvents(Input&);
	void render(Input&);

public:
	// Constructors & Destructors
	Menu();
	Menu(Window*);
	~Menu();

	// Member function
	void update(Input&);

	// Getter & Setter
	bool quit() const;
	MenuEvents getLastEvent();
};