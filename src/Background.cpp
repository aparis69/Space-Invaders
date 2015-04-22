#include "Background.h"

Background::Background(void)
{
	sprite = new Sprite(0, 0, 0, 0, 0);
	currentSprite = 0;
	scroll.x = 0;
	scroll.y = 0;
}

Background::~Background(void)
{
}

void Background::updateScroll(int YRES)
{
	if(scroll.y >= 0)
		scroll.y -= 1;
	else
		scroll.y = 480;
}