#pragma once
#include <vector>

class PhysicsManager;
class GameObject;

// This class should NOT be initialized like this : ObjectManager* oM = new ObjectManager();
// It is used to factorize code between MissileManager & EnemyManager
class ObjectManager
{
protected:
	// vector of GameObject & its iterator
	std::vector<GameObject*> objectsOnScreen;
	std::vector<GameObject*>::iterator oIt;
	// Spawn timer in ms
	unsigned int spawnTimer;
	// Spawn delay in ms. An object will authorized to spawn every <spawnDelay> ms
	int spawnDelay;

	// Set all parent value to null to child gameobject
	// Dumb function : gameobject should store pointers to their children
	// @Cleanup
	void clearChild(GameObject*);

public:
	// Constructors & Destructor
	ObjectManager();
	virtual ~ObjectManager();

	// Member Functions
	virtual void manageVectorSize(PhysicsManager*);
	virtual void destroyObject(GameObject *);

	// Getter & Setter
	int getObjectCount() const;
	GameObject* getObject(int) const;
};