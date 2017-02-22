#pragma once

#include "Input.h"
#include "Types.h"
#include "Params.h"

#include <vector>
#include <SDL_ttf.h>

class Window;
class AssetManager;
class MissileManager;
class PhysicsManager;
class EnemyManager;
class Player;
class Background;
class GameObject;

class Context
{
private:
	// Static array of all the gameObject in the scene
	static std::vector<GameObject*> gameObjects;

	// Temporary array : store the object that will be destroyed at the end of the frame
	std::vector<GameObject*> objectsToDestroy;

	// Manager
	MissileManager* missileManager;
	PhysicsManager* physicsManager;
	EnemyManager* enemyManager;

	// Unique Objects
	Player* player;
	unsigned int lastPlayerLifePoints;
	Background* background;
	Window* window;
	bool hasLoose;

	// HUD variables
	SDL_Color fontColor;
	SDL_Surface* lifePointsSurface;

	// Init all the gameobject at the beginning of the game
	void initGameObjects();
	// Update the background image position (scrolling)
	void updateBackground();
	// Update the player position and action based on input
	void updatePlayer(Input&);
	// Update other game object position and action, like missiles&enemies
	void updateGameObjects();
	// Destroy object no longer needed
	void cleanGameScene();

	// Determine the GameState of the next frame
	void determineGameState(Input&, GameState&);
	
	// Call physicsManager to check collision & react depending on return value
	void objectHasMoved(GameObject* movedObject);
	// Handle the gameObject reaction to collision
	void handleReaction(GameObject* object, ReactionTypes reaction);

public:
	// Constructor & Destructor
	Context();
	~Context();

	// Member functions
	GameState update(Input& in);
	void render();
	void gameOver();

	// Getter & Setter
	Window* getWindow() const;

	// Static function, interact with the gameObject array
	static std::vector<GameObject*>& getGameObjects();
	static void addGameObject(GameObject* object);
	static void deleteGameObject(GameObject* object);
	static int getGameObjectCount();
};