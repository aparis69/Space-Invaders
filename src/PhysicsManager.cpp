#include "PhysicsManager.h"
#include "GameObject.h"
#include "Context.h"
#include <vector>
using namespace std;

PhysicsManager::PhysicsManager(void)
{
    XRES = -1;
    YRES = -1;
}

PhysicsManager::PhysicsManager(int xres, int yres)
{
    XRES = xres;
    YRES = yres;
}

GameObject* PhysicsManager::collideWith(GameObject* movedObject)
{
    vector<GameObject*>::iterator it;
    for (int i = 0 ; i < Context::getGameObjectCount() ; i++)
    {
        it = Context::getGameObjectIterator(i);
        if((*it) != movedObject && collideWithGameObject(movedObject->getX(), movedObject->getY(), movedObject->getXSize(), movedObject->getYSize(),
            (*it)->getX(), (*it)->getY(), (*it)->getXSize(), (*it)->getYSize()))
            return (*it);
    }

    return nullptr;
}

bool PhysicsManager::collideWithGameObject(int xPosM, int yPosM, int xSizeM, int ySizeM,
                                           int xPosE, int yPosE, int xSizeE, int ySizeE)
{
    if(xPosM + xSizeM < xPosE ||
       xPosM > xPosE + xSizeE ||
       yPosM + ySizeM < yPosE ||
       yPosM > yPosE + ySizeE)
       return false;
    
    return true;
}

bool PhysicsManager::isOutOfScreen(int xPos, int yPos, int xSize, int ySize)
{
    if (xPos + xSize >= XRES || yPos + ySize >= YRES || xPos <= 0 || yPos <= 0)
        return true;

    return false;
}

bool PhysicsManager::isOutOfScreen(int xPos, int yPos)
{
    if (xPos >= XRES || yPos >= YRES || xPos <= 0 || yPos <= 0)
        return true;

    return false;
}