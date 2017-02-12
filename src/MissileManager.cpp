#include "MissileManager.h"
#include "PhysicsManager.h"
#include "Missile.h"
#include "Params.h"

MissileManager::MissileManager()
{
    spawnTimer = 0;
	spawnDelay = MISSILE_SPAWN_DELAY;
}

MissileManager::~MissileManager()
{
}

void MissileManager::spawnMissile(int x, int y, int speed, MissileTypes t)
{
    // Look if the timer is finished
    if (SDL_GetTicks() < spawnTimer)
        return;
    objectsOnScreen.push_back(new Missile(x, y, speed, t));
    spawnTimer = SDL_GetTicks() + spawnDelay;
}