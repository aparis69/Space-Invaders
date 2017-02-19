#pragma once
#include "GameObject.h"

class Missile : public GameObject
{
private:
    MissileTypes missileTypes;

public:
    // Constructors & Destructor
    Missile();
    Missile(Vec2, int, MissileTypes, GameObject*);
    ~Missile();

    // Member functions
    void loadSprites();
    ReactionTypes reactToCollision(GameObject* hitObject);
};