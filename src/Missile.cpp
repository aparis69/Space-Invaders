#include "Missile.h"

Missile::Missile(void)
{
	type = ObjectTypes::Missile;
	numberOfSprite = 4;
	currentSprite = 0;
	animDuration = 0;
}

Missile::Missile(int xPos, int yPos, int speed, MissileTypes mtype)
{
	type = ObjectTypes::Missile;
	numberOfSprite = 4;
	currentSprite = 0;
	transform.setX(xPos);
	transform.setY(yPos);
	transform.SetXSpeed(0);
	transform.SetYSpeed(speed);

	animDuration = 40;
	missileTypes = mtype;

	loadSprites();
	loadSpriteSize();
}

Missile::~Missile(void)
{
}

void Missile::loadSprites()
{
	sprite = new int[numberOfSprite];
	sprite[0] = 5;
	sprite[1] = 6;
	sprite[2] = 7;
	sprite[3] = 8;
}

ReactionTypes Missile::reactToCollision(GameObject* hitObject)
{
	if (hitObject->getObjectType() != ObjectTypes::Player)
		return ReactionTypes::Destroy;
	return ReactionTypes::Nothing;
}