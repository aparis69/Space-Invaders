#include "Player.h"

Player::Player(void)
{
    type = ObjectTypes::Player;
    speedY = speedX = 0.1;
    xSize = 93;
    ySize = 97;
    x = 200;
    y = 200;
    numberOfSprite = 4;
    currentSprite = 0;
    animDuration = 50;
    loadSprites();
}

Player::Player(float speed)
{
    type = ObjectTypes::Player;
    speedY = speedX = speed;
    xSize = 93;
    ySize = 97;
    x = 200;
    y = 200;
    numberOfSprite = 4;
    currentSprite = 0;
    animDuration = 50;
    loadSprites();
}

void Player::loadSprites()
{
    sprite = new int[numberOfSprite];
    sprite[0] = 1;
    sprite[1] = 2;
    sprite[2] = 3;
    sprite[3] = 4;
}
