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

void GameObject::moveX(int elapsedTime, bool left)
{
    //cout << "Trying to move after " << elapsedTime << " ms" << endl;
    x+=moveValueX(elapsedTime, left);
    //cout << "Moved at " << SDL_GetTicks() << " of " << moveValueX(elapsedTime, left) << endl;
}

void GameObject::moveY(int elapsedTime, bool forward)
{
    y+=moveValueY(elapsedTime, forward);
}

void GameObject::move(bool forward, bool left)
{
    moveX(1, left);
    moveY(1, forward);
}

int GameObject::moveValueX(int elapsedTime, bool left) const
{
    if(left)
        return -speedX*10/FPS;
    else
        return speedX*10/FPS;
}

int GameObject::moveValueY(int elapsedTime, bool forward) const
{
    if(forward)
        return -speedY*FPS;
    else
        return speedY*FPS;
}
