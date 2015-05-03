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
    // Variables
    std::vector<Missile*> missileInProgress;
    std::vector<Missile*>::iterator mIterator;
    float timer;

public:
    // Constructor & Destructor
    MissileManager(void);
    ~MissileManager(void);

    // Member functions
    void shootMissile(int xPos, int yPos, int speed, MissileTypes type);
    void manageVectorSize(PhysicsManager* physicsManager);
    void destroyMissile(Missile* m);

    // Getter & Setter
    int getNumberOfMissile() const;

    Missile* getMissile(int index) const;
};