#pragma once
#include "GameObject.h"
#include "EnemyTypes.h"

class Enemy : public GameObject
{
private:
    EnemyType type;

public:
    // Constructor & Destructor
    Enemy(void);
    Enemy(int xPos, int yPos, int xSpeed, int ySpeed, EnemyType type);

    ~Enemy(void)
    {
    }

    // Member functions
    void loadSprites();
    ActionTypes reactToCollision(GameObject* hitObject) { return ActionTypes::Destroy; }
};
