#include "MenuButton.h"
using namespace std;

// Constructors & Destructor
MenuButton::MenuButton()
{
	buttonSurface = nullptr;
	width = height = x = y = 0;
}

MenuButton::MenuButton(std::string t)
{
	text = t;
	buttonSurface = nullptr;
	width = height = y = x = 0;
}

MenuButton::MenuButton(std::string t, int x, int y)
{
	text = t;
	this->x = x;
	this->y = y;
	width = height = 0;
	buttonSurface = nullptr;
}

MenuButton::~MenuButton()
{
	SDL_FreeSurface(buttonSurface);
	buttonSurface = nullptr;
}


// Member Function
bool MenuButton::selected(Input& in) const
{
	int mouseX = in.MouseX();
	int mouseY = in.MouseY();
	if (mouseX > x && mouseX < x + width)
	{
		if (mouseY > y && mouseY < y + height)
			return true;
	}
	return false;
}


// Getter & Setter
const string& MenuButton::getText() const
{
	return text;
}

int MenuButton::getX() const
{
	return x;
}

int MenuButton::getY() const
{
	return y;
}

SDL_Surface* MenuButton::getSurface() const
{
	return buttonSurface;
}

void MenuButton::setSurface(SDL_Surface* s)
{
	buttonSurface = s;
	width = s->w;
	height = s->h;
}