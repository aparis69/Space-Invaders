#include "Context.h"
#include "Player.h"
#include "Background.h"
#include "MissileManager.h"
#include "Missile.h"
#include "PhysicsManager.h"
#include "Window.h"
#include "AssetManager.h"
#include "EnemyManager.h"
#include "Enemy.h"

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*
TO DO
-Introduce proper rotation
-Gérer collisions multiples : Context::ObjectHasMoved
-Gestion de layers pour les collisions
-ExplosionEffect/ParticleEffects
*/

// Init static array of gameObjects : all object in game scene
vector<GameObject*> Context::gameObjects = vector<GameObject*>();

// Constructors & Destructor
Context::Context()
{
	// Init Window and Managers
	window = new Window(WINDOW_SIZE_X, WINDOW_SIZE_Y, WINDOW_FPS, WINDOW_TITLE);
	physicsManager = new PhysicsManager();
	missileManager = new MissileManager();
	enemyManager = new EnemyManager();
	AssetManager::init();

	// Init GameObjects in the scene
	initGameObjects();

	// Init font
	fontColor.b = fontColor.r = fontColor.g = 0;
	lifePointsSurface = nullptr;
}

Context::~Context()
{
	gameObjects.clear();

	SDL_FreeSurface(lifePointsSurface);
	AssetManager::releaseData();
	delete player;
	delete background;
	delete missileManager;
	delete physicsManager;
	delete enemyManager;
	delete window;
}


// Member Functions
void Context::initGameObjects()
{
	objectsToDestroy = vector<GameObject*>();
	player = new Player();
	background = new Background();
	lastPlayerLifePoints = 0;
	hasLoose = false;
}

GameState Context::update(Input& in)
{
	GameState nextState = GAME;

	updatePlayer(in);
	updateGameObjects();
	updateBackground();
	determineGameState(in, nextState);
	cleanGameScene();

	render();

	return nextState;
}

void Context::updatePlayer(Input& in)
{
	// Check hasLoose boolean : only updated when transition from menu
	// to game scene
	if (hasLoose)
	{
		hasLoose = false;
		player->resetLifePoints();
	}

	// Storing temporary object to improve readability
	Transform t = player->getTransform();
	bool wasForward = player->isMovingForward();
	bool wasBackward = player->isMovingBackward();

	if (!in.Key(SDLK_UP) && !in.Key(SDLK_DOWN))
		player->stop();

	// Move the player after checking screen bounds
	Transform bound;
	if (in.Key(SDLK_UP)) // Up
	{
		bound = Transform(Vec2(t.X(), t.Y() + player->moveValueY()), t.getSize());
		if (!physicsManager->isOutOfScreen(bound))
		{
			player->moveY();
			player->forward();
		}
		else
			player->stop();
	}
	if (in.Key(SDLK_DOWN)) // Down
	{
		bound = Transform(Vec2(t.X(), t.Y() + player->moveValueY(false)), t.getSize());
		if (!physicsManager->isOutOfScreen(bound))
		{
			player->moveY(false);
			player->backward();
		}
		else
			player->stop();
	}
	if (in.Key(SDLK_LEFT)) // left
	{
		bound = Transform(Vec2(t.X() + player->moveValueX(), t.Y()), t.getSize());
		if (!physicsManager->isOutOfScreen(bound))
			player->moveX();
	}
	if (in.Key(SDLK_RIGHT)) // right
	{
		bound = Transform(Vec2(t.X() + player->moveValueX(false), t.Y()), t.getSize());
		if (!physicsManager->isOutOfScreen(bound))
			player->moveX(false);
	}
	if (in.Key(SDLK_e)) // Shoot medium missile
		player->shoot(missileManager, MissileTypes::Medium);
	if (in.Key(SDLK_SPACE)) // Shoot small missile (two by two)
	{
		Transform p = player->getTransform();
		p.setX(p.X() + 30);
		player->shoot(missileManager, MissileTypes::Small, true, &p);
		p.setX(p.X() + 30);
		player->shoot(missileManager, MissileTypes::Small, false, &p);
	}

	// Update the background behaviour based on the player move
	if (!wasForward && player->isMovingForward())
		background->speedUp();
	else if (!wasBackward && player->isMovingBackward())
		background->slowDown();
	else if ((wasForward && !player->isMovingForward())
		|| (wasBackward && !player->isMovingBackward()))
		background->idle();

	// Indicate to physicsManager an object has moved and can potentially collide with another
	objectHasMoved(player);
	// Animation timers
	player->updateAnimation();
	player->update();
}

void Context::updateGameObjects()
{
	enemyManager->manageEnemySpawn();
	auto eObjs = enemyManager->getObjects();
	// Update enemy logic
	for_each(eObjs.begin(), eObjs.end(), [this](auto& it)
	{
		it->move();
		it->updateAnimation();
		it->update();
		objectHasMoved(it);
	});
	// Delete enemies out of screen
	enemyManager->manageVectorSize(physicsManager);

	// Update missile logic
	auto mObjs = missileManager->getObjects();
	for_each(mObjs.begin(), mObjs.end(), [this](auto& it)
	{
		it->move();
		it->updateAnimation();
		objectHasMoved(it);
	});
	// Delete missile out of screen
	missileManager->manageVectorSize(physicsManager);
}

