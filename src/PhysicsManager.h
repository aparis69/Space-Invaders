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

    ~PhysicsManager(void)
    {
    }

    // Return the gameobject hit by movedObject, or null if there is not
    GameObject* collideWith(GameObject* movedObject);
    
    // Member functions
    bool isOutOfScreen(int xPos, int yPos, int xSize, int ySize);
    bool isOutOfScreen(int xPos, int yPos);

    // Getter & Setter

    inline void setXRES(int xres)
    {
        XRES = xres;
    }

    inline void setYRES(int yres)
    {
        YRES = yres;
    }

    inline int getXRES() const
    {
        return XRES;
    }

    inline int getYRES() const
    {
        return YRES;
    }
};