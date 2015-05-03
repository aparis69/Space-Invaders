#include "MissileManager.h"
#include "PhysicsManager.h"
#include "Missile.h"
using namespace std;

MissileManager::MissileManager(void)
{
    timer = -1;
}

MissileManager::~MissileManager(void)
{
    for (mIterator = missileInProgress.begin(); mIterator != missileInProgress.end(); mIterator++)
        delete (*mIterator);

    missileInProgress.clear();
}

void MissileManager::shootMissile(int xPos, int yPos, int speed, MissileType type)
{
    if (SDL_GetTicks() < timer)
        return;

    missileInProgress.push_back(new Missile(xPos, yPos, speed, type));
    timer = SDL_GetTicks() + 500;
}

void MissileManager::manageVectorSize(PhysicsManager* physicsManager)
{
    // Look at missile out of screen bounds, and delete them
    bool erased = false;
    for (mIterator = missileInProgress.begin(); mIterator != missileInProgress.end();)
    {
        erased = false;
        if (physicsManager->isOutOfScreen((*mIterator)->getX(), (*mIterator)->getY()))
        {
            erased = true;
            delete (*mIterator);
            mIterator = missileInProgress.erase(mIterator);
        }

        if (!erased)
            ++mIterator;
        else if (mIterator == missileInProgress.end())
            break;
    }
}

void MissileManager::destroyMissile(Missile* m)
{
    for (mIterator = missileInProgress.begin(); mIterator != missileInProgress.end(); mIterator++)
    {
        if((*mIterator) == m)
        {
            delete (*mIterator);
            missileInProgress.erase(mIterator);
            break;
        }
    }
}

int MissileManager::getNumberOfMissile() const
{
    return missileInProgress.size();
}

Missile* MissileManager::getMissile(int index) const
{
    return missileInProgress.at(index);
}