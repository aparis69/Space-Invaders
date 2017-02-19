#pragma once
#include "Transform.h"

class GameObject;

class PhysicsManager
{
private:
    bool collideWithGameObject(Transform, Transform);

public:
    // Constructors & Destructor
    PhysicsManager();
    ~PhysicsManager();

    // Return the gameobject hit by movedObject, or nullptr if there is not
    GameObject* collideWith(GameObject*);
    
    // Take some positions and size and return true of the object is out of screen
    bool isOutOfScreen(Transform);
};