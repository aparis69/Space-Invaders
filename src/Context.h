#pragma once
#include "Window.h"
#include "AssetManager.h"
#include "Input.h"
#include "GameObject.h"
#include "MissileManager.h"
#include "PhysicsManager.h"

class Context
{
	private:
		// Variables
		Window* window;
		AssetManager* assetManager;
		MissileManager* missileManager;
		PhysicsManager* physicsManager;
		std::vector<GameObject*> gameObjects;

		// Private functions
		void initGameObjects();
		void updateBackground();
		void updatePlayer(Input& in);
		void updateAI();
		void updateGameObjects();

	public:
		// Constructor & Destructor
		Context(void);
		~Context(void);

		// Member functions
		void update(Input& in);
		void render();

		// Getter & Setter
		bool gameOver();
};