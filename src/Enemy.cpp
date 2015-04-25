#include "Enemy.h"

Enemy::Enemy(void)
{
    type = ObjectTypes::Enemy;
    enemyType = EnemyType::Easy;
    x = -1;
    y = -1;
    
    // Size of enemy type 1
    xSize = 40;
    ySize = 57;    
    
    speedX = -1;
    speedY = -1;
    numberOfSprite = 4;
    currentSprite = 0;
}

Enemy::Enemy(int xPos, int yPos, int xSpeed, int ySpeed, EnemyType etype)
{
    type = ObjectTypes::Enemy;
    enemyType = etype;
    x = xPos;
    y = yPos;
    speedX = xSpeed;
    speedY = ySpeed;
    numberOfSprite = 4;
    currentSprite = 0;

    // Size of enemy type 1
    xSize = 40;
    ySize = 57;

    loadSprites();
}

void Enemy::loadSprites()
{
    sprite = new int[numberOfSprite];
    sprite[0] = 9;
    sprite[1] = 10;
    sprite[2] = 11;
    sprite[3] = 12;

    switch (type)
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