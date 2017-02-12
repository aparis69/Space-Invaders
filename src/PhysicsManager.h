#pragma once
class GameObject;

class PhysicsManager
{
private:
    bool collideWithGameObject(int xPosM, int yPosM, int xSizeM, int ySizeM,
                               int xPosE, int yPosE, int xSizeE, int ySizeE);

public:
    // Constructors & Destructor
    PhysicsManager();
    ~PhysicsManager();

    // Return the gameobject hit by movedObject, or nullptr if there is not
    GameObject* collideWith(GameObject*);
    
    // Take some positions and size and return true of the object is out of screen
    bool isOutOfScreen(int, int, int = 0, int = 0);
};