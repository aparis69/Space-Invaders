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
	Transform a = movedObject->getTransform();
    for (int i = 0 ; i < Context::getGameObjectCount() ; i++)
    {
        it = Context::getGameObjectIterator(i);
		if ((*it) != movedObject)
		{
			Transform b = (*it)->getTransform();
			if (collideWithGameObject(a, b))
				return (*it);
		}
    }
    return nullptr;
}


bool PhysicsManager::collideWithGameObject(Transform a, Transform b)
{
    if(a.X() + a.XSize() <= b.X() ||
        a.X() >= b.X() + b.XSize() ||
        a.Y() + a.YSize() <= b.Y()||
        a.Y() >= b.Y() + b.YSize())
        return false;
    return true;
}


bool PhysicsManager::isOutOfScreen(Transform t)
{
    if (t.X() + t.XSize() >= Window::XRES 
		|| t.Y() + t.YSize() >= Window::YRES 
		|| t.X() <= 0 
		|| t.Y() <= 0)
        return true;
    return false;
}