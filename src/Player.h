#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
    // Constructor & Destructor
    Player(void);
    Player(float speed);

    ~Player(void)
    {
    }

    void loadSprites();
};

