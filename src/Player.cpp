#include "Player.h"

Player::Player(void)
{
	playerSpeed = 4;

	numberOfSprite = 4;
	sprite = new Sprite[numberOfSprite];
	sprite[0] = Sprite(1, 280, 320, 0, 0);
	sprite[1] = Sprite(2, 280, 320, 0, 0);
	sprite[2] = Sprite(3, 280, 320, 0, 0);
	sprite[3] = Sprite(4, 280, 320, 0, 0);

	currentSprite = 0;
}

Player::Player(int speed)
{
	playerSpeed = speed;

	numberOfSprite = 4;
	sprite = new Sprite[numberOfSprite];
	sprite[0] = Sprite(1, 280, 320, 0, 0);
	sprite[1] = Sprite(2, 280, 320, 0, 0);
	sprite[2] = Sprite(3, 280, 320, 0, 0);
	sprite[3] = Sprite(4, 280, 320, 0, 0);

	currentSprite = 0;
}