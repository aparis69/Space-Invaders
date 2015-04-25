#include "Player.h"

Player::Player(void)
{
    type = ObjectTypes::Player;
    speedY = speedX = 0.1;
    xSize = 93;
    ySize = 97;
    spawn();
    numberOfSprite = 4;
    currentSprite = 0;
    animDuration = 50;
    lifePoints = START_LP;
    loadSprites();
}

Player::Player(float speed)
{
    type = ObjectTypes::Player;
    speedY = speedX = speed;
    spawn();
    numberOfSprite = 4;
    currentSprite = 0;
    animDuration = 50;
    lifePoints = START_LP;
    
    loadSprites();
    loadSpriteSize();
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

ReactionTypes Player::reactToCollision(GameObject* hitObject)
{
    ReactionTypes ret;
    switch(hitObject->getObjectType())
    {
        case ObjectTypes::Enemy:
            // currently calling Context::gameOver(), which does nothing
            ret = ReactionTypes::Destroy;
            lifePoints--;
            spawn();
        default:
            ret = ReactionTypes::Nothing;
    }
    return ret;
}

unsigned int Player::getLifePoints() const
{
    return lifePoints;
}

void Player::spawn()
{
    x = X_SPAWN;
    y = Y_SPAWN;
}
