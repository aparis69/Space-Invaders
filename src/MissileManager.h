#pragma once
#include <vector>
#include <chrono>
#include "SDLinclude.h"
#include "MissileTypes.h"

class Missile;
class PhysicsManager;

class MissileManager
{
private:
    // Vector and iterator of all the missiles in the scene
    std::vector<Missile*> missilesOnScreen;
    std::vector<Missile*>::iterator mIt;
    // timer used to manage the ability to shoot a missile
    float timer;

public:
    // Constructors & Destructor
    MissileManager();
    ~MissileManager();

    // create a missile at a certain position
    void shootMissile(int xPos, int yPos, int speed, MissileTypes type);
    // delete all missiles out of screen
    void manageVectorSize(PhysicsManager* physicsManager);
    // destroy a missile into the missileInProgress vector
    void destroyMissile(Missile* m);

    // Getter & Setter
    int getMissileCount() const;
    Missile* getMissile(int index) const;
};