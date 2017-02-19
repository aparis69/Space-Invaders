#include "ObjectManager.h"
#include "GameObject.h"
#include "PhysicsManager.h"
#include "Context.h"
#include <algorithm>
using namespace std;

// Constructors & Destructor
ObjectManager::ObjectManager()
{
	objectsOnScreen = vector<GameObject*>();
}

ObjectManager::~ObjectManager()
{
	for (oIt = objectsOnScreen.begin(); oIt != objectsOnScreen.end(); oIt++)
		delete (*oIt);
	objectsOnScreen.clear();
}


// Member Function
void ObjectManager::clearChild(GameObject* s)
{
	// set parent to null because s is gonna be destroyed
	std::vector<GameObject*> sceneObjs = Context::getGameObjects();
	for (auto it = sceneObjs.begin(); it != sceneObjs.end(); it++)
	{
		if ((*it)->getParent() != nullptr && *(*it)->getParent() == *s)
			(*it)->setParent(nullptr);
	}
}

void ObjectManager::manageVectorSize(PhysicsManager* physicsManager)
{
	// Look at missile out of screen bounds, and delete them
	Transform t;
	for (oIt = objectsOnScreen.begin(); oIt != objectsOnScreen.end(); ) // no mIt++ intentionally
	{
		if (physicsManager->isOutOfScreen((*oIt)->getTransform()))
		{
			clearChild((*oIt));
			delete (*oIt);
			oIt = objectsOnScreen.erase(oIt);
		}
		else
			++oIt;
	}
}

void ObjectManager::destroyObject(GameObject* o)
{
	auto it = std::find(objectsOnScreen.begin(), objectsOnScreen.end(), o);
	if ((*it) != nullptr)
	{
		clearChild((*it));
		delete (*it);
		objectsOnScreen.erase(it);
	}
}


// Getter & Setter
int ObjectManager::getObjectCount() const
{
	return objectsOnScreen.size();
}

GameObject* ObjectManager::getObject(int i) const
{
	return objectsOnScreen.at(i);
}