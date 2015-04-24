#include "Missile.h"

Missile::Missile(void)
{
    numberOfSprite = 4;
    currentSprite = 0;
    speedY = -6;
    startingXPos = -1;
    startingYPos = -1;
}

Missile::Missile(int xPos, int yPos, int speed, MissileType type)
{
    numberOfSprite = 4;
    currentSprite = 0;
    speedY = speed;
    missileType = type;

    startingXPos = xPos;
    startingYPos = yPos;

    loadSprites();
}

void Missile::loadSprites()
{
    sprite = new int[numberOfSprite];
    sprite[0] = 5;
    sprite[1] = 6;
    sprite[2] = 7;
    sprite[3] = 8;
}
