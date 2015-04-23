#include "GameObject.h"

GameObject::GameObject(void)
{
	sprite = nullptr;
}

GameObject::~GameObject(void)
{
	delete sprite;
}

void GameObject::updateAnimation()
{
	for (int i = 0 ; i < numberOfSprite ; i++)
		sprite[i].setPosition(sprite[currentSprite].getX(), sprite[currentSprite].getY());
	
	// Change animation's image
	currentSprite++;
	currentSprite %= numberOfSprite;
}
