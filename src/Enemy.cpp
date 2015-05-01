#include "Enemy.h"

Enemy::Enemy(void)
{
    type = ObjectTypes::Enemy;
    enemyType = EnemyType::Easy;
    x = -1;
    y = -1;   
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
    currentSprite = 0;
    loadSprites();
    loadSpriteSize();
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
    switch(hitObject->getObjectType())
    {
        case ObjectTypes::Enemy:
            speedX = -speedX;
            speedY = -speedY;
            move();
            return ReactionTypes::ChangeDirection;
        default:
            return ReactionTypes::Destroy;
    }
}