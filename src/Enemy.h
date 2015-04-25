#pragma once
#include "GameObject.h"
#include "EnemyTypes.h"

class Enemy : public GameObject
{
private:
    EnemyType enemyType;

public:
    // Constructor & Destructor
    Enemy(void);
    Enemy(int xPos, int yPos, int xSpeed, int ySpeed, EnemyType type);

    ~Enemy(void)
    {
    }

    // Member functions
    void loadSprites();
    ReactionTypes reactToCollision(GameObject* hitObject);
};
