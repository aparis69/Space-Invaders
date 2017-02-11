#pragma once
#include "GameObject.h"
#include "MissileTypes.h"

class Missile : public GameObject
{
private:
    MissileTypes missileTypes;

public:
    // Constructors & Destructor
    Missile();
    Missile(int, int, int, MissileTypes);
    ~Missile();

    // Member functions
    void loadSprites();
    ReactionTypes reactToCollision(GameObject* hitObject);
};