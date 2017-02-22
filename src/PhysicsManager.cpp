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

CollisionInfo PhysicsManager::collideWith(GameObject* movedObject)
{
	CollisionInfo ret;
    vector<GameObject*>::iterator it;
	Transform a = movedObject->getTransform();
	auto objs	= Context::getGameObjects();
    for (auto& it : objs)
    {
		if (it != movedObject)
		{
			Transform b = it->getTransform();
			if (collideWithGameObject(a, b))
				ret.hitObjects.push_back(it);
		}
    }
    return ret;
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