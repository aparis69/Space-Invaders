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
    // Regarde les missiles en dehors de l'écran, et les détruit
    bool erased = false;
    for (std::vector<Missile*>::iterator it = missileInProgress.begin(); it != missileInProgress.end();)
    {
        erased = false;
        if (physicsManager->isOutOfScreen((*it)->getX(), (*it)->getY()))
        {
            erased = true;
            it = missileInProgress.erase(it);
        }

        if (!erased)
            ++it;
        else if (it == missileInProgress.end())
            break;
    }
}

void MissileManager::destroyMissile(Missile* m)
{
    for (mIterator = missileInProgress.begin(); mIterator != missileInProgress.end(); mIterator++)
    {
        if((*mIterator) == m)
        {
            missileInProgress.erase(mIterator);
            break;
        }
    }
}
