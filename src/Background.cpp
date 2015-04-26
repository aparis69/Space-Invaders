#include "Background.h"
#include "Window.h"

#include <iostream>

Background::Background(int scrollSpeed)
{
    type = ObjectTypes::Other;
    currentSprite = 0;
    scroll.x = 0;
    scroll.y = 480;
    scroll.w = 640;
    scroll.h = 480;
    this->scrollSpeed = scrollSpeed;
    lastScroll = SDL_GetTicks();
    
    loadSprites();
}

void Background::updateScroll()
{
    float adjust = scrollSpeed;
    if(slowingDown)
        adjust-=SPEED_ADJUST;
    else if(speedingUp)
        adjust+=SPEED_ADJUST;
    Uint32 now = SDL_GetTicks();
    adjust*=(now-lastScroll)/1000.f;
    scroll.y -= adjust;
    lastScroll = now;
}

void Background::loadSprites()
{
    sprite = new int[1];
    sprite[0] = 0;
}

void Background::resetScroll()
{
    scroll.y = 480;
}

void Background::speedUp()
{
    speedingUp = true;
    slowingDown = false;
}

void Background::slowDown()
{
    speedingUp = false;
    slowingDown = true;
}

void Background::idle()
{
    speedingUp = slowingDown = false;
}
