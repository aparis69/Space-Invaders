#include "MissileManager.h"
#include "PhysicsManager.h"
#include "Missile.h"
#include "Params.h"

// Constructor & Destructor
MissileManager::MissileManager()
{
}

MissileManager::~MissileManager()
{
}

// Member Functions
void MissileManager::spawnMissile(int x, int y, Vec2 dir, MissileTypes t)
{
	int speed = t == MissileTypes::Small ? SMALL_MISSILE_SPEED : t == MissileTypes::Medium ? MEDIUM_MISSILE_SPEED : BIG_MISSILE_SPEED;
	if (dir.getY() < 0)
		speed = -speed;
    objectsOnScreen.push_back(new Missile(x, y, speed, t));
}