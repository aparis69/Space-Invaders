#include "Context.h"
#include "Player.h"
#include "Background.h"
#include "MissileManager.h"
#include "Missile.h"
#include "PhysicsManager.h"
#include "Window.h"
#include "AssetManager.h"
using namespace std;

Context::Context(void)
{
	// Init Window and Managers
	window = new Window(640, 480, "Space Invaders 2");
	assetManager = new AssetManager();
	physicsManager = new PhysicsManager(window->getXRES(), window->getYRES());
    missileManager = new MissileManager();

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
    player = new Player(4);
    background = new Background();
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
	SDLKey tabkey[5] = { SDLK_UP, SDLK_DOWN, SDLK_LEFT, SDLK_RIGHT, SDLK_SPACE };

    // Storing temporary object to improve readability
	int speed = player->getSpeed();
    int xSize = player->getCurrentSprite()->getXSize();
    int ySize = player->getCurrentSprite()->getYSize();
    int xPos = player->getXPos();
    int yPos = player->getYPos();

    // Move the player after checking screen bounds
    if (in.Key(tabkey[0]) && !physicsManager->isOutOfScreen(xPos, yPos - speed, xSize, ySize))  // Up
		player->getCurrentSprite()->moveY(-speed);
    if (in.Key(tabkey[1]) && !physicsManager->isOutOfScreen(xPos, yPos + speed, xSize, ySize))  // Down
		player->getCurrentSprite()->moveY(speed);
    if (in.Key(tabkey[2]) && !physicsManager->isOutOfScreen(xPos - speed, yPos, xSize, ySize))  // left
		player->getCurrentSprite()->moveX(-speed);
    if (in.Key(tabkey[3]) && !physicsManager->isOutOfScreen(xPos + speed, yPos, xSize, ySize))  // right
		player->getCurrentSprite()->moveX(speed);
	if (in.Key(tabkey[4]))  // Shoot missile
        missileManager->shootMissile(xPos, yPos, -5, MissileType::Small);

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
	background->updateScroll(window->getYRES());
}

void Context::render()
{
	// Background directly blitted to make scrolling work
    SDL_Rect pos = background->getPosition();
	SDL_BlitSurface(assetManager->getSurface(background->getCurrentSprite()->getIm()), 
                    &pos, 
					window->getSurface(), NULL);

	// Player blitting
    window->blitSurface(assetManager->getSurface(player->getCurrentSprite()->getIm()),
						player->getCurrentSprite()->getX(),
						player->getCurrentSprite()->getY());

	// Missiles in progress blitting
	for (int i = 0 ; i < missileManager->getNumberOfMissile() ; i++)
		window->blitSurface(assetManager->getSurface(missileManager->getMissile(i)->getCurrentSprite()->getIm()),
							missileManager->getMissile(i)->getXPos(),
							missileManager->getMissile(i)->getYPos());
	// Flip screen
    window->flipScreen();
}

bool Context::gameOver()
{
	return false;
}