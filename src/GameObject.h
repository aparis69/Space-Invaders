#pragma once
#include "SDLinclude.h"
#include "ReactionTypes.h"
#include "ObjectTypes.h"

class GameObject
{
protected:
    // Indicate the type of the gameObject
    ObjectTypes type;

    int* sprite;
    int currentSprite;
    int numberOfSprite;
    //Current positions of object on screen (pixels)
    int x, y;
    // Size of the game object
    int xSize, ySize;
    //Speeds of the object in pixels/ms
    int speedX, speedY;
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
    void loadSpriteSize();

    // Virtual functions
    virtual void loadSprites() = 0;
    virtual ReactionTypes reactToCollision(GameObject* hitObject) = 0;

    //Moves function which depends on elapsed time since last render
    virtual int moveValueX(bool left = true) const;
    virtual int moveValueY(bool left = true) const;
    virtual void moveX(bool left = true);
    virtual void moveY(bool forward = true);
    virtual void move(bool forward = true, bool left = true);

    //Index image of the sprite to be displayed.
    int getCurrentSpriteIndex() const;

    int getX() const;

    int getY() const;

    int getXSize() const;

    int getYSize() const;

    int getXSpeed() const;

    int getYSpeed() const;

    void setYSpeed(int s);

    void setXSpeed(int s);

    ObjectTypes getObjectType() const;
};
