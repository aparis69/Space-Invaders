#include "GameObject.h"
#include "Global.h"

#include <iostream>
using namespace std;

GameObject::GameObject(void)
{
    sprite = nullptr;
    ticksSinceAnim = -1;
}

GameObject::~GameObject(void)
{
    delete sprite;
}

void GameObject::updateAnimation()
{
    int now = SDL_GetTicks();
    // Change animation's image
    if(now-ticksSinceAnim > animDuration)
    {
        currentSprite++;
        currentSprite %= numberOfSprite;
        ticksSinceAnim = now;
    }
}

void GameObject::moveX(bool left)
{
    x+=moveValueX(left);
}

void GameObject::moveY(bool forward)
{
    y+=moveValueY(forward);
}

void GameObject::move(bool forward, bool left)
{
    moveX(left);
    moveY(forward);
}

int GameObject::moveValueX(bool left) const
{
    if(left)
        return (int)(-speedX*10/FPS);
    else
        return (int)(speedX*10/FPS);
}

int GameObject::moveValueY(bool forward) const
{
    if(forward)
        return (int)(-speedY*10/FPS);
    else
        return (int)(speedY*10/FPS);
}
