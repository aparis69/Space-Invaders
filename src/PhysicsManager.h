#pragma once
class GameObject;

class PhysicsManager
{
private:
    int XRES;
    int YRES;

    bool collideWithGameObject(int xPosM, int yPosM, int xSizeM, int ySizeM,
                               int xPosE, int yPosE, int xSizeE, int ySizeE);

public:
    // Constructor & Destructor
    PhysicsManager(void);
    PhysicsManager(int xres, int yres);
    ~PhysicsManager(void);

    // Return the gameobject hit by movedObject, or null if there is not
    GameObject* collideWith(GameObject* movedObject);
    
    // Take some positions and size and return true of the object is out of screen
    bool isOutOfScreen(int xPos, int yPos, int xSize, int ySize);
    bool isOutOfScreen(int xPos, int yPos);

    // Getter & Setter
    void setXRES(int xres);
    void setYRES(int yres);
    int getXRES() const;
    int getYRES() const;
};