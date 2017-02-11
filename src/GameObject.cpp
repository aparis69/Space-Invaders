#include "GameObject.h"
#include "Window.h"
#include "Context.h"
#include "AssetManager.h"

#include <iostream>
using namespace std;

GameObject::GameObject(void)
{
	// Add itself to the gameObject list stored in context class
	Context::addGameObject(this);

	sprite = nullptr;
	ticksSinceAnim = -1;
}

GameObject::~GameObject(void)
{
	// Delete itself from the gameobject list stored in context class
	Context::deleteGameObject(this);

	delete sprite;
}

void GameObject::updateAnimation()
{
	int now = SDL_GetTicks();
	// Change animation's image
	if (now - ticksSinceAnim > animDuration)
	{
		currentSprite++;
		currentSprite %= numberOfSprite;
		ticksSinceAnim = now;
	}
}

void GameObject::moveX(bool left)
{
	transform.setX(transform.X() + moveValueX(left));
}

void GameObject::moveY(bool forward)
{
	transform.setY(transform.Y() + moveValueY(forward));
}

void GameObject::move(bool forward, bool left)
{
	moveX(left);
	moveY(forward);
}

int GameObject::moveValueX(bool left) const
{
	if (left)
		return (int)(-transform.XSpeed() * 10 / Window::FPS);
	else
		return (int)(transform.XSpeed() * 10 / Window::FPS);
}

int GameObject::moveValueY(bool forward) const
{
	if (forward)
		return (int)(-transform.YSpeed() * 10 / Window::FPS);
	else
		return (int)(transform.YSpeed() * 10 / Window::FPS);
}

void GameObject::loadSpriteSize()
{
	transform.setXSize(AssetManager::getSpriteXSize(sprite[currentSprite]));
	transform.setYSize(AssetManager::getSpriteYSize(sprite[currentSprite]));
}

int GameObject::getCurrentSpriteIndex() const
{
	return sprite[currentSprite];
}

Transform GameObject::getTransform() const
{
	return transform;
}

ObjectTypes GameObject::getObjectType() const
{
	return type;
}