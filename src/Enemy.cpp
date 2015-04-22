#include "Enemy.h"

Enemy::Enemy(void)
{
}

Enemy::Enemy(int speed, EnemyType etype)
{
	ennemySpeed = speed;
	type = etype;
}

void Enemy::loadSprite()
{
	switch(type)
	{
		case EnemyType::Easy:
			break;
		case EnemyType::Medium:
			break;
		case EnemyType::Hard:
			break;
		case EnemyType::Insane:
			break;
	}
}