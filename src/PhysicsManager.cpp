#include "PhysicsManager.h"
#include "GameObject.h"
#include "Context.h"
#include "Window.h"

#include <vector>
using namespace std;

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}

GameObject* PhysicsManager::collideWith(GameObject* movedObject)
{
    vector<GameObject*>::iterator it;
	Transform t = movedObject->getTransform();
	int x = t.X();
	int y = t.Y();
	int xSize = t.XSize();
	int ySize = t.YSize();

    for (int i = 0 ; i < Context::getGameObjectCount() ; i++)
    {
        it = Context::getGameObjectIterator(i);

		if ((*it) != movedObject)
		{
			Transform itT = (*it)->getTransform();
			if (collideWithGameObject(x, y, xSize, ySize, itT.X(), itT.Y(), itT.XSize(), itT.YSize()))
				return (*it);
		}
    }
    return nullptr;
}


bool PhysicsManager::collideWithGameObject(int xPosM, int yPosM, int xSizeM, int ySizeM,
                                           int xPosE, int yPosE, int xSizeE, int ySizeE)
{
    if(xPosM + xSizeM <= xPosE ||
        xPosM >= xPosE + xSizeE ||
        yPosM + ySizeM <= yPosE ||
        yPosM >= yPosE + ySizeE)
        return false;

    return true;
}


bool PhysicsManager::isOutOfScreen(int xPos, int yPos, int xSize, int ySize)
{
    if (xPos + xSize >= Window::XRES 
		|| yPos + ySize >= Window::YRES 
		|| xPos <= 0 
		|| yPos <= 0)
        return true;

    return false;
}