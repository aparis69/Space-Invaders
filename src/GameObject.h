#pragma once
#include "SDLinclude.h"
#include "Sprite.h"

class GameObject
{
protected:
    int* sprite;
    int currentSprite;
    int numberOfSprite;
    //Current positions of object on screen (pixels)
    int x, y;
    // Size of the game object
    int xSize, ySize;
    //Speeds of the object in pixels/ms
    float speedX, speedY;
    //Animation duration in ms (time a sprite stays on screen)
    int animDuration;
    //Ticks when sprite was changed for animation
    int ticksSinceAnim;

public:
    // Constructor & Destructor
    GameObject(void);
    virtual ~GameObject(void);

    // Member functions
    void updateAnimation();

    // Virtual functions
    virtual void loadSprites() = 0;

    //Moves function which depends on elapsed time since last render
    virtual int moveValueX(int elapsedTime, bool left = true) const;
    virtual int moveValueY(int elapsedTime, bool left = true) const;
    virtual void moveX(int elapsedTime, bool left = true);
    virtual void moveY(int elapsedTime, bool forward = true);
    virtual void move(bool forward = true, bool left = true);

    //Index image of the sprite to be displayed.
    virtual inline int getCurrentSpriteIndex() const
    {
        return sprite[currentSprite];
    }

    inline int getX() const
    {
        return x;
    }

    inline int getY() const
    {
        return y;
    }

    inline int getXSize() const
    {
        return xSize;
    }

    inline int getYSize() const
    {
        return ySize;
    }

    inline float getXSpeed() const
    {
        return speedX;
    }

    inline float getYSpeed() const
    {
        return speedY;
    }
};
