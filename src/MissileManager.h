#pragma once
#include <vector>
#include <chrono>
#include "ObjectManager.h"
#include "SDLinclude.h"
#include "Types.h"

class Missile;
class PhysicsManager;

class MissileManager : public ObjectManager
{
private:
	int spawnTimers[3];
	int spawnDelays[3];

public:
    // Constructors & Destructor
    MissileManager();
    ~MissileManager();

    // create a missile at a certain position
	// 
    void spawnMissile(int, int, MissileTypes, bool ignoreDelay = false);
};