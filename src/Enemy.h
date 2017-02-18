#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
private:
	EnemyType enemyType;

public:
	// Constructors & Destructor
	Enemy();
	Enemy(int, int, int, int, EnemyType);
	~Enemy();

	// Member functions
	void loadSprites();
	ReactionTypes reactToCollision(GameObject*);
};