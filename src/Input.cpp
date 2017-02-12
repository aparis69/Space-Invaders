#include "Input.h"
#include <iostream>

using namespace std;

// Constructors & Destructor
Input::Input()
{
	memset(this, 0, sizeof(*this));
	quit = false;
}

Input::~Input()
{
}


// Member Functions
void Input::Update()
{
	SDL_Event event;
	mousebuttons[SDL_BUTTON_WHEELUP] = 0;
	mousebuttons[SDL_BUTTON_WHEELDOWN] = 0;
	uppedKeys.clear();

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			key[event.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			key[event.key.keysym.sym] = false;
			uppedKeys.push_back(event.key.keysym.sym);
			break;
		case SDL_MOUSEMOTION:
			mousex = event.motion.x;
			mousey = event.motion.y;
			mousexrel = event.motion.xrel;
			mouseyrel = event.motion.yrel;
			break;
		case SDL_MOUSEBUTTONDOWN:
			mousebuttons[event.button.button] = true;
			break;
		case SDL_MOUSEBUTTONUP:
			mousebuttons[event.button.button] = false;
			break;
		case SDL_QUIT:
			quit = true;
			break;
		default:
			break;
		}
	}
}

bool Input::isMoving() const
{
	return key[SDLK_UP] || key[SDLK_LEFT] || key[SDLK_RIGHT] || key[SDLK_DOWN];
}

bool Input::wasKeyUpped(SDLKey k) const
{
	bool ret = false;
	for (SDLKey key : uppedKeys)
	{
		if (key == k)
		{
			ret = true;
			break;
		}
	}
	return ret;
}

bool Input::Key(int i) const
{
	return key[i];
}

int Input::MouseX() const
{
	return mousex;
}

int Input::MouseY() const
{
	return mousey;
}

int Input::MouseXrel() const
{
	return mousexrel;
}

int Input::MouseYrel() const
{
	return mouseyrel;
}

bool Input::MouseButton(int i) const
{
	return mousebuttons[i];
}

bool Input::Quit() const
{
	return quit;
}