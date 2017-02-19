#include "Missile.h"

Missile::Missile()
{
	type = ObjectTypes::Missile;
	numberOfSprite = 4;
	currentSprite = 0;
	animDuration = 0;
}

Missile::Missile(Vec2 pos, int speed, MissileTypes mtype, GameObject* p)
{
	parent = p;
	type = ObjectTypes::Missile;
	transform.setPosition(pos);
	transform.SetXSpeed(0);
	transform.SetYSpeed(speed);

	animDuration = 40;
	missileTypes = mtype;

	loadSprites();
	loadSpriteSize();
}

Missile::~Missile()
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
	ReactionTypes ret = ReactionTypes::Nothing;
	GameObject* hitObjectParent = hitObject->getParent();
	// Missile check if its shooting its own parent
	if (hitObjectParent != nullptr && parent != nullptr && *parent == *hitObjectParent)
		ret = ReactionTypes::Nothing;
	else
		ret = ReactionTypes::Destroy;
	return ReactionTypes::Nothing;
}