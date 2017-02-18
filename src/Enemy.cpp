#include "Enemy.h"

Enemy::Enemy(void)
{
	type = ObjectTypes::Enemy;
	enemyType = EnemyType::Easy;
	numberOfSprite = 4;
	currentSprite = 0;
	transform.setXRotation(0);
	transform.setYRotation(-1);
}

Enemy::Enemy(int xPos, int yPos, int xSpeed, int ySpeed, EnemyType etype)
{
	type = ObjectTypes::Enemy;
	enemyType = etype;
	transform.setX(xPos);
	transform.setY(yPos);
	transform.SetXSpeed(xSpeed);
	transform.SetYSpeed(ySpeed);
	currentSprite = 0;
	transform.setXRotation(0);
	transform.setYRotation(-1);

	loadSprites();
	loadSpriteSize();
}

Enemy::~Enemy(void)
{
}

void Enemy::loadSprites()
{
	switch (enemyType)
	{
	case EnemyType::Easy:
		numberOfSprite = 1;
		sprite = new int[numberOfSprite];
		sprite[0] = 9;
		break;
	case EnemyType::Medium:
		numberOfSprite = 4;
		sprite = new int[numberOfSprite];
		sprite[0] = 10;
		sprite[1] = 11;
		sprite[2] = 12;
		sprite[3] = 13;
		break;
	case EnemyType::Hard:
		numberOfSprite = 4;
		sprite = new int[numberOfSprite];
		sprite[0] = 14;
		sprite[1] = 15;
		sprite[2] = 16;
		sprite[3] = 17;
		break;
	case EnemyType::Insane:
		numberOfSprite = 1;
		sprite = new int[numberOfSprite];
		sprite[0] = 13;
		break;
	}
}

ReactionTypes Enemy::reactToCollision(GameObject* hitObject)
{
	switch (hitObject->getObjectType())
	{
	case ObjectTypes::Enemy:
		return ReactionTypes::Nothing;
	default:
		return ReactionTypes::Destroy;
	}
}