#include "Player.h"

Player::Player(void)
{
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

void Player::forward()
{
    movingForward = true;
    movingBackward = false;
}

void Player::backward()
{
    movingForward = false;
    movingBackward = true;
}

bool Player::isMovingForward() const
{
    return movingForward;
}

bool Player::isMovingBackward() const
{
    return movingBackward;
}

void Player::stop()
{
    movingBackward = movingForward = false;
}
