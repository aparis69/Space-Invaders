#include "Enemy.h"
#include "Params.h"

Enemy::Enemy()
{
	type = ObjectTypes::Enemy;
	enemyType = EnemyType::Easy;
	numberOfSprite = 4;
	currentSprite = 0;
	transform.setXRotation(0);
	transform.setYRotation(-1);

	spawnDelays[0] = SMALL_MISSILE_SPAWN_DELAY_ENEMY;
}

Enemy::Enemy(Vec2 pos, Vec2 speed, EnemyType etype)
{
	type = ObjectTypes::Enemy;
	enemyType = etype;
	transform.setPosition(pos);
	transform.setSpeed(speed);
	transform.setXRotation(0);
	transform.setYRotation(-1);
	currentSprite = 0;
	spawnDelays[0] = SMALL_MISSILE_SPAWN_DELAY_ENEMY;

	loadSprites();
	loadSpriteSize();
}

Enemy::~Enemy()
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
	ReactionTypes ret = ReactionTypes::Nothing;
	if (!castCollision) 
		return ret;

	switch (hitObject->getObjectType())
	{
	case ObjectTypes::Player:
		ret = ReactionTypes::Destroy;
		break;
	case ObjectTypes::Enemy:
		ret = ReactionTypes::Nothing;
		break;
	case ObjectTypes::Missile:
		// If this enemy is not shooted by his own missile
		// or by a friendly fire
		if (isOurs(hitObject->getParent()) || compareType(hitObject->getParent()))
			break;
		collisionTimer = SDL_GetTicks() + COLLISION_DELAY;
		castCollision = false;
		ret = ReactionTypes::Destroy;
		break;
	}
	return ret;
}