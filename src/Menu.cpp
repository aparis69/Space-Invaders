#include "Menu.h"
#include "Window.h"

// Constructors & Destructors
Menu::Menu()
{
	window = nullptr;
}

Menu::Menu(Window* w)
{
	window = w;
	menuFont = TTF_OpenFont("TlwgTypo.ttf", 40);
	menuBackgroundColor.r = 0;
	menuBackgroundColor.g = 150;
	menuBackgroundColor.b = 200;

	menuFontColor.r = menuFontColor.g = menuFontColor.b = 0;
	menuFontColorSelected.r = menuFontColorSelected.b = menuFontColorSelected.g = 60;

	// TO DO : adapt to resolution dynamically
	buttons.push_back(MenuButton("Resume", Window::XRES / 2 - 80, 50));
	buttons.push_back(MenuButton("Options", Window::XRES / 2 - 95, 150));
	buttons.push_back(MenuButton("Quit", Window::XRES / 2 - 55, 250));
}

Menu::~Menu()
{
}


// Member Functions
void Menu::update(Input& in)
{
	processEvents(in);
	render(in);
}

void Menu::processEvents(Input& in)
{
	// Resume
	if (buttons[0].selected(in) && in.MouseButton(1))
	{
		lastEvent = RESUME;
	}
	// Options
	else if (buttons[1].selected(in) && in.MouseButton(1))
	{
		lastEvent = NONE;
	}
	// Quit
	else if (buttons[2].selected(in) && in.MouseButton(1))
	{
		lastEvent = QUIT;
	}
}

void Menu::render(Input& in)
{
	// Render background color
	SDL_FillRect(window->getSurface(), &window->getSurface()->clip_rect,
		SDL_MapRGB(window->getSurface()->format,
			menuBackgroundColor.r,
			menuBackgroundColor.g,
			menuBackgroundColor.b));

	// Render each button
	SDL_Color usedColor;
	for (unsigned int i = 0; i < buttons.size(); i++)
	{
		usedColor = buttons[i].selected(in) ? menuFontColorSelected : menuFontColor;
		buttons[i].setSurface(TTF_RenderText_Solid(menuFont,
			buttons[i].getText().c_str(),
			usedColor));
		window->blitSurface(buttons[i].getSurface(), buttons[i].getX(), buttons[i].getY());
	}

	// Flip screen
	window->flipScreen();
}

MenuEvents Menu::getLastEvent()
{
	// When Main retreives last event, we also clear it here
	MenuEvents ret = lastEvent;
	lastEvent = NONE;
	return ret;
}

bool Menu::quit() const
{
	// Functions used to not modify lastEvent
	return lastEvent == QUIT;
}