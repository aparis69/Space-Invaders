#include "Background.h"

Background::Background(void)
{
    currentSprite = 0;
    scroll.x = 0;
    scroll.y = 0;
    scroll.w = 640;
    scroll.h = 480;

    loadSprites();
}

void Background::updateScroll()
{
    if (scroll.y >= 0)
        scroll.y -= 1;
    else
        scroll.y = 480;
}

void Background::loadSprites()
{
    sprite = new int[1];
    sprite[0] = 0;
}
