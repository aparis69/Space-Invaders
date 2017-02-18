#include "MissileManager.h"
#include "PhysicsManager.h"
#include "Missile.h"
#include "Params.h"

MissileManager::MissileManager()
{
	spawnTimers[0] = spawnTimers[1] = spawnTimers[2] = 0;
	spawnDelays[0] = SMALL_MISSILE_SPAWN_DELAY;
	spawnDelays[1] = MEDIUM_MISSILE_SPAWN_DELAY;
	spawnDelays[2] = MEDIUM_MISSILE_SPAWN_DELAY;
}

MissileManager::~MissileManager()
{
}

void MissileManager::spawnMissile(int x, int y, MissileTypes t, bool ignoreDelay)
{
    // Look if the timer is finished
    if (SDL_GetTicks() < spawnTimers[(int)t])
        return;
	int speed = t == MissileTypes::Small ? SMALL_MISSILE_SPEED : t == MissileTypes::Medium ? MEDIUM_MISSILE_SPEED : BIG_MISSILE_SPEED;
    objectsOnScreen.push_back(new Missile(x, y, speed, t));
	if (!ignoreDelay)
		spawnTimers[(int)t] = SDL_GetTicks() + spawnDelays[(int)t];
}