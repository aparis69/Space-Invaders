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
		sprite[i].SetPosition(sprite[currentSprite].GetX(), sprite[currentSprite].GetY());
	
	// Changement d'image de l'animation
	currentSprite++;
	currentSprite %= numberOfSprite;
}
