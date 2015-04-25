#include "Missile.h"

Missile::Missile(void)
{
    type = ObjectTypes::Missile;
    numberOfSprite = 4;
    currentSprite = 0;
    speedY = -6;
    x = -1;
    y = -1;
    animDuration = 0;
}

Missile::Missile(int xPos, int yPos, int speed, MissileType mtype)
{
    type = ObjectTypes::Missile;
    numberOfSprite = 4;
    currentSprite = 0;
    speedY = speed;
    speedX = 0;
    animDuration = 40;
    missileType = mtype;

    x = xPos;
    y = yPos;

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