void Context::updateBackground()
{
	// Update the portion of background to display
	background->updateScroll();
}

void Context::cleanGameScene()
{
	for (auto& it : objectsToDestroy)
	{
		if (it->getObjectType() == ObjectTypes::Enemy)
			enemyManager->destroyObject(it);
		if (it->getObjectType() == ObjectTypes::Missile)
			missileManager->destroyObject(it);
		objectsToDestroy.erase(objectsToDestroy.begin());
	}
	objectsToDestroy.clear();
}

void Context::render()
{
	// Background directly blitted to make scrolling work
	SDL_Rect pos = background->getPosition();
	SDL_Surface* backgroundSurface = AssetManager::getSurface(background->getCurrentSpriteIndex());
	if (pos.y >= 0)
		SDL_BlitSurface(backgroundSurface, &pos, window->getSurface(), NULL);
	else
	{
		pos.h = pos.h + pos.y;
		int lastY = pos.y;
		pos.y = 0;
		SDL_BlitSurface(backgroundSurface, &pos, window->getSurface(), NULL);

		SDL_Rect dst;
		dst.x = 0;
		dst.y = Window::YRES - lastY;
		pos.y = 960 + lastY;
		pos.h = lastY*-1;
		SDL_BlitSurface(backgroundSurface, &pos, window->getSurface(), &dst);
		background->resetScroll();
	}

	// Player blitting
	window->blitSurface(AssetManager::getSurface(player->getCurrentSpriteIndex()),
		player->getTransform().X(),
		player->getTransform().Y());

	// Lifepoints blitting
	if (lastPlayerLifePoints != player->getLifePoints())
	{
		if (lifePointsSurface != nullptr)
			SDL_FreeSurface(lifePointsSurface);
		lastPlayerLifePoints = player->getLifePoints();
		lifePointsSurface = TTF_RenderText_Solid(window->getFont(),
			to_string(lastPlayerLifePoints).c_str(),
			fontColor);
	}
	window->blitSurface(lifePointsSurface, 5, 5);

	// Enemy blitting
	auto eObjs = enemyManager->getObjects();
	for (auto& it : eObjs)
		window->blitSurface(AssetManager::getSurface(it->getCurrentSpriteIndex()),
			it->getTransform().X(),
			it->getTransform().Y());

	// Missiles in progress blitting
	auto mObjs = missileManager->getObjects();
	for (auto& it : mObjs)
		window->blitSurface(AssetManager::getSurface(it->getCurrentSpriteIndex()),
			it->getTransform().X(),
			it->getTransform().Y());

	// Flip screen
	window->flipScreen();
}

void Context::gameOver()
{
	hasLoose = true;
}

void Context::objectHasMoved(GameObject* movedObject)
{
	// Check if the movedObject collide with something in the scene
	CollisionInfo info = physicsManager->collideWith(movedObject);
	for (auto& it : info.hitObjects)
	{
		if (it->getObjectType() != ObjectTypes::Other)
		{
			// Make the object react to the collision, and get their instructions
			// on the next action to do
			ReactionTypes movedObjectAction = movedObject->reactToCollision(it);
			ReactionTypes hitObjectAction = it->reactToCollision(movedObject);

			// Handle the reactions of the two objects
			handleReaction(movedObject, movedObjectAction);
			handleReaction(it, hitObjectAction);
		}
	}
}

void Context::handleReaction(GameObject* object, ReactionTypes reaction)
{
	// For now, the context only handle destruction of the gameobject
	// The others are handled by the gameobject itself
	switch (reaction)
	{
		// object wants to be destroyed
	case ReactionTypes::Destroy:
		// For enemy & missile, we destroy at the end of the frame
		// to avoid nullptr error in game logic part
		if (object->getObjectType() == ObjectTypes::Enemy)
			objectsToDestroy.push_back(object);
		if (object->getObjectType() == ObjectTypes::Missile)
			objectsToDestroy.push_back(object);
		if (object->getObjectType() == ObjectTypes::Player)
			gameOver();
		break;
	default:
		break;
	}
}

void Context::determineGameState(Input& in, GameState& s)
{
	if (in.wasKeyUpped(MENU_KEY))
		s = MENU;
	if (hasLoose)
		s = GAME_OVER;
}

Window* Context::getWindow() const
{
	return window;
}

std::vector<GameObject*>& Context::getGameObjects()
{
	return gameObjects;
}


// Static member functions
void Context::addGameObject(GameObject* object)
{
	gameObjects.push_back(object);
}

void Context::deleteGameObject(GameObject* object)
{
	for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		if ((*it) == object)
		{
			gameObjects.erase(it);
			return;
		}
	}
}

int Context::getGameObjectCount()
{
	return gameObjects.size();
}