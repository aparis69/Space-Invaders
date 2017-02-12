#include "ObjectManager.h"
#include "GameObject.h"
#include "PhysicsManager.h"
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
void ObjectManager::manageVectorSize(PhysicsManager* physicsManager)
{
	// Look at missile out of screen bounds, and delete them
	oIt = objectsOnScreen.begin();
	Transform t;
	for (; oIt != objectsOnScreen.end();) // no mIt++ intentionally
	{
		t = (*oIt)->getTransform();
		if (physicsManager->isOutOfScreen(t.X(), t.Y()))
		{
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