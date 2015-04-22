#include "Context.h"
#include "Player.h"
#include "Background.h"
using namespace std;

Context::Context(void)
{
	// test3
	// test
	// Init Window and Asset
	window = new Window(640, 480, "Space Invaders 2");
	assetManager = new AssetManager();
	physicsManager = new PhysicsManager(window->getXRES(), window->getYRES());

	SDL_BlitSurface(assetManager->getSurface(0), NULL, window->getSurface(), NULL);

	// Init GameObjects in the scene
	initGameObjects();
}

Context::~Context(void)
{
	delete assetManager;
	delete window;
}

void Context::initGameObjects()
{
	gameObjects = vector<GameObject*>();
	gameObjects.push_back(new Background());
	gameObjects.push_back(new Player(4));

	missileManager = new MissileManager();
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
	SDLKey tabkey[1][5] = {{SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT,SDLK_SPACE}};

	Player* player = ((Player*)gameObjects.at(1));
	int speed = player->getSpeed();

	if (in.Key(tabkey[0][0]) && !physicsManager->isOutOfScreen(player->getXPos(), player->getYPos() - speed))  // haut
		player->getCurrentSprite()->MoveY(-speed);
	if (in.Key(tabkey[0][1]) && !physicsManager->isOutOfScreen(player->getXPos(), player->getYPos() + speed))  // bas
		player->getCurrentSprite()->MoveY(speed);
	if (in.Key(tabkey[0][2]) && !physicsManager->isOutOfScreen(player->getXPos() - speed, player->getYPos()))  // gauche
		player->getCurrentSprite()->MoveX(-speed);
	if (in.Key(tabkey[0][3]) && !physicsManager->isOutOfScreen(player->getXPos() + speed, player->getYPos()))  // droite
		player->getCurrentSprite()->MoveX(speed);
	if (in.Key(tabkey[0][4]))  // Attaque missile
		missileManager->shootMissile(player->getXPos(), player->getYPos());

	player->updateAnimation();
}

void Context::updateAI()
{

}

void Context::updateGameObjects()
{
	// Missiles in progress
	missileManager->updateMissileInProgress();
	missileManager->manageVectorSize(physicsManager);
}

void Context::updateBackground()
{
	((Background*)gameObjects.at(0))->updateScroll(window->getYRES());
}

void Context::render()
{
	// Fond, collé à la main pour Scrolling
	SDL_BlitSurface(assetManager->getSurface(gameObjects.at(0)->getCurrentSprite()->GetIm()), 
		&(((Background*)gameObjects.at(0))->getBackgroundPosition()), 
		window->getSurface(), NULL);

	// Game object direct
	for (unsigned int i = 1 ; i < gameObjects.size() ; i++)
		window->blitSurface(assetManager->getSurface(gameObjects.at(i)->getCurrentSprite()->GetIm()),
		gameObjects.at(i)->getCurrentSprite()->GetX(),
		gameObjects.at(i)->getCurrentSprite()->GetY());

	// Missiles in progress
	for (int i = 0 ; i < missileManager->getNumberOfMissile() ; i++)
		window->blitSurface(assetManager->getSurface(missileManager->getMissile(i)->getCurrentSprite()->GetIm()),
		missileManager->getMissile(i)->getXPos(),
		missileManager->getMissile(i)->getYPos());
	window->flipScreen();
}

bool Context::gameOver()
{
	return false;
}