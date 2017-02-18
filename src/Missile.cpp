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
	switch (missileTypes)
	{
	case MissileTypes::Small:
		numberOfSprite = 1;
		sprite = new int[numberOfSprite];
		sprite[0] = 18;
		break;
	case MissileTypes::Medium:
		numberOfSprite = 4;
		sprite = new int[numberOfSprite];
		sprite[0] = 5;
		sprite[1] = 6;
		sprite[2] = 7;
		sprite[3] = 8;
		break;
	case MissileTypes::Big:
		break;
	}
}

ReactionTypes Missile::reactToCollision(GameObject* hitObject)
{
	if (hitObject->getObjectType() != ObjectTypes::Player)
		return ReactionTypes::Destroy;
	return ReactionTypes::Nothing;
}