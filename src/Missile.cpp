#include "Missile.h"

Missile::Missile(void)
{
	numberOfSprite = 4;
	currentSprite = 0;
	missileSpeed = -6;

	sprite = new Sprite[4];
	sprite[0] = Sprite(5, 280, 320, 0, missileSpeed);
	sprite[1] = Sprite(6, 280, 320, 0, missileSpeed);
	sprite[2] = Sprite(7, 280, 320, 0, missileSpeed);
	sprite[3] = Sprite(8, 280, 320, 0, missileSpeed);
}

Missile::Missile(int xPos, int yPos, int speed)
{
	numberOfSprite = 4;
	currentSprite = 0;
	missileSpeed = speed;

	sprite = new Sprite[4];
	sprite[0] = Sprite(5, xPos, yPos, 0, missileSpeed);
	sprite[1] = Sprite(6, xPos, yPos, 0, missileSpeed);
	sprite[2] = Sprite(7, xPos, yPos, 0, missileSpeed);
	sprite[3] = Sprite(8, xPos, yPos, 0, missileSpeed);
}