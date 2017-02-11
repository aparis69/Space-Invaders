#include "MissileManager.h"
#include "PhysicsManager.h"
#include "Missile.h"
using namespace std;

MissileManager::MissileManager()
{
    timer = 0;
}

MissileManager::~MissileManager()
{
    for (mIt = missilesOnScreen.begin(); mIt != missilesOnScreen.end(); mIt++)
        delete (*mIt);
    missilesOnScreen.clear();
}

void MissileManager::shootMissile(int x, int y, int speed, MissileTypes type)
{
    // Look if the timer is finished
    if (SDL_GetTicks() < timer)
        return;
    missilesOnScreen.push_back(new Missile(x, y, speed, type));
    timer = SDL_GetTicks() + 500;
}

void MissileManager::manageVectorSize(PhysicsManager* physicsManager)
{
    // Look at missile out of screen bounds, and delete them
    bool erased = false;
    for (mIt = missilesOnScreen.begin(); mIt != missilesOnScreen.end(); ) // no mIt++ intentionally
    {
        erased = false;
        if (physicsManager->isOutOfScreen((*mIt)->getTransform().X(), 
										  (*mIt)->getTransform().Y()))
        {
            erased = true;
            delete (*mIt);
            mIt = missilesOnScreen.erase(mIt);
        }

        if (!erased)
            ++mIt;
        else if (mIt == missilesOnScreen.end())
            break;
    }
}

void MissileManager::destroyMissile(Missile* m)
{
    // Search for the missile m, delete it and return
    for (mIt = missilesOnScreen.begin(); mIt != missilesOnScreen.end(); mIt++)
    {
        if((*mIt) == m)
        {
            delete (*mIt);
            missilesOnScreen.erase(mIt);
            break;
        }
    }
}

int MissileManager::getMissileCount() const
{
    return missilesOnScreen.size();
}

Missile* MissileManager::getMissile(int i) const
{
    return missilesOnScreen.at(i);
}