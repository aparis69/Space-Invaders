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
public:
    // Constructors & Destructor
    MissileManager();
    ~MissileManager();

    // create a missile at a certain position
    void spawnMissile(int, int, int, MissileTypes);
};