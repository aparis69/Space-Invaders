#pragma once
#include "SDLinclude.h"
#include "Types.h"
#include "Transform.h"

class MissileManager;

class GameObject
{
protected:
	// Parent object : null most of the time
	GameObject* parent;

    // Indicate the type of the gameObject
    ObjectTypes type;

	// Transform, store basic info on gameobject (size, position...)
	Transform transform;

    // Array of the gameobject sprite
    int* sprite;
    // current sprite displayed on the screen
    int currentSprite;
    // size of the sprite* array
    int numberOfSprite;

    // Animation duration in ms (time a sprite stays on screen)
    int animDuration;
    // Ticks when sprite was changed for animation
    int ticksSinceAnim;

	// Used for gameobject that can shoot missiles
	int* spawnTimers;
	int* spawnDelays;

	// Collision timer
	bool castCollision;
	int collisionTimer;

public:
    // Constructors & Destructor
    GameObject();
    virtual ~GameObject();

    // Member functions
	virtual void update();
	virtual void shoot(MissileManager*, MissileTypes t = MissileTypes::Small, bool ignoreDelay = false, Transform* p = nullptr, bool upward = true);
    void updateAnimation();
    void loadSpriteSize();
	bool isOurs(GameObject*) const;

    // Virtual functions
    virtual void loadSprites() = 0;
    virtual ReactionTypes reactToCollision(GameObject* hitObject) = 0;

	// Operator overloading
	virtual bool operator==(const GameObject&) const;
	virtual bool operator!=(const GameObject&) const;

    // Moves function which depends on elapsed time since last render
    virtual int moveValueX(bool left = true) const;
    virtual int moveValueY(bool left = true) const;
    virtual void moveX(bool left = true);
    virtual void moveY(bool forward = true);
    virtual void move(bool forward = true, bool left = true);

    // Index image of the sprite to be displayed.
    int getCurrentSpriteIndex() const;
    // Getter & Setter
	bool compareType(GameObject*) const;
	void setParent(GameObject*);
	GameObject* getParent();
	Transform getTransform() const;
    ObjectTypes getObjectType() const;
};