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

#include <iostream>
#include <string>

using namespace std;

// Init static array of gameObjects
vector<GameObject*> Context::gameObjects = vector<GameObject*>();

// Constructors & Destructor
Context::Context()
{
	// Init Window and Managers
	window = new Window(WINDOW_SIZE_X, WINDOW_SIZE_Y, WINDOW_FPS, WINDOW_TITLE);
	assetManager = new AssetManager();
	physicsManager = new PhysicsManager();
	missileManager = new MissileManager();
	enemyManager = new EnemyManager();

	// Init GameObjects in the scene
	initGameObjects();

	// Init font
	fontColor.b = fontColor.r = fontColor.g = 0;
	lifePointsSurface = nullptr;
}

Context::~Context()
{
	gameObjects.clear();

	delete player;
	delete background;
	delete missileManager;
	delete physicsManager;
	delete enemyManager;
	delete assetManager;
	delete window;
	SDL_FreeSurface(lifePointsSurface);
}


// Member Functions
void Context::initGameObjects()
{
	player = new Player(PLAYER_SPEED);
	background = new Background(SCROLL_SPEED);
	lastPlayerLifePoints = 0;
}

void Context::update(Input& in)
{
	updatePlayer(in);
	updateAI();
	updateGameObjects();
	updateBackground();

	render();
}

void Context::updatePlayer(Input& in)
{
	// Storing temporary object to improve readability
	Transform t = player->getTransform();
	bool wasForward = player->isMovingForward();
	bool wasBackward = player->isMovingBackward();

	if (!in.Key(SDLK_UP) && !in.Key(SDLK_DOWN))
		player->stop();

	// Move the player after checking screen bounds
	if (in.Key(SDLK_UP)) // Up
	{
		if (!physicsManager->isOutOfScreen(t.X(), t.Y() + player->moveValueY(), t.XSize(), t.YSize()))
		{
			player->moveY();
			player->forward();
		}
		else
			player->stop();
	}
	if (in.Key(SDLK_DOWN)) // Down
	{
		if (!physicsManager->isOutOfScreen(t.X(), t.Y() + player->moveValueY(false), t.XSize(), t.YSize()))
		{
			player->moveY(false);
			player->backward();
		}
		else
			player->stop();
	}
	if (in.Key(SDLK_LEFT) && !physicsManager->isOutOfScreen(t.X() + player->moveValueX(), t.Y(), t.XSize(), t.YSize())) // left
		player->moveX();
	if (in.Key(SDLK_RIGHT) && !physicsManager->isOutOfScreen(t.X() + player->moveValueX(false), t.Y(), t.XSize(), t.YSize())) // right
		player->moveX(false);
	if (in.Key(SDLK_SPACE)) // Shoot missile
		missileManager->spawnMissile(t.X(), t.Y(), MEDIUM_MISSILE_SPEED, MissileTypes::Small);

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

	player->updateAnimation();
}

void Context::updateAI()
{
	// Decide if new enemies spawn or not
	enemyManager->manageEnemySpawn();

	// Update enemies position and animation
	for (int i = 0; i < enemyManager->getObjectCount(); i++)
	{
		enemyManager->getObject(i)->move();
		enemyManager->getObject(i)->updateAnimation();
	}

	// Indicate to the physics manager that the enemies have moved
	for (int i = 0; i < enemyManager->getObjectCount(); i++)
		objectHasMoved(enemyManager->getObject(i));

	// Manage enemy out of screen
	enemyManager->manageVectorSize(physicsManager);
}

void Context::updateGameObjects()
{
	// Update missiles in progress and animation
	for (int i = 0; i < missileManager->getObjectCount(); i++)
	{
		missileManager->getObject(i)->move();
		missileManager->getObject(i)->updateAnimation();
	}

	// Indicate to the physics manager that the missiles have moved
	for (int i = 0; i < missileManager->getObjectCount(); i++)
		objectHasMoved(missileManager->getObject(i));

	// Delete missile out of screen
	missileManager->manageVectorSize(physicsManager);
}

void Context::updateBackground()
{
	// Update the portion of background to display
	background->updateScroll();
}

void Context::render()
{
	// Background directly blitted to make scrolling work
	SDL_Rect pos = background->getPosition();
	SDL_Surface* backgroundSurface = assetManager->getSurface(background->getCurrentSpriteIndex());
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
	window->blitSurface(assetManager->getSurface(player->getCurrentSpriteIndex()),
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
	for (int i = 0; i < enemyManager->getObjectCount(); i++)
		window->blitSurface(assetManager->getSurface(enemyManager->getObject(i)->getCurrentSpriteIndex()),
			enemyManager->getObject(i)->getTransform().X(),
			enemyManager->getObject(i)->getTransform().Y());

	// Missiles in progress blitting
	for (int i = 0; i < missileManager->getObjectCount(); i++)
		window->blitSurface(assetManager->getSurface(missileManager->getObject(i)->getCurrentSpriteIndex()),
			missileManager->getObject(i)->getTransform().X(),
			missileManager->getObject(i)->getTransform().Y());

	// Flip screen
	window->flipScreen();
}

bool Context::gameOver()
{
	// TO DO
	return false;
}

void Context::objectHasMoved(GameObject* movedObject)
{
	// Check if the movedObject collide with something in the scene
	GameObject* hitObject = physicsManager->collideWith(movedObject);
	if (hitObject != nullptr && hitObject->getObjectType() != ObjectTypes::Other)
	{
		// Make the object react to the collision, and get their instructions
		ReactionTypes movedObjectAction = movedObject->reactToCollision(hitObject);
		ReactionTypes hitObjectAction = hitObject->reactToCollision(movedObject);

		// Handle the reactions of the two objects
		handleReaction(movedObject, movedObjectAction);
		handleReaction(hitObject, hitObjectAction);
	}
}

void Context::handleReaction(GameObject* object, ReactionTypes reaction)
{
	// For now, the context only handle destruction of the gameobject
	// The other types of reactions are handled by the gameobject itself
	switch (reaction)
	{
		case ReactionTypes::Destroy:
			if (object->getObjectType() == ObjectTypes::Enemy)
				enemyManager->destroyObject(object);
			if (object->getObjectType() == ObjectTypes::Missile)
				missileManager->destroyObject(object);
			if (object->getObjectType() == ObjectTypes::Player)
				gameOver();
			break;
		default:;
	}
}

Window* Context::getWindow() const
{
	return window;
}


// Static member functions
void Context::addGameObject(GameObject* object)
{
	gameObjects.push_back(object);
}

void Context::deleteGameObject(GameObject* object)
{
	vector<GameObject*>::iterator it = getGameObjectIterator(0);
	for (; it != gameObjects.end(); it++)
	{
		if ((*it) == object)
		{
			gameObjects.erase(it);
			return;
		}
	}
}

vector<GameObject*>::iterator Context::getGameObjectIterator(int i)
{
	vector<GameObject*>::iterator it = gameObjects.begin();
	if (i > 0)
		std::advance(it, i);
	return it;
}

int Context::getGameObjectCount()
{
	return gameObjects.size();
}