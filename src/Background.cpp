#include "Background.h"
#include "Window.h"

Background::Background(int scrollSpeed)
{
    currentSprite = 0;
    scroll.x = 0;
    scroll.y = 480;
    scroll.w = 640;
    scroll.h = 480;
    this->scrollSpeed = scrollSpeed;
    loadSprites();
}

void Background::updateScroll()
{
    scroll.y -= scrollSpeed/Window::FPS;
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
