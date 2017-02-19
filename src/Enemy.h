#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
private:
	EnemyType enemyType;

public:
	// Constructors & Destructor
	Enemy();
	Enemy(Vec2, Vec2, EnemyType);
	~Enemy();

	// Member functions
	void loadSprites();
	ReactionTypes reactToCollision(GameObject*);
};