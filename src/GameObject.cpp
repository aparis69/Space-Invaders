#include "GameObject.h"
#include "Window.h"
#include "Context.h"
#include "AssetManager.h"
#include "MissileManager.h"

#include <iostream>
using namespace std;

GameObject::GameObject()
{
	// Add itself to the gameObject list stored in context class
	Context::addGameObject(this);

	sprite = nullptr;
	ticksSinceAnim = -1;

	spawnDelays = new int[3];
	spawnTimers = new int[3];
	spawnTimers[0] = spawnTimers[1] = spawnTimers[2] = 0;
	spawnDelays[0] = SMALL_MISSILE_SPAWN_DELAY;
	spawnDelays[1] = MEDIUM_MISSILE_SPAWN_DELAY;
	spawnDelays[2] = MEDIUM_MISSILE_SPAWN_DELAY;
}

GameObject::~GameObject()
{
	// Delete itself from the gameobject list stored in Context
	Context::deleteGameObject(this);
	delete sprite;
	delete spawnDelays;
	delete spawnTimers;
}

void GameObject::shoot(MissileManager* m, MissileTypes t, bool ignoreDelay, Transform* p, bool upward)
{
	// Look if the timer is passed
	if (SDL_GetTicks() < spawnTimers[(int)t])
		return;
	
	// Shooting
	Vec2 dir = upward ? Vec2(0, 1) : Vec2(0, -1);
	if (p == nullptr)
		m->spawnMissile(transform.X(), transform.Y(), dir, t);
	else
		m->spawnMissile((*p).X(), (*p).Y(), dir, t);

	// Setting delays
	if (!ignoreDelay)
		spawnTimers[(int)t] = SDL_GetTicks() + spawnDelays[(int)t];
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