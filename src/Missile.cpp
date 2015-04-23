#include "Missile.h"

Missile::Missile(void)
{
    numberOfSprite = 4;
    currentSprite = 0;
    missileSpeed = -6;
    startingXPos = -1;
    startingYPos = -1;

    sprite = new Sprite[4];
}

Missile::Missile(int xPos, int yPos, int speed, MissileType type)
{
    numberOfSprite = 4;
    currentSprite = 0;
    missileSpeed = speed;
    missileType = type;

    startingXPos = xPos;
    startingYPos = yPos;

    loadSprites();
}

void Missile::loadSprites()
{
    sprite = new Sprite[4];
    sprite[0] = Sprite(5, startingXPos, startingYPos, 0, missileSpeed);
    sprite[1] = Sprite(6, startingXPos, startingYPos, 0, missileSpeed);
    sprite[2] = Sprite(7, startingXPos, startingYPos, 0, missileSpeed);
    sprite[3] = Sprite(8, startingXPos, startingYPos, 0, missileSpeed);
}