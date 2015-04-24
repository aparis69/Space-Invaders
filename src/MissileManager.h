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
    void shootMissile(int xPos, int yPos, int speed, MissileType type);
    void updateMissileInProgress();
    void manageVectorSize(PhysicsManager* physicsManager);

    // Getter & Setter

    int getNumberOfMissile() const
    {
        return missileInProgress.size();
    }

    Missile* getMissile(int index) const
    {
        return missileInProgress.at(index);
    }
};